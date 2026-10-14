// stamp/core/assert.h

#ifndef STAMP_CORE_ASSERT_H
#define STAMP_CORE_ASSERT_H

#include <string>
#include <string_view>
#include <stdexcept>
#include <source_location>

#if !defined(NDEBUG) || defined(_DEBUG)
#define STAMP_CORE_DEBUG
#endif

#if defined(_MSC_VER)
#define FORCE_BREAKPOINT() __debugbreak()
#elif defined(__GNUC__) || defined(__clang__)
#define FORCE_BREAKPOINT() __builtin_trap()
#else
#define FORCE_BREAKPOINT() do { *(volatile int*)0 = 0; } while(0) // Fallback crash
#endif

namespace stamp::core {
#ifdef STAMP_CORE_DEBUG
	static inline constexpr bool is_debug_v = true;
#else
	static inline constexpr bool is_debug_v = false;
#endif

	inline void s_assert(bool condition, const std::string_view& str = {}, std::source_location sl = std::source_location::current()) {
		if constexpr (!is_debug_v) return;
		if (condition) return;

		std::string msg{str};
		msg = std::string{} + sl.file_name() + " " + std::to_string(sl.line()) + " " + sl.function_name() + ": " + msg;
		FORCE_BREAKPOINT();
		throw std::runtime_error(msg);
	}
	inline void s_assert(bool condition, const std::string& str, std::source_location sl = std::source_location::current()) {
		s_assert(condition, std::string_view(str), sl);
	}
	inline void s_assert(bool condition, const char* str, std::source_location sl = std::source_location::current()) {
		s_assert(condition, std::string_view(str), sl);
	}
}

#endif // STAMP_CORE_ASSERT_H
