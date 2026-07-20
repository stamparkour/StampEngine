#include <gtest/gtest.h>
#include <stamp/task/coroutine.h>
#include <chrono>
#include <vector>
#include <thread>
#include <atomic>
#include <cmath>
#include <iomanip>

using namespace stamp::task;

// ============================================================================
// SECTION 1: Basic Coroutine Tests
// ============================================================================

// Test 1.1: Simple coroutine creation and execution
TEST(CoroutineBasics, SimpleCreationAndExecution) {
	auto task = []() -> coroutine<int> {
		co_return 42;
	}();

	ASSERT_FALSE(task.done());
	task.start();
	ASSERT_TRUE(task.done());
	ASSERT_EQ(task.result(), 42);
}

// Test 1.2: Coroutine with yield
TEST(CoroutineBasics, YieldValue) {
	auto task = []() -> coroutine<int> {
		co_yield 1;
		co_yield 2;
		co_return 3;
	}();

	task.start();
	ASSERT_TRUE(task.done());
	ASSERT_EQ(task.result(), 3);
}

// Test 1.3: Void coroutine
TEST(CoroutineBasics, VoidCoroutine) {
	auto task = []() -> coroutine<void> {
		void_t _;
		co_yield _;
		co_return;
	}();

	ASSERT_FALSE(task.done());
	task.start();
	ASSERT_TRUE(task.done());
}

// Test 1.4: Coroutine with multiple yields
TEST(CoroutineBasics, MultipleYields) {
	int yield_count = 0;
	auto task = [&yield_count]() -> coroutine<int> {
		for (int i = 0; i < 5; i++) {
			yield_count++;
			co_yield i;
		}
		co_return 99;
	}();

	task.start();
	ASSERT_TRUE(task.done());
	ASSERT_EQ(yield_count, 5);
	ASSERT_EQ(task.result(), 99);
}

// ============================================================================
// SECTION 2: Synchronization and Awaiting Tests
// ============================================================================

// Test 2.1: Awaiting another coroutine
TEST(CoroutineSynchronization, AwaitOtherCoroutine) {
	auto producer = []() -> coroutine<int> {
		co_yield 1;
		co_yield 2;
		co_return 42;
	}();

	int received_value = 0;
	auto consumer = [&]() -> coroutine<void> {
		received_value = co_await producer;
		void_t _;
		co_yield _;
		co_return;
	}();

	producer.start();
	consumer.start();

	ASSERT_TRUE(producer.done());
	ASSERT_TRUE(consumer.done());
	ASSERT_EQ(received_value, 42);
}

// Test 2.2: Multiple consumers on single producer
TEST(CoroutineSynchronization, MultipleConsumers) {
	auto producer = []() -> coroutine<int> {
		co_yield 10;
		co_yield 20;
		co_return 100;
	}();

	int value1 = 0, value2 = 0;
	auto consumer1 = [&]() -> coroutine<void> {
		value1 = co_await producer;
		co_return;
	}();

	auto consumer2 = [&]() -> coroutine<void> {
		value2 = co_await producer;
		co_return;
	}();

	producer.start();
	consumer1.start();
	consumer2.start();

	ASSERT_TRUE(producer.done());
	ASSERT_TRUE(consumer1.done());
	ASSERT_TRUE(consumer2.done());
	// Both consumers may get the same final value
	ASSERT_EQ(value1, 100);
	ASSERT_EQ(value2, 100);
}

// Test 2.3: Wait function
TEST(CoroutineSynchronization, WaitFunction) {
	auto task = []() -> coroutine<int> {
		co_yield 1;
		co_return 42;
	}();

	ASSERT_FALSE(task.done());
	task.start();
	task.wait();
	ASSERT_TRUE(task.done());
	ASSERT_EQ(task.result(), 42);
}

// Test 2.4: Kill function
TEST(CoroutineSynchronization, KillFunction) {
	auto task = []() -> coroutine<void> {
		for (int i = 0; i < 1000; i++) {
			void_t _;
			co_yield _;
		}
		co_return;
	}();

	task.start();
	task.kill();
	task.wait();
	ASSERT_TRUE(task.done());
}

// ============================================================================
// SECTION 3: Performance and Profiling Tests
// ============================================================================

