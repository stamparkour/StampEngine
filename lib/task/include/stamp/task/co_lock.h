#ifndef STAMP_TASK_CO_LOCK_H

#include <atomic>
#include <coroutine>
#include <stamp/task/coroutine.h>

// TODO: remake co_lock_shared

namespace stamp::task {
	// not movable, not copyable
	class co_lock {
		std::atomic<void*> next_handle_v{};
		void* tmp_handle_v{};
	public:
		co_lock() = default;
		co_lock(const co_lock&) = delete;

		struct co_await_t {
			co_lock* lock_v;
			void* self_handle = nullptr;
			void* next_handle = nullptr;

			co_await_t() = default;
			co_await_t(co_lock* lock_v, void* self_handle = nullptr, void* next_handle = nullptr) :
				lock_v(lock_v), self_handle(self_handle), next_handle(next_handle) {}

			bool await_ready() {
				return false;
			}
			bool await_suspend(std::coroutine_handle<void> handle) {
				self_handle = handle.address();
				// 2 atomic steps: set next_handle; then, swap lock handle to self handle.
				while (!lock_v->next_handle_v.compare_exchange_strong(next_handle, self_handle));
				return next_handle != nullptr; // if nullptr, continue coroutine; else, pause.
			}
			[[nodiscard]] auto await_resume() {
				struct await_resume_t {
					co_lock* lock_v;
					void* self_handle;
					void* next_handle;
					void unlock() {
						if (self_handle == nullptr) return;
						if (next_handle == nullptr) {
							while (true) {
								auto next = lock_v->next_handle_v.exchange(self_handle);
								if (next == self_handle) {
									// if next is self_handle, then try to end loop
									if (lock_v->next_handle_v.compare_exchange_strong(next, nullptr)) break;
									else continue;
								}
								auto h1 = std::coroutine_handle<void>::from_address(next);
								h1.resume();

								// tmp_handle_v can only be set after h.resume
								while(lock_v->tmp_handle_v != nullptr) {
									auto tmp = lock_v->tmp_handle_v;
									lock_v->tmp_handle_v = nullptr;
									// if end of chain
									if (tmp == self_handle) break;
									auto h2 = std::coroutine_handle<void>::from_address(tmp);
									h2.resume();
								}
							}
						}
						else {
							lock_v->tmp_handle_v = next_handle;
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

	class co_lock_shared {
		std::atomic<void*> next_handle_v{};
		void* tmp_handle_v{};
		std::atomic_int shared_count_v{};
		// std::atomic_int exec_count_v{};
		std::atomic_flag flag_v{};
	public:

		co_lock_shared() = default;
		co_lock_shared(const co_lock_shared&) = delete;

		struct co_await_t {
			co_lock_shared* lock_v;
			void* self_handle;
			void* next_handle;
			bool started_paused = false;
			
			co_await_t() = default;
			co_await_t(co_lock_shared* lock_v, void* self_handle = nullptr, void* next_handle = nullptr, bool started_paused = false) :
				lock_v(lock_v), self_handle(self_handle), next_handle(next_handle), started_paused(started_paused) {}


			bool await_ready() {
				return false;
			}
			bool await_suspend(std::coroutine_handle<void> handle) {
				self_handle = handle.address();
				atomic_flag_lock_guard l{lock_v->flag_v};
				// 2 atomic steps: set next_handle; then, swap lock handle to self handle.
				while (!lock_v->next_handle_v.compare_exchange_strong(next_handle, self_handle));
				started_paused = !(next_handle == nullptr && lock_v->shared_count_v.load() == 0);
				return started_paused; // if nullptr and not reading, continue coroutine; else, pause.
			}
			[[nodiscard]] auto await_resume() {
				struct await_resume_t {
					co_lock_shared* lock_v;
					void* self_handle;
					void* next_handle;
					bool started_paused;
					void unlock() {
						if (self_handle == nullptr) return;
						if (!started_paused) {
							while (true) {
								void* next;
								{
									atomic_flag_lock_guard l{lock_v->flag_v};
									next = lock_v->next_handle_v.exchange(self_handle);
									if (next == self_handle) {
										// if next is self_handle, then try to end loop
										if (lock_v->next_handle_v.compare_exchange_strong(next, nullptr)) break;
										else continue;
									}
								}
								auto h1 = std::coroutine_handle<void>::from_address(next);
								h1.resume();

								// tmp_handle_v can only be set after h.resume
								while (lock_v->tmp_handle_v != nullptr) {
									auto tmp = lock_v->tmp_handle_v;
									lock_v->tmp_handle_v = nullptr;
									// if end of chain
									if (tmp == self_handle) break;
									auto h2 = std::coroutine_handle<void>::from_address(tmp);
									h2.resume();
								}
							}
						}
						else {
							lock_v->tmp_handle_v = next_handle;
						}
						self_handle = nullptr;
					}
					~await_resume_t() {
						unlock();
					}
				};
				return await_resume_t{lock_v, self_handle, next_handle, started_paused};
			}
		};
		struct shared_co_await_t {
			co_lock_shared* lock_v;
			void* self_handle = nullptr;
			void* next_handle = nullptr; // if nullptr, then is reading
			bool started_paused = false;

			shared_co_await_t() = default;
			shared_co_await_t(co_lock_shared* lock_v, void* self_handle = nullptr, void* next_handle = nullptr, bool started_paused = false) :
				lock_v(lock_v), self_handle(self_handle), next_handle(next_handle), started_paused(started_paused) {
			}

			bool await_ready() {
				return false;
			}
			bool await_suspend(std::coroutine_handle<void> handle) {
				self_handle = handle.address();
				atomic_flag_lock_guard l{lock_v->flag_v};

				// init reading during other reading thread(that could be queue looping)
				//int sc = lock_v->shared_count_v.load();

				//if (sc > 0) {
				//	lock_v->shared_count_v.fetch_add(1);
				//	started_paused = false;
				//	return false;
				//}

				next_handle = lock_v->next_handle_v.load();

				if (next_handle == nullptr) {
					lock_v->shared_count_v.fetch_add(1);
					started_paused = false;
					return false;
				}

				// 2 atomic steps: set next_handle; then, swap lock handle to self handle.
				while (!lock_v->next_handle_v.compare_exchange_strong(next_handle, self_handle));
				started_paused = true;
				return true;
			}
			[[nodiscard]] auto await_resume() {
				struct await_shared_resume_t {
					co_lock_shared* lock_v;
					void* self_handle;
					void* next_handle;
					bool started_paused;
					void unlock() {
						if (self_handle == nullptr) return;

						int sc;
						void* tmp_handle;
						{
							atomic_flag_lock_guard l{lock_v->flag_v};
							sc = lock_v->shared_count_v.fetch_sub(1) - 1;
							tmp_handle = lock_v->next_handle_v.load();
						}

						if (sc == 0 && tmp_handle != nullptr || next_handle != nullptr) {
							if (!started_paused) {
								while (true) {
									void* next;
									{
										atomic_flag_lock_guard l{lock_v->flag_v};
										next = lock_v->next_handle_v.exchange(self_handle);
										if (next == self_handle) {
											// if next is self_handle, then try to end loop
											if (lock_v->next_handle_v.compare_exchange_strong(next, nullptr)) break;
											else continue;
										}
									}
									auto h1 = std::coroutine_handle<void>::from_address(next);
									h1.resume();
									

									// tmp_handle_v can only be set after h.resume
									while (lock_v->tmp_handle_v != nullptr) {
										auto tmp = lock_v->tmp_handle_v;
										lock_v->tmp_handle_v = nullptr;
										// if end of chain
										if (tmp == self_handle) break;
										auto h2 = std::coroutine_handle<void>::from_address(tmp);
										h2.resume();
									}
								}
							}
							else {
								lock_v->tmp_handle_v = next_handle;
							}
						}

						
						self_handle = nullptr;
					}
					~await_shared_resume_t() {
						unlock();
					}
				};
				if (next_handle != nullptr) {
					atomic_flag_lock_guard l{lock_v->flag_v};
					lock_v->shared_count_v.fetch_add(1);
				}
				return await_shared_resume_t{lock_v, self_handle, next_handle, started_paused};
			}
		};

		auto lock() {
			return co_await_t{this};
		}
		auto lock_shared() {
			return shared_co_await_t{this};
		}
		auto operator co_await() {
			return lock();
		}
	};
}

#endif // STAMP_TASK_CO_LOCK_H