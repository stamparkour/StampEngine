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

using namespace stamp::reflect;
using namespace stamp::serialize;

// 3. Member Pointers
struct Dummy {
	int test;
	float my_ptr;


	void my_func(int& i) {
		std::cout << i << std::endl;
		i = 13;
	}
};
template<> struct stamp::reflect::reflect_traits<Dummy> {
	using type = Dummy;
	static constexpr string_literal space = "my";
	static constexpr string_literal name = "Dummy";
	static constexpr auto properties = std::tuple{
		reflect("test"_rf, &type::test),
		reflect("my_ptr"_rf, &type::my_ptr)
	};
	static constexpr auto functions = std::tuple{
		reflect("my_func"_rf, &type::my_func),

		// for cv overloads, use:
		// reflect(tag::const_rf, "my_func"_rf, &type::my_func),
		// reflect(tag::none_rf, "my_func"_rf, &type::my_func),
	};
};

struct my_obj_t {
	std::vector<std::pair<std::string, int>> vec;
	float my_num;
};

template<> struct stamp::reflect::reflect_traits<my_obj_t> {
	using type = my_obj_t;
	static constexpr string_literal name = "Dummy_obj_tmy";
	static constexpr auto properties = std::tuple{
		reflect("vec"_rf, &type::vec),
		reflect("my_num"_rf, &type::my_num)
	};
};

int main(int argc, char** argv) {
	std::array<int, 10> v{1, 2, 3, 4, 5};

	std::cout << (std::string_view)stamp::reflect::traits::name_v<std::pair<int, float> const>;
	for_each_reflect_member_properties<std::pair<int, float> const>([&]<typename P>(const P & property) {
		using value_type = typename P::value_type;

		std::cout << (std::string_view)property.name();
	});

	{
		Dummy obj = {};
		obj.test = 4;
		view my_view{obj};
		std::cout << my_view.reflect_info().name << std::endl;
		std::cout << my_view.fetch("test").to_string() << std::endl;
		std::cout << my_view.fetch("test").reflect_info().name << std::endl;
		std::cout << my_view.fetch("my_func").reflect_info().name << std::endl;

		int i = 17;
		my_view.fetch("my_func").invoke(i);
		my_view.fetch("my_func").invoke(i);
	}

	my_obj_t obj = {};
	obj.vec.push_back({"hi",2});
	obj.vec.push_back({"frog",-3});
	obj.vec.push_back({"dig",1982});
	obj.my_num = 12.48;
	std::stringstream stream;

	stamp::serialize::json_formatter format{
		.nested_str = "",
		.newline_str = "",
		.spacing_str = "",
		.force_object_pairs = false,
		.force_string_char_array = false
	};

	std::cout << stamp::serialize::json(obj, format) << std::endl;

	stream << stamp::serialize::json(obj, format);

	my_obj_t oobj = {};
	stream >> stamp::serialize::json(oobj);


	
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
