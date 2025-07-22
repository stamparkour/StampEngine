#pragma once
#ifndef STAMP_MATH_ALGORITHM_H
#define STAMP_MATH_ALGORITHM_H

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


// provides short names for all functions
// #define STAMP_MATH_ALGORITHM_SHORT_NAMES

#include <stamp/getset.h>
#include <exception>
#include <initializer_list>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stamp/math/mathdefine.h>

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

STAMP_MATH_NAMESPACE_END

STAMP_MATHCONST_NAMESPACE_BEGIN

constexpr double PI = 3.141592653589793;
constexpr double TAU = 2 * PI;
constexpr double DEGTORAD = PI / 180;
constexpr double RADTODEG = 180 / PI;
constexpr double E = 2.718281828459045;

STAMP_MATHCONST_NAMESPACE_END

STAMP_MATH_NAMESPACE_BEGIN

template<Quantity T> inline bool equal_aprox(T a, T b);

#ifdef STAMP_MATH_ALGORITHM_SHORT_NAMES
template<Quantity T> inline bool eq_e(T a, T b);
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