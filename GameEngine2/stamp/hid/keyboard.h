//stamp/hid/keyboard.h

#pragma once
#ifndef STAMP_HID_KEYBOARD_H
#define STAMP_CONTROLS_KEYBOARD_H

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


#include <stamp/hid/define.h>
#include <stamp/hid/hid.h>
#include <stamp/noncopyable.h>

STAMP_HID_NAMESPACE_BEGIN

class Keyboard : public IHumanInterfaceDevice, public STAMP_NAMESPACE::INonCopyable {
	friend class Window_Base;
	Keyboard() : IHumanInterfaceDevice(256, 0) {}
public:
};

STAMP_HID_NAMESPACE_END
STAMP_HID_KEYBOARD_NAMESPACE_BEGIN
using namespace STAMP_HID_NAMESPACE;

/// <returns>maximum index for keyboards</returns>
size_t MaxIndex();
/// <returns>current count of present keyboards</returns>
size_t Count();
/// <param name="index">: id of keyboard (>=1)</param>
/// <returns>true if the keyboard exists</returns>
bool Exsists(size_t index = 1);
Keyboard* Lock(size_t index = 1);

STAMP_HID_KEYBOARD_NAMESPACE_END

#endif