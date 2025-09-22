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
#include <map>
#include <hidusage.h>
#include <atomic>
#include <set>

using namespace STAMP_HID_NAMESPACE;

STAMP_HID_NAMESPACE_BEGIN

struct Keyboard_internal {
	STAMP_HID_NAMESPACE::GenericHumanInterfaceDevice controller{512};
	bool exists = false;
	HANDLE handle;

	std::shared_mutex bindMutex{};
	std::set<Keyboard*> bindedKeyboards{};

	void Button(STAMP_HID_NAMESPACE::buttonID_t index, bool down) {
		std::shared_lock lock{ bindMutex };
		controller.Button(index, down);
		for(Keyboard* kb : bindedKeyboards) {
			if (down) {
				kb->OnButtonDown(index);
			}
			else {
				kb->OnButtonUp(index);
			}
		}
	}
	void Connect() {
		std::shared_lock lock{ bindMutex };
		for (Keyboard* kb : bindedKeyboards) {
			kb->OnConnect();
		}
	}
	void Disconnect() {
		std::shared_lock lock{ bindMutex };
		for (Keyboard* kb : bindedKeyboards) {
			kb->OnDisconnect();
		}
	}
	void AddListener(Keyboard* kb) {
		std::unique_lock lock{ bindMutex };
		bindedKeyboards.insert(kb);
	}
	void RemoveListener(Keyboard* kb) {
		std::unique_lock lock{ bindMutex };
		bindedKeyboards.erase(kb);
	}
};

STAMP_HID_NAMESPACE_END

extern HWND parentHwnd;
extern std::atomic_int win32_windowsActive;
Keyboard_internal globalKeyboard{};
static std::vector<Keyboard_internal*> keyboardCollection{};
static std::map<HANDLE, Keyboard_internal*> keyboardMap{};

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
	case RIM_TYPEKEYBOARD: {
		RAWKEYBOARD& rawKeyboard = rawInput->data.keyboard;
		uint16_t scanCode = rawKeyboard.MakeCode;
		uint16_t flags = rawKeyboard.Flags;

		auto ki = keyboardMap.find(handle);
		if(ki != keyboardMap.end()) {
			Keyboard_internal* internals = ki->second;
			internals->Button(scanCode, flags & RI_KEY_MAKE);
			globalKeyboard.Button(scanCode, flags & RI_KEY_MAKE);
		}
	} break;
	}
}
int WinInputDeviceChange(WPARAM wParam, LPARAM lParam) {
	bool isAdded = wParam == GIDC_ARRIVAL;
	HANDLE handle = (HANDLE)lParam;

	RID_DEVICE_INFO info{};
	UINT size = sizeof(info);
	if(GetRawInputDeviceInfo(handle, RIDI_DEVICEINFO, &info, &size) < 0) return -1;

	switch (info.dwType) {
	case RIM_TYPEKEYBOARD: {
		RID_DEVICE_INFO_KEYBOARD& keyboard = info.keyboard;
		if (isAdded) {
			Keyboard_internal* internals = nullptr;
			for(Keyboard_internal* kb : keyboardCollection) {
				if (!kb->exists) {
					kb->exists = true;
					internals = kb;
					break;
				}
			}
			if(!internals) {
				internals = new Keyboard_internal();
				internals->exists = true;
				keyboardCollection.push_back(internals);
			}
			internals->handle = handle;
			internals->Connect();

			keyboardMap[handle] = internals;
		}
		else {
			auto it = keyboardMap.find(handle);
			if(it != keyboardMap.end()) {
				it->second->exists = false;
				it->second->handle = nullptr;
				it->second->Disconnect();
				keyboardMap.erase(it);
			}
		}
	} break;
	}
}

static int InitializeKeyboardCollection() {
	RAWINPUTDEVICE rid = {
		HID_USAGE_PAGE_GENERIC, 
		HID_USAGE_GENERIC_KEYBOARD,
		RIDEV_INPUTSINK | RIDEV_EXINPUTSINK | RIDEV_DEVNOTIFY,
		parentHwnd
	};
	if (RegisterRawInputDevices(&rid, 1, sizeof(rid)) == FALSE) {
		return -1;
	}

	Keyboard_internal* kb = new Keyboard_internal();
	keyboardCollection.push_back(kb);

	return 0;
}

Keyboard::Keyboard(size_t id) {
	static int _ = InitializeKeyboardCollection();
	//id 0 is global keyboard, id 1+ are specific keyboards
	if (id > keyboardCollection.size()) {
		size_t size = keyboardCollection.size();
		keyboardCollection.resize(id);
		for(size_t i = size; i < id; ++i) {
			Keyboard_internal* kb = new Keyboard_internal();
			keyboardCollection[i] = kb;
		}
	}
	//if id is 0, use global keyboard
	if (id == 0) {
		data = &globalKeyboard;
	}
	else {
		data = keyboardCollection[id - 1];
	}
	
	if(data) {
		data->AddListener(this);
	}
}

Keyboard::~Keyboard() noexcept {
	if (!data) return;
	data->RemoveListener(this);
	data = nullptr;
}

bool Keyboard::Exists() const noexcept {
	return data && data->exists;
}
bool Keyboard::ButtonDown(size_t index) const noexcept {
	return data && data->controller.ButtonDown(index);
}
bool Keyboard::ButtonUp(size_t index) const noexcept {
	return data && data->controller.ButtonUp(index);
}
bool Keyboard::ButtonPressed(size_t index) const noexcept {
	return data && data->controller.ButtonPressed(index);
}
bool Keyboard::ButtonReleased(size_t index) const noexcept {
	return data && data->controller.ButtonReleased(index);
}

#endif

