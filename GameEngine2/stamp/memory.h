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
class stamp_ptr_internal;

template<typename T>
using Stamp_Deleter = void(*)(stamp_ptr_internal<T>*);

template <typename T>
class stamp_ptr_internal final {
	std::atomic_int readCount = 0;
	std::condition_variable writeProtection{};
public:
	std::mutex accessMutex{};
	Stamp_Deleter<T> deleter;
	std::atomic_int refrenceCount = 0;
	T* ptr = nullptr;

	stamp_ptr_internal(T* ptr, Stamp_Deleter<T> deleter = Deleter) {
		this->ptr = ptr;
		this->deleter = deleter;
	}
	int ReadCount() {
		return readCount;
	}
	std::unique_lock<std::mutex> write_lock() {
		std::unique_lock lk(accessMutex);
		writeProtection.wait(lk, [this]() { return readCount == 0; });
		return lk;
	}
	void write_unlock(std::unique_lock<std::mutex>& lk) {
		lk.unlock();
		writeProtection.notify_all();
	}
	void read_lock() {
		std::unique_lock lk(accessMutex);
		readCount++;
	}
	void read_unlock() {
		//could notify either a read or write access
		if((--readCount) == 0) writeProtection.notify_all();
	}

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
		this->ptri->read_lock();
	}
public:
	readonly_ptr(nullptr_t) {
		this->ptri = nullptr;
	}
	readonly_ptr& operator=(nullptr_t) {
		if (!ptri) return;
		this->ptri->read_unlock();

		this->ptri = nullptr;
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
	int read_count() {
		return ptri->ReadCount();
	}
	operator bool() const noexcept {
		return ptri != nullptr && ptri->ptr != nullptr;
	}

	~readonly_ptr() {
		if (!ptri) return;
		this->ptri->read_unlock();
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
	std::unique_lock<std::mutex> lock;

	writable_ptr(stamp_ptr_internal<T>* ptri) {
		if (ptri == nullptr) return;
		this->ptri = ptri;
		lock = this->ptri->write_lock();

	}
public:
	writable_ptr(nullptr_t) {
		this->ptri = nullptr;
	}
	writable_ptr& operator=(nullptr_t) {
		if (!ptri) return;
		this->ptri->write_unlock(lock);
		
		this->ptri = nullptr;
	}

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
		this->ptri->write_unlock(lock);
	}
};

template<typename T>
class threadsafe_ptr final : INonAddressable {
public:
	template<typename T, typename... Args>
	friend threadsafe_ptr<T> make_threadsafe(Args&&... args);

	using element_type = T;
private:

	stamp_ptr_internal<T>* ptri = nullptr;
	threadsafe_ptr(stamp_ptr_internal<T>* ptri) {
		this->ptri = ptri;
		if (ptri == nullptr) return;
		ptri->refrenceCount++;
	}
public:
	threadsafe_ptr() {
		ptri = nullptr;
	}
	threadsafe_ptr(element_type* ptr) {
		if (ptr == nullptr) return;
		ptri = new stamp_ptr_internal<T>(ptr);
		ptri->refrenceCount++;
	}
	threadsafe_ptr(nullptr_t) {
		ptri = nullptr;
	}

	threadsafe_ptr(const threadsafe_ptr<T>& v) noexcept {
		ptri = v.ptri;
		if (ptri == nullptr) return;
		ptri->refrenceCount++;
	}
	threadsafe_ptr(threadsafe_ptr<T>&& v) noexcept = default;

	threadsafe_ptr<T>& operator=(const threadsafe_ptr<T>& v) noexcept {
		if (this == &v) return *this;
		if (ptri == v.ptri) return *this;

		if (ptri) {
			ptri->refrenceCount--;
			if (ptri->refrenceCount == 0) {
				ptri->read_lock();
				ptri->read_unlock();
				ptri->deleter(ptri);
				delete ptri;
				ptri = 0;
			}
		}

		ptri = v.ptri;
		if (ptri == nullptr) return *this;
		ptri->refrenceCount++;

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
	operator bool() const noexcept {
		return ptri != nullptr && ptri->ptr != nullptr;
	}

	int read_count() {
		return ptri->ReadCount();
	}
	int use_count() {
		return ptri->refrenceCount;
	}
	bool unique() {
		return ptri->refrenceCount == 1;
	}
	readonly_ptr<T> get_readonly() const {
		return readonly_ptr<T>(ptri);
	}
	writable_ptr<T> get_writable() {
		return writable_ptr<T>(ptri);
	}

	~threadsafe_ptr() {
		if (!ptri) return;
		if (--ptri->refrenceCount > 0) return;
		auto p = ptri;
		auto k = p->write_lock();
		ptri = nullptr;
		p->write_unlock(k);
		p->deleter(p);
	}
};

template<typename T, typename... Args>
threadsafe_ptr<T> make_threadsafe(Args&&... args) {
	struct MAKE_THREADSAFE {
		stamp_ptr_internal<T> ptri;
		T value;
	};

	Stamp_Deleter<T> deleter = [](stamp_ptr_internal<T>* ptri) {
		ptri->~stamp_ptr_internal();
		::operator delete(ptri, sizeof(MAKE_THREADSAFE), std::align_val_t{ alignof(MAKE_THREADSAFE) });
	};

	MAKE_THREADSAFE* mem = 0;
	mem = (MAKE_THREADSAFE*)::operator new(sizeof(MAKE_THREADSAFE), std::align_val_t{ alignof(MAKE_THREADSAFE) });
	new (&(mem->value)) T( std::forward<Args>(args)... );
	new (&(mem->ptri)) stamp_ptr_internal<T>(&(mem->value), deleter);

	return threadsafe_ptr<T>(&(mem->ptri));
}

STAMP_NAMESPACE_END

#endif