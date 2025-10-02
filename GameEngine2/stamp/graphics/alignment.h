//stamp/graphics/define.h

#pragma once
#ifndef STAMP_GRAHPICS_ALIGNMENT_H
#define STAMP_GRAHPICS_ALIGNMENT_H

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
#include <stamp/math/vector.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

using rigid_alignment_t = size_t;
namespace rigid_alignment {
	enum : rigid_alignment_t {
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
	inline STAMP_MATH_NAMESPACE::Vector2<T> Vector(rigid_alignment_t value) {
		return {(value & 3) * 2 - 1, 1 - (value >> 2 & 3) * 2};
	}
}

template<STAMP_MATH_NAMESPACE::Quantity T>
struct Bounds {
	STAMP_MATH_NAMESPACE::Vector2<T> topleft;
};

STAMP_GRAPHICS_NAMESPACE_END

#endif