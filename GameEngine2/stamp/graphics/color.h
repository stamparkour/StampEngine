//stamp/graphics/color.h

#pragma once
#ifndef STAMP_GRAPHICS_COLOR_H
#define STAMP_GRAPHICS_COLOR_H

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

#include <stdint.h>
#include <stamp/graphics/define.h>
#include <stamp/math/vector.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

template<typename T = uint8_t>
struct ColorRGBA : STAMP_MATH_NAMESPACE::vector4<T> {
	using data_type = T;

	ColorRGBA(T m) : STAMP_MATH_NAMESPACE::vector4<T>(m, m, m, m) {}
	ColorRGBA(T r, T g, T b) : STAMP_MATH_NAMESPACE::vector4<T>(r, g, b, 1) {}
	ColorRGBA(T r, T g, T b, T a) : STAMP_MATH_NAMESPACE::vector4<T>(r, g, b, a) {}

	const T&	mono()	const	{ return this->x; }
	T&			mono()			{ return this->x; }

	const T&	red()	const	{ return this->x; }
	T&			red()			{ return this->x; }
	const T&	green()	const	{ return this->y; }
	T&			green()			{ return this->y; }
	const T&	blue()	const	{ return this->z; }
	T&			blue()			{ return this->z; }
	const T&	alpha()	const	{ return this->w; }
	T&			alpha()			{ return this->w; }
};

STAMP_GRAPHICS_NAMESPACE_END
#endif