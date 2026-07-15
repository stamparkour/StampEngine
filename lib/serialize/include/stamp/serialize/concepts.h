// stamp/serialize/concepts.h
#ifndef STAMP_SERIALIZE_CONCEPTS_H
#define STAMP_SERIALIZE_CONCEPTS_H

#include <concepts>
#include <coroutine>

namespace stamp::serialize::concepts {
	template<typename T>
	concept awaitor_c =
		requires (T a, std::coroutine_handle<> h) {
			{ a.await_ready() } -> std::convertible_to<bool>;
			a.await_suspend(h);
			a.await_resume();
		};
	template<typename T>
	concept awaitable_c = 
		awaitor_c<T> ||
		requires (T a) {
			{ a.operator co_await() } -> awaitor_c;
		} ||
		requires (T&& a) {
			{ operator co_await(a) } -> awaitor_c;
		};

	template<typename F>
	constexpr auto awaitable_function_v = awaitable_c<std::invoke_result_t<F>>;

	template<typename T>
	concept istream_c =
		requires {
			typename T::char_type;
			typename T::int_type;
		} &&
		requires(T& v, T::char_type* buffer, std::streamsize size) {
			v.read(buffer, size);
			{ v.peek() } -> std::same_as<typename T::int_type>;
			{ v.get() } -> std::same_as<typename T::int_type>;
			{ static_cast<bool>(v) } -> std::same_as<bool>;
			{ !v } -> std::same_as<bool>;
		};

	template<typename T>
	concept awaitable_istream_c =
		istream_c<T> &&
		requires(T & v, T::char_type * buffer, std::streamsize size) {
			{ v.read(buffer, size) } -> awaitable_c;
			{ v.peek() } -> awaitable_c;
			{ v.get() } -> awaitable_c;
		};

	template<typename T>
	concept ostream_c =
		requires {
			typename T::char_type;
		} &&
			requires(T& v, typename T::char_type* buffer, std::streamsize size, typename T::char_type next_char) {
			v.write(buffer, size);
			v.put(next_char);
			{ static_cast<bool>(v) } -> std::same_as<bool>;
			{ !v } -> std::same_as<bool>;
		};

	template<typename T>
	concept awaitable_ostream_c =
		ostream_c<T> &&
		requires(T& v, typename T::char_type * buffer, std::streamsize size, typename T::char_type next_char) {
			{ v.write(buffer, size) } -> awaitable_c;
			{ v.put(next_char) } -> awaitable_c;
		};

	template<typename T>
	concept json_key = std::convertible_to<std::string, T>;

	template<typename Container>
	concept array_iterable =
		requires {
			typename Container::iterator;
			typename Container::value_type;
		} &&
		std::forward_iterator<typename Container::iterator>&&
		requires (Container c, typename Container::iterator i, typename Container::value_type v) {
			{ std::begin(c) } -> std::same_as<typename Container::iterator>;
			{ std::end(c) } -> std::same_as<typename Container::iterator>;
			{ *i } -> std::same_as<typename Container::value_type&>;
			{ *i = v } -> std::same_as<typename Container::value_type&>;
		};
	template<typename Container>
	concept array_json_pair_iterable =
		array_iterable<Container> &&
		requires {
		typename Container::value_type::first_type;
		typename Container::value_type::second_type;
	}&&
		json_key<typename Container::value_type::first_type>;


	template<typename Container>
	concept inserter_iterable =
		array_iterable<Container> &&
		requires (Container c, typename Container::iterator i, typename Container::value_type v) {
			c.insert(i, v);
			{ std::inserter(c, i) } -> std::same_as<std::insert_iterator<Container>>;
		};

	template<typename Container>
	concept inserter_json_pair_iterable =
		inserter_iterable<Container> &&
		requires {
			typename Container::value_type::first_type;
			typename Container::value_type::second_type;
		}&&
		json_key<typename Container::value_type::first_type>;

	
};

#endif // STAMP_SERIALIZE_CONCEPTS_H