//stamp/lua/define.h


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


#include <stamp/define.h>

#ifndef STAMP_LUA_DEFINE_H
#define STAMP_LUA_DEFINE_H

#ifdef STAMP_LUA_AVAILABLE
#include <sol/sol.hpp>

#define STAMP_LUA_NAMESPACE				STAMP_NAMESPACE::lua
#define STAMP_LUA_NAMESPACE_BEGIN		namespace STAMP_LUA_NAMESPACE {
#define STAMP_LUA_NAMESPACE_END			}

#define STAMP_LUA_INSTANCEOF_FUNCTION "instanceof"
#define STAMP_LUA_INSTANCE_FUNCTION "instance"
#define STAMP_LUA_ROOT_OBJECT "stamp"

using lualib_t = void (*)(sol::state& state);

STAMP_LUA_NAMESPACE_BEGIN

STAMP_LUA_NAMESPACE_END

#endif
#endif