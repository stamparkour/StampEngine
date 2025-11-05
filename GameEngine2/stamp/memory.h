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
using tsp = threadsafe_ptr<T>;

template <typename T>
class stamp_ptr_internal;

template<typename T>
using Stamp_Deleter = void(*)(stamp_ptr_internal<T>*);

template <typename T>
struct stamp_ptr_internal_control {
	std::shared_mutex accessMutex{};
	Stamp_Deleter<T> strongDeleter;
	Stamp_Deleter<T> weakDeleter;
	std::atomic_int readCount = 0;
	std::atomic_int strongReferenceCount = 0;
	std::atomic_int weakReferenceCount = 0;

	stamp_ptr_internal_control(Stamp_Deleter<T> strongDel, Stamp_Deleter<T> weakDel) : strongDeleter(strongDel), weakDeleter(weakDel) { }

};

template <typename T>
class stamp_ptr_internal {
public:
	stamp_ptr_internal_control<T>* control = nullptr;
	T* ptr = nullptr;

	stamp_ptr_internal() {}

	static inline void StrongDeleter(stamp_ptr_internal<T>* ptri) {
		if (ptri->ptr) {
			delete ptri->ptr;
			ptri->ptr = 0;
		}
	}

	static inline void WeakDeleter(stamp_ptr_internal<T>* ptri) {
		delete ptri->control;
	}
};

//pointer manager - deletes pointer, access read and write


//writable pointer - noncopyable, can read or write, but locks all other access
//readonly pointer - noncopyable, only blocks write access

template <typename T>
class readonly_ptr final : stamp_ptr_internal<T>, INonCopyable, INonAddressable {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
private:

	readonly_ptr(const stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptr = ptri->ptr;
		this->control = ptri->control;
		this->control->accessMutex.lock_shared();
		this->control->readCount++;
	}
public:
	readonly_ptr(nullptr_t) {
		this->ptr = nullptr;
		this->control = nullptr;
	}
	readonly_ptr& operator=(nullptr_t) {
		if (!this->control) return;
		this->control->readCount--;
		auto c = this->control;
		this->control = nullptr;
		this->ptr = nullptr;
		c->accessMutex.unlock_shared();
	}

	int readCount() const noexcept {
		if (!this->control) return 0;
		return this->control->readCount;
	}

	bool operator==(nullptr_t) const noexcept {
		return this->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const readonly_ptr<T>& v) const noexcept {
		return this->ptr == v.ptr;
	}
	bool operator!=(const readonly_ptr<T>& v) const noexcept {
		return !(*this == v);
	}

	const element_type& operator *() const noexcept {
		return *this->ptr;
	}
	const element_type* operator ->() const noexcept {
		return this->ptr;
	}
	const element_type& operator [](std::ptrdiff_t index) const noexcept {
		return this->ptr[index];
	}
	const element_type* get() const noexcept {
		return this->ptr;
	}
	operator bool() const noexcept {
		return this->ptr != nullptr;
	}

	~readonly_ptr() {
		if (!this->control) return;
		this->control->readCount--;
		auto c = this->control;
		this->ptr = nullptr;
		this->control = nullptr;
		c->accessMutex.unlock_shared();
	}
};

template <typename T>
class unsafe_readonly_ptr final : stamp_ptr_internal<T>, INonCopyable, INonAddressable {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
private:

	unsafe_readonly_ptr(const stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptr = ptri->ptr;
		this->control = ptri->control;
		this->control->readCount++;
	}
public:
	unsafe_readonly_ptr(nullptr_t) {
		this->ptr = nullptr;
		this->control = nullptr;
	}
	unsafe_readonly_ptr& operator=(nullptr_t) {
		if (!this->control) return;
		this->control->readCount--;

		this->control = nullptr;
		this->ptr = nullptr;
	}

	int readCount() const noexcept {
		if (!this->control) return 0;
		return this->control->readCount;
	}

