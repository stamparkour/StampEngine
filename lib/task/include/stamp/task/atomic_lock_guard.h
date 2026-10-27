#ifndef STAMP_TASK_ATOMIC_LOCK_GUARD_H
#define STAMP_TASK_ATOMIC_LOCK_GUARD_H

#include <atomic>
#include <stamp/core/assert.h>

namespace stamp::task {
	struct atomic_lock_guard {
		std::atomic_bool* lock_v = nullptr;

		atomic_lock_guard() = default;
		atomic_lock_guard(std::atomic_bool& t) : lock_v(&t) {
			bool v = false;
			while (!lock_v->compare_exchange_weak(v, true)) {
				v = false;
				lock_v->wait(true);
			}
		}

		atomic_lock_guard(const atomic_lock_guard&) = delete;
		atomic_lock_guard(atomic_lock_guard&& other) {
			lock_v = other.lock_v;
			other.lock_v = nullptr;
		}
		atomic_lock_guard& operator =(const atomic_lock_guard&) = delete;
		atomic_lock_guard& operator =(atomic_lock_guard&& other) {
			if (lock_v != nullptr) {
				stamp::core::s_assert(lock_v->load() == true, "atomic must be true before reassignment");
				lock_v->store(false);
				lock_v->notify_one();
			}
			lock_v = other.lock_v;
			other.lock_v = nullptr;
			return *this;
		}

		~atomic_lock_guard() {
			if (lock_v != nullptr) {
				stamp::core::s_assert(lock_v->load() == true, "atomic must be true before deconstruction");
				lock_v->store(false);
				lock_v->notify_one();
				lock_v = nullptr;
			}
		}
	};
}

#endif // STAMP_TASK_ATOMIC_LOCK_GUARD_H