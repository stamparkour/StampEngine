#ifndef STAMP_TASK_THREAD_POOL_H
#define STAMP_TASK_THREAD_POOL_H

#include <stamp/task/coroutine.h>

namespace stamp::task {
	class thread_pool {
		// threadsafe task queue
		// threadsafe time based priority queue
		struct thread_state {

		};
		void thread_func() {

		}
	public:
		thread_pool() {} // uses optimal thread count
		thread_pool(unsigned int thread_count) {}
		void schedule(/* coroutine, arguments */) {}

		auto operator co_await() {

		}
	};
}

#endif // STAMP_TASK_THREAD_POOL_H
