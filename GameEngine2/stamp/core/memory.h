//stamp/core/memory.h

#pragma once
#ifndef STAMP_CORE_MEMORY_H
#define STAMP_CORE_MEMORY_H

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


#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <cstddef>
#include <utility>
#include <memory>
#include <atomic>
#include <type_traits>

#include <stamp/core/define.h>
#include <stamp/core/noncopyable.h>
#include <stamp/debug.h>

#ifdef STAMP_DEBUG
#define STAMP_MEMORY_DEBUG
#endif

#define STAMP_MEMORY_THREADSAFE_FRIEND template<typename T, typename... Args> friend STAMP_CORE_NAMESPACE::threadsafe_ptr<T> STAMP_CORE_NAMESPACE::make_threadsafe(Args&&... args)

STAMP_CORE_NAMESPACE_BEGIN

template <typename T>
class threadsafe_ptr;
template <typename T>
class weak_threadsafe_ptr;
template <typename T>
class enable_threadsafe_from_this;
template <typename T>
using tsp = threadsafe_ptr<T>;

template<typename T, typename... Args>
threadsafe_ptr<T> make_threadsafe(Args&&... args);

template<typename T>
class threadsafe_control {
public:
	std::shared_mutex mutex;
	T* ptr;

	threadsafe_control(T* p) : ptr(p) {}

	~threadsafe_control() {
		if (ptr == nullptr) return;
		delete ptr;
		ptr = nullptr;
	}
};

template<typename T> 
class readonly_ptr : STAMP_CORE_NAMESPACE::INonCopyable, STAMP_CORE_NAMESPACE::INonAddressable {
	template<typename U>
	friend class threadsafe_ptr;

	using ptr_type = threadsafe_control<T>;
	std::shared_ptr<ptr_type> ptr;
	bool locked = false;

	readonly_ptr(const std::shared_ptr<ptr_type>& other, bool startLocked) : ptr(other) {
		if(startLocked) lock();
	}
public:
	~readonly_ptr() {
		unlock();
	}
	readonly_ptr() : readonly_ptr(nullptr, false) {}
	readonly_ptr(nullptr_t) : readonly_ptr(nullptr, false) {}

	const T& operator*() const {
		STAMPASSERT(ptr != nullptr, "stamp::readonly_ptr::operator* - Dereferencing null readonly_ptr");
		return *(ptr->ptr);
	}
	const T* operator->() const {
		STAMPASSERT(ptr != nullptr, "stamp::readonly_ptr::operator-> - Dereferencing null readonly_ptr");
		return ptr->ptr;
	}
	const T& operator[](size_t index) const {
		STAMPASSERT(ptr != nullptr, "stamp::readonly_ptr::operator[] - Dereferencing null readonly_ptr");
		return ptr->ptr[index];
	}
	explicit operator const T* () const {
		return get();
	}
	bool operator==(const readonly_ptr<T>& b) const {
		return ptr == b.ptr;
	}
	bool operator!=(const readonly_ptr<T>& b) const {
		return ptr != b.ptr;
	}
	bool operator==(nullptr_t) const {
		return ptr == nullptr;
	}
	bool operator!=(nullptr_t) const {
		return ptr != nullptr;
	}
	explicit operator bool() const {
		return ptr != nullptr;
	}
	bool operator!() const {
		return ptr == nullptr;
	}

	const T* get() const {
		return ptr->ptr;
	}
	
	void lock() {
		if (ptr == nullptr) return;
		if (locked) return;
		ptr->mutex.lock_shared();
		locked = true;
	}
	void unlock() {
		if (ptr == nullptr) return;
		if (!locked) return;
		locked = false;
		ptr->mutex.unlock_shared();
	}
};

template<typename T>
class writable_ptr {
	template<typename U>
	friend class threadsafe_ptr;

	using ptr_type = threadsafe_control<T>;
	std::shared_ptr<ptr_type> ptr;
	bool locked = false;

