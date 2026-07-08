#pragma once
#ifndef STAMP_REFLECT_STRING_LITERAL_H
#define STAMP_REFLECT_STRING_LITERAL_H

#include <cstddef>
#include <string>
#include <string_view>
#include <array>
#include <ranges>
#include <algorithm>

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
		consteval std::size_t size() const { return N - 1; }
		constexpr const char* data() const { return chars; }
		constexpr char* data() { return chars; }
		constexpr const char* c_str() const { return chars; }
		explicit constexpr operator const char* () const { return chars; }
		constexpr operator std::string_view() const { return { chars }; }
		constexpr operator std::string() const { return { chars }; }

		template<size_t N2>
		bool constexpr operator ==(const string_literal<N2>& o) const noexcept {
			if (N != N2) return false;
			for (size_t i = 0; i < N; ++i) {
				if (chars[i] != o.chars[i]) return false;
			}
			return true;
		}
		template<size_t N2>
		bool constexpr operator ==(const char(&str)[N2]) const noexcept {
			if (N != N2) return false;
			for (size_t i = 0; i < N; ++i) {
				if (chars[i] != str[i]) return false;
			}
			return true;
		}
	};

	template<string_literal... Arg>
	constexpr auto concat_cstring_v = []() {
		std::array<char, 1 + (Arg.length() + ...)> buffer{};
		auto buffer_it = buffer.begin();
		((buffer_it = std::copy(Arg.begin(), Arg.end(), buffer_it)), ...);
		*buffer_it = '\0';
		return string_literal{ buffer };
	}();

	template<string_literal... Other>
	struct comma_list_string_literals;
	template<string_literal A, string_literal... Other>
	struct comma_list_string_literals<A, Other...> {
		constexpr static auto value = concat_cstring_v<A, concat_cstring_v<", ", Other>...>;
	};
	template<>
	struct comma_list_string_literals<> {
		constexpr static auto value = string_literal{""};
	};
	template<string_literal... Arg>
	constexpr auto comma_list_string_literals_v = comma_list_string_literals< Arg...>::value;

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



	class hash_fnv1a {
		static constexpr auto FNV_offset_basis = 14695981039346656037;
		static constexpr auto FNV_prime = 1099511628211;
		std::size_t hash_v = FNV_offset_basis;
	public:
		hash_fnv1a() = default;
		constexpr hash_fnv1a(const char* str) {
			(*this) << str;
		}
		constexpr hash_fnv1a(const std::string& str) {
			(*this) << str;
		}
		std::size_t hash() const noexcept {
			return hash_v;
		}
		operator std::size_t() const noexcept {
			return hash_v;
		}

		constexpr hash_fnv1a& operator << (char c) {
			hash_v ^= c;
			hash_v *= FNV_prime;
			return *this;
		}
		constexpr hash_fnv1a& operator << (const char* str) {
			for (; (*str) != 0; ++str) {
				(*this) << *str;
			}
			return *this;
		}
		constexpr hash_fnv1a& operator << (std::string_view str) {
			for (auto i = std::begin(str); i != std::end(str); ++i) {
				(*this) << *i;
			}
			return *this;
		}
		constexpr hash_fnv1a& operator << (std::string str) {
			for (auto i = std::begin(str); i != std::end(str); ++i) {
				(*this) << *i;
			}
			return *this;
		}
		template<std::ranges::range Range>
		constexpr hash_fnv1a& operator << (Range& range) {
			std::for_each(std::begin(range), std::end(range), [&](auto& v) {
				(*this) << v;
			});
			return *this;
		}

		constexpr bool operator ==(const hash_fnv1a& other) const {
			return hash_v == other.hash_v;
		}
	};
}

template<>
struct std::hash<stamp::reflect::hash_fnv1a> {
	std::size_t operator()(const stamp::reflect::hash_fnv1a& v) const {
		std::hash<std::size_t> hash_f{};
		return hash_f(v.hash());
	}
};

#endif // STAMP_REFLECT_STRING_LITERAL_H