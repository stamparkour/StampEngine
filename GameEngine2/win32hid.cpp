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
#if defined(STAMP_PLATFORM_WINDOWS) && defined(STAMP_DEPLOY)
#include <stamp/hid/hid.h>
#include <stamp/hid/keyboard.h>
#include <stamp/hid/mouse.h>
#include <Windows.h>

using namespace STAMP_HID_NAMESPACE;

STAMP_HID_NAMESPACE_BEGIN

class Keyboard_internal {
	STAMP_HID_NAMESPACE::GenericHumanInterfaceDevice controller;
};

STAMP_HID_NAMESPACE_END


#endif

