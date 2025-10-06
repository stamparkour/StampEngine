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

STAMP_MATH_NAMESPACE_BEGIN

template<Quantity T = STAMP_DEFAULT_FLOATINGPOINT>
struct Rect;

STAMP_TEMPLATE_ALL_QUANTITY(Rect);

template<Quantity T>
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
			T left;
			T top;
			T right;
			T bottom;
		};
		struct {
			Vector2<T> min;
			Vector2<T> max;
		};
	};

	Rect() : A(), B() {}
	Rect(Vector2<T> A) : A(A), B() {}
	Rect(Vector2<T> A, Vector2<T> B) : A(A), B(B) {}
	Rect(T left, T top, T right, T bottom) : A({ left, top }), B({right, bottom }) {}
};

STAMP_MATH_NAMESPACE_END

#endif