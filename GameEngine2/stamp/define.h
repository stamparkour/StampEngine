//stamp/define.h

//make sure all define files are not pragma and include stamp/define.h outside the ifdef block

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

// Defines the default value type for all library functions
#define STAMP_DEFAULT_FLOATINGPOINT double
#define STAMP_DEFAULT_ALIGN_FLOATINGPOINT float
#define STAMP_DEFAULT_CHAR char32_t
#define STAMP_STRING(v) U##v

// network endianness 1: big-endian, 0: little-endian
#define STAMP_NETWORK_ENDIANNESS 0

// Defines the default loop count for benchmarks
#define STAMP_BENCHMARK_LOOPCOUNT 500000

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

#ifdef _TEST
#define STAMP_UNITTEST
#if __has_include(<CppUnitTest.h>)
#define STAMP_MICROSOFT_UNITTEST
#endif
#else
#define STAMP_DEPLOY
#endif

#ifdef _DEBUG
#define STAMP_DEBUG
#endif


#if __has_include(<lua/lua.h>)
#define STAMP_LUA_AVAILABLE
#endif


#ifdef STAMP_COMPILER_MSVC 
#define NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#else
#define NO_UNIQUE_ADDRESS [[no_unique_address]]
#endif

#define COMMA ,

#define STAMP_DESCRIPTION_STRING "Stamp Engine " STAMP_VERSION " [" STAMP_PLATFORM_STRING " - " STAMP_COMPILER_STRING "]"

#endif

//optional headers
#if defined(_OSTREAM_) && !defined(STAMP_OSTREAM_HEADER_INCLUDED)
#define STAMP_OSTREAM_HEADER_INCLUDED
#endif
#if defined(_ISTREAM_) && !defined(STAMP_ISTREAM_HEADER_INCLUDED)
#define STAMP_ISTREAM_HEADER_INCLUDED
#endif
#if defined(_STRING_) && !defined(STAMP_STRING_HEADER_INCLUDED)
#define STAMP_STRING_HEADER_INCLUDED
#include <stamp/core/string_internal.h>
#endif
#if defined(_BIT_) && !defined(STAMP_BIT_HEADER_INCLUDED)
#define STAMP_BIT_HEADER_INCLUDED
#include <stamp/core/bit_internal.h>
#endif