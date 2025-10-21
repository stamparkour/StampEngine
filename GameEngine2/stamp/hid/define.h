//stamp/hid/define.h


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

#ifndef STAMP_HID_DEFINE_H
#define STAMP_HID_DEFINE_H

#define STAMP_HID_NAMESPACE								STAMP_NAMESPACE::hid
#define STAMP_HID_NAMESPACE_BEGIN						namespace STAMP_HID_NAMESPACE {
#define STAMP_HID_NAMESPACE_END							}

#define STAMP_HID_KEYBOARD_MAX_INDEX 256

// hid device bind a announcement group.
// where all hid devices bound will recieve the same events ( connect, disconect)
// and some device and increment/decrement an active counter (like having a scene only track windows with that specific scene)

// a keyboard will be able to detect which scene is present (by tracking current scene though threadlocal pointer)
// and show no input when all keyboards disconnect.

#endif