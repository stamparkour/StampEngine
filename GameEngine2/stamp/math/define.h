//stamp/math/define.h

#pragma once
#ifndef STAMP_MATH_DEFINE_H
#define STAMP_MATH_DEFINE_H

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

// provides short names for all math headers
// #define STAMP_MATH_ALL_SHORT_NAMES

#include <initializer_list>
#include <cmath>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <concepts>
#include <stamp/define.h>

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif
#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif
#define STAMP_DEFAULT_ROTATION_ORDER RotationOrder::ZXY
#define STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(T, TEMPLATE, ARGS) \
	TEMPLATE using T##b = T<bool ARGS>;					\
	TEMPLATE using T##uc = T<unsigned char ARGS>;		\
	TEMPLATE using T##c = T<char ARGS>;					\
	TEMPLATE using T##us = T<unsigned short ARGS>;		\
	TEMPLATE using T##s = T<short ARGS>;				\
	TEMPLATE using T##ui = T<unsigned int ARGS>;		\
	TEMPLATE using T##i = T<int ARGS>;					\
	TEMPLATE using T##ul = T<unsigned long ARGS>;		\
	TEMPLATE using T##l = T<long ARGS>;					\
	TEMPLATE using T##ull = T<unsigned long long ARGS>;	\
	TEMPLATE using T##ll = T<long long ARGS>;			\
	TEMPLATE using T##f = T<float ARGS>;				\
	TEMPLATE using T##d = T<double ARGS>;				\
	TEMPLATE using T##ld = T<long double ARGS>
#define STAMP_TEMPLATE_ALL_QUANTITY(T) STAMP_TEMPLATE_ALL_QUANTITY_TEMPLATED(T,,)

#define STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE_CLASS, TYPE_OTHER, TYPE_CAST, TYPE_RETURN, TEMPLATE_ASSIGNMENT, TEMPLATE) \
TEMPLATE TYPE_RETURN			operator	+	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a + static_cast<TYPE_CAST>(b); } \
TEMPLATE TYPE_RETURN			operator	-	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a - static_cast<TYPE_CAST>(b); } \
TEMPLATE TYPE_RETURN			operator	*	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a * static_cast<TYPE_CAST>(b); } \
TEMPLATE TYPE_RETURN			operator	/	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a / static_cast<TYPE_CAST>(b); } \
TEMPLATE TYPE_RETURN			operator	+	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_CAST>(a) + b; } \
TEMPLATE TYPE_RETURN			operator	-	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_CAST>(a) - b; } \
TEMPLATE TYPE_RETURN			operator	*	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_CAST>(a) * b; } \
TEMPLATE TYPE_RETURN			operator	/	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_CAST>(a) / b; } \
TEMPLATE_ASSIGNMENT TYPE_CLASS& operator	+=	(TYPE_CLASS& a, TYPE_OTHER b)		noexcept { return a += static_cast<TYPE_CAST>(b); } \
TEMPLATE_ASSIGNMENT TYPE_CLASS& operator	-=	(TYPE_CLASS& a, TYPE_OTHER b)		noexcept { return a -= static_cast<TYPE_CAST>(b); } \
TEMPLATE_ASSIGNMENT TYPE_CLASS& operator	*=	(TYPE_CLASS& a, TYPE_OTHER b)		noexcept { return a *= static_cast<TYPE_CAST>(b); } \
TEMPLATE_ASSIGNMENT TYPE_CLASS& operator	/=	(TYPE_CLASS& a, TYPE_OTHER b)		noexcept { return a /= static_cast<TYPE_CAST>(b); }
#define STAMP_OPERATOR_ALL_QUANTITY(TYPE) STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE<T1>, T2, TYPE<T2>, TYPE<TR>, template<typename T1 COMMA typename T2>, template<typename T1 COMMA typename T2 COMMA typename TR = std::common_type_t<T1 COMMA T2>>)


#define STAMP_COMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE_CLASS, TYPE_OTHER, TYPE_COMPARE, TYPE_RETURN, TEMPLATE) \
TEMPLATE TYPE_RETURN	operator	==	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a == static_cast<TYPE_COMPARE>(b); } \
TEMPLATE bool			operator	!=	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a != static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	>	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a > static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	<	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a < static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	>=	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a >= static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	<=	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a <= static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	&&	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a && static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	||	(const TYPE_CLASS& a, TYPE_OTHER b)	noexcept { return a || static_cast<TYPE_COMPARE>(b); } \
TEMPLATE TYPE_RETURN	operator	==	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) == b; } \
TEMPLATE bool			operator	!=	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) != b; } \
TEMPLATE TYPE_RETURN	operator	>	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) > b; } \
TEMPLATE TYPE_RETURN	operator	<	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) < b; } \
TEMPLATE TYPE_RETURN	operator	>=	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) >= b; } \
TEMPLATE TYPE_RETURN	operator	<=	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) <= b; } \
TEMPLATE TYPE_RETURN	operator	&&	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) && b; } \
TEMPLATE TYPE_RETURN	operator	||	(TYPE_OTHER a, const TYPE_CLASS& b)	noexcept { return static_cast<TYPE_COMPARE>(a) || b; }
#define STAMP_COMP_OPERATOR_ALL_QUANTITY(TYPE) STAMP_COMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE<T1>, T2, TYPE<T2>, TYPE<bool>, template<typename T1, typename T2>)

