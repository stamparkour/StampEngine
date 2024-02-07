#include <atomic>
#include <cstring>
#pragma once

template<class T>
class xptr_base {
private:
	bool decRefrense();
	void incRefrense();
protected:
	T ptr;
	std::atomic<size_t>* count;
	bool canDelete() const;
public:
	xptr_base();
	xptr_base(T other);
	xptr_base(const xptr_base<T>& other);
	xptr_base(xptr_base<T>&& other) noexcept;
	xptr_base<T>& operator =(T& other);
	xptr_base<T>& operator =(const xptr_base<T>& other);
	xptr_base<T>& operator =(xptr_base<T>&& other) noexcept;
	template<class T>
	friend void swap(xptr_base<T>& a, xptr_base<T>& b);
	~xptr_base<T>();
};

template<class T>
class xptr final : private xptr_base<T*> {
public:
	xptr(T* other) : xptr_base<T*>(other) {}
	template<class T, size_t X>
	xptr(const T (&other)[X]) : xptr_base<T*>(NULL) {
		size_t size = X * sizeof(T);
		xptr_base<T*>::ptr = new T[X];
		memcpy_s(xptr_base<T*>::ptr, size, &other, size);
	}
	xptr(xptr<T>& other) : xptr_base<T*>(other) {}
	xptr<T>& operator =(T* other) {
		xptr_base<T*>::operator =(other);
	}
	xptr<T>& operator =(const T* other) {
		xptr_base<T*>::operator =(other);
	}
	template<class T, size_t X>
	xptr<T>& operator =(const T (&other)[X]) {
		size_t size = X * sizeof(T);
		T* p = new T[X];
		memcpy_s(xptr_base<T*>::ptr, size, &other, size);
		xptr_base<T*>::operator =(p);
	}
	xptr<T>& operator =(const xptr<T>& other) {
		xptr_base<T*>::operator =(other);
	}
	xptr<T>& operator =(xptr<T>&& other) noexcept {
		xptr_base<T*>::operator =(other);
	}
	T operator *();
	T** operator &() {
		return *xptr_base<T*>::ptr;
	}
	T* operator ->();
	T operator [](size_t i);
	const T operator *() const;
	const T* operator ->() const;
	const T operator [](size_t i) const;
	operator bool() const noexcept;
	operator void* ();
	operator const void* () const;
	operator explicit T* () {
		return xptr_base<T*>::ptr;
	}
	~xptr();
};


template<class T>
T xptr<T>::operator*()
{
	return *xptr_base<T*>::ptr;
}
template<class T>
T* xptr<T>::operator->()
{
	return xptr_base<T*>::ptr;
}
template<class T>
const T xptr<T>::operator[](size_t i) const
{
	return xptr_base<T*>::ptr[i];
}
template<class T>
const T xptr<T>::operator*() const
{
	return *xptr_base<T*>::ptr;
}
template<class T>
const T* xptr<T>::operator->() const
{
	return xptr_base<T*>::ptr;
}
template<class T>
T xptr<T>::operator[](size_t i)
{
	return xptr_base<T*>::ptr[i];
}
template<class T>
xptr<T>::operator void* ()
{
	return xptr_base<T*>::ptr;
}
template<class T>
xptr<T>::operator const void* () const
{
	return xptr_base<T*>::ptr;
}
template<class T>
xptr<T>::operator bool() const noexcept
{
	return xptr_base<T*>::count && xptr_base<T*>::ptr;
}
template<class T>
inline xptr<T>::~xptr() {
	if (xptr_base<T*>::canDelete()) delete [] xptr_base<T*>::ptr;
}
template<class T>
inline xptr_base<T>::xptr_base()
{
	ptr = {};
	count = {};
}
template<class T>
inline xptr_base<T>::xptr_base(T other)
{
	ptr = other;
	count = new std::atomic<size_t>(1);
}
template<class T>
xptr_base<T>::xptr_base(const xptr_base<T>& other)
{
	ptr = other.ptr;
	count = other.count;
	incRefrense();
}
template<class T>
xptr_base<T>::xptr_base(xptr_base<T>&& other) noexcept
{
	using std::swap;
	ptr = {};
	count = {};
	swap<T>(*this, other);
}
template<class T>
xptr_base<T>& xptr_base<T>::operator=(T& other)
{
	decRefrense();
	ptr = other;
	count = new std::atomic<size_t>(1);
}
template<class T>
xptr_base<T>& xptr_base<T>::operator=(const xptr_base<T>& other)
{
	decRefrense();
	ptr = other.ptr;
	count = other.count;
	incRefrense();
	return *this;
}
template<class T>
xptr_base<T>& xptr_base<T>::operator=(xptr_base<T>&& other) noexcept
{
	using std::swap;
	swap<T>(*this, other);
	return *this;
}
template<class T>
inline void swap(xptr_base<T>& a, xptr_base<T>& b)
{
	using std::swap;
	swap(a.ptr, b.ptr);
	swap(a.count, b.count);
}
template<class T>
bool xptr_base<T>::canDelete() const {
	return ptr && count != NULL && *count == 1;
}
template<class T>
void xptr_base<T>::incRefrense() {
	if(count) count++;
}
template<class T>
bool xptr_base<T>::decRefrense() {
	if (count != NULL && --(*count) > 0) return false;
	delete count;
	count = NULL;
	ptr = {};
	return true;
}
template<class T>
inline xptr_base<T>::~xptr_base()
{
	decRefrense();
}