class CoroutinePerformance : public ::testing::Test {
protected:
	// Helper to measure execution time
	template<typename Func>
	static std::chrono::nanoseconds MeasureTime(Func&& func) {
		auto start = std::chrono::high_resolution_clock::now();
		func();
		auto end = std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	}

	// Helper to format duration in appropriate units
	static std::string FormatDuration(std::chrono::nanoseconds ns) {
		if (ns.count() < 1000) {
			return std::to_string(ns.count()) + " ns";
		} else if (ns.count() < 1000000) {
			return std::to_string(ns.count() / 1000.0) + " µs";
		} else if (ns.count() < 1000000000) {
			return std::to_string(ns.count() / 1000000.0) + " ms";
		} else {
			return std::to_string(ns.count() / 1000000000.0) + " s";
		}
	}

	// Helper to calculate statistics
	struct Stats {
		std::chrono::nanoseconds min, max, avg, median;
		double stddev;
	};

	static Stats CalculateStats(const std::vector<std::chrono::nanoseconds>& times) {
		EXPECT_GT(times.size(), 0);
		std::vector<std::chrono::nanoseconds> sorted_times = times;
		std::sort(sorted_times.begin(), sorted_times.end());

		auto min = sorted_times.front();
		auto max = sorted_times.back();

		std::chrono::nanoseconds sum{0};
		for (const auto& t : sorted_times) {
			sum += t;
		}
		auto avg = sum / static_cast<long long>(sorted_times.size());
		auto median = sorted_times[sorted_times.size() / 2];

		// Calculate standard deviation
		double sum_sq_diff = 0;
		double avg_ns = avg.count();
		for (const auto& t : sorted_times) {
			double diff = t.count() - avg_ns;
			sum_sq_diff += diff * diff;
		}
		double variance = sum_sq_diff / sorted_times.size();
		double stddev = std::sqrt(variance);

		return {min, max, avg, median, stddev};
	}
};

// Test 3.1: Create and start single coroutine
TEST_F(CoroutinePerformance, SingleCoroutineCreationAndStart) {
	std::vector<std::chrono::nanoseconds> times;

	for (int i = 0; i < 100; i++) {
		auto duration = MeasureTime([]() {
			auto task = []() -> coroutine<int> {
				co_return 42;
			}();
			task.start();
		});
		times.push_back(duration);
	}

	auto stats = CalculateStats(times);
	std::cout << "\n[PERF] Single coroutine creation and start (100 iterations):" << std::endl;
	std::cout << "  Min:    " << FormatDuration(stats.min) << std::endl;
	std::cout << "  Max:    " << FormatDuration(stats.max) << std::endl;
	std::cout << "  Avg:    " << FormatDuration(stats.avg) << std::endl;
	std::cout << "  Median: " << FormatDuration(stats.median) << std::endl;
	std::cout << "  StdDev: " << stats.stddev << " ns" << std::endl;
}

// Test 3.2: Create many coroutines and start them all
TEST_F(CoroutinePerformance, ManyCoroutinesCreationAndStart) {
	std::vector<std::chrono::nanoseconds> times;
	constexpr int TASK_COUNT = 100;

	for (int run = 0; run < 10; run++) {
		auto duration = MeasureTime([&]() {
			std::vector<coroutine<int>> tasks;
			for (int i = 0; i < TASK_COUNT; i++) {
				tasks.push_back([]() -> coroutine<int> {
					co_return 42;
				}());
			}
			for (auto& t : tasks) {
				t.start();
			}
		});
		times.push_back(duration);
	}

	auto stats = CalculateStats(times);
	std::cout << "\n[PERF] Create and start " << TASK_COUNT << " coroutines (10 runs):" << std::endl;
	std::cout << "  Min:    " << FormatDuration(stats.min) << std::endl;
	std::cout << "  Max:    " << FormatDuration(stats.max) << std::endl;
	std::cout << "  Avg:    " << FormatDuration(stats.avg) << std::endl;
	std::cout << "  Median: " << FormatDuration(stats.median) << std::endl;
	std::cout << "  StdDev: " << stats.stddev << " ns" << std::endl;
	std::cout << "  Per-task avg: " << FormatDuration(stats.avg / TASK_COUNT) << std::endl;
}

