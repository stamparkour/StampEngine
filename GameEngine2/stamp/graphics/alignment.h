//stamp/graphics/define.h

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


#include <stamp/graphics/define.h>
#include <stamp/math/matrix.h>
#include <stamp/math/vector.h>
#include <stamp/math/rect.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

using alignment_t = size_t;
namespace alignment {
	enum : alignment_t {
		TopLeft = 0b0000,
		Top = 0b0001,
		TopRight = 0b0010,
		Left = 0b0100,
		Center = 0b0101,
		Right = 0b0110,
		BottomLeft = 0b1000,
		Bottom = 0b1001,
		BottomRight = 0b1010
	};

	template<STAMP_MATH_NAMESPACE::Quantity T>
	inline STAMP_MATH_NAMESPACE::Vector2<T> Vector(alignment_t value) {
		return {(value & 3) * 2 - 1, 1 - (value >> 2 & 3) * 2};
	}
}

using offset_mode_t = size_t;
namespace offset_mode {
	enum : offset_mode_t {
		Absolute,
		Relative
	};
}

template<STAMP_MATH_NAMESPACE::Quantity T>
STAMP_MATH_NAMESPACE::Vector2<T> ConvertAlignment(const STAMP_MATH_NAMESPACE::Vector2<STAMP_DEFAULT_ALIGN_FLOATINGPOINT>& alignIn, const STAMP_MATH_NAMESPACE::Vector2<T>& vec, const STAMP_MATH_NAMESPACE::Vector2<STAMP_DEFAULT_ALIGN_FLOATINGPOINT>& alignOut, const STAMP_MATH_NAMESPACE::Vector2<T>& size) {
	return (alignIn - alignOut) * size / 2 + vec;
}
//pivot alignment
//offset from alignment
//left right up down sizes

//tree for parent child ui
//binary tree for mouse events

STAMP_GRAPHICS_NAMESPACE_END

#endif