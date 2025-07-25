#pragma once
#ifndef STAMP_DEFINE_H
#define STAMP_DEFINE_H

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


// Defines the version of the Stamp Engine library
// This is used for version checking and compatibility
#define STAMP_VERSION "0.1.0" 
// Major versions introduce breaking changes, which are not compatible with previous versions.
#define STAMP_VERSION_MAJOR 0
// minor versions add new or depricate features, which are compatible with previous versions.
#define STAMP_VERSION_MINOR 1
// Patches are always compatible with no new features or breaking changes.
#define STAMP_VERSION_PATCH 0

// Defines the default floating point value for all library functions
#define STAMP_DEFAULT_FLOATINGPOINT double

#define STAMP_NAMESPACE					stamp
#define STAMP_NAMESPACE_BEGIN			namespace STAMP_NAMESPACE {
#define STAMP_NAMESPACE_END				}


//OS platform
#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__) 
#define STAMP_PLATFORM_WINDOWS
#define STAMP_PLATFORM_STRING "WINDOWS"
#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
#define STAMP_PLATFORM_LINUX
#define STAMP_PLATFORM_STRING "LINUX"
#elif defined(__APPLE__) || defined(__MACH__)
#define STAMP_PLATFORM_APPLE
#define STAMP_PLATFORM_STRING "APPLE"
#else
#error Stamp Engine does not support this platform.
#endif
//Compiler platform
#ifdef _MSC_VER
#define STAMP_COMPILER_MSVC
#define STAMP_COMPILER_STRING "MSVC"
#elif __clang__
#define STAMP_COMPILER_CLANG
#define STAMP_COMPILER_STRING "CLANG"
#elif __GNUC__
#define STAMP_COMPILER_GNUC
#define STAMP_COMPILER_STRING "GNUC"
#elif __MINGW32__
#define STAMP_COMPILER_MINGW32
#define STAMP_COMPILER_STRING "MINGW32"
#else
#error Stamp Engine does not support this compiler.
#endif


//optional headers
#ifdef _IOSTREAM_
#define STAMP_IOSTREAM_HEADER_INCLUDED
#endif
#ifdef _STRING_
#define STAMP_STRING_HEADER_INCLUDED
#endif

#ifdef STAMP_COMPILER_MSVC 
#define NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#else
#define NO_UNIQUE_ADDRESS [[no_unique_address]]
#endif

#define COMMA ,

#endif