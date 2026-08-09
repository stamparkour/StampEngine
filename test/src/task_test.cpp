#include <gtest/gtest.h>
#include <stamp/task/coroutine.h>
#include <stamp/task/co_lock.h>
#include <stamp/task/thread_pool.h>
#include <stamp/task/task_queue.h>
#include <stdexcept>
#include <chrono>

using namespace stamp::task;

// test coroutine multithreading
// test task_queue
// test timer_task_queue
// test thread_pool
// test co_lock

coroutine<void> noop_coroutine() {
	co_return;
}
coroutine<void> yield_coroutine() {
	co_yield{};
	co_return;
}
coroutine<int> return_coroutine() {
	co_return 1;
}
coroutine<void> throw_coroutine() {
	throw std::runtime_error("runtime error");
	co_return;
}
template<typename Awaitable> requires awaitable_c<std::remove_cvref_t<Awaitable>>
coroutine<void> co_await_coroutine(Awaitable&& target) {
	co_await std::forward<Awaitable>(target);
	co_return;
}
coroutine<void> sleep_coroutine() {
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(0.5s);
	co_return;
}
coroutine<void> increment_coroutine(std::atomic_int* target) {
	target->fetch_add(1);
	target->notify_all();
	co_return;
}

struct co_lock_state_t {
	std::atomic_int access_count;
	std::atomic_int max_access_count;
	std::atomic_int shared_access_count;
	std::atomic_int max_shared_access_count;
};
coroutine<void> increment_and_co_lock_coroutine(std::atomic_int* target, co_lock* lock, co_lock_state_t* state) {
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(5ms);

	{
		auto l = co_await lock->lock();

		int ac = state->access_count.fetch_add(1) + 1;
		int mac = state->max_access_count.load();

		if (ac > mac) {
			state->max_access_count.compare_exchange_strong(mac, ac);
		}

		std::this_thread::sleep_for(8ms);

		state->access_count.fetch_sub(1);
	}

	target->fetch_add(1);
	target->notify_all();

	co_return;
}


coroutine<void> increment_and_co_shared_lock_read_coroutine(std::atomic_int* target, co_lock_shared* lock, co_lock_state_t* state) {
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(5ms);

	{
		auto l = co_await lock->lock_shared();

		int ac = state->shared_access_count.fetch_add(1) + 1;
		int mac = state->max_shared_access_count.load();

		if (ac > mac) {
			state->max_shared_access_count.compare_exchange_strong(mac, ac);
		}

		std::this_thread::sleep_for(8ms);

		state->shared_access_count.fetch_sub(1);
	}

	target->fetch_add(1);
	target->notify_all();

	co_return;
}

coroutine<void> increment_and_co_shared_lock_write_coroutine(std::atomic_int* target, co_lock_shared* lock, co_lock_state_t* state) {
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(5ms);

	{
		auto l = co_await lock->lock();

		int ac = state->access_count.fetch_add(1) + 1;
		int mac = state->max_access_count.load();

		if (ac > mac) {
			state->max_access_count.compare_exchange_strong(mac, ac);
		}

		std::this_thread::sleep_for(8ms);

		state->access_count.fetch_sub(1);
	}

	target->fetch_add(1);
	target->notify_all();

	co_return;
}


TEST(Coroutine, Invokation) {
	coroutine<void> noop_coroutine_v = noop_coroutine();
	EXPECT_EQ(static_cast<bool>(noop_coroutine_v), true);
}

TEST(Coroutine, Destruction) {
	coroutine<void> noop_coroutine_v = noop_coroutine();

	EXPECT_EQ(static_cast<bool>(noop_coroutine_v), true);

	noop_coroutine_v.~coroutine();

	EXPECT_EQ(static_cast<bool>(noop_coroutine_v), false);
}

TEST(Coroutine, Kill) {
	coroutine<void> yield_coroutine_v = yield_coroutine();

	EXPECT_EQ(yield_coroutine_v.done(), false);

	yield_coroutine_v.kill();
	yield_coroutine_v.resume();

	EXPECT_EQ(yield_coroutine_v.done(), true);
}

