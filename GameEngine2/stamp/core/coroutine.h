//stamp/core/coroutine.h

#pragma once
#ifndef STAMP_CORE_COROUTINE_H
#define STAMP_CORE_COROUTINE_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <coroutine>
#include <queue>
#include <future>

#include <stamp/core/define.h>
#include <stamp/core/memory.h>
#include <stamp/core/taskqueue.h>

STAMP_CORE_NAMESPACE_BEGIN

template<typename T>
class coroutine;

using co_conditional_enum_t = int;
namespace co_conditional_enum{
	enum : co_conditional_enum_t {
		None,
		Finished,
		Cancelled,
	};
}

template<typename T>
class co_conditional {
public:
	constexpr static auto has_return_value = true;
	using return_type = T;

	co_conditional_enum_t state = co_conditional_enum::None;
	T return_value;
};

template<>
class co_conditional<void> {
public:
	constexpr static auto has_return_value = false;
	using return_type = void;

	co_conditional_enum_t state = co_conditional_enum::None;
};

class coroutine_handle_conditional {
public:
	std::coroutine_handle<> handle;
	co_conditional_enum_t* state_ptr;

	coroutine_handle_conditional(const std::coroutine_handle<>& h, co_conditional_enum_t* state_ptr = nullptr) : handle(h), state_ptr(state_ptr) {}
	coroutine_handle_conditional(const std::coroutine_handle<>& h) : handle(h), state_ptr(nullptr) {}

	void operator()() {
		if (state_ptr != nullptr) {
			*state_ptr = co_conditional_enum::Finished;
		}
		handle();
	}
	void task_queue_failed() {
		if (state_ptr != nullptr) {
			*state_ptr = co_conditional_enum::Cancelled;
			handle();
		}
	}
};

template<typename R = void, typename Q = coroutine_queue>
class awaitable {
public:
	using function_type = R;
	using return_type = decltype(std::declval<R>().get_co_return());
	using queue_type = Q;
private:
	queue_type* queue;
	bool run_next;
	function_type func;
public:
	awaitable(const queue_type* queue, bool run_next = false, const function_type& func) : queue(queue), run_next(run_next), func(func) {}

	bool await_ready() { 
		return !run_next && queue->is_running_on_current_thread();
	}
	void await_suspend(const std::coroutine_handle<>& h) {
		if (run_next) queue->push_next(h);
		else queue->push(h);
	}
	return_type await_resume() {
		return func();
	}
};

template<typename Q>
class awaitable<void, Q> {
public:
	using return_type = void;
	using queue_type = Q;
private:
	queue_type* queue;
	bool run_next;
public:
	awaitable(const queue_type* queue, bool run_next = false) : queue(queue), run_next(run_next) {}

	bool await_ready() {
		return !run_next && queue->is_running_on_current_thread();
	}
	void await_suspend(const std::coroutine_handle<>& h) {
		if (run_next) queue->push_next(h);
		else queue->push(h);
	}
	void await_resume() {
		return;
	}
};

template<typename R = void, typename Q = coroutine_queue>
class awaitable_conditional {
public:
	using function_type = R;
	using return_type = co_conditional<decltype(std::declval<R>().get_co_return())>;
	using queue_type = Q;
private:
	queue_type* queue;
	bool run_next;
	function_type func;
	co_conditional_enum_t state = co_conditional_enum::None;
public:
	awaitable_conditional(const queue_type* queue, bool run_next = false, const function_type& func) : queue(queue), run_next(run_next), func(func) {}

	bool await_ready() { 
		return !run_next && queue->is_running_on_current_thread();
	}
	void await_suspend(const std::coroutine_handle<>& h) {
		if (run_next) queue->push_next(coroutine_handle_conditional{h, &state });
		else queue->push(coroutine_handle_conditional{ h, &state });
	}
	return_type await_resume() {
		return func();
	}
};

using coroutine_queue = basic_task_queue<std::coroutine_handle<>>;
using co_thread_pool = basic_timed_thread_pool<std::coroutine_handle<>>;
using coroutine_queue_conditional = basic_task_queue<coroutine_handle_conditional>;
using co_thread_pool_conditional = basic_timed_thread_pool<coroutine_handle_conditional>;

template<typename R = void, typename Q = coroutine_queue>
class timed_awaitable {
public:
	using return_type = R;
	using queue_type = Q;
private:
	queue_type* queue;
	const return_type& val;
	bool run_next;
	queue_type::time_point time;
public:
	awaitable(const queue_type* queue, const queue_type::time_point& t, bool run_next = false, const T& val = {}) : queue(queue), time(t), val(val), run_next(run_next) {}

	bool await_ready() {
		return !run_next && queue->is_running_on_current_thread() && std::chrono::steady_clock::now() >= time;
	}
	void await_suspend(const std::coroutine_handle<>& h) {
		if (run_next) queue->push_next(h, time);
		else queue->push(h, time);
	}
	const T& await_resume() {
		return val;
	}
};

struct suspend_conditional {
	bool shouldSuspend = false;
	suspend_conditional(bool shouldSuspend) noexcept : shouldSuspend(shouldSuspend) {}
	bool await_ready() noexcept {
		return !shouldSuspend;
	}
	void await_suspend(const std::coroutine_handle<>& h) noexcept {}
	void await_resume() noexcept {}
};

template<typename T>
class promise {
public:
	using return_type = T;
	using coroutine_type = coroutine<return_type>;
	using handle_type = std::coroutine_handle<promise<return_type>>;
private:
	T value{};
public:
	std::atomic_int referenceCount = 0;
	STAMP_CORE_NAMESPACE::atomic_threadsafe_ptr<coroutine_queue> queue{};

