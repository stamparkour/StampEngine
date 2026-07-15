// stamp/reflect/meta_tuple.h
#ifndef STAMP_REFLECT_META_TUPLE_H
#define STAMP_REFLECT_META_TUPLE_H

/**
* @file
* @brief Compile-time helper functions for tuples.
*/

#include <tuple>
#include <cstddef>

namespace stamp::reflect {
	/**
	* @brief runs a unary function on each element of the tuple.
	* 
	* The function is called with std::tuple_element<N, Tuple> of the nth element of the tuple.
	* Use T::type to retrieve the type information of the std::tuple_element.
	* 
	* example:
	* ``` c++
	* stamp::reflect::for_each<int, float, double>([]<typename T>(T) {
	*	using type = typename T::type;
	* });
	* ```
	*/
	template<typename Tuple, typename UnaryFunc>
	constexpr void for_each(UnaryFunc func) {
		[&] <std::size_t... Is>(std::index_sequence<Is...>) {
			(func(std::tuple_element<Is, Tuple>{}), ...);
		}(std::make_index_sequence<std::tuple_size_v<Tuple>>{});
	}

	//for_each(args, [&]<typename P>(P p) {
	//	using type = P::type;

	// runs the Func on all members of the tuple<Arg...>
	template<typename UnaryFunc, typename... Arg>
	constexpr void for_each(const std::tuple<Arg...>& tuple, UnaryFunc func) {
		std::apply([&](const Arg&... arg) { (func(arg), ...); }, tuple);
	}
	template<typename UnaryFunc, typename... Arg>
	constexpr void for_each(std::tuple<Arg...>& tuple, UnaryFunc func) {
		std::apply([&](Arg&... arg) { (func(arg), ...); }, tuple);
	}

	// runs the Func on all the types of the tuple<Arg...> that match Pred. passes a std::tuple_element to the func
	template<template<typename> typename Pred, typename Tuple, typename UnaryFunc>
	constexpr void for_each_of(UnaryFunc func) {
		for_each<Tuple>([&]<typename type>(type&& arg) {
			if constexpr (Pred<type>::value) {
				func(std::forward<type>(arg));
			}
		});
	}


	// runs the Func on all members of the tuple<Arg...> that match Pred
	template<template<typename> typename Pred, typename Func, typename... Arg>
	constexpr void for_each_of(const std::tuple<Arg...>& tuple, Func func) {
		for_each(tuple, [&]<typename Arg>(Arg&& arg) {
			using type = std::decay_t<decltype(arg)>;
			if constexpr (Pred<type>::value) {
				func(std::forward<Arg>(arg));
			}
		});
	}


	template<typename Tuple, typename Func>
	constexpr Tuple for_each_construct(Func func) {
		return [&] <std::size_t... Is>(std::index_sequence<Is...>) ->Tuple {
			return Tuple{func(std::tuple_element<Is, Tuple>{})...};
		}(std::make_index_sequence<std::tuple_size_v<Tuple>>{});
	}

	/*
	template<template<typename> typename Pred, typename... Arg>
	consteval std::size_t count_of(const std::tuple<Arg...>& tuple) {
		std::size_t count = 0;
		for_each_of<Pred>(tuple, [&](auto& arg) {
			count++;
			});
		return count;
	}
	*/
}

#endif // STAMP_REFLECT_META_TUPLE_H