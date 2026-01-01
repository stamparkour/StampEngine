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

#include <stamp/graphics/window.h>

using namespace STAMP_GRAPHICS_NAMESPACE;

constexpr const char* window::visibility::to_string(visibility_t v) {
	switch (v) {
	case Visible: return "Visible";
	case Hidden: return "Hidden";
	case Maximized: return "Maximized";
	case Minimized: return "Minimized";
	default: return "Unknown";
	}
}
constexpr bool window::visibility::is_shown(visibility_t v) {
	switch (v) {
	case Visible:
	case Maximized:
		return true;
	case Hidden:
	case Minimized:
	default:
		return false;
	}
}
constexpr const char* window::displaymode::to_string(displaymode_t v) {
	switch (v) {
	case Normal: return "Normal";
	case Borderless: return "Borderless";
	case Popup: return "Popup";
	default: return "Unknown";
	}
}