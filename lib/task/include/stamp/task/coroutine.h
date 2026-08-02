// stamp/task/coroutine.h
#ifndef STAMP_TASK_COROUTINE_H
#define STAMP_TASK_COROUTINE_H

#include <memory>
#include <vector>
#include <coroutine>
#include <future>
#include <mutex>
#include <concepts>
#include <exception>
#include <stdexcept>
#include <thread>

// TODO: add some way to query for exceptions from coroutine_view

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

	class atomic_flag_lock_guard {
		std::atomic_flag* flag;
	public:
		atomic_flag_lock_guard(std::atomic_flag& flag) : flag(&flag) {
			while (flag.test_and_set()) {
				flag.wait(true);
			}
		}

		~atomic_flag_lock_guard() {
			flag->clear();
			flag->notify_all();
		}
	};

	class atomic_bool_lock_guard {
		std::atomic_bool* flag;
	public:
		atomic_bool_lock_guard(std::atomic_bool& flag) : flag(&flag) {
			while (flag.exchange(true)) {
				flag.wait(true);
			}
		}

		~atomic_bool_lock_guard() {
			flag->store(false);
			flag->notify_all();
		}
	};


	template<typename T>
	struct basic_promise;
	template<typename T>
	struct coroutine;
	template<typename T>
	class coroutine_view;

	class generic_promise {
		template<typename T>
		friend struct coroutine_view;
	public:
		std::atomic_bool request_kill_v{false}; // needs to be threadsafe
		std::atomic_bool is_started_v{false}; // needs to be threadsafe
		std::atomic_bool is_done_v{false}; // needs to be threadsafe
		std::atomic_bool is_finished_v{false}; // needs to be threadsafe
		std::atomic_bool is_detached_v{false}; // needs to be threadsafe
		std::atomic_bool is_pausing_v{false}; // needs to be threadsafe
		std::atomic_bool is_yielded_v{false};
		std::atomic_flag is_detached_flag{}; // needs to be threadsafe
		std::atomic_flag on_end_handle_flag{}; // needs to be threadsafe
		std::atomic<void*> on_yield_handle{nullptr}; // needs to be threadsafe
		std::atomic<void*> on_interrupt_handle{nullptr}; // needs to be threadsafe
		std::coroutine_handle<void> handle_v;
		std::exception_ptr exception_buffer{nullptr};

		// should return a dedicated awaiter object. in order to prevent mangling coroutine_handle
		auto initial_suspend() noexcept {
			struct await_t {
				generic_promise* promise_v;
				bool await_ready() noexcept {
					return false;
				}
				bool await_suspend(const std::coroutine_handle<void>& handle) noexcept {
					promise_v->handle_v = handle;
					return true;
				}
				void await_resume() noexcept {
					promise_v->is_started_v.store(true);
					promise_v->is_started_v.notify_all();
				}
			};
			return await_t{this};
		}
		auto final_suspend() noexcept {
			struct await_t {
				generic_promise* promise;

				bool await_ready() noexcept {
					return false;
				}
				bool await_suspend(const std::coroutine_handle<void>&) noexcept {
					void* addr;
					void* addr_int;
					{
						atomic_flag_lock_guard l{promise->on_end_handle_flag};
						promise->is_done_v.store(true);
						addr = promise->on_yield_handle.exchange(nullptr);
						addr_int = promise->on_interrupt_handle.exchange(nullptr);
					}

					if (addr_int != nullptr) {
						std::coroutine_handle<void>::from_address(addr_int).resume();
					}
					if (addr != nullptr) {
						std::coroutine_handle<void>::from_address(addr).resume();
					}
					
					bool ret_val;
					{
						atomic_flag_lock_guard l{promise->is_detached_flag};
						ret_val = !promise->is_detached_v.load();
						promise->is_finished_v.store(true);
						promise->is_finished_v.notify_all();
					}
					return ret_val; // return false (resume coroutine) if kill on finish
				}
				void await_resume() noexcept {}
			};
			return await_t{this};
		}
		void unhandled_exception() noexcept {
			exception_buffer = std::current_exception();
		}

		void throw_if_exception() {
			if (exception_buffer) {
				std::rethrow_exception(exception_buffer);
			}
		}

		bool done() const {
			return is_done_v.load();
		}

		void kill() {
			request_kill_v.store(true);
		}
		void pause() {
			is_pausing_v.store(true);
		}

		void set_is_killed() {
			exception_buffer = std::make_exception_ptr(std::runtime_error("awaited coroutine has been killed"));
			auto v = final_suspend();
			v.await_suspend(handle_v);
		}

		template<typename V>
		struct await_transform_t {
			V awaiter;
			generic_promise& promise;
			bool request_kill_v;
			await_transform_t(generic_promise& promise, V awaiter, bool request_kill_v) : promise(promise), awaiter(awaiter), request_kill_v(request_kill_v) {}

			bool await_ready() {
				if (request_kill_v) return false;
				return awaiter.await_ready();
			}
			bool await_suspend(auto handle) {
				if constexpr (std::same_as<decltype(awaiter.await_suspend(handle)), void>) {
					void* addr_int = promise.on_interrupt_handle.exchange(nullptr, std::memory_order_relaxed);
					if (addr_int != nullptr) {
						std::coroutine_handle<void>::from_address(addr_int).resume();
					}

					if (request_kill_v) {
						promise.set_is_killed();
						return true;
					}
					
					awaiter.await_suspend(handle);
					return true;
				}
				else if constexpr (std::same_as<decltype(awaiter.await_suspend(handle)), bool>) {
					void* addr_int = promise.on_interrupt_handle.exchange(nullptr, std::memory_order_relaxed);
					if (addr_int != nullptr) {
						std::coroutine_handle<void>::from_address(addr_int).resume();
					}

					if (request_kill_v) {
						promise.set_is_killed();
						return true;
					}
					
					return awaiter.await_suspend(handle);
				}
				else { // should be a coroutine_handle. could have problems here
					auto next_handle = awaiter.await_suspend(handle);
					next_handle.resume();

					void* addr_int = promise.on_interrupt_handle.exchange(nullptr, std::memory_order_relaxed);
					if (addr_int != nullptr) {
						std::coroutine_handle<void>::from_address(addr_int).resume();
					}

					if (request_kill_v) {
						promise.set_is_killed();
					}
					return true;
				}
			}
			decltype(auto) await_resume() {
				return awaiter.await_resume();
			}
		};
		template<typename V> requires awaitable_c<V>
		auto await_transform(V&& awaiter) {
			if constexpr (requires { awaiter.operator co_await(); }) {
				return await_transform_t{*this, std::forward<V>(awaiter).operator co_await(), request_kill_v.load()};
			}
			else if constexpr (requires { operator co_await(static_cast<V&&>(awaiter)); }) {
				return await_transform_t{*this, operator co_await(static_cast<V&&>(std::forward<V>(awaiter))), request_kill_v.load()};
			}
			else {
				return await_transform_t{*this, std::forward<V>(awaiter), request_kill_v.load()};
			}
		}
	};

	template<typename T>
	class basic_promise : public generic_promise {
	public:
		T ret_value{};

		// should return a dedicated awaiter object. in order to prevent mangling coroutine_handle
		coroutine<T> get_return_object();
		void return_value(const T& new_value) noexcept {
			ret_value = new_value;
		}
		void return_value(T&& new_value) noexcept {
			ret_value = std::move(new_value);
		}

		// TODO: add lvalue and rvalue variants (for move and copy)
		auto yield_value(T new_value) {
			struct await_t {
				basic_promise<T>& promise_v;
				T& new_value;
				await_t(
					basic_promise<T>& promise_v, 
					T& new_value) :
					promise_v(promise_v), 
					new_value(new_value) {}

				bool await_ready() {
					return false;
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					promise_v.ret_value = std::forward<T>(new_value);
					promise_v.is_yielded_v.store(true);

					if (promise_v.request_kill_v.load()) {
						auto fs = promise_v.final_suspend();
						fs.await_suspend(handle);
						promise_v.set_is_killed();
						return true;
					}

					void* addr_int = promise_v.on_interrupt_handle.load();
					if (addr_int != nullptr) {
						addr_int = promise_v.on_interrupt_handle.exchange(nullptr);
						std::coroutine_handle<void>::from_address(addr_int).resume();
					}
					void* addr = promise_v.on_yield_handle.load();
					if (addr != nullptr) {
						addr = promise_v.on_yield_handle.exchange(nullptr);
						std::coroutine_handle<void>::from_address(addr).resume();
					}

					bool is_pausing_v = promise_v.is_pausing_v.load();
					if (is_pausing_v) {
						promise_v.is_pausing_v.store(false);
						return true;
					}

					return false;
				}
				void await_resume() {
					promise_v.is_yielded_v.store(false);
				}
			};

			return await_t{*this, new_value};
		}
	};

	template<typename T>
	class coroutine_view {
		friend struct coroutine_view<void>;
		friend class basic_promise<T>;
		template<typename T>
		friend class coroutine;
	public:
		using return_type = T;
	protected:
		basic_promise<T>* promise_v{nullptr};
	public:
		coroutine_view() {}
		coroutine_view(nullptr_t) {}
		coroutine_view& operator =(nullptr_t) noexcept {
			promise_v = nullptr;
			return *this;
		}

		coroutine_view(const std::coroutine_handle<basic_promise<T>>& h) {
			promise_v = &h.promise();
		}
		coroutine_view& operator =(const std::coroutine_handle<basic_promise<T>>& h) {
			promise_v = &h.promise();
			return *this;
		}
		coroutine_view(basic_promise<T>& p) {
			promise_v = &p;
		}
		coroutine_view& operator =(basic_promise<T>& p) {
			promise_v = &p;
			return *this;
		}

		template<typename V>
		auto operator <=>(const coroutine_view<V>& other) const {
			return reinterpret_cast<void*>(promise_v) <=> reinterpret_cast<void*>(other.promise_v);
		}
		template<typename V>
		bool operator ==(const coroutine_view<V>& other) const {
			return reinterpret_cast<void*>(promise_v) == reinterpret_cast<void*>(other.promise_v);
		}


		bool done() const {
			return promise_v->done();
		}
		bool is_started() const {
			return promise_v->is_started_v.load();
		}
		bool is_yielded() const {
			return promise_v->is_yielded_v.load();
		}
		explicit operator bool() const {
			return (bool)promise_v;
		}
		coroutine_view<T>& resume() {
			promise_v->handle_v.resume();
			return *this;
		}

		T& result() {
			return promise_v->ret_value;
		}
		const T& result() const {
			return promise_v->ret_value;
		}

		// threadsafe
		std::exception_ptr get_exception() const {
			if (promise_v) return promise_v->exception_buffer;
		}

		// threadsafe
		void kill() {
			if (promise_v) promise_v->kill();
		}
		// threadsafe
		void pause() {
			if (promise_v) promise_v->pause();
		}

		// threadsafe
		void wait() {
			while (!promise_v->is_finished_v.load()) {
				promise_v->is_finished_v.wait(false);
			}
		}

		// threadsafe
		std::coroutine_handle<void> handle() const {
			return promise_v->handle_v;
		}
		// threadsafe
		basic_promise<T>& promise() const {
			return *promise_v;
		}

		auto await_interupt() const noexcept {
			struct await_t {
				generic_promise& my_promise;
				void* next_handle{nullptr};
				await_t(generic_promise& my_promise) : my_promise(my_promise) {}

				bool await_ready() const noexcept {
					return my_promise.done();
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					atomic_flag_lock_guard l{my_promise.on_end_handle_flag};
					if (!my_promise.done()) {
						next_handle = my_promise.on_interrupt_handle.exchange(handle.address());
						// debating whether to auto resume if not started  
						if (!my_promise.is_started_v.load()) {
							my_promise.handle_v.resume();
						}
						return true;
					}
					else {
						return false;
					}
				}
				void await_resume() {
					if (next_handle) std::coroutine_handle<void>::from_address(next_handle).resume();
					my_promise.throw_if_exception();
				}
			};

			return await_t{*promise_v};
		}

		auto operator co_await() const noexcept {
			struct await_t {
				basic_promise<T>& my_promise;
				void* next_handle{nullptr};
				await_t(basic_promise<T>& my_promise) : my_promise(my_promise) {}

				bool await_ready() const noexcept {
					return my_promise.done();
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					atomic_flag_lock_guard l{my_promise.on_end_handle_flag};
					if (!my_promise.done()) {
						next_handle = my_promise.on_yield_handle.exchange(handle.address());
						// debating whether to auto resume if not started
						//if (!my_promise.is_started_v.load()) {
						//	my_promise.handle_v.resume();
						//}
						return true;
					}
					else {
						return false;
					}
				}
				T await_resume() {
					if (next_handle) std::coroutine_handle<void>::from_address(next_handle).resume();
					my_promise.throw_if_exception(); 
					return my_promise.ret_value;
				}
			};

			return await_t{*promise_v};
		}
	};


	struct void_t {};
	template<>
	class basic_promise<void> : public generic_promise {
	public:

		coroutine<void> get_return_object();
		void return_void() const noexcept {}

		// void* operator new(std::size_t);
		// <awaiter> await_transform(<awaiter>);

		auto yield_value(void_t) {
			struct await_t {
				basic_promise<void>& promise_v;
				await_t(basic_promise<void>& promise_v) :
					promise_v(promise_v) {}

				bool await_ready() {
					return false;
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					promise_v.is_yielded_v.store(true);

					if (promise_v.request_kill_v.load()) {
						auto fs = promise_v.final_suspend();
						fs.await_suspend(handle);
						promise_v.set_is_killed();
						return true;
					}

					void* addr_int = promise_v.on_interrupt_handle.load();
					if (addr_int != nullptr) {
						addr_int = promise_v.on_interrupt_handle.exchange(nullptr);
						std::coroutine_handle<void>::from_address(addr_int).resume();
					}
					void* addr = promise_v.on_yield_handle.load();
					if (addr != nullptr) {
						addr = promise_v.on_yield_handle.exchange(nullptr);
						std::coroutine_handle<void>::from_address(addr).resume();
					}

					bool is_pausing_v = promise_v.is_pausing_v.load();
					if (is_pausing_v) {
						promise_v.is_pausing_v.store(false);
						return true;
					}

					return false;
				}
				void await_resume() {
					promise_v.is_yielded_v.store(false);
				}
			};

			return await_t{*this};
		}
	};

	template<>
	class coroutine_view<void> {
		friend class basic_promise<void>;
		template<typename T>
		friend class coroutine;
	public:
		using return_type = void;
	protected:
		generic_promise* promise_v{nullptr};
	public:
		coroutine_view() {}
		coroutine_view(nullptr_t) {}
		coroutine_view& operator =(nullptr_t) noexcept {
			promise_v = nullptr;
			return *this;
		}

		template<typename T>
		coroutine_view(const std::coroutine_handle<basic_promise<T>>& h) {
			if (h) promise_v = &h.promise();
		}
		template<typename T>
		coroutine_view& operator = (const std::coroutine_handle<basic_promise<T>>& h) {
			if(h) promise_v = &h.promise();
			return *this;
		}
		template<typename T>
		coroutine_view(basic_promise<T>& p) {
			promise_v = &p;
		}
		template<typename T>
		coroutine_view& operator =(basic_promise<T>& p) {
			promise_v = &p;
			return *this;
		}
		coroutine_view(generic_promise& p) {
			promise_v = &p;
		}
		coroutine_view& operator =(generic_promise& p) {
			promise_v = &p;
			return *this;
		}

		template<typename T>
		coroutine_view(coroutine_view<T>&& other) {
			if (other.promise_v) promise_v = other.promise_v;
			other.promise_v = nullptr;
		}
		template<typename T>
		coroutine_view(const coroutine_view<T>& other) {
			promise_v = other.promise_v;
		}

		template<typename T>
		coroutine_view& operator =(coroutine_view<T>&& other) {
			promise_v = other.promise_v;
			other.promise_v = nullptr;
			return *this;
		}
		template<typename T>
		coroutine_view& operator =(const coroutine_view<T>& other) {
			promise_v = other.promise_v;
			return *this;
		}


		template<typename V>
		auto operator <=>(const coroutine_view<V>& other) const {
			return reinterpret_cast<void*>(promise_v) <=> reinterpret_cast<void*>(other.promise_v);
		}
		template<typename V>
		bool operator ==(const coroutine_view<V>& other) const {
			return reinterpret_cast<void*>(promise_v) == reinterpret_cast<void*>(other.promise_v);
		}

		bool done() const {
			return promise_v->done();
		}
		bool is_started() const {
			return promise_v->is_started_v.load();
		}
		bool is_yielded() const {
			return promise_v->is_yielded_v.load();
		}
		explicit operator bool() const {
			return (bool)promise_v;
		}
		coroutine_view<void>& resume() {
			promise_v->handle_v.resume();
			return *this;
		}

		// threadsafe
		std::exception_ptr get_exception() const {
			if (promise_v) return promise_v->exception_buffer;
		}

		// threadsafe
		void kill() {
			if (promise_v) promise_v->kill();
		}
		// threadsafe
		void pause() {
			if (promise_v) promise_v->pause();
		}

		// threadsafe
		void wait() {
			while (!promise_v->is_finished_v.load()) {
				promise_v->is_finished_v.wait(false);
			}
		}

		// threadsafe
		std::coroutine_handle<void> handle() const {
			return promise_v->handle_v;
		}
		// threadsafe
		generic_promise& promise() const {
			return *promise_v;
		}

		auto await_interupt() const noexcept {
			struct await_t {
				generic_promise& my_promise;
				void* next_handle{nullptr};
				await_t(generic_promise& my_promise) : my_promise(my_promise) {}

				bool await_ready() const noexcept {
					return my_promise.done();
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					atomic_flag_lock_guard l{my_promise.on_end_handle_flag};
					if (!my_promise.done()) {
						next_handle = my_promise.on_interrupt_handle.exchange(handle.address());
						// debating whether to auto resume if not started  
						if (!my_promise.is_started_v.load()) {
							my_promise.handle_v.resume();
						}
						return true;
					}
					else {
						return false;
					}
				}
				void await_resume() {
					if (next_handle) std::coroutine_handle<void>::from_address(next_handle).resume();
					my_promise.throw_if_exception();
				}
			};

			return await_t{*promise_v};
		}

		auto operator co_await() const noexcept {
			struct await_t {
				generic_promise& my_promise;
				void* next_handle{nullptr};
				await_t(generic_promise& my_promise) : my_promise(my_promise) {}

				bool await_ready() const noexcept {
					return my_promise.done();
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					atomic_flag_lock_guard l{my_promise.on_end_handle_flag};
					if (!my_promise.done()) {
						next_handle = my_promise.on_yield_handle.exchange(handle.address());
						// debating whether to auto resume if not started  
						//if (!my_promise.is_started_v.load()) {
						//	my_promise.handle_v.resume();
						//}
						return true;
					}
					else {
						return false;
					}
				}
				void await_resume() {
					if (next_handle) std::coroutine_handle<void>::from_address(next_handle).resume();
					my_promise.throw_if_exception();
				}
			};

			return await_t{*promise_v};
		}
	};

	template<typename T>
	class coroutine : public coroutine_view<T> {
		friend class basic_promise<T>;
	public:
		using promise_type = basic_promise<T>;
		using return_type = T;
	private:
		coroutine(const std::coroutine_handle<basic_promise<T>>& handle) {
			this->promise_v = &handle.promise();
		}

	public:
		coroutine() {}

		coroutine(const coroutine<T>&) = delete;
		coroutine(coroutine<T>&& other) noexcept {
			this->promise_v = other.promise_v;
			other.promise_v = nullptr;
		}
		coroutine<T>& operator = (const coroutine<T>&) = delete;
		coroutine<T>& operator = (coroutine<T>&& other) noexcept {
			this->promise_v = other.promise_v;
			other.promise_v = nullptr;
			return *this;
		}

		coroutine<T>& resume()& {
			coroutine_view<T>::resume();
			return *this;
		}
		coroutine<T>&& resume()&& {
			coroutine_view<T>::resume();
			return std::move(*this);
		}

		// threadsafe
		void detach() {
			auto& p = *this->promise_v;
			atomic_flag_lock_guard l{p.is_detached_flag};
			if (p.is_finished_v.load()) {
				this->promise_v->handle_v.destroy();
				this->promise_v = nullptr;
			}
			p.is_detached_v.store(true);
		}

		~coroutine() {
			if (this->promise_v && !(this->promise_v->is_detached_v.load())) {
				this->promise_v->handle_v.destroy();
				this->promise_v = nullptr;
			}
		}
	};

	template<>
	class coroutine<void> : public coroutine_view<void> {
		friend class basic_promise<void>;
	public:
		using promise_type = basic_promise<void>;
		using return_type = void;
	private:

		coroutine(const std::coroutine_handle<basic_promise<void>>& handle) {
			promise_v = &handle.promise();
		}

	public:
		coroutine() {}

		coroutine(const coroutine&) = delete;
		coroutine& operator = (const coroutine&) = delete;

		template<typename T>
		coroutine(coroutine<T>&& other) {
			promise_v = other.promise_v;
			other.promise_v = nullptr;
		}
		coroutine(coroutine<void>&& other) noexcept {
			this->promise_v = other.promise_v;
			other.promise_v = nullptr;
		}
		template<typename T>
		coroutine& operator = (coroutine<T>&& other) noexcept {
			this->promise_v = other.promise_v;
			other.promise_v = nullptr;
			return *this;
		}
		coroutine& operator = (coroutine<void>&& other) noexcept {
			this->promise_v = other.promise_v;
			other.promise_v = nullptr;
			return *this;
		}

		coroutine<void>& resume()& {
			coroutine_view<void>::resume();
			return *this;
		}
		coroutine<void>&& resume()&& {
			coroutine_view<void>::resume();
			return std::move(*this);
		}

		// threadsafe
		void detach() {
			auto& p = *this->promise_v;
			atomic_flag_lock_guard l{p.is_detached_flag};
			if (p.is_finished_v.load()) {
				this->promise_v->handle_v.destroy();
				this->promise_v = nullptr;
			}
			p.is_detached_v.store(true);
		}

		~coroutine() {
			if (!this->promise_v) return;
			if (promise_v->is_detached_v.load()) return;
			
			this->promise_v->handle_v.destroy();
			this->promise_v = nullptr;
		}
	};

	/*template<typename T>
	class coroutine_view {
		coroutine<T>* coroutine_v;
	public:
		coroutine_view(coroutine<T>& co) : coroutine_v(&co) {}
	};*/

	// some object that converts coroutines into std::promise in order to work with non-coroutine code.


	template<typename CoFunc, typename... Args>
	auto co_dispatch_thread(CoFunc&& co_func, Args&&... args) {
		using coroutine_type = decltype(std::forward<CoFunc>(co_func)(std::forward<Args>(args)...));
		coroutine_type coro{};
		std::atomic_bool is_init{false};
		std::atomic_bool* is_start_p{nullptr};
		std::thread([&]() {
			auto v = std::forward<CoFunc>(co_func)(std::forward<Args>(args)...);
			auto handle = v.handle();
			coro = std::move(v);
			is_init.store(true);
			is_init.notify_all();
			std::atomic_bool is_start{false};
			is_start_p = &is_start;
			while (!is_start.load()) 
				is_start.wait(false);
			handle.resume();			
		}).detach();

		while (!is_init.load()) is_init.wait(false);
		struct co_start_t {
			std::atomic_bool* is_start_p;
			void start() const {
				is_start_p->store(true);
				is_start_p->notify_all();
			}
			void operator() () const {
				start();
			}
		};
		return std::pair<coroutine_type, co_start_t>{std::move(coro), co_start_t{is_start_p}};
	}

	// bool BoolFunc(coroutine_view<T>)
	/*template<typename T, typename BoolFunc>
	coroutine<void> co_pause_function(coroutine_view<T> target, BoolFunc&& func) {
		while ((bool)std::forward<BoolFunc>(func)(target)) {
			co_await target;
			target.pause();
		}
		co_return;
	}*/

	template<typename RetType> 
	struct co_get_coroutine_await_t {
		basic_promise<RetType>* promise;
		bool await_ready() {
			return false;
		}
		bool await_suspend(std::coroutine_handle<basic_promise<RetType>>& handle) {
			promise = &handle.promise();
			return false; // resumes the current coroutine.
		}
		coroutine_view<RetType> await_resume() {
			return {*promise};
		}
	};
	template<>
	struct co_get_coroutine_await_t<void> {
		generic_promise* promise;
		bool await_ready() {
			return false;
		}
		template<typename T>
		bool await_suspend(std::coroutine_handle<basic_promise<T>>& handle) {
			promise = &handle.promise();
			return false; // resumes the current coroutine.
		}
		coroutine_view<void> await_resume() {
			return {*promise};
		}
	};
	template<typename RetType>
	auto co_get_coroutine() {
		return co_get_coroutine_await_t<RetType>{};
	}
}

template<typename T>
stamp::task::coroutine<T> stamp::task::basic_promise<T>::get_return_object() {
	return coroutine<T>(std::coroutine_handle<stamp::task::basic_promise<T>>::from_promise(*this));
}
stamp::task::coroutine<void> stamp::task::basic_promise<void>::get_return_object() {
	return coroutine<void>(std::coroutine_handle<stamp::task::basic_promise<void>>::from_promise(*this));
}

#endif // STAMP_TASK_COROUTINE_H