TEST(Coroutine, Detatch) {
	coroutine<void> noop_coroutine_v = noop_coroutine();

	noop_coroutine_v.detach();
	noop_coroutine_v.resume();

	// undefined behavior after co_return
}
TEST(Coroutine, Pause) {
	{
		coroutine<void> yield_coroutine_v = yield_coroutine();

		EXPECT_EQ(yield_coroutine_v.is_yielded(), false);
		EXPECT_EQ(yield_coroutine_v.done(), false);

		yield_coroutine_v.pause();
		yield_coroutine_v.resume();

		EXPECT_EQ(yield_coroutine_v.is_yielded(), true);
		EXPECT_EQ(yield_coroutine_v.done(), false);

		yield_coroutine_v.resume();

		EXPECT_EQ(yield_coroutine_v.is_yielded(), false);
		EXPECT_EQ(yield_coroutine_v.done(), true);
	}
	{
		coroutine<void> yield_coroutine_v = yield_coroutine();

		EXPECT_EQ(yield_coroutine_v.is_yielded(), false);
		EXPECT_EQ(yield_coroutine_v.done(), false);

		yield_coroutine_v.resume();

		EXPECT_EQ(yield_coroutine_v.is_yielded(), false);
		EXPECT_EQ(yield_coroutine_v.done(), true);
	}
}

TEST(Coroutine, Accessors) {
	coroutine<void> yield_coroutine_v = yield_coroutine();

	EXPECT_EQ(yield_coroutine_v.done(), false);
	EXPECT_EQ(yield_coroutine_v.is_started(), false);
	EXPECT_EQ(yield_coroutine_v.is_yielded(), false);
	EXPECT_EQ(static_cast<bool>(yield_coroutine_v), true);

	yield_coroutine_v.pause();
	yield_coroutine_v.resume();

	EXPECT_EQ(yield_coroutine_v.done(), false);
	EXPECT_EQ(yield_coroutine_v.is_started(), true);
	EXPECT_EQ(yield_coroutine_v.is_yielded(), true);
	EXPECT_EQ(static_cast<bool>(yield_coroutine_v), true);

	yield_coroutine_v.resume();

	EXPECT_EQ(yield_coroutine_v.done(), true);
	EXPECT_EQ(yield_coroutine_v.is_started(), true);
	EXPECT_EQ(yield_coroutine_v.is_yielded(), false);
	EXPECT_EQ(static_cast<bool>(yield_coroutine_v), true);
}

TEST(Coroutine, Comparison) {
	coroutine<void> coroutine_1 = noop_coroutine();
	coroutine<void> coroutine_2 = noop_coroutine();

	EXPECT_EQ(coroutine_1 == coroutine_1, true);
	EXPECT_EQ(coroutine_1 != coroutine_1, false);

	EXPECT_EQ(coroutine_1 == coroutine_2, false);
	EXPECT_EQ(coroutine_1 != coroutine_2, true);

	EXPECT_EQ(coroutine_1 >= coroutine_1, true);
	EXPECT_EQ(coroutine_1 <= coroutine_1, true);

	EXPECT_EQ(coroutine_1 > coroutine_2, !(coroutine_1 < coroutine_2));
	EXPECT_EQ(coroutine_1 < coroutine_2, !(coroutine_1 > coroutine_2));
	EXPECT_EQ(coroutine_1 <= coroutine_2, !(coroutine_1 > coroutine_2));
	EXPECT_EQ(coroutine_1 >= coroutine_2, !(coroutine_1 < coroutine_2));
}

TEST(Coroutine, Return) {
	coroutine<int> return_coroutine_v = return_coroutine();

	return_coroutine_v.resume();

	EXPECT_EQ(return_coroutine_v.result(), 1);
}

TEST(Coroutine, Casting) {
	coroutine<void> return_coroutine_v = return_coroutine();

	return_coroutine_v.resume();
}

TEST(Coroutine, Error) {
	coroutine<void> throw_coroutine_v = throw_coroutine();

	throw_coroutine_v.resume();

	EXPECT_EQ(static_cast<bool>(throw_coroutine_v.get_exception()), true);
}

TEST(Coroutine, CoAwait) {
	coroutine<void> noop_coroutine_v = noop_coroutine();
	coroutine<void> co_await_coroutine_v = co_await_coroutine(noop_coroutine_v);
	coroutine<void> await2 = co_await_coroutine(co_await_coroutine_v);
	coroutine<void> await3 = co_await_coroutine(noop_coroutine_v);

	co_await_coroutine_v.resume();
	await2.resume();
	await3.resume();

	EXPECT_EQ(co_await_coroutine_v.done(), false);

	noop_coroutine_v.resume();

	EXPECT_EQ(co_await_coroutine_v.done(), true);
}


TEST(Coroutine, CoAwaitDeconstruct) {
	coroutine<void> noop_coroutine_v = noop_coroutine();

	coroutine<void> h;

	{
		coroutine<void> co_await_coroutine_v = co_await_coroutine(noop_coroutine_v);
		co_await_coroutine_v.resume();
		h = co_await_coroutine(noop_coroutine_v);
		h.resume();
	}

	noop_coroutine_v.resume();

	EXPECT_EQ(h.done(), true);
}


