//stamp/math/rect.h

#pragma once
#ifndef STAMP_MATH_RECT_H
#define STAMP_MATH_RECT_H

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

#include <stamp/math/define.h>
#include <stamp/math/vector.h>
#include <stamp/math/matrix.h>

STAMP_MATH_NAMESPACE_BEGIN

template<typename T = STAMP_DEFAULT_FLOATINGPOINT>
struct Rect;

STAMP_TEMPLATE_ALL_QUANTITY(Rect);

template<typename T>
struct Rect {
	union {
		struct {
			Vector2<T> A;
			Vector2<T> B;
		};
		struct {
			Vector2<T> topLeft;
			Vector2<T> bottomRight;
		};
		struct {
			Vector2<T> min;
			Vector2<T> max;
		};
		struct {
			T left;
			T top;
			T right;
			T bottom;
		};
		T V[4];
	};

	Rect() : A(), B() {}
	Rect(T v) : A(v), B(v) {}
	Rect(Vector2<T> A) : A(A), B() {}
	Rect(Vector2<T> A, Vector2<T> B) : A(A), B(B) {}
	Rect(T left, T top, T right, T bottom) : A({ left, top }), B({right, bottom }) {}

	Vector2<T> Size() const noexcept { return B - A; }
};

template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Rect<TR>	operator	+	(const Rect<T1>& a, const Rect<T2>& b)		noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Rect<TR>	operator	-	(const Rect<T1>& a, const Rect<T2>& b)		noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Rect<TR>	operator	*	(const Rect<T1>& a, const Rect<T2>& b)		noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Rect<TR>	operator	*	(const Matrix3<T1>& a, const Rect<T2>& b)	noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Rect<TR>	operator	*	(const Rect<T1>& a, const Matrix3<T2>& b)	noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	Rect<TR>	operator	/	(const Rect<T1>& a, const Rect<T2>& b)		noexcept;
template <typename T1, typename T2>	Rect<T1>& operator	+=	(Rect<T1>& a, const Rect<T2>& b)	noexcept;
template <typename T1, typename T2>	Rect<T1>& operator	-=	(Rect<T1>& a, const Rect<T2>& b)	noexcept;
template <typename T1, typename T2>	Rect<T1>& operator	*=	(Rect<T1>& a, const Rect<T2>& b)	noexcept;
template <typename T1, typename T2>	Rect<T1>& operator	/=	(Rect<T1>& a, const Rect<T2>& b)	noexcept;

STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(Rect<T1>, T2, Rect<T2>, Rect<TR>, template <typename T1 COMMA typename T2>, template <typename T1 COMMA typename T2 COMMA typename TR = std::common_type_t<T1 COMMA T2>>);

template<Field T>
bool RectCollide(const Rect<T>& a, const Rect<T>& b) noexcept;

#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <typename T> std::ostream& operator <<(std::ostream& stream, const Rect<T>& v);
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template <typename T> std::string to_string(const Rect<T>& v);
#endif

// Definitions

template<typename T1, typename T2, typename TR>
inline Rect<TR> operator+(const Rect<T1>& a, const Rect<T2>& b) noexcept {
	Rect<TR> o;
	o.A = a.A + b.A;
	o.B = a.B + b.B;
	return o;
}
template<typename T1, typename T2, typename TR>
inline Rect<TR> operator-(const Rect<T1>& a, const Rect<T2>& b) noexcept {
	Rect<TR> o;
	o.A = a.A - b.A;
	o.B = a.B - b.B;
	return o;
}
template<typename T1, typename T2, typename TR>
inline Rect<TR> operator*(const Rect<T1>& a, const Rect<T2>& b) noexcept {
	Rect<TR> o{};
	o.A = a.A * b.A;
	o.B = a.B * b.B;
	return o;
}
template<typename T1, typename T2, typename TR>
inline Rect<TR> operator*(const Matrix3<T1>& a, const Rect<T2>& b) noexcept {
	Rect<TR> o;
	o.A = static_cast<Vector2<TR>>(a * Vector3<T2>{b.A, 1});
	o.B = static_cast<Vector2<TR>>(a * Vector3<T2>{b.B, 1});
	return o;
}
template<typename T1, typename T2, typename TR>
inline Rect<TR> operator*(const Rect<T1>& a, const Matrix3<T2>& b) noexcept {
	Rect<TR> o;
	o.A = static_cast<Vector2<TR>>(Vector3<T2>{a.A, 1} * b);
	o.B = static_cast<Vector2<TR>>(Vector3<T2>{a.B, 1} * b);
	return o;
}
template<typename T1, typename T2, typename TR>
inline Rect<TR> operator/(const Rect<T1>& a, const Rect<T2>& b) noexcept {
	Rect<TR> o;
	o.A = a.A / b.A;
	o.B = a.B / b.B;
	return o;
}
template<typename T1, typename T2>
inline Rect<T1>& operator+=(Rect<T1>& a, const Rect<T2>& b) noexcept {
	a.A += b.A;
	a.B += b.B;
	return a;
}
template<typename T1, typename T2>
inline Rect<T1>& operator-=(Rect<T1>& a, const Rect<T2>& b) noexcept {
	a.A -= b.A;
	a.B -= b.B;
	return a;
}
template<typename T1, typename T2>
inline Rect<T1>& operator*=(Rect<T1>& a, const Rect<T2>& b) noexcept {
	a.A *= b.A;
	a.B *= b.B;
	return a;
}
template<typename T1, typename T2>
inline Rect<T1>& operator/=(Rect<T1>& a, const Rect<T2>& b) noexcept {
	a.A /= b.A;
	a.B /= b.B;
	return a;
}

#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <typename T>
inline std::ostream& operator <<(std::ostream& stream, const Rect<T>& v) {
	stream << "Rect(";
	stream << v.A << ", " << v.B;
	stream << ")";
	return stream;
}
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template <typename T>
inline std::string to_string(const Rect<T>& v) {
	std::string result = "Rect(";
	result += to_string(v.A) + ", " + to_string(v.B);
	result += ")";
	return result;
}
#endif

template<Field T>
inline bool RectCollide(const Rect<T>& a, const Rect<T>& b) noexcept {
	return (a.left < b.right) && (a.right > b.left) && (a.top < b.bottom) && (a.bottom > b.top);
}

STAMP_MATH_NAMESPACE_END

#endif