//stamp/core/window_base.h

#pragma once
#ifndef STAMP_CORE_WINDOW_BASE_H
#define STAMP_CORE_WINDOW_BASE_H

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

#include <string>
#include <stamp/core/define.h>
#include <stamp/noncopyable.h>
#include <stamp/math/rect.h>

STAMP_CORE_NAMESPACE_BEGIN

struct WindowCreationSettings {

};

enum struct WindowVisibility {
	Hidden,
	Visible,
	Minimized,
	Maximized,
	Borderless,
	//Fullscreen,
};


class IWindowBase : INonCopyable {
private:
	std::string title;
	STAMP_MATH_NAMESPACE::Recti rect;
	WindowVisibility visibility;
protected:
	IWindowBase(const WindowCreationSettings& settings);
public:
	virtual ~IWindowBase();

	void Title(const std::string& title);
	std::string Title() const;

	void Rect(const STAMP_MATH_NAMESPACE::Recti& rect);
	STAMP_MATH_NAMESPACE::Recti Rect() const;

	void Visibility(WindowVisibility visibility);
	WindowVisibility Visibility() const;
};

STAMP_CORE_NAMESPACE_END

#endif