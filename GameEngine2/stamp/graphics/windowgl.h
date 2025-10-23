//stamp/graphics/window.h

#pragma once
#ifndef STAMP_GRAPHICS_WINDOW_H
#define STAMP_GRAPHICS_WINDOW_H

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
#include <stamp/graphics/define.h>
#include <stamp/graphics/window.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

class IChildWindowgl;

namespace windowgl {
	void UnbindGLContext();
	void ShareContext(IChildWindowgl*, IChildWindowgl*);

	struct CreationSettings {
		bool vsync;
	};
}

class ChildWindowgl : public Window {
protected:
	ChildWindowgl(const windowgl::CreationSettings& settings);
public:
	virtual ~ChildWindowgl();

	virtual void Title(const STAMP_NAMESPACE::sstring& title) noexcept = 0;
	virtual STAMP_NAMESPACE::sstring Title() const noexcept = 0;

	virtual void Rect(const STAMP_MATH_NAMESPACE::Recti& rect) noexcept = 0;
	virtual STAMP_MATH_NAMESPACE::Recti Rect() const noexcept = 0;

	virtual void Visibility(window::visibility_t visibility) noexcept = 0;
	virtual window::visibility_t Visibility() const noexcept = 0;

	virtual void Active(bool active) noexcept = 0;
	virtual bool Active() const noexcept = 0;


	void BindGLContext();
};

STAMP_GRAPHICS_NAMESPACE_END

#endif