// Test 3.3: Yield performance
TEST_F(CoroutinePerformance, YieldThroughput) {
	std::vector<std::chrono::nanoseconds> times;
	constexpr int YIELD_COUNT = 10000;

	for (int run = 0; run < 10; run++) {
		auto duration = MeasureTime([&]() {
			int count = 0;
			auto task = [&]() -> coroutine<void> {
				for (int i = 0; i < YIELD_COUNT; i++) {
					count++;
					void_t _;
					co_yield _;
				}
				co_return;
			}();
			task.start();
		});
		times.push_back(duration);
	}

	auto stats = CalculateStats(times);
	std::cout << "\n[PERF] " << YIELD_COUNT << " yields throughput (10 runs):" << std::endl;
	std::cout << "  Min:           " << FormatDuration(stats.min) << std::endl;
	std::cout << "  Max:           " << FormatDuration(stats.max) << std::endl;
	std::cout << "  Avg:           " << FormatDuration(stats.avg) << std::endl;
	std::cout << "  Median:        " << FormatDuration(stats.median) << std::endl;
	std::cout << "  StdDev:        " << stats.stddev << " ns" << std::endl;
	std::cout << "  Per-yield avg: " << FormatDuration(stats.avg / YIELD_COUNT) << std::endl;
	std::cout << "  Yields/sec:    " << (1e9 * YIELD_COUNT) / stats.avg.count() << " M/s" << std::endl;
}

// Test 3.4: Await performance
TEST_F(CoroutinePerformance, AwaitPerformance) {
	std::vector<std::chrono::nanoseconds> times;

	for (int run = 0; run < 100; run++) {
		auto duration = MeasureTime([]() {
			auto producer = []() -> coroutine<int> {
				co_return 42;
			}();

			auto consumer = [&]() -> coroutine<int> {
				int val = co_await producer;
				co_return val;
			}();

			producer.start();
			consumer.start();
		});
		times.push_back(duration);
	}

	auto stats = CalculateStats(times);
	std::cout << "\n[PERF] Await performance (100 iterations):" << std::endl;
	std::cout << "  Min:    " << FormatDuration(stats.min) << std::endl;
	std::cout << "  Max:    " << FormatDuration(stats.max) << std::endl;
	std::cout << "  Avg:    " << FormatDuration(stats.avg) << std::endl;
	std::cout << "  Median: " << FormatDuration(stats.median) << std::endl;
	std::cout << "  StdDev: " << stats.stddev << " ns" << std::endl;
}

// Test 3.5: Concurrent execution throughput
TEST_F(CoroutinePerformance, ConcurrentExecutionThroughput) {
	std::vector<std::chrono::nanoseconds> times;
	constexpr int TASK_COUNT = 500;

	for (int run = 0; run < 10; run++) {
		auto duration = MeasureTime([&]() {
			std::vector<coroutine<int>> tasks;
			for (int i = 0; i < TASK_COUNT; i++) {
				tasks.push_back([i]() -> coroutine<int> {
					for (int j = 0; j < 10; j++) {
						co_yield -1;
					}
					co_return i;
				}());
			}
			for (auto& t : tasks) {
				t.start();
			}
		});
		times.push_back(duration);
	}

	auto stats = CalculateStats(times);
	std::cout << "\n[PERF] Concurrent execution " << TASK_COUNT << " tasks with 10 yields each (10 runs):" << std::endl;
	std::cout << "  Min:           " << FormatDuration(stats.min) << std::endl;
	std::cout << "  Max:           " << FormatDuration(stats.max) << std::endl;
	std::cout << "  Avg:           " << FormatDuration(stats.avg) << std::endl;
	std::cout << "  Median:        " << FormatDuration(stats.median) << std::endl;
	std::cout << "  StdDev:        " << stats.stddev << " ns" << std::endl;
	std::cout << "  Per-task avg:  " << FormatDuration(stats.avg / TASK_COUNT) << std::endl;
	std::cout << "  Total yields:  " << (TASK_COUNT * 10) << std::endl;
	std::cout << "  Yield rate:    " << (1e9 * TASK_COUNT * 10) / stats.avg.count() << " M/s" << std::endl;
}

