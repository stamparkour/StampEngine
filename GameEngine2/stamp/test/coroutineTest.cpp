#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/core/coroutine.h>
#include <CppUnitTest.h>
#include <atomic>
#include <thread>

//completely generated with AI

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_CORE_NAMESPACE;

namespace Core {

    TEST_CLASS(CoroutineTests) {
public:

    // simple coroutine returning int
    static coroutine<int> simple_value_coroutine() {
        co_return 42;
    }

    // simple coroutine returning void
    static coroutine<void> simple_void_coroutine() {
        co_return;
    }

    // waiter coroutine that awaits an int coroutine and stores result
    static coroutine<void> waiter_store(coroutine<int> c, std::atomic<int>& out) {
        int v = co_await c;
        out.store(v);
        co_return;
    }

    TEST_METHOD(ReturnObjectAndHandle) {
        auto c = simple_value_coroutine();
        // handle should be non-null
        Assert::IsTrue(c);
    }

    TEST_METHOD(OnFinishPromise_NonVoid) {
        auto c = simple_value_coroutine();
        auto f = c.on_finish_promise();
        // future should become ready with returned value
        int v = f.get();
        Assert::AreEqual(42, v);
    }

    TEST_METHOD(OnFinishPromise_Void) {
        auto c = simple_void_coroutine();
        auto f = c.on_finish_promise();
        // should not throw and should be ready
        f.get(); // just ensure it completes
        Assert::IsTrue(true);
    }

    TEST_METHOD(CoAwait_PropagatesValue) {
        auto c = simple_value_coroutine();
        std::atomic<int> storage{ 0 };
        // launching waiter; because promise/initial_suspend semantics may run immediately,
        // this will ensure waiter runs and stores the awaited value.
        auto w = waiter_store(c, storage);
        // ensure any asynchronous completion has occurred (implementation details may vary)
        // small yield to allow coroutines that schedule work to run in other threads if any
        std::this_thread::yield();

        Assert::AreEqual(42, storage.load());
    }

    // Simple value coroutine used by some tests
    static coroutine<int> simple_value_coroutine_777() {
        co_return 777;
    }

    // Waiter that co_awaits an awaitable<void> and sets flag when resumed
    static coroutine<void> waiter_set_flag(const STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue>& q, std::atomic_bool& flag) {
        co_await awaitable<void>(q, false);
        flag.store(true);
        co_return;
    }

    // Waiter that co_awaits an awaitable<int> and stores the value
    static coroutine<void> waiter_store_value(const STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue>& q, std::atomic_int& out, int suppliedValue) {
        int v = co_await awaitable<int>(q, false, suppliedValue);
        out.store(v);
        co_return;
    }

    TEST_METHOD(Awaitable_Resumes_On_RunAll_Void) {
        auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();
        std::atomic_bool flag{ false };

        // Construct coroutine which will reach co_await and suspend; awaitable will enqueue its continuation in q
        auto c = waiter_set_flag(q, flag);

        // Before running the queue, the waiter should be suspended and flag false
        Assert::IsFalse(flag.load());

        // Run queued continuations (should resume the waiter and set the flag)
        q.get()->run_all();

        Assert::IsTrue(flag.load());
    }

    TEST_METHOD(Awaitable_Resumes_On_RunAll_WithValue) {
        auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();
        std::atomic_int valueOut{ 0 };
        const int supplied = 12345;

        auto c = waiter_store_value(q, valueOut, supplied);

        // still suspended
        Assert::AreEqual(0, valueOut.load());

        q.get()->run_all();

        Assert::AreEqual(supplied, valueOut.load());
    }

    TEST_METHOD(MultipleAwaiters_RunAll) {
        auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();
        std::atomic_bool f1{ false }, f2{ false };

        auto a = waiter_set_flag(q, f1);
        auto b = waiter_set_flag(q, f2);

        // both suspended before run_all
        Assert::IsFalse(f1.load());
        Assert::IsFalse(f2.load());

        q.get()->run_all();

        Assert::IsTrue(f1.load());
        Assert::IsTrue(f2.load());
    }

    TEST_METHOD(OnFinishPromise_CanBeWaitedFromOtherThread) {
        auto c = simple_value_coroutine_777();
        auto fut = c.on_finish_promise();

        std::atomic_int result{ 0 };
        std::thread t([&fut, &result]() {
            // block until ready on another thread
            int v = fut.get();
            result.store(v);
            });

        // join and verify
        t.join();
        Assert::AreEqual(777, result.load());
    }

    TEST_METHOD(OnFinishPromise_ImmediateCompletion) {
        // coroutine that returns immediately; on_finish_promise should be ready and yield value
        auto c = simple_value_coroutine_777();
        auto fut = c.on_finish_promise();
        int v = fut.get();
        Assert::AreEqual(777, v);
    }

    // Ensure awaitable with an int reference uses coroutine frame lifetime (no dangling ref)
    TEST_METHOD(Awaitable_ValueLifetimeAcrossSuspend) {
        auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();
        std::atomic_int valueOut{ 0 };

        // This waiter stores a local 'supplied' into coroutine frame and awaits it.
        auto c = waiter_store_value(q, valueOut, /*suppliedValue*/ 4242);

        q.get()->run_all();

        Assert::AreEqual(4242, valueOut.load());
    }

    // A waiter coroutine that suspends on the provided queue and increments `completed` when resumed.
    static coroutine<void> waiter_increment(const STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue>& q, std::atomic_int& completed) {
        co_await awaitable<void>(q, false);
        completed.fetch_add(1, std::memory_order_relaxed);
        co_return;
    }

    TEST_METHOD(Multithreaded_ProducerConsumer_Stress) {
        constexpr int PRODUCERS = 4;
        constexpr int PER_PRODUCER = 250; // total 1000 coroutines; adjust if tests run too long
        const int TOTAL = PRODUCERS * PER_PRODUCER;

        auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();

        std::atomic_int createdCount{ 0 };
        std::atomic_int completedCount{ 0 };
        std::atomic_bool producersDone{ false };


        // Consumer thread: repeatedly call run_all to process queued continuations while producers are active.
        std::thread consumer([&]() {
            while (true) {
                q.get()->run_all();
                // Exit when producers finished and we've seen all completions.
                if (producersDone.load(std::memory_order_acquire) && completedCount.load(std::memory_order_acquire) >= TOTAL) break;
                // small sleep to avoid busy spin and allow producers to enqueue
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            });

        // Producer threads: create coroutines that will suspend on `q` and enqueue their continuation.
        std::vector<std::thread> producers;
        for (int p = 0; p < PRODUCERS; ++p) {
            producers.emplace_back([&, p]() {
                for (int i = 0; i < PER_PRODUCER; ++i) {
                    // create coroutine; it will run immediately until it co_awaits and then enqueue its continuation
                    coroutine<void> c = waiter_increment(q, completedCount);
                    createdCount.fetch_add(1, std::memory_order_relaxed);
                    // slight throttle to increase interleaving
                    if ((i & 0x3F) == 0) std::this_thread::yield();
                }
                });
        }

        // join producers
        for (auto& t : producers) t.join();
        producersDone.store(true, std::memory_order_release);

        // wait up to timeout for all completions
        auto start = std::chrono::steady_clock::now();
        const auto timeout = std::chrono::seconds(5);
        while (completedCount.load(std::memory_order_acquire) < TOTAL) {
            // let consumer run and other scheduling happen
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (std::chrono::steady_clock::now() - start > timeout) break;
        }

        // ensure consumer exits
        consumer.join();

        // All created should be completed
        Assert::AreEqual(TOTAL, createdCount.load());
        Assert::AreEqual(TOTAL, completedCount.load());
    }

    };

} // namespace CoreTests

#endif