#include <iostream>
#include <vector>
#include <map>
#include <stamp/reflect/reflect.h>
#include <stamp/reflect/reflect_ctypes.h>
#include <stamp/reflect/std/reflect_std.h>
#include <stamp/reflect/view/view.h>
#include <stamp/serialize/json.h>
#include <concepts>
#include <sstream>
#include <stamp/serialize/stream.h>
#include <stamp/serialize/ordered_binary.h>
#include <fstream>
#include <filesystem>

using namespace stamp::reflect;
using namespace stamp::serialize;


struct my_obj_t {
	float* my_ptr;
	int my_value = 39;
};

template<> struct stamp::reflect::reflect_traits<my_obj_t> {
	using type = my_obj_t;
	static constexpr string_literal name = "my_obj_t";
	static constexpr auto properties = std::tuple{
		reflect("my_ptr"_rf, &type::my_ptr),
		reflect("my_value"_rf, &type::my_value)
	};
};

int main(int argc, char** argv) {


	float value = 12.94;
	my_obj_t obj = {};
	obj.my_ptr = &value;

	std::cout << std::filesystem::current_path() << std::endl;
	std::stringstream file{std::ios::binary | std::ios::in | std::ios::out};
	stamp::serialize::pointer_track_registry tracker1{};

	file << stamp::serialize::ordered_binary(obj, tracker1);

	my_obj_t obj2 = {};
	stamp::serialize::pointer_track_registry tracker2{};

	file >> stamp::serialize::ordered_binary(obj2, tracker2);

	
	std::cout << "done" << std::endl;

	/*auto& tuple = stamp::reflect::traits::functions_v<std::array<int, 10>>;
	stamp::reflect::for_each(tuple, [](auto member) {
		using type = decltype(member);
		using ptr_type = typename decltype(member)::ptr_type;
		std::cout << member.name() << " -> " << stamp::reflect::traits::name_v<ptr_type> << std::endl;
		
		stamp::reflect::for_each(member.attributes(), [](auto attrib) {
			std::cout << "attribute: " << attrib.name << std::endl;
		});
	});
	std::cout << std::endl;
	auto& t3 = stamp::reflect::traits::constructors_v<std::array<int, 10>>;
	stamp::reflect::for_each(t3, [](auto member) {
		using type = decltype(member);
		using ptr_type = typename decltype(member)::ptr_type;
		std::cout << member.name() << " -> " << stamp::reflect::traits::name_v<ptr_type> << std::endl;

		stamp::reflect::for_each(member.attributes(), [](auto attrib) {
			std::cout << "attribute: " << attrib.name << std::endl;
			});
		});
	std::cout << std::endl;
	auto& t2 = stamp::reflect::traits::properties_v<Dummy>;
	stamp::reflect::for_each(t2, [](auto member) {
		using type = decltype(member);
		using ptr_type = typename decltype(member)::ptr_type;
		std::cout << member.name() << " -> " << stamp::reflect::traits::name_v<ptr_type> << std::endl;

		stamp::reflect::for_each(member.attributes(), [](auto attrib) {
			std::cout << "attribute: " << attrib.operator_name << std::endl;
			});
		});*/

	return 0;
}
