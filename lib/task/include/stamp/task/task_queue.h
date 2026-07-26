// stamp/task/task_queue.h
#ifndef STAMP_TASK_TASK_QUEUE_H
#define STAMP_TASK_TASK_QUEUE_H

#include <blockingconcurrentqueue.h>
#include <stamp/task/coroutine.h>
#include <array>
#include <concepts>

namespace stamp::task {
	template<typename Container=std::array<coroutine_view<void>, 16>> 
		requires std::same_as<typename Container::value_type, coroutine_view<void>>
	class task_bulk {
		friend class task_queue;
	public:
		using container_type = Container;
		using const_iterator = typename container_type::const_iterator;
		using iterator = typename container_type::iterator;
		using value_type = typename container_type::value_type;
		using reference = typename container_type::reference;
		using size_type = typename container_type::size_type;
	private:
		container_type container_v{};
	public:
		task_bulk() {}

		iterator begin() {
			return container_v.begin();
		}
		iterator end() {
			return container_v.end();
		}
		iterator cbegin() const {
			return container_v.cbegin();
		}
		iterator cend() const {
			return container_v.cend();
		}
		size_t size() const {
			return container_v.size();
		}
		size_t max_size() const {
			return container_v.max_size();
		}
	};

	class task_queue {
		moodycamel::BlockingConcurrentQueue<coroutine_view<void>> queue;
	public:
		task_queue() : queue() {}
		task_queue(int init_size) : queue(init_size) {}

		template<typename CoFunc, typename... Args>
		[[nodiscard]] auto enqueue(CoFunc&& func, Args&&... args) {
			auto ret = std::forward<CoFunc>(func)(std::forward<Args>(args)...);
			coroutine_view<void> view = ret;
			queue.enqueue(view);
			return ret;
		}
		template<typename CoFunc, typename... Args>
		void enqueue_detached(CoFunc&& func, Args&&... args) {
			auto ret = std::forward<CoFunc>(func)(std::forward<Args>(args)...);
			ret.detach();
			coroutine_view<void> view = ret;
			queue.enqueue(view);
		}
		template<typename T>
		void enqueue(coroutine<T>& co) {
			queue.enqueue(coroutine_view<T>{co});
		}
		template<typename T>
		void enqueue(coroutine_view<T>& co) {
			queue.enqueue(co);
		}
		template<typename T>
		void enqueue(coroutine_view<T>&& co) {
			queue.enqueue(co);
		}

		template<typename Container = std::array<coroutine_view<void>, 16>>
		task_bulk<Container> wait_dequeue_bulk(Container::size_type max_count) {
			task_bulk<Container> ret{};

			typename Container::size_type count = max_count;
			typename Container::size_type max_size = ret.container_v.max_size();
			if (count > max_size) {
				count = max_size;
			}

			queue.wait_dequeue_bulk(ret.begin(), count);

			return ret;
		}

		struct operator_co_await_t {
			task_queue* queue_v;
			bool await_ready() noexcept {
				return false;
			}
			template<typename T>
			bool await_suspend(const std::coroutine_handle<basic_promise<T>>& handle) noexcept {
				queue_v->queue.enqueue(coroutine_view<T>{handle});
				return true;
			}
			void await_resume() noexcept {}
		};

		auto operator co_await() noexcept {
			return operator_co_await_t{this};
		}
	};
}

#endif // STAMP_TASK_TASK_QUEUE_H
