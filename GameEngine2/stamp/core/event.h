//stamp/event.h

#pragma once
#ifndef STAMP_EVENT_H
#define STAMP_EVENT_H

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
#include <functional>
#include <set>

STAMP_NAMESPACE_BEGIN

template<typename... Args>
using Consumer = std::function<void(Args...)>;

template<typename... Args>
class EventListener final {
	std::set<Consumer<Args>> listeners;
public:
	EventListener() = default;
	void AddListener(const Consumer<Args>& func) {
		listeners.insert(func);
	}
	void RemoveListener(const Consumer<Args>& func) {
		listeners.erase(func);
	}
	void ClearListeners() {
		listeners.clear();
	}
	void Invoke(Args... args) {
		for (const auto& func : listeners) {
			func(args);
		}
	}
};

STAMP_NAMESPACE_END

#endif