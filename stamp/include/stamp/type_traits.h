#ifndef STAMP_TYPE_TRAITS_H
#define STAMP_TYPE_TRAITS_H

#include <type_traits>

namespace stamp {
	template<typename T> 
	struct is_shared_ptr : std::false_type {};
	template<typename T> 
	struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};
	template<typename T>
	constexpr bool is_shared_ptr_v = is_shared_ptr<T>::value;
}

#endif // STAMP_TYPE_TRAITS_H
