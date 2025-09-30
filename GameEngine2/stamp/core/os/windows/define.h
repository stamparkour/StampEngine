//stamp/core/windows/os/define.h

#pragma once
#ifndef STAMP_CORE_WIN32_DEFINE_H
#define STAMP_CORE_WIN32_DEFINE_H

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
#include <Windows.h>
#include <Windowsx.h>
#include <stdio.h>
#include <atomic>

#define STAMP_CORE_WIN32_NAMESPACE			STAMP_CORE_NAMESPACE::win32
#define STAMP_CORE_WIN32_NAMESPACE_BEGIN	namespace STAMP_CORE_WIN32_NAMESPACE {
#define STAMP_CORE_WIN32_NAMESPACE_END		}

extern HWND parentHwnd;
extern std::atomic_int win32_windowsActive;

#endif