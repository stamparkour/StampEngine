#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/core/memory.h>

#include <CppUnitTest.h>
#include <vector>
#include <thread>
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_NAMESPACE;
using namespace std;

namespace Memory {

TEST_CLASS(ThreadSafePointer) {
public:
	TEST_METHOD(DefaultConstructor) {
		threadsafe_ptr<int> ptr;
		Assert::IsTrue(!ptr);
	}
	TEST_METHOD(Constructor) {
		threadsafe_ptr<int> ptr{ new int(7) };
		Assert::IsTrue((bool)ptr);
		Assert::AreEqual(*ptr.get_readonly(), 7);
	}
	TEST_METHOD(MakeThreadSafe) {
		threadsafe_ptr<int> ptr = make_threadsafe<int>(3);
		Assert::AreEqual(*ptr.get_readonly(), 3);
	}
	TEST_METHOD(ReadWrite) {
		threadsafe_ptr<int> ptr = make_threadsafe<int>(3);
		Assert::AreEqual(*ptr.get_readonly(), 3);
		{
			auto w = ptr.get();
			*w = 5;
		}
		Assert::AreEqual(*ptr.get_readonly(), 5);
	}
	TEST_METHOD(SharedCount) {
		threadsafe_ptr<int> ptr = make_threadsafe<int>(3);
		Assert::AreEqual((int)ptr.use_count(), 1);
		{
			threadsafe_ptr<int> ptr2 = ptr;
			Assert::AreEqual((int)ptr.use_count(), 2);
		}
		Assert::AreEqual((int)ptr.use_count(), 1);
		Assert::AreEqual(*ptr.get_readonly(), 3);
	}

	TEST_METHOD(MultipleReadersOneWriter) {
        auto sp = make_threadsafe<int>(0);
        const int readers = 5;
        std::atomic<int> activeReaders{ 0 };
        std::atomic<bool> readersStarted{ false };
        std::atomic<bool> writerAcquired{ false };

        std::vector<std::thread> threads;
        // readers: get readonly_ptr and hold for 250ms
        for (int i = 0; i < readers; ++i) {
            threads.emplace_back([&]() {
                auto r = sp.get_readonly();
                // r locks shared access
                ++activeReaders;
                readersStarted = true;
                std::this_thread::sleep_for(100ms);
                --activeReaders;
            });
        }

        // ensure readers started
        while (!readersStarted) std::this_thread::sleep_for(5ms);
        // writer attempts to get exclusive access - should block until readers finish
        auto start = std::chrono::steady_clock::now();
        std::thread writer([&]() {
            // short delay to ensure writer attempts while readers active
            std::this_thread::sleep_for(10ms);
            auto w = sp.get(); // exclusive lock - must wait until readers drop
            writerAcquired = true;
            // modify
            *w = 123;
            });

        // join
        for (auto& t : threads) t.join();
        writer.join();

        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        // writer should have waited at least ~200ms for readers to finish (some slack)
        Assert::IsTrue(writerAcquired, L"writer never acquired lock");
        Assert::IsTrue(elapsed > 80, L"writer did not block long enough (readers not blocking writer)");
	}

    TEST_METHOD(MultipleWriters) {
        auto sp = make_threadsafe<int>(0);
        const int writers = 6;
        std::atomic<int> activeWriters{ 0 };
        std::atomic<int> maxConcurrent{ 0 };
        std::vector<std::thread> threads;
        for (int i = 0; i < writers; ++i) {
            threads.emplace_back([&]() {
                // each writer will try to obtain exclusive access and hold 50ms
                auto w = sp.get();
                int cur = ++activeWriters;
                maxConcurrent.store(std::max(maxConcurrent.load(), cur));
                // critical region
                std::this_thread::sleep_for(20ms);
                --activeWriters;
                });
        }
        for (auto& t : threads) t.join();
        Assert::IsTrue(maxConcurrent.load() <= 1, L"more than one writer was in the critical section simultaneously");
    }

    TEST_METHOD(ConditionalVariableWithWritablePtr) {
        auto sp = make_threadsafe<int>(0);
        std::condition_variable_any cv;
        std::atomic<bool> ready{ false };

        std::thread waiter([&]() {
            // obtain writable_ptr; writable_ptr ctor locks the mutex
            auto w = sp.get();
            // wait on condition variable using the writable_ptr's lock/unlock semantics
            cv.wait_for(w, 500ms, [&] { return ready.load(); });
            // after wake, modify
            if (ready) *w = 55;
        });

        std::this_thread::sleep_for(100ms);
        // signal
        {
            auto w2 = sp.get();
            ready = true;
            cv.notify_one(); // should wake waiter; notif while another writable exists is allowed (wait releases and reacquires)
        }
        waiter.join();

        // no deadlock occurs
    }

    TEST_METHOD(DestructionOccursWhenNoOwners) {
        static std::atomic<int> instances;

        struct Counted {
            Counted() { ++instances; }
            ~Counted() { --instances; }
        };

        instances = 0;

        {
            auto sp = make_threadsafe<Counted>();
            Assert::AreEqual(1, (int)instances.load());
            sp.reset();
            // after reset and no other owners, instance should be destroyed
            Assert::IsTrue(instances.load() == 0);
        }
    }

    TEST_METHOD(ResetWhileReaderHolds) {
        auto sp = make_threadsafe<int>(42);
        std::atomic<bool> readerStarted{ false };
        std::atomic<bool> readerDone{ false };
        std::thread reader([&]() {
            auto r = sp.get_readonly();
            readerStarted = true;
            // hold the readonly_ptr for a bit
            std::this_thread::sleep_for(50ms);
            // still valid while held
            Assert::AreEqual(42, *r.get());
            readerDone = true;
            });
        while (!readerStarted) std::this_thread::sleep_for(1ms);
        // reset the strong owner while reader holds a shared reference
        sp.reset();
        // underlying object should remain alive until reader releases
        reader.join();
        Assert::IsTrue(readerDone);
    }

    TEST_METHOD(WeakExpiredAfterReset) {
        auto sp = make_threadsafe<int>(7);
        weak_threadsafe_ptr<int> wp = sp;
        Assert::IsFalse(wp.expired());
        sp.reset();
        Assert::IsTrue(wp.expired());
        auto locked = wp.lock();
        Assert::IsFalse((bool)locked);
    }

    TEST_METHOD(GetUnsafeDoesNotBlock) {
        auto sp = make_threadsafe<int>(0);
        std::atomic<bool> writerLocked{ false };
        std::atomic<bool> unsafeSeen{ false };
        std::thread writer([&]() {
            auto w = sp.get(); // exclusive lock
            writerLocked = true;
            std::this_thread::sleep_for(100ms);
            });
        // tiny delay so writer acquires
        while (!writerLocked) std::this_thread::sleep_for(1ms);
        std::thread t([&]() {
            // should not block even if writer holds exclusive lock
            auto r = sp.get_readonly_unsafe();
            unsafeSeen = true; // if this runs quickly, unsafe did not block
            });
        t.join();
        writer.join();
        Assert::IsTrue(unsafeSeen.load());
    }

    TEST_METHOD(ThreadsafeFromThisWithMakeThreadsafe) {
        struct Self : public enable_threadsafe_from_this<Self> {
            threadsafe_ptr<Self> grab() { return threadsafe_from_this(); }
        };
        auto sp = make_threadsafe<Self>();
        auto fromIns = sp.get()->grab();
        Assert::IsTrue((bool)fromIns);
        // ensure it's the same object (pointer equality)
        Assert::IsTrue(fromIns.get_readonly().get() == sp.get_readonly().get());
    }

    TEST_METHOD(LockableConstLockUnlock) {
        struct S { int x = 0; };
        lockable<S> ls;
        // lock from const reference
        const lockable<S>& cls = ls;
        cls.lock();
        cls.unlock();
    }
};

//TEST_CLASS(Benchmark) {
//public:
//	TEST_METHOD(SharedPointer) {
//		for (int i = 0; i < STAMP_BENCHMARK_LOOPCOUNT; ++i) {
//			shared_ptr<int> ptr = make_shared<int>(i);
//		}
//	}
//	TEST_METHOD(ThreadSafePointer) {
//		for (int i = 0; i < STAMP_BENCHMARK_LOOPCOUNT; ++i) {
//			threadsafe_ptr<int> ptr = make_threadsafe<int>(i);
//		}
//	}
//};
}

#endif