	writable_ptr(const std::shared_ptr<ptr_type>& other, bool startLocked) : ptr(other) {
		if (startLocked) lock();
	}
public:
	~writable_ptr() {
		unlock();
	}
	writable_ptr() : writable_ptr(nullptr, false) {}
	writable_ptr(nullptr_t) : writable_ptr(nullptr, false) {}

	T& operator*() {
		STAMPASSERT(ptr != nullptr, "stamp::writable_ptr::operator* - Dereferencing null readonly_ptr");
		return *(ptr->ptr);
	}
	const T& operator*() const {
		STAMPASSERT(ptr != nullptr, "stamp::writable_ptr::operator* - Dereferencing null readonly_ptr");
		return *(ptr->ptr);
	}
	T* operator->() {
		STAMPASSERT(ptr != nullptr, "stamp::writable_ptr::operator-> - Dereferencing null readonly_ptr");
		return ptr->ptr;
	}
	const T* operator->() const {
		STAMPASSERT(ptr != nullptr, "stamp::writable_ptr::operator-> - Dereferencing null readonly_ptr");
		return ptr->ptr;
	}
	T& operator[](size_t index) {
		STAMPASSERT(ptr != nullptr, "stamp::writable_ptr::operator[] - Dereferencing null readonly_ptr");
		return ptr->ptr[index];
	}
	const T& operator[](size_t index) const {
		STAMPASSERT(ptr != nullptr, "stamp::writable_ptr::operator[] - Dereferencing null readonly_ptr");
		return ptr->ptr[index];
	}
	explicit operator T* () {
		return get();
	}
	explicit operator const T* () const {
		return get();
	}
	bool operator==(const readonly_ptr<T>& b) const {
		return ptr == b.ptr;
	}
	bool operator!=(const readonly_ptr<T>& b) const {
		return ptr != b.ptr;
	}
	bool operator==(nullptr_t) const {
		return ptr == nullptr;
	}
	bool operator!=(nullptr_t) const {
		return ptr != nullptr;
	}
	explicit operator bool() const {
		return ptr != nullptr;
	}
	bool operator!() const {
		return ptr == nullptr;
	}

	T* get() {
		return ptr->ptr;
	}
	const T* get() const {
		return ptr->ptr;
	}

	void lock() {
		if (ptr == nullptr) return;
		if (locked) return;
		ptr->mutex.lock();
		locked = true;
	}
	void unlock() {
		if (ptr == nullptr) return;
		if (!locked) return;
		locked = false;
		ptr->mutex.unlock();
	}
};

template<typename T>
class threadsafe_ptr {
	using ptr_type = threadsafe_control<T>;
public:
	using element_type = T;
	
	template<typename U, typename... Args>
	friend threadsafe_ptr<U> make_threadsafe(Args&&... args);
	template<typename U>
	friend class enable_threadsafe_from_this;
	template<typename U>
	friend class weak_threadsafe_ptr;
	template<typename U, typename V>
	friend threadsafe_ptr<U> static_pointer_cast(const threadsafe_ptr<V>& other);
	template<typename U, typename V>
	friend threadsafe_ptr<U> dynamic_pointer_cast(const threadsafe_ptr<V>& other);
	template<typename U>
	friend class atomic_threadsafe_ptr;

	using weak_type = weak_threadsafe_ptr<element_type>;
	using read_type = readonly_ptr<element_type>;
	using write_type = writable_ptr<element_type>;
private:
	std::shared_ptr<ptr_type> ptr;

