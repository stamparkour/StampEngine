/**
 * @file source.cpp
 * @brief Performance profiling of the StampEngine Coroutine System using Google Benchmark
 */

#include <stamp/task/coroutine.h>
#include <stamp/task/task_queue.h>
#include <stamp/task/thread_pool.h>
#include <stamp/task/co_lock.h>
#include <benchmark/benchmark.h>
#include <unordered_map>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <windows.h>

using namespace stamp::task;


coroutine<void> co_lock_test(co_lock_shared* lock, std::atomic_int* counter) {
	using namespace std::chrono_literals;
	for (int i = 0; i < 10; i++) {
		if (i == 7) {
			auto l = co_await lock->lock();
			for (int k = 0; k < 50; k++) {
				benchmark::DoNotOptimize(k);
			}
		}
		else {
			auto l = co_await lock->lock_shared();

			for (int k = 0; k < 50; k++) {
				benchmark::DoNotOptimize(k);
			}
		}
	}

	counter->fetch_add(1);
	counter->notify_all();
}

static void CoLockTest(benchmark::State& state) {
	constexpr int loop_count = 2000;

	thread_pool pool{4};
	std::atomic_int count{0};
	co_lock_shared lock{};
	for (auto _ : state) {
		count.store(0);

		for (int i = 0; i < loop_count; i++) {
			pool.queue().emplace_detached(co_lock_test, &lock, &count);
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			count.wait(tmp);
		}
	}
	pool.kill();
}
BENCHMARK(CoLockTest)->Iterations(1000);

coroutine<void> mutex_test(std::shared_mutex* lock, std::atomic_int* counter) {
	using namespace std::chrono_literals;

	for (int i = 0; i < 10; i++) {
		if (i == 7) {
			lock->lock_shared();
			for (int k = 0; k < 50; k++) {
				benchmark::DoNotOptimize(k);
			}
			lock->unlock_shared();
		}
		else {
			lock->lock();
			for (int k = 0; k < 50; k++) {
				benchmark::DoNotOptimize(k);
			}
			lock->unlock();
		}
	}

	counter->fetch_add(1);
	counter->notify_all();

	co_return;
}

static void MutexTest(benchmark::State& state) {
	constexpr int loop_count = 2000;

	thread_pool pool{4};
	std::atomic_int count{0};
	std::shared_mutex lock{};
	for (auto _ : state) {
		count.store(0);

		for (int i = 0; i < loop_count; i++) {
			pool.queue().emplace_detached(mutex_test, &lock, &count);
		}

		int tmp;
		while ((tmp = count.load()) != loop_count) {
			count.wait(tmp);
		}
	}
	pool.kill();
}
BENCHMARK(MutexTest)->Iterations(1000);

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
