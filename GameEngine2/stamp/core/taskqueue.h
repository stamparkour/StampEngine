//stamp/core/taskqueue.h

#pragma once
#ifndef STAMP_CORE_TASKQUEUE_H
#define STAMP_CORE_TASKQUEUE_H

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


//need to implement "run_failed" for timed task queue

#include <queue>
#include <functional>
#include <atomic>

#include <stamp/core/define.h>
#include <stamp/core/noncopyable.h>
#include <stamp/core/memory.h>
#include <vector>
#include <thread>
#include <stdexcept>
#include <limits>
#include <chrono>

STAMP_CORE_NAMESPACE_BEGIN

template<typename T = std::function<void()>>
class basic_task_queue {
public:
	using function_type = T;
private:
	STAMP_CORE_NAMESPACE::lockable<std::queue<function_type>> taskQueue;
	STAMP_CORE_NAMESPACE::lockable<std::queue<function_type>> nextQueue;
	std::atomic_bool isRunning = false;
	std::thread::id runningThread{};
	std::atomic_int _size;
public:
	basic_task_queue() {}
	~basic_task_queue() {
		if(is_running()) {
			throw std::runtime_error("stamp::core::basic_task_queue - cannot destroy a task queue while it is running");
		}
		run_failed();
	}
	bool is_running() const {
		return isRunning;
	}
	bool is_running_on_current_thread() const {
		return isRunning && (runningThread == std::this_thread::get_id());
	}
	void push(const function_type& h) {
		auto l = taskQueue.get_unique_lock();
		taskQueue.push(h);
		_size++;
	}
	void push_next(const function_type& h) {
		if (isRunning) {
			auto l = nextQueue.get_unique_lock();
			nextQueue.push(h);
			_size++;
		}
		else {
			push(h);
		}
	}
	size_t size() const {
		return _size;
	}

	void run_all() {
		STAMPASSERT(!isRunning, "can only have one thread running a task_queue at a time");
		isRunning = true;
		runningThread = std::this_thread::get_id();
		while (true) {
			function_type task = nullptr;
			{
				auto l = taskQueue.get_unique_lock();
				if (taskQueue.empty()) {
					auto l2 = nextQueue.get_unique_lock();
					std::swap(taskQueue, nextQueue);
					break;
				}
				_size--;
				task = taskQueue.front();
				taskQueue.pop();
			}
			if (task) {
				try {
					task();
				}
				catch (std::exception& e) {
					STAMPDMSG("stamp::engine::coroutine_queue - Task Exception: " << e.what());
				}
			}
		}
		isRunning = false;
	}

	void run_cv(std::condition_variable& cv) {
		STAMPASSERT(!isRunning, "can only have one thread running a task_queue at a time");
		isRunning = true;

		function_type task = nullptr;
		{
			auto l = taskQueue.get_unique_lock();
			cv.wait(l, [this]() -> bool {
				return !taskQueue.empty();
			});


			isRunning = true;
			runningThread = std::this_thread::get_id();

			auto l2 = nextQueue.get_unique_lock();
			std::swap(taskQueue, nextQueue);

			_size--;
			task = taskQueue.front();
			taskQueue.pop();
		}
		if (task) {
			try {
				task();
			}
			catch (std::exception& e) {
				STAMPDMSG("stamp::engine::coroutine_queue - Task Exception: " << e.what());
			}
		}

		isRunning = false;
	}

	void run_failed() {
		if constexpr (requires { std::declval< function_type>().task_queue_failed(); }) {
			STAMPASSERT(!isRunning, "can only have one thread running a task_queue at a time");
			isRunning = true;
			runningThread = std::this_thread::get_id();
			while (true) {
				function_type task = nullptr;
				{
					auto l = taskQueue.get_unique_lock();
					if (taskQueue.empty()) {
						auto l2 = nextQueue.get_unique_lock();
						std::swap(taskQueue, nextQueue);
						break;
					}
					_size--;
					task = taskQueue.front();
					taskQueue.pop();
				}
				if (task) {
					try {
						task.task_queue_failed();
					}
					catch (std::exception& e) {
						STAMPDMSG("stamp::engine::coroutine_queue - Task Exception: " << e.what());
					}
				}
			}
			isRunning = false;
		}
	}
};

template<typename T = std::function<void()>>
class basic_timed_task_queue {
public:
	using function_type = T;
	using time_point = std::chrono::time_point<std::chrono::steady_clock>;
private:
	struct queue_item{
		timepoint t;
		function_type f;

		std::strong_ordering operator <=>(const queue_item& other) const {
			return t <=> other.t;
		}
	};

