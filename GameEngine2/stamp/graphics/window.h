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
#include <stamp/core/noncopyable.h>
#include <stamp/math/rect.h>
#include <stamp/core/memory.h>
#include <stamp/math/alignment.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

// todo: create templated threads for use with specialized windows - like main render loop, or dialog box

namespace window {
	using displaymode_t = size_t;
	using visibility_t = size_t;
	namespace visibility {
		enum : visibility_t {
			Visible,
			Hidden,
			Maximized,
			Minimized
		};
		constexpr const char* to_string(visibility_t);
		constexpr bool is_shown(visibility_t);
	}
	namespace displaymode {
		enum : displaymode_t {
			Normal,
			BorderlessFullscreen,
			Borderless,
			Popup,
			Toolbox,
			//Fullscreen,
		};
		constexpr const char* to_string(displaymode_t v);
	}

	struct CreationSettings {
		STAMP_NAMESPACE::sstring title = U"Stamp Engine—Window Title";
		STAMP_MATH_NAMESPACE::Recti rect = {};
		STAMP_MATH_NAMESPACE::Recti rectBound = {};
		visibility_t visibility = visibility::Visible;
		displaymode_t displaymode = displaymode::Normal;
		bool terminateApplicationOnClose = false;
	};
}

class Window : STAMP_CORE_NAMESPACE::INonCopyable, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<Window> {
	friend struct Window_internal;
	friend class IWindowListener;
	STAMP_MEMORY_THREADSAFE_FRIEND;
private:
	struct Window_internal* windowData;
protected:
	Window(const window::CreationSettings& settings);
public:
	static STAMP_CORE_NAMESPACE::threadsafe_ptr<Window> Create(const window::CreationSettings& settings) { return STAMP_CORE_NAMESPACE::make_threadsafe<Window>(settings); }

	virtual ~Window();

	void Title(const STAMP_NAMESPACE::sstring& title) noexcept;
	STAMP_NAMESPACE::sstring Title() const noexcept;

	STAMP_MATH_NAMESPACE::Recti ParentRect() const noexcept;
	STAMP_MATH_NAMESPACE::Recti MonitorRect() const noexcept;

	void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	STAMP_MATH_NAMESPACE::Recti Rect() const noexcept;

	void RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	STAMP_MATH_NAMESPACE::Recti RectBound() const noexcept;

	STAMP_MATH_NAMESPACE::Recti ClientRectOffset() const noexcept;

	void Visibility(window::visibility_t visibility) noexcept;
	window::visibility_t Visibility() const noexcept;

	void DisplayMode(window::displaymode_t displaymode) noexcept;
	window::displaymode_t DisplayMode() const noexcept;

	void Focus(bool focus) noexcept;
	bool Focus() const noexcept;

	void Close() noexcept;
	bool IsAlive() const noexcept;
	std::future<void> WindowClosePromise() const noexcept;

	void BindDisplayContext();
};

class IWindowListener : STAMP_CORE_NAMESPACE::INonCopyable, public STAMP_CORE_NAMESPACE::enable_threadsafe_from_this<IWindowListener> {
	friend struct Window_internal;
protected:
	STAMP_NAMESPACE::weak_threadsafe_ptr<Window> window = nullptr;

	virtual void OnWindowResize(const STAMP_MATH_NAMESPACE::Recti& newRect) = 0;
	virtual void OnWindowVisibility(window::visibility_t visibility) = 0;
	virtual void OnWindowDisplay(window::displaymode_t displaymode) = 0;
	virtual void OnWindowFocus(bool isFocused) = 0;
	virtual void OnWindowClose() = 0;

	void AttachWindowListener(const STAMP_CORE_NAMESPACE::threadsafe_ptr<Window>& window);
	IWindowListener();
public:
	~IWindowListener();
};


STAMP_GRAPHICS_NAMESPACE_END

#endif