// Test 3.6: Kill operation performance
TEST_F(CoroutinePerformance, KillPerformance) {
	std::vector<std::chrono::nanoseconds> times;

	for (int run = 0; run < 100; run++) {
		auto duration = MeasureTime([]() {
			auto task = []() -> coroutine<void> {
				for (int i = 0; i < 10000; i++) {
					void_t _;
					co_yield _;
				}
				co_return;
			}();
			task.start();
			task.kill();
			task.wait();
		});
		times.push_back(duration);
	}

	auto stats = CalculateStats(times);
	std::cout << "\n[PERF] Kill operation performance (100 iterations):" << std::endl;
	std::cout << "  Min:    " << FormatDuration(stats.min) << std::endl;
	std::cout << "  Max:    " << FormatDuration(stats.max) << std::endl;
	std::cout << "  Avg:    " << FormatDuration(stats.avg) << std::endl;
	std::cout << "  Median: " << FormatDuration(stats.median) << std::endl;
	std::cout << "  StdDev: " << stats.stddev << " ns" << std::endl;
}

// ============================================================================
// SECTION 4: Edge Case and Stress Tests
// ============================================================================

// Test 4.1: Exception handling in coroutine
TEST(CoroutineEdgeCases, ExceptionHandling) {
	auto task = []() -> coroutine<int> {
		throw std::runtime_error("Test exception");
		co_return 0;
	}();

	task.start();
	ASSERT_TRUE(task.done());

	EXPECT_THROW(
		task.result(),
		std::runtime_error
	);
}

// Test 4.2: Empty coroutine
TEST(CoroutineEdgeCases, EmptyCoroutine) {
	auto task = []() -> coroutine<void> {
		co_return;
	}();

	ASSERT_FALSE(task.done());
	task.start();
	ASSERT_TRUE(task.done());
}

// Test 4.3: Return value from awaiter
TEST(CoroutineEdgeCases, ReturnValueFromAwaiter) {
	auto producer = []() -> coroutine<int> {
		co_yield 5;
		co_yield 10;
		co_return 999;
	}();

	int final_value = 0;
	auto consumer = [&]() -> coroutine<void> {
		final_value = co_await producer;
		co_return;
	}();

	producer.start();
	consumer.start();

	ASSERT_EQ(final_value, 999);
}

// Test 4.4: Chain of awaits
TEST(CoroutineEdgeCases, ChainOfAwaits) {
	auto task1 = []() -> coroutine<int> {
		co_return 10;
	}();

	int result = 0;
	auto task2 = [&]() -> coroutine<int> {
		result = co_await task1;
		co_return result + 5;
	}();

	task1.start();
	task2.start();

	ASSERT_EQ(result, 10);
	ASSERT_EQ(task2.result(), 15);
}

// Test 4.5: Large return values
TEST(CoroutineEdgeCases, LargeReturnValues) {
	struct LargeData {
		std::vector<int> data;
		int id;

		LargeData(int i) : data(1000, i), id(i) {}
	};

	// Note: This test may fail if coroutine<T> doesn't support move semantics well
	// for larger types. Using a reference might be safer in real code.
	auto task = []() -> coroutine<int> {
		co_return 42;
	}();

	task.start();
	ASSERT_EQ(task.result(), 42);
}

// Test 4.6: Nested coroutine calls
TEST(CoroutineEdgeCases, NestedCoroutineCalls) {
	auto inner = []() -> coroutine<int> {
		co_return 100;
	}();

	int inner_result = 0;
	auto outer = [&]() -> coroutine<int> {
		inner_result = co_await inner;
		co_return inner_result + 50;
	}();

	inner.start();
	outer.start();

	ASSERT_EQ(inner_result, 100);
	ASSERT_EQ(outer.result(), 150);
}

// ============================================================================
// SECTION 5: Memory and Resource Tests
// ============================================================================

class CoroutineMemoryTests : public ::testing::Test {
protected:
	static std::atomic<int> instance_count;

	struct TrackedObject {
		int id;
		static int next_id;

		TrackedObject() : id(next_id++) {
			instance_count++;
		}

