#pragma once
#ifndef STAMP_VECTOR_H
#define STAMP_VECTOR_H

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

// provides short names for vector types and functions
// #define STAMPENGINE_VECTOR_SHORT_NAMES

//optional headers: <iostream>
#include <cmath>
#include <utility>
#include <stamp/math/mathdefine.h>


STAMPENGINE_MATH_NAMESPACE_BEGIN

template <Quantity T>
struct Vector2;
template <Quantity T>
struct Vector3;
template <Quantity T>
struct Vector4;

using Vector2b = Vector2<bool>;
using Vector2uc = Vector2<unsigned char>;
using Vector2c = Vector2<char>;
using Vector2us = Vector2<unsigned short>;
using Vector2s = Vector2<short>;
using Vector2ui = Vector2<unsigned int>;
using Vector2i = Vector2<int>;
using Vector2ul = Vector2<unsigned long>;
using Vector2l = Vector2<long>;
using Vector2ull = Vector2<unsigned long long>;
using Vector2ll = Vector2<long long>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

using Vector3b = Vector3<bool>;
using Vector3uc = Vector3<unsigned char>;
using Vector3c = Vector3<char>;
using Vector3us = Vector3<unsigned short>;
using Vector3s = Vector3<short>;
using Vector3ui = Vector3<unsigned int>;
using Vector3i = Vector3<int>;
using Vector3ul = Vector3<unsigned long>;
using Vector3l = Vector3<long>;
using Vector3ull = Vector3<unsigned long long>;
using Vector3ll = Vector3<long long>;
using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;

using Vector4b = Vector4<bool>;
using Vector4uc = Vector4<unsigned char>;
using Vector4c = Vector4<char>;
using Vector4us = Vector4<unsigned short>;
using Vector4s = Vector4<short>;
using Vector4ui = Vector4<unsigned int>;
using Vector4i = Vector4<int>;
using Vector4ul = Vector4<unsigned long>;
using Vector4l = Vector4<long>;
using Vector4ull = Vector4<unsigned long long>;
using Vector4ll = Vector4<long long>;
using Vector4f = Vector4<float>;
using Vector4d = Vector4<double>;

#ifdef STAMPENGINE_VECTOR_SHORT_NAMES
using Vec2b = Vector2<bool>;
using Vec2uc = Vector2<unsigned char>;
using Vec2c = Vector2<char>;
using Vec2us = Vector2<unsigned short>;
using Vec2s = Vector2<short>;
using Vec2ui = Vector2<unsigned int>;
using Vec2i = Vector2<int>;
using Vec2ul = Vector2<unsigned long>;
using Vec2l = Vector2<long>;
using Vec2ull = Vector2<unsigned long long>;
using Vec2ll = Vector2<long long>;
using Vec2f = Vector2<float>;
using Vec2d = Vector2<double>;

using Vec3b = Vector3<bool>;
using Vec3uc = Vector3<unsigned char>;
using Vec3c = Vector3<char>;
using Vec3us = Vector3<unsigned short>;
using Vec3s = Vector3<short>;
using Vec3ui = Vector3<unsigned int>;
using Vec3i = Vector3<int>;
using Vec3ul = Vector3<unsigned long>;
using Vec3l = Vector3<long>;
using Vec3ull = Vector3<unsigned long long>;
using Vec3ll = Vector3<long long>;
using Vec3f = Vector3<float>;
using Vec3d = Vector3<double>;

using Vec4b = Vec4<bool>;
using Vec4uc = Vec4<unsigned char>;
using Vec4c = Vec4<char>;
using Vec4us = Vec4<unsigned short>;
using Vec4s = Vec4<short>;
using Vec4ui = Vec4<unsigned int>;
using Vec4i = Vec4<int>;
using Vec4ul = Vec4<unsigned long>;
using Vec4l = Vec4<long>;
using Vec4ull = Vec4<unsigned long long>;
using Vec4ll = Vec4<long long>;
using Vec4f = Vec4<float>;
using Vec4d = Vec4<double>;
#endif

