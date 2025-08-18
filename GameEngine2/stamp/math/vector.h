//stamp/math/vector.h

#pragma once
#ifndef STAMP_MATH_VECTOR_H
#define STAMP_MATH_VECTOR_H

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
// #define STAMP_MATH_VECTOR_SHORT_NAMES

// makes all comparison operators prefer equal_aprox
// #define STAMP_MATH_VECTOR_EQUAL_APROX

//optional headers: <iostream> <string>
#include <stamp/math/define.h>


STAMP_MATH_NAMESPACE_BEGIN

template<Quantity T = STAMP_DEFAULT_FLOATINGPOINT, size_t D = 2>
struct Vector;
STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(Vector, template<size_t D = 2>, COMMA D);

template <Quantity T>
using Vector2 = Vector<T, 2>;
template <Quantity T>
using Vector3 = Vector<T, 3>;
template <Quantity T>
using Vector4 = Vector<T, 4>;

STAMP_TEMPLATE_ALL_QUANTITY(Vector2);
STAMP_TEMPLATE_ALL_QUANTITY(Vector3);
STAMP_TEMPLATE_ALL_QUANTITY(Vector4);

#ifdef STAMP_MATH_VECTOR_SHORT_NAMES
template <Quantity T = STAMP_DEFAULT_FLOATINGPOINT>
using Vec2 = Vector2<T>;
STAMP_TEMPLATE_ALL_QUANTITY(Vec2);

template <Quantity T = STAMP_DEFAULT_FLOATINGPOINT>
using Vec3 = Vector2<T>;
STAMP_TEMPLATE_ALL_QUANTITY(Vec3);

template <Quantity T = STAMP_DEFAULT_FLOATINGPOINT>
using Vec4 = Vector2<T>;
STAMP_TEMPLATE_ALL_QUANTITY(Vec4);
#endif

template<typename V, typename T, size_t D>
struct Vector_Base {
	template<Quantity T1, size_t D1> explicit operator Vector<T1, D1>() const noexcept;
	explicit operator const T* () const noexcept;
	explicit operator T* () noexcept;
	explicit operator bool() const noexcept;
};

template<Quantity T, size_t D>
struct Vector final : public Vector_Base<Vector<T, D>, T, D> {
	using member_type = T;
	constexpr static size_t dimensions = D;

	T V[D] = {};
	Vector() noexcept {}
	Vector(T x) noexcept {
		for (int i = 0; i < dimensions; i++) V[i] = x;
	}
};



template <Quantity T>
struct Vector<T, 2> final : public Vector_Base<Vector<T, 2>, T, 2> {
	using member_type = T;
	constexpr static size_t dimensions = 2;

	union {
		T V[2] = {};
		struct { T x, y; };
	};

	Vector() noexcept {}
	Vector(T x) noexcept : x(x), y(x) {}
	Vector(T x, T y)	noexcept : x(x), y(y) {}

	const static Vector2<T> UNIT;
	const static Vector2<T> UP;
	const static Vector2<T> DOWN;
	const static Vector2<T> RIGHT;
	const static Vector2<T> LEFT;
};

template <Quantity T>
struct Vector<T, 3> final : public Vector_Base<Vector<T, 3>, T, 3> {
	using member_type = T;
	constexpr static size_t dimensions = 3;
	union {
		T V[3] = {};
		struct { T x, y, z; };
	};

	Vector() noexcept {}
	Vector(T x) noexcept : x(x), y(x), z(x) {}
	Vector(T x, T y, T z)				noexcept : x(x),	y(y),	z(z) {}
	Vector(const Vector2<T>& a, T z)	noexcept : x(a.x),	y(a.y),	z(z) {}
	Vector(T x, const Vector2<T>& a)	noexcept : x(x),	y(a.x),	z(a.y) {}

	const static Vector3<T> UNIT;
	const static Vector3<T> UP;
	const static Vector3<T> DOWN;
	const static Vector3<T> RIGHT;
	const static Vector3<T> LEFT;
	const static Vector3<T> FORWARD;
	const static Vector3<T> BACK;
};

template <Quantity T>
struct Vector<T, 4> final : public Vector_Base<Vector<T, 4>, T, 4> {
	using member_type = T;
	constexpr static size_t dimensions = 4;
	union {
		T V[4] = {};
		struct { T x, y, z, w; };
	};