	threadsafe_ptr(const std::shared_ptr<ptr_type>& other) {
		ptr = other;
	}
public:
	threadsafe_ptr() : ptr{ nullptr } {}
	threadsafe_ptr(nullptr_t) : ptr{ nullptr } {}
	explicit threadsafe_ptr(T* v) {
		if (v == nullptr) {
			ptr = nullptr;
		}
		else {
			ptr = std::make_shared<ptr_type>(v);
			if constexpr (std::is_base_of_v<enable_threadsafe_from_this<T>, T>) {
				v->weak_this = weak_threadsafe_ptr<T>(ptr);
			}
		}
	}
	threadsafe_ptr(const weak_threadsafe_ptr<T>& other) {
		ptr = other.ptr.lock();
	}
	threadsafe_ptr<T>& operator=(nullptr_t) {
		ptr = nullptr;
		return *this;
	}
	threadsafe_ptr<T>& operator=(T* v) {
		if (v == nullptr) {
			ptr = nullptr;
		}
		else {
			ptr = std::make_shared<ptr_type>(v);
			if constexpr (std::is_base_of_v<enable_threadsafe_from_this<T>, T>) {
				v->weak_this = weak_threadsafe_ptr<T>(ptr);
			}
		}
		return *this;
	}
	threadsafe_ptr<T>& operator=(const weak_threadsafe_ptr<T>& other) {
		ptr = other.ptr.lock();
		return *this;
	}

	threadsafe_ptr(const threadsafe_ptr& other) {
		ptr = other.ptr;
	}
	threadsafe_ptr(threadsafe_ptr&& other) {
		ptr = other.ptr;
	}
	threadsafe_ptr<T>& operator=(const threadsafe_ptr& other) {
		ptr = other.ptr;
		return *this;
	}
	threadsafe_ptr<T>& operator=(threadsafe_ptr&& other) {
		ptr = other.ptr;
		return *this;
	}
	~threadsafe_ptr() = default;

	bool operator ==(const threadsafe_ptr& other) const {
		return ptr == other.ptr;
	}
	bool operator !=(const threadsafe_ptr& other) const {
		return ptr != other.ptr;
	}
	bool operator ==(nullptr_t) const {
		return ptr == nullptr;
	}
	bool operator !=(nullptr_t) const {
		return ptr != nullptr;
	}
	explicit operator bool() const {
		return ptr != nullptr;
	}
	bool operator !() const {
		return ptr == nullptr;
	}
	size_t use_count() const {
		return ptr.use_count();
	}
	bool unique() const {
		return use_count() == 1;
	}
	void reset() {
		ptr.reset();
	}
	write_type get() const {
		return write_type(ptr, true);
	}
	write_type get_unsafe() const {
		return write_type(ptr, false);
	}
	read_type get_readonly() const {
		return read_type(ptr, true);
	}
	read_type get_readonly_unsafe() const {
		return read_type(ptr, false);
	}
};

template<typename T>
class weak_threadsafe_ptr {
	template<typename U>
	friend class threadsafe_ptr;
public:
	using element_type = T;
	using strong_type = threadsafe_ptr<T>;
private:
	using ptr_type = threadsafe_control<T>;
	std::weak_ptr<ptr_type> ptr;

	weak_threadsafe_ptr(const std::weak_ptr<ptr_type>& other) {
		ptr = other;
	}
public:
	weak_threadsafe_ptr() : ptr{} {}
	weak_threadsafe_ptr(nullptr_t) : ptr{} {}
	weak_threadsafe_ptr<T>& operator=(nullptr_t) {
		ptr = {};
		return *this;
	}

	weak_threadsafe_ptr(const strong_type& other) {
		ptr = other.ptr;
	}
	weak_threadsafe_ptr(strong_type&& other) {
		ptr = std::move(other.ptr);
	}
	weak_threadsafe_ptr<T>& operator=(const strong_type& other) {
		ptr = other.ptr;
		return *this;
	}
	weak_threadsafe_ptr<T>& operator=(strong_type&& other) {
		ptr = std::move(other.ptr);
		return *this;
	}

	weak_threadsafe_ptr(const weak_threadsafe_ptr& other) {
		ptr = other.ptr;
	}
	weak_threadsafe_ptr(weak_threadsafe_ptr&& other) {
		ptr = other.ptr;
	}
	weak_threadsafe_ptr<T>& operator=(const weak_threadsafe_ptr& other) {
		ptr = other.ptr;
		return *this;
	}
	weak_threadsafe_ptr<T>& operator=(weak_threadsafe_ptr&& other) {
		ptr = other.ptr;
		return *this;
	}
	~weak_threadsafe_ptr() = default;

