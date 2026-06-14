#ifndef STAMP_SERIALIZE_JSON_H
#define STAMP_SERIALIZE_JSON_H

#include <stamp/reflect/reflect.h>
#include <stamp/reflect/string_literal.h>
#include <string>
#include <string_view>
#include <concepts>
#include <unordered_map>
#include <functional>

namespace stamp::serialize {
	bool is_whitespace_ascii(char c) {
		switch (c) {
		case ' ':
		case '\r':
		case '\n':
		case '\t':
			return true;
		default:
			return false;
		}
	}
	bool is_json_delim_ascii(char c) {
		switch (c) {
		case ',':
		case '}':
		case '{':
			return true;
		default:
			return false;
		}
	}

	namespace concepts {
		template<typename T>
		concept stamp_istream_c = requires(T & v, T::char_type * buffer, std::streamsize size) {
			static_cast<bool>(v);
			{ v.read(buffer, size) } -> std::same_as<T&>;
		};
		template<typename T>
		concept stamp_ostream_c = requires(T & v, T::char_type * buffer, std::streamsize size) {
			static_cast<bool>(v);
			{ v.write(buffer, size) } -> std::same_as<T&>;
		};
	}
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

	template<typename IS, typename T> requires std::integral<T> || std::floating_point<T>
	void json_in(IS& istream, const json_serializer<T>& serializer) {
		if (!istream) return; // should throw something (error before call)
		std::string txt = "";
		while (true) {
			char next_char = (char)istream.peek();
			if (!istream) return; // should throw something
			if (is_json_delim_ascii(next_char) || is_whitespace_ascii(next_char)) {
				break;
			}

			txt += next_char;
			istream.get(); // go to next char
		}

		if constexpr (std::same_as<T, int>) {
			(*serializer.data) = std::stoi(txt);
		}
		else if constexpr (std::same_as<T, float>) {
			(*serializer.data) = std::stof(txt);
		}
		else {
			static_assert(false, "no implementation for integral or floating point type");
		}
	}

	template<typename IS, typename T>
	void json_in(IS& istream, const json_serializer<T>& serializer) {
		using namespace stamp::reflect;

		static std::unordered_map<stamp::reflect::hash_fnv1a, std::function<void(IS&, const json_serializer<T>&)>>
			member_map = []() {

			std::unordered_map<stamp::reflect::hash_fnv1a, std::function<void(IS&, const json_serializer<T>&)>> ret;

			for_each_reflect_member_properties<T>([&]<typename Prop>(const Prop & property) {
				using ptr_type = typename Prop::ptr_type;
				using value_type = typename Prop::value_type;
				using class_type = typename Prop::class_type; // same as T

				std::string_view name = property.name();
				stamp::reflect::hash_fnv1a key;
				key << name;
				ret.emplace(key, [property](IS& istream, const json_serializer<T>& val) {
					class_type* target = val.data;
					ptr_type ptr = property.member_ptr();

					auto j = json(target->*ptr, val.format);
					json_in(istream, j);
				});
			});

			return ret;
		}();

		typename IS::char_type buffer[256];

		// {
		if (!istream) return; // should throw something (error before read)
		buffer[0] = (char)istream.get();
		if (!istream) return; // should throw something
		if (buffer[0] != '{') return;

		while (true) {
			buffer[0] = (char)istream.get();
			if (!istream) return; // should throw something
			if (buffer[0] == '}') break;
			if (buffer[0] == '"') {
				stamp::reflect::hash_fnv1a hash;
				std::size_t index = 0;
				//retrieve hash
				while (true) {
					buffer[index] = (char)istream.get();
					if (!istream) return; // should throw something
					if (buffer[index] == '"') {
						index++;
						break;
					}
					hash << buffer[index];
					index++;
				}
				// go to value body
				while (true) {
					buffer[index] = (char)istream.get();
					if (!istream) return; // should throw something
					if (buffer[index] == ':') {
						index++;
						break;
					}
					index++;
				}
				// skip whitespace
				while (true) {
					buffer[index] = (char)istream.peek();
					if (!istream) return; // should throw something
					if (!is_whitespace_ascii(buffer[index])) {
						index++;
						break;
					}
					istream.get(); // skip char
					index++;
				}

				if (auto iter = member_map.find(hash); iter != member_map.end()) {
					iter->second(istream, serializer);
				}
			}
		}
	}

	template<typename OS, std::integral T>
	void json_out(OS& ostream, const json_serializer<T>& serializer) {
		// change to use ostream.write with a buffered to_chars
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