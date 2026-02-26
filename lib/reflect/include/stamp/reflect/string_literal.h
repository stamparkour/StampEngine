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
		constexpr string_literal(const char(&& str)[N]) {
			std::copy_n(str, N, chars);
		}

		// Helper to allow returning from our concat function
		constexpr string_literal(const std::array<char, N>& arr) {
			std::copy_n(arr.data(), N, chars);
		}

		constexpr const char* begin() const { return chars; }
		constexpr const char* end() const { return chars + N - 1; }

		consteval std::size_t length() const { return N - 1; }
		consteval std::size_t size() const { return N; }
		consteval const char* data() const { return chars; }
		constexpr operator const char* () const { return chars; }
		constexpr operator std::string_view() const { return { chars }; }
	};

	template<string_literal... Arg>
	constexpr auto concat_cstring_v = []() {
		std::array<char, 0 + (Arg.length() + ...) + 1> buffer{};
		auto buffer_it = buffer.begin();
		((buffer_it = std::copy(Arg.begin(), Arg.end(), buffer_it)), ...);
		*buffer_it = '\0';
		return string_literal{ buffer };
		}();

	constexpr std::size_t count_digits(long long val, std::size_t base = 10) {
		if (val == 0) return 0;
		std::size_t c = 0;
		while (val > 0) {
			++c;
			val /= base;
		}
		return c;
	}

	constexpr char int_digit_to_char(long long d) {
		if (d > 9 && d < 9 + 26) return (char)(d + 'a');
		else return (char)(d + '0');
	}

	template<typename T, T val, std::size_t base = 10, std::size_t N = count_digits(val, base) + 1>
	constexpr string_literal<N> integral_to_string_literal_v = []() {
		std::array<char, N> o{};
		T v = val;
		auto b = o.rbegin();

		*b = 0; // null char
		++b;

		while (v > 0) {
			*b = int_digit_to_char(v % base);
			++b;
			v /= base;
		}
		return string_literal<N>{o};
		}();

	template<typename T>
	constexpr std::size_t string_literal_length_v;
	template<std::size_t N>
	constexpr std::size_t string_literal_length_v < const char(&)[N]> = N;
	template<std::size_t N>
	constexpr std::size_t string_literal_length_v <string_literal<N>> = N;
}

#endif // STAMP_REFLECT_STRING_LITERAL_H