	size_t use_count() const {
		return ptr.use_count();
	}
	bool expired() const {
		auto p = ptr;
		return p.expired();
	}
	void reset() {
		ptr.reset();
	}
	strong_type lock() const {
		return strong_type(ptr.lock());
	}
};

template<typename T>
class atomic_threadsafe_ptr : STAMP_CORE_NAMESPACE::INonCopyable {
	using ptr_type = threadsafe_control<T>;
public:
	using element_type = T;
	using strong_type = threadsafe_ptr<T>;
private:
	std::atomic<std::shared_ptr<ptr_type>> ptr;
public:
	atomic_threadsafe_ptr() : ptr{ std::shared_ptr<ptr_type>(nullptr) } {}
	atomic_threadsafe_ptr(nullptr_t) : ptr{ std::shared_ptr<ptr_type>(nullptr) } {}
	atomic_threadsafe_ptr(const threadsafe_ptr<T>& other) {
		ptr.store(other.ptr);
	}
	atomic_threadsafe_ptr<T>& operator=(nullptr_t) {
		ptr.store(nullptr);
		return *this;
	}
	atomic_threadsafe_ptr<T>& operator=(const threadsafe_ptr<T>& other) {
		ptr.store(other.ptr);
		return *this;
	}
	operator strong_type() const {
		return strong_type(ptr.load());
	}
	bool is_lock_free() const noexcept {
		return ptr.is_lock_free();
	}
	strong_type load() const {
		return strong_type(ptr.load());
	}
	void store(const strong_type& desired) {
		ptr.store(desired.ptr);
	}
	strong_type exchange(const strong_type& desired) {
		return strong_type(ptr.exchange(desired.ptr));
	}
	bool compare_exchange_strong(strong_type& expected, const strong_type& desired) {
		auto exp = expected.ptr;
		bool result = ptr.compare_exchange_strong(exp, desired.ptr);
		if (!result) {
			expected = strong_type(exp);
		}
		return result;
	}
	void wait(const strong_type& old) const {
		ptr.wait(old.ptr);
	}
	void notify_one() {
		ptr.notify_one();
	}
	void notify_all() {
		ptr.notify_all();
	}
};

template<typename T>
class atomic_weak_threadsafe_ptr : STAMP_CORE_NAMESPACE::INonCopyable {
	using ptr_type = threadsafe_control<T>;
public:
	using element_type = T;
	using weak_type = threadsafe_ptr<T>;
private:
	std::atomic<std::weak_ptr<ptr_type>> ptr;
public:
	atomic_weak_threadsafe_ptr() : ptr{ nullptr } {}
	atomic_weak_threadsafe_ptr(nullptr_t) : ptr{ nullptr } {}
	atomic_weak_threadsafe_ptr<T>& operator=(nullptr_t) {
		ptr.store(nullptr);
		return *this;
	}
	operator weak_type() const {
		return weak_type(ptr.load());
	}
	bool is_lock_free() const noexcept {
		return ptr.is_lock_free();
	}
	weak_type load() const {
		return weak_type(ptr.load());
	}
	void store(const weak_type& desired) {
		ptr.store(desired.ptr);
	}
	weak_type exchange(const weak_type& desired) {
		return weak_type(ptr.exchange(desired.ptr));
	}
	bool compare_exchange_strong(weak_type& expected, const weak_type& desired) {
		auto exp = expected.ptr;
		bool result = ptr.compare_exchange_strong(exp, desired.ptr);
		if (!result) {
			expected = weak_type(exp);
		}
		return result;
	}
	void wait(const weak_type& old) const {
		ptr.wait(old.ptr);
	}
	void notify_one() {
		ptr.notify_one();
	}
	void notify_all() {
		ptr.notify_all();
	}
};

//template<typename T>
//class std::atomic<stamp::threadsafe_ptr<T>> {
//
//};

