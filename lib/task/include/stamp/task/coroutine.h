// stamp/task/coroutine.h
#ifndef STAMP_TASK_COROUTINE_H
#define STAMP_TASK_COROUTINE_H

#include <stamp/core/assert.h>
#include <coroutine>
#include <atomic>
#include <stdexcept>
#include <exception>
#include <memory>
#include <stop_token>
#include <future>

// TODO: add template overload for custom coroutine allocators
// TODO: add new co_queue that can have custom states to atomically switch between

namespace stamp::task {
	template<typename T>
	concept awaitor_c =
		requires (T a) {
			{ a.await_ready() } -> std::convertible_to<bool>;
			a.await_suspend;
			a.await_resume();
		};
	template<typename T>
	concept awaitable_c =
		awaitor_c<T> ||
		requires (T a) {
			{ a.operator co_await() } -> awaitor_c;
		} ||
		requires (T && a) {
			{ operator co_await(a) } -> awaitor_c;
		};

	template<typename F>
	constexpr auto awaitable_function_v = awaitable_c<std::invoke_result_t<F>>;

	template<typename Coroutine>
	concept is_coroutine_c = requires {
		typename Coroutine::promise_type;
	};

	template<typename CoFunc, typename... Args>
	concept coroutine_invocable_c =
		std::invocable<CoFunc, Args...> &&
		is_coroutine_c<std::invoke_result_t<CoFunc, Args...>>;

	struct atomic_lock_guard {
		std::atomic_bool* lock_v = nullptr;

		atomic_lock_guard() = default;
		atomic_lock_guard(std::atomic_bool& t) : lock_v(&t) {
			bool v = false;
			while (!lock_v->compare_exchange_weak(v, true)) {
				v = false;
				lock_v->wait(true);
			}
		}

		atomic_lock_guard(const atomic_lock_guard&) = delete;
		atomic_lock_guard(atomic_lock_guard&& other) {
			lock_v = other.lock_v;
			other.lock_v = nullptr;
		}
		atomic_lock_guard& operator =(const atomic_lock_guard&) = delete;
		atomic_lock_guard& operator =(atomic_lock_guard&& other) {
			if (lock_v != nullptr) {
				stamp::core::s_assert(lock_v->load() == true, "atomic must be true before reassignment");
				lock_v->store(false);
				lock_v->notify_one();
			}
			lock_v = other.lock_v;
			other.lock_v = nullptr;
			return *this;
		}

		~atomic_lock_guard() {
			if (lock_v != nullptr) {
				stamp::core::s_assert(lock_v->load() == true, "atomic must be true before deconstruction");
				lock_v->store(false);
				lock_v->notify_one();
				lock_v = nullptr;
			}
		}
	};

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

	// multiple producer, single consumer, pop all
	class co_simple_queue {
		struct node_t {
			node_t* next;
			std::coroutine_handle<> handle;
			std::exception_ptr exception;
		};

		std::atomic<node_t*> back{nullptr};
	public:
		co_simple_queue() = default;
		~co_simple_queue() {
			pop_all_except_unsafe(std::make_exception_ptr(std::runtime_error("cannot destroy queue that is not empty")));
		}

		auto push() {
			struct await_t {
				co_simple_queue* self;
				node_t node{};

				await_t() {}
				await_t(co_simple_queue* self) : self(self) {}

				bool await_ready() noexcept {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					node_t* n = self->back.load();
					do {
						node.next = n;
					} while (!self->back.compare_exchange_weak(n, &node));
				}
				void await_resume() noexcept {
					if (node.exception) std::rethrow_exception(node.exception);
				}
			};

			return await_t{this};
		}
		bool pop_all_unsafe() {
			node_t* n = back.exchange(nullptr);
			if (n == nullptr) return false;
			auto f = [this](auto&& self, node_t* ptr) -> void {
				if (ptr == nullptr) return;
				self(self, ptr->next);
				ptr->handle.resume();
			};

			f(f, n);
			return true;
		}
		bool pop_all_except_unsafe(const std::exception_ptr& p) {
			node_t* n = back.exchange(nullptr);
			if (n == nullptr) return false;

			auto f = [this](auto&& self, node_t* ptr) -> void {
				if (ptr == nullptr) return;
				self(self, ptr->next);
				ptr->handle.resume();
			};

			f(f, n);
			return true;
		}
	};

