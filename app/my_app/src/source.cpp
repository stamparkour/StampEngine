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
#include <chrono>
#include <windows.h>

using namespace stamp::task;


coroutine<void> looping_test(int a) {
	for(int i = 0; i < a; i++) {
		benchmark::DoNotOptimize(i);
		co_yield{};
	}
	co_return;
}

static void LoopingTest(benchmark::State& state) {
	for (auto _ : state) {
		auto task = looping_test(state.range(0));
		while (!task.done()) 
			task.resume();
		benchmark::DoNotOptimize(task);
	}
	state.SetItemsProcessed(state.range(0) * state.iterations());
}
BENCHMARK(LoopingTest)->Iterations(10000)->RangeMultiplier(4)->Ranges({{2048, 2048}});

coroutine<void> schedular_test(thread_pool& pool, std::atomic_int& ct) {
	ct++;
	ct.notify_all();
	co_return;
}

static void SchedularTest(benchmark::State& state) {
	thread_pool pool{(unsigned int)state.range(1)};
	std::atomic_int count{0};
	for (auto _ : state) {
		count.store(0);
		for (int i = 0; i < state.range(0); i++) {
			pool.enqueue_detached(schedular_test, pool, count);
		}
		int current_count;
		while ((current_count = count.load()) < state.range(0)) {
			count.wait(current_count);
		}
	}
	pool.kill();
	state.SetItemsProcessed(state.range(0) * state.iterations());
}
BENCHMARK(SchedularTest)->Iterations(3000)->RangeMultiplier(2)->Ranges({{2048, 2048}, {1, 16}});

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
