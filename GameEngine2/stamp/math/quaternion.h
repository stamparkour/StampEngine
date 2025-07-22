#pragma once
#ifndef STAMP_MATH_QUATERNION_H
#define STAMP_MATH_QUATERNION_H

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
// #define STAMP_QUATERNION_SHORT_NAMES

// makes all comparison operators prefer equal_aprox
// #define STAMP_MATH_QUATERNION_EQUAL_APROX

//optional headers: <iostream> <string>
#include <stamp/math/algorithm.h>
#include <stamp/math/matrix.h>
#include <stamp/math/vector.h>

STAMP_MATH_NAMESPACE_BEGIN

template<Quantity T = STAMP_DEFAULT_FLOATINGPOINT>
struct Quaternion;

STAMP_TEMPLATE_ALL_QUANTITY(Quaternion);

#ifdef STAMP_MATH_QUATERNION_SHORT_NAMES
template <Quantity T = STAMP_DEFAULT_FLOATINGPOINT>
using Quat = Quaternion<T>;
STAMP_TEMPLATE_ALL_QUANTITY(Quat);
#endif

template<Quantity T>
struct Quaternion final {
	T x;
	T i;
	T j;
	T k;

	Quaternion	()								noexcept : x(0), i(0), j(0), k(0) {}
	Quaternion	(T x)							noexcept : x(x), i(0), j(0), k(0) {}
	Quaternion	(T x, T i, T j, T k)			noexcept : x(x), i(i), j(j), k(k) {}
	explicit Quaternion	(const Vector2<T>& v)	noexcept : x(v.x), i(v.y), j(0), k(0) {}
	explicit Quaternion	(const Vector3<T>& v)	noexcept : x(0), i(v.x), j(v.y), k(v.z) {}
	Quaternion	(T x, const Vector3<T>& v)		noexcept : x(x), i(v.x), j(v.y), k(v.z) {}
	explicit Quaternion	(const Vector4<T>& v)	noexcept : x(v.x), i(v.y), j(v.z), k(v.w) {}

	template <Quantity T1> explicit	operator Quaternion<T1>	()	const	noexcept;
	template <Quantity T1> explicit	operator			T1	()	const	noexcept;
	explicit						operator const		T*	()	const	noexcept;
	explicit						operator			T*	()			noexcept;
	explicit						operator	Matrix3<T>	()	const	noexcept;
	explicit						operator	Matrix4<T>	()	const	noexcept;

	const static Quaternion<T> IDENTITY;
};

STAMP_MATH_NAMESPACE_END
STAMP_MATH_QUATERNION_NAMESPACE_BEGIN
using namespace STAMP_MATH_NAMESPACE;

template<Quantity T> inline Matrix3<T>    ToMatrix3	(const Quaternion<T>& q)	noexcept;
template<Quantity T> inline Matrix4<T>	  ToMatrix4	(const Quaternion<T>& q)	noexcept;

template<Quantity T> inline Quaternion<T> RotationX	(T v)						noexcept;
template<Quantity T> inline Quaternion<T> RotationY	(T v)						noexcept;
template<Quantity T> inline Quaternion<T> RotationZ	(T v)						noexcept;
template<Quantity T> inline Quaternion<T> RotationAxis(T r, const Vector3<T>& axis) noexcept;
template<Quantity T> inline Quaternion<T> Rotation(const Vector3<T>& angles, RotationOrder order = RotationOrder::ZXY) noexcept;
template<Quantity T> inline Quaternion<T> LookAt(const Vector3<T>& position)	noexcept;

STAMP_MATH_QUATERNION_NAMESPACE_END
STAMP_MATH_NAMESPACE_BEGIN

template<Quantity T> Quaternion<T>	operator	+	(const Quaternion<T>& a, const Quaternion<T>& b)	noexcept;
template<Quantity T> Quaternion<T>&	operator	+=	(Quaternion<T>& a, const Quaternion<T>& b)			noexcept;
template<Quantity T> Quaternion<T>	operator	-	(const Quaternion<T>& a, const Quaternion<T>& b)	noexcept;
template<Quantity T> Quaternion<T>&	operator	-=	(Quaternion<T>& a, const Quaternion<T>& b)			noexcept;
template<Quantity T> Quaternion<T>	operator	*	(const Quaternion<T>& a, const Quaternion<T>& b)	noexcept;
template<Quantity T> Quaternion<T>&	operator	*=	(Quaternion<T>& a, const Quaternion<T>& b)			noexcept;
template<Quantity T> Quaternion<T>	operator	/	(const Quaternion<T>& a, const Quaternion<T>& b)	noexcept;
template<Quantity T> Quaternion<T>&	operator	/=	(Quaternion<T>& a, const Quaternion<T>& b)			noexcept;
template<Quantity T> Vector4<bool>&	operator	==	(const Quaternion<T>& a, const Quaternion<T>& b)	noexcept;
template<Quantity T> Vector3<T>		operator	*	(const Quaternion<T>& a, const Vector3<T>& b)		noexcept;

