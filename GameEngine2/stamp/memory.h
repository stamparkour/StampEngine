//stamp/memory.h

#pragma once
#ifndef STAMP_MEMORY_H
#define STAMP_MEMORY_H

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

#include <stamp/define.h>
#include <stamp/noncopyable.h>

#ifdef STAMP_DEBUG
#define STAMP_MEMORY_DEBUG
#endif

#define STAMP_MEMORY_THREADSAFE_FRIEND template<typename T, typename... Args> friend stamp::threadsafe_ptr<T> stamp::make_threadsafe(Args&&... args)

STAMP_NAMESPACE_BEGIN

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
class readonly_ptr : STAMP_NAMESPACE::INonCopyable, STAMP_NAMESPACE::INonAddressable {
	template<typename T>
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
		return *(ptr->ptr);
	}
	const T* operator->() const {
		return ptr->ptr;
	}
	const T& operator[](size_t index) const {
		return ptr->ptr[index];
	}
	explicit operator const T* () const {
		return get();
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
		if (locked) return;
		locked = false;
		ptr->mutex.unlock_shared();
	}
};

template<typename T>
class writable_ptr {
	template<typename T>
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
		return *(ptr->ptr);
	}
	const T& operator*() const {
		return *(ptr->ptr);
	}
	T* operator->() {
		return ptr->ptr;
	}
	const T* operator->() const {
		return ptr->ptr;
	}
	T& operator[](size_t index) {
		return ptr->ptr[index];
	}
	const T& operator[](size_t index) const {
		return ptr->ptr[index];
	}
	explicit operator T* () {
		return get();
	}
	explicit operator const T* () const {
		return get();
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
		if (locked) return;
		locked = false;
		ptr->mutex.unlock();
	}
};

template<typename T>
class threadsafe_ptr {
public:
	using element_type = T;
	using ptr_type = threadsafe_control<element_type>;

	template<typename T, typename... Args>
	friend threadsafe_ptr<T> make_threadsafe(Args&&... args);
	template<typename T>
	friend class enable_threadsafe_from_this;
	template<typename T>
	friend class weak_threadsafe_ptr;

	using weak_type = weak_threadsafe_ptr<element_type>;
	using read_type = readonly_ptr<element_type>;
	using write_type = writable_ptr<element_type>;
private:
	std::atomic<std::shared_ptr<ptr_type>> ptr;

	threadsafe_ptr(const std::atomic<std::shared_ptr<ptr_type>>& other) {
		ptr = other.load();
	}
public:
	threadsafe_ptr() : ptr{ nullptr } {}
	threadsafe_ptr(nullptr_t) : ptr{ nullptr } {}
	threadsafe_ptr(T* v) {
		ptr = { std::shared_ptr<ptr_type>(v == nullptr ? nullptr : new ptr_type(v)) };
	}
	threadsafe_ptr(const weak_threadsafe_ptr<T>& other) {
		ptr = other.ptr.load().lock();
	}
	threadsafe_ptr& operator=(nullptr_t) {
		ptr = nullptr;
		return *this;
	}
	threadsafe_ptr& operator=(T* v) {
		ptr = { std::shared_ptr<ptr_type>(new ptr_type(v)) };
		return *this;
	}
	threadsafe_ptr& operator=(const weak_threadsafe_ptr<T>& other) {
		ptr = other.ptr.load().lock();
		return *this;
	}

	threadsafe_ptr(const threadsafe_ptr& other) {
		ptr = other.ptr.load();
	}
	threadsafe_ptr(threadsafe_ptr&& other) {
		ptr = other.ptr.load();
	}
	threadsafe_ptr& operator=(const threadsafe_ptr& other) {
		ptr = other.ptr.load();
		return *this;
	}
	threadsafe_ptr& operator=(threadsafe_ptr&& other) {
		ptr = other.ptr.load();
		return *this;
	}
	~threadsafe_ptr() = default;

