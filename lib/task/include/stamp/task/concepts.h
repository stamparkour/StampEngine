#ifndef STAMP_TASK_CONCEPTS_H
#define STAMP_TASK_CONCEPTS_H

#include <coroutine>
#include <concepts>
#include <stamp/reflect/function_traits.h>

namespace stamp::task {
	template<typename T>
	concept awaitor_c =
		requires (T a) {
			{ a.await_ready() } -> std::convertible_to<bool>;
				&T::await_suspend;
				a.await_resume();
			} && 
			(std::tuple_size_v<typename stamp::reflect::function_traits<decltype(&T::await_suspend)>::arg_type> == 1) &&
			std::convertible_to<std::tuple_element_t<0, typename stamp::reflect::function_traits<decltype(&T::await_suspend)>::arg_type>, typename std::coroutine_handle<>>;
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
		std::invocable<CoFunc, Args...>&&
		is_coroutine_c<std::invoke_result_t<CoFunc, Args...>>;
}

#endif // STAMP_TASK_CONCEPTS_H