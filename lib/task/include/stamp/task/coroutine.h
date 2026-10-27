// stamp/task/coroutine.h
#ifndef STAMP_TASK_COROUTINE_H
#define STAMP_TASK_COROUTINE_H

#include <stamp/core/assert.h>
#include <coroutine>
#include <atomic>
#include <stdexcept>
#include <exception>
#include <memory>
#include <future>
#include <stamp/task/atomic_lock_guard.h>

// TODO: add template overload for custom coroutine allocators
// TODO: make co_await coroutine<T> more performant by removing 'count' atomic and use node states.

namespace stamp::task {
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
	// l.unlock(); // or use deconstructor
	// co_await /* something else */
	class co_lock {
		struct node_t {
			node_t* next = nullptr;
			node_t* prev = nullptr;
			std::coroutine_handle<> handle{};
			std::coroutine_handle<> tmp_handle{};
		};
		std::atomic<node_t*> back;
		static_assert(std::atomic<node_t*>::is_always_lock_free, "node_t* should be lock free");
	public:
		auto lock_guard() {
			struct lock_guard_t {
				co_lock* self = nullptr;
				node_t node{};
				bool is_primary = false;
				bool is_released = false;
				bool is_locked = false;

				lock_guard_t(co_lock* self) : self(self) {}
				~lock_guard_t() {
					unlock();
				}
				lock_guard_t(const lock_guard_t&) = delete;
				lock_guard_t(lock_guard_t&&) = delete;
				lock_guard_t& operator =(const lock_guard_t&) = delete;
				lock_guard_t& operator =(lock_guard_t&&) = delete;

				auto lock() {
					struct await_t {
						lock_guard_t* self;
						bool await_ready() noexcept {
							return false;
						}
						bool await_suspend(std::coroutine_handle<> h) {
							// TODO: add code to prevent double locking/ unlocking
							self->is_locked = true;
							self->is_released = false;
							self->node.handle = self->node.tmp_handle = h;
							self->is_primary = false;
							node_t* old_back = self->self->back.load();
							while (true) {
								self->node.next = old_back; // line requires memory_order_release
								if (self->self->back.compare_exchange_weak(old_back, &self->node, std::memory_order_release)) {
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
							stamp::core::s_assert(!self->is_released);
							stamp::core::s_assert(self->is_locked);
							stamp::core::s_assert(!self->is_primary || self->node.next == nullptr);
							stamp::core::s_assert(self->is_primary || self->node.next != nullptr);
							stamp::core::s_assert(self->node.prev == nullptr || self->node.prev->next == &self->node);
						}
					};
					return await_t{this};
				}
				auto operator co_await() {
					return lock();
				}

				void unlock() {
					if (!is_locked) return;
					is_locked = false;
					if (is_released) return;
					is_released = true;
					if (!is_primary) return;

					node_t* n = self->back.load();
					while (true) {
						// exit lock
						if (n == &node) {
							// must be release to allow all mutex changes to be released for the next co_lock locking
							if (self->back.compare_exchange_weak(n, nullptr, std::memory_order_release))
								break;
						}
						// swap out queue
						else {
							if (!self->back.compare_exchange_weak(n, &node, std::memory_order_acquire))
								continue;
							stamp::core::s_assert((bool)n->handle);
							
							// reverse order
							node_t* t = n;
							node_t* t_prev = nullptr;
							while (t != nullptr) {
								t->prev = t_prev;
								t_prev = t;
								t = t->next;
							}
							// t_prev should be &node
							stamp::core::s_assert(t_prev == &node);
							t = t_prev->prev;
							while (t != nullptr) {
								stamp::core::s_assert((bool)t->handle);
								node_t* tmp = t->prev;
								std::coroutine_handle<> h = t->handle;
								t->handle = nullptr;
								h.resume(); // *t can be destroyed after this point
								t = tmp;
							}
						}
					}
				}
			};
			return lock_guard_t{this};
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
		std::atomic_bool request_stop_v = false;
		std::atomic_int queue_size_v{0};
		std::exception_ptr exception_v{};
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
			STAMP_BREAKPOINT();
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
			while (!is_queue_empty()) queue_v.pop_all_unsafe();
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
		void stop() {
			stamp::core::s_assert((bool)handle_v);
			handle_v.promise().request_stop_v.store(true, std::memory_order_relaxed);
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
		void stop() {
			stamp::core::s_assert((bool)handle_v);
			handle_v.promise().request_stop_v.store(true, std::memory_order_relaxed);
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

	struct await_co_get_request_stop_t {
		basic_coroutine_promise* promise_v = nullptr;

		bool await_ready() {
			return false;
		}

		template<typename T>
		bool await_suspend(std::coroutine_handle<coroutine_promise<T>> h) {
			promise_v = &h.promise();
			return false;
		}
		bool await_resume() {
			return promise_v->request_stop_v.load(std::memory_order_relaxed);
		}
	};
	inline auto co_get_request_stop() {
		return await_co_get_request_stop_t{};
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

