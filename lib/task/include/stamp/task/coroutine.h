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

// TODO: have public function that returns the lock value from the co_bique

namespace stamp::task {
	struct atomic_lock_guard {
		std::atomic_bool* lock = nullptr;


		atomic_lock_guard() = default;
		atomic_lock_guard(std::atomic_bool& t) : lock(&t) {
			bool v = false;
			while (!lock->compare_exchange_weak(v, true)) {
				v = false;
				lock->wait(true);
			}
		}

		atomic_lock_guard(const atomic_lock_guard&) = delete;
		atomic_lock_guard(atomic_lock_guard&& other) {
			lock = other.lock;
			other.lock = nullptr;
		}
		atomic_lock_guard& operator =(const atomic_lock_guard&) = delete;
		atomic_lock_guard& operator =(atomic_lock_guard&& other) {
			if (lock != nullptr) {
				stamp::core::s_assert(lock->load() == true, "atomic must be true before reassignment");
				lock->store(false);
				lock->notify_one();
			}
			lock = other.lock;
			other.lock = nullptr;
			return *this;
		}

		~atomic_lock_guard() {
			if (lock != nullptr) {
				stamp::core::s_assert(lock->load() == true, "atomic must be true before deconstruction");
				lock->store(false);
				lock->notify_one();
				lock = nullptr;
			}
		}
	};

