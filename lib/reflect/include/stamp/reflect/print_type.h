#ifndef STAMP_REFLECT_PRINT_TYPE_H
#define STAMP_REFLECT_PRINT_TYPE_H

namespace stamp::reflect {
	template <typename... Ts>
	struct print_type {
		static_assert(sizeof...(Ts) == -1, "Type inspection");
	};
}

// static void tmp_func() { print_type<my_type>{}; } -> prints out type info of `my_type`

#endif // STAMP_REFLECT_PRINT_TYPE_H