template <Quantity T = STAMPENGINE_DEFAULT_FLOATINGPOINT>
struct Vector2 final {
	T x = 0;
	T y = 0;

	Vector2													()								noexcept : x(0), y(0) {}
	Vector2													(T x)							noexcept : x(x), y(x) {}
	explicit Vector2										(T x, T y)						noexcept : x(x), y(y) {}
	~Vector2												() = default;
	Vector2													(const Vector2<T>& other)		noexcept : x(other.x), y(other.y) {}
	Vector2													(Vector2<T>&& other)			noexcept;
	Vector2<T>&								operator	=	(const Vector2<T>& other)		noexcept;
	Vector2<T>&								operator	=	(Vector2<T>&& other)			noexcept;
	
	template <Quantity T1> explicit operator Vector2<T1>	()						const	noexcept;
	template <Quantity T1> explicit operator Vector3<T1>	()						const	noexcept;
	template <Quantity T1> explicit operator Vector4<T1>	()						const	noexcept;

	Vector2<T>								operator	+	(const Vector2<T>& b)	const	noexcept;
	Vector2<T>&								operator	+=	(const Vector2<T>& b)			noexcept;
	Vector2<T>								operator	-	(const Vector2<T>& b)	const	noexcept;
	Vector2<T>&								operator	-=	(const Vector2<T>& b)			noexcept;
	Vector2<T>								operator	*	(const Vector2<T>& b)	const	noexcept;
	Vector2<T>&								operator	*=	(const Vector2<T>& b)			noexcept;
	Vector2<T>								operator	/	(const Vector2<T>& b)	const	noexcept;
	Vector2<T>&								operator	/=	(const Vector2<T>& b)			noexcept;
	Vector2<bool>							operator	==	(const Vector2<T>& b)	const	noexcept;
	bool									operator	!=	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	>	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	<	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	>=	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	<=	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	&&	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	||	(const Vector2<T>& b)	const	noexcept;
	Vector2<bool>							operator	!	()						const	noexcept;
	explicit								operator bool	()						const	noexcept;
};

template <Quantity T = STAMPENGINE_DEFAULT_FLOATINGPOINT>
struct Vector3 final {
	T x = 0;
	T y = 0;
	T z = 0;
	
	Vector3													()								noexcept : x(0), y(0), z(0) {}
	Vector3													(T x)							noexcept : x(x), y(x), z(x) {}
	Vector3													(T x, T y, T z)					noexcept : x(x), y(y), z(z) {}
	explicit Vector3										(const Vector2<T>& a, T z)		noexcept : x(a.x), y(a.y), z(z) {}
	explicit Vector3										(T x, const Vector2<T>& a)		noexcept : x(x), y(a.x), z(a.y) {}
	~Vector3												() = default;
	Vector3													(const Vector3<T>& other)		noexcept : x(other.x), y(other.y), z(other.z) {}
	Vector3													(Vector3<T>&& other)			noexcept;
	Vector3<T>&								operator	=	(const Vector3<T>& other)		noexcept;
	Vector3<T>&								operator	=	(Vector3<T>&& other)			noexcept;
	
	template <Quantity T1> explicit operator Vector2<T1>	()						const	noexcept;
	template <Quantity T1> explicit operator Vector3<T1>	()						const	noexcept;
	template <Quantity T1> explicit operator Vector4<T1>	()						const	noexcept;

	Vector3<T>								operator	+	(const Vector3<T>& b)	const	noexcept;
	Vector3<T>&								operator	+=	(const Vector3<T>& b)			noexcept;
	Vector3<T>								operator	-	(const Vector3<T>& b)	const	noexcept;
	Vector3<T>&								operator	-=	(const Vector3<T>& b)			noexcept;
	Vector3<T>								operator	*	(const Vector3<T>& b)	const	noexcept;
	Vector3<T>&								operator	*=	(const Vector3<T>& b)			noexcept;
	Vector3<T>								operator	/	(const Vector3<T>& b)	const	noexcept;
	Vector3<T>&								operator	/=	(const Vector3<T>& b)			noexcept;
	Vector3<bool>							operator	==	(const Vector3<T>& b)	const	noexcept;
	bool									operator	!=	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	>	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	<	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	>=	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	<=	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	&&	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	||	(const Vector3<T>& b)	const	noexcept;
	Vector3<bool>							operator	!	()						const	noexcept;
	explicit								operator bool	()						const	noexcept;
};

