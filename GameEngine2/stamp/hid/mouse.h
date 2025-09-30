//stamp/hid/keyboard.h

#pragma once
#ifndef STAMP_HID_MOUSE_H
#define STAMP_HID_MOUSE_H

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
#include <stamp/memory.h>

STAMP_HID_NAMESPACE_BEGIN

class Mouse;

namespace mouseButtons {
	enum : buttonID_t {
		Left = 0,
		Middle = 1,
		Right = 2,
		X1 = 3,
		X2 = 4,
	};
}
namespace mouseAxes {
	enum : axisID_t {
		X,
		Y,
		LocalX,
		LocalY,
		NormalizedScreenX,
		NormalizedScreenY,
		WheelX,
		WheelY,
		RawDeltaX,
		RawDeltaY,
		RawWheelX,
		RawWheelY,
	};
}

namespace mouse {
	enum struct confinement {
		Free,
		Confined,
		Freeze,
	};
}

class Mouse final : public IHumanInterfaceDevice {
	friend class Mouse_internal;
private:
	class Keyboard_internal* data;

	// axis for: X, Y, local X, local Y, normalized screenspace X, normalized screenspace Y, wheel X, wheel Y, raw delta X, raw delta Y, raw wheel X, raw wheel Y
public:
	Mouse(size_t index) noexcept;

	virtual ~Mouse() noexcept;

	void Confinement(mouse::confinement);
	void Visibility(bool);

	bool ButtonDown(size_t index) const noexcept override;
	bool ButtonUp(size_t index) const noexcept override;
	bool ButtonPressed(size_t index) const noexcept override;
	bool ButtonReleased(size_t index) const noexcept override;

	STAMP_DEFAULT_FLOATINGPOINT Axis(size_t index) const noexcept override;
	STAMP_DEFAULT_FLOATINGPOINT AxisDelta(size_t index) const noexcept override;

	bool Exists() const noexcept override;
};

class IMouseListener : public IHumanInterfaceDevice {
	friend class Mouse_internal;
private:
	Mouse mouse;
	// axis for: X, Y, local X, local Y, normalized screenspace X, normalized screenspace Y, wheel X, wheel Y, raw delta X, raw delta Y, raw wheel X, raw wheel Y
protected:
	IMouseListener(size_t index) noexcept;

	virtual void OnButtonDown(buttonID_t index) = 0;
	virtual void OnButtonUp(buttonID_t index) = 0;
	virtual void OnMouseMove(STAMP_DEFAULT_FLOATINGPOINT x, STAMP_DEFAULT_FLOATINGPOINT y) = 0;
	virtual void OnConnect() = 0;
	virtual void OnDisconnect() = 0;
public:

	virtual ~IMouseListener() noexcept;

	void Confinement(mouse::confinement confinement) { mouse.Confinement(confinement); }
	void Visibility(bool visiblity) { mouse.Visibility(visiblity); }

	bool ButtonDown(buttonID_t index) const noexcept final override { return mouse.ButtonDown(index); }
	bool ButtonUp(buttonID_t index) const noexcept final override { return mouse.ButtonUp(index); }
	bool ButtonPressed(buttonID_t index) const noexcept final override { return mouse.ButtonPressed(index); }
	bool ButtonReleased(buttonID_t index) const noexcept final override { return mouse.ButtonReleased(index); }

	STAMP_DEFAULT_FLOATINGPOINT Axis(axisID_t index) const noexcept final override { return mouse.Axis(index); }
	STAMP_DEFAULT_FLOATINGPOINT AxisDelta(axisID_t index) const noexcept final override { return mouse.AxisDelta(index); }

	bool Exists() const noexcept final override { return mouse.Exists(); }
};

STAMP_HID_NAMESPACE_END

#endif