	void push(const std::coroutine_handle<>& h) {
		STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue> n = nullptr;
		auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();
		if (!queue.compare_exchange_strong(n, q)) {
			q = n;
		}
		q.get()->push(h);
	}
	template<typename U>
	void push(const coroutine<U>& c) {
		push(c.get_handle());
	}

	const T& get_return_value() {
		return value;
	}

	coroutine_type get_return_object();
	std::suspend_never initial_suspend() noexcept { 
		return {};
	}
	suspend_conditional final_suspend() noexcept { 
		return { referenceCount.load() != 0};
	}
	void return_value(const T& v) {
		value = v;

		STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue> q = nullptr;
		queue.exchange(q);
		if (q == nullptr) return;

		auto k = q.get();
		k->run_all();
	}
	void unhandled_exception() {}
};

template<>
class promise<void> {
public:
	using return_type = void;
	using coroutine_type = coroutine<return_type>;
	using handle_type = std::coroutine_handle<promise<return_type>>;
public:
	std::atomic_int referenceCount = 0;
	STAMP_CORE_NAMESPACE::atomic_threadsafe_ptr<coroutine_queue> queue{};

	void push(const std::coroutine_handle<>& h) {
		STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue> n = nullptr;
		auto q = STAMP_CORE_NAMESPACE::make_threadsafe<coroutine_queue>();
		if (!queue.compare_exchange_strong(n, q)) {
			q = n;
		}
		q.get()->push(h);
	}
	template<typename U>
	void push(const coroutine<U>& c) {
		push(c.get_handle());
	}

	coroutine_type get_return_object();
	std::suspend_never initial_suspend() noexcept { 
		return {};
	}
	suspend_conditional final_suspend() noexcept { 
		return { referenceCount.load() != 0};
	}
	void return_void() {
		STAMP_CORE_NAMESPACE::threadsafe_ptr<coroutine_queue> q = nullptr;
		queue.exchange(q);
		if (q == nullptr) return;

		auto k = q.get();
		k->run_all();
	}
	void unhandled_exception() {}
};

template <typename T>
class coroutine {
	friend class promise<T>;
public:
	using promise_type = promise<T>;
	using handle_type = std::coroutine_handle<promise_type>;
	using handle_type_generic = std::coroutine_handle<>;
private:
    handle_type handle;

	coroutine(handle_type h);

	void increment();
	void decrement();
public:
	coroutine(const coroutine<T>&);
	coroutine(coroutine<T>&&);
	coroutine<T>& operator =(const coroutine<T>&);
	coroutine<T>& operator =(coroutine<T>&&);
	~coroutine();

	operator handle_type_generic() const {
		return get_handle();
	}
	operator bool() const {
		return handle.address() != nullptr;
	}
	bool operator !() const {
		return !(bool)(*this);
	}
	bool done() const {
		return handle.done();
	}

	handle_type_generic get_handle() const { return handle; }
	void destroy() {
		handle.destroy();
	}

    //awaitable
	bool await_ready();
	void await_suspend(const std::coroutine_handle<>& h);
	T await_resume();

    //get std::promise
	std::future<T> on_finish_promise() {
		std::future<T> f{};
		auto c = [](std::future<T>& ret, coroutine<T> co) -> coroutine<void> {
			std::promise<T> p{};
			ret = std::move(p.get_future());
			co_await co;
			if constexpr (!std::is_void_v<T>) {
				p.set_value(co.handle.promise().get_return_value());
			}
			else {
				p.set_value();
			}
		};
		c(f, *this);
		return f;
	}
};

// definition

template<typename T>
promise<T>::coroutine_type promise<T>::get_return_object() {
	return coroutine_type(handle_type::from_promise(*this));
}
promise<void>::coroutine_type promise<void>::get_return_object() {
	return coroutine_type(handle_type::from_promise(*this));
}

template<typename T>
void coroutine<T>::increment() {
	if (!*this) return;
	handle.promise().referenceCount++;
}
template<typename T>
void coroutine<T>::decrement() {
	if (!*this) return;
	handle.promise().referenceCount--;
}
template<typename T>
coroutine<T>::coroutine(handle_type h) : handle(h) {
	increment();
}
template<typename T>
coroutine<T>::coroutine(const coroutine<T>& other) {
	handle = other.handle;
	increment();
}
template<typename T>
coroutine<T>::coroutine(coroutine<T>&& other) {
	handle = std::move(other.handle);
}
template<typename T>
coroutine<T>& coroutine<T>::operator =(const coroutine<T>& other) {
	decrement();
	handle = other.handle;
	increment();
}
template<typename T>
coroutine<T>& coroutine<T>::operator =(coroutine<T>&& other) {
	decrement();
	handle = std::move(other.handle);
}
template<typename T>
coroutine<T>::~coroutine() {
	decrement();
}
template<typename T>
bool coroutine<T>::await_ready() {
	STAMPASSERT(*this, "stamp::core::coroutine::co_await - invalid coroutine object. handle is nullptr");
	return handle.done();
}
template<typename T>
void coroutine<T>::await_suspend(const std::coroutine_handle<>& h) {
	handle.promise().push(h);
}
template<typename T>
T coroutine<T>::await_resume() {
	if constexpr (!std::is_void_v<T>) {
		return handle.promise().get_return_value();
	}
}

STAMP_CORE_NAMESPACE_END
#endif