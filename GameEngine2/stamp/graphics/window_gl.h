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
#include <stamp/graphics/window_base.h>

STAMP_GRAPHICS_NAMESPACE_BEGIN

namespace window_gl {
	void UnbindGLContext();
}

class IWindow_gl : public IWindow_Base {
protected:
	IWindow_gl(const window::CreationSettings& settings);
public:
	virtual ~IWindow_gl();
	void BindGLContext();
};

STAMP_GRAPHICS_NAMESPACE_END

#endif