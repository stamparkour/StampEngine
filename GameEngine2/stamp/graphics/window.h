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
#include <stdio.h>

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
		STAMP_NAMESPACE::sstring title = U"Stamp Engine—Window Title";
		STAMP_MATH_NAMESPACE::Recti rect = {};
		STAMP_MATH_NAMESPACE::Recti rectBound = {};
		window::visibility visibility = visibility::Visible;
		bool vsync = false;
		stamp::threadsafe_ptr<std::thread> windowThread;
		bool terminateOnClose = true;
	};
}

class IWindow_Base : INonCopyable {
	friend struct IWindow_internal;
private:
	bool isWindowClosePromise = false;
	std::promise<void> windowClosePromise{};
protected:
	// call at most once
	void SetWindowClosed();
public:
	virtual ~IWindow_Base();

	virtual void Title(const STAMP_NAMESPACE::sstring& title) noexcept = 0;
	virtual STAMP_NAMESPACE::sstring Title() const noexcept = 0;

	virtual void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept = 0;
	virtual STAMP_MATH_NAMESPACE::Recti Rect() const noexcept = 0;

	virtual void RectBound(const STAMP_MATH_NAMESPACE::Vector2i& fixedSize) noexcept = 0;
	virtual void RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept = 0;
	virtual STAMP_MATH_NAMESPACE::Recti RectBound() const noexcept = 0;

	virtual void VSync(bool enabled) noexcept = 0;
	virtual bool VSync() const noexcept = 0;

	virtual void Visibility(window::visibility visibility) noexcept = 0;
	virtual window::visibility Visibility() const noexcept = 0;


	std::future<void> WaitForWindowClose();
};

class IWindow : public IWindow_Base {
	friend struct IWindow_internal;
private:
	STAMP_NAMESPACE::sstring title;
	STAMP_MATH_NAMESPACE::Recti rect;
	STAMP_MATH_NAMESPACE::Recti rectBound;
	window::visibility visibility;
	bool vsync = false;
	struct IWindow_internal* windowData;
protected:
public:
	//should be protected but is testing
	IWindow(const window::CreationSettings& settings);

	virtual ~IWindow();

	virtual void Title(const STAMP_NAMESPACE::sstring& title) noexcept override;
	virtual STAMP_NAMESPACE::sstring Title() const noexcept override;

	virtual void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept override;
	virtual STAMP_MATH_NAMESPACE::Recti Rect() const noexcept override;

	virtual void RectBound(const STAMP_MATH_NAMESPACE::Vector2i& fixedSize) noexcept override;
	virtual void RectBound(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept override;
	virtual STAMP_MATH_NAMESPACE::Recti RectBound() const noexcept override;

	virtual void VSync(bool enabled) noexcept override;
	virtual bool VSync() const noexcept override;

	virtual void Visibility(window::visibility visibility) noexcept override;
	virtual window::visibility Visibility() const noexcept override;

};

STAMP_GRAPHICS_NAMESPACE_END

#endif