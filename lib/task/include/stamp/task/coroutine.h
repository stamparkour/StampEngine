// stamp/task/coroutine.h

#ifndef STAMP_TASK_COROUTINE_H
#define STAMP_TASK_COROUTINE_H

#include <coroutine>
#include <atomic>

namespace stamp::task {
	class co_queue {
	public:
		struct node_t {
			std::atomic<std::coroutine_handle<>> prev;
			std::coroutine_handle<> self;
			std::atomic<std::coroutine_handle<>> next;
			
			node_t() = default;
			node_t(const node_t&) = delete;
			node_t(node_t&&) = delete;
			node_t& operator =(const node_t&) = delete;
			node_t& operator =(node_t&&) = delete;
		};
	private:
		std::atomic<node_t*> front{nullptr};
		std::atomic<node_t*> back{nullptr};
	public:
		auto push_back() {
			struct await_t {
				node_t node{};
				co_queue* self;

				await_t(co_queue* q) : self(q) {}

				bool await_ready() { 
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.self = h;
					self->back.exchange(&node);
				}
				void await_resume() {}
			};
			return await_t{this};
		}
		void pop_front_all();
		void pop_front();
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

