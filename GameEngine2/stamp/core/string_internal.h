//stamp/core/string_internal.h

#pragma once
#ifndef STAMP_CORE_STRING_INTERNAL_H
#define STAMP_CORE_STRING_INTERNAL_H

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


#include <stamp/core/define.h>
#include <string>

STAMP_NAMESPACE_BEGIN

using stamp_char = STAMP_DEFAULT_CHAR;
using sstring = std::basic_string<stamp_char>;

/// <summary>
/// Convert a UTF-16 character to UTF-8 character
/// </summary>
/// <param name="buffer">- the output buffer of the conversion.</param>
/// <param name="length1">- size of buffer, recommended to be 4.</param>
/// <param name="str">- input character to convert</param>
/// <param name="length2">- size of input str, recommended to be 2.</param>
/// <returns>if both buffer and length1 are 0, then it returns the required size of the buffer. Else it returns the number of characters written.</returns>

size_t to_utf8(char8_t* buffer, size_t length1, const char16_t* str, size_t length2);
size_t to_utf8(char8_t* buffer, size_t length, char32_t str);
size_t to_utf16(char16_t* buffer, size_t length1, const char8_t* str, size_t length2);
size_t to_utf16(char16_t* buffer, size_t length, char32_t str);
char32_t to_utf32(const char8_t* buffer, size_t length);
char32_t to_utf32(const char16_t* buffer, size_t length);

std::u8string to_utf8(const std::u16string& str);
std::u8string to_utf8(const std::u32string& str);
std::u16string to_utf16(const std::u8string& str);
std::u16string to_utf16(const std::u32string& str);
std::u32string to_utf32(const std::u8string& str);
std::u32string to_utf32(const std::u16string& str);

STAMP_NAMESPACE_END

#endif