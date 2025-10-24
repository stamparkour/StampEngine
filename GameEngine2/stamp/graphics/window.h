//stamp/graphics/window_base.h

#pragma once
#ifndef STAMP_GRAPHICS_WINDOW_BASE_H
#define STAMP_GRAPHICS_WINDOW_BASE_H

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

#include <thread>
#include <future>
#include <string>
#include <stamp/graphics/define.h>
#include <stamp/noncopyable.h>
#include <stamp/math/rect.h>
#include <stamp/memory.h>
#include <stamp/math/alignment.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

// todo: create templated threads for use with specialized windows - like main render loop, or dialog box

namespace window {
	using visibility_t = int;
	namespace visibility {
		enum : visibility_t {
			Hidden,
			Visible,
			Maximized,
			Minimized,
			Borderless,
			BorderlessMaximized,
			BorderlessMinimized,
			//Fullscreen,
		};

		constexpr const char* to_string(visibility_t v) {
			switch (v) {
			case Hidden: return "Hidden";
			case Visible: return "Visible";
			case Maximized: return "Maximized";
			case Minimized: return "Minimized";
			case Borderless: return "Borderless";
			case BorderlessMaximized: return "BorderlessMaximized";
			case BorderlessMinimized: return "BorderlessMinimized";
			//case Fullscreen: return "Fullscreen";
			default: return "Unknown";
			}
		}

		constexpr const bool IsBorderlessVisibility(visibility_t v) {
			switch (v) {
			case Borderless:
			case BorderlessMaximized:
			case BorderlessMinimized:
				return true;
			default: return false;
			}
		}

		constexpr const bool IsNormalVisibility(visibility_t v) {
			switch (v) {
			case Borderless:
			case Visible:
				return true;
			default: return false;
			}
		}

		constexpr const bool IsMaximizedVisibility(visibility_t v) {
			switch (v) {
			case BorderlessMaximized:
			case Maximized:
				return true;
			default: return false;
			}
		}

		constexpr const bool IsMinimizedVisibility(visibility_t v) {
			switch (v) {
			case Minimized:
			case BorderlessMinimized:
				return true;
			default: return false;
			}
		}
	}

	struct CreationSettings {
		STAMP_NAMESPACE::sstring title = U"Stamp Engine—Window Title";
		STAMP_MATH_NAMESPACE::Recti rect = {};
		STAMP_MATH_NAMESPACE::Recti rectBound = {};
		visibility_t visibility = visibility::Visible;
		bool terminateApplicationOnClose = false;
	};
}

class Window : public STAMP_NAMESPACE::enable_threadsafe_from_this<Window> {
	friend struct Window_internal;
	template<typename T, typename... Args> friend stamp::threadsafe_ptr<T> stamp::make_threadsafe(Args&&... args);
private:
	struct Window_internal* windowData;
protected:
	virtual void OnCreate() {}
	virtual void OnResize(const STAMP_MATH_NAMESPACE::Recti& newRect) {}
	virtual void OnMove(const STAMP_MATH_NAMESPACE::Vector2i& newPosition) {}
	virtual void OnClose() {}
	virtual void OnFocus(bool isFocused) {}

	Window(const window::CreationSettings& settings);
public:
	//should be protected but is testing
	static stamp::threadsafe_ptr<Window> Create(const window::CreationSettings& settings) { return stamp::make_threadsafe<Window>(settings); }

	virtual ~Window();

	void Title(const STAMP_NAMESPACE::sstring& title) noexcept;
	STAMP_NAMESPACE::sstring Title() const noexcept;

	STAMP_MATH_NAMESPACE::Recti ParentRect() const noexcept;
	STAMP_MATH_NAMESPACE::Recti MonitorRect() const noexcept;

	void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	STAMP_MATH_NAMESPACE::Recti Rect() const noexcept;

	void RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	STAMP_MATH_NAMESPACE::Recti RectBound() const noexcept;

	void Visibility(window::visibility_t visibility) noexcept;
	window::visibility_t Visibility() const noexcept;

	void Focus(bool focus) noexcept;
	bool Focus() const noexcept;

	void Close() noexcept;
	bool IsAlive() const noexcept;
	std::future<void> WindowClosePromise() const noexcept;

	void* GetFramebuffer() const;
};


STAMP_GRAPHICS_NAMESPACE_END

#endif