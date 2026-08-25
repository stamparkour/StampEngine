// stamp/task/co_stream.h

#ifndef STAMP_TASK_CO_STREAM_H
#define STAMP_TASK_CO_STREAM_H

#include <stamp/task/coroutine.h>
#include <stamp/task/generic_promise.h>
#include <memory>

namespace stamp::task {
	template<typename Buffer>
	class co_stream_base {
	public:
		using buffer_type = Buffer;
	private:
		buffer_type* buffer;
	public:
		co_base_stream(buffer_type* buffer) : buffer(buffer) {}
		co_base_stream(const co_base_stream&) = delete;
		co_base_stream& operator=(const co_base_stream&) = delete;
		~co_base_stream() {
			if (!buffer) return;
			buffer->close();
			buffer = nullptr;
		}

		buffer_type* buf() const {
			return buffer;
		}
		buffer_type* set_buf(buffer_type* buf) {
			auto old = buffer;
			buffer = buf;
			return old;
		}
	};

	template<typename Buffer>
	class co_istream : public virtual co_stream_base<Buffer> {
	public:
		using buffer_type = Buffer;
	private:
	public:
		co_istream(buffer_type* buffer) : co_base_stream(buffer) {}
		co_istream(const co_istream&) = delete;
		co_istream& operator=(const co_istream&) = delete;

		// provides a buffer of 'size' to read
		// for(const auto& v : co_await read(size)) {}
		// return value must be able to co_await.
		// return value of co_await must be an iterator of at least 'size' elements.
		auto read(std::size_t size) {
			return this->buffer->read(size);
		}
	};

	template<typename Buffer>
	class co_ostream : public virtual co_stream_base<Buffer> {
	public:
		using buffer_type = Buffer;
	private:
	public:
		co_ostream(buffer_type* buffer) : co_base_stream(buffer) {}
		co_ostream(const co_ostream&) = delete;
		co_ostream& operator=(const co_ostream&) = delete;

		// provides a buffer of 'size' to write
		// for(auto& v : co_await write(size)) {}
		// return value must be able to co_await.
		// return value of co_await must be an iterator of at least 'size' elements.
		auto write(std::size_t size) {
			return this->buffer->write(size);
		}
	};

	template<typename Buffer>
	class co_stream : public virtual co_istream<Buffer>, public virtual co_ostream<Buffer> {
	public:
		using buffer_type = Buffer;
	public:
		co_stream(buffer_type* buffer) : co_istream(buffer), co_ostream(buffer) {}
		co_stream(const co_stream&) = delete;
		co_stream& operator=(const co_stream&) = delete;
	};

	class generic_read_buffer {
		virtual ~generic_read_buffer() = default;
		virtual std::size_t size() const = 0;
		virtual /* iterator */ begin();
		virtual /* iterator */ end();
	};
	class generic_write_buffer {
		virtual ~generic_write_buffer() = default;
	};

	class co_stream_generic_buffer {
	public:
		virtual ~co_stream_polymorphic_buffer() = default;
		virtual generic_promise_container<generic_read_buffer> read(std::size_t size) = 0;
		virtual generic_promise_container<generic_write_buffer> write(std::size_t size) = 0;
		virtual void close() = 0;
	};
	template<typename T>
	class co_stream_mixin_buffer : public co_stream_polymorphic_buffer, public T {

	};
}

#endif // STAMP_TASK_CO_STREAM_H