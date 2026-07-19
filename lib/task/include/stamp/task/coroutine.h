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

namespace stamp::task {
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
	struct promise;
	template<typename T>
	struct coroutine;

	template<typename Return, typename Container = std::vector<std::coroutine_handle<void>>>
	class task_sequence {
	public:
		using container_type = Container;
		using return_type = Return;
	private:
		container_type container{};
		return_type ret; // might change to reference because it should just work (depending on stack layout)
		bool is_complete = false;
	public:
		task_sequence() {}
		task_sequence(const return_type& init_ret) : ret(init_ret) {}
		task_sequence(return_type&& init_ret) : ret(init_ret) {}

		bool await_ready() const noexcept {
			return !is_complete;
		}
		void await_suspend(const std::coroutine_handle<void>& handle) {
			container.emplace(container.end(), handle);
		}
		return_type await_resume() {
			return ret;
		}

		void yield() {
			for (const auto& c : container) {
				c.resume();
			}
		}

		void yield(return_type&& ret_v) requires (not std::same_as<return_type, void>) {
			ret = std::forward<return_type>(ret_v);
			yield();
		}

		void finish() {
			is_complete = true;
			yield();
			container.clear();
		}
		
		void finish(return_type&& ret_v) requires (not std::same_as<return_type, void>) {
			is_complete = true;
			yield(std::forward<return_type>(ret_v));
			container.clear();
		}
		
		bool done() const noexcept {
			return is_complete;
		}

		void error() {
			finish();
		}
	};

	// struct void_t {};

	class promise_interface {
		template<typename T>
		friend struct coroutine;
	public:
		std::atomic_bool request_kill_v{false};
		// std::atomic_bool is_killed_v{false};
		std::atomic_bool is_done_v{false};
		std::atomic_flag on_end_handle_flag{};
		std::atomic<void*> on_end_handle{nullptr};

		std::exception_ptr exception_buffer{nullptr};

