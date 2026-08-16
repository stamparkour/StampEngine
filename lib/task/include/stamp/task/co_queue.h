// stamp/task/co_queue.h

#ifndef STAMP_TASK_CO_QUEUE_H
#define STAMP_TASK_CO_QUEUE_H

#include <atomic>

namespace stamp::task {
	class co_queue {
		std::atomic<void*> next_handle;
	public:
		void invoke() {
			void* next = next_handle.exchange(nullptr);
			if (next != nullptr) {
				std::coroutine_handle<>::from_address(next).resume();
			}
		}
		auto operator co_await() {
			struct co_await_t {
				co_queue& queue;
				void* next;

				bool await_ready() { return false; }
				void await_suspend(std::coroutine_handle<> h) {
					next = queue.next_handle.exchange(h.address());
				}
				void await_resume() {
					if (next != nullptr) {
						std::coroutine_handle<>::from_address(next).resume();
					}
				}
			};
			return co_await_t{*this};
		}
	};
}

#endif // STAMP_TASK_CO_QUEUE_H