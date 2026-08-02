#ifndef STAMP_TASK_CO_LOCK_H

#include <atomic>
#include <coroutine>

namespace stamp::task {
	// not movable, not copyable
	class co_lock {
		std::atomic<void*> next_handle_v;
	public:
		struct co_await_t {
			co_lock* lock_v;
			void* self_handle;
			void* next_handle;

			bool await_ready() {
				return false;
			}
			bool await_suspend(std::coroutine_handle<void> handle) {
				self_handle = handle.address();
				next_handle = lock_v->next_handle_v.exchange(self_handle);
				return next_handle != nullptr; // if nullptr, continue coroutine; else, pause.
			}
			auto await_resume() {
				struct await_resume_t {
					co_lock* lock_v;
					void* self_handle;
					void* next_handle;
					void unlock() {
						if (self_handle == nullptr) return;

						while (true) {
							void* tmp = self_handle;
							//if lock's handle is self, then
							//		set to next_handle (nullptr for last)
							//		exit.
							//else,
							//		execute the new handle.
							if (lock_v->next_handle_v.compare_exchange_strong(tmp, next_handle)) break;

							// tmp is next to execute.
							auto h = std::coroutine_handle<void>::from_address(tmp);
							h.resume();
						}
						self_handle = nullptr;
					}
					~await_resume_t() {
						unlock();
					}
				};
				return await_resume_t{lock_v, self_handle, next_handle};
			}
		};

		auto lock() {
			return co_await_t{this};
		}
		auto operator co_await() {
			return lock();
		}
	};
}

#endif // STAMP_TASK_CO_LOCK_H