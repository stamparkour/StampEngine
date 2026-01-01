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

#include <queue>
#include <functional>
#include <atomic>

#include <stamp/core/define.h>
#include <stamp/core/noncopyable.h>
#include <stamp/core/memory.h>
#include <vector>
#include <thread>
#include <stdexcept>

STAMP_CORE_NAMESPACE_BEGIN

template<typename T = std::function<void()>>
class task_queue {
public:
	using function_type = T;
private:
	STAMP_CORE_NAMESPACE::lockable<std::queue<function_type>> taskQueue;
	STAMP_CORE_NAMESPACE::lockable<std::queue<function_type>> nextQueue;
	std::atomic_bool isRunning = false;
	std::thread::id runningThread{};
	std::atomic_int _size;
public:
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
		if (isRunning) throw std::runtime_error("can only have one thread running a task_queue at a time");
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

	void run_all(std::condition_variable& cv) {
		if (isRunning) throw std::runtime_error("can only have one thread running a task_queue at a time");
		
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
};

template<typename T = std::function<void()>>
class thread_pool {
public:
	using function_type = T;
	using queue_type = task_queue<T>;
	static constexpr int core_count = 0;
private:
	struct pool_t {
		std::thread thread;
		queue_type queue;
		std::condition_variable cv{};
	};
	std::vector<pool_t> threadPool{};
	std::atomic_bool running;

	void threadTask(pool_t* p) {
		while (running) {
			p->queue.run_all(p->cv);
		}
	}
public:
	void push(const std::function<void()>& func) {
		queue.get_unique_lock();
		queue.push(func);
	}

	thread_pool(int threads = core_count) {
		if(threads == core_count) {
			threads = threads = std::thread::hardware_concurrency();
		}
		threadPool.reserve(threads);

		for (int i = 0; i < threads; i++) {
			threadPool.emplace_back({ thread_pool::threadTask, this, &threadPool[i] }, {});
		}
	}
};

STAMP_CORE_NAMESPACE_END

#endif