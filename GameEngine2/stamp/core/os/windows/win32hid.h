//stamp/core/windows/os/define.h

#pragma once
#ifndef STAMP_CORE_WIN32_WIN32HID_H
#define STAMP_CORE_WIN32_WIN32HID_H

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

#include <stamp/core/os/windows/define.h>

int WinInput(WPARAM wParam, LPARAM lParam);
int WinInputDeviceChange(WPARAM wParam, LPARAM lParam);
int WinIntitializeHID();

int WinKeyboardRawInput(RAWINPUT* rawInput);
int WinKeyboardRawInputChange(HANDLE handle, RID_DEVICE_INFO* info, bool isAdded);
int WinKeyboardInitialize();

int WinMouseRawInput(RAWINPUT* rawInput);
int WinMouseRawInputChange(HANDLE handle, RID_DEVICE_INFO* info, bool isAdded);
int WinMouseInitialize();

#endif