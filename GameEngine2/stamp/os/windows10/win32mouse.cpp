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
#include <stamp/os/windows10/define.h>
#include <stamp/hid/hid.h>
#include <stamp/hid/mouse.h>
#include <Windows.h>
#include <map>
#include <hidusage.h>
#include <atomic>
#include <set>

STAMP_HID_NAMESPACE_BEGIN

struct Mouse_internal {
	STAMP_HID_NAMESPACE::GenericHumanInterfaceDevice controller{ 16, 8 };
	bool exists = false;
	HANDLE handle = 0;

	std::shared_mutex bindMutex{};
	std::set<IMouseListener*> bindedMice{};

	void Button(STAMP_HID_NAMESPACE::buttonID_t index, bool down) {
		std::shared_lock lock{ bindMutex };
		controller.Button(index, down);
		for (IMouseListener* kb : bindedMice) {
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
		for (IMouseListener* kb : bindedMice) {
			if (exists) {
				kb->OnConnect();
			}
			else {
				kb->OnDisconnect();
			}
		}
	}
	void AddListener(IMouseListener* kb) {
		std::unique_lock lock{ bindMutex };
		bindedMice.insert(kb);
	}
	void RemoveListener(IMouseListener* kb) {
		std::unique_lock lock{ bindMutex };
		bindedMice.erase(kb);
	}
};

STAMP_HID_NAMESPACE_END

using namespace STAMP_HID_NAMESPACE;

Mouse_internal globalMouse{};
static std::vector<Mouse_internal*> mouseCollection{};
static std::map<HANDLE, Mouse_internal*> mouseMap{};

int WinMouseRawInput(RAWINPUT* rawInput) {
	return 0;
}
int WinMouseRawInputChange(HANDLE handle, RID_DEVICE_INFO* info, bool isAdded) {
	wchar_t buf[512]{};
	UINT size = sizeof(buf);
	if (GetRawInputDeviceInfo(handle, RIDI_DEVICENAME, &buf, &size) < 0) return -1;

	RID_DEVICE_INFO_KEYBOARD& keyboard = info->keyboard;
	if (isAdded) {
		if (mouseMap.find(handle) != mouseMap.end()) return 0;

		Mouse_internal* internals = nullptr;
		for (Mouse_internal* m : mouseCollection) {
			if (!m->exists) {
				m->exists = true;
				internals = m;
				break;
			}
		}
		if (!internals) {
			internals = new Mouse_internal();
			internals->exists = true;
			mouseCollection.push_back(internals);
		}
		internals->handle = handle;
		internals->Connect(true);

		mouseMap[handle] = internals;
	}
	else {
		auto it = mouseMap.find(handle);
		if (it != mouseMap.end()) {
			it->second->handle = nullptr;
			it->second->Connect(false);
			mouseMap.erase(it);
		}
	}
	return 0;
}
int WinMouseInitialize() {
	RAWINPUTDEVICE rid;

	//keyboard
	rid.usUsagePage = HID_USAGE_PAGE_GENERIC;
	rid.usUsage = HID_USAGE_GENERIC_MOUSE;
	rid.dwFlags = RIDEV_INPUTSINK | RIDEV_DEVNOTIFY;
	rid.hwndTarget = parentHwnd;
	if (RegisterRawInputDevices(&rid, 1, sizeof(rid)) == FALSE) {
		return -1;
	}

	Mouse_internal* kb = new Mouse_internal();
	mouseCollection.push_back(kb);

	return 0;
}

Mouse::Mouse(size_t index) noexcept {

}
Mouse::~Mouse() noexcept {

}
bool Mouse::Exists() const noexcept {
	return false;
}
void Mouse::Confinement(mouse::confinement) {

}
void Mouse::Visibility(bool) {

}
bool Mouse::ButtonDown(size_t index) const noexcept {
	return false;
}
bool Mouse::ButtonUp(size_t index) const noexcept {
	return false;
}
bool Mouse::ButtonPressed(size_t index) const noexcept {
	return false;
}
bool Mouse::ButtonReleased(size_t index) const noexcept {
	return false;
}
STAMP_DEFAULT_FLOATINGPOINT Mouse::Axis(size_t index) const noexcept {
	return STAMP_DEFAULT_FLOATINGPOINT();
}
STAMP_DEFAULT_FLOATINGPOINT Mouse::AxisDelta(size_t index) const noexcept {
	return STAMP_DEFAULT_FLOATINGPOINT();
}

#endif