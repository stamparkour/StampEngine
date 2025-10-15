//stamp/math/alignment.h

#pragma once
#ifndef STAMP_GRAPHICS_ALIGNMENT_H
#define STAMP_GRAPHICS_ALIGNMENT_H

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
#include <stamp/math/matrix.h>
#include <stamp/math/vector.h>
#include <stamp/math/rect.h>

STAMP_MATH_NAMESPACE_BEGIN

template<Field T>
using alignment_t = Vector2<T>;

namespace alignment {
	template<Field T>
	constexpr auto TopLeft = alignment_t<T>{ -1, 1 };
	template<Field T>
	constexpr auto Top = alignment_t<T>{ 0, 1 };
	template<Field T>
	constexpr auto TopRight = alignment_t<T>{ 1, 1 };
	template<Field T>
	constexpr auto Left = alignment_t<T>{ -1, 0 };
	template<Field T>
	constexpr auto Center = alignment_t<T>{ 0, 0 };
	template<Field T>
	constexpr auto Right = alignment_t<T>{ 1, 0 };
	template<Field T>
	constexpr auto BottomLeft = alignment_t<T>{ -1, -1 };
	template<Field T>
	constexpr auto Bottom = alignment_t<T>{ 0, -1 };
	template<Field T>
	constexpr auto BottomRight = alignment_t<T>{ 1, -1 };
};

using offset_mode_t = size_t;
namespace offset_mode {
	enum : offset_mode_t {
		Absolute,
		Relative
	};
}

template<Field T>
Vector2<T> ConvertAlignment(const Vector2<STAMP_DEFAULT_ALIGN_FLOATINGPOINT>& alignIn, const Vector2<STAMP_DEFAULT_ALIGN_FLOATINGPOINT>& alignOut, const Vector2<T>& vec, const Vector2<T>& size) {
	return static_cast<Vector2<T>>(((alignOut - alignIn) * Vector<STAMP_DEFAULT_ALIGN_FLOATINGPOINT>(-0.5, 0.5)) * size + vec);
}
//pivot alignment
//offset from alignment
//left right up down sizes

//tree for parent child ui
//binary tree for mouse events

STAMP_MATH_NAMESPACE_END

#endif