	class basic_co_bique;
	template<typename T>
	class co_bique;

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
				prev->next = this;
				next->prev = this;
				other.prev = other.next = nullptr;
				handle = other.handle;
				other.handle = nullptr;
				except_ptr = other.except_ptr;
				ret_v = other.ret_v;
				return *this;
			}

			~node_t() {
				stamp::core::s_assert(prev == nullptr);
				stamp::core::s_assert(next == nullptr);
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
		std::atomic_bool lock = false;
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

		auto push_back() {
			struct await_t {
				node_t node{};
				co_bique<void>* self;
				await_t(co_bique<void>* s) {
					self = s;
				}
				~await_t() {
					if (self == nullptr) return;
					atomic_lock_guard l{self->lock};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&&) = default;
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&&) = default;

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock};
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
					if (self == nullptr) return;
					atomic_lock_guard l{self->lock};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&&) = default;
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&&) = default;

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock};
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

		void pop_front(return_type ret_value) {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->ret_v = &ret_value;
			t->resume();
		}
		void pop_front_all(return_type ret_value) {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->ret_v = &ret_value;
				t->resume();
				t = t->next;
			}
		}
		void pop_back(return_type ret_value) {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->ret_v = &ret_value;
			t->resume();
		}
		void pop_back_all(return_type ret_value) {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->ret_v = &ret_value;
				t->resume();
				t = t->prev;
			}
		}
		void pop_front_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
		}
		void pop_front_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->except_ptr = p;
				t->resume();
				t = t->next;
			}
		}
		void pop_back_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
		}
		void pop_back_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->except_ptr = p;
				t->resume();
				t = t->prev;
			}
		}
	};

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
				if(prev != nullptr) prev->next = next;
				if (next != nullptr) next->prev = prev;
				// set to other
				prev = other.prev;
				next = other.next;
				prev->next = this;
				next->prev = this;
				other.prev = other.next = nullptr;
				handle = other.handle;
				other.handle = nullptr;
				except_ptr = other.except_ptr;
				return *this;
			}

			~node_t() {
				stamp::core::s_assert(prev == nullptr);
				stamp::core::s_assert(next == nullptr);
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
		std::atomic_bool lock = false;
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

		auto push_back() {
			struct await_t {
				node_t node{};
				co_bique<void>* self;
				await_t(co_bique<void>* s) {
					self = s;
				}
				~await_t() {
					if (self == nullptr) return;
					atomic_lock_guard l{self->lock};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&&) = default;
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&&) = default;

				bool await_ready() { 
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock};
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
					if (self == nullptr) return;
					atomic_lock_guard l{self->lock};
					self->size_v--;
					node.remove_node();
				}
				await_t(const await_t&) = delete;
				await_t(await_t&&) = default;
				await_t& operator =(const await_t&) = delete;
				await_t& operator =(await_t&&) = default;

				bool await_ready() {
					return false;
				}
				void await_suspend(std::coroutine_handle<> h) {
					node.handle = h;
					atomic_lock_guard l{self->lock};
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

		void pop_front() {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->resume();
		}
		void pop_front_all() {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->resume();
				t = t->next;
			}
		}
		void pop_back() {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->resume();
		}
		void pop_back_all() {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->resume();
				t = t->prev;
			}
		}

		void pop_front_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.next;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
		}
		void pop_front_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.next;
			while (t != &n) {
				t->except_ptr = p;
				t->resume();
				t = t->next;
			}
		}
		void pop_back_except(const std::exception_ptr& p) {
			node_t* t;
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				t = root_node.prev;
				t->remove_node();
				size_v--;
			}
			t->except_ptr = p;
			t->resume();
		}
		void pop_back_all_except(const std::exception_ptr& p) {
			node_t n{};
			{
				atomic_lock_guard l{lock};
				stamp::core::s_assert(size_v.load() != 0);
				n = std::move(root_node);
				root_node.prev = root_node.next = &root_node;
				size_v = 0;
			}
			node_t* t = n.prev;
			while (t != &n) {
				t->except_ptr = p;
				t->resume();
				t = t->prev;
			}
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
		void pop(return_type r) {
			queue_v.pop_front(r);
		}
		void pop_all(return_type r) {
			queue_v.pop_front_all(r);
		}
		void pop_except(const std::exception_ptr& p) {
			queue_v.pop_front_except(p);
		}
		void pop_all_except(const std::exception_ptr& p) {
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

		auto push() {
			return queue_v.push_back();
		}
		void pop() {
			queue_v.pop_front();
		}
		void pop_all() {
			queue_v.pop_front_all();
		}
		void pop_except(const std::exception_ptr& p) {
			queue_v.pop_front_except(p);
		}
		void pop_all_except(const std::exception_ptr& p) {
			queue_v.pop_front_all_except(p);
		}
	};

	class co_mutex {
		co_queue<void> queue_v;
		std::atomic_bool is_blocked = false;
	public:
		co_mutex() {}
		~co_mutex() {}

		auto lock() {
			// TODO: fill in
		}
		void unlock() {
			// TODO: fill in
		}
	};

	template<typename T>
	class coroutine;
	template<typename T>
	class coroutine_promise;

	template<>
	class coroutine<void> {
	public:
		using return_type = void;
		using self_type = class coroutine<typename return_type>;
		using promise_type = class coroutine_promise<typename return_type>;
		using handle_type = std::coroutine_handle<promise_type>;

		friend promise_type;
	private:
		handle_type handle_v = nullptr;

		coroutine(promise_type* promise) {
			handle_v = handle_type::from_promise(*promise);
			initialize();
		}

		void initialize() {
			if (handle_v) {
				auto& p = handle_v.promise();
				promise_type::bit_mask_t desired, expected = p.state.load();
				do {
					desired = expected;
					desired.shared_count_v++;
				} while (!p.state.compare_exchange_weak(expected, desired));
			}
		}
		void deinitialize() {
			if (handle_v) {
				auto& p = handle_v.promise();
				promise_type::bit_mask_t desired, expected = p.state.load();
				do {
					desired = expected;
					desired.shared_count_v--;
				} while (!p.state.compare_exchange_weak(expected, desired));

				if (desired.shared_count_v == 0) {
					if (desired.is_finalized_v) {
						handle_v.resume();
					}
					else if (!desired.is_started_v) {
						handle_v.destroy();
					}
				}
				handle_v = nullptr;
			}
		}
	public:
		coroutine() = default;
		coroutine(const coroutine& other) {
			operator =(other);
		}
		coroutine(coroutine&& other) {
			operator =(std::move(other));
		}
		coroutine& operator =(const coroutine& other) {
			deinitialize();
			handle_v = other.handle_v;
			initialize();
			return *this;
		}
		coroutine& operator =(coroutine&& other) {
			deinitialize();
			handle_v = other.handle_v;
			other.handle_v = nullptr;
			// same count afterwards
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
					promise_type::bit_mask_t value = p.state.load();
					if (value.is_returned_v) {
						return false;
					}
					use_queue_await = true;
					return queue_await_v.await_ready();
				}
				void await_suspend(std::coroutine_handle<> h) {
					if (!use_queue_await) return;
					queue_await_v.await_suspend(h);
				}
				return_type await_resume() {
					if (use_queue_await) {
						return queue_await_v.await_resume();
					}
					else {
						auto& p = self->handle_v.promise();
						if (p.exception_v) std::rethrow_exception(p.exception_v);
						return; // TODO: replace with return_type for non-void.
					}
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

		std::size_t use_count() const {
			auto& p = handle_v.promise();
			promise_type::bit_mask_t value = p.state.load();
			return (std::size_t)value.shared_count_v;
		}
		explicit operator bool() const {
			return (bool)handle_v;
		}
		handle_type get() const {
			return handle_v;
		}

	};
	template<>
	class coroutine_promise<void> {
	public:
		using return_type = void;
		using self_type = coroutine_promise<void>;

		// TODO: implement detection for 32 bit atomics
		struct bit_mask_t {
			std::uint32_t shared_count_v = 0;
			std::uint32_t is_started_v : 1 = 0; // when ended (returned or exception
			std::uint32_t is_ended_v : 1 = 0; // when ended (returned or exception
			std::uint32_t is_returned_v : 1 = 0; // when returned
			std::uint32_t is_finalized_v : 1 = 0; // when final suspended
		};
		static_assert(std::atomic<bit_mask_t>::is_always_lock_free, "coroutine_promise should be lock free");

		std::atomic<bit_mask_t> state{};
		std::exception_ptr exception_v{};
		co_queue<return_type> queue_v{};
		std::stop_source stop_v{};

		coroutine<void> get_return_object() { 
			return {this};
		}
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
				self_type* self;
				await_t(self_type* s) {
					self = s;
				}
				~await_t() {}
				bool await_ready() {
					return false;
				}
				bool await_suspend(std::coroutine_handle<> h) {
					bit_mask_t desired, expected = self->state.load();
					do {
						desired = expected;
						desired.is_finalized_v = true;
					} while (!self->state.compare_exchange_weak(expected, desired));
					return desired.shared_count_v != 0; // return false when no shared access, thus destroying coroutine.
				}
				void await_resume() {}
			};
			return await_t{this};
		}
		void return_void() {
			bit_mask_t desired, expected = state.load();
			do {
				desired = expected;
				desired.is_returned_v = true;
				desired.is_ended_v = true;
			} while (!state.compare_exchange_weak(expected, desired));
			queue_v.pop_all();
		}
		void unhandled_exception() {
			exception_v = std::current_exception();
			bit_mask_t desired, expected = state.load();
			do {
				desired = expected;
				desired.is_ended_v = true;
			} while (!state.compare_exchange_weak(expected, desired));
			queue_v.pop_all_except(exception_v);
		}
		//auto await_transform(auto v) {
		//	return v;
		//}
	};

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
}

#endif // STAMP_TASK_COROUTINE_H

