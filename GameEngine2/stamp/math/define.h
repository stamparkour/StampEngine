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

#include <exception>
#include <initializer_list>
#include <cmath>
#include <utility>
#include <algorithm>
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

#define STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE, TYPE2, TEMPLATE) \
TEMPLATE TYPE	operator	+	(const TYPE& a, TYPE2 b)	noexcept { return a + static_cast<TYPE>(b); } \
TEMPLATE TYPE&	operator	+=	(TYPE& a, TYPE2 b)			noexcept { return a += static_cast<TYPE>(b); } \
TEMPLATE TYPE	operator	-	(const TYPE& a, TYPE2 b)	noexcept { return a - static_cast<TYPE>(b); } \
TEMPLATE TYPE&	operator	-=	(TYPE& a, TYPE2 b)			noexcept { return a -= static_cast<TYPE>(b); } \
TEMPLATE TYPE	operator	*	(const TYPE& a, TYPE2 b)	noexcept { return a * static_cast<TYPE>(b); } \
TEMPLATE TYPE&	operator	*=	(TYPE& a, TYPE2 b)			noexcept { return a *= static_cast<TYPE>(b); } \
TEMPLATE TYPE	operator	/	(const TYPE& a, TYPE2 b)	noexcept { return a / static_cast<TYPE>(b); } \
TEMPLATE TYPE&	operator	/=	(TYPE& a, TYPE2 b)			noexcept { return a /= static_cast<TYPE>(b); } \
TEMPLATE TYPE	operator	+	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) + b; } \
TEMPLATE TYPE	operator	-	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) - b; } \
TEMPLATE TYPE	operator	*	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) * b; } \
TEMPLATE TYPE	operator	/	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) / b; }
#define STAMP_OPERATOR_ALL_QUANTITY(TYPE) STAMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE<T>, T, template<Quantity T>)


#define STAMP_COMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE, TYPE1, TYPE2, TEMPLATE) \
TEMPLATE TYPE1	operator	==	(const TYPE& a, TYPE2 b)	noexcept { return a == static_cast<TYPE>(b); } \
TEMPLATE bool	operator	!=	(const TYPE& a, TYPE2 b)	noexcept { return a != static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	>	(const TYPE& a, TYPE2 b)	noexcept { return a > static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	<	(const TYPE& a, TYPE2 b)	noexcept { return a < static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	>=	(const TYPE& a, TYPE2 b)	noexcept { return a >= static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	<=	(const TYPE& a, TYPE2 b)	noexcept { return a <= static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	&&	(const TYPE& a, TYPE2 b)	noexcept { return a && static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	||	(const TYPE& a, TYPE2 b)	noexcept { return a || static_cast<TYPE>(b); } \
TEMPLATE TYPE1	operator	==	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) == b; } \
TEMPLATE bool	operator	!=	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) != b; } \
TEMPLATE TYPE1	operator	>	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) > b; } \
TEMPLATE TYPE1	operator	<	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) < b; } \
TEMPLATE TYPE1	operator	>=	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) >= b; } \
TEMPLATE TYPE1	operator	<=	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) <= b; } \
TEMPLATE TYPE1	operator	&&	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) && b; } \
TEMPLATE TYPE1	operator	||	(TYPE2 a, const TYPE& b)	noexcept { return static_cast<TYPE>(a) || b; }
#define STAMP_COMP_OPERATOR_ALL_QUANTITY(TYPE) STAMP_COMP_OPERATOR_ALL_QUANTITY_TEMPLATED(TYPE<T>, TYPE<bool>, T, template<Quantity T>)

#define STAMP_MATHCONST_NAMESPACE				STAMP_NAMESPACE::mathconst
#define STAMP_MATHCONST_NAMESPACE_BEGIN			namespace STAMP_MATHCONST_NAMESPACE {
#define STAMP_MATHCONST_NAMESPACE_END			}

#define STAMP_MATH_NAMESPACE					STAMP_NAMESPACE::math
#define STAMP_MATH_NAMESPACE_BEGIN				namespace STAMP_MATH_NAMESPACE {
#define STAMP_MATH_NAMESPACE_END				}

#define STAMP_MATH_MATRIX_NAMESPACE				STAMP_MATH_NAMESPACE::matrix
#define STAMP_MATH_MATRIX_NAMESPACE_BEGIN		namespace STAMP_MATH_MATRIX_NAMESPACE {
#define STAMP_MATH_MATRIX_NAMESPACE_END			}

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
concept Quantity = requires(T a, T b) {
	a = b;
	a + b; a - b; a* b; a / b;
	a += b; a -= b; a *= b; a /= b;
	a == b; a != b;
	a < b; a > b; a <= b; a >= b;
};

enum struct RotationOrder {
	XYZ,
	XZY,
	YXZ,
	YZX,
	ZXY,
	ZYX
};

template<Quantity T> bool equal_aprox(T a, T b);

#ifdef STAMP_MATH_ALGORITHM_SHORT_NAMES
template<Quantity T> bool eq_e(T a, T b);
#endif

//Definitions

template<Quantity T> inline bool equal_aprox(T a, T b) {
	return abs(a - b) < std::numeric_limits<T>::epsilon;
}
#ifdef STAMP_MATH_ALGORITHM_SHORT_NAMES
template<Quantity T> inline bool eq_e(T a, T b) {
	return equal_aprox(a, b);
}
#endif

STAMP_MATH_NAMESPACE_END

#endif