	// if awaited, then only one thread can access this lock
	// example:
	// co_lock my_lock{};
	// auto l = my_lock.instance();
	// co_await l.lock();
	// // my code here.
	// l.release(); // or use deconstructor
	// co_await /* something else */
	class co_lock {
		struct node_t {
			node_t* next = nullptr;
			node_t* prev = nullptr;
			std::coroutine_handle<> handle{};
		};
		std::atomic<node_t*> back;
	public:
		auto instance() {
			struct lock_guard_t {
				co_lock* self = nullptr;
				node_t node{};
				bool is_primary = false;
				bool is_released = false;
				bool is_locked = false;

				lock_guard_t(co_lock* self) : self(self) {}
				~lock_guard_t() {
					release();
				}

				auto lock() {
					struct await_t {
						lock_guard_t* self;
						bool await_ready() noexcept {
							return false;
						}
						bool await_suspend(std::coroutine_handle<> h) {
							self->is_locked = true;
							self->is_released = false;
							self->node.handle = h;
							node_t* old_back = self->self->back.load();
							while (true) {
								self->node.next = old_back;
								if (self->self->back.compare_exchange_weak(old_back, &self->node)) {
									break;
								}
							}
							if (old_back == nullptr) {
								self->is_primary = true;
								self->node.handle = nullptr;
								return false;
							}
							return true;
						}
						void await_resume() {
							if (self->is_primary) return;
							if (self->node.next != nullptr && self->node.next->handle) {
								self->node.next->handle.resume();
							}
						}
					};
					return await_t{this};
				}

				void release() {
					if (!is_locked) return;
					is_locked = false;
					if (is_released) return;
					is_released = true;
					if (!is_primary) return;

					node_t* n = self->back.load();
					while (true) {
						if (n == &node) {
							if (self->back.compare_exchange_weak(n, nullptr)) break;
						}
						else {
							if (!self->back.compare_exchange_weak(n, &node)) continue;


						}
					}
				}
			};
			return lock_guard_t{this};
		}

		auto operator co_await() {
			return lock_guard();
		}
	};

	template<typename T>
	class coroutine;
	class basic_coroutine_promise;
	template<typename T>
	class coroutine_promise;

	class basic_coroutine_promise {
	public:
		// TODO: implement detection for 32 bit atomics
		struct bit_mask_t {
			std::uint32_t shared_count_v = 0;
			std::uint16_t unused_0 = 0;
			std::uint16_t is_started_v : 1 = 0; // when first resume
			std::uint16_t is_ended_v : 1 = 0; // when ended (returned or exception)
			std::uint16_t is_returned_v : 1 = 0; // when returned (no exception) (can only be true if is_ended is true)
			std::uint16_t is_finalized_v : 1 = 0; // when final suspended
		};
		static_assert(std::atomic<bit_mask_t>::is_always_lock_free, "coroutine_promise should be lock free");

		std::atomic<bit_mask_t> state{};
		std::atomic_int queue_size_v{0};
		std::exception_ptr exception_v{};
		std::stop_source stop_v{};
		co_simple_queue queue_v{};

