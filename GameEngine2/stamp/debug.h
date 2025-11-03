//stamp/debug.h

#pragma once
#ifndef STAMP_DEBUG_H
#define STAMP_DEBUG_H

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
#include <stacktrace>
#include <iostream>

#if defined(STAMP_DEBUG) 
#ifdef STAMP_DEBUG_PAUSE 
#define STAMPSTACK() std::cout << std::to_string(std::stacktrace::current()) << std::endl << __FUNCTION__  << " " << __LINE__ << " " << __FILE__ << std::endl; ((void)0)
#define STAMPDMSG(msg) std::cout << msg << std::endl; std::cin.get(); ((void)0)
#define STAMPERROR(con,msg) if(con) {STAMPSTACK(); std::cout << msg << std::endl; std::cin.get(); }; ((void)0)
#else
#define STAMPSTACK() std::cout << std::to_string(std::stacktrace::current()) << std::endl; ((void)0)
#define STAMPDMSG(msg) std::cout << msg << std::endl; ((void)0)
#define STAMPERROR(con,msg) if(con) {STAMPSTACK(); std::cout << msg << std::endl; } ((void)0)
#endif
#else
#define STAMPSTACK() ((void)0)
#define STAMPDMSG(msg) ((void)0)
#define STAMPERROR(con,msg) ((void)0)
#endif

#define GLSTAMPERROR STAMPERROR(STAMP_GRAPHICS_GL_NAMESPACE::checkOpenGLErrors(), "")
#define GLSTAMPERRORM(message) STAMPERROR(STAMP_GRAPHICS_GL_NAMESPACE::checkOpenGLErrors(), message)

//DebugBreak(void)

#endif