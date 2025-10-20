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
struct stamp_ptr_internal_counter {
	std::shared_mutex accessMutex{};
	Stamp_Deleter<T> deleter;
	std::atomic_int readCount = 0;
	std::atomic_int refrenceCount = 0;
};

template <typename T>
class stamp_ptr_internal final {
public:
	stamp_ptr_internal_counter<T>* counter = nullptr;
	T* ptr = nullptr;

	stamp_ptr_internal(T* ptr, Stamp_Deleter<T> deleter = Deleter) {
		this->ptr = ptr;
		counter = new stamp_ptr_internal_counter<T>();
		this->counter->deleter = deleter;
	}
	stamp_ptr_internal() {}

	static inline void Deleter(stamp_ptr_internal<T>* ptri) {
		if (ptri->ptr) {
			delete ptri->ptr;
			ptri->ptr = 0;
		}
		delete ptri;
	}
};

//pointer manager - deletes pointer, access read and write


//writable pointer - noncopyable, can read or write, but locks all other access
//readonly pointer - noncopyable, only blocks write access

template <typename T>
class readonly_ptr final : INonCopyable, INonAddressable {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
private:
	stamp_ptr_internal<T>* ptri = nullptr;

	readonly_ptr(stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptri = ptri;
		this->ptri->counter->accessMutex.lock_shared();
		this->ptri->counter->readCount++;
	}
public:
	readonly_ptr(nullptr_t) {
		this->ptri = nullptr;
	}

	readonly_ptr(const readonly_ptr<T>&) = delete;
	readonly_ptr(readonly_ptr<T>&&) = delete;

	readonly_ptr& operator=(nullptr_t) {
		if (!ptri) return;
		this->ptri->counter->accessMutex.unlock_shared();
		this->ptri->counter->readCount--;

		this->ptri = nullptr;
	}
	readonly_ptr& operator=(const readonly_ptr<T>&) = delete;
	readonly_ptr& operator=(readonly_ptr<T>&&) = delete;

	int readCount() const noexcept {
		if (!ptri) return 0;
		return ptri->counter->readCount;
	}

	bool operator==(nullptr_t) const noexcept {
		return ptri == nullptr || ptri->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const readonly_ptr<T>& v) const noexcept {
		return ptri == v.ptri || (ptri && v.ptri && ptri->ptr == v.ptri->ptr);
	}
	bool operator!=(const readonly_ptr<T>& v) const noexcept {
		return !(*this == v);
	}

	const element_type& operator *() const noexcept {
		return *(ptri->ptr);
	}
	const element_type* operator ->() const noexcept {
		return ptri->ptr;
	}
	const element_type& operator [](std::ptrdiff_t index) const noexcept {
		return ptri->ptr[index];
	}
	const element_type* get() const noexcept {
		return ptri->ptr;
	}
	operator bool() const noexcept {
		return ptri != nullptr && ptri->ptr != nullptr;
	}

	~readonly_ptr() {
		if (!ptri) return;
		this->ptri->counter->readCount--;
		this->ptri->counter->accessMutex.unlock_shared();
		this->ptri = nullptr;
	}
};

template <typename T>
class writable_ptr final : INonCopyable, INonAddressable {
	template<typename T>
	friend class threadsafe_ptr;
public:
	using element_type = T;
private:
	stamp_ptr_internal<T>* ptri = nullptr;

	writable_ptr(stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptri = ptri;
		this->ptri->counter->accessMutex.lock();
	}
public:
	writable_ptr(nullptr_t) {
		this->ptri = nullptr;
	}
	writable_ptr(const writable_ptr<T>&) = delete;
	writable_ptr(writable_ptr<T>&&) = delete;
	writable_ptr& operator=(nullptr_t) {
		if (!ptri) return;
		this->ptri->counter->accessMutex.unlock();
		
		this->ptri = nullptr;
	}
	writable_ptr& operator=(const writable_ptr<T>&) = delete;
	writable_ptr& operator=(writable_ptr<T>&&) = delete;

	bool operator==(nullptr_t) const noexcept {
		return ptri == nullptr || ptri->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const writable_ptr<T>& v) const noexcept {
		return ptri == v.ptri || (ptri && v.ptri && ptri->ptr == v.ptri->ptr);
	}
	bool operator!=(const writable_ptr<T>& v) const noexcept {
		return !(*this == v);
	}

	element_type& operator *() const noexcept {
		return *(ptri->ptr);
	}
	element_type* operator ->() const noexcept {
		return ptri->ptr;
	}
	element_type& operator [](std::ptrdiff_t index) const noexcept {
		return ptri->ptr[index];
	}
	element_type* get() const noexcept {
		return ptri->ptr;
	}
	operator bool() const noexcept {
		return ptri != nullptr && ptri->ptr != nullptr;
	}

	~writable_ptr() {
		if (!ptri) return;
		this->ptri->counter->accessMutex.unlock();
	}
};

template<typename T>
class threadsafe_ptr final : INonAddressable {
public:
	template<typename T, typename... Args>
	friend threadsafe_ptr<T> make_threadsafe(Args&&... args);
	template<typename T>
	friend class enable_threadsafe_from_this;

	using element_type = T;
private:

	stamp_ptr_internal<T>* ptri = nullptr;
	threadsafe_ptr(stamp_ptr_internal<T>* ptri) {
		this->ptri = ptri;
		if (ptri == nullptr) return;
		ptri->counter->refrenceCount++;
	}
	