	bool operator==(nullptr_t) const noexcept {
		return this->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const unsafe_readonly_ptr<T>& v) const noexcept {
		return this->ptr == v.ptr;
	}
	bool operator!=(const unsafe_readonly_ptr<T>& v) const noexcept {
		return !(*this == v);
	}

	const element_type& operator *() const noexcept {
		return *(this->ptr);
	}
	const element_type* operator ->() const noexcept {
		return this->ptr;
	}
	const element_type& operator [](std::ptrdiff_t index) const noexcept {
		return this->ptr[index];
	}
	const element_type* get() const noexcept {
		return this->ptr;
	}
	operator bool() const noexcept {
		return this->ptr != nullptr;
	}

	~unsafe_readonly_ptr() {
		if (!this->control) return;
		this->control->readCount--;
		auto c = this->control;
		this->ptr = nullptr;
		this->control = nullptr;
	}
};

template <typename T>
class writable_ptr final : stamp_ptr_internal<T>, INonCopyable, INonAddressable {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
private:
	writable_ptr(const stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptr = ptri->ptr;
		this->control = ptri->control;
		this->control->accessMutex.lock();
	}
public:
	writable_ptr(nullptr_t) {
		this->ptr = nullptr;
		this->control = nullptr;
	}
	writable_ptr& operator=(nullptr_t) {
		if (!this->control) return;
		auto c = this->control;
		this->ptr = nullptr;
		this->control = nullptr;
		c->accessMutex.unlock();
		
	}

	bool operator==(nullptr_t) const noexcept {
		return this->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const writable_ptr<T>& v) const noexcept {
		return this->ptr == v.ptr;
	}
	bool operator!=(const writable_ptr<T>& v) const noexcept {
		return !(*this == v);
	}

	element_type& operator *() noexcept {
		return *this->ptr;
	}
	element_type* operator ->() noexcept {
		return this->ptr;
	}
	element_type& operator [](std::ptrdiff_t index) noexcept {
		return this->ptr[index];
	}
	element_type* get() noexcept {
		return this->ptr;
	}
	operator bool() const noexcept {
		return this->ptr != nullptr;
	}

	~writable_ptr() {
		if (!this->control) return;
		auto c = this->control;
		this->ptr = nullptr;
		this->control = nullptr;
		c->accessMutex.unlock();
	}
};

template <typename T>
class unsafe_writable_ptr final : stamp_ptr_internal<T>, INonCopyable, INonAddressable {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
private:
	unsafe_writable_ptr(const stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptr = ptri->ptr;
		this->control = ptri->control;
	}
public:
	unsafe_writable_ptr(nullptr_t) {
		this->ptr = nullptr;
		this->control = nullptr;
	}
	unsafe_writable_ptr& operator=(nullptr_t) {
		if (!this->control) return;
		auto c = this->control;
		this->ptr = nullptr;
		this->control = nullptr;
	}

	bool operator==(nullptr_t) const noexcept {
		return this->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const unsafe_writable_ptr<T>& v) const noexcept {
		return this->ptr == v.ptr;
	}
	bool operator!=(const unsafe_writable_ptr<T>& v) const noexcept {
		return !(*this == v);
	}

	element_type& operator *() noexcept {
		return *this->ptr;
	}
	element_type* operator ->() noexcept {
		return this->ptr;
	}
	element_type& operator [](std::ptrdiff_t index) noexcept {
		return this->ptr[index];
	}
	element_type* get() noexcept {
		return this->ptr;
	}
	operator bool() const noexcept {
		return this->ptr != nullptr;
	}

	~unsafe_writable_ptr() {
		if (!this->control) return;
		auto c = this->control;
		this->ptr = nullptr;
		this->control = nullptr;
	}
};

template<typename T>
class threadsafe_ptr final : stamp_ptr_internal<T>, INonAddressable {
public:
	using element_type = T;

