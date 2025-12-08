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
#include <stamp/noncopyable.h>
#include <vector>
#include <functional>
#include <stamp/event.h>

STAMP_HID_NAMESPACE_BEGIN

using buttonID_t = size_t;
using axisID_t = size_t;



class IHumanInterfaceDevice {
	friend class Window_Base;
protected:
	IHumanInterfaceDevice() = default;
public:
	virtual ~IHumanInterfaceDevice() {}

	virtual bool Exists() const noexcept = 0;

	virtual bool ButtonDown(buttonID_t index) const noexcept = 0;
	virtual bool ButtonUp(buttonID_t index) const noexcept = 0;
	virtual bool ButtonPressed(buttonID_t index) const noexcept = 0;
	virtual bool ButtonReleased(buttonID_t index) const noexcept = 0;

	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(axisID_t index) const noexcept = 0;
	virtual STAMP_DEFAULT_FLOATINGPOINT AxisDelta(axisID_t index) const noexcept = 0;
};

class IHumanInterfaceDeviceListener {
protected:
	IHumanInterfaceDeviceListener() = default;
	
	virtual void OnButtonDown(buttonID_t index) = 0;
	virtual void OnButtonUp(buttonID_t index) = 0;
	virtual void OnAxis(axisID_t index) = 0;

	virtual void OnConnect() = 0;
	virtual void OnDisconnect() = 0;
};

class GenericHumanInterfaceDevice : public IHumanInterfaceDevice {
	std::vector<bool> buttons;
	std::vector<bool> buttons_prev;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes_prev;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes_delta;
public:
	GenericHumanInterfaceDevice(size_t button_count = 0, size_t axis_count = 0);

	//copy and assignment operator/constructor

	~GenericHumanInterfaceDevice() noexcept;

	virtual bool Exists() const noexcept override;

	void Update(STAMP_DEFAULT_FLOATINGPOINT deltaTime);
	void Unfocus();

	void Button(buttonID_t index, bool down) noexcept;
	void Axis(axisID_t index, STAMP_DEFAULT_FLOATINGPOINT input) noexcept;

	virtual bool ButtonDown(buttonID_t index) const noexcept override;
	virtual bool ButtonUp(buttonID_t index) const noexcept override;
	virtual bool ButtonPressed(buttonID_t index) const noexcept override;
	virtual bool ButtonReleased(buttonID_t index) const noexcept override;

	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(axisID_t index) const noexcept override;
	virtual STAMP_DEFAULT_FLOATINGPOINT AxisDelta(axisID_t index) const noexcept override;
};

STAMP_HID_NAMESPACE_END

#endif