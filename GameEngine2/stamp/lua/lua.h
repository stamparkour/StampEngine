//stamp/lua/lua.h

#pragma once
#ifndef STAMP_LUA_LUA_H
#define STAMP_LUA_LUA_H

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


// provides short names for vector types and functions
// #define STAMP_MATH_VECTOR_SHORT_NAMES

// makes all comparison operators prefer equal_aprox
// #define STAMP_MATH_VECTOR_EQUAL_APROX

//optional headers: <iostream> <string>
#include <stamp/lua/define.h>

STAMP_LUA_NAMESPACE_BEGIN

#define STAMP_LUA_TYPEID_METATABLEKEY "__typeid"
#define STAMP_LUA_TYPEID_REGISTRYKEY "stamp_typeid"
#define STAMP_LUA_TYPEIDMAX_REGISTRYKEY "stamp_typeid_max"
#define STAMP_LUA_CLASSES_REGISTRYKEY "stamp_classes"

#define STAMP_LUA_MIN_TYPEID LUA_NUMTYPES

STAMP_LUA_NAMESPACE_END

#endif