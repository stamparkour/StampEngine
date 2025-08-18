//stamp/core/bit_internal.h

#pragma once
#ifndef STAMP_CORE_BIT_INTERNAL_H
#define STAMP_CORE_BIT_INTERNAL_H

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


#include <stamp/core/define.h>
#include <bit>

template<typename T>
constexpr T networkOrder(T value) {
	//swap bytes if native endianness is different from network endianness
	if (std::endian::native == std::endian::big && STAMP_NETWORK_ENDIANNESS == 0 ||
		std::endian::native == std::endian::little && STAMP_NETWORK_ENDIANNESS == 1) {
		T o;
		for(size_t i = 0; i < sizeof(T); ++i) {
			// swap bytes
			((unsigned char*)&o)[i] = ((unsigned char*)&value)[sizeof(T) - 1 - i];
		}
		return o;
	}
	// no conversion needed or native endianness is unknown
	else {
		return value;
	}
	
}

#endif