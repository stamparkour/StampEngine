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

template<Field T = STAMP_DEFAULT_FLOATINGPOINT>
struct Rect;

STAMP_TEMPLATE_ALL_QUANTITY(Rect);

template<Field T>
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

	Vector2<T> size() const noexcept { return B - A; }
};

#ifdef STAMP_OSTREAM_HEADER_INCLUDED
template <typename T> std::ostream& operator <<(std::ostream& stream, const Rect<T>& v);
#endif
#ifdef STAMP_STRING_HEADER_INCLUDED
template <typename T> std::string to_string(const Rect<T>& v);
#endif

// Definitions

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

STAMP_MATH_NAMESPACE_END

#endif