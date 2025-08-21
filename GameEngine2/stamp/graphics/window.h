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

STAMP_GRAPHICS_NAMESPACE_BEGIN

// todo: create templated threads for use with specialized windows - like main render loop, or dialog box

namespace window {
	enum struct visibility {
		Hidden,
		Visible,
		Minimized,
		Maximized,
		Borderless,
		//Fullscreen,
	};
	struct CreationSettings {
		std::string title = "Window Title";
		STAMP_MATH_NAMESPACE::Recti rect = {};
		STAMP_MATH_NAMESPACE::Recti rectBound = {};
		window::visibility visibility = visibility::Visible;
		bool vsync = false;
		stamp::threadsafe_ptr<std::thread> windowThread;
		bool terminateOnClose = true;
	};
}

class IWindow_Base : INonCopyable {
public:
	virtual ~IWindow_Base() = 0;

	virtual void Title(const std::string& title) noexcept;
	virtual std::string Title() const noexcept;

	virtual void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	virtual STAMP_MATH_NAMESPACE::Recti Rect() const noexcept;

	virtual void RectBound(const STAMP_MATH_NAMESPACE::Vector2i& fixedSize) noexcept;
	virtual void RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	virtual STAMP_MATH_NAMESPACE::Recti RectBound() const noexcept;

	virtual void VSync(bool enabled) noexcept;
	virtual bool VSync() const noexcept;

	virtual void Visibility(window::visibility visibility) noexcept;
	virtual window::visibility Visibility() const noexcept;

	virtual void WindowEventsWait();
	virtual bool WindowEventsQuery();

	virtual std::future<void> Wait_WindowClose();
	virtual std::future<void> WaitFor_WindowClose();
	virtual std::future<void> WaitUntil_WindowClose();
};

class IWindow : IWindow_Base {
private:
	std::string title;
	STAMP_MATH_NAMESPACE::Recti rect;
	STAMP_MATH_NAMESPACE::Recti rectBound;
	window::visibility visibility;
	bool vsync = false;
	struct WindowData* windowData;
protected:
	IWindow(const window::CreationSettings& settings);
public:
	virtual ~IWindow() = 0;

	virtual void Title(const std::string& title) noexcept;
	virtual std::string Title() const noexcept;

	virtual void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	virtual STAMP_MATH_NAMESPACE::Recti Rect() const noexcept;

	virtual void RectBound(const STAMP_MATH_NAMESPACE::Vector2i& fixedSize) noexcept;
	virtual void RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept;
	virtual STAMP_MATH_NAMESPACE::Recti RectBound() const noexcept;

	virtual void VSync(bool enabled) noexcept;
	virtual bool VSync() const noexcept;

	virtual void Visibility(window::visibility visibility) noexcept;
	virtual window::visibility Visibility() const noexcept;

	virtual void WindowEventsWait();
	virtual bool WindowEventsQuery();

	virtual std::future<void> Wait_WindowClose();
	virtual std::future<void> WaitFor_WindowClose();
	virtual std::future<void> WaitUntil_WindowClose();
};

STAMP_GRAPHICS_NAMESPACE_END

#endif