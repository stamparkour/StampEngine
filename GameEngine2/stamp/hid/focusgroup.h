 //stamp/hid/define.h

#pragma once
#ifndef STAMP_HID_INPUTGROUP_H
#define STAMP_HID_INPUTGROUP_H

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

#include <atomic>
#include <stamp/hid/define.h>
#include <vector>

STAMP_HID_NAMESPACE_BEGIN

class IFocusable {
	std::vector<class FocusGroup*> focusGroups{};
protected:
	void OnFocus(bool focus);

	IFocusable() {}
	~IFocusable() {

	}
public:
};

class FocusGroup {
	std::vector<IFocusable*> focusables{};
	std::atomic_int count; 
public:
	bool IsEnabled() {
		return count > 0;
	}
};

STAMP_HID_NAMESPACE_END

#endif