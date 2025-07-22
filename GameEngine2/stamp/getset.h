#pragma once
#ifndef STAMP_MATH_GETSET_H
#define STAMP_MATH_GETSET_H

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


#include <utility>
#include <stamp/define.h>
#include <stamp/inoncopyable.h>

STAMP_NAMESPACE_BEGIN

#define sGet NO_UNIQUE_ADDRESS Get_Base

template<typename S, typename T>
using getterFunction = T(*)(S*);
template<typename S, typename T>
using setterFunction = void(*)(S*, const T&);

template<typename S, typename T, T(*Getter)(S*)>
class Get_Base final {
public:
	using self_type = S;
	using target_type = T;

	Get_Base() {}
	operator T() const {
		return Getter((S*)this - 1);
	}
};

STAMP_NAMESPACE_END

#endif