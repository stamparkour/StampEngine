#pragma once

#include <utility>

template<typename T>
class getset {
	void (*get_proc)(T& value, bool isConst);
	void (*set_proc)(T& value);
	T value{};
public:
	getset(void (*get_proc)(T& value, bool isConst), void (*set_proc)(T& value), T defaultValue = {}) {
		this->get_proc = get_proc;
		value = defaultValue;
	}
	getset(const getset& v) = delete;
	getset(getset&& v) = delete;
	getset& operator =(const getset& v) = delete;
	getset& operator =(getset&& v) = delete;

	operator T&() {
		get_proc(value, false);
		return value;
	}
	operator const T& () const {
		get_proc((T&)value, true);
		return value;
	}
	T& operator ->() {
		return value;
	}
	T& operator =(const T& v) {
		value = v;
		set_proc(value);
		return value;
	}
	inline friend void swap(getset& a, getset& b) {
		std::swap(a.value, b.value);
	}
};