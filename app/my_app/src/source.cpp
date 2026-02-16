#include <iostream>
#include <vector>
#include <stamp/reflect/reflect.h>
#include <stamp/reflect/reflect_ctypes.h>
#include <stamp/reflect/std/reflect_std.h>

int main(int argc, char** argv) {
	std::array<int, 10> v{1, 2, 3, 4, 5};
	stamp::reflect::for_each_of_reflect<stamp::reflect::is_member_function, decltype(v)>([](auto member) {
		using type = typename decltype(member)::ptr_type;
		std::cout << member.name << " " << stamp::reflect::reflect_traits<type>::name << std::endl;
	});
	return 0;
}