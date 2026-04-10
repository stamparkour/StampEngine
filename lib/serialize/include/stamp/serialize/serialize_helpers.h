#ifndef STAMP_SERIALIZE_SERIALIZE_HELPERS_H
#define STAMP_SERIALIZE_SERIALIZE_HELPERS_H

#include <algorithm>
#include <array>
#include <cstddef>
#include <bit>

namespace stamp::serialize {

	template<typename T>
	std::array<char, sizeof(T)> reverse_bytes_arr(const T& val) {
		auto *arr = reinterpret_cast< const std::array<char,sizeof(T)>* >(&val);
		std::array<char, sizeof(T)> out;
		std::ranges::reverse_copy(arr->begin(), arr->end(), out.begin());
		return out;
	}

	template<typename T>
	std::array<char, sizeof(T)> to_little_endian_arr(const T& val) {
		if constexpr (std::endian::native == std::endian::little) {
			return *reinterpret_cast<const std::array<char, sizeof(T)>*>(&val);
		}
		else {
			return reverse_bytes_arr(val);
		}
	}
}

#endif // STAMP_SERIALIZE_SERIALIZE_HELPERS_H
