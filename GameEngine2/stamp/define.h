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

#define STAMPENGINE_NAMESPACE					stamp
#define STAMPENGINE_NAMESPACE_BEGIN				namespace STAMP_NAMESPACE {
#define STAMPENGINE_NAMESPACE_END				}

// Defines the default floating point value for all library functions
#define STAMPENGINE_DEFAULT_FLOATINGPOINT double

#ifdef _IOSTREAM_
#define STAMPENGINE_IOSTREAM_HEADER_INCLUDED
#endif
#ifdef _STRING_
#define STAMPENGINE_STRING_HEADER_INCLUDED
#endif

#endif