	template<typename T, typename... Args>
	friend threadsafe_ptr<T> make_threadsafe(Args&&... args);
	template<typename T>
	friend class enable_threadsafe_from_this;
	template<typename T>
	friend class weak_threadsafe_ptr;
	template<typename T1, typename T2>
	friend threadsafe_ptr<T1> static_pointer_cast(const threadsafe_ptr<T2>& sp) noexcept;
	template<typename T1, typename T2>
	friend threadsafe_ptr<T1> dynamic_pointer_cast(const threadsafe_ptr<T2>& sp) noexcept;
private:
	threadsafe_ptr(T* ptr, stamp_ptr_internal_control<T>* control) {
		if (ptr == nullptr || control == nullptr) return;
		this->ptr = ptr;
		this->control = control;
		this->control->strongReferenceCount++;
	}

	void decrementReference() {
		if (this->control == nullptr) return;
		//is last reference
		if (--this->control->strongReferenceCount != 0) return;

		this->control->accessMutex.lock();
		this->control->strongDeleter(this);
		this->ptr = nullptr;
		this->control->accessMutex.unlock();

		if (this->control->weakReferenceCount != 0) return;

		this->control->weakDeleter(this);
		this->control = nullptr;
	}

	void setPtr(element_type* ptr) {
		if (ptr == nullptr) {
			this->ptr = nullptr;
			this->control = nullptr;
			return;
		}

		this->ptr = ptr;

		if constexpr (requires { this->ptr->value.stampThreadsafePtrControlPointer; }) {
			if (this->ptr->stampThreadsafePtrControlPointer == nullptr) {
				this->control = new stamp_ptr_internal_control<T>(stamp_ptr_internal<T>::StrongDeleter, stamp_ptr_internal<T>::WeakDeleter);

				this->ptr->stampThreadsafePtrControlPointer = this->control;
			}
			else {
				this->control = this->ptr->stampThreadsafePtrControlPointer;
			}
		}
		else {
			this->control = new stamp_ptr_internal_control<T>(stamp_ptr_internal<T>::StrongDeleter, stamp_ptr_internal<T>::WeakDeleter);
		}
		this->control->strongReferenceCount++;
	}
public:
	threadsafe_ptr() {}
	threadsafe_ptr(nullptr_t) {}

	threadsafe_ptr(element_type* ptr) {
		setPtr(ptr);
	}

	threadsafe_ptr(const threadsafe_ptr<T>& v) noexcept {
		this->ptr = v.ptr;
		this->control = v.control;
	}
	threadsafe_ptr(threadsafe_ptr<T>&& v) noexcept {
		this->ptr = v.ptr;
		v.ptr = nullptr;
		this->control = v.control;
		v.control = nullptr;
	}

	threadsafe_ptr<T>& operator=(nullptr_t) noexcept {
		decrementReference();
		this->ptr = nullptr;
		this->control = nullptr;
		return *this;
	}
	threadsafe_ptr<T>& operator=(element_type* ptr) noexcept {
		decrementReference();
		setPtr(ptr);

		return *this;
	}
	threadsafe_ptr<T>& operator=(const threadsafe_ptr<T>& v) noexcept {
		if (this == &v) return *this;
		if (this->ptr == v.ptr) return *this;
		decrementReference();
		setPtr(v.ptr, v.control);
		return *this;
	}
	threadsafe_ptr<T>& operator=(threadsafe_ptr<T>&& v) noexcept {
		using std::swap;
		swap(this->ptr, v.ptr);
		swap(this->control, v.control);
		return *this;
	}

	bool operator==(nullptr_t) const noexcept {
		return this->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const threadsafe_ptr<T>& v) const noexcept {
		return this->ptr == v.ptr;
	}
	bool operator!=(const threadsafe_ptr<T>& v) const noexcept {
		return !(*this == v);
	}
	explicit operator bool() const noexcept {
		return this->ptr != nullptr;
	}

