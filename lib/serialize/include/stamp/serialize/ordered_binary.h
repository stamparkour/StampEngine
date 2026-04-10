#ifndef STAMP_SERIALIZE_ORDERED_BINARY_H
#define STAMP_SERIALIZE_ORDERED_BINARY_H

#include "serialize_helpers.h"

#include <iostream>
#include <stamp/reflect/reflect.h>
#include <type_traits>
#include <cstdint>
#include <concepts>
#include <cstring>
#include <bit>
#include <unordered_map>

namespace stamp::serialize {
	template<typename T>
	struct ordered_binary_serializer;

	template<typename OS, typename T>
	void ordered_binary_out(OS&, const ordered_binary_serializer<T>&);

	class pointer_track_registry {
		std::unordered_map<const void*, std::size_t> track_out;
	public:
		bool insert_out(const void* ptr, std::size_t cur, std::size_t target) {
			return track_out.insert({ ptr, sizeof(ptr) }).second;
		}

	};

	struct ordered_binary_formatter {
	};

	template<typename T>
	struct ordered_binary_serializer {
		using type = T;

		type* data;
		const ordered_binary_formatter* format;
		pointer_track_registry* pointer_tracker;

		constexpr ordered_binary_serializer(type* data, const ordered_binary_formatter* format, pointer_track_registry* pointer_tracker) :
			data(data),
			format(format),
			pointer_tracker(pointer_tracker) {}
	};

	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(T& val, const ordered_binary_formatter& format = {}) {
		pointer_track_registry track{};
		return { &val, &format, &track };
	}
	template<typename T>
	inline ordered_binary_serializer<const T> ordered_binary(const T& val, const ordered_binary_formatter& format = {}) {
		pointer_track_registry track{};
		return { &val, &format, &track };
	}

	template<typename OS, typename T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<T>& serializer) {
		using namespace stamp::reflect;
		for_each_reflect_member_properties<T>([&]<typename P>(const P & property) {
			using value_type = typename T::value_type;

			auto& val = (serializer.data->*property.member_ptr());
			auto obs = ordered_binary_serializer<std::remove_reference_t<value_type>>{ val, serializer.format, serializer.pointer_tracker };

			ordered_binary_out(ostream, obs);
		});
	}
	template<typename OS, std::integral T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<T>& serializer) {
		auto out = to_little_endian_arr(*(serializer.data));
		ostream.write(reinterpret_cast<const char*>(&out), static_cast<std::size_t>(out.size()));
	}
	// might need to be altered for non IEEE754 floating point types
	template<typename OS, std::floating_point T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<T>& serializer) {
		auto out = to_little_endian_arr(serializer.data);
		ostream.write(reinterpret_cast<const char*>(&out), static_cast<std::size_t>(out.size()));
	}
	/*template<typename OS, typename T>
	void ordered_binary_out(OS& ostream, ordered_binary_serializer<T*>& serializer) {
		auto out = to_little_endian_arr(reinterpret_cast<std::size_t>(serializer.data));
		ostream.write(reinterpret_cast<const char*>(&out), static_cast<std::size_t>(out.size()));
	}*/

	template<typename OS, typename T>
	inline OS& operator <<(OS& os, const ordered_binary_serializer<T>& serializer) {
		ordered_binary_out(os, serializer);
		return os;
	}
	template<typename IS, typename T>
	inline IS& operator >>(IS& is, const ordered_binary_serializer<T>& serializer) {
		// serializer.deserialize(is);
		return is;
	}
}

#endif // STAMP_SERIALIZE_ORDERED_BINARY_H
