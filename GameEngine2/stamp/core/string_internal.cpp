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

#include <iostream>
#include <stamp/core/string_internal.h>

using namespace STAMP_NAMESPACE;

size_t STAMP_NAMESPACE::to_utf8(char8_t* buffer, size_t length1, const char16_t* str, size_t length2, size_t* readCount) {
	char32_t codepoint = to_utf32(str, length2, readCount);
	return to_utf8(buffer, length1, codepoint);
}
size_t STAMP_NAMESPACE::to_utf8(char8_t* buffer, size_t length, char32_t str) {
	if (str < 0x80) {
		if (length < 1) {
			if (length == 0 && buffer == nullptr) return 1;
			return 0;
		}
		buffer[0] = static_cast<char>(str);
		return 1; // Single byte
	}
	else if (str < 0x800) {
		if (length < 2) {
			if (length == 0 && buffer == nullptr) return 2;
			return 0;
		}
		buffer[0] = static_cast<char>(0xC0 | (str >> 6));
		buffer[1] = static_cast<char>(0x80 | (str & 0x3F));
		return 2; // Two bytes
	}
	else if (str < 0x10000) {
		if (length < 3) {
			if (length == 0 && buffer == nullptr) return 3;
			return 0;
		}
		buffer[0] = static_cast<char>(0xE0 | (str >> 12));
		buffer[1] = static_cast<char>(0x80 | ((str >> 6) & 0x3F));
		buffer[2] = static_cast<char>(0x80 | (str & 0x3F));
		return 3; // Three bytes
	}
	else if (str <= 0x10FFFF) {
		if (length < 4) {
			if (length == 0 && buffer == nullptr) return 4;
			return 0;
		}
		buffer[0] = static_cast<char>(0xF0 | (str >> 18));
		buffer[1] = static_cast<char>(0x80 | ((str >> 12) & 0x3F));
		buffer[2] = static_cast<char>(0x80 | ((str >> 6) & 0x3F));
		buffer[3] = static_cast<char>(0x80 | (str & 0x3F));
		return 4; // Four bytes
	}
	if (length < 3) {
		if (length == 0 && buffer == nullptr) return 3;
		return 0;
	}
	buffer[0] = 0xEF; // Invalid code point, return replacement character
	buffer[1] = 0xBF;
	buffer[2] = 0xBD;
	return 3;
}
size_t STAMP_NAMESPACE::to_utf16(char16_t* buffer, size_t length1, const char8_t* str, size_t length2, size_t* readCount) {
	char32_t codepoint = to_utf32(str, length2, readCount);
	return to_utf16(buffer, length1, codepoint);
}
size_t STAMP_NAMESPACE::to_utf16(char16_t* buffer, size_t length, char32_t str) {
	if (str < 0x10000) {
		if (length < 1) {
			if (length == 0 && buffer == nullptr) return 1;
			return 0;
		}
		buffer[0] = static_cast<char16_t>(str);
		return 1; // Single UTF-16 code unit
	}
	else if (str <= 0x10FFFF) {
		if (length < 2) {
			if (length == 0 && buffer == nullptr) return 2;
			return 0;
		}
		str -= 0x10000;
		buffer[0] = static_cast<char16_t>((str >> 10) + 0xD800);
		buffer[1] = static_cast<char16_t>((str & 0x3FF) + 0xDC00);
		return 2; // Surrogate pair
	}
	if (length < 1) {
		if (length == 0 && buffer == nullptr) return 1;
		return 0;
	}
	buffer[0] = 0xFFFD; // Invalid code point
	return 1;
}
char32_t STAMP_NAMESPACE::to_utf32(const char8_t* buffer, size_t length, size_t* readCount) {
	if (length < 1) return 0xFFFD; // Invalid input
	if ((buffer[0] & 0x80) == 0) {
		if (readCount) *readCount = 1;
		return buffer[0];
	}
	if (length < 2) {
		if (readCount) *readCount = 1;
		return 0xFFFD; // Invalid input
	}
	if ((buffer[0] & 0xE0) == 0xC0) {
		if (readCount) *readCount = 2;
		if ((buffer[1] & 0xC0) != 0x80) return 0xFFFD; // Invalid continuation byte
		return buffer[0] << 6 | (buffer[1] & 0x3F);
	}
	if (length < 3) {
		if (readCount) *readCount = 2;
		return 0xFFFD; // Invalid input
	}
	if ((buffer[0] & 0xF0) == 0xE0) {
		if (readCount) *readCount = 3;
		if ((buffer[1] & 0xC0) != 0x80 || (buffer[2] & 0xC0) != 0x80) return 0xFFFD; // Invalid continuation bytes
		return buffer[0] << 12 | (buffer[1] & 0x3F) << 6 | (buffer[2] & 0x3F);
	}
	if (length < 4) {
		if (readCount) *readCount = 3;
		return 0xFFFD; // Invalid input
	}
	if ((buffer[0] & 0xF8) == 0xF0) {
		if (readCount) *readCount = 4;
		if ((buffer[1] & 0xC0) != 0x80 || (buffer[2] & 0xC0) != 0x80 || (buffer[3] & 0xC0) != 0x80) return 0xFFFD; // Invalid continuation bytes
		return buffer[0] << 18 | (buffer[1] & 0x3F) << 12 | (buffer[2] & 0x3F) << 6 | (buffer[3] & 0x3F);
	}
	if (readCount) *readCount = 4;
	return 0xFFFD;
}
char32_t STAMP_NAMESPACE::to_utf32(const char16_t* buffer, size_t length, size_t* readCount) {
	if (length < 1) return 0xFFFD; // Invalid input
	if ((buffer[0] & 0xFC00) == 0xD800) {
		if (length < 2) {
			if (readCount) *readCount = 1;
			return 0xFFFD; // Invalid input
		}
		if (readCount) *readCount = 2;
		if ((buffer[1] & 0xFC00) != 0xDC00) return 0xFFFD; // Invalid surrogate pair
		return buffer[0] << 10 | buffer[1] & 0x3FF | 0x10000;
	}
	if (readCount) *readCount = 1;
	return buffer[0];
}

