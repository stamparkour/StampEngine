// stamp/task/thread_pool.h
#ifndef STAMP_TASK_THREAD_POOL_H
#define STAMP_TASK_THREAD_POOL_H

#include <stamp/task/coroutine.h>
#include <stamp/task/task_queue.h>
#include <vector>
#include <thread>
#include <atomic>
#include <stdexcept>
#include <iostream>
#include <atomic>

namespace stamp::task {
	inline constexpr auto fallback_thread_count_v = 4;

	// TODO: change coroutine pause to normal bool
	// TODO: add coroutine func that just auto pauses instead of using .is_paused()

	// make thread_pool a more global resource
	// fix kill() to kill stuck coroutines
	// add monitor coroutine that checks threads periodically.
	class thread_pool {
		// threadsafe task queue
		// threadsafe time based priority queue
		struct thread_state {
			alignas(std::atomic_ref<coroutine_view<void>>::required_alignment) coroutine_view<void> current_task;
			alignas(std::atomic_ref<unsigned int>::required_alignment) unsigned int update_count;
			alignas(std::atomic_ref<bool>::required_alignment) bool should_end;
		};

		std::vector<std::thread> thread_vector{};
		std::vector<thread_state> state_vector{};
		task_queue queue{8192};


		static void thread_func(thread_pool* pool, int index) {

			thread_state& state = pool->state_vector[index];
			std::atomic_ref<bool> should_end{state.should_end};
			while (true) {
				if (should_end.load()) goto break_1;
				task_bulk tasks = pool->queue.wait_dequeue_bulk(16); // do some smarter thing (like checking what the current queue size is
				for (auto& v : tasks) {
					if (!v) continue;

					state.current_task = v;

					v.resume();

					if (should_end.load()) goto break_1;

					// pool->queue.enqueue(v);

					++state.update_count;
				}
				state.current_task = nullptr;
			}
			break_1:;

			// pool->state_vector[index] = nullptr;
		}
	public:
		thread_pool() : thread_pool(std::thread::hardware_concurrency()) {}
		thread_pool(unsigned int thread_count) {
			if (thread_count == 0) thread_count = fallback_thread_count_v;
			state_vector.reserve(thread_count);
			thread_vector.reserve(thread_count);

			for (int i = 0; i < thread_count; ++i) {
				state_vector.emplace_back(nullptr, 0, false);
			}
			// do NOT modify vector size after this
			for (int i = 0; i < thread_count; ++i) {
				thread_vector.emplace_back(thread_func, this, i);
			}
		}
		template<typename CoFunc, typename... Args>
		[[nodiscard]] auto enqueue(CoFunc&& func, Args&&... args) {
			return queue.enqueue(std::forward<CoFunc>(func), std::forward<Args>(args)...);
		}
		template<typename CoFunc, typename... Args>
		void enqueue_detached(CoFunc&& func, Args&&... args) {
			queue.enqueue_detached(std::forward<CoFunc>(func), std::forward<Args>(args)...);
		}
		template<typename T>
		void enqueue(coroutine<T>& co) {
			queue.enqueue(coroutine_view<T>{co});
		}
		template<typename T>
		void enqueue(coroutine_view<T>& co) {
			queue.enqueue(co);
		}
		template<typename T>
		void enqueue(coroutine_view<T>&& co) {
			queue.enqueue(co);
		}

		void kill() {
			for (auto& v : state_vector) {
				std::atomic_ref<bool> should_end{v.should_end};
				should_end.store(true);
			}

			coroutine<void> v = enqueue([](thread_pool& pool) -> coroutine<void> {
				while (true) {
					co_await pool;
				}
			}, *this);

			for (auto& v : thread_vector) {
				v.join();
			}
		}

		auto operator co_await() {
			return queue.operator co_await();
		}
	};
}

#endif // STAMP_TASK_THREAD_POOL_H
