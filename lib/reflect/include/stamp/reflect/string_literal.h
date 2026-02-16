#pragma once
#ifndef STAMP_REFLECT_STRING_LITERAL_H
#define STAMP_REFLECT_STRING_LITERAL_H

#include <cstddef>
#include <string>
#include <array>

namespace stamp::reflect {

	template<std::size_t N>
	struct string_literal {
		char chars[N]{};

		constexpr string_literal(const char(&str)[N]) {
			std::copy_n(str, N, chars);
		}

		// Helper to allow returning from our concat function
		constexpr string_literal(const std::array<char, N>& arr) {
			std::copy_n(arr.data(), N, chars);
		}

		constexpr const char* begin() const { return chars; }
		constexpr const char* end() const { return chars + N - 1; }

		constexpr std::size_t size() const { return N - 1; }
		constexpr operator const char* () const { return chars; }
	};

	template<string_literal... Arg>
	struct concat_cstring {
		constexpr static std::size_t size = (Arg.size() + ...) + 1;
		constexpr static auto value = []() {
			std::array<char, size> buffer{};
			auto buffer_it = std::begin(buffer);
			((buffer_it = std::copy(Arg.begin(), Arg.end(), buffer_it)), ...);
			*buffer_it = '\0';
			return string_literal{ buffer };
		}();
	};

	template<string_literal... Arg>
	constexpr auto concat_cstring_v = concat_cstring<Arg...>::value;
}

#endif // STAMP_REFLECT_STRING_LITERAL_H