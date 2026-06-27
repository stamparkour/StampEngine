#ifndef STAMP_SERIALIZE_JSON_H
#define STAMP_SERIALIZE_JSON_H

#include <stamp/reflect/reflect.h>
#include <stamp/reflect/string_literal.h>
#include <string>
#include <string_view>
#include <concepts>
#include <unordered_map>
#include <functional>
#include <iterator>
#include <charconv>

// implemented:
// - json_in
//   - int, float
//   - stamp::reflect obj
//   - inserter_iterable
// - json_out
//   - integral, floating point
//   - stamp::reflect obj
//   - inserter_iterable 
//   - inserter_json_pair_iterable 

namespace stamp::serialize {
	namespace detail {
		inline bool is_whitespace_ascii(char c) {
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
		inline bool is_json_delim_ascii(char c) {
			switch (c) {
			case ',':
			case '}':
			case '{':
			case '[':
			case ']':
				return true;
			default:
				return false;
			}
		}
	}

	namespace concepts {
		template<typename T>
		concept stamp_istream_c = 
			requires {
				typename T::char_type;
				typename T::int_type;
			}&&
			requires(T & v, T::char_type* buffer, std::streamsize size) {
				static_cast<bool>(v);
				{ v.read(buffer, size) } -> std::same_as<T&>;
				{ v.peek() } -> std::same_as<typename T::int_type>;
				{ v.get() } -> std::same_as<typename T::int_type>;
			};

		template<typename T>
		concept stamp_ostream_c = 
			requires {
				typename T::char_type;
			} &&
			requires(T & v, typename T::char_type * buffer, std::streamsize size, typename T::char_type next_char) {
				static_cast<bool>(v);
				{ v.write(buffer, size) } -> std::same_as<T&>;
				{ v.put(next_char) } -> std::same_as<T&>;
			};

		template<typename T>
		concept json_key = std::convertible_to<std::string, T>;

		template<typename Container>
		concept inserter_iterable = 
			requires {
				typename Container::iterator;
				typename Container::value_type;
			} &&
			requires (Container c, typename Container::iterator i, typename Container::value_type v) {
				c.insert(i, v);
				{ std::inserter(c, i) } -> std::same_as<std::insert_iterator<Container>>;
			};

		template<typename Container>
		concept inserter_json_pair_iterable =
			inserter_iterable<Container> &&
			requires {
				typename Container::value_type::first_type;
				typename Container::value_type::second_type;
			} && 
			json_key<typename Container::value_type::first_type>;

	}

	struct json_formatter {
		char nested_str[8] = "";
		char newline_str[8] = "";
		char spacing_str[8] = "";
		bool force_object_pairs = false; // forces std::pair to use object instead of key-value 
		bool force_string_char_array = false; // forces std::string and other text iterables to use the char array format.
	};

	template<typename T>
	struct json_serializer {
		using type = T;
		type* data;
		const json_formatter* format;

		json_serializer(type* data, const json_formatter* format) : data(data), format(format) {}
	};

	namespace detail {
		template<typename IS>
		inline void skip_whitespace(IS& is, const json_formatter*) {
			char next_char;
			while (true) {
				next_char = (char)is.peek();
				if (!is) return; // should throw something
				if (!is_whitespace_ascii(next_char)) {
					break;
				}
				is.get();
			}
		}

		template<typename OS>
		inline void print_newline(OS& os, const json_formatter* format) {
			if (format == nullptr) return;
			if (format->newline_str[0] != '0')
				os << format->newline_str;
		}
		template<typename OS>
		inline void print_spacing(OS& os, const json_formatter* format) {
			if (format == nullptr) return;
			if (format->spacing_str[0] != '0')
				os << format->spacing_str;
		}
		template<typename OS>
		inline void print_nested(OS& os, const json_formatter* format, std::size_t call_depth) {
			if (format == nullptr) return;
			if (format->nested_str[0] != '0')
				for (std::size_t i = call_depth; i; --i)
					os << format->nested_str;
		}

		template<typename IS>
		inline char32_t parse_hex4(IS& is) {
			char buf[4];
			is.read(buf, sizeof(buf));
			std::uint32_t out;
			std::from_chars(std::begin(buf), std::end(buf), out, 16);
			return out;
		}

		template<typename IS>
		inline char escape_to_char(IS& is) {
			char c = (char)is.peek();
			if (!is) return 0; // should throw something
			is.get();

			switch (c) {
			case '0':
				return '\0';
			case 'n':
				return '\n';
			case 'r':
				return '\r';
			case 't':
				return '\t';
			case 'b':
				return '\b';
			case 'f':
				return '\f';
			case 'u': 
				return (char)parse_hex4(is); // should be fixed to support unicode 32
			default:
				return c;
			}
		}
	}

