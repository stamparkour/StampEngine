#pragma once
#ifndef STAMP_MATH_INONCOPYABLE_H
#define STAMP_MATH_INONCOPYABLE_H

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

STAMP_NAMESPACE_BEGIN

class INonCopyable {
public:
	INonCopyable() = default;
	INonCopyable(const INonCopyable&) = delete;
	INonCopyable& operator=(const INonCopyable&) = delete;
};

STAMP_NAMESPACE_END

#endif