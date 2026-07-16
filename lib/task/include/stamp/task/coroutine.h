#ifndef STAMP_TASK_COROUTINE_H
#define STAMP_TASK_COROUTINE_H

#include <memory>

namespace stamp::task {

	template<typename T>
	struct promise;
	template<typename T>
	struct coroutine : std::coroutine_handle<promise<T>> {
		using promise_type = promise<T>;

		// bool await_ready() {}
		// void await_suspend(std::coroutine_handle&) {}
		// T await_resume() {}
	};

	template<typename T>
	struct promise {
		// should return a dedicated awaiter object. in order to prevent mangling coroutine_handle
		coroutine<T> get_return_object() { return {coroutine<T>::from_promise(*this)}; }
		std::suspend_never initial_suspend() noexcept { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void return_void() {}
		void return_value(T&&) {}
		void unhandled_exception() {}

		
		// <awaiter> yield_value(T&&);

		// void* operator new(std::size_t);
		// <awaiter> await_transform(<awaiter>);

	};

	// some object that converts coroutines into std::promise in order to work with non-coroutine code.
}

#endif // STAMP_TASK_COROUTINE_H
