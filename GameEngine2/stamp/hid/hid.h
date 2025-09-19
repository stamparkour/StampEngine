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

STAMP_HID_NAMESPACE_BEGIN

class IHumanInterfaceDevice_Base : STAMP_NAMESPACE::INonCopyable {
	friend class Window_Base;
protected:
	IHumanInterfaceDevice_Base() = default;

	virtual void Update(STAMP_DEFAULT_FLOATINGPOINT deltaTime) = 0;
	virtual void Unfocus() = 0;
public:
	virtual ~IHumanInterfaceDevice_Base() {}

	virtual bool Exists() const noexcept = 0;

	virtual bool ButtonDown(size_t index) const noexcept = 0;
	virtual bool ButtonUp(size_t index) const noexcept = 0;
	virtual bool ButtonPressed(size_t index) const noexcept = 0;
	virtual bool ButtonReleased(size_t index) const noexcept = 0;

	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(size_t index) const noexcept = 0;
	virtual STAMP_DEFAULT_FLOATINGPOINT AxisDelta(size_t index) const noexcept = 0;
};

class GenericHumanInterfaceDevice : IHumanInterfaceDevice_Base {
	std::vector<bool> buttons;
	std::vector<bool> buttons_prev;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes_prev;
	std::vector<STAMP_DEFAULT_FLOATINGPOINT> axes_delta;
protected:
public:
	GenericHumanInterfaceDevice(size_t button_count = 0, size_t axis_count = 0);
	~GenericHumanInterfaceDevice() noexcept;

	virtual bool Exists() const noexcept override = 0;

	virtual void Update(STAMP_DEFAULT_FLOATINGPOINT deltaTime) override;
	virtual void Unfocus() override;

	void Button(size_t index, bool down) noexcept;
	void Axis(size_t index, STAMP_DEFAULT_FLOATINGPOINT input) noexcept;

	virtual bool ButtonDown(size_t index) const noexcept override;
	virtual bool ButtonUp(size_t index) const noexcept override;
	virtual bool ButtonPressed(size_t index) const noexcept override;
	virtual bool ButtonReleased(size_t index) const noexcept override;

	virtual STAMP_DEFAULT_FLOATINGPOINT Axis(size_t index) const noexcept override;
	virtual STAMP_DEFAULT_FLOATINGPOINT AxisDelta(size_t index) const noexcept override;
};

STAMP_HID_NAMESPACE_END

#endif