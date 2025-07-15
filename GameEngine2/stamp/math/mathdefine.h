#pragma once
#ifndef STAMP_MATHDEFINE_H
#define STAMP_MATHDEFINE_H

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

#include <stamp/define.h>

#define STAMPENGINE_MATHCONST_NAMESPACE			STAMPENGINE_NAMESPACE::mathconst
#define STAMPENGINE_MATHCONST_NAMESPACE_BEGIN	namespace STAMPENGINE_MATHCONST_NAMESPACE {
#define STAMPENGINE_MATHCONST_NAMESPACE_END		}
#define STAMPENGINE_MATH_NAMESPACE				STAMPENGINE_NAMESPACE::math
#define STAMPENGINE_MATH_NAMESPACE_BEGIN		namespace STAMPENGINE_MATH_NAMESPACE {
#define STAMPENGINE_MATH_NAMESPACE_END			}


STAMPENGINE_MATHCONST_NAMESPACE_BEGIN

constexpr double PI			= 3.141592653589793;
constexpr double TAU		= 2 * PI;
constexpr double DEGTORAD	= PI / 180;
constexpr double RADTODEG	= 180 / PI;
constexpr double E			= 2.718281828459045;

STAMPENGINE_MATHCONST_NAMESPACE_END



STAMPENGINE_MATH_NAMESPACE_BEGIN

template<typename T>
concept Quantity = requires(T a, T b) {
	a = b;
	a + b;
	a - b;
	a * b;
	a / b;
	a += b;
	a -= b;
	a *= b;
	a /= b;
	a == b;
	a != b;
	a < b;
	a > b;
};

STAMPENGINE_MATH_NAMESPACE_END

#endif