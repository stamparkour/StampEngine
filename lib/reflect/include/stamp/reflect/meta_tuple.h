#pragma once
#ifndef STAMP_REFLECT_META_TUPLE_H
#define STAMP_REFLECT_META_TUPLE_H

#include <tuple>
#include <cstddef>

namespace stamp::reflect {
	// runs the Func on all the types of the tuple<Arg...> that match Pred. passes a std::tuple_element to the func
	template<typename Tuple, typename Func>
	constexpr void for_each(Func func) {
		[&] <std::size_t... Is>(std::index_sequence<Is...>) {
			(func(std::tuple_element<Is, Tuple>{}), ...);
		}(std::make_index_sequence<std::tuple_size_v<Tuple>>{});
	}

	// runs the Func on all members of the tuple<Arg...>
	template<typename Func, typename... Arg>
	constexpr void for_each(const std::tuple<Arg...>& tuple, Func func) {
		std::apply([&](const Arg&... arg) { (func(arg), ...); }, tuple);
	}

	// runs the Func on all the types of the tuple<Arg...> that match Pred. passes a std::tuple_element to the func
	template<template<typename> typename Pred, typename Tuple, typename Func>
	constexpr void for_each_of(Func func) {
		for_each<Tuple>([&](auto arg) {
			using type = decltype(arg)::type;
			if constexpr (Pred<type>::value) {
				func(arg);
			}
		});
	}


	// runs the Func on all members of the tuple<Arg...> that match Pred
	template<template<typename> typename Pred, typename Func, typename... Arg>
	constexpr void for_each_of(const std::tuple<Arg...>& tuple, Func func) {
		for_each(tuple, [&](auto& arg) {
			using type = std::decay_t<decltype(arg)>;
			if constexpr (Pred<type>::value) {
				func(arg);
			}
		});
	}

	template<template<typename> typename Pred, typename... Arg>
	consteval std::size_t count_of(const std::tuple<Arg...>& tuple) {
		std::size_t count = 0;
		for_each_of<Pred>(tuple, [&](auto& arg) {
			count++;
			});
		return count;
	}
}

#endif // STAMP_REFLECT_META_TUPLE_H