template <Quantity T = STAMPENGINE_DEFAULT_FLOATINGPOINT>
struct Vector4 final {
	T x = 0;
	T y = 0;
	T z = 0;
	T w = 0;

	Vector4													()								noexcept :	x(0),	y(0),	z(0),	w(0) {}
	Vector4													(T x)							noexcept :	x(x),	y(x),	z(x),	w(x) {}
	Vector4													(T x, T y)						noexcept :	x(x),	y(y),	z(x),	w(y) {}
	Vector4													(T x, T y, T z, T w)			noexcept :	x(x),	y(y),	z(z),	w(w) {}
	explicit Vector4										(const Vector2<T>& a, T z, T w)	noexcept :	x(a.x), y(a.y),	z(z),	w(w) {}
	explicit Vector4										(T x, const Vector2<T>& a, T w)	noexcept :	x(x),	y(a.x),	z(a.y),	w(w) {}
	explicit Vector4										(T x, T y, const Vector2<T>& a)	noexcept :	x(x),	y(y),	z(a.x),	w(a.y) {}
	explicit Vector4							(const Vector2<T>& a, const Vector2<T>& b)	noexcept :	x(a.x), y(a.y),	z(b.x),	w(b.y) {}
	explicit Vector4										(const Vector3<T>& a, T w)		noexcept :	x(a.x), y(a.y),	z(a.z),	w(w) {}
	explicit Vector4										(T x, const Vector3<T>& a)		noexcept :	x(x),	y(a.x),	z(a.y),	w(a.z) {}
	~Vector4												() = default;
	Vector4													(const Vector4<T>& other)		noexcept :	x(other.x), y(other.y), z(other.z), w(other.w) {}
	Vector4													(Vector4<T>&& other)			noexcept;
	Vector4<T>&								operator	=	(const Vector4<T>& other)		noexcept;
	Vector4<T>&								operator	=	(Vector4<T>&& other)			noexcept;
	
	template <Quantity T1> explicit operator Vector2<T1>	()						const	noexcept;
	template <Quantity T1> explicit operator Vector3<T1>	()						const	noexcept;
	template <Quantity T1> explicit operator Vector4<T1>	()						const	noexcept;

	Vector4<T>								operator	+	(const Vector4<T>& b)	const	noexcept;
	Vector4<T>&								operator	+=	(const Vector4<T>& b)			noexcept;
	Vector4<T>								operator	-	(const Vector4<T>& b)	const	noexcept;
	Vector4<T>&								operator	-=	(const Vector4<T>& b)			noexcept;
	Vector4<T>								operator	*	(const Vector4<T>& b)	const	noexcept;
	Vector4<T>&								operator	*=	(const Vector4<T>& b)			noexcept;
	Vector4<T>								operator	/	(const Vector4<T>& b)	const	noexcept;
	Vector4<T>&								operator	/=	(const Vector4<T>& b)			noexcept;
	Vector4<bool>							operator	==	(const Vector4<T>& b)	const	noexcept;
	bool									operator	!=	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	>	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	<	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	>=	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	<=	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	&&	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	||	(const Vector4<T>& b)	const	noexcept;
	Vector4<bool>							operator	!	()						const	noexcept;
	explicit								operator bool	()						const	noexcept;
};