	int use_count() const {
		if (this->control == nullptr) return 0;
		return this->control->strongReferenceCount;
	}
	bool unique() const {
		if (this->control == nullptr) return false;
		return this->control->strongReferenceCount == 1;
	}
	readonly_ptr<T> get_readonly() const {
		return readonly_ptr<T>(this);
	}
	unsafe_readonly_ptr<T> get_readonly_unsafe() const {
		return unsafe_readonly_ptr<T>(this);
	}
	writable_ptr<T> get() requires !std::is_const_v<T> {
		return writable_ptr<T>(this);
	}
	unsafe_writable_ptr<T> get_unsafe() requires !std::is_const_v<T> {
		return unsafe_writable_ptr<T>(this);
	}

	void reset() noexcept {
		decrementReference();
		this->ptr = nullptr;
		this->control = nullptr;
	}

	~threadsafe_ptr() {
		decrementReference();
	}
};

template<typename T>
class weak_threadsafe_ptr final : stamp_ptr_internal<T>, INonAddressable {
public:
	using element_type = T;

	template<typename T, typename... Args>
	friend threadsafe_ptr<T> make_threadsafe(Args&&... args);
	template<typename T>
	friend class enable_threadsafe_from_this;
	template<typename T1, typename T2>
	friend weak_threadsafe_ptr<T1> static_pointer_cast(const weak_threadsafe_ptr<T2>& sp)  noexcept;
	template<typename T1, typename T2>
	friend weak_threadsafe_ptr<T1> dynamic_pointer_cast(const weak_threadsafe_ptr<T2>& sp)  noexcept;
private:
	weak_threadsafe_ptr(T* ptr, stamp_ptr_internal_control<T>* control) {
		if (ptr == nullptr || control == nullptr) return;
		this->control = control;
		this->ptr = ptr;
		this->control->weakReferenceCount++;
	}

	void decrementReference() {
		if (this->control == nullptr) return;
		//is last reference
		if (--this->control->weakReferenceCount != 0) return;
		if (this->control->strongReferenceCount != 0) return;

		this->control->weakDeleter(this);
		this->control = nullptr;
	}
public:
	weak_threadsafe_ptr() {}
	weak_threadsafe_ptr(nullptr_t) {}

	weak_threadsafe_ptr(const weak_threadsafe_ptr<T>& v) noexcept {
		this->ptr = v.ptr;
		this->control = v.control;
	}
	weak_threadsafe_ptr(weak_threadsafe_ptr<T>&& v) noexcept {
		this->ptr = v.ptr;
		this->control = v.control;
		v.ptr = nullptr;
		v.control = nullptr;
	}
	weak_threadsafe_ptr(const threadsafe_ptr<T>& v) noexcept {
		this->ptr = v.ptr;
		this->control = v.control;
		if (this->control != nullptr) this->control->weakReferenceCount++;
	}

	weak_threadsafe_ptr<T>& operator=(const weak_threadsafe_ptr<T>& v) noexcept {
		if (this == &v) return *this;
		if (this->ptr == v.ptr) return *this;
		decrementReference();
		this->ptr = v.ptr;
		this->control = v.control;
		return *this;
	}
	weak_threadsafe_ptr<T>& operator=(weak_threadsafe_ptr<T>&& v) noexcept {
		if (this == &v) return *this;
		if (this->ptr == v.ptr) return *this;

		using std::swap;
		swap(this->ptr, v.ptr);
		swap(this->control, v.control);
		return *this;
	}
	weak_threadsafe_ptr<T>& operator=(const threadsafe_ptr<T>& v) noexcept {
		decrementReference();
		this->ptr = v.ptr;
		this->control = v.control;
		if (this->control != nullptr) this->control->weakReferenceCount++;
		return *this;
	}

	bool operator==(nullptr_t) const noexcept {
		return this->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const threadsafe_ptr<T>& v) const noexcept {
		return this->ptr == v.ptr;
	}
	bool operator!=(const threadsafe_ptr<T>& v) const noexcept {
		return !(*this == v);
	}
	explicit operator bool() const noexcept {
		return !expired();
	}

