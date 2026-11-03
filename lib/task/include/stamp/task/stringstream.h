// stamp/task/stringstream.h
#ifndef STAMP_TASK_STRINGSTREAM_H
#define STAMP_TASK_STRINGSTREAM_H

#include <stamp/task/stream.h>
#include <string>

namespace stamp::task {
	class co_string_stream_strand;

	class co_string_stream {
		std::string data;
	public:
		co_string_stream() {}
		co_string_stream(const std::string& init) {
			data = init;
		}

		co_string_stream(const co_string_stream&) = delete;
		co_string_stream(co_string_stream&&) = delete;
		co_string_stream& operator =(const co_string_stream&) = delete;
		co_string_stream& operator =(co_string_stream&&) = delete;

		co_string_stream_strand co_iostream_strand();
	};
	class co_string_stream_strand : co_stream_strand {
		co_string_stream* self;
	public:
		co_string_stream_strand(co_string_stream* self) : self(self) {}
		virtual ~co_string_stream_strand() {}
	protected:
		virtual bool do_eof() const {

		}
		virtual bool do_fail() const {

		}
		virtual bool do_bad() const {
			return false;
		}

		virtual std::size_t do_get_ppos() const {

		}
		virtual void do_set_ppos(std::size_t pos, co_stream_strand::seekdir) {

		}
		virtual std::size_t do_get_gpos() const {

		}
		virtual void do_set_gpos(std::size_t pos, co_stream_strand::seekdir) {

		}

		virtual std::size_t do_try_put_span(const char* span, std::size_t size) {

		}
		virtual std::size_t do_try_get_span(char* span, std::size_t size) {

		}

		virtual bool do_await_ready() {

		}
		virtual bool do_await_suspend(std::coroutine_handle<> h) {

		}
		virtual std::size_t do_await_resume() {

		}
	};

	inline co_string_stream_strand co_string_stream::co_iostream_strand() {
		return co_string_stream_strand(this);
	}
}

#endif // STAMP_TASK_STRINGSTREAM_H