	STAMP_CORE_NAMESPACE::lockable<std::priority_queue<queue_item>> taskQueue;
	STAMP_CORE_NAMESPACE::lockable<std::priority_queue<queue_item>> nextQueue;
	std::atomic_bool isRunning = false;
	std::thread::id runningThread{};
	std::atomic_int _size;
	std::mutex mutex;
public:
	bool is_running() const {
		return isRunning;
	}
	bool is_running_on_current_thread() const {
		return isRunning && (runningThread == std::this_thread::get_id());
	}
	void push(const function_type& h, const time_point& t = {}) {
		auto l = taskQueue.get_unique_lock();
		taskQueue.push({ t, h });
		_size++;
	}
	void push_next(const function_type& h, const time_point& t = {}) {
		if (isRunning) {
			auto l = nextQueue.get_unique_lock();
			nextQueue.push({ t, h });
			_size++;
		}
		else {
			push(h, t);
		}
	}
	size_t size() const {
		return _size;
	}

	void run_cv(std::condition_variable& cv) {
		STAMPASSERT(!isRunning,"can only have one thread running a task_queue at a time");
		isRunning = true;

		queue_item task{};
		{
			auto l = taskQueue.get_unique_lock();
			cv.wait(l, [this]() -> bool {
				return !taskQueue.empty();
				});


			isRunning = true;
			runningThread = std::this_thread::get_id();

			auto l2 = nextQueue.get_unique_lock();
			std::swap(taskQueue, nextQueue);

			_size--;
			task = taskQueue.top();
			taskQueue.pop();
		}
		if (task.f) {
			std::unique_lock l{ mutex };
			cv.wait_until(l, task.t);
			if (std::chrono::steady_clock::now() < task.t) {
				isRunning = false;
				return;
			}
			try {
				task.f();
			}
			catch (std::exception& e) {
				STAMPDMSG("stamp::engine::coroutine_queue - Task Exception: " << e.what());
			}
		}

		isRunning = false;
	}
};

template<typename T = std::function<void()>>
class basic_thread_pool {
public:
	using function_type = T;
	using queue_type = basic_task_queue<T>;
	static constexpr int core_count = 0;
private:
	struct pool_t {
		std::thread thread;
		queue_type queue{};
		std::condition_variable cv{};
	};
	std::vector<pool_t> threadPool{};
	std::atomic_bool running;


	void threadTask(pool_t* p) {
		while (running) {
			p->queue.run_cv(p->cv);
		}
	}
	pool_t* min() {
		pool_t* minp = nullptr;
		size_t min = std::numeric_limits<size_t>::max();
		for (auto& p : threadPool) {
			size_t s = p.queue.size();
			if (s < min) {
				minp = &p;
			}
		}
		return minp;
	}
public:
	void push(const function_type& func) {
		pool_t* minp = min();
		if (minp == nullptr) return;
		minp->queue.push(func);
	}
	void push_next(const function_type& func) {
		pool_t* minp = min();
		if (minp == nullptr) return;
		minp->queue.push_next(func);
	}

	basic_thread_pool(int threads = core_count) {
		if(threads == core_count) {
			threads = threads = std::thread::hardware_concurrency();
		}
		threadPool.reserve(threads);

		for (int i = 0; i < threads; i++) {
			threadPool.emplace_back(std::thread{ basic_thread_pool::threadTask, this, &threadPool[i] });
		}
	}
};

template<typename T = std::function<void()>>
class basic_timed_thread_pool {
public:
	using function_type = T;
	using queue_type = basic_timed_task_queue<T>;
	using time_point = queue_type::time_point;
	static constexpr int core_count = 0;
private:
	struct pool_t {
		std::thread thread;
		queue_type queue{};
		std::condition_variable cv{};
	};
	std::vector<pool_t> threadPool{};
	std::atomic_bool running;


	void threadTask(pool_t* p) {
		while (running) {
			p->queue.run_cv(p->cv);
		}
	}
	pool_t* min() {
		pool_t* minp = nullptr;
		size_t min = std::numeric_limits<size_t>::max();
		for (auto& p : threadPool) {
			size_t s = p.queue.size();
			if (s < min) {
				minp = &p;
			}
		}
		return minp;
	}
public:
	void push(const function_type& func, const queue_type::time_point& t = {}) {
		pool_t* minp = min();
		if (minp == nullptr) return;
		minp->queue.push(func, t);
	}
	void push_next(const function_type& func, const queue_type::time_point& t = {}) {
		pool_t* minp = min();
		if (minp == nullptr) return;
		minp->queue.push_next(func, t);
	}

	basic_timed_thread_pool(int threads = core_count) {
		if (threads == core_count) {
			threads = threads = std::thread::hardware_concurrency();
		}
		threadPool.reserve(threads);

		for (int i = 0; i < threads; i++) {
			threadPool.emplace_back(std::thread{ basic_timed_thread_pool::threadTask, this, &threadPool[i] });
		}
	}
};

using task_queue = basic_task_queue<>;
using thread_pool = basic_thread_pool<>;

using timed_task_queue = basic_timed_task_queue<>;
using timed_thread_pool = basic_timed_thread_pool<>;

STAMP_CORE_NAMESPACE_END

#endif