	Vector() noexcept {}
	Vector(T x) noexcept : x(x), y(x), z(x), w(x) {}
	Vector(T x, T y)									noexcept :	x(x),	y(y),	z(x),	w(y) {}
	Vector(T x, T y, T z, T w)							noexcept :	x(x),	y(y),	z(z),	w(w) {}
	Vector(const Vector2<T>& a, T z, T w)				noexcept :	x(a.x),	y(a.y),	z(z),	w(w) {}
	Vector(T x, const Vector2<T>& a, T w)				noexcept :	x(x),	y(a.x),	z(a.y), w(w) {}
	Vector(T x, T y, const Vector2<T>& a)				noexcept :	x(x),	y(y),	z(a.x),	w(a.y) {}
	Vector(const Vector2<T>& a, const Vector2<T>& b)	noexcept :	x(a.x),	y(a.y), z(b.x), w(b.y) {}
	Vector(const Vector3<T>& a, T w)					noexcept :	x(a.x),	y(a.y),	z(a.z),	w(w) {}
	Vector(T x, const Vector3<T>& a)					noexcept :	x(x),	y(a.x),	z(a.y),	w(a.z) {}

	const static Vector4<T> UNIT;
	const static Vector4<T> UP;
	const static Vector4<T> DOWN;
	const static Vector4<T> RIGHT;
	const static Vector4<T> LEFT;
	const static Vector4<T> FORWARD;
	const static Vector4<T> BACK;
	const static Vector4<T> ANA;
	const static Vector4<T> KANA;
};


