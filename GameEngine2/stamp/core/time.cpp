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
#include <stamp/core/time.h>

#if defined(STAMP_PLATFORM_WINDOWS)
#include <Windows.h>

using namespace STAMP_NAMESPACE;

static inline double tickTimeLength = []() -> double {
	LARGE_INTEGER largeInt{};
	QueryPerformanceFrequency(&largeInt);
	return 1.0 / largeInt.QuadPart;
}();

double STAMP_NAMESPACE::time::TimeTickLength() {
	return tickTimeLength;
}
long long STAMP_NAMESPACE::time::getTimeRaw() {
	LARGE_INTEGER largeInt{};
	QueryPerformanceCounter(&largeInt);
	return (largeInt.QuadPart);
}
double STAMP_NAMESPACE::time::getTime() {
	return getTimeRaw() * tickTimeLength;
}

#endif