TEST(TaskQueue, Emplace) {
	constexpr int target_count = 100;

	task_queue queue{};

	std::atomic_int value = 0;

	for (int i = 0; i < target_count; i++) {
		queue.emplace_detached(increment_coroutine, &value);
	}

	int dequeue_count = 0;

	while (dequeue_count < target_count) {
		auto bulk = queue.wait_dequeue_bulk();
		for (auto& v : bulk) {
			if (!v) continue;
			v.resume();
			dequeue_count++;
		}
	}

	EXPECT_EQ(value, target_count);
}


TEST(TimerTaskQueue, Emplace) {
	using namespace std::chrono_literals;

	auto delay = 200ms;
	auto delay_padded = 190ms;

	timer_task_queue queue{};
	
	auto now_v = timer_task_queue::clock::now();

	auto noop_v = queue.emplace_until(timer_task_queue::clock::now() + delay, noop_coroutine);
	auto next_v = queue.pop_wait();

	auto then_v = timer_task_queue::clock::now();

	EXPECT_EQ(noop_v, next_v);
	EXPECT_GE(then_v, now_v + delay_padded);
}

TEST(ThreadPool, Enqueue) {
	constexpr int target_count = 100;

	thread_pool pool{4};
	
	std::atomic_int value = 0;

	for (int i = 0; i < target_count; i++) {
		pool.queue().emplace_detached(increment_coroutine, &value);
	}

	int t;
	while ((t = value.load()) < target_count) {
		value.wait(t);
	}

	pool.kill();
}


TEST(CoLock, CoLock) {
	constexpr int target_count = 100;

	thread_pool pool{8};

	std::atomic_int value = 0;
	co_lock lock{};
	co_lock_state_t state{};

	for (int i = 0; i < target_count; i++) {
		pool.queue().emplace_detached(increment_and_co_lock_coroutine, &value, &lock, &state);
	}

	int t;
	while ((t = value.load()) < target_count) {
		value.wait(t);
	}

	EXPECT_EQ(state.access_count.load(), 0);
	EXPECT_EQ(state.max_access_count.load(), 1);

	pool.kill();
}

TEST(CoSharedLock, ParallelRead) {
	constexpr int target_count = 100;

	thread_pool pool{8};

	std::atomic_int value = 0;
	co_lock_shared lock{};
	co_lock_state_t state{};

	for (int i = 0; i < target_count; i++) {
		pool.queue().emplace_detached(increment_and_co_shared_lock_read_coroutine, &value, &lock, &state);
	}

	int t;
	while ((t = value.load()) < target_count) {
		value.wait(t);
	}

	EXPECT_EQ(state.shared_access_count.load(), 0);
	EXPECT_GT(state.max_shared_access_count.load(), 1);

	pool.kill();
}
TEST(CoSharedLock, Write) {
	constexpr int target_count = 100;

	thread_pool pool{8};

	std::atomic_int value = 0;
	co_lock_shared lock{};
	co_lock_state_t state{};

	for (int i = 0; i < target_count; i++) {
		pool.queue().emplace_detached(increment_and_co_shared_lock_write_coroutine, &value, &lock, &state);
	}

	int t;
	while ((t = value.load()) < target_count) {
		value.wait(t);
	}

	EXPECT_EQ(state.access_count.load(), 0);
	EXPECT_EQ(state.max_access_count.load(), 1);

	pool.kill();
}
TEST(CoSharedLock, ReadWrite) {
	constexpr int target_count = 100;

	thread_pool pool{8};

	std::atomic_int value = 0;
	co_lock_shared lock{};
	co_lock_state_t state{};

	for (int i = 0; i < target_count; i++) {
		if (i % 16 == 15) {
			pool.queue().emplace_detached(increment_and_co_shared_lock_write_coroutine, &value, &lock, &state);
		}
		else {
			pool.queue().emplace_detached(increment_and_co_shared_lock_read_coroutine, &value, &lock, &state);
		}
	}

	int t;
	while ((t = value.load()) < target_count) {
		value.wait(t);
	}

	EXPECT_EQ(state.access_count.load(), 0);
	EXPECT_EQ(state.max_access_count.load(), 1);
	EXPECT_EQ(state.shared_access_count.load(), 0);
	EXPECT_GE(state.max_shared_access_count.load(), 1);

	pool.kill();
}