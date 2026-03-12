#pragma once
#ifndef STAMP_REFLECT_TAG_H
#define STAMP_REFLECT_TAG_H

#include <stamp/reflect/string_literal.h>
#include <concepts>

namespace stamp::reflect {
	namespace tag {
		struct generic_tag_t {};
		struct named_generic_tag_t : generic_tag_t{};
		template<string_literal S>
		struct named_tag_t : named_generic_tag_t {
			static constexpr auto name = S;
		};

		template<typename T>
		constexpr string_literal to_string_v = "unknown tag";
		template<std::derived_from<named_generic_tag_t> T>
		constexpr string_literal to_string_v<T> = T::name;
	}
	template<string_literal S>
	constexpr tag::named_tag_t<S> operator ""_rf() {
		return {};
	}

	namespace concepts {
		template<typename T>
		concept is_tag_c = std::derived_from<T, stamp::reflect::tag::generic_tag_t>;
	}
}

#endif // STAMP_REFLECT_TAG_H