	bool operator ==(nullptr_t) const {
		return ptr.load() == nullptr;
	}
	bool operator !=(nullptr_t) const {
		return ptr.load() != nullptr;
	}
	bool operator ==(const threadsafe_ptr& other) const {
		return ptr.load() == other.ptr.load();
	}
	bool operator !=(const threadsafe_ptr& other) const {
		return ptr.load() != other.ptr.load();
	}
	explicit operator bool() const {
		return ptr.load() != nullptr;
	}
	bool operator !() const {
		return ptr.load() == nullptr;
	}
	size_t use_count() const {
		auto p = ptr.load();
		if (p == nullptr) return 0;
		return p.use_count();
	}
	bool unique() const {
		return use_count() == 1;
	}
	void reset() {
		ptr = nullptr;
	}
	write_type get() {
		return write_type(ptr.load(), true);
	}
	write_type get_unsafe() {
		return write_type(ptr.load(), false);
	}
	read_type get_readonly() const {
		return read_type(ptr.load(), true);
	}
	read_type get_readonly_unsafe() const {
		return read_type(ptr.load(), false);
	}
};

template<typename T>
class weak_threadsafe_ptr {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
	using strong_type = threadsafe_ptr<T>;
private:
	using ptr_type = threadsafe_control<T>;
	std::atomic<std::weak_ptr<ptr_type>> ptr;

	weak_threadsafe_ptr(const std::atomic<std::weak_ptr<ptr_type>>& other) {
		ptr = other.load();
	}
public:
	weak_threadsafe_ptr() : ptr{ nullptr } {}
	weak_threadsafe_ptr(nullptr_t) : ptr{ nullptr } {}
	weak_threadsafe_ptr(const strong_type& other) {
		ptr = other.ptr.load();
	}
	weak_threadsafe_ptr& operator=(nullptr_t) {
		ptr = nullptr;
		return *this;
	}
	weak_threadsafe_ptr& operator=(const strong_type& other) {
		ptr = other.ptr.load();
		return *this;
	}

	weak_threadsafe_ptr(const weak_threadsafe_ptr& other) {
		ptr = other.ptr.load();
	}
	weak_threadsafe_ptr(weak_threadsafe_ptr&& other) {
		ptr = other.ptr.load();
	}
	weak_threadsafe_ptr& operator=(const weak_threadsafe_ptr& other) {
		ptr = other.ptr.load();
		return *this;
	}
	weak_threadsafe_ptr& operator=(weak_threadsafe_ptr&& other) {
		ptr = other.ptr.load();
		return *this;
	}
	~weak_threadsafe_ptr() = default;

	size_t use_count() const {
		auto p = ptr.load();
		if (p == nullptr) return 0;
		return p.use_count();
	}
	bool expired() const {
		auto p = ptr.load();
		return p.expired();
	}
	void reset() {
		ptr = nullptr;
	}
	strong_type lock() const {
		return strong_type(ptr.load().lock());
	}
};

template<typename T, typename... Args>
inline threadsafe_ptr<T> make_threadsafe(Args&&... args) {
	//could be optimized
	return threadsafe_ptr<T>(std::make_shared<threadsafe_control<T>>(new T(std::forward<Args>(args)...)));
}

template<typename U, typename V>
inline threadsafe_ptr<U> static_pointer_cast(const threadsafe_ptr<V>& other) {
	return threadsafe_ptr<U>(std::static_pointer_cast<threadsafe_ptr<U>::ptr_type>(other.ptr.load()));
}
template<typename U, typename V>
inline threadsafe_ptr<U> dynamic_pointer_cast(const threadsafe_ptr<V>& other) {
	return threadsafe_ptr<U>(std::dynamic_pointer_cast<threadsafe_ptr<U>::ptr_type>(other.ptr.load()));
}


template<typename T>
class enable_threadsafe_from_this : private std::enable_shared_from_this<threadsafe_control<T>> {
	using base_type = std::enable_shared_from_this<threadsafe_control<T>>;
protected:
	enable_threadsafe_from_this() {}
public:
	threadsafe_ptr<T> threadsafe_from_this() {
		return threadsafe_ptr<T>(base_type::shared_from_this());
	}
};

template<typename T, typename Base>
class enable_threadsafe_from_this_derived {
protected:
	enable_threadsafe_from_this_derived() {}
public:

	threadsafe_ptr<T> threadsafe_from_this() {
		return static_pointer_cast<T>(Base::threadsafe_from_this());
	}
};

template<typename T>
class lockable : public T {
private:
	mutable std::mutex _mutex;
public:

	template <typename... Args>
	lockable(Args&&... args) : T(std::forward<Args>(args)...) {}

	void lock() const {
		_mutex.lock();
	}
	void unlock() const {
		_mutex.unlock();
	}
	std::mutex& get_mutex() const {
		return _mutex;
	}
};

STAMP_NAMESPACE_END

#endif