/**
 * @file source.cpp
 * @brief Performance profiling of the StampEngine Coroutine System using Google Benchmark
 */

#include <stamp/task/coroutine.h>
#include <benchmark/benchmark.h>
#include <unordered_map>
#include <mutex>

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
		task.pause_interval(state.range(1), true);
		while (!task.done()) 
			task.resume();
		benchmark::DoNotOptimize(task);
	}
	state.SetItemsProcessed(state.range(0) * state.iterations());
}
BENCHMARK(LoopingTest)->RangeMultiplier(4)->Ranges({{1024, 1024}, {1, 1024}});

BENCHMARK_MAIN();

/*coroutine<void> looping_test() {
	int c = 0;
	while (true) {
		std::cout << "loop " << c << std::endl;
		c++;
		co_yield void_t{};
	}
}

int main(int argc, char** argv) {
	coroutine<void> looping_test_v = looping_test();
	looping_test_v.pause_interval(3, true);
	for (int i = 0; i < 100; i++) {
		looping_test_v.resume();
		std::cout << "auto paused" << std::endl;
	}
}*/
