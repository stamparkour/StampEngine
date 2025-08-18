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
	enum : size_t {
		Left = 0,
		Middle = 1,
		Right = 2,
		X1 = 3,
		X2 = 4,
	};
}
namespace mouseAxes {
	enum : size_t {
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

	/// <returns>maximum index for keyboards</returns>
	size_t MaxIndex();
	STAMP_NAMESPACE::readonly_ptr<Mouse> Get(size_t index = 1) noexcept;
	STAMP_NAMESPACE::writable_ptr<Mouse> GetLocked(size_t index = 1) noexcept;
}

class Mouse final : public IHumanInterfaceDevice {
	friend class Window_Base;

	Mouse(); // axis for: X, Y, local X, local Y, normalized screenspace X, normalized screenspace Y, wheel X, wheel Y, raw delta X, raw delta Y, raw wheel X, raw wheel Y
public:
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

STAMP_HID_NAMESPACE_END

#endif