		std::suspend_always initial_suspend() {
			bit_mask_t desired, expected = state.load();
			do {
				desired = expected;
				desired.is_started_v = true;
			} while (!state.compare_exchange_weak(expected, desired));
			return {};
		}
		auto final_suspend() noexcept {
			struct await_t {
				basic_coroutine_promise* self;
				await_t(basic_coroutine_promise* s) {
					self = s;
				}
				~await_t() {}
				bool await_ready() noexcept {
					return false;
				}
				bool await_suspend(std::coroutine_handle<> h) noexcept {
					bit_mask_t desired, expected = self->state.load();
					do {
						desired = expected;
						desired.is_finalized_v = true;
					} while (!self->state.compare_exchange_weak(expected, desired));
					return desired.shared_count_v != 0; // return false when no shared access, thus destroying coroutine.
				}
				void await_resume() noexcept {
				}
			};
			return await_t{this};
		}
		void unhandled_exception() {
			exception_v = std::current_exception();
			bit_mask_t desired, expected = state.load();
			while(true) {
				desired = expected;
				desired.is_ended_v = true;
				if (state.compare_exchange_weak(expected, desired)) break;
			}
			while(!is_queue_empty()) queue_v.pop_all_except_unsafe(exception_v);
		}

		bool is_queue_empty() {
			return queue_size_v.load() == 0;
		}
	};

	template<>
	class coroutine_promise<void> : public basic_coroutine_promise {
	public:
		using return_type = void;
		using self_type = coroutine_promise<void>;
		// return_type return_v;

		coroutine<void> get_return_object();
		
		void return_void() {
			bit_mask_t desired, expected = state.load();
			while (true) {
				desired = expected;
				desired.is_ended_v = true;
				desired.is_returned_v = true;
				if (state.compare_exchange_weak(expected, desired)) break;
			}
			while (!is_queue_empty()) queue_v.pop_all_except_unsafe(exception_v);
		}
		std::suspend_never yield_value(nullptr_t) {
			queue_v.pop_all_unsafe();
			return {};
		}
		//auto await_transform(auto v) {
		//	return v;
		//}
	};
	template<>
	class coroutine<void> {
	public:
		using return_type = void;
		using self_type = coroutine<void>;
		using promise_type = coroutine_promise<void>;
		using basic_promise_type = basic_coroutine_promise;
		using handle_type = std::coroutine_handle<basic_promise_type>;

		friend promise_type;
	private:
		handle_type handle_v = nullptr;

		coroutine(basic_promise_type* promise) {
			handle_v = handle_type::from_promise(*promise);
			initialize();
		}

		void initialize() {
			if (handle_v) {
				auto& p = handle_v.promise();
				typename basic_promise_type::bit_mask_t desired, expected = p.state.load();
				do {
					desired = expected;
					desired.shared_count_v++;
				} while (!p.state.compare_exchange_weak(expected, desired));
			}
		}
		void deinitialize() {
			if (handle_v) {
				auto& p = handle_v.promise();
				typename basic_promise_type::bit_mask_t desired, expected = p.state.load();
				do {
					desired = expected;
					desired.shared_count_v--;
				} while (!p.state.compare_exchange_weak(expected, desired));

				if (desired.shared_count_v == 0) {
					if (desired.is_finalized_v || !desired.is_started_v) {
						handle_v.destroy();
					}
				}
				handle_v = nullptr;
			}
		}
	public:
		coroutine() = default;
		coroutine(handle_type h) {
			handle_v = h;
			initialize();
		}
		coroutine(nullptr_t) {
			handle_v = nullptr;
		}
		template<typename T>
		coroutine(std::coroutine_handle<coroutine_promise<T>> h) {
			auto& p = h.promise();
			basic_promise_type* my_promise = &p;
			handle_v = handle_type::from_promise(*my_promise); // works because first inheritance is same pointer as child class
			initialize();
		}
		template<typename T>
		coroutine(const coroutine<T>& other) {
			operator =(other);
		}
		template<typename T>
		coroutine(coroutine<T>&& other) {
			operator =(std::move(other));
		}
		coroutine(const coroutine<void>& other) {
			operator =(other);
		}
		coroutine(coroutine<void>&& other) {
			operator =(std::move(other));
		}
		template<typename T>
		coroutine<void>& operator =(const coroutine<T>& other) {
			deinitialize();
			auto& p = other.handle_v.promise();
			basic_promise_type* my_promise = &p;
			handle_v = handle_type::from_promise(my_promise);
			initialize();
			return *this;
		}
		template<typename T>
		coroutine<void>& operator =(coroutine<T>&& other) {
			deinitialize();
			auto& p = other.handle_v.promise();
			basic_promise_type* my_promise = &p;
			handle_v = handle_type::from_promise(*my_promise);
			other.handle_v = nullptr;
			// same count afterwards
			return *this;
		}
		coroutine<void>& operator =(const coroutine<void>& other) {
			deinitialize();
			handle_v = other.handle_v;
			initialize();
			return *this;
		}
		coroutine<void>& operator =(coroutine<void>&& other) {
			deinitialize();
			handle_v = other.handle_v;
			other.handle_v = nullptr;
			// same count afterwards
			return *this;
		}
		coroutine<void>& operator =(nullptr_t) {
			deinitialize();
			handle_v = nullptr;
			return *this;
		}
		~coroutine() {
			deinitialize();
		}

