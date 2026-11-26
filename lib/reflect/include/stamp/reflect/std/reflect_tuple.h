// stamp/reflect/std/reflect_tuple.h
#pragma once
#ifndef STAMP_REFLECT_STD_REFLECT_TUPLE_H
#define STAMP_REFLECT_STD_REFLECT_TUPLE_H

#include <stamp/reflect/reflect_traits.h>
#include <stamp/reflect/reflect_types.h>
#include <tuple>

namespace stamp::reflect::desc {
	template<typename... Arg>
	struct reflect_traits<std::tuple<Arg...>> {
		using type = std::tuple<Arg...>;
		static constexpr string_literal space = "std::";
		static constexpr string_literal name = concat_cstring_v<"tuple<", comma_list_string_literals_v<traits::name_v<Arg>...>, ">">;
		static constexpr string_literal basic_name = "tuple";
		static constexpr string_literal full_name = concat_cstring_v<"std::tuple<", comma_list_string_literals_v<traits::full_name_v<Arg>...>, ">">;
		
		// TODO: generate getter/setters from args
		static constexpr auto properties = std::tuple{
			// reflect("first"_rf, &type::first)...
		};
		
		static constexpr auto constructors = std::tuple{
			reflect_constructor<type, Arg...>()
		};
	};

}

#endif // STAMP_REFLECT_STD_REFLECT_TUPLE_H