	template<typename T>
	json_serializer<T> json(T& val) {
		return {&val, 0};
	}
	template<typename T>
	json_serializer<T> json(T& val, const json_formatter& format) {
		return {&val, &format};
	}

	template<typename IS, typename T> requires std::integral<T> || std::floating_point<T>
	inline void json_in(IS& istream, const json_serializer<T>& serializer) {
		if (!istream) return; // should throw something (error before call)
		std::string txt = "";
		while (true) {
			char next_char = (char)istream.peek();
			if (!istream) return; // should throw something
			if (detail::is_json_delim_ascii(next_char) || detail::is_whitespace_ascii(next_char)) {
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

		detail::skip_whitespace(istream, serializer.format);
	}

	template<typename IS>
	inline void json_in(IS & istream, const json_serializer<bool>& serializer) {
		if (!istream) return; // should throw something (error before call)
		std::string txt = "";
		while (true) {
			char next_char = (char)istream.peek();
			if (!istream) return; // should throw something
			if (detail::is_json_delim_ascii(next_char) || detail::is_whitespace_ascii(next_char)) {
				break;
			}

			txt += next_char;
			istream.get(); // go to next char
		}

		if (txt == "true") {
			(*serializer.data) = true;
		}
		else if (txt == "false") {
			(*serializer.data) = false;
		}
		else {
			return; // do some exception
		}

		detail::skip_whitespace(istream, *serializer.format);
	}

	template<typename IS>
	inline void json_in(IS& istream, const json_serializer<std::string>& serializer) {
		if (!istream) return; // should throw something (error before call)
		std::string txt = "";

		char next_char = (char)istream.peek();
		if (!istream) return; // should throw something
		if (next_char != '"') return; // should throw something
		istream.get(); // go to next char

		while (true) {
			next_char = (char)istream.peek();
			if (!istream) return; // should throw something
			if (next_char == '"') {
				istream.get(); // go to next char
				break;
			}
			else if (next_char == '\\') {
				istream.get(); // skip backslash 
				if (!istream) return; // should throw something
				next_char = detail::escape_to_char(istream); 
			}

			txt += next_char;
			istream.get(); // go to next char
		}

		(*serializer.data) = std::move(txt);

		detail::skip_whitespace(istream, serializer.format);
	}

	// iterable. specify with pair iterator to allow for generic dictionaries. std::back_inserter

	template<typename IS, concepts::inserter_iterable T>
	inline void json_in(IS& istream, const json_serializer<T>& serializer) {
		if (!istream) return; // should throw something (error before call)
		char next_char;
		while (true) {
			next_char = (char)istream.peek();
			if (!istream) return; // should throw something
			if (detail::is_json_delim_ascii(next_char)) {
				break;
			}
			istream.get(); // go to next char
		}

		// the next character is a json delim character

		if (next_char == '[') {
			istream.get(); // skip [
			auto inserter = std::inserter(*serializer.data, serializer.data->end());
			while (true) {
				detail::skip_whitespace(istream, serializer.format);
				next_char = (char)istream.peek();
				if (!istream) return; // should throw something
				if (next_char == ']') {
					istream.get(); // skip ]
					break;
				}

				typename T::value_type instance;
				auto j = json(instance, *serializer.format);
				json_in(istream, j);
				inserter = std::move(instance);

				detail::skip_whitespace(istream, serializer.format);

				next_char = (char)istream.peek();
				if (!istream) return; // should throw something
				if (next_char == ',') {
					istream.get(); // skip ,
				}
				else if (next_char == ']') {
					// ignore ]
				}
				else {
					return; // should throw something
				}

				detail::skip_whitespace(istream, serializer.format);
			}
		}
		else if (concepts::inserter_json_pair_iterable<T> && next_char == '{') {
			istream.get(); // skip {
			auto inserter = std::inserter(*serializer.data, serializer.data->end());
			while (true) {
				detail::skip_whitespace(istream, serializer.format);
				next_char = (char)istream.peek();
				if (!istream) return; // should throw something
				if (next_char == '}') {
					istream.get(); // skip ]
					break;
				}

				typename T::value_type instance;
				auto j1 = json(instance.first, *serializer.format);
				json_in(istream, j1);

				detail::skip_whitespace(istream, serializer.format);
				next_char = (char)istream.peek();
				if (!istream) return; // should throw something
				if (next_char != ':') {
					return; // should throw somthing
				}
				istream.get(); // skip :
				detail::skip_whitespace(istream, serializer.format);

				auto j2 = json(instance.second, *serializer.format);
				json_in(istream, j2);
				inserter = std::move(instance);

				detail::skip_whitespace(istream, serializer.format);

				next_char = (char)istream.peek();
				if (!istream) return; // should throw something
				if (next_char == ',') {
					istream.get(); // skip ,
				}
				else if (next_char == '}') {
					// ignore ]
				}
				else {
					return; // should throw something
				}

				detail::skip_whitespace(istream, serializer.format);
			}
		}
		else {
			return; // should throw something
		}
	}

	template<typename IS, typename T>
	inline void json_in(IS& istream, const json_serializer<T>& serializer) {
		using namespace stamp::reflect;

		static std::unordered_map<stamp::reflect::hash_fnv1a, std::function<void(IS&, const json_serializer<T>&)>> member_map = []() {
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

					auto j = json(target->*ptr, *val.format);
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
					if (!detail::is_whitespace_ascii(buffer[index])) {
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

	template<typename OS, typename T>
	inline void json_out(OS& ostream, const json_serializer<T>& serializer, std::size_t call_depth = 0) {
		static_assert(stamp::reflect::concepts::reflect_traits_c<T>);

		// already pre-indented
		ostream << "{";

		using namespace stamp::reflect;
		bool first = true;
		for_each_reflect_member_properties<T>([&]<typename P>(const P & property) {
			using value_type = typename P::value_type;

			if (!first) ostream << ",";

			detail::print_newline(ostream, serializer.format);
			detail::print_nested(ostream, serializer.format, call_depth + 1);

			ostream << (std::string_view)stamp::reflect::concat_cstring_v<"\"", property.name(), "\":">;
			detail::print_spacing(ostream, serializer.format);

			auto& val = (serializer.data->*property.member_ptr());
			auto obs = json(val, *serializer.format); // , serializer.pointer_tracker);
			json_out(ostream, obs, call_depth+1);

			first = false;
		});
		detail::print_newline(ostream, serializer.format);
		detail::print_nested(ostream, serializer.format, call_depth);
		ostream << "}";
	}
	template<typename OS, std::integral T>
	inline void json_out(OS& ostream, const json_serializer<T>& serializer, std::size_t call_depth = 0) {
		// change to use ostream.write with a buffered to_chars
		ostream << *(serializer.data);
	}
	template<typename OS, std::floating_point T>
	inline void json_out(OS& ostream, const json_serializer<T>& serializer, std::size_t call_depth = 0) {
		ostream << *(serializer.data);
	}
	template<typename OS>
	inline void json_out(OS& ostream, const json_serializer<std::string>& serializer, std::size_t call_depth = 0) {
		ostream << *(serializer.data);
	}
	template<typename OS>
	inline void json_out(OS& ostream, const json_serializer<std::string_view>& serializer, std::size_t call_depth = 0) {
		ostream << *(serializer.data);
	}
	template<typename OS, concepts::inserter_iterable T>
	inline void json_out(OS& ostream, const json_serializer<T>& serializer, std::size_t call_depth = 0) {
		if (concepts::inserter_json_pair_iterable<T> && !serializer.format->force_object_pairs) {
			// already pre-indented
			ostream << '{';
			int index = 0;
			for (const auto& v : *serializer.data) {
				if (index != 0) ostream << ",";
				detail::print_newline(ostream, serializer.format);
				detail::print_nested(ostream, serializer.format, call_depth + 1);

				ostream << "\"" << v.first << "\":";
				detail::print_spacing(ostream, serializer.format);

				auto j2 = json(v.second, *serializer.format);
				json_out(ostream, j2, call_depth + 1);

				index++;
			}
			detail::print_newline(ostream, serializer.format);
			detail::print_nested(ostream, serializer.format, call_depth);
			ostream << '}';
		}
		else {
			// already pre-indented
			ostream << '[';
			int index = 0;
			for (const auto& v : *serializer.data) {
				if (index != 0) ostream << ",";
				detail::print_newline(ostream, serializer.format);
				detail::print_nested(ostream, serializer.format, call_depth + 1);
				auto j = json(v, *serializer.format);
				json_out(ostream, j, call_depth + 1);
				index++;
			}
			detail::print_newline(ostream, serializer.format);
			detail::print_nested(ostream, serializer.format, call_depth);
			ostream << ']';
		}
	}
	template<typename OS, typename T>
	inline void json_out(OS& ostream, const json_serializer<T const>& serializer, std::size_t call_depth = 0) {
		json_out(ostream, reinterpret_cast<const json_serializer<T>&>(serializer), call_depth);
	}

	template<typename OS, typename T>
	inline OS& operator <<(OS& ostream, const json_serializer<T>& serializer) {
		json_out(ostream, serializer);
		return ostream;
	}
	template<typename IS, typename T>
	inline IS& operator >>(IS& istream, const json_serializer<T>& serializer) {
		json_in(istream, serializer);
		return istream;
	}
}

#endif // STAMP_SERIALIZE_JSON_H