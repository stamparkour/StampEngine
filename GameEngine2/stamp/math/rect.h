//stamp/math/rect.h

#pragma once
#ifndef STAMP_MATH_rect_H
#define STAMP_MATH_rect_H

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

template<typename T>
struct rect;

STAMP_TEMPLATE_ALL_QUANTITY(rect);

template<typename T>
struct rect {
	union {
		struct {
			vector2<T> A;
			vector2<T> B;
		};
		struct {
			vector2<T> topLeft;
			vector2<T> bottomRight;
		};
		struct {
			vector2<T> min;
			vector2<T> max;
		};
		struct {
			T left;
			T top;
			T right;
			T bottom;
		};
		T V[4];
	};

	rect() : A(), B() {}
	rect(T v) : A(v), B(v) {}
	rect(vector2<T> A) : A(A), B(A) {}
	rect(vector2<T> A, vector2<T> B) : A(A), B(B) {}
	rect(T left, T top, T right, T bottom) : A({ left, top }), B({ right, bottom }) {}
	rect(T x, T y) : A({ x, y }), B({ x, y }) {}

	vector2<T> Size() const noexcept { return B - A; }
};

template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	rect<TR>	operator	+	(const rect<T1>& a, const rect<T2>& b)		noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	rect<TR>	operator	-	(const rect<T1>& a, const rect<T2>& b)		noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	rect<TR>	operator	*	(const rect<T1>& a, const rect<T2>& b)		noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	rect<TR>	operator	*	(const Matrix3<T1>& a, const rect<T2>& b)	noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	rect<TR>	operator	*	(const rect<T1>& a, const Matrix3<T2>& b)	noexcept;
template <typename T1, typename T2, typename TR = std::common_type_t<T1, T2>>	rect<TR>	operator	/	(const rect<T1>& a, const rect<T2>& b)		noexcept;
template <typename T1, typename T2>	rect<T1>& operator	+=	(rect<T1>& a, const rect<T2>& b)	noexcept;
template <typename T1, typename T2>	rect<T1>& operator	-=	(rect<T1>& a, const rect<T2>& b)	noexcept;
template <typename T1, typename T2>	rect<T1>& operator	*=	(rect<T1>& a, const rect<T2>& b)	noexcept;
template <typename T1, typename T2>	rect<T1>& operator	/=	(rect<T1>& a, const rect<T2>& b)	noexcept;

STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(rect<T1>, vector2<T2>, rect<T2>, rect<TR>, template <typename T1 COMMA typename T2>, template <typename T1 COMMA typename T2 COMMA typename TR = std::common_type_t<T1 COMMA T2>>);
STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(rect<T1>, T2, rect<T2>, rect<TR>, template <typename T1 COMMA typename T2>, template <typename T1 COMMA typename T2 COMMA typename TR = std::common_type_t<T1 COMMA T2>>);

template<Field T>
bool rectCollide(const rect<T>& a, const rect<T>& b) noexcept;

#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <typename T> std::ostream& operator <<(std::ostream& stream, const rect<T>& v);
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template <typename T> std::string to_string(const rect<T>& v);
#endif

// Definitions

template<typename T1, typename T2, typename TR>
inline rect<TR> operator+(const rect<T1>& a, const rect<T2>& b) noexcept {
	rect<TR> o;
	o.A = a.A + b.A;
	o.B = a.B + b.B;
	return o;
}
template<typename T1, typename T2, typename TR>
inline rect<TR> operator-(const rect<T1>& a, const rect<T2>& b) noexcept {
	rect<TR> o;
	o.A = a.A - b.A;
	o.B = a.B - b.B;
	return o;
}
template<typename T1, typename T2, typename TR>
inline rect<TR> operator*(const rect<T1>& a, const rect<T2>& b) noexcept {
	rect<TR> o{};
	o.A = a.A * b.A;
	o.B = a.B * b.B;
	return o;
}
template<typename T1, typename T2, typename TR>
inline rect<TR> operator*(const Matrix3<T1>& a, const rect<T2>& b) noexcept {
	rect<TR> o;
	o.A = static_cast<vector2<TR>>(a * vector3<T2>{b.A, 1});
	o.B = static_cast<vector2<TR>>(a * vector3<T2>{b.B, 1});
	return o;
}
template<typename T1, typename T2, typename TR>
inline rect<TR> operator*(const rect<T1>& a, const Matrix3<T2>& b) noexcept {
	rect<TR> o;
	o.A = static_cast<vector2<TR>>(vector3<T2>{a.A, 1} * b);
	o.B = static_cast<vector2<TR>>(vector3<T2>{a.B, 1} * b);
	return o;
}
template<typename T1, typename T2, typename TR>
inline rect<TR> operator/(const rect<T1>& a, const rect<T2>& b) noexcept {
	rect<TR> o;
	o.A = a.A / b.A;
	o.B = a.B / b.B;
	return o;
}
template<typename T1, typename T2>
inline rect<T1>& operator+=(rect<T1>& a, const rect<T2>& b) noexcept {
	a.A += b.A;
	a.B += b.B;
	return a;
}
template<typename T1, typename T2>
inline rect<T1>& operator-=(rect<T1>& a, const rect<T2>& b) noexcept {
	a.A -= b.A;
	a.B -= b.B;
	return a;
}
template<typename T1, typename T2>
inline rect<T1>& operator*=(rect<T1>& a, const rect<T2>& b) noexcept {
	a.A *= b.A;
	a.B *= b.B;
	return a;
}
template<typename T1, typename T2>
inline rect<T1>& operator/=(rect<T1>& a, const rect<T2>& b) noexcept {
	a.A /= b.A;
	a.B /= b.B;
	return a;
}

#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <typename T>
inline std::ostream& operator <<(std::ostream& stream, const rect<T>& v) {
	stream << "rect(";
	stream << v.A << ", " << v.B;
	stream << ")";
	return stream;
}
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template <typename T>
inline std::string to_string(const rect<T>& v) {
	std::string result = "rect(";
	result += to_string(v.A) + ", " + to_string(v.B);
	result += ")";
	return result;
}
#endif

template<Field T>
inline bool rectCollide(const rect<T>& a, const rect<T>& b) noexcept {
	return (a.left < b.right) && (a.right > b.left) && (a.top < b.bottom) && (a.bottom > b.top);
}

STAMP_MATH_NAMESPACE_END

#endif