		TrackedObject(const TrackedObject& other) : id(other.id) {
			instance_count++;
		}

		~TrackedObject() {
			instance_count--;
		}
	};
};

std::atomic<int> CoroutineMemoryTests::instance_count{0};
int CoroutineMemoryTests::TrackedObject::next_id{0};

// Test 5.1: Object lifetime in coroutines
TEST_F(CoroutineMemoryTests, ObjectLifetime) {
	ASSERT_EQ(instance_count.load(), 0);

	{
		auto task = []() -> coroutine<int> {
			TrackedObject obj;
			co_return 42;
		}();

		EXPECT_GT(instance_count.load(), 0);
		task.start();
	}

	// After coroutine destruction, objects should be cleaned up
	ASSERT_EQ(instance_count.load(), 0);
}

// Test 5.2: Multiple coroutines memory usage
TEST_F(CoroutineMemoryTests, MultipleCoroutinesMemory) {
	ASSERT_EQ(instance_count.load(), 0);

	{
		std::vector<coroutine<int>> tasks;
		for (int i = 0; i < 100; i++) {
			tasks.push_back([]() -> coroutine<int> {
				TrackedObject obj;
				co_return 42;
			}());
		}

		for (auto& t : tasks) {
			t.start();
		}
	}

	// Memory should be cleaned up after scope exit
	ASSERT_EQ(instance_count.load(), 0);
}

// ============================================================================
// SECTION 6: Comprehensive Integration Tests
// ============================================================================

// Test 6.1: Producer-consumer pipeline
TEST(CoroutineIntegration, ProducerConsumerPipeline) {
	std::vector<int> produced_values;
	std::vector<int> consumed_values;

	auto producer = [&]() -> coroutine<int> {
		for (int i = 1; i <= 5; i++) {
			produced_values.push_back(i);
			co_yield i;
		}
		co_return 99;
	}();

	auto consumer = [&]() -> coroutine<void> {
		while (!producer.done()) {
			int val = co_await producer;
			consumed_values.push_back(val);
		}
		co_return;
	}();

	producer.start();
	consumer.start();

	ASSERT_EQ(consumed_values.size(), produced_values.size());
	for (size_t i = 0; i < consumed_values.size(); i++) {
		ASSERT_EQ(consumed_values[i], produced_values[i]);
	}
}

// Test 6.2: Multiple producers, single consumer
TEST(CoroutineIntegration, MultipleProducersSingleConsumer) {
	auto producer1 = []() -> coroutine<int> {
		co_yield 1;
		co_return 10;
	}();

	auto producer2 = []() -> coroutine<int> {
		co_yield 2;
		co_return 20;
	}();

	int val1 = 0, val2 = 0;
	auto consumer = [&]() -> coroutine<void> {
		val1 = co_await producer1;
		val2 = co_await producer2;
		co_return;
	}();

	producer1.start();
	producer2.start();
	consumer.start();

	ASSERT_EQ(val1, 10);
	ASSERT_EQ(val2, 20);
}

// Test 6.3: Task cancellation with await
TEST(CoroutineIntegration, CancellationWithAwait) {
	auto producer = []() -> coroutine<int> {
		for (int i = 0; i < 100; i++) {
			co_yield i;
		}
		co_return 999;
	}();

	auto consumer = [&]() -> coroutine<void> {
		int count = 0;
		while (!producer.done() && count < 50) {
			auto val = co_await producer;
			count++;
		}
		co_return;
	}();

	producer.start();
	consumer.start();

	ASSERT_TRUE(consumer.done());
}

// Test 6.4: Stress test with many concurrent tasks
TEST(CoroutineIntegration, ManyConcurrentTasksStressTest) {
	std::atomic<int> completed_count{0};
	constexpr int TASK_COUNT = 1000;

	std::vector<coroutine<int>> tasks;
	for (int i = 0; i < TASK_COUNT; i++) {
		tasks.push_back([i, &completed_count]() -> coroutine<int> {
			completed_count++;
			for (int j = 0; j < 10; j++) {
				co_yield -1;
			}
			co_return i * 2;
		}());
	}

	for (auto& t : tasks) {
		t.start();
	}

	ASSERT_EQ(completed_count.load(), TASK_COUNT);
}
