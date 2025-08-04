//stamp/hid/hid_base.h

#pragma once
#ifndef STAMP_HID_HID_BASE_H
#define STAMP_HID_HID_BASE_H

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
#include <stamp/noncopyable.h>
#include <vector>

STAMP_HID_NAMESPACE_BEGIN

class IHumanInterfaceDevice_Base : public STAMP_NAMESPACE::INonCopyable {
protected:
	IHumanInterfaceDevice_Base();

	virtual void OnFrame();
	virtual void OnDeselect();
public:
	virtual ~IHumanInterfaceDevice_Base();

	virtual bool ButtonDown(size_t index);
	virtual bool ButtonUp(size_t index);
	virtual bool ButtonPressed(size_t index);
	virtual bool ButtonReleased(size_t index);
	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(size_t index);
};

STAMP_HID_NAMESPACE_END
#endif