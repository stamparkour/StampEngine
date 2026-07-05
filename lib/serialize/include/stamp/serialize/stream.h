#pragma once
#ifndef STAMP_SERIALIZE_STREAM_H
#define STAMP_SERIALIZE_STREAM_H

#include <string>
#include <algorithm>

namespace stamp::serialize {
	template<typename T>
	class basic_string_stream_wrapper {
	public:
		using string_type = T;
		using traits_type = typename string_type::traits_type;
		using char_type = typename traits_type::char_type;
		using int_type = typename traits_type::int_type;
		using pos_type = std::size_t;
		using off_type = int;
	private:
		string_type& buffer;
		std::size_t get_index = 0;
		std::size_t put_index = 0;
		bool eof = false;
	public:
		basic_string_stream_wrapper(string_type& buffer) : buffer(buffer) {}

		basic_string_stream_wrapper read(char_type* out, std::streamsize size) {
			size = std::min(size, (std::streamsize)(buffer.size() - get_index));

			std::copy_n(buffer.begin() + get_index, size, out);

			get_index += size;
			if (eof = get_index > buffer.size(); eof) {
				get_index = buffer.size();
			}
			return *this;
		}
		int_type peek() {
			if (eof = get_index + 1 >= buffer.size(); eof) {
				get_index = buffer.size();
				return traits_type::eof();
			}

			return buffer[get_index];
		}
		int_type get() {
			if (eof = get_index + 1 >= buffer.size(); eof) {
				get_index = buffer.size();
				return traits_type::eof();
			}
			return buffer[get_index++];
		}

		pos_type tellg() {
			return get_index;
		}
		basic_string_stream_wrapper& seekg(pos_type pos) {
			get_index = pos;
			return *this;
		}
		basic_string_stream_wrapper& seekg(off_type pos, std::ios_base::seekdir dir) {
			switch (dir) {
			case std::ios_base::beg:
				get_index = pos;
				break;
			case std::ios_base::cur:
				get_index += pos;
				break;
			case std::ios_base::end:
				get_index = pos + buffer.size();
				break;
			}
			return *this;
		}

		basic_string_stream_wrapper& write(const char_type* out, std::streamsize size) {
			buffer.insert(put_index, out, size);
			put_index += size;
			return *this;
		}

		basic_string_stream_wrapper& put(char_type next_char) {
			buffer.insert(buffer.begin() + put_index, next_char);
			put_index++;
			return *this;
		}

		pos_type tellp() {
			return put_index;
		}
		basic_string_stream_wrapper& seekp(pos_type pos) {
			put_index = pos;
			return *this;
		}
		basic_string_stream_wrapper& seekp(off_type pos, std::ios_base::seekdir dir) {
			switch (dir) {
			case std::ios_base::beg:
				put_index = pos;
				break;
			case std::ios_base::cur:
				put_index += pos;
				break;
			case std::ios_base::end:
				put_index = pos + buffer.size();
				break;
			}
			return *this;
		}

		void clear() {
			eof = false;
			get_index = 0;
			put_index = 0;
		}
		void str(const std::string& str) {
			buffer.clear();
			buffer.insert(buffer.begin(), str.begin(), str.end());
		}

		operator bool() {
			return !(eof);
		}
		bool operator !() {
			return !(bool)(*this);
		}
	};
	using string_stream_wrapper = basic_string_stream_wrapper<std::string>;

	/*template<typename T>
	class basic_buffered_stream {
	public:
		using string_type = T;
		using traits_type = typename string_type::traits_type;
		using char_type = typename traits_type::char_type;
		using int_type = typename traits_type::int_type;
		using pos_type = std::size_t;
		using off_type = int;
	private:
		std::size_t get_index = 0;
		std::size_t put_index = 0;
		bool eof = false;
	public:
		basic_string_stream_wrapper(string_type& buffer) : buffer(buffer) {}

		basic_string_stream_wrapper read(char_type* out, std::streamsize size) {
			size = std::min(size, (std::streamsize)(buffer.size() - get_index));

			std::copy_n(buffer.begin() + get_index, size, out);

			get_index += size;
			if (eof = get_index > buffer.size(); eof) {
				get_index = buffer.size();
			}
			return *this;
		}
		int_type peek() {}
		int_type get() {}

		pos_type tellg() {}
		basic_string_stream_wrapper& seekg(pos_type pos) {}
		basic_string_stream_wrapper& seekg(off_type pos, std::ios_base::seekdir dir) {}

		basic_string_stream_wrapper& write(const char_type* out, std::streamsize size) {}

		basic_string_stream_wrapper& put(char_type next_char) {}

		pos_type tellp() {}
		basic_string_stream_wrapper& seekp(pos_type pos) {}
		basic_string_stream_wrapper& seekp(off_type pos, std::ios_base::seekdir dir) {}

		void clear() {}
		void str(const std::string& str) {}

		operator bool() {}
		bool operator !() {}
	};
	using buffered_stream = basic_buffered_stream<std::string>;*/
}

#endif // STAMP_SERIALIZE_BUFFER_H