template<typename T, typename... Args>
inline threadsafe_ptr<T> make_threadsafe(Args&&... args) {
	//could be optimized
	return threadsafe_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename U, typename V>
inline threadsafe_ptr<U> static_pointer_cast(const threadsafe_ptr<V>& other) {
	return threadsafe_ptr<U>(std::static_pointer_cast<threadsafe_ptr<U>::ptr_type>(other.ptr));
}
template<typename U, typename V>
inline threadsafe_ptr<U> dynamic_pointer_cast(const threadsafe_ptr<V>& other) {
	return threadsafe_ptr<U>(std::dynamic_pointer_cast<threadsafe_ptr<U>::ptr_type>(other.ptr));
}


template<typename T>
class enable_threadsafe_from_this {
	template<typename U>
	friend class threadsafe_ptr;
	using instance_type = threadsafe_control<T>;
	using base_type = std::enable_shared_from_this<instance_type>;
	
	weak_threadsafe_ptr<T> weak_this;
protected:
	enable_threadsafe_from_this() {}
public:
	threadsafe_ptr<T> threadsafe_from_this() {
		return weak_this.lock();
	}
};

template<typename T, typename Base>
class enable_threadsafe_from_this_derived {
protected:
	enable_threadsafe_from_this_derived() {}
public:

	threadsafe_ptr<T> threadsafe_from_this() {
		T* t = static_cast<T*>(this);
		Base* base = static_cast<Base*>(t);
		return static_pointer_cast<T>(base->threadsafe_from_this());
	}
	threadsafe_ptr<Base> threadsafe_from_base() {
		T* t = static_cast<T*>(this);
		Base* base = static_cast<Base*>(t);
		return base->threadsafe_from_this();
	}
};

template<typename T>
class lockable : public T {
private:
	mutable std::mutex _mutex;
public:

	template <typename... Args>
	lockable(Args&&... args) : T(std::forward<Args>(args)...) {}
	lockable(const lockable& other) : T(*static_cast<const T*>(&other)) {}
	lockable(lockable&& other) : T(std::move(*static_cast<T*>(&other))) {}
	lockable& operator =(const lockable& other) {
		T::operator=(*static_cast<const T*>(&other));
		return *this;
	}
	lockable& operator =(lockable&& other) {
		T::operator=(std::move(*static_cast<T*>(&other)));
		return *this;
	}

	void lock() const {
		_mutex.lock();
	}
	void unlock() const {
		_mutex.unlock();
	}

	std::mutex& get_mutex() const {
		return _mutex;
	}
	std::unique_lock<std::mutex> get_unique_lock() const {
		return std::unique_lock<std::mutex>(_mutex);
	}
};

template<typename T>
class shared_lockable : public T {
private:
	mutable std::shared_mutex _mutex;
public:

	template <typename... Args>
	shared_lockable(Args&&... args) : T(std::forward<Args>(args)...) {}
	shared_lockable(const shared_lockable& other) : T(*static_cast<const T*>(&other)) {}
	shared_lockable(shared_lockable&& other) : T(std::move(*static_cast<T*>(&other))) {}
	shared_lockable& operator =(const shared_lockable& other) {
		T::operator=(*static_cast<const T*>(&other));
		return *this;
	}
	shared_lockable& operator =(shared_lockable&& other) {
		T::operator=(std::move(*static_cast<T*>(&other)));
		return *this;
	}

	void lock() const {
		_mutex.lock();
	}
	void unlock() const {
		_mutex.unlock();
	}
	void lock_shared() const {
		_mutex.lock_shared();
	}
	void unlock_shared() const {
		_mutex.unlock_shared();
	}

	std::shared_mutex& get_mutex() const {
		return _mutex;
	}

	std::unique_lock<std::shared_mutex> get_unique_lock() const {
		return std::unique_lock<std::shared_mutex>(_mutex);
	}
	std::shared_lock<std::shared_mutex> get_shared_lock() const {
		return std::shared_lock<std::shared_mutex>(_mutex);
	}
};


STAMP_CORE_NAMESPACE_END

#endif