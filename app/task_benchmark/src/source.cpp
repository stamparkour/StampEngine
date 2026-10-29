/**
 * @file source.cpp
 * @brief Performance profiling of the StampEngine Coroutine System using Google Benchmark
 */

#include <stamp/task/coroutine.h>
#include <stamp/task/task_queue.h>
#include <stamp/task/thread_pool.h>
#include <benchmark/benchmark.h>
#include <unordered_map>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <cppcoro/task.hpp>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/async_mutex.hpp>
#include <cppcoro/static_thread_pool.hpp>
#include <cppcoro/async_scope.hpp>

using namespace stamp::task;

struct co_lock_state_t {
	std::atomic_int access_count;
	std::atomic_int max_access_count;
	std::atomic_int shared_access_count;
	std::atomic_int max_shared_access_count;
};

void linear_test(std::atomic_int* counter) {
	using namespace std::chrono_literals;

	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 50; k++) {
			benchmark::DoNotOptimize(k);
			benchmark::DoNotOptimize(i);
		}
	}

	counter->fetch_add(1);

	return;
}
static void LinearTest(benchmark::State& state) {
	int loop_count = state.range(0);

	std::atomic_int count{0};
	std::mutex lock_v{};
	for (auto _ : state) {
		count.store(0);

		for (int i = 0; i < loop_count; i++) {
			linear_test(&count);
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			STAMP_CPU_PAUSE();
		}
	}
}
// BENCHMARK(LinearTest)->Range(8, 8192)->MinTime(1.0);

cppcoro::task<void> cpp_coro_test(cppcoro::static_thread_pool& tp, cppcoro::async_mutex* lock_v, std::atomic_int* counter) {
	using namespace std::chrono_literals;
	co_await tp.schedule();
	for (int i = 0; i < 10; i++) {
		{
			auto l = co_await lock_v->scoped_lock_async();
			for (int k = 0; k < 50; k++) {
				benchmark::DoNotOptimize(k);
			}
		}
		co_await tp.schedule();
	}

	counter->fetch_add(1);
}
static void CppCoroTest(benchmark::State& state) {
	int loop_count = state.range(0);

	cppcoro::async_scope scope{};
	cppcoro::static_thread_pool pool = cppcoro::static_thread_pool{4};
	std::atomic_int count{0};
	cppcoro::async_mutex lock_v{};
	for (auto _ : state) {
		count.store(0);

		for (int i = 0; i < loop_count; i++) {
			scope.spawn(cpp_coro_test(pool, &lock_v, &count));
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			STAMP_CPU_PAUSE();
		}
	}
	scope.join();
}
// does not work? one task remains after joining.
BENCHMARK(CppCoroTest)->Range(8, 8192)->MinTime(3.0);

coroutine<void> co_lock_test(co_lock* lock_v, std::atomic_int* counter) {
	using namespace std::chrono_literals;
	auto& tp = *thread_pool::current_threadpool();
	for (int i = 0; i < 10; i++) {
		auto l = lock_v->lock_guard();
		co_await l.lock();
		for (int k = 0; k < 50; k++) {
			benchmark::DoNotOptimize(k);
		}
		l.unlock();
		co_await tp;
	}

	counter->fetch_add(1);
}

static void CoLockTest(benchmark::State& state) {
	int loop_count = state.range(0);

	thread_pool pool{4};
	std::atomic_int count{0};
	co_lock lock_v{};
	for (auto _ : state) {
		count.store(0);

		for (int i = 0; i < loop_count; i++) {
			pool.queue().emplace(co_lock_test, &lock_v, &count);
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			STAMP_CPU_PAUSE();
		}
		if (pool.queue().size_aprox() > 0) {
			STAMP_BREAKPOINT();
		}
	}
	pool.kill();
}
BENCHMARK(CoLockTest)->Range(8, 8192)->MinTime(3.0);

coroutine<void> mutex_test(std::mutex* lock_v, std::atomic_int* counter) {
	using namespace std::chrono_literals;
	auto& tp = *thread_pool::current_threadpool();

	for (int i = 0; i < 10; i++) {
		lock_v->lock();
		for (int k = 0; k < 50; k++) {
			benchmark::DoNotOptimize(k);
		}
		lock_v->unlock();
		co_await tp;
	}

	counter->fetch_add(1);

	co_return;
}

