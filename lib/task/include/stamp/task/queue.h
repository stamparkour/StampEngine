// stamp/task/bique.h
#ifndef STAMP_TASK_QUEUE_H
#define STAMP_TASK_QUEUE_H

#include <stamp/core/assert.h>
#include <coroutine>
#include <atomic>
#include <stdexcept>
#include <exception>
#include <memory>
#include <stamp/task/atomic_lock_guard.h>

namespace stamp::task {
	// co_bique assumes multiple producers and multiple consumers 
	template<typename T>
	class co_bique;

	template<>
	class co_bique<void> {
	public:
		using return_type = void;
	private:
		struct node_t {
			node_t* prev = nullptr;
			node_t* next = nullptr;
			std::coroutine_handle<> handle = nullptr;
			std::exception_ptr except_ptr = nullptr;

			node_t() = default;
			node_t(const node_t&) = delete;
			node_t(node_t&& other) {
				operator = (std::move(other));
			}
			node_t& operator =(const node_t&) = delete;
			node_t& operator =(node_t&& other) {
				// remove self
				if (prev != nullptr) prev->next = next;
				if (next != nullptr) next->prev = prev;
				// set to other
				prev = other.prev;
				next = other.next;
				if (prev != nullptr) prev->next = this;
				if (next != nullptr) next->prev = this;
				other.prev = other.next = nullptr;
				handle = other.handle;
				other.handle = nullptr;
				except_ptr = other.except_ptr;
				return *this;
			}

			~node_t() {
			}

			void remove_node() {
				prev->next = next;
				next->prev = prev;
				prev = next = nullptr;
			}

			void insert_after(node_t* target) {
				stamp::core::s_assert(prev == nullptr);
				stamp::core::s_assert(next == nullptr);

				prev = target;
				next = target->next;
				prev->next = next->prev = this;
			}

			void resume() {
				auto h = handle;
				handle = nullptr;
				h.resume();
			}
		};

		std::atomic_size_t size_v = 0;
		std::atomic_bool lock_v = false;
		node_t root_node{};
	public:
		co_bique() {
			root_node.prev = root_node.next = &root_node;
		}
		~co_bique() {
			// stamp::core::s_assert(size_v.load() == 0);
			if (!empty()) {
				std::exception_ptr ptr = std::make_exception_ptr(std::runtime_error("queue must be emptied before deconstruction."));
				pop_front_all_except(ptr);
				std::rethrow_exception(ptr);
			}

			root_node.next = nullptr;
			root_node.prev = nullptr;
		}

		std::size_t size() const {
			return size_v.load();
		}
		bool empty() {
			return size() == 0;
		}
		std::atomic_bool& lock() {
			return lock_v;
		}

