// stamp/task/coroutine.h

#ifndef STAMP_TASK_COROUTINE_H
#define STAMP_TASK_COROUTINE_H

#include <stamp/core/assert.h>
#include <coroutine>
#include <atomic>

namespace stamp::task {
	struct atomic_lock_guard {
		std::atomic_bool* lock = nullptr;


		atomic_lock_guard() = default;
		atomic_lock_guard(std::atomic_bool& t) : lock(&t) {
			while (lock->compare_exchange_weak(false, true)) {
				lock->wait(true);
			}
		}

		atomic_lock_guard(const atomic_lock_guard&) = delete;
		atomic_lock_guard(atomic_lock_guard&& other) {
			atomic_lock_guard::operator =(other);
		}
		atomic_lock_guard& operator =(const atomic_lock_guard&) = delete;
		atomic_lock_guard& operator =(atomic_lock_guard&& other) {
			lock = other.lock;
			other.lock = nullptr;
			return *this;
		}

		~atomic_lock_guard() {
			if (lock != nullptr) {
				stamp::core::s_assert(lock->load() == true, "atomic must be true before deconstruction");
				lock->store(false);
				lock = nullptr;
			}
		}
	};

	class basic_co_bique;

	class co_semaphore {
		struct node_t {
			node_t* prev = nullptr;
			node_t* next = nullptr;
			std::coroutine_handle<> self = nullptr;
			co_semaphore* semaphore;

			node_t() = default;
			node_t(const node_t&) = delete;
			node_t(node_t&& other) {
			}
			node_t& operator =(const node_t&) = delete;
			node_t& operator =(node_t&& other) {
			}
			~node_t() {
			}

			void remove_node() {
			}

			void insert_after(node_t* target) {
			}
		};

		std::atomic_int count = 0;
		std::atomic_bool lock = false;
		node_t root_node{};
	public:
		co_semaphore(int c) : count(c) {
			root_node.prev = root_node.next = &root_node;
			root_node.semaphore = this;
		}

		auto wait() {
			struct await_t {
				node_t node{};
				await_t(co_semaphore* s) {
					node.semaphore = s;
				}
				bool await_ready() { 
					int c = self->count.fetch_sub(1) - 1;
					return c >= 0;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.self = h;
					atomic_lock_guard l{self->lock};
					self->root_node.insert_after(&node);
				}
				void await_resume() {}
			};
			return await_t{this};
		}

		void signal() {
			int c = count.fetch_add(1) + 1;
			if (c > 0) return;

			node_t n;
			{
				atomic_lock_guard l{self->lock};
				n = std::move(root_node);
			}


		}
	};

	class basic_coroutine_promise {
	public:
	};
	class basic_coroutine {
	public:
		using promise_type = basic_coroutine_promise;
	private:
	public:
	};
}

#endif // STAMP_TASK_COROUTINE_H