		auto await() const {
			auto a = handle_v.promise().queue_v.push();
			using queue_await_type = decltype(a);

			struct await_t {
				const self_type* self = nullptr;
				queue_await_type queue_await_v;
				bool use_queue_await = false;
				await_t(const self_type* self, queue_await_type&& queue_await_v) : self(self), queue_await_v(std::move(queue_await_v)) {}

				bool await_ready() {
					auto& p = self->handle_v.promise();
					p.queue_size_v.fetch_add(1);
					basic_promise_type::bit_mask_t value = p.state.load();
					if (value.is_returned_v) {
						return false;
					}
					use_queue_await = true;
					return queue_await_v.await_ready();
				}
				void await_suspend(std::coroutine_handle<> h) {
					auto& p = self->handle_v.promise();
					if (!use_queue_await) return;
					queue_await_v.await_suspend(h);
					basic_promise_type::bit_mask_t desired, expected = p.state.load();
				}
				return_type await_resume() {
					auto& p = self->handle_v.promise();
					p.queue_size_v.fetch_sub(1);
					if (use_queue_await) {
						queue_await_v.await_resume();
					}
					else {
						if (p.exception_v) std::rethrow_exception(p.exception_v);
					}
					return; 
				}
			};
			return await_t{this, std::move(a)};
		}
		auto operator co_await() const {
			return await();
		}

		// must be called at least once before deconstructor.
		coroutine& resume() & {
			handle_v.resume();
			return *this;
		}
		coroutine&& resume() && {
			handle_v.resume();
			return std::move(*this);
		}
		// call this to inform the compiler that the coroutine will not exist after this call to optimize out heap allocating coroutine.
		// calling destroy while other threads own the target coroutine or coroutine is running on another thread is undefined behavior.
		void destroy() {
			handle_v.destroy();
			handle_v = nullptr;
		}
		// sends request to stop token
		void stop() {
			auto& p = handle_v.promise();
			p.stop_v.request_stop();
		}

		std::exception_ptr exception() const {
			return handle_v.promise().exception_v;
		}
		bool done() const {
			auto& p = handle_v.promise();
			basic_promise_type::bit_mask_t value = p.state.load();
			return value.is_ended_v;
		}
		// true if coroutine is good (exists, no errors)
		bool good() {
			auto& p = handle_v.promise();
			typename promise_type::bit_mask_t value = p.state.load();
			return (bool)handle_v && (!value.is_ended_v || value.is_returned_v);
		}

		std::size_t use_count() const {
			auto& p = handle_v.promise();
			basic_promise_type::bit_mask_t value = p.state.load();
			return (std::size_t)value.shared_count_v;
		}
		explicit operator bool() const {
			return (bool)handle_v;
		}
		handle_type get() const {
			return handle_v;
		}
		template<typename V>
		bool operator ==(const coroutine<V>& other) const {
			return handle_v.address() == other.handle_v.address();
		}
		template<typename V>
		auto operator <=>(const coroutine<V>& other) const {
			return handle_v.address() <=> other.handle_v.address();
		}
	};
	inline coroutine<void> coroutine_promise<void>::get_return_object() {
		return {this};
	}

