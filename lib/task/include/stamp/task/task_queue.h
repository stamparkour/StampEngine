// stamp/task/task_queue.h
#ifndef STAMP_TASK_TASK_QUEUE_H
#define STAMP_TASK_TASK_QUEUE_H

#include <blockingconcurrentqueue.h>
#include <stamp/task/coroutine.h>
#include <array>
#include <concepts>
#include <queue>
#include <chrono>

namespace stamp::task {
	inline constexpr int default_dequeue_count_v = 16;

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
		[[nodiscard]] auto emplace(CoFunc&& func, Args&&... args) {
			auto ret = std::forward<CoFunc>(func)(std::forward<Args>(args)...);
			coroutine_view<void> view = ret;
			push(view);
			return ret;
		}
		template<typename CoFunc, typename... Args>
		void emplace_detached(CoFunc&& func, Args&&... args) {
			auto ret = std::forward<CoFunc>(func)(std::forward<Args>(args)...);
			ret.detach();
			coroutine_view<void> view = ret;
			push(view);
		}
		template<typename T>
		void push(coroutine<T>& co) {
			queue.enqueue(coroutine_view<T>{co});
		}
		template<typename T>
		void push(coroutine_view<T>& co) {
			queue.enqueue(co);
		}
		template<typename T>
		void push(coroutine_view<T>&& co) {
			queue.enqueue(co);
		}

		std::size_t size_aprox() const {
			return queue.size_approx();
		}

		template<typename Container = std::array<coroutine_view<void>, 16>>
		task_bulk<Container> wait_dequeue_bulk(Container::size_type max_count = 0) {
			task_bulk<Container> ret{};

			typename Container::size_type count = max_count;
			typename Container::size_type max_size = ret.container_v.max_size();

			if (count == 0) {
				count = (typename Container::size_type)default_dequeue_count_v;
			}
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
				queue_v->push(coroutine_view<T>{handle});
				return true;
			}
			void await_resume() noexcept {}
		};

		auto operator co_await() noexcept {
			return operator_co_await_t{this};
		}
	};

	class timer_task_queue {
	public:
		using time_point = typename std::chrono::steady_clock::time_point;
		using clock = std::chrono::steady_clock;
	private:
		struct entry_t {
			time_point time_v;
			coroutine_view<void> coroutine_v;

			auto operator <=>(const entry_t& other) const {
				return time_v <=> other.time_v;
			}
			bool operator ==(const entry_t& other) const {
				return time_v == other.time_v;
			}
		};
		std::priority_queue<entry_t, std::vector<entry_t>, std::greater<entry_t>> queue;
		std::mutex queue_lock;
		std::condition_variable queue_cv;
		std::atomic_size_t size_v;
	public:
		timer_task_queue() : queue() {}

		template<typename CoFunc, typename... Args>
		[[nodiscard]] auto emplace_until(const time_point& exec_time, CoFunc&& func, Args&&... args) {
			auto ret = std::forward<CoFunc>(func)(std::forward<Args>(args)...);
			coroutine_view<void> view = ret;
			push_until(exec_time, view);
			return ret;
		}
		template<typename CoFunc, typename... Args>
		void emplace_detached_until(const time_point& exec_time, CoFunc&& func, Args&&... args) {
			auto ret = std::forward<CoFunc>(func)(std::forward<Args>(args)...);
			ret.detach();
			coroutine_view<void> view = ret;
			push_until(exec_time, view);
		}
		template<typename T>
		void push_until(const time_point& exec_time, coroutine<T>& co) {
			{
				std::lock_guard l{queue_lock};
				size_v.fetch_add(1);
				queue.emplace(exec_time, coroutine_view<T>{co});
			}
			queue_cv.notify_one();
		}
		template<typename T>
		void push_until(const time_point& exec_time, coroutine_view<T>& co) {
			{
				std::lock_guard l{queue_lock};
				size_v.fetch_add(1);
				queue.emplace(exec_time, co);
			}
			queue_cv.notify_one();
		}
		template<typename T>
		void push_until(const time_point& exec_time, coroutine_view<T>&& co) {
			{
				std::lock_guard l{queue_lock};
				size_v.fetch_add(1);
				queue.emplace(exec_time, std::move(co));
			}
			queue_cv.notify_one();
		}

		std::size_t size() const {
			return size_v.load();
		}

		coroutine_view<void> pop_wait() {
			std::unique_lock ul{queue_lock}; // locks mutex

			entry_t entry_v;
			while (true) {
				if (queue.empty()) {
					queue_cv.wait(ul);
				}
				else {
					entry_v = queue.top();
					if (clock::now() > entry_v.time_v) break;
					queue_cv.wait_until(ul, entry_v.time_v);
				}
			}
			// top is a valid pop

			queue.pop();
			size_v.fetch_sub(1);
			return entry_v.coroutine_v;
		}

		/*template<typename Container = std::array<coroutine_view<void>, 16>>
		task_bulk<Container> wait_dequeue_bulk(Container::size_type max_count) {
			task_bulk<Container> ret{};

			typename Container::size_type count = max_count;
			typename Container::size_type max_size = ret.container_v.max_size();
			if (count > max_size) {
				count = max_size;
			}

			queue.wait_dequeue_bulk(ret.begin(), count);

			return ret;
		}*/

		struct co_await_until_t {
			timer_task_queue* queue_v;
			time_point time;
			bool await_ready() noexcept {
				return !(clock::now() > time);
			}
			template<typename T>
			bool await_suspend(const std::coroutine_handle<basic_promise<T>>& handle) noexcept {
				queue_v->push_until(time, coroutine_view<T>{handle});
				return true;
			}
			void await_resume() noexcept {}
		};

		auto await_until(const time_point& time) noexcept {
			return co_await_until_t{this, time};
		}
	};
}

#endif // STAMP_TASK_TASK_QUEUE_H
