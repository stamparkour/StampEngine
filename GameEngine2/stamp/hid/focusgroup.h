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
#include <set>
#include <mutex>
#include <stamp/hid/define.h>

STAMP_HID_NAMESPACE_BEGIN

class IFocusable {
	friend class FocusGroup;

	mutable std::mutex focusMutex{};
	std::set<class FocusGroup*> focusGroups{};
	bool focused = false;
protected:
	void OnFocus(bool focus) {
		if (focused == focus) return;
		focused = focus;

		if(focused) {
			for (FocusGroup* group : focusGroups) {
				group->count++;
			}
		}
		else {
			for (FocusGroup* group : focusGroups) {
				group->count--;
			}
		}
	}

	IFocusable() {}
public:
	~IFocusable() {

	}
};

class FocusGroup {
	friend class IFocusable;

	mutable std::mutex focusMutex{};
	std::set<IFocusable*> focusables{};
	std::atomic_int count;
 
	void Add(IFocusable* focusable) {
		std::lock_guard<std::mutex> lock(focusMutex);
		std::lock_guard<std::mutex> lock2(focusable->focusMutex);
		Add_unsafe(focusable);
	}
	void Add_unsafe(IFocusable* focusable) {
		focusable->focusGroups.insert(this);
		auto k = focusables.insert(focusable);
		// only proceed if it was actually inserted
		if (!k.second) return;
		if (focusable->focused) count++;
	}
	void Delete() {
		std::lock_guard<std::mutex> lock(focusMutex);
		for (IFocusable* focusable : focusables) {
			std::lock_guard<std::mutex> lock2(focusable->focusMutex);
			focusable->focusGroups.erase(this);
		}
		focusables.clear();
	}
public:
	FocusGroup() {}
	FocusGroup(const FocusGroup& other) {
		std::lock_guard<std::mutex> lock(focusMutex);
		std::lock_guard<std::mutex> lock2(other.focusMutex);
		focusables = other.focusables;
		for (IFocusable* focusable : other.focusables) {
			std::lock_guard<std::mutex> lock3(focusable->focusMutex);
			Add_unsafe(focusable);
		}
	}
	FocusGroup(FocusGroup&& other) noexcept {
		std::lock_guard<std::mutex> lock(focusMutex);
		std::lock_guard<std::mutex> lock2(other.focusMutex);
		focusables = std::move(other.focusables);
		for (IFocusable* focusable : focusables) {
			std::lock_guard<std::mutex> lock3(focusable->focusMutex);
			focusable->focusGroups.erase(&other);
			Add_unsafe(focusable);
		}
		other.focusables.clear();
		other.count = 0;
	}
	FocusGroup& operator =(const FocusGroup& other) {
		if (this == &other) return *this;
		Delete();
		std::lock_guard<std::mutex> lock(focusMutex);
		std::lock_guard<std::mutex> lock2(other.focusMutex);
		focusables = other.focusables;
		count = other.count.load();
		for (IFocusable* focusable : other.focusables) {
			std::lock_guard<std::mutex> lock3(focusable->focusMutex);
			Add_unsafe(focusable);
		}
		return *this;
	}
	FocusGroup& operator =(FocusGroup&& other) noexcept {
		using std::swap;
		if (this == &other) return *this;

		std::lock_guard<std::mutex> lock(focusMutex);
		std::lock_guard<std::mutex> lock2(other.focusMutex);

		focusables = std::move(other.focusables);
		count.exchange(other.count);
		for (IFocusable* focusable : focusables) {
			std::lock_guard<std::mutex> lock3(focusable->focusMutex);
			focusable->focusGroups.erase(&other);
			Add_unsafe(focusable);
		}
	}

	~FocusGroup() {
		Delete();
	}

	bool IsEnabled() {
		return count > 0;
	}
};

STAMP_HID_NAMESPACE_END

#endif