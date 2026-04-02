#include <iostream>
#include <vector>
#include <stamp/reflect/reflect.h>
#include <stamp/reflect/reflect_ctypes.h>
#include <stamp/reflect/std/reflect_std.h>
#include <stamp/reflect/view.h>
#include <concepts>

using namespace stamp::reflect;

// 3. Member Pointers
struct Dummy {
	int test;
	float* my_ptr;
	Dummy* next;

	void my_func(int i) {
		std::cout << i << std::endl;
	}
};
namespace stamp::reflect {
	template<> struct reflect_traits<Dummy> {
		using type = Dummy;
		static constexpr string_literal space = "my";
		static constexpr string_literal name = "Dummy";
		static constexpr auto properties = std::tuple{
			reflect("test"_rf, &type::test),
			reflect("my_ptr"_rf, &type::my_ptr),
			reflect("next"_rf, &type::next)
		};
		static constexpr auto functions = std::tuple{
			reflect("my_func"_rf, &type::my_func),

			// for cv overloads, use:
			// reflect(tag::const_rf, "my_func"_rf, &type::my_func),
			// reflect(tag::none_rf, "my_func"_rf, &type::my_func),
		};
	};
}


int main(int argc, char** argv) {
	std::array<int, 10> v{1, 2, 3, 4, 5};

	{
		Dummy obj = {};
		obj.test = 4;
		view my_view{obj};
		std::cout << my_view.reflect_info().name << std::endl;
		std::cout << my_view.fetch("test").name() << std::endl;
		std::cout << my_view.fetch("test").to_string() << std::endl;
		std::cout << my_view.fetch("test").reflect_info().name << std::endl;
		std::cout << my_view.fetch("my_func").name() << std::endl;
		std::cout << my_view.fetch("my_func").to_string() << std::endl;
		std::cout << my_view.fetch("my_func").reflect_info().name << std::endl;
		int i = 17;
		my_view.fetch("my_func").invoke(i);
		my_view.fetch("my_func").invoke(i);
	}

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
