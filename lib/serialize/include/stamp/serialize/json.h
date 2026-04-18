#ifndef STAMP_SERIALIZE_JSON_H
#define STAMP_SERIALIZE_JSON_H

#include <stamp/reflect/reflect.h>
#include <string>
#include <string_view>
#include <concepts>

namespace stamp::serialize {
	struct json_formatter {

	};

	template<typename T>
	struct json_serializer {
		using type = T;
		type* data;
		const json_formatter* format;

		json_serializer(type* data, const json_formatter* format) : data(data), format(format) {}
	};

	template<typename T>
	json_serializer<T> json(T& val, const json_formatter* format = {}) {
		return {&val, format};
	}

	template<typename OS, typename T>
	void json_out(OS& ostream, const json_serializer<T>& serializer) {
		ostream << "{";
		using namespace stamp::reflect;
		bool first = true;
		for_each_reflect_member_properties<T>([&]<typename P>(const P & property) {
			using value_type = typename P::value_type;

			if (!first) ostream << (std::string_view)stamp::reflect::concat_cstring_v<",\"",property.name(),"\":">;
			else ostream << (std::string_view)stamp::reflect::concat_cstring_v<"\"", property.name(), "\":">;

			auto& val = (serializer.data->*property.member_ptr());
			auto obs = json(val, serializer.format); // , serializer.pointer_tracker);
			json_out(ostream, obs);

			first = false;
		});
		ostream << "}";
	}
	template<typename IS, typename T>
	void json_in(IS& istream, const json_serializer<T>& serializer) {
		using namespace stamp::reflect;
		for_each_reflect_member_properties<T>([&]<typename P>(const P & property) {
			using value_type = typename T::value_type;

			auto& val = (serializer.data->*property.member_ptr());
			auto obs = json(val, serializer.format); // , serializer.pointer_tracker);
			json_in(istream, obs);
		});
	}

	template<typename OS, std::integral T>
	void json_out(OS& ostream, const json_serializer<T>& serializer) {
		ostream << *(serializer.data);
	}
	template<typename OS, std::floating_point T>
	void json_out(OS& ostream, const json_serializer<T>& serializer) {
		ostream << *(serializer.data);
	}
	template<typename OS>
	void json_out(OS& ostream, const json_serializer<std::string>& serializer) {
		ostream << *(serializer.data);
	}
	template<typename OS>
	void json_out(OS& ostream, const json_serializer<std::string_view>& serializer) {
		ostream << *(serializer.data);
	}

	template<typename OS, typename T>
	OS& operator <<(OS& ostream, const json_serializer<T>& serializer) {
		json_out(ostream, serializer);
		return ostream;
	}
	template<typename IS, typename T>
	IS& operator >>(IS& istream, const json_serializer<T>& serializer) {
		json_in(istream, serializer);
		return istream;
	}
}

#endif // STAMP_SERIALIZE_JSON_H