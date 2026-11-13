#ifndef STAMP_TASK_LOCK_H
#define STAMP_TASK_LOCK_H

#include <stamp/core/assert.h>
#include <coroutine>
#include <atomic>
#include <stdexcept>
#include <exception>
#include <memory>
#include <future>
#include <stamp/task/atomic_lock_guard.h>

namespace stamp::task {
	/**
	* if awaited, then only one thread can access this lock
	* example:
	* co_lock my_lock{};
	* auto l = co_await my_lock.lock();
	* // my code here.
	* l.unlock(); // or use deconstructor
	* co_await; // something else
	*
	* you can co_await the lock multiple times, as long as the lock is released beforehand


	*/
	class co_lock {
		struct node_t {
			node_t* next = nullptr;
			node_t* prev = nullptr;
			std::coroutine_handle<> handle{};
		};
		struct unlock_t {
			co_lock* self = nullptr;
			node_t* front_old = nullptr;
			bool primary = false;
			bool is_locked = false;
			node_t node{};
			unlock_t(co_lock* self, node_t* node_old, bool primary) : primary(primary), self(self) {
				is_locked = true;
				if (!primary) return;
				node_t* back_old = self->back.exchange(&node, std::memory_order_acquire);
				front_old = reverse(back_old, node_old);
			}
			~unlock_t() {
				unlock();
			}

			unlock_t(const unlock_t&) = delete;
			unlock_t(unlock_t&&) = delete;
			unlock_t& operator =(const unlock_t&) = delete;
			unlock_t& operator =(unlock_t&&) = delete;

			node_t* reverse(node_t* target, node_t* end_node) {
				node_t* i = target;
				node_t* prev = nullptr;
				while (i != end_node) {
					stamp::core::s_assert(i != nullptr);
					i->prev = prev;
					prev = i;
					i = i->next;
				}
				return prev;
			}
			void run_chain(node_t* target) {
				node_t* i = target;
				while (i != nullptr) {
					node_t* next = i->prev;
					i->handle.resume();
					i = next;
				}
			}
			void unlock() {
				stamp::core::s_assert(is_locked);
				is_locked = false;
				if (!primary) return;
				primary = false;
				run_chain(front_old);

				node_t* back_old = nullptr;
				while (true) {
					if (back_old == &node) {
						if (self->back.compare_exchange_weak(back_old, nullptr, std::memory_order_acquire)) {
							break;
						}
					}
					else if (self->back.compare_exchange_weak(back_old, &node, std::memory_order_acquire)) {
						run_chain(reverse(back_old, &node));
					}
				}
			}

			bool await_ready() noexcept {
				stamp::core::s_assert(!is_locked);
				return false;
			}
			bool await_suspend(std::coroutine_handle<> h) noexcept {
				node.handle = h;
				node_t* back_old = nullptr;
				while (true) {
					node.next = back_old;
					primary = back_old == nullptr;
					if (self->back.compare_exchange_weak(back_old, &node, std::memory_order_release)) break;
				}
				return back_old != nullptr;
			}
			void await_resume() {
				stamp::core::s_assert(node.next != nullptr || primary);
				is_locked = true;
				if (!primary) return;
				node_t* back_old = self->back.exchange(&node, std::memory_order_acquire);
				front_old = reverse(back_old, &node);
			}
		};
		struct lock_t {
			co_lock* self = nullptr;
			node_t node{};
			bool primary = false;

			lock_t(co_lock* self) : self(self) {}
			lock_t(const lock_t&) = delete;
			lock_t(lock_t&&) = delete;
			lock_t& operator =(const lock_t&) = delete;
			lock_t& operator =(lock_t&&) = delete;

			bool await_ready() noexcept {
				return false;
			}
			bool await_suspend(std::coroutine_handle<> h) noexcept {
				node.handle = h;
				node_t* back_old = nullptr;
				while (true) {
					node.next = back_old;
					primary = back_old == nullptr;
					if (self->back.compare_exchange_weak(back_old, &node, std::memory_order_release)) break;
				}
				return back_old != nullptr;
			}
			auto await_resume() {
				stamp::core::s_assert(node.next != nullptr || primary);
				return unlock_t{self, &node, primary};
			}
		};


		std::atomic<node_t*> back;
		static_assert(std::atomic<node_t*>::is_always_lock_free, "node_t* should be lock free");
	public:
		auto lock() {
			return lock_t{this};
		}
		auto operator co_await() {
			return lock();
		}
	};

	class co_shared_lock {
	public:
	private:
	public:
		/*
		three states:
		- unlocked
		- locked
		- shared locked

		6 actions:
		- construct
		- deconstruct
		- add shared
		- remove shared
		- add locked
		- remove locked

		two flow charts:
		- data flow
		- execution flow
		*/
	};
}

#endif // STAMP_TASK_LOCK_H