static void MutexTest(benchmark::State& state) {
	int loop_count = state.range(0);

	thread_pool pool{4};
	std::atomic_int count{0};
	std::mutex lock_v{};
	for (auto _ : state) {
		count.store(0);

		for (int i = 0; i < loop_count; i++) {
			pool.queue().emplace(mutex_test, &lock_v, &count);
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			STAMP_CPU_PAUSE();
		}
		if (pool.queue().size_aprox() > 0) {
			STAMP_BREAKPOINT();
		}
	}
	pool.kill();
}
BENCHMARK(MutexTest)->Range(8, 8192)->MinTime(3.0);

void mutex_thread_test(std::mutex* lock_v, std::atomic_int* counter) {
	using namespace std::chrono_literals;

	for (int i = 0; i < 10; i++) {
		lock_v->lock();
		for (int k = 0; k < 50; k++) {
			benchmark::DoNotOptimize(k);
		}
		lock_v->unlock();
	}

	counter->fetch_add(1);

	return;
}
static void MutexThreadTest(benchmark::State& state) {
	int loop_count = state.range(0);

	std::atomic_int count{0};
	std::mutex lock_v{};
	std::vector<std::thread> threads{};
	for (auto _ : state) {
		count.store(0);

		threads.clear();
		for (int i = 0; i < loop_count; i++) {
			threads.emplace_back(mutex_thread_test, &lock_v, &count);
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			STAMP_CPU_PAUSE();
		}

		for (int i = 0; i < loop_count; i++) {
			threads[i].join();
		}
	}
}
// BENCHMARK(MutexThreadTest)->RangeMultiplier(4)->Range(4, 64)->MinTime(3.0);


BENCHMARK_MAIN();


/*struct timed_t {
	std::thread::id id;
	std::chrono::steady_clock::time_point time;
};

coroutine<void> run_test(thread_pool& pool, std::vector<timed_t>& vector) {
	co_await pool;
	for(int i = 0; i < 500; i++) {
		vector.push_back({
			std::this_thread::get_id(),
			std::chrono::steady_clock::now()
		});
		co_yield{};
	}
}

void print_index(const char* c, int index) {
	for (int i = 0; i < index; ++i) {
		std::cout << "    ";
	}
	std::cout << c << std::endl;
}
void print_duration(const char* c, int index, int count) {
	for (int i = 0; i < count; ++i) {
		print_index(c, index);
	}
}

coroutine<void> looping_test(int a) {
	for (int i = 0; i < a; i++) {
		co_yield{};
	}
	co_return;
}

int main(int argc, char** argv) {
	using namespace std::chrono_literals;

	SetConsoleOutputCP(CP_UTF8);

	for (int i = 0; i < 1000; i++) {
		coroutine<void> looping_test_v = looping_test(50000);
		looping_test_v.pause_interval(0, false);
		looping_test_v.resume();
	}

	thread_pool pool{};
	std::vector<timed_t> vector{};
	coroutine<void> run_test_v = pool.enqueue(run_test, pool, vector);

	run_test_v.wait();

	int next_index = 0;
	std::map<std::thread::id, int> map{};

	std::chrono::steady_clock::time_point prev = vector[0].time;

	auto total_delta = vector[vector.size() - 1].time - vector[0].time;
	std::chrono::duration<float> total_delta_float = total_delta;
	float total_duration = total_delta_float.count();

	int total_lines = 1000;

	std::cout << "seconds per line: " << (total_duration / total_lines) << std::endl;

	for (auto& v : vector) {
		int index;
		if (auto p = map.find(v.id); p != map.end()) {
			index = p->second;
		}
		else {
			map.emplace(v.id, next_index);
			index = next_index;
			next_index++;
		}
		auto delta = v.time - prev;
		prev = v.time;
		std::chrono::duration<float> delta_float = delta;
		float duration = delta_float.count();
		float duration_percent = duration / total_duration;
		int lines = std::ceil(duration_percent * total_lines);
		print_duration("████", index, lines - 1);
		print_index("▒▒▒▒", index);
		std::cout << std::endl;
	}

	pool.kill();
}*/
