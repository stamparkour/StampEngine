// stamp/reflect/std/reflect_pair.h
#pragma once
#ifndef STAMP_REFLECT_STD_REFLECT_PAIR_H
#define STAMP_REFLECT_STD_REFLECT_PAIR_H

#include <stamp/reflect/reflect_traits.h>
#include <stamp/reflect/reflect_types.h>
#include <vector>

namespace stamp::reflect {
	template<typename T1, typename T2>
	struct reflect_traits<std::pair<T1, T2>> {
		using type = std::pair<T1, T2>;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"pair<", traits::name_v<T1>, ",", traits::name_v<T2>, ">">;
		static constexpr string_literal basic_name = "pair";
		static constexpr string_literal full_name = concat_cstring_v<"std::pair<", traits::full_name_v<T1>, ",", traits::name_v<T2>, ">">;
		static constexpr auto properties = std::tuple{
			reflect("first"_rf, &type::first),
			reflect("second"_rf, &type::second),
		};
	};
}

#endif // STAMP_REFLECT_STD_REFLECT_VECTOR_H