	template<typename T>
	class coroutine_promise : public basic_coroutine_promise {
	public:
		using return_type = T;
		using self_type = coroutine_promise<return_type>;
		return_type return_v;

		coroutine<return_type> get_return_object();

		void return_value(return_type ret_value) {
			return_v = ret_value;
			self_type::bit_mask_t desired, expected = state.load();
			while (true) {
				desired = expected;
				desired.is_ended_v = true;
				desired.is_returned_v = true;
				if (state.compare_exchange_weak(expected, desired)) break;
			}
			while(!is_queue_empty()) queue_v.pop_all_unsafe();
		}

		std::suspend_never yield_value(return_type ret_value) {
			return_v = ret_value;
			queue_v.pop_all_unsafe();
			return {};
		}
		//auto await_transform(auto v) {
		//	return v;
		//}
	};
	template<typename T>
	class coroutine {
	public:
		using return_type = T;
		using self_type = coroutine<typename return_type>;
		using promise_type = coroutine_promise<typename return_type>;
		using handle_type = std::coroutine_handle<promise_type>;

		friend promise_type;
		friend coroutine<void>;
	private:
		handle_type handle_v = nullptr;

		coroutine(promise_type* promise) {
			handle_v = handle_type::from_promise(*promise);
			initialize();
		}

		void initialize() {
			if (handle_v) {
				auto& p = handle_v.promise();
				typename promise_type::bit_mask_t desired, expected = p.state.load();
				do {
					desired = expected;
					desired.shared_count_v++;
				} while (!p.state.compare_exchange_weak(expected, desired));
			}
		}
		void deinitialize() {
			if (handle_v) {
				auto& p = handle_v.promise();
				typename promise_type::bit_mask_t desired, expected = p.state.load();
				do {
					desired = expected;
					desired.shared_count_v--;
				} while (!p.state.compare_exchange_weak(expected, desired));

				if (desired.shared_count_v == 0) {
					if (desired.is_finalized_v || !desired.is_started_v) {
						handle_v.destroy();
					}
				}
				handle_v = nullptr;
			}
		}
	public:
		coroutine() = default;
		coroutine(handle_type h) {
			handle_v = h;
			initialize();
		}
		coroutine(nullptr_t) {
			handle_v = nullptr;
		}
		coroutine(const coroutine<T>& other) {
			operator =(other);
		}
		coroutine(coroutine<T>&& other) {
			operator =(std::move(other));
		}
		coroutine<T>& operator =(const coroutine<T>& other) {
			deinitialize();
			handle_v = other.handle_v;
			initialize();
			return *this;
		}
		coroutine<T>& operator =(coroutine<T>&& other) {
			deinitialize();
			handle_v = other.handle_v;
			other.handle_v = nullptr;
			// same count afterwards
			return *this;
		}
		coroutine<T>& operator =(nullptr_t) {
			deinitialize();
			handle_v = nullptr;
			return *this;
		}
		~coroutine() {
			deinitialize();
		}

		auto await() const {
			auto a = handle_v.promise().queue_v.push();
			using queue_await_type = decltype(a);

			struct await_t {
				const self_type* self = nullptr;
				queue_await_type queue_await_v;
				bool use_queue_await = false;
				await_t(const self_type* self, queue_await_type&& queue_await_v) : self(self), queue_await_v(std::move(queue_await_v)) {}

				bool await_ready() {
					auto& p = self->handle_v.promise();
					p.queue_size_v.fetch_add(1);
					typename promise_type::bit_mask_t value = p.state.load();
					if (value.is_returned_v) {
						return false;
					}
					use_queue_await = true;
					return queue_await_v.await_ready();
				}
				void await_suspend(std::coroutine_handle<> h) {
					auto& p = self->handle_v.promise();
					if (!use_queue_await) return;
					queue_await_v.await_suspend(h);
					typename promise_type::bit_mask_t desired, expected = p.state.load();
				}
				return_type await_resume() {
					auto& p = self->handle_v.promise();
					p.queue_size_v.fetch_sub(1);
					if (use_queue_await) {
						queue_await_v.await_resume();
					}
					else {
						if (p.exception_v) std::rethrow_exception(p.exception_v);
					}
					return p.return_v;
				}
			};
			return await_t{this, std::move(a)};
		}
		auto operator co_await() const {
			return await();
		}