#define STAMP_MATHCONST_NAMESPACE				STAMP_NAMESPACE::mathconst
#define STAMP_MATHCONST_NAMESPACE_BEGIN			namespace STAMP_MATHCONST_NAMESPACE {
#define STAMP_MATHCONST_NAMESPACE_END			}

#define STAMP_MATH_NAMESPACE					STAMP_NAMESPACE::math
#define STAMP_MATH_NAMESPACE_BEGIN				namespace STAMP_MATH_NAMESPACE {
#define STAMP_MATH_NAMESPACE_END				}

#define STAMP_MATH_MATRIX4_NAMESPACE			STAMP_MATH_NAMESPACE::matrix4
#define STAMP_MATH_MATRIX4_NAMESPACE_BEGIN		namespace STAMP_MATH_MATRIX4_NAMESPACE {
#define STAMP_MATH_MATRIX4_NAMESPACE_END		}

#define STAMP_MATH_MATRIX3_NAMESPACE			STAMP_MATH_NAMESPACE::matrix3
#define STAMP_MATH_MATRIX3_NAMESPACE_BEGIN		namespace STAMP_MATH_MATRIX3_NAMESPACE {
#define STAMP_MATH_MATRIX3_NAMESPACE_END		}

#define STAMP_MATH_QUATERNION_NAMESPACE			STAMP_MATH_NAMESPACE::quat
#define STAMP_MATH_QUATERNION_NAMESPACE_BEGIN	namespace STAMP_MATH_QUATERNION_NAMESPACE {
#define STAMP_MATH_QUATERNION_NAMESPACE_END		}

#define STAMP_MATH_VECTOR_NAMESPACE				STAMP_MATH_NAMESPACE::vector
#define STAMP_MATH_VECTOR_NAMESPACE_BEGIN		namespace STAMP_MATH_VECTOR_NAMESPACE {
#define STAMP_MATH_VECTOR_NAMESPACE_END			}

#ifdef STAMP_MATH_ALL_SHORT_NAMES
#define STAMP_MATH_VECTOR_SHORT_NAMES
#define STAMP_MATH_QUATERNION_SHORT_NAMES
#define STAMP_MATH_ALGORITHM_SHORT_NAMES
#define STAMP_MATH_MATRIX_SHORT_NAMES
#endif



STAMP_MATHCONST_NAMESPACE_BEGIN

constexpr double PI = 3.141592653589793;
constexpr double TAU = 2 * PI;
constexpr double DEGTORAD = PI / 180;
constexpr double RADTODEG = 180 / PI;
constexpr double E = 2.718281828459045;

STAMP_MATHCONST_NAMESPACE_END
STAMP_MATH_NAMESPACE_BEGIN


template<typename T>
concept Field = requires(T a, T b) {
	{ a = b }  -> std::same_as<T&>;
	{ a + b }  -> std::convertible_to<T>;
	{ a - b }  -> std::convertible_to<T>;
	{ a * b }  -> std::convertible_to<T>;
	{ a / b }  -> std::convertible_to<T>;
	{ a += b } -> std::same_as<T&>;
	{ a -= b } -> std::same_as<T&>;
	{ a *= b } -> std::same_as<T&>;
	{ a /= b } -> std::same_as<T&>;
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
	{ a < b }  -> std::convertible_to<bool>;
	{ a > b }  -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;
};

enum struct RotationOrder {
	XYZ,
	XZY,
	YXZ,
	YZX,
	ZXY,
	ZYX
};

//Definitions

template<typename T1, typename T2> inline bool equal_aprox(T1 a, T2 b) requires requires(T1 a, T2 b) { a.equal_aprox(b); } {
	return a.equal_aprox(b);
}
template<::std::integral T1, ::std::integral T2> inline bool equal_aprox(T1 a, T2 b) {
	return a == b;
}
template<::std::floating_point T1, ::std::floating_point T2> inline bool equal_aprox(T1 a, T2 b) {
	return abs(a - b) < abs(std::nextafter(a, b));
}
#ifdef STAMP_MATH_ALGORITHM_SHORT_NAMES
template<typename T1, typename T2> inline bool eq_e(T a, T b) {
	return equal_aprox(a, b);
}
#endif

STAMP_MATH_NAMESPACE_END

#endif