		// should return a dedicated awaiter object. in order to prevent mangling coroutine_handle
		std::suspend_always initial_suspend() noexcept {
			return {};
		}
		auto final_suspend() noexcept {
			struct await_t {
				promise_interface* promise;

				bool await_ready() noexcept {
					return false;
				}
				void await_suspend(const std::coroutine_handle<void>&) noexcept {
					void* addr;
					{
						atomic_flag_lock_guard l{promise->on_end_handle_flag};
						addr = promise->on_end_handle.exchange(nullptr);
						promise->is_done_v.store(true);
						promise->is_done_v.notify_all();
					}
					if (addr != nullptr) {
						std::coroutine_handle<void>::from_address(addr).resume();
					}
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

		int done() const {
			return is_done_v.load();
		}

		void kill() {
			request_kill_v.store(true);
		}

		void set_is_killed() {
			// is_killed_v.store(true);
			exception_buffer = std::make_exception_ptr(std::runtime_error("awaited coroutine has been killed"));
			auto v = final_suspend();
			v.await_suspend(std::coroutine_handle<void>::from_address(this));
		}

		template<typename V>
		struct await_ready_t {
			V awaiter;
			promise_interface& promise;
			bool request_kill_v;
			await_ready_t(promise_interface& promise, V awaiter, bool request_kill_v) : promise(promise), awaiter(awaiter), request_kill_v(request_kill_v) {}

			bool await_ready() {
				if (request_kill_v) return false;
				return awaiter.await_ready();
			}
			bool await_suspend(auto handle) {
				if constexpr (std::same_as<decltype(awaiter.await_suspend(handle)), void>) {
					if (request_kill_v) {
						promise.set_is_killed();
						return true;
					}
					
					awaiter.await_suspend(handle);
					return true;
				}
				else if constexpr (std::same_as<decltype(awaiter.await_suspend(handle)), bool>) {
					if (request_kill_v) {
						promise.set_is_killed();
						return true;
					}
					
					return awaiter.await_suspend(handle);
				}
				else { // should be a coroutine_handle. could have problems here
					auto next_handle = awaiter.await_suspend(handle);
					next_handle.resume();

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
		template<typename V>
		auto await_transform(V&& awaiter) {
			if constexpr (requires { awaiter.operator co_await(); }) {
				return await_ready_t{*this, std::forward<V>(awaiter).operator co_await(), request_kill_v.load()};
			}
			else if constexpr (requires { operator co_await(static_cast<V&&>(awaiter)); }) {
				return await_ready_t{*this, operator co_await(static_cast<V&&>(std::forward<V>(awaiter))), request_kill_v.load()};
			}
			else {
				return await_ready_t{*this, std::forward<V>(awaiter), request_kill_v.load()};
			}
		}
	};

	template<typename T>
	class promise : public promise_interface {
	public:
		T ret_value{};

		// should return a dedicated awaiter object. in order to prevent mangling coroutine_handle
		coroutine<T> get_return_object();
		void return_value(T&& new_value) noexcept {
			ret_value = std::forward<T>(new_value);
		}

		auto yield_value(T& new_value) {
			struct await_t {
				promise<T>& promise_v;
				T& new_value;
				bool request_kill_v;
				await_t(promise<T>& promise_v, T& new_value, bool request_kill_v) : promise_v(promise_v), new_value(new_value), request_kill_v(request_kill_v) {}

				bool await_ready() {
					return false;
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					promise_v.ret_value = std::forward<T>(new_value);
					
					if (request_kill_v) {
						auto fs = promise_v.final_suspend();
						fs.await_suspend(handle);
						promise_v.set_is_killed();
					}
					else {
						void* addr;
						{
							atomic_flag_lock_guard l{promise_v.on_end_handle_flag};
							addr = promise_v.on_end_handle.exchange(nullptr);
						}
						if (addr != nullptr) {
							std::coroutine_handle<void>::from_address(addr).resume();
						}
					}
					return false;
				}
				void await_resume() {}
			};
			return await_t{*this, new_value, request_kill_v.load()};
		}
	};

	template<typename T>
	class coroutine {
		friend struct coroutine<void>;
		friend class promise<T>;
	public:
		using promise_type = promise<T>;
	private:
		std::coroutine_handle<promise<T>> handle_v{nullptr};

		coroutine(const std::coroutine_handle<promise<T>>& handle) : handle_v(handle) {}
	public:
		coroutine() {}

		coroutine(const coroutine&) = delete;
		coroutine(coroutine&& other) : 
			handle_v(other.handle_v) {
			other.handle_v = nullptr;
		}
		coroutine& operator = (const coroutine&) = delete;
		coroutine& operator = (coroutine&& other) {
			handle_v = other.handle_v;
			other.handle_v = nullptr;
			return *this;
		}

		~coroutine() {
			if (handle_v) {
				kill();
				handle_v.destroy();
				handle_v = nullptr;
			}
		}

		bool done() const {
			if (!handle_v) return true;
			return handle_v.promise().done();
		}
		explicit operator bool() const {
			return (bool)handle_v;
		}

		coroutine<T>&& start()&& {
			if (handle_v) handle_v.resume();
			return std::move(*this);
		}
		coroutine<T>& start()& {
			if (handle_v) handle_v.resume();
			return *this;
		}

		// threadsafe
		void kill() {
			if (handle_v) handle_v.promise().kill();
		}

		// threadsafe
		void wait() {
			auto& is_done_v = handle_v.promise().is_done_v;
			while (!is_done_v.load()) {
				is_done_v.wait(false);
			}
		}

		// threadsafe
		std::coroutine_handle<void> handle() const {
			return static_cast<std::coroutine_handle<void>>(handle_v);
		}

		auto operator co_await() const noexcept {
			struct await_t {
				promise<T>& my_promise;
				void* next_handle{nullptr};
				await_t(promise<T>& my_promise) : my_promise(my_promise) {}

				bool await_ready() const noexcept {
					return my_promise.done();
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					atomic_flag_lock_guard l{my_promise.on_end_handle_flag};
					if (!my_promise.done()) {
						next_handle = my_promise.on_end_handle.exchange(handle.address());
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

			return await_t{handle_v.promise()};
		}
	};


	struct void_t {};
	template<>
	class promise<void> : public promise_interface {
	public:

		coroutine<void> get_return_object();
		void return_void() const noexcept {}

		// void* operator new(std::size_t);
		// <awaiter> await_transform(<awaiter>);

		auto yield_value(void_t) {
			struct await_t {
				promise<void>& promise_v;
				bool request_kill_v;
				await_t(promise<void>& promise_v, bool request_kill_v) : promise_v(promise_v), request_kill_v(request_kill_v) {}

				bool await_ready() {
					return false;
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					if (request_kill_v) {
						auto fs = promise_v.final_suspend();
						fs.await_suspend(handle);
						promise_v.set_is_killed();
					}
					else {
						void* addr;
						{
							atomic_flag_lock_guard l{promise_v.on_end_handle_flag};
							addr = promise_v.on_end_handle.exchange(nullptr);
						}
						if (addr != nullptr) {
							std::coroutine_handle<void>::from_address(addr).resume();
						}
					}
					return false;
				}
				void await_resume() {}
			};
			return await_t{*this, request_kill_v.load()};
		}
	};

	template<>
	class coroutine<void> {
		friend class promise<void>;
	public:
		using promise_type = promise<void>;
	private:
		std::coroutine_handle<void> handle_v{nullptr};
		promise_interface* promise_v{nullptr};

		coroutine(const std::coroutine_handle<promise<void>>& handle) : handle_v(handle) {
			promise_v = &handle.promise();
		}
	public:
		coroutine() {}

		coroutine(const coroutine&) = delete;
		coroutine& operator = (const coroutine&) = delete;

		template<typename T>
		coroutine(coroutine<T>&& other) : handle_v(std::move(other.handle_v)) {
			promise_v = &other.handle_v.promise();
			other.handle_v = nullptr;
		}
		coroutine(coroutine<void>&& other) :
			handle_v(other.handle_v),
			promise_v(other.promise_v) {
			other.handle_v = nullptr;
			other.promise_v = nullptr;
		}
		template<typename T>
		coroutine& operator = (coroutine<T>&& other) {
			handle_v = other.handle_v;
			promise_v = &other.handle_v.promise();
			other.handle_v = nullptr;
			return *this;
		}
		coroutine& operator = (coroutine<void>&& other) {
			handle_v = other.handle_v;
			promise_v = other.promise_v;
			other.handle_v = nullptr;
			other.promise_v = nullptr;
			return *this;
		}


		~coroutine() {
			if (handle_v) {
				kill();
				handle_v.destroy();
				handle_v = nullptr;
			}
		}

		bool done() const {
			if (!handle_v) return true;
			return promise_v->done();
		}
		explicit operator bool() const {
			return (bool)handle_v;
		}

		coroutine<void>&& start()&& {
			if (handle_v) handle_v.resume();
			return std::move(*this);
		}
		coroutine<void>& start() & {
			if (handle_v) handle_v.resume();
			return *this;
		}

		// threadsafe
		void kill() {
			if (handle_v) promise_v->kill();
		}

		// threadsafe
		void wait() {
			auto& is_done_v = promise_v->is_done_v;
			while (!is_done_v.load()) {
				is_done_v.wait(false);
			}
		}

		// threadsafe

		std::coroutine_handle<void> handle() const {
			return static_cast<std::coroutine_handle<void>>(handle_v);
		}

		auto operator co_await() const noexcept {
			struct await_t {
				promise_interface& my_promise;
				void* next_handle{nullptr};
				await_t(promise_interface& my_promise) : my_promise(my_promise) {}

				bool await_ready() const noexcept {
					return my_promise.done();
				}
				bool await_suspend(std::coroutine_handle<void> handle) {
					atomic_flag_lock_guard l{my_promise.on_end_handle_flag};
					if (!my_promise.done()) {
						next_handle = my_promise.on_end_handle.exchange(handle.address());
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
	class coroutine_view {
	public:
	};

	// some object that converts coroutines into std::promise in order to work with non-coroutine code.


	template<typename T>
	class coroutine_promise {
		std::promise<T> promise;
		coroutine<void> handle;
	public:
		coroutine_promise(const coroutine<T>& target_handle) {
			handle = [&]() -> coroutine<void> {
				promise.set_value(co_await target_handle);
				co_return;
			}();
		}

		std::future<T> get_future() {
			return promise.get_future();
		}
	};

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
}

template<typename T>
stamp::task::coroutine<T> stamp::task::promise<T>::get_return_object() {
	return coroutine<T>(std::coroutine_handle<stamp::task::promise<T>>::from_promise(*this));
}
stamp::task::coroutine<void> stamp::task::promise<void>::get_return_object() {
	return coroutine<void>(std::coroutine_handle<stamp::task::promise<void>>::from_promise(*this));
}

#endif // STAMP_TASK_COROUTINE_H
