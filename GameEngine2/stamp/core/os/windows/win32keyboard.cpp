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
#include <stamp/hid/hid.h>
#include <stamp/hid/keyboard.h>
#include <Windows.h>
#include <map>
#include <hidusage.h>
#include <atomic>
#include <set>
#include <iostream>

STAMP_HID_NAMESPACE_BEGIN

struct Keyboard_internal {
	STAMP_HID_NAMESPACE::GenericHumanInterfaceDevice controller{ 512 };
	bool exists = false;
	HANDLE handle = 0;

	std::shared_mutex bindMutex{};
	std::set<IKeyboardListener*> bindedKeyboards{};

	void Button(STAMP_HID_NAMESPACE::buttonID_t index, bool down) {
		std::shared_lock lock{ bindMutex };
		controller.Button(index, down);
		for (IKeyboardListener* kb : bindedKeyboards) {
			if (down) {
				kb->OnButtonDown(index);
			}
			else {
				kb->OnButtonUp(index);
			}
		}
	}
	void Connect(bool exists) {
		this->exists = exists;
		std::shared_lock lock{ bindMutex };
		for (IKeyboardListener* kb : bindedKeyboards) {
			if (exists) {
				kb->OnConnect();
			}
			else {
				kb->OnDisconnect();
			}
		}
	}
	void AddListener(IKeyboardListener* kb) {
		std::unique_lock lock{ bindMutex };
		bindedKeyboards.insert(kb);
	}
	void RemoveListener(IKeyboardListener* kb) {
		std::unique_lock lock{ bindMutex };
		bindedKeyboards.erase(kb);
	}
};

STAMP_HID_NAMESPACE_END

using namespace STAMP_HID_NAMESPACE;

Keyboard_internal globalKeyboard{};
static std::vector<Keyboard_internal*> keyboardCollection{};
static std::map<HANDLE, Keyboard_internal*> keyboardMap{};

int WinKeyboardRawInput(RAWINPUT* rawInput) {
	HANDLE handle = rawInput->header.hDevice;
	RAWKEYBOARD& rawKeyboard = rawInput->data.keyboard;

	uint16_t scanCode = rawKeyboard.MakeCode;
	uint16_t flags = rawKeyboard.Flags;
	bool down = ~flags & RI_KEY_BREAK;
	bool e0 = flags & RI_KEY_E0;
	bool e1 = flags & RI_KEY_E1;

	if (e0) scanCode |= 0xe000;
	if (e1) scanCode |= 0xe100;

	auto ki = keyboardMap.find(handle);
	if (ki != keyboardMap.end()) {
		Keyboard_internal* internals = ki->second;
		internals->Button(scanCode, down);
		globalKeyboard.Button(scanCode, down);
	}
	return 0;
}

int WinKeyboardRawInputChange(HANDLE handle, RID_DEVICE_INFO* info, bool isAdded) {
	////remove generic keyboard
	//static bool isFirst = true;
	//if (isFirst) {
	//	isFirst = false;
	//	return;
	//}

	//test with multiple keyboards

	std::cout << (int)handle << std::endl;

	wchar_t buf[512]{};
	UINT size = sizeof(buf);
	if (GetRawInputDeviceInfo(handle, RIDI_DEVICENAME, &buf, &size) < 0) return -1;

	RID_DEVICE_INFO_KEYBOARD& keyboard = info->keyboard;
	if (isAdded) {
		if (keyboardMap.find(handle) != keyboardMap.end()) return 0;

		Keyboard_internal* internals = nullptr;
		for (Keyboard_internal* kb : keyboardCollection) {
			if (!kb->exists) {
				kb->exists = true;
				internals = kb;
				break;
			}
		}
		if (!internals) {
			internals = new Keyboard_internal();
			internals->exists = true;
			keyboardCollection.push_back(internals);
		}
		internals->handle = handle;
		internals->Connect(true);

		keyboardMap[handle] = internals;
	}
	else {
		auto it = keyboardMap.find(handle);
		if (it != keyboardMap.end()) {
			it->second->handle = nullptr;
			it->second->Connect(false);
			keyboardMap.erase(it);
		}
	}
	return 0;
}

int WinKeyboardInitialize() {
	RAWINPUTDEVICE rid;

	//keyboard
	rid.usUsagePage = HID_USAGE_PAGE_GENERIC;
	rid.usUsage = HID_USAGE_GENERIC_KEYBOARD;
	rid.dwFlags = RIDEV_INPUTSINK | RIDEV_DEVNOTIFY;
	rid.hwndTarget = parentHwnd;
	if (RegisterRawInputDevices(&rid, 1, sizeof(rid)) == FALSE) {
		return -1;
	}

	Keyboard_internal* kb = new Keyboard_internal();
	keyboardCollection.push_back(kb);
}


Keyboard::Keyboard(size_t id) {
	if (id > STAMP_HID_KEYBOARD_MAX_INDEX) {
		data = nullptr;
		return;
	}
	//id 0 is global keyboard, id 1+ are specific keyboards
	if (id > keyboardCollection.size()) {
		size_t size = keyboardCollection.size();
		keyboardCollection.resize(id);
		for (size_t i = size; i < id; ++i) {
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
}

Keyboard::~Keyboard() noexcept {
	if (!data) return;
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
Keyboard_internal* Keyboard::InternalHandle() const noexcept {
	return data;
}

IKeyboardListener::IKeyboardListener(size_t id) : keyboard(id) {
	if (keyboard.InternalHandle() != nullptr) 
		keyboard.InternalHandle()->AddListener(this);
}
IKeyboardListener::~IKeyboardListener() noexcept {
	if (keyboard.InternalHandle() != nullptr) keyboard.InternalHandle()->RemoveListener(this);
}

#endif
