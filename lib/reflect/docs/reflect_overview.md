@page reflect_page Reflect

# Overview

The stamp::reflect library provides compile-time [reflections][1] for C++20. 
The library uses explicitly defined reflect_trait to reflect any type.
Each reflect_trait contains reflections for names, member functions and properties, operator overloads (and later, inheritance).
Further, the library provides compile-time string_literal.h and meta_tuple.h to facilitate reflections.

string_literal.h contains several functions and classes to facilitate easy use of strings as template arguments. 
Such as, concatinating string_literals at compile time, and querying the length of a string_literal.

meta_tuple.h contains several functions that can itterate over every member of a tuple.

# Reflections

## What is a Reflection

[Reflections][1] are used to make generic code for using or displaying members without explicitly referencing them. 
Reflections are similar to how many scripting languages (javascript, lua) handle objects--a programmer can iterate over all members without knowing the names.

Within the Stamp Engine project, reflections will be used for python and lua bindings, and displaying debug information about any object.

## Reflecting a Class

In order to reflect a class, you must create a reflect_trait overload.

The simplest implemention of reflect_trait is:

``` c++
#include <stamp/reflect/reflect.h>

struct stamp::reflect::reflect_traits<MyType> {
	static constexpr string_literal name = "MyType";
	static constexpr auto properties = std::tuple{
		reflect("val1"_rf,  &MyType::val1),
		reflect("val2"_rf,  &MyType::val2)
	};
};
```

To access the reflections, call @ref stamp::reflect::for_each_reflect_member_properties "for_each_reflect_member_properties":
``` c++
stamp::reflect::for_each_reflect_member_properties<MyType>([]<typename P>(P& property) {
	using value_type = typename P::value_type;
	string_literal name = property.name();
	value_type MyType::* memberPtr = property.member_ptr();
});
```
Note that the lambda's parameter's type is stamp::reflect::member_property_t.

[1]: https://en.wikipedia.org/wiki/Reflective_programming
