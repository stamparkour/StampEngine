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


#include <stamp/hid/hid.h>
#include <stamp/hid/keyboard.h>


using namespace STAMP_HID_NAMESPACE;

// GenericHumanInterfaceDevice implementation
GenericHumanInterfaceDevice::GenericHumanInterfaceDevice(size_t buttons, size_t axes) {
	this->buttons = std::vector<bool>(buttons, false);
	buttons_prev = std::vector<bool>(buttons, false);
	this->axes = std::vector<STAMP_DEFAULT_FLOATINGPOINT>(axes, 0);
	axes_prev = std::vector<STAMP_DEFAULT_FLOATINGPOINT>(axes, 0);
	axes_delta = std::vector<STAMP_DEFAULT_FLOATINGPOINT>(axes, 0);
}
GenericHumanInterfaceDevice::~GenericHumanInterfaceDevice() {}
void GenericHumanInterfaceDevice::Button(size_t index, bool value) noexcept {
	if (index >= buttons.size()) return;
	buttons[index] = value;
}
void GenericHumanInterfaceDevice::Axis(size_t index, STAMP_DEFAULT_FLOATINGPOINT value) noexcept {
	if (index >= axes.size()) return;
	axes[index] = value;
}
void GenericHumanInterfaceDevice::Update(STAMP_DEFAULT_FLOATINGPOINT deltaTime) {
	buttons_prev = buttons;
	axes_prev = axes;
	for(size_t i = 0; i < axes.size(); ++i) {
		axes_delta[i] = (axes[i] - axes_prev[i]) / deltaTime;
	}
}
void GenericHumanInterfaceDevice::Unfocus() {
	std::fill(buttons.begin(), buttons.end(), false);
	std::fill(buttons_prev.begin(), buttons_prev.end(), false);
	std::fill(axes.begin(), axes.end(), 0);
	std::fill(axes_prev.begin(), axes_prev.end(), 0);
	std::fill(axes_delta.begin(), axes_prev.end(), 0);
}
bool GenericHumanInterfaceDevice::ButtonDown(size_t index) const noexcept {
	if (index >= buttons.size()) return false;
	return buttons[index];
}
bool GenericHumanInterfaceDevice::ButtonUp(size_t index) const noexcept {
	if (index >= buttons.size()) return false;
	return !buttons[index];
}
bool GenericHumanInterfaceDevice::ButtonPressed(size_t index) const noexcept {
	if (index >= buttons.size()) return false;
	return buttons[index] && !buttons_prev[index];
}
bool GenericHumanInterfaceDevice::ButtonReleased(size_t index) const noexcept {
	if (index >= buttons.size()) return false;
	return !buttons[index] && buttons_prev[index];
}
STAMP_DEFAULT_FLOATINGPOINT GenericHumanInterfaceDevice::Axis(size_t index) const noexcept {
	if (index >= axes.size()) return false;
	return axes[index];
}
STAMP_DEFAULT_FLOATINGPOINT GenericHumanInterfaceDevice::AxisDelta(size_t index) const noexcept {
	if (index >= axes.size()) return false;
	return axes_delta[index];
}

