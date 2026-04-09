#ifndef STAMP_SERIALIZE_ORDERED_BINARY_H
#define STAMP_SERIALIZE_ORDERED_BINARY_H

#include <iostream>
#include <stamp/reflect/reflect.h>
#include <cstdint>
#include <concepts>
#include <cstring>

namespace stamp::serialize {
	template<typename T>
	struct ordered_binary_serializer;

	template<typename OS, typename T>
	void ordered_binary_out(OS&, ordered_binary_serializer<T>&);

	class pointer_track_registry {

	};

	template<typename T>
	struct ordered_binary_serializer {
		using type = T;
		struct formatter {

		};

		type* data;
		formatter* format;
		pointer_track_registry* pointer_tracker;

		constexpr ordered_binary_serializer(type* data, formatter* format, pointer_track_registry* pointer_tracker) :
			data(data),
			format(format),
			pointer_tracker(pointer_tracker) {}

		template<typename OS>
		void out(OS& ostream) {
			using namespace stamp::reflect;
			for_each_reflect_member_properties<type>([&]<typename P>(const P& property) {
				using value_type = typename T::value_type;

				auto& val = data->*property.member_ptr();
				auto obs = ordered_binary_serializer{val, format, pointer_tracker};

				ordered_binary_out(ostream, obs);
			});
		}
		template<typename IS>
		void in(IS& istream) {

		}
	};

	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(const T&, const ordered_binary_serializer<T>::formatter&, pointer_tracker&) {

	}

	template<typename OS, typename T>
	void ordered_binary_out(OS& ostream, ordered_binary_serializer<T>& serializer) {
		serializer.out(ostream);
	}
	template<typename OS, std::integral T>
	void ordered_binary_out(OS& ostream, ordered_binary_serializer<T>& serializer) {
		char buffer[sizeof(T)];

	}


	template<typename OS, typename T>
	inline OS& operator <<(OS& os, const ordered_binary_serializer<T>& serializer) {
		serializer.serialize(os);
		return os;
	}
	template<typename IS, typename T>
	inline IS& operator >>(IS& is, const ordered_binary_serializer<T>& serializer) {
		serializer.deserialize(is);
		return is;
	}
}

#endif // STAMP_SERIALIZE_ORDERED_BINARY_H