template <Quantity T> inline bool		_and		(const Vector2<T>& v) 						noexcept;
template <Quantity T> inline bool		_and		(const Vector3<T>& v) 						noexcept;
template <Quantity T> inline bool		_and		(const Vector4<T>& v) 						noexcept;
template <Quantity T> inline bool		_or			(const Vector2<T>& v) 						noexcept;
template <Quantity T> inline bool		_or			(const Vector3<T>& v) 						noexcept;
template <Quantity T> inline bool		_or			(const Vector4<T>& v) 						noexcept;
template <Quantity T> inline T			summation	(const Vector2<T>& v) 						noexcept;
template <Quantity T> inline T			summation	(const Vector3<T>& v) 						noexcept;
template <Quantity T> inline T			summation	(const Vector4<T>& v) 						noexcept;
template <Quantity T> inline T 			magnitude	(const Vector2<T>& v)						noexcept;
template <Quantity T> inline T 			magnitude	(const Vector3<T>& v)						noexcept;
template <Quantity T> inline T 			magnitude	(const Vector4<T>& v) 						noexcept;
template <Quantity T> inline T 			magnitude2	(const Vector2<T>& v) 						noexcept;
template <Quantity T> inline T 			magnitude2	(const Vector3<T>& v) 						noexcept;
template <Quantity T> inline T 			magnitude2	(const Vector4<T>& v) 						noexcept;
template <Quantity T> inline Vector2<T> normal		(const Vector2<T>& v) 						noexcept;
template <Quantity T> inline Vector3<T> normal		(const Vector3<T>& v) 						noexcept;
template <Quantity T> inline Vector4<T> normal		(const Vector4<T>& v) 						noexcept;
template <Quantity T> inline T			dot			(const Vector2<T>& a, const Vector2<T>& b)	noexcept;
template <Quantity T> inline T 			dot			(const Vector3<T>& a, const Vector3<T>& b)	noexcept;
template <Quantity T> inline T 			dot			(const Vector4<T>& a, const Vector4<T>& b)	noexcept;
template <Quantity T> inline T 			cross		(const Vector2<T>& a, const Vector2<T>& b)	noexcept;
template <Quantity T> inline Vector3<T> cross		(const Vector3<T>& a, const Vector3<T>& b)	noexcept;


#ifdef STAMPENGINE_VECTOR_SHORT_NAMES
template <Quantity T> inline T			sum(const Vector2<T>& v)	noexcept;
template <Quantity T> inline T			sum(const Vector3<T>& v)	noexcept;
template <Quantity T> inline T			sum(const Vector4<T>& v)	noexcept;
template <Quantity T> inline T 			mag(const Vector2<T>& v)	noexcept;
template <Quantity T> inline T 			mag(const Vector3<T>& v)	noexcept;
template <Quantity T> inline T 			mag(const Vector4<T>& v)	noexcept;
template <Quantity T> inline T 			mag2(const Vector2<T>& v)	noexcept;
template <Quantity T> inline T 			mag2(const Vector3<T>& v)	noexcept;
template <Quantity T> inline T 			mag2(const Vector4<T>& v)	noexcept;
template <Quantity T> inline Vector2<T> norm(const Vector2<T>& v)	noexcept;
template <Quantity T> inline Vector3<T> norm(const Vector3<T>& v)	noexcept;
template <Quantity T> inline Vector4<T> norm(const Vector4<T>& v)	noexcept;
#endif

STAMPENGINE_MATH_NAMESPACE_END

template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline void swap(STAMPENGINE_MATH_NAMESPACE::Vector2<T>& a, STAMPENGINE_MATH_NAMESPACE::Vector2<T>& b) noexcept;
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline void swap(STAMPENGINE_MATH_NAMESPACE::Vector3<T>& a, STAMPENGINE_MATH_NAMESPACE::Vector3<T>& b) noexcept;
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline void swap(STAMPENGINE_MATH_NAMESPACE::Vector4<T>& a, STAMPENGINE_MATH_NAMESPACE::Vector4<T>& b) noexcept;

#ifdef STAMPENGINE_IOSTREAM_HEADER_INCLUDED
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline std::ostream& operator <<(std::ostream& stream, const STAMPENGINE_MATH_NAMESPACE::Vector2<T>& v);
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline std::ostream& operator <<(std::ostream& stream, const STAMPENGINE_MATH_NAMESPACE::Vector3<T>& v);
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline std::ostream& operator <<(std::ostream& stream, const STAMPENGINE_MATH_NAMESPACE::Vector4<T>& v);
#endif

#ifdef STAMPENGINE_STRING_HEADER_INCLUDED
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline std::string to_string(const STAMPENGINE_MATH_NAMESPACE::Vector2<T>& v);
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline std::string to_string(const STAMPENGINE_MATH_NAMESPACE::Vector3<T>& v);
template <STAMPENGINE_MATH_NAMESPACE::Quantity T> inline std::string to_string(const STAMPENGINE_MATH_NAMESPACE::Vector4<T>& v);
#endif
// Definitions

STAMPENGINE_MATH_NAMESPACE_BEGIN

// ------------ Vector2 Logic ------------
template<Quantity T>
Vector2<T>::Vector2(Vector2<T>&& other) noexcept {
	swap(*this, other);
}
template<Quantity T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& other) noexcept {
	x = other.x;
	y = other.y;
	return *this;
}
template<Quantity T>
Vector2<T>& Vector2<T>::operator=(Vector2<T>&& other) noexcept {
	swap(*this, other);
	return *this;
}
template<Quantity T> template<Quantity T1>
inline Vector2<T>::operator Vector2<T1>() const noexcept {
	return Vector2<T1>((T1)x, (T1)y);
}
template<Quantity T> template<Quantity T1>
inline Vector2<T>::operator Vector3<T1>() const noexcept {
	return Vector3<T1>((T1)x, (T1)y, 0);
}
template<Quantity T> template<Quantity T1>
inline Vector2<T>::operator Vector4<T1>() const noexcept {
	return Vector4<T1>((T1)x, (T1)y, 0, 0);
}
template<Quantity T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& b) const noexcept {
	return Vector2<T>(x + b.x, y + b.y);
}
template<Quantity T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& b) noexcept {
	return *this = *this + b;
}
template<Quantity T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& b) const noexcept {
	return Vector2<T>(x - b.x, y - b.y);
}
template<Quantity T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& b) noexcept {
	return *this = *this - b;
}
template<Quantity T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& b) const noexcept {
	return Vector2<T>(x * b.x, y * b.y);
}
template<Quantity T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& b) noexcept {
	return *this = *this * b;
}
template<Quantity T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& b) const noexcept {
	return Vector2<T>(x / b.x, y / b.y);
}
template<Quantity T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& b) noexcept {
	return *this = *this / b;
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator==(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x == b.x, y == b.y);
}
template<Quantity T>
bool Vector2<T>::operator!=(const Vector2<T>& b) const noexcept {
	return _or(!(*this == b));
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator>(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x > b.x, y > b.y);
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator<(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x < b.x, y < b.y);
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator>=(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x >= b.x, y >= b.y);
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator<=(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x <= b.x, y <= b.y);
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator&&(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x && b.x, y && b.y);
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator||(const Vector2<T>& b) const noexcept {
	return Vector2<bool>(x || b.x, y || b.y);
}
template<Quantity T>
Vector2<bool> Vector2<T>::operator!() const noexcept {
	return Vector2<bool>(!x, !y);
}
template<Quantity T>
Vector2<T>::operator bool() const noexcept {
	return _and(*this);
}

// ------------ Vector3 Logic ------------
template<Quantity T>
Vector3<T>::Vector3(Vector3<T>&& other) noexcept {
	swap(*this, other);
}
template<Quantity T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T>& other) noexcept {
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}
template<Quantity T>
Vector3<T>& Vector3<T>::operator=(Vector3<T>&& other) noexcept {
	swap(*this, other);
	return *this;
}
template<Quantity T> template<Quantity T1>
inline Vector3<T>::operator Vector2<T1>() const noexcept {
	return Vector2<T1>((T1)x, (T1)y);
}
template<Quantity T> template<Quantity T1>
inline Vector3<T>::operator Vector3<T1>() const noexcept {
	return Vector3<T1>((T1)x, (T1)y, (T1)z);
}
template<Quantity T> template<Quantity T1>
inline Vector3<T>::operator Vector4<T1>() const noexcept {
	return Vector4<T1>((T1)x, (T1)y, (T1)z, 0);
}
template<Quantity T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& b) const noexcept {
	return Vector3<T>(x + b.x, y + b.y, z + b.z);
}
template<Quantity T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& b) noexcept {
	return *this = *this + b;
}
template<Quantity T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& b) const noexcept {
	return Vector3<T>(x - b.x, y - b.y, z - b.z);
}
template<Quantity T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& b) noexcept {
	return *this = *this - b;
}
template<Quantity T>
Vector3<T> Vector3<T>::operator*(const Vector3<T>& b) const noexcept {
	return Vector3<T>(x * b.x, y * b.y, z * b.z);
}
template<Quantity T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& b) noexcept {
	return *this = *this * b;
}
template<Quantity T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& b) const noexcept {
	return Vector3<T>(x / b.x, y / b.y, z / b.z);
}
template<Quantity T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& b) noexcept {
	return *this = *this / b;
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator==(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x == b.x, y == b.y, z == b.z);
}
template<Quantity T>
bool Vector3<T>::operator!=(const Vector3<T>& b) const noexcept {
	return _or(!(*this == b));
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator>(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x > b.x, y > b.y, z > b.z);
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator<(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x < b.x, y < b.y, z < b.z);
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator>=(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x >= b.x, y >= b.y, z >= b.z);
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator<=(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x <= b.x, y <= b.y, z <= b.z);
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator&&(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x && b.x, y && b.y, z && b.z);
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator||(const Vector3<T>& b) const noexcept {
	return Vector3<bool>(x || b.x, y || b.y, z || b.z);
}
template<Quantity T>
Vector3<bool> Vector3<T>::operator!() const noexcept {
	return Vector3<bool>(!x, !y, !z);
}
template<Quantity T>
Vector3<T>::operator bool() const noexcept {
	return _and(*this);
}



// ------------ Vector4 Logic ------------
template<Quantity T>
Vector4<T>::Vector4(Vector4<T>&& other) noexcept {
	swap(*this, other);
}
template<Quantity T>
Vector4<T>& Vector4<T>::operator=(const Vector4<T>& other) noexcept {
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}
template<Quantity T>
Vector4<T>& Vector4<T>::operator=(Vector4<T>&& other) noexcept {
	swap(*this, other);
	return *this;
}
template<Quantity T> template<Quantity T1>
inline Vector4<T>::operator Vector2<T1>() const noexcept {
	return Vector2<T1>((T1)x, (T1)y);
}
template<Quantity T> template<Quantity T1>
inline Vector4<T>::operator Vector3<T1>() const noexcept {
	return Vector3<T1>((T1)x, (T1)y, (T1)z);
}
template<Quantity T> template<Quantity T1>
inline Vector4<T>::operator Vector4<T1>() const noexcept {
	return Vector4<T1>((T1)x, (T1)y, (T1)z, (T1)w);
}
template<Quantity T>
Vector4<T> Vector4<T>::operator+(const Vector4<T>& b) const noexcept {
	return Vector4<T>(x + b.x, y + b.y, z + b.z, w + b.w);
}
template<Quantity T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& b) noexcept {
	return *this = *this + b;
}
template<Quantity T>
Vector4<T> Vector4<T>::operator-(const Vector4<T>& b) const noexcept {
	return Vector4<T>(x - b.x, y - b.y, z - b.z, w - b.w);
}
template<Quantity T>
Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& b) noexcept {
	return *this = *this - b;
}
template<Quantity T>
Vector4<T> Vector4<T>::operator*(const Vector4<T>& b) const noexcept {
	return Vector4<T>(x * b.x, y * b.y, z * b.z, w * b.w);
}
template<Quantity T>
Vector4<T>& Vector4<T>::operator*=(const Vector4<T>& b) noexcept {
	return *this = *this * b;
}
template<Quantity T>
Vector4<T> Vector4<T>::operator/(const Vector4<T>& b) const noexcept {
	return Vector4<T>(x / b.x, y / b.y, z / b.z, w / b.w);
}
template<Quantity T>
Vector4<T>& Vector4<T>::operator/=(const Vector4<T>& b) noexcept {
	return *this = *this / b;
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator==(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x == b.x, y == b.y, z == b.z, w == b.w);
}
template<Quantity T>
bool Vector4<T>::operator!=(const Vector4<T>& b) const noexcept {
	return _or(!(*this == b));
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator>(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x > b.x, y > b.y, z > b.z, w > b.w);
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator<(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x < b.x, y < b.y, z < b.z, w < b.w);
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator>=(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x >= b.x, y >= b.y, z >= b.z, w >= b.w);
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator<=(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x <= b.x, y <= b.y, z <= b.z, w <= b.w);
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator&&(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x && b.x, y && b.y, z && b.z, w && b.w);
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator||(const Vector4<T>& b) const noexcept {
	return Vector4<bool>(x || b.x, y || b.y, z || b.z, w || b.w);
}
template<Quantity T>
Vector4<bool> Vector4<T>::operator!() const noexcept {
	return Vector4<bool>(!x, !y, !z, !w);
}
template<Quantity T>
Vector4<T>::operator bool() const noexcept {
	return _and(*this);
}

template<Quantity T>
inline bool _and(const Vector2<T>& v) noexcept {
	return v.x && v.y;
}
template<Quantity T>
inline bool _and(const Vector3<T>& v) noexcept {
	return v.x && v.y && v.z;
}
template<Quantity T>
inline bool _and(const Vector4<T>& v) noexcept {
	return v.x && v.y && v.z && v.w;
}
template<Quantity T>
inline bool _or(const Vector2<T>& v) noexcept {
	return v.x || v.y;
}
template<Quantity T>
inline bool _or(const Vector3<T>& v) noexcept {
	return v.x || v.y || v.z;
}
template<Quantity T>
inline bool _or(const Vector4<T>& v) noexcept {
	return v.x || v.y || v.z || v.w;
}
template<Quantity T>
inline T summation(const Vector2<T>& v) noexcept {
	return v.x + v.y;
}
template<Quantity T>
inline T summation(const Vector3<T>& v) noexcept {
	return v.x + v.y + v.z;
}
template<Quantity T>
inline T summation(const Vector4<T>& v) noexcept {
	return v.x + v.y + v.z + v.w;
}
template<Quantity T>
inline Vector2<T> normal(const Vector2<T>& v) noexcept {
	return v / magnitude(v);
}
template<Quantity T>
inline Vector3<T> normal(const Vector3<T>& v) noexcept {
	return v / magnitude(v);
}
template<Quantity T>
inline Vector4<T> normal(const Vector4<T>& v) noexcept {
	return v / magnitude(v);
}
template<Quantity T>
inline T dot(const Vector2<T>& a, const Vector2<T>& b) noexcept {
	return summation(a * b);
}
template<Quantity T>
inline T dot(const Vector3<T>& a, const Vector3<T>& b) noexcept {
	return summation(a * b);
}
template<Quantity T>
inline T dot(const Vector4<T>& a, const Vector4<T>& b) noexcept {
	return summation(a * b);
}
template<Quantity T>
inline T cross(const Vector2<T>& a, const Vector2<T>& b) noexcept {
	return a.x * b.y - a.y * b.x;
}
template<Quantity T>
inline Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b) noexcept {
	return Vector3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
template<Quantity T>
inline T magnitude(const Vector2<T>& v) noexcept {
	return (T)sqrt(magnitude2(v));
}
template<Quantity T>
inline T magnitude(const Vector3<T>& v) noexcept {
	return (T)sqrt(magnitude2(v));
}
template<Quantity T>
inline T magnitude(const Vector4<T>& v) noexcept {
	return (T)sqrt(magnitude2(v));
}
template<Quantity T>
inline T magnitude2(const Vector2<T>& v) noexcept {
	return (T)summation(v * v);
}
template<Quantity T>
inline T magnitude2(const Vector3<T>& v) noexcept {
	return (T)summation(v * v);
}
template<Quantity T>
inline T magnitude2(const Vector4<T>& v) noexcept {
	return (T)summation(v * v);
}

#ifdef STAMPENGINE_VECTOR_SHORT_NAMES
template <Quantity T>
inline T sum(const Vector2<T>& v) noexcept {
	return summation(v);
}
template <Quantity T>
inline T sum(const Vector3<T>& v) noexcept {
	return summation(v);
}
template <Quantity T>
inline T sum(const Vector4<T>& v) noexcept {
	return summation(v);
}
template <Quantity T>
inline T mag(const Vector2<T>& v) noexcept {
	return magnitude(v);
}
template <Quantity T>
inline T mag(const Vector3<T>& v) noexcept {
	return magnitude(v);
}
template <Quantity T>
inline T mag(const Vector4<T>& v) noexcept {
	return magnitude(v);
}
template <Quantity T>
inline T mag2(const Vector2<T>& v) noexcept {
	return magnitude2(v);
}
template <Quantity T>
inline T mag2(const Vector3<T>& v) noexcept {
	return magnitude2(v);
}
template <Quantity T>
inline T mag2(const Vector4<T>& v) noexcept {
	return magnitude2(v);
}
template <Quantity T>
inline Vector2<T> norm(const Vector2<T>& v)	noexcept {
	return normal(v);
}
template <Quantity T>
inline Vector3<T> norm(const Vector3<T>& v)	noexcept {
	return normal(v);
}
template <Quantity T>
inline Vector4<T> norm(const Vector4<T>& v)	noexcept {
	return normal(v);
}
#endif

STAMPENGINE_MATH_NAMESPACE_END

template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline void swap(STAMPENGINE_MATH_NAMESPACE::Vector2<T>& a, STAMPENGINE_MATH_NAMESPACE::Vector2<T>& b) noexcept {
	using std::swap;
	swap(a.x, b.x);
	swap(a.y, b.y);
}
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline void swap(STAMPENGINE_MATH_NAMESPACE::Vector3<T>& a, STAMPENGINE_MATH_NAMESPACE::Vector3<T>& b) noexcept {
	using std::swap;
	swap(a.x, b.x);
	swap(a.y, b.y);
	swap(a.z, b.z);
}
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline void swap(STAMPENGINE_MATH_NAMESPACE::Vector4<T>& a, STAMPENGINE_MATH_NAMESPACE::Vector4<T>& b) noexcept {
	using std::swap;
	swap(a.x, b.x);
	swap(a.y, b.y);
	swap(a.z, b.z);
	swap(a.w, b.w);
}

#ifdef STAMPENGINE_IOSTREAM_HEADER_INCLUDED
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline std::ostream& operator<<(std::ostream& stream, const STAMPENGINE_MATH_NAMESPACE::Vector2<T>& v) {
	return stream << "(" << v.x << ", " << v.y << ")";
}
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline std::ostream& operator<<(std::ostream& stream, const STAMPENGINE_MATH_NAMESPACE::Vector3<T>& v) {
	return stream << "(" << v.x << ", " << v.y << "," << v.z << ")";
}
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline std::ostream& operator<<(std::ostream& stream, const STAMPENGINE_MATH_NAMESPACE::Vector4<T>& v) {
	return stream << "(" << v.x << ", " << v.y << "," << v.z << "," << v.w << ")";
}
#endif

#ifdef STAMPENGINE_STRING_HEADER_INCLUDED
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline std::string to_string(const STAMPENGINE_MATH_NAMESPACE::Vector2<T>& v) {
	return std::string("(") + std::to_string(v.x) + "," + std::to_string(v.y) + ")";
}
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline std::string to_string(const STAMPENGINE_MATH_NAMESPACE::Vector3<T>& v) {
	return std::string("(") + std::to_string(v.x) + "," + std::to_string(v.y) + "," + std::to_string(v.z) + ")";
}
template<STAMPENGINE_MATH_NAMESPACE::Quantity T>
inline std::string to_string(const STAMPENGINE_MATH_NAMESPACE::Vector4<T>& v) {
	return std::string("(") + std::to_string(v.x) + "," + std::to_string(v.y) + "," + std::to_string(v.z) + "," + std::to_string(v.w) + ")";
}
#endif

#endif