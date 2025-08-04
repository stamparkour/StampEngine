//stamp/hid/hid.h

#pragma once
#ifndef STAMP_HID_HID_H
#define STAMP_HID_HID_H

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
#include <stamp/hid/hid_base.h>
#include <stamp/noncopyable.h>
#include <mutex>
#include <vector>

STAMP_HID_NAMESPACE_BEGIN

class IHumanInterfaceDevice : public IHumanInterfaceDevice_Base, public STAMP_NAMESPACE::INonCopyable {
private:
	std::vector<bool> buttons;
	std::vector<bool> buttons_prev;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes;
	virtual void OnFrame();
	virtual void OnDeselect();
protected:
	IHumanInterfaceDevice(size_t buttons, size_t axes);
	void Button(size_t index, bool value);
	void Axis(size_t index, STAMP_DEFAULT_FLOATINGPOINT value);
public:
	virtual ~IHumanInterfaceDevice();

	virtual bool Enabled();

	virtual bool ButtonDown(size_t index);
	virtual bool ButtonUp(size_t index);
	virtual bool ButtonPressed(size_t index);
	virtual bool ButtonReleased(size_t index);

	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(size_t index);
};

STAMP_HID_NAMESPACE_END

#endif