	int use_count() const {
		if (this->control == nullptr) return 0;
		return this->control->strongReferenceCount;
	}
	bool expired() const {
		if (this->control == nullptr) return true;
		return this->control->strongReferenceCount == 0;
	}
	threadsafe_ptr<T> lock() const {
		return threadsafe_ptr<T>(this->ptr, this->control);
	}

	void reset() noexcept {
		decrementReference();
		this->ptr = nullptr;
		this->control = nullptr;
	}

	~weak_threadsafe_ptr() {
		decrementReference();
	}
};

template<typename T, typename... Args>
threadsafe_ptr<T> make_threadsafe(Args&&... args) {
	struct MAKE_THREADSAFE {
		stamp_ptr_internal_control<T> control;
		T value;
	};

	Stamp_Deleter<T> strongDeleter = [](stamp_ptr_internal<T>* ptri) {
		ptri->ptr->~T();
	};
	Stamp_Deleter<T> weakDeleter = [](stamp_ptr_internal<T>* ptri) {
		ptri->control->~stamp_ptr_internal_control<T>();
		::operator delete(ptri->control, sizeof(MAKE_THREADSAFE), std::align_val_t{ alignof(MAKE_THREADSAFE) });
	};

	MAKE_THREADSAFE* mem = 0;
	mem = (MAKE_THREADSAFE*)::operator new(sizeof(MAKE_THREADSAFE), std::align_val_t{ alignof(MAKE_THREADSAFE) });
	new (&(mem->value)) T((std::forward<Args>(args))...);
	new (&(mem->control)) stamp_ptr_internal_control<T>(strongDeleter, weakDeleter);

	if constexpr (requires { mem->value.stampThreadsafePtrControlPointer; }) {
		mem->value.stampThreadsafePtrControlPointer = &(mem->control);
	}

	return threadsafe_ptr<T>(&(mem->value), &(mem->control));
}

template<typename T1, typename T2>
threadsafe_ptr<T1> static_pointer_cast(const threadsafe_ptr<T2>& sp) noexcept {
	if (!sp) return threadsafe_ptr<T1>(nullptr);
	return threadsafe_ptr<T1>(static_cast<T1*>(sp.ptr), (stamp_ptr_internal_control<T1>*)(void*)sp.control);
}
template<typename T1, typename T2>
threadsafe_ptr<T1> dynamic_pointer_cast(const threadsafe_ptr<T2>& sp) noexcept {
	if (!sp) return threadsafe_ptr<T1>(nullptr);
	return threadsafe_ptr<T1>(dynamic_cast<T1*>(sp.ptr), (stamp_ptr_internal_control<T1>*)(void*)sp.control);
}

template<typename T1, typename T2>
weak_threadsafe_ptr<T1> static_pointer_cast(const weak_threadsafe_ptr<T2>& sp) noexcept {
	if (!sp) return threadsafe_ptr<T1>(nullptr);
	return threadsafe_ptr<T1>(static_cast<T1*>(sp.ptr), (stamp_ptr_internal_control<T1>*)(void*)sp.control);
}
template<typename T1, typename T2>
weak_threadsafe_ptr<T1> dynamic_pointer_cast(const weak_threadsafe_ptr<T2>& sp) noexcept {
	if (!sp) return threadsafe_ptr<T1>(nullptr);
	return threadsafe_ptr<T1>(dynamic_cast<T1*>(sp.ptr), (stamp_ptr_internal_control<T1>*)(void*)sp.control);
}


template<typename T>
class enable_threadsafe_from_this {
	template<typename U, typename... Args>
	friend threadsafe_ptr<U> make_threadsafe<U, Args...>(Args&&... args);
	friend class threadsafe_ptr<T>;
	friend class weak_threadsafe_ptr<T>;

	stamp_ptr_internal_control<T>* stampThreadsafePtrControlPointer = nullptr;
protected:
	enable_threadsafe_from_this() {}
public:

	threadsafe_ptr<T> threadsafe_from_this() {
		return threadsafe_ptr<T>((T*)this, stampThreadsafePtrControlPointer);
	}
};

STAMP_NAMESPACE_END

#endif