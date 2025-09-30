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
#include <stamp/core/os/windows/define.h>
#include <stamp/core/os/windows/win32hid.h>
#include <stamp/hid/hid.h>
#include <stamp/hid/keyboard.h>
#include <stamp/hid/mouse.h>
#include <Windows.h>
#include <map>
#include <hidusage.h>
#include <atomic>
#include <set>

using namespace STAMP_HID_NAMESPACE;




int WinInput(WPARAM wParam, LPARAM lParam) {
	if (win32_windowsActive <= 0) return 0;

	HRAWINPUT hrawInput = (HRAWINPUT)lParam;
	bool sink = wParam & RIM_INPUTSINK;

	UINT pcbSize = 0;
	if (GetRawInputData(hrawInput, RID_INPUT, nullptr, &pcbSize, sizeof(RAWINPUTHEADER)) == -1) return -1;
	std::vector<uint8_t> buffer(pcbSize);
	RAWINPUT* rawInput = (RAWINPUT*)buffer.data();
	if (GetRawInputData(hrawInput, RID_INPUT, rawInput, &pcbSize, sizeof(RAWINPUTHEADER)) == -1) return -1;
	HANDLE handle = rawInput->header.hDevice;

	switch (rawInput->header.dwType) {
	case RIM_TYPEKEYBOARD: return WinKeyboardRawInput(rawInput);
	case RIM_TYPEMOUSE: return WinMouseRawInput(rawInput); 
	}
}
int WinInputDeviceChange(WPARAM wParam, LPARAM lParam) {
	bool isAdded = wParam == GIDC_ARRIVAL;
	HANDLE handle = (HANDLE)lParam;

	RID_DEVICE_INFO info{};
	UINT size = sizeof(info);
	if(GetRawInputDeviceInfo(handle, RIDI_DEVICEINFO, &info, &size) < 0) return -1;

	switch (info.dwType) {
	case RIM_TYPEKEYBOARD: return WinKeyboardRawInputChange(handle, &info, isAdded);
	case RIM_TYPEMOUSE: return WinMouseRawInputChange(handle, &info, isAdded);
	}
}

static void UpdateAllHID() {
	UINT length = 0;
	GetRawInputDeviceList(nullptr, &length, sizeof(RAWINPUTDEVICELIST));
	std::vector<RAWINPUTDEVICELIST> deviceList(length);
	GetRawInputDeviceList(deviceList.data(), &length, sizeof(RAWINPUTDEVICELIST));
	for (RAWINPUTDEVICELIST& r : deviceList) {
		WinInputDeviceChange(GIDC_ARRIVAL, (LPARAM)r.hDevice);
	}
}

int WinIntitializeHID() {
	int k = 0;
	if(!(k = WinKeyboardInitialize())) return k;

	//mark all plugged in devices as active
	WinKeyboardInitialize();
	WinMouseInitialize();
	// UpdateAllHID();

	return 0;
}

#endif