STAMP_OPERATOR_ALL_QUANTITY(Quaternion);

template<Quantity T> inline Quaternion<T> conjugate(const Quaternion<T>& q)	noexcept;
template<Quantity T> inline T norm(const Quaternion<T>& q)		noexcept;
template<Quantity T> inline T norm2(const Quaternion<T>& q)		noexcept;
template<Quantity T> inline Quaternion<T> unit(const Quaternion<T>& q)		noexcept;
template<Quantity T> inline Quaternion<T> inverse(const Quaternion<T>& q)	noexcept;

template <Quantity T> inline Quaternion<bool>	equal_aprox(const Quaternion<T>& a, const Quaternion<T>& b);

#ifdef STAMP_MATH_QUATERNION_SHORT_NAMES
template<Quantity T> inline Quaternion<T> conj		(const Quaternion<T>& q)	noexcept;
template<Quantity T> inline Quaternion<T> inv		(const Quaternion<T>& q)	noexcept;
#endif

#ifdef STAMP_IOSTREAM_HEADER_INCLUDED
template <STAMP_MATH_NAMESPACE::Quantity T> inline std::ostream& operator <<(std::ostream& stream, const STAMP_MATH_NAMESPACE::Quaternion<T>& v);
#endif

#ifdef STAMP_STRING_HEADER_INCLUDED
template <STAMP_MATH_NAMESPACE::Quantity T> inline std::string to_string(const STAMP_MATH_NAMESPACE::Quaternion<T>& v);
#endif

//Definitions
template<Quantity T>
template<Quantity T1>
inline Quaternion<T>::operator Quaternion<T1>() const noexcept {
	return Quaternion<T1>{(T1)x, (T1)i, (T1)j, (T1)k};
}
template<Quantity T>
template<Quantity T1>
inline Quaternion<T>::operator T1() const noexcept {
	return (T1)x;
}
template<Quantity T>
inline Quaternion<T>::operator const T* () const noexcept {
	return &x;
}
template<Quantity T>
inline Quaternion<T>::operator T* () noexcept {
	return &x;
}
template<Quantity T>
inline Quaternion<T>::operator Matrix3<T>() const noexcept {
	return Matrix3<T>{
			1 - 2 * (j * j + k * k), 2 * (i * j + k * x), 2 * (i * k - j * x),
			2 * (i * j - k * x), 1 - 2 * (i * i + k * k), 2 * (j * k + i * x),
			2 * (i * k + j * x), 2 * (j * k - i * x), 1 - 2 * (i * i + j * j),
	};
}
template<Quantity T>
inline Quaternion<T>::operator Matrix<T, 4, 4>() const noexcept {
	return Matrix4<T>{
		1 - 2 * (j * j + k * k), 2 * (i * j + k * x), 2 * (i * k - j * x), 0,
		2 * (i * j - k * x), 1 - 2 * (i * i + k * k), 2 * (j * k + i * x), 0,
		2 * (i * k + j * x), 2 * (j * k - i * x), 1 - 2 * (i * i + j * j), 0,
		0,0,0,1
	};
}
template<Quantity T>
inline Quaternion<T> operator + (const Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return { a.x + b.x, a.i + b.i, a.j + b.j, a.k + b.k };
}
template<Quantity T>
Quaternion<T>& operator +=(Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return *this = *this + b;
}
template<Quantity T>
Quaternion<T> operator -(Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return { a.x - b.x, a.i - b.i, a.j - b.j, a.k - b.k };
}
template<Quantity T>
Quaternion<T>& operator -=(Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return *this = *this - b;
}
template<Quantity T>
Quaternion<T> operator *(const Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return { a.x * b.x - a.i * b.i - a.j * b.j - a.k * b.k,
		a.x * b.i + a.i * b.x + a.j * b.k - a.k * b.j,
		a.x * b.j - a.i * b.k + a.j * b.x + a.k * b.i,
		a.x * b.k + a.i * b.j - a.j * b.i + a.k * b.x };
}
template<Quantity T>
Quaternion<T>& operator *=(Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return *this = *this * b;
}
template<Quantity T>
Quaternion<T> operator /(const Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return a * inverse(b);
}
template<Quantity T>
Quaternion<T>& operator /=(Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return *this = *this / b;
}
#ifdef STAMP_MATH_QUATERNION_EQUAL_APROX
template<Quantity T>
inline Quaternion<bool>& operator==(const Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return equal_aprox(a, b);
}
#else
template<Quantity T>
inline Vector4<bool>& operator==(const Quaternion<T>& a, const Quaternion<T>& b) noexcept {
	return Vector4<bool>(a.x == b.x, a.i == b.i, a.j == b.j, a.k == b.k);
}
#endif
template<Quantity T>
Vector3<T> operator *(const Quaternion<T>& a, const Vector3<T>& b) noexcept {
	Quaternion<T> v = *this * (Quaternion<T>)b * inverse(*this);
	return (Vector3<T>)v;
}

STAMP_MATH_NAMESPACE_END
STAMP_MATH_QUATERNION_NAMESPACE_BEGIN