		auto push_back() {
			struct await_t {
				node_t node{};
				co_bique<void>* self;
				await_t(co_bique<void>* s) {
					self = s;
				}
				~await_t() {
					if (node.handle == nullptr) return;
					atomic_lock_guard l{self->lock_v};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&& other) {
					operator =(std::move(other));
				}
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&& other) {
					node = std::move(other.node);
					self = other.self;
					return *this;
				}

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock_v};
					self->size_v++;
					node.insert_after(self->root_node.prev);
				}
				void await_resume() {
					if (node.except_ptr) {
						std::rethrow_exception(node.except_ptr);
					}
				}
			};
			return await_t{this};
		}
		auto push_front() {
			struct await_t {
				node_t node{};
				co_bique<void>* self;
				await_t(co_bique<void>* s) {
					self = s;
				}
				~await_t() {
					if (node.handle == nullptr) return;
					atomic_lock_guard l{self->lock_v};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&& other) {
					operator =(std::move(other));
				}
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&& other) {
					node = std::move(other.node);
					self = other.self;
					other.self = nullptr;
					return *this;
				}

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock_v};
					self->size_v++;
					node.insert_after(&self->root_node);
				}
				void await_resume() {
					if (node.except_ptr) {
						std::rethrow_exception(node.except_ptr);
					}
				}
			};
			return await_t{this};
		}

		bool pop_front() {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->resume();
			return true;
		}
		bool pop_front_all() {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
		bool pop_back() {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->resume();
			return true;
		}
		bool pop_back_all() {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}

		bool pop_front_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
			return true;
		}
		bool pop_front_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->except_ptr = p;
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
		bool pop_back_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
			return true;
		}
		bool pop_back_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->except_ptr = p;
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
	};

	template<typename T>
	class co_bique {
	public:
		using return_type = T;
	private:
		struct node_t {
			node_t* prev = nullptr;
			node_t* next = nullptr;
			std::coroutine_handle<> handle = nullptr;
			std::exception_ptr except_ptr = nullptr;
			return_type* ret_v = nullptr;

			node_t() = default;
			node_t(const node_t&) = delete;
			node_t(node_t&& other) {
				operator = (std::move(other));
			}
			node_t& operator =(const node_t&) = delete;
			node_t& operator =(node_t&& other) {
				// remove self
				if (prev != nullptr) prev->next = next;
				if (next != nullptr) next->prev = prev;
				// set to other
				prev = other.prev;
				next = other.next;
				if (prev != nullptr) prev->next = this;
				if (next != nullptr) next->prev = this;
				other.prev = other.next = nullptr;
				handle = other.handle;
				other.handle = nullptr;
				except_ptr = other.except_ptr;
				ret_v = other.ret_v;
				return *this;
			}

			~node_t() {
			}

			void remove_node() {
				prev->next = next;
				next->prev = prev;
				prev = next = nullptr;
			}

			void insert_after(node_t* target) {
				stamp::core::s_assert(prev == nullptr);
				stamp::core::s_assert(next == nullptr);

				prev = target;
				next = target->next;
				prev->next = next->prev = this;
			}

			void resume() {
				auto h = handle;
				handle = nullptr;
				h.resume();
			}
		};

		std::atomic_size_t size_v = 0;
		std::atomic_bool lock_v = false;
		node_t root_node{};
	public:
		co_bique() {
			root_node.prev = root_node.next = &root_node;
		}
		~co_bique() {
			// stamp::core::s_assert(size_v.load() == 0);
			if (!empty()) {
				std::exception_ptr ptr = std::make_exception_ptr(std::runtime_error("queue must be emptied before deconstruction."));
				pop_front_all_except(ptr);
				std::rethrow_exception(ptr);
			}

			root_node.next = nullptr;
			root_node.prev = nullptr;
		}

		std::size_t size() const {
			return size_v.load();
		}
		bool empty() const {
			return size() == 0;
		}
		std::atomic_bool& lock() {
			return lock_v;
		}

		auto push_back() {
			struct await_t {
				node_t node{};
				co_bique<void>* self;
				await_t(co_bique<void>* s) {
					self = s;
				}
				~await_t() {
					if (node.handle == nullptr) return;
					atomic_lock_guard l{self->lock_v};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&& other) {
					operator =(std::move(other));
				}
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&& other) {
					node = std::move(other.node);
					self = other.self;
					other.self = nullptr;
					return *this;
				}

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock_v};
					self->size_v++;
					node.insert_after(self->root_node.prev);
				}
				return_type await_resume() {
					if (node.except_ptr) {
						std::rethrow_exception(node.except_ptr);
					}
					return *node.ret_v;
				}
			};
			return await_t{this};
		}
		auto push_front() {
			struct await_t {
				node_t node{};
				co_bique<void>* self;
				await_t(co_bique<void>* s) {
					self = s;
				}
				~await_t() {
					if (node.handle == nullptr) return;
					atomic_lock_guard l{self->lock_v};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&& other) {
					operator =(std::move(other));
				}
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&& other) {
					node = std::move(other.node);
					self = other.self;
					other.self = nullptr;
					return *this;
				}

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock_v};
					self->size_v++;
					node.insert_after(&self->root_node);
				}
				return_type await_resume() {
					if (node.except_ptr) {
						std::rethrow_exception(node.except_ptr);
					}
					return *node.ret_v;
				}
			};
			return await_t{this};
		}

		bool pop_front(return_type ret_value) {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->ret_v = &ret_value;
			t->resume();
			return true;
		}
		bool pop_front_all(return_type ret_value) {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->ret_v = &ret_value;
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
		bool pop_back(return_type ret_value) {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->ret_v = &ret_value;
			t->resume();
			return true;
		}
		bool pop_back_all(return_type ret_value) {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->ret_v = &ret_value;
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
		bool pop_front_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
			return true;
		}
		bool pop_front_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->except_ptr = p;
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
		bool pop_back_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
			return true;
		}
		bool pop_back_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock_v};
				if (size_v.load() == 0) return false;
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->except_ptr = p;
				auto* l = t;
				t = t->next;
				l->resume();
			}
			return true;
		}
	};


	template<typename T, typename Container = co_bique<T>>
	class co_queue;

	template<typename T, typename Container>
	class co_queue {
	public:
		using return_type = T;
		using container_type = Container;
	private:
		container_type queue_v{};
	public:
		co_queue() = default;
		~co_queue() = default;

		auto push() {
			return queue_v.push_back();
		}
		bool pop(return_type r) {
			queue_v.pop_front(r);
		}
		bool pop_all(return_type r) {
			queue_v.pop_front_all(r);
		}
		bool pop_except(const std::exception_ptr& p) {
			queue_v.pop_front_except(p);
		}
		bool pop_all_except(const std::exception_ptr& p) {
			queue_v.pop_front_all_except(p);
		}
	};
	template<typename Container>
	class co_queue<void, Container> {
	public:
		using return_type = void;
		using container_type = Container;
	private:
		container_type queue_v{};
	public:
		co_queue() = default;
		~co_queue() = default;

		std::size_t size() const {
			return queue_v.size();
		}
		bool empty() {
			return queue_v.empty();
		}
		std::atomic_bool& lock() {
			return queue_v.lock();
		}

		auto push() {
			return queue_v.push_back();
		}
		bool pop() {
			return queue_v.pop_front();
		}
		bool pop_all() {
			return queue_v.pop_front_all();
		}
		bool pop_except(const std::exception_ptr& p) {
			return queue_v.pop_front_except(p);
		}
		bool pop_all_except(const std::exception_ptr& p) {
			return queue_v.pop_front_all_except(p);
		}
	};
}


#endif // STAMP_TASK_QUEUE_H