	template<typename... Args>
	static void construct_at(void* p, Args... args) {
		new (p) T(std::forward<Args>(args)...);
	}
public:
	threadsafe_ptr() {
		ptri = nullptr;
	}
	threadsafe_ptr(element_type* ptr) {
		if (ptr == nullptr) return;
		if constexpr (std::is_base_of_v<enable_threadsafe_from_this<T>, T>) {
			if(ptr->ptri) {
				ptri = ptr->ptri;
				ptri->counter->refrenceCount++;
			}
			else {
				ptri = new stamp_ptr_internal<T>(ptr);
				ptri->counter->refrenceCount++;
				ptr->ptri = ptri;
			}
		}
		else {
			ptri = new stamp_ptr_internal<T>(ptr);
			ptri->counter->refrenceCount++;
		}
	}
	threadsafe_ptr(nullptr_t) {
		ptri = nullptr;
	}

	threadsafe_ptr(const threadsafe_ptr<T>& v) noexcept {
		ptri = v.ptri;
		if (ptri == nullptr) return;
		ptri->counter->refrenceCount++;
	}
	threadsafe_ptr(threadsafe_ptr<T>&& v) noexcept = default;

	threadsafe_ptr<T>& operator=(const threadsafe_ptr<T>& v) noexcept {
		if (this == &v) return *this;
		if (ptri == v.ptri) return *this;

		if (ptri) {
			ptri->counter->refrenceCount--;
			if (ptri->counter->refrenceCount == 0) {

				auto p = ptri;
				p->counter->accessMutex.lock();
				ptri = nullptr;
				p->counter->accessMutex.unlock();

				ptri->deleter(ptri);
			}
		}

		ptri = v.ptri;
		if (ptri == nullptr) return *this;
		ptri->counter->refrenceCount++;

		return *this;
	}
	threadsafe_ptr<T>& operator=(threadsafe_ptr<T>&& v) noexcept = default;

	bool operator==(nullptr_t) const noexcept {
		return ptri == nullptr || ptri->ptr == nullptr;
	}
	bool operator!=(nullptr_t) const noexcept {
		return !(*this == nullptr);
	}
	bool operator==(const threadsafe_ptr<T>& v) const noexcept {
		return ptri == v.ptri || (ptri && v.ptri && ptri->ptr == v.ptri->ptr);
	}
	bool operator!=(const threadsafe_ptr<T>& v) const noexcept {
		return !(*this == v);
	}
	explicit operator bool() const noexcept {
		return ptri != nullptr && ptri->ptr != nullptr;
	}
	template<typename T1>
	explicit operator threadsafe_ptr<T1>() const noexcept {
		if (!ptri) return threadsafe_ptr<T1>(nullptr);
		threadsafe_ptr<T1> v(new stamp_ptr_internal<T>());
		v.ptri->counter = ptri->counter;
		v.ptri->ptr = staic_cast<T1*>(ptri->ptr);
	}
	int use_count() {
		return ptri->counter->refrenceCount;
	}
	bool unique() {
		return ptri->counter->refrenceCount == 1;
	}
	readonly_ptr<T> get_readonly() const {
		return readonly_ptr<T>(ptri);
	}
	writable_ptr<T> get() requires !std::is_const_v<T> {
		return writable_ptr<T>(ptri);
	}

	~threadsafe_ptr() {
		if (!ptri) return;
		if (--ptri->counter->refrenceCount > 0) return;

		auto p = ptri;
		p->counter->accessMutex.lock();
		ptri = nullptr;
		p->counter->accessMutex.unlock();

		p->counter->deleter(p);
	}
};

template<typename T, typename... Args>
threadsafe_ptr<T> make_threadsafe(Args&&... args) {
	struct MAKE_THREADSAFE {
		stamp_ptr_internal<T> ptri;
		T value;
	};

	Stamp_Deleter<T> deleter = [](stamp_ptr_internal<T>* ptri) {
		ptri->ptr->~T();
		ptri->~stamp_ptr_internal();
		::operator delete(ptri, sizeof(MAKE_THREADSAFE), std::align_val_t{ alignof(MAKE_THREADSAFE) });
	};

	MAKE_THREADSAFE* mem = 0;
	mem = (MAKE_THREADSAFE*)::operator new(sizeof(MAKE_THREADSAFE), std::align_val_t{ alignof(MAKE_THREADSAFE) });
	threadsafe_ptr<T>::construct_at(&(mem->value), std::forward<Args>(args)...);
	new (&(mem->ptri)) stamp_ptr_internal<T>(&(mem->value), deleter);

	if constexpr (std::is_base_of_v<enable_threadsafe_from_this<T>, T>) {
		mem->value.ptri = &(mem->ptri);
	}

	return threadsafe_ptr<T>(&(mem->ptri));
}

template<typename T>
class enable_threadsafe_from_this {
	template<typename U, typename... Args>
	friend threadsafe_ptr<U> make_threadsafe(Args&&... args);
	template<typename U>
	friend class threadsafe_ptr;
	
	stamp_ptr_internal<T>* ptri = nullptr;
protected:
	enable_threadsafe_from_this() {}
public:

	threadsafe_ptr<T> threadsafe_from_this() {
		return threadsafe_ptr<T>(ptri);
	}
};

STAMP_NAMESPACE_END

#endif