		// must be called at least once before deconstructor.
		coroutine& resume()& {
			handle_v.resume();
			return *this;
		}
		coroutine&& resume()&& {
			handle_v.resume();
			return std::move(*this);
		}
		// call this to inform the compiler that the coroutine will not exist after this call to optimize out heap allocating coroutine.
		// calling destroy while other threads own the target coroutine or coroutine is running on another thread is undefined behavior.
		void destroy() {
			handle_v.destroy();
			handle_v = nullptr;
		}
		// sends request to stop token
		void stop() {
			auto& p = handle_v.promise();
			p.stop_v.request_stop();
		}

		bool done() const {
			auto& p = handle_v.promise();
			typename promise_type::bit_mask_t value = p.state.load();
			return value.is_ended_v;
		}
		// true if coroutine is good (exists, no errors)
		bool good() {
			auto& p = handle_v.promise();
			typename promise_type::bit_mask_t value = p.state.load();
			return (bool)handle_v && (!value.is_ended_v || value.is_returned_v);
		}
		const return_type& result() const {
			if (exception()) std::rethrow_exception(exception());
			return handle_v.promise().return_v;
		}
		std::exception_ptr exception() const {
			return handle_v.promise().exception_v;
		}
		std::size_t use_count() const {
			auto& p = handle_v.promise();
			typename promise_type::bit_mask_t value = p.state.load();
			return (std::size_t)value.shared_count_v;
		}
		explicit operator bool() const {
			return (bool)handle_v;
		}
		handle_type get() const {
			return handle_v;
		}
		template<typename V>
		bool operator ==(const coroutine<V>& other) const {
			return handle_v.address() == other.handle_v.address();
		}
		template<typename V>
		auto operator <=>(const coroutine<V>& other) const {
			return handle_v.address() <=> other.handle_v.address();
		}
	};
	template<typename T>
	inline coroutine<T> coroutine_promise<T>::get_return_object() {
		return {this};
	}

	// TODO: add non-void variant

	template<typename T>
	inline auto co_get_stop_token() {
		struct await_t {
			coroutine_promise<T>* promise_v = nullptr;

			bool await_ready() {
				return false;
			}
			
			bool await_suspend(std::coroutine_handle<coroutine_promise<T>> h) {
				promise_v = &h.promise();
				return false;
			}
			std::stop_token await_resume() {
				return promise_v.stop_v.get_token();
			}
		};
		return await_t{};
	}

	template<typename T>
	inline auto co_get_coroutine() {
		struct await_t {
			coroutine_promise<T>* promise_v = nullptr;

			bool await_ready() {
				return false;
			}

			bool await_suspend(std::coroutine_handle<coroutine_promise<T>> h) {
				promise_v = &h.promise();
				return false;
			}
			coroutine<T> await_resume() {
				return coroutine<T>{promise_v};
			}
		};
		return await_t{};
	}

	inline void wait_for_coroutine(const coroutine<void>& target) {
		if (target.done()) return;
		std::promise<void> promise{};
		std::future future = promise.get_future();
		auto co = [&target, &promise]() -> coroutine<void> {
			auto t = target;
			auto p = std::move(promise);
			co_await t;
			p.set_value();
		}();
		future.wait();
	}
}

#endif // STAMP_TASK_COROUTINE_H

