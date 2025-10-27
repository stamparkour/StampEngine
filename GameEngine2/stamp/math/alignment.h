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

/// <summary>
/// Vector2 representing alignment where (-1, -1) is bottom-left, (0, 0) is center, and (1, 1) is top-right.
/// All values should be in the range [-1, 1].
/// </summary>
template<Field T>
using alignment_t = Vector2<T>;

using alignmentf = alignment_t<STAMP_DEFAULT_ALIGN_FLOATINGPOINT>;

namespace alignment {
	template<Field T>
	inline const auto TopLeft = alignment_t<T>{ -1, 1 };
	template<Field T>
	inline const auto Top = alignment_t<T>{ 0, 1 };
	template<Field T>
	inline const auto TopRight = alignment_t<T>{ 1, 1 };
	template<Field T>
	inline const auto Left = alignment_t<T>{ -1, 0 };
	template<Field T>
	inline const auto Center = alignment_t<T>{ 0, 0 };
	template<Field T>
	inline const auto Right = alignment_t<T>{ 1, 0 };
	template<Field T>
	inline const auto BottomLeft = alignment_t<T>{ -1, -1 };
	template<Field T>
	inline const auto Bottom = alignment_t<T>{ 0, -1 };
	template<Field T>
	inline const auto BottomRight = alignment_t<T>{ 1, -1 };
};

template<Field T>
Matrix3<T> AlignmentMatrix(const alignment_t<T>& align, const alignment_t<T>& alignOffset, const Vector2<T>& offset, const Vector2<T>& scale, const Vector2<T>& scaleParent) {
	return Matrix3<T>{
		scale.x / scaleParent.x, 0, align.x + (offset.x * 2 - alignOffset.x * scale.x) / scaleParent.x,
		0, scale.y / scaleParent.y, align.y + (offset.y * 2 - alignOffset.y * scale.y) / scaleParent.y,
		0, 0, 1
	};
}
//pivot alignment
//offset from alignment
//left right up down sizes

//tree for parent child ui
//binary tree for mouse events

STAMP_MATH_NAMESPACE_END

#endif