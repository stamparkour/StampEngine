//stamp/core/define.h

#pragma once
#ifndef STAMP_CORE_DEFINE_H
#define STAMP_CORE_DEFINE_H

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
#include <Windows.h>
#include <Windowsx.h>
#include <stdio.h>

#define STAMP_CORE_NAMESPACE				STAMP_NAMESPACE::core
#define STAMP_CORE_NAMESPACE_BEGIN			namespace STAMP_CORE_NAMESPACE {
#define STAMP_CORE_NAMESPACE_END			}

inline void StampCreateConsole() {
#ifndef STAMP_UNITTEST
	static BOOL console = []()->BOOL {
		BOOL k = AllocConsole();
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stdout);
#pragma warning(suppress : 4996 6031)
		freopen("CONIN$", "r", stdin);
#pragma warning(suppress : 4996 6031)
		freopen("CONOUT$", "w", stderr);

		SetConsoleOutputCP(CP_UTF8);
		return k;
		}();
#endif
}

#endif