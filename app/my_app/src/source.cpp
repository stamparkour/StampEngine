#include <iostream>
#include <vector>
#include <stamp/reflect/reflect.h>
#include <stamp/reflect/reflect_ctypes.h>
#include <stamp/reflect/std/reflect_std.h>
// #include <stamp/reflect/view.h>
#include <concepts>

using namespace stamp::reflect;

// Helper to make compile-time testing clean
template<typename T>
constexpr std::string_view get_name() {
	return std::string_view(reflect_name_v<T>);
}

// 1. Primitive Tests
static_assert(get_name<int>() == "int", "Int trait failed");
static_assert(get_name<short>() == "short", "Short trait failed");
static_assert(get_name<void>() == "void", "Void trait failed");

// 2. Modifiers
static_assert(get_name<int*>() == "int*", "Pointer trait failed");
static_assert(get_name<int&>() == "int&", "Reference trait failed");
static_assert(get_name<int const>() == "int const", "Const trait failed");
static_assert(get_name<int const*&>() == "int const*&", "Compound modifier failed");

// 3. Member Pointers
struct Dummy {
	int test;
};
namespace stamp::reflect {
	template<> struct reflect_traits<Dummy> {
		using type = Dummy;
		static constexpr auto name = string_literal<6>{ "Dummy" };
		static constexpr auto properties = std::tuple{
			reflect<"test">(&Dummy::test)
		};
	};
}
static_assert(get_name<int Dummy::*>() == "int Dummy::*", "Member variable failed");

// 4. Function Pointers
static_assert(get_name<void(*)()>() == "void (*)()", "Free function failed");
static_assert(get_name<int(*)(short, int)>() == "int (*)(short, int)", "Free function args failed");

// 5. Member Functions (The Final Boss)
static_assert(get_name<void(Dummy::*)()>() == "void (Dummy::*)()", "Member func failed");
static_assert(get_name<void(Dummy::*)() const>() == "void (Dummy::*)() const", "Const member func failed");

// The exact crazy pointer from your array test
using CrazyPtr = void (Dummy::*)(int, int (Dummy::*)(short, short));
static_assert(get_name<CrazyPtr>() == "void (Dummy::*)(int, int (Dummy::*)(short, short))", "Nested function ptr failed");


int main(int argc, char** argv) {
	std::array<int, 10> v{1, 2, 3, 4, 5};
	auto& tuple = stamp::reflect::reflect_functions_v<std::array<int, 10>>;
	stamp::reflect::for_each(tuple, [](auto member) {
		using type = decltype(member);
		using ptr_type = typename decltype(member)::ptr_type;
		std::cout << member.name() << " -> " << stamp::reflect::reflect_name_v<ptr_type> << std::endl;
		
		stamp::reflect::for_each(member.attributes(), [](auto attrib) {
			std::cout << "attribute: " << attrib.name << std::endl;
		});
	});
	std::cout << std::endl;
	auto& t3 = stamp::reflect::reflect_constructors_v<std::array<int, 10>>;
	stamp::reflect::for_each(t3, [](auto member) {
		using type = decltype(member);
		using ptr_type = typename decltype(member)::ptr_type;
		std::cout << member.name() << " -> " << stamp::reflect::reflect_name_v<ptr_type> << std::endl;

		stamp::reflect::for_each(member.attributes(), [](auto attrib) {
			std::cout << "attribute: " << attrib.name << std::endl;
			});
		});
	std::cout << std::endl;
	auto& t2 = stamp::reflect::reflect_properties_v<Dummy>;
	stamp::reflect::for_each(t2, [](auto member) {
		using type = decltype(member);
		using ptr_type = typename decltype(member)::ptr_type;
		std::cout << member.name() << " -> " << stamp::reflect::reflect_name_v<ptr_type> << std::endl;

		stamp::reflect::for_each(member.attributes(), [](auto attrib) {
			std::cout << "attribute: " << attrib.operator_name << std::endl;
			});
		});

	return 0;
}