std::u8string STAMP_NAMESPACE::to_utf8(const std::string& str) {
	return std::u8string(str.begin(), str.end());
}
std::u8string STAMP_NAMESPACE::to_utf8(const std::u16string& str) {
	char8_t buffer[4];
	std::u8string result{};
	for (size_t i = 0; i < str.size();) {
		size_t r = str.size() - i;
		size_t c = to_utf8(buffer, 4, str.c_str() + i, r, &r);
		result += std::u8string(buffer, buffer + c);
		i += r;
	}
	return result;
}
std::u8string STAMP_NAMESPACE::to_utf8(const std::u32string& str) {
	char8_t buffer[4];
	std::u8string result{};
	for (size_t i = 0; i < str.size();) {
		size_t r = str.size() - i;
		size_t c = to_utf8(buffer, 4, str[i]);
		result += std::u8string(buffer, buffer + c);
		i++;
	}
	return result;
}
std::u16string STAMP_NAMESPACE::to_utf16(const std::string& str) {
	return to_utf16(to_utf8(str));
}
std::u16string STAMP_NAMESPACE::to_utf16(const std::u8string& str) {
	char16_t buffer[2];
	std::u16string result{};
	for (size_t i = 0; i < str.size();) {
		size_t r = str.size() - i;
		size_t c = to_utf16(buffer, 2, str.c_str() + i, r, &r);
		result += std::u16string(buffer, buffer + c);
		i += r;
	}
	return result;
}
std::u16string STAMP_NAMESPACE::to_utf16(const std::u32string& str) {
	char16_t buffer[2];
	std::u16string result{};
	for (size_t i = 0; i < str.size();) {
		size_t r = str.size() - i;
		size_t c = to_utf16(buffer, 2, str[i]);
		result += std::u16string(buffer, buffer + c);
		i++;
	}
	return result;
}

std::u32string STAMP_NAMESPACE::to_utf32(const std::string& str) {
	return to_utf32(to_utf8(str));
}
std::u32string STAMP_NAMESPACE::to_utf32(const std::u8string& str) {
	std::u32string result{};
	for (size_t i = 0; i < str.size();) {
		size_t r = str.size() - i;
		result += to_utf32(str.c_str() + i, r, &r);
		i += r;
	}
	return result;
}
std::u32string STAMP_NAMESPACE::to_utf32(const std::u16string& str) {
	std::u32string result{};
	for (size_t i = 0; i < str.size();) {
		size_t r = str.size() - i;
		result += to_utf32(str.c_str() + i, r, &r);
		i += r;
	}
	return result;
}


std::string STAMP_NAMESPACE::to_utf8_s(const std::u8string& str) {
	return std::string(str.begin(), str.end());
}
std::string STAMP_NAMESPACE::to_utf8_s(const std::u16string& str) {
	std::u8string u8 = to_utf8(str);
	return std::string(u8.begin(), u8.end());
}
std::string STAMP_NAMESPACE::to_utf8_s(const std::u32string& str) {
	std::u8string u8 = to_utf8(str);
	return std::string(u8.begin(), u8.end());
}

std::ostream& STAMP_NAMESPACE::operator <<(std::ostream& stream, const sstring& v) {
	stream << to_utf8_s(v);
	return stream;
}