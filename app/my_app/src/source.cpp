/**
 * @file source.cpp
 * @brief Performance profiling of the StampEngine Coroutine System using Google Benchmark
 */

#include <stamp/task/coroutine.h>
#include <benchmark/benchmark.h>

using namespace stamp::task;

// --- Helpers ---

coroutine<void> empty_task() {
	co_return;
}

coroutine<int> yield_value_task(int count) {
	for (int i = 0; i < count; i++) {
		co_yield i;
	}
	co_return count;
}

coroutine<void> yield_void_task(int count) {
	for (int i = 0; i < count; i++) {
		void_t _;
		co_yield _;
	}
	co_return;
}

coroutine<void> consumer_task(const coroutine<int>& producer) {
	while (!producer.done()) {
		auto val = co_await producer;
		(void)val;
	}
	co_return;
}

// --- Benchmarks ---

static void BM_TaskCreationAndDestruction(benchmark::State& state) {
	for (auto _ : state) {
		auto task = empty_task();
		benchmark::DoNotOptimize(task);
	}
}
BENCHMARK(BM_TaskCreationAndDestruction);

static void BM_TaskExecutionEmpty(benchmark::State& state) {
	for (auto _ : state) {
		auto task = empty_task();
		task.start();
		task.wait();
	}
}
BENCHMARK(BM_TaskExecutionEmpty);

static void BM_TaskYieldValues(benchmark::State& state) {
	int yields_per_task = state.range(0);
	for (auto _ : state) {
		state.PauseTiming();
		auto task = yield_value_task(yields_per_task);
		state.ResumeTiming();

		task.start();
		while (!task.done()) {
			task.start(); // Resumes
		}
		task.wait();
	}
	state.SetItemsProcessed(state.iterations() * yields_per_task);
}
BENCHMARK(BM_TaskYieldValues)->Range(1, 1024);

static void BM_TaskYieldVoid(benchmark::State& state) {
	int yields_per_task = state.range(0);
	for (auto _ : state) {
		state.PauseTiming();
		auto task = yield_void_task(yields_per_task);
		state.ResumeTiming();

		task.start();
		while (!task.done()) {
			task.start(); // Resumes
		}
		task.wait();
	}
	state.SetItemsProcessed(state.iterations() * yields_per_task);
}
BENCHMARK(BM_TaskYieldVoid)->Range(1, 1024);

static void BM_TaskAwait(benchmark::State& state) {
	int yields = state.range(0);
	for (auto _ : state) {
		state.PauseTiming();
		auto prod = yield_value_task(yields);
		auto cons = consumer_task(prod);
		state.ResumeTiming();

		prod.start();
		cons.start();

		while (!cons.done()) {
			cons.start();
			prod.start();
		}
	}
}
BENCHMARK(BM_TaskAwait)->Range(1, 1024);

BENCHMARK_MAIN();