template <Quantity T, size_t D>	Vector<T, D>	operator	+	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>&	operator	+=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>	operator	-	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>&	operator	-=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>	operator	*	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>&	operator	*=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>	operator	/	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>&	operator	/=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	==	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	bool			operator	!=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	>	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	<	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	>=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	<=	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	&&	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	||	(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
template <Quantity T, size_t D>	Vector<T, D>	operator	-	(const Vector<T, D>& v)							noexcept;
template <Quantity T, size_t D>	Vector<bool, D>	operator	~	(const Vector<T, D>& v)							noexcept;
template <Quantity T, size_t D>	bool			operator	!	(const Vector<T, D>& v)							noexcept;


STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(Vector<T COMMA D>, T, template <Quantity T COMMA size_t D>);
STAMP_COMP_OPERATOR_ALL_QUANTITY_TEMPLATED(Vector<T COMMA D>, Vector<bool COMMA D>, T, template <Quantity T COMMA size_t D>);

template <Quantity T> T 						cross		(const Vector2<T>& a, const Vector2<T>& b)		noexcept;
template <Quantity T> Vector3<T>				cross		(const Vector3<T>& a, const Vector3<T>& b)		noexcept;
template <Quantity T, size_t D> bool			_and		(const Vector<T, D>& v) 						noexcept;
template <Quantity T, size_t D> bool			_or			(const Vector<T, D>& v) 						noexcept;
template <Quantity T, size_t D> T				summation	(const Vector<T, D>& v) 						noexcept;
template <Quantity T, size_t D> T 				magnitude	(const Vector<T, D>& v)							noexcept;
template <Quantity T, size_t D> T 				magnitude2	(const Vector<T, D>& v) 						noexcept;
template <Quantity T, size_t D> Vector<T, D>	normal		(const Vector<T, D>& v) 						noexcept;
template <Quantity T, size_t D> T				dot			(const Vector<T, D>& a, const Vector<T, D>& b)	noexcept;
#ifdef STAMP_MATH_VECTOR_SHORT_NAMES
template <Quantity T, size_t D> T				sum(const Vector<T, D>& v)	noexcept;
template <Quantity T, size_t D> T 				mag(const Vector<T, D>& v)	noexcept;
template <Quantity T, size_t D> T 				mag2(const Vector<T, D>& v)	noexcept;
template <Quantity T, size_t D> Vector<T, D>	norm(const Vector<T, D>& v)	noexcept;
#endif

template <Quantity T, size_t D> Vector<bool, D>	equal_aprox(const Vector<T, D>& a, const Vector<T, D>& b);

#if defined(STAMP_MATH_ALGORITHM_SHORT_NAMES) || defined(STAMP_MATH_VECTOR_SHORT_NAMES)
template <Quantity T, size_t D> Vector<bool, D> eq_e(const Vector<T, D>& a, const Vector<T, D>& b);
#endif
#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <Quantity T, size_t D> std::ostream& operator <<(std::ostream& stream, const Vector<T, D>& v);
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template <Quantity T, size_t D, typename S> std::basic_string<S> to_string(const Vector<T, D>& v);
#endif

// Definitions

//----------- Vector Base Logic ----------

template<typename V, typename T, size_t D>
template<Quantity T1, size_t D1> 
inline Vector_Base<V, T, D>::operator Vector<T1, D1>() const noexcept {
	auto self = static_cast<const V*>(this);
	Vector<T1, D1> o;
	for (size_t i = 0; i < D1; ++i)
		o.V[i] = (i < V::dimensions ? static_cast<T1>(self->V[i]) : 0);
	return o;
}
template<typename V, typename T, size_t D>
inline Vector_Base<V, T, D>::operator const T* () const noexcept {
	auto self = static_cast<const V*>(this);
	return &self->V;
}
template<typename V, typename T, size_t D>
inline Vector_Base<V, T, D>::operator T* () noexcept {
	auto self = static_cast<V*>(this);
	return &self->V;
}
template<typename V, typename T, size_t D>
inline Vector_Base<V, T, D>::operator bool() const noexcept {
	auto self = static_cast<const V*>(this);
	for (size_t i = 0; i < D; ++i) if (!self->V[i]) return false; return true;
}
// ------------ Generic Logic ------------
template<Quantity T, size_t D>
inline Vector<T, D> operator+(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<T, D> o;
	for(size_t i = 0; i < D; ++i) o.V[i] = a.V[i] + b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<T, D>& operator+=(Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return a = a + b;
}
template<Quantity T, size_t D>
inline Vector<T, D> operator-(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<T, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] - b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<T, D>& operator-=(Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return a = a - b;
}
template<Quantity T, size_t D>
inline Vector<T, D> operator*(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<T, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] * b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<T, D>& operator*=(Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return a = a * b;
}
template<Quantity T, size_t D>
inline Vector<T, D> operator/(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<T, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] / b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<T, D>& operator/=(Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return a = a / b;
}
#ifdef STAMP_MATH_VECTOR_EQUAL_APROX
template<Quantity T, size_t D>
inline Vector2<bool> operator==(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return equal_aprox(*this, b);
}
#else
template<Quantity T, size_t D>
inline Vector<bool, D> operator==(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] == b.V[i];
	return o;
}
#endif
template<Quantity T, size_t D>
inline bool operator!=(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return !(a == b);
}
template<Quantity T, size_t D>
inline Vector<bool, D> operator>(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] > b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<bool, D> operator<(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] < b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<bool, D> operator>=(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] >= b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<bool, D>operator<=(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] <= b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<bool, D> operator&&(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] && b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<bool, D> operator||(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = a.V[i] || b.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<T, D> operator-(const Vector<T, D>& v) noexcept {
	Vector<T, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = -v.V[i];
	return o;
}
template<Quantity T, size_t D>
inline Vector<bool, D> operator~(const Vector<T, D>& v) noexcept {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = !v.V[i];
	return o;
}
template<Quantity T, size_t D>
inline bool operator!(const Vector<T, D>& v) noexcept {
	return _or(~v);
}

// ------------ Vector2 Logic ------------
template<Quantity T>
inline T cross(const Vector2<T>& a, const Vector2<T>& b) noexcept {
	return a.x * b.y - a.y * b.x;
}
// ------------ Vector3 Logic ------------
template<Quantity T>
inline Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b) noexcept {
	return Vector3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
// ------------ Generic Logic ------------
template <Quantity T, size_t D>
inline bool _and(const Vector<T, D>& v) noexcept {
	for (size_t i = 0; i < D; ++i) if(!v.V[i]) return false;
	return true;
}
template <Quantity T, size_t D>
inline bool _or(const Vector<T, D>& v) noexcept {
	for (size_t i = 0; i < D; ++i) if (v.V[i]) return true;
	return false;
}
template <Quantity T, size_t D>
inline T summation(const Vector<T, D>& v) noexcept {
	T sum = 0;
	for (size_t i = 0; i < D; ++i) sum += v.V[i];
	return sum;
}
template <Quantity T, size_t D>
inline Vector<T, D> normal(const Vector<T, D>& v) noexcept {
	return v / Vector<T,D>(magnitude(v));
}
template <Quantity T, size_t D>
inline T dot(const Vector<T, D>& a, const Vector<T, D>& b) noexcept {
	return summation(a * b);
}
template <Quantity T, size_t D>
inline T magnitude(const Vector<T, D>& v) noexcept {
	return (T)sqrt(magnitude2(v));
}
template <Quantity T, size_t D>
inline T magnitude2(const Vector<T, D>& v) noexcept {
	return (T)summation(v * v);
}

#ifdef STAMP_MATH_VECTOR_SHORT_NAMES
template <Quantity T, size_t D>
inline T sum(const Vector<T, D>& v) noexcept {
	return summation(v);
}
template <Quantity T, size_t D>
inline T mag(const Vector<T, D>& v) noexcept {
	return magnitude(v);
}
template <Quantity T, size_t D>
inline T mag2(const Vector<T, D>& v) noexcept {
	return magnitude2(v);
}
template <Quantity T, size_t D>
inline Vector<T, D> norm(const Vector<T, D>& v)	noexcept {
	return normal(v);
}
#endif

template <Quantity T, size_t D>
inline Vector<bool, D> equal_aprox(const Vector<T, D>& a, const Vector<T, D>& b) {
	Vector<bool, D> o;
	for (size_t i = 0; i < D; ++i) o.V[i] = equal_aprox(a.V[i], b.V[i]);
	return o;
}
#if defined(STAMP_MATH_ALGORITHM_SHORT_NAMES) || defined(STAMP_MATH_VECTOR_SHORT_NAMES)
template <Quantity T, size_t D> 
inline Vector<bool, D>	eq_e(const Vector<T, D>& a, const Vector<T, D>& b) {
	return equal_aprox(a, b);
}
#endif

#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <Quantity T, size_t D>
inline std::ostream& operator<<(std::ostream& stream, const Vector<T, D>& v) {
	stream << "(";
	for (size_t i = 0; i < D; ++i) {
		stream << v.V[i];
		if(i != D - 1) stream << ", ";
	}
	stream << ")";
	return stream;
}
#endif

#ifdef STAMP_STRING_HEADER_INCLUDED
template <Quantity T, size_t D>
inline std::string to_string_templated(const Vector<T, D>& v) {
	using namespace std;

	std::string result = "(";
	for (size_t i = 0; i < D; i++) {
		result += to_string(v.V[i]);
		if (i != D - 1) result += ", ";
	}
	result += ")";
	return result;
}
template <Quantity T, size_t D>
inline std::string to_string(const Vector<T, D>& v) {
	return to_string_templated(v);
}
#endif

template<Quantity T> inline const Vector2<T> Vector<T, 2>::UNIT = Vector2<T>(1);
template<Quantity T> inline const Vector2<T> Vector<T, 2>::UP = Vector2<T>(1, 0);
template<Quantity T> inline const Vector2<T> Vector<T, 2>::DOWN = Vector2<T>(-1, 0);
template<Quantity T> inline const Vector2<T> Vector<T, 2>::RIGHT = Vector2<T>(0, 1);
template<Quantity T> inline const Vector2<T> Vector<T, 2>::LEFT = Vector2<T>(0, -1);

template<Quantity T> inline const Vector3<T> Vector<T, 3>::UNIT = Vector3<T>(1);
template<Quantity T> inline const Vector3<T> Vector<T, 3>::UP = Vector3<T>(1, 0, 0);
template<Quantity T> inline const Vector3<T> Vector<T, 3>::DOWN = Vector3<T>(-1, 0, 0);
template<Quantity T> inline const Vector3<T> Vector<T, 3>::RIGHT = Vector3<T>(0, 1, 0);
template<Quantity T> inline const Vector3<T> Vector<T, 3>::LEFT = Vector3<T>(0, -1, 0);
template<Quantity T> inline const Vector3<T> Vector<T, 3>::FORWARD = Vector3<T>(0, 0, 1);
template<Quantity T> inline const Vector3<T> Vector<T, 3>::BACK = Vector3<T>(0, 0, -1);

template<Quantity T> inline const Vector4<T> Vector<T, 4>::UNIT = Vector4<T>(1);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::UP = Vector4<T>(1, 0, 0, 0);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::DOWN = Vector4<T>(-1, 0, 0, 0);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::RIGHT = Vector4<T>(0, 1, 0, 0);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::LEFT = Vector4<T>(0, -1, 0, 0);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::FORWARD = Vector4<T>(0, 0, 1, 0);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::BACK = Vector4<T>(0, 0, -1, 0);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::ANA = Vector4<T>(0, 0, 0, 1);
template<Quantity T> inline const Vector4<T> Vector<T, 4>::KANA = Vector4<T>(0, 0, 0, -1);

STAMP_MATH_NAMESPACE_END

#endif