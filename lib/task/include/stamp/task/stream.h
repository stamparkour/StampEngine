// stamp/task/stream.h
#ifndef STAMP_TASK_STREAM_H
#define STAMP_TASK_STREAM_H

#include <coroutine>
#include <cstdlib>
#include <concepts>
#include <stamp/task/coroutine.h>

namespace stamp::task {
	// 
	/**
	* @brief interface for coroutine stream.
	* each strand is assumed to have one owner that is running at a time (no syncing)
	* assumes a co_await before destruction.
	* 
	* example:
	* ``` cpp
	* co_stream_strand* strand;
	* strand.set_ppos(0, co_stream_strand::beg);
	* strand.put_span("Hello", 5);
	* co_await strand; // syncs every action beforehand.
	* ```
	*/
	class co_stream_strand {
	public:
		enum seekdir : std::size_t {
			cur,
			beg,
			end
		};
	protected:
		virtual bool do_eof() const = 0;
		virtual bool do_fail() const = 0;
		virtual bool do_bad() const = 0;

		virtual std::size_t do_get_ppos() const = 0;
		virtual void do_set_ppos(std::size_t pos, seekdir) = 0;
		virtual std::size_t do_get_gpos() const = 0;
		virtual void do_set_gpos(std::size_t pos, seekdir) = 0;

		virtual std::size_t do_try_put_span(const char* span, std::size_t size) = 0;
		virtual std::size_t do_try_get_span(char* span, std::size_t size) = 0;

		virtual bool do_await_ready() = 0;
		virtual bool do_await_suspend(std::coroutine_handle<> h) = 0;
		virtual std::size_t do_await_resume() = 0;

	public:
		co_stream_strand(const co_stream_strand&) = delete;
		co_stream_strand(co_stream_strand&&) = default;
		co_stream_strand& operator =(const co_stream_strand&) = delete;
		co_stream_strand& operator =(co_stream_strand&&) = default;

		virtual ~co_stream_strand() = 0;

		bool eof() const { return do_eof(); }
		bool fail() const { return do_fail(); }
		bool bad() const { return do_bad(); }
		bool good() const { return !(eof() || fail() || bad()); }
		explicit operator bool() const { return good(); }

		std::size_t get_ppos() const { return do_get_ppos(); }
		void set_ppos(std::size_t pos, seekdir d) { do_set_ppos(pos, d); }
		std::size_t get_gpos() const { return do_get_gpos(); }
		void set_gpos(std::size_t pos, seekdir d) { do_set_gpos(pos, d); }

		// returns amount of characters wrote
		std::size_t try_put_span(const char* span, std::size_t size) { return do_try_put_span(span, size); }
		// returns amount of characters read
		std::size_t try_get_span(char* span, std::size_t size) { return do_try_get_span(span, size); }

		// puts full span
		// bool success = co_await put_span(...);
		coroutine<bool> put_span(const char* span, std::size_t size) {
			while (size > 0) {
				std::size_t p = try_put_span(span, size);
				size -= p;
				span += p;
				if (!(co_await *this)) co_return false;
			}
			co_return true;
		}
		// gets full span
		// std::size_t total_read_count = co_await get_span(...);
		coroutine<std::size_t> get_span(char* span, std::size_t size) {
			std::size_t total_read = 0;
			while (size > 0) {
				std::size_t p = try_put_span(span, size);
				size -= p;
				span += p;
				total_read += p;
				if (!(co_await *this)) break;
			}
			co_return total_read;
		}

		// syncing strand
		bool await_ready() { return do_await_ready(); }
		bool await_suspend(std::coroutine_handle<> h) { return do_await_suspend(h); }
		// returns equivalend to `good()`
		std::size_t await_resume() { return do_await_resume(); }
	};

	template<typename T>
	concept is_co_istream =
		requires (T a) {
			{ a.co_istream_strand() } -> std::derived_from<co_stream_strand>;
		};
	template<typename T>
	concept is_co_ostream =
		requires (const T a) {
			{ a.co_ostream_strand() } -> std::derived_from<co_stream_strand>;
		};
	template<typename T>
	concept is_co_iostream =
		is_co_istream<T> ||
		is_co_ostream<T> ||
		requires (T a) {
			{ a.co_iostream_strand() } -> std::derived_from<co_stream_strand>;
		};
}

#endif // STAMP_TASK_STREAM_H