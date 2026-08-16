// stamp/task/generic_promise.h
#ifndef STAMP_TASK_GENERIC_PROMISE_H
#define STAMP_TASK_GENERIC_PROMISE_H

#include <memory>
#include <stamp/reflect/function_traits.h>
#include <coroutine>

namespace stamp::task {
	template<typename Promise>
	using promise_suspend_t = typename stamp::reflect::function_traits<&T::await_suspend>::return_type;
	template<typename Promise>
	using promise_resume_t = typename stamp::reflect::function_traits<&T::await_resume>::return_type;

	template<typename ResumeType, typename SuspendType = bool>
	class generic_promise {
	public:
		~generic_promise() = default;
		virtual bool await_ready() = 0;
		virtual SuspendType await_suspend(std::coroutine_handle<> handle) = 0;
		virtual ResumeType await_resume() = 0;
	};

	template<typename T>
	class mixin_promise : public generic_promise<promise_resume_t<T>, bool>, public T {
	public:
		virtual bool await_ready() {
			return T::await_ready();
		}
		virtual bool await_suspend(std::coroutine_handle<> handle) {
			if constexpr (std::is_same_v<promise_suspend_t<T>, void>) {
				T::await_suspend(handle);
				return true;
			}
			else if constexpr (std::is_same_v<promise_suspend_t<T>, bool>) {
				return T::await_suspend(handle);
			}
			else {
				T::await_suspend(handle).resume();
				return true;
			}
		}
		virtual promise_resume_t<T> await_resume() {
			return T::await_resume();
		}
	};

	template<typename ResumeType, typename SuspendType = bool>
	class generic_promise_container {
	public:
		std::unique_ptr<generic_promise<ResumeType, SuspendType>, void(*)(generic_promise<ResumeType, SuspendType>)> promise;

		bool await_ready() {
			return promise->await_ready();
		}
		SuspendType await_suspend(std::coroutine_handle<> handle) {
			return promise->await_suspend(handle);
		}
		ResumeType await_resume() {
			return promise->await_resume();
		}
	};
}

#endif // STAMP_TASK_GENERIC_PROMISE_H
