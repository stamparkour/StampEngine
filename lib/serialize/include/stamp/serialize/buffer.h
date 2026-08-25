// stamp/serialize/buffer.h

#ifndef STAMP_SERIALIZE_BUFFER_H
#define STAMP_SERIALIZE_BUFFER_H

#include <cstddef>
#include <span>
#include <array>

namespace stamp::serialize {
	
	template<typename T>
	class basic_buffer;

	template<typename T>
	class basic_buffer<std::array<T>> {
	public:
		using buffer_type = basic_buffer<std::array<T>>;
		using container_type = std::array<T>;
	private:
	public:
		//co_await
		auto read(std::size_t size) {
			struct await_t {
				buffer_type& buffer;
				bool await_ready() const noexcept {
					return true;
				}
				void await_suspend(const std::coroutine_handle<void>&) noexcept {}
				auto await_resume() noexcept {
					
				}
			};
			return await_t{ *this };
		}
		//co_await
		auto write(std::size_t size);
	};
}

#endif // STAMP_SERIALIZE_BUFFER_H