template<Quantity T>
inline Matrix3<T> ToMatrix3(const Quaternion<T>& q) noexcept {
	return (Matrix3<T>)q;
}
template<Quantity T>
inline Matrix3<T> ToMatrix4(const Quaternion<T>& q) noexcept {
	return (Matrix4<T>)q;
}
template<Quantity T>
inline Quaternion<T> RotationX(T v) noexcept {
	return { (T)cos(v / 2),(T)sin(v / 2),0,0 };
}
template<Quantity T>
inline Quaternion<T> RotationY(T v) noexcept {
	return { (T)cos(v / 2),0,(T)sin(v / 2),0 };
}
template<Quantity T>
inline Quaternion<T> RotationZ(T v) noexcept {
	return { (T)cos(v / 2),0,0,(T)sin(v / 2) };
}
template<Quantity T>
inline Quaternion<T> RotationAxis(T r, const Vector3<T>& axis) noexcept {
	Vector3<T> a = axis.Normal();
	return { (T)cos(r / 2),a.x * (T)sin(r / 2),a.y * (T)sin(r / 2),a.z * (T)sin(r / 2) };
}
template<Quantity T>
inline Quaternion<T> Rotation(const Vector3<T>& angles, RotationOrder order) noexcept {
	T x = angles.x, y = angles.y, z = angles.z;
	switch (order) {
	case RotationOrder::XYZ:
		return RotationZ(z) * RotationY(y) * RotationX(x);
	case RotationOrder::XZY:
		return RotationY(y) * RotationZ(z) * RotationX(x);
	case RotationOrder::YXZ:
		return RotationZ(z) * RotationX(x) * RotationY(y);
	case RotationOrder::YZX:
		return RotationX(x) * RotationZ(z) * RotationY(y);
	case RotationOrder::ZXY:
		return RotationY(y) * RotationX(x) * RotationZ(z);
	case RotationOrder::ZYX:
		return RotationX(x) * RotationY(y) * RotationZ(z);
	}
}
template<Quantity T>
inline Quaternion<T> LookAt(const Vector3<T>& position) noexcept {
	T x = position.x, y = position.y, z = position.z;
	T thetaY = atan2(x, z);
	T thetaX = atan2(y, sqrt(x * x + z * z));
	return RotationX(thetaY) * RotationY(thetaX);
}

STAMP_MATH_QUATERNION_NAMESPACE_END
STAMP_MATH_NAMESPACE_BEGIN


template<Quantity T>
inline Quaternion<T> conjugate(const Quaternion<T>& q) noexcept {
	return { q.x, -q.i, -q.j, -q.k };
}
template<Quantity T>
inline T norm(const Quaternion<T>& q) noexcept {
	return sqrtf(norm2(q));
}

template<Quantity T>
inline T norm2(const Quaternion<T>& q) noexcept {
	return q.x * q.x + q.i * q.i + q.j * q.j + q.k * q.k;
}
template<Quantity T>
inline Quaternion<T> unit(const Quaternion<T>& q) noexcept {
	return q / norm(q);
}
template<Quantity T>
inline Quaternion<T> inverse(const Quaternion<T>& q) noexcept {
	return conjugate(q) * (1 / norm2(q));
}
#ifdef STAMP_MATH_QUATERNION_SHORT_NAMES
template<Quantity T>
inline Quaternion<T> conj(const Quaternion<T>& q) noexcept {
	return conjugate(q);
}
template<Quantity T>
inline Quaternion<T> inv(const Quaternion<T>& q) noexcept {
	return inverse(q);
}
#endif

template<Quantity T>
inline Quaternion<bool> equal_aprox(const Quaternion<T>& a, const Quaternion<T>& b) {
	return Quaternion<bool>(equal_aprox(a.x, b.x), equal_aprox(a.i, b.i), equal_aprox(a.j, b.j), equal_aprox(a.k, b.k));
}
#if defined(STAMP_MATH_ALGORITHM_SHORT_NAMES) || defined(STAMP_MATH_QUATERNION_SHORT_NAMES)
template <Quantity T> inline Quaternion<bool>	eq_e(const Quaternion<T>& a, const Quaternion<T>& b) {
	return equal_aprox(a, b);
}}
#endif

#ifdef STAMP_IOSTREAM_HEADER_INCLUDED
template<STAMP_MATH_NAMESPACE::Quantity T>
inline std::ostream& operator<<(std::ostream& stream, const STAMP_MATH_NAMESPACE::Quaternion<T>& v) {
	return stream << "(" << v.x << "+" << v.i << "i+" << v.j << "j+" << v.k << "k)";
}
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template<STAMP_MATH_NAMESPACE::Quantity T>
inline std::string to_string(const STAMP_MATH_NAMESPACE::Quaternion<T>& v) {
	return std::string("(") + v.x + "+" + v.i + "i+" + v.j + "j+" + v.k + "k)";
}
#endif

template<Quantity T> inline const Quaternion<T> Quaternion<T>::IDENTITY = Quaternion<T>(1, 0, 0, 0);

STAMP_MATH_NAMESPACE_END

#endif