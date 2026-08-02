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

	// thread_pool: convert awaitable to a wait_until condition using timer_task_queue
	// coroutine mutex
	// co_await timer_task_queue
	// fix kill() to kill stuck coroutines
	// add monitor coroutine that checks threads periodically.
	class thread_pool {
		struct thread_state {
			alignas(std::atomic_ref<coroutine_view<void>>::required_alignment) coroutine_view<void> current_task;
			alignas(std::atomic_ref<unsigned int>::required_alignment) unsigned int update_count;
			alignas(std::atomic_ref<bool>::required_alignment) bool should_end;
		};

		std::vector<std::thread> thread_vector{};
		std::vector<thread_state> state_vector{};
		task_queue queue_v{8192};

		thread_state timer_thread_state;
		timer_task_queue timer_queue_v{};
		std::thread timer_thread;

		static void timer_thread_func(thread_pool* pool) {
			thread_state& state = pool->timer_thread_state;
			std::atomic_ref<bool> should_end{state.should_end};

			while (true) {
				if (should_end.load()) break;

				auto v = pool->timer_queue_v.pop_wait();
				state.current_task = v;
				v.resume();
				state.current_task = nullptr;
			}
		}

		static void thread_func(thread_pool* pool, int index) {
			thread_state& state = pool->state_vector[index];
			std::atomic_ref<bool> should_end{state.should_end};

			while (true) {
				if (should_end.load()) break;

				auto size = pool->queue_v.size_aprox();
				auto max = pool->thread_vector.size();

				std::size_t count;
				if (size > max * 16)	count = 16;
				else if (size > max)	count = size / pool->thread_vector.size();
				else					count = 1;

				task_bulk tasks = pool->queue_v.wait_dequeue_bulk(count); // do some smarter thing (like checking what the current queue size is
				for (auto& v : tasks) {
					if (!v) continue;

					state.current_task = v;

					auto co = [&](coroutine_view<void>& target) -> coroutine<void> {
						co_await target.await_interupt();
						/*if (target.is_yielded()) {
						}
						else if (target.done()) {
						}
						// is co_await
						else {  
						}*/
						state.current_task = nullptr;
					}(v);

					v.resume();


					// pool->queue.enqueue(v);

					++state.update_count;
				}
				state.current_task = nullptr;
			}

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

			timer_thread = std::thread{timer_thread_func, this};
		}

		task_queue& queue() {
			return queue_v;
		}
		const task_queue& queue() const {
			return queue_v;
		}
		timer_task_queue& timer_queue() {
			return timer_queue_v;
		}
		const timer_task_queue& timer_queue() const {
			return timer_queue_v;
		}


		/*template<typename T>
		struct co_until_t {
			bool await_ready() noexcept {
				return false;
			}
			template<typename T>
			bool await_suspend(decltype(auto) handle) noexcept {
				return true;
			}
			void await_resume() noexcept {}
		};
		template<typename T> requires awaitable_c<T>
		auto co_until(const timer_task_queue::time_point& time, T&& awaitable) {

		}*/

		void kill() {
			for (auto& v : state_vector) {
				std::atomic_ref<bool> should_end{v.should_end};
				should_end.store(true);
			}

			coroutine<void> v1 = queue_v.emplace([](thread_pool& pool) -> coroutine<void> {
				while (true) {
					co_await pool.queue();
				}
			}, *this);

			std::atomic_ref<bool> should_end{timer_thread_state.should_end};
			should_end.store(true);

			coroutine<void> v2 = timer_queue_v.emplace_until(timer_task_queue::clock::now(), [](thread_pool& pool) -> coroutine<void> {
				co_return;
			}, *this);

			for (auto& v : thread_vector) {
				v.join();
			}
			timer_thread.join();
		}
	};

	// 
}

#endif // STAMP_TASK_THREAD_POOL_H
