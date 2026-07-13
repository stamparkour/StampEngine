The header-only `stamp::reflect` library provides noninvasive compile-time reflections. These reflection can be accessed through several compile time accessors.

# Table of Contents
- [Why Use stamp::reflect?](#why-use-stampreflect?)
	- [What about C++26 Reflections?](#what-about-c-26-reflections)
- [CMake](#cmake)
- [Usage Guide](#usage-guide)
	- [Creating Reflections](#creating-reflections)
	- [Structure of reflect_traits](#structure-of-reflect_traits)
	- [Using Reflections](#using-reflections)
	- [Trait Accessors](#trait-accessors)
- [string_literal](#string_literal)
	- [Concatenate string_literal](#concatenate-string_literal)
	- [Comma Separated Concatenate string_literal](#comma-separated-concatenate-string_literal)
- [Meta Tuple](#meta-tuple)
	- [for_each](#for_each)
	- [for_each_construct](#for_each_construct)
- [Member Function Traits](#member-function-traits)
	- [Member Function Overload Tags](#member-function-overload-tags)
# Why Use stamp::reflect

There are many other C++20 reflection libraries out there, so why choose `stamp::reflect`? 

`stamp::reflect` provides compile-time reflection information through noninvasive class external class definitions and allows for custom compile time attributes for each member and type.
These compile-time reflection can then be accessed at runtime or other compile-time code (such as template parameters).

With every reflect library, there usually comes some form of serialization or scripting binding. With `stamp::reflect`, I am planning to unify several of these libraries under one uniform reflection library. Some libraries that will work with `stamp::reflect` are:
- Sol2/Lua
- PyBind11

`stamp::reflect` will also provide serialization (native or through other libraries) for several formats, such as:
- binary
- json
- toml
See [[Serialize]] for documentation about serializing reflected objects.

### What about C++26 Reflections?

I needed a library that does all of the above now, and I wanted this project to be for older versions of C++.

I plan to add C++26 reflections when that time comes. But for now, I will stick with this implementation.
# CMake

To use the reflect library, add the following to your `CMakeLists.txt`:
```cmake
# import the stamp package
find_package(stamp REQUIRED)

#include the reflect library
target_link_libraries(your_target PRIVATE stamp::reflect)
```


# Usage Guide

include  `stamp/reflect/reflect.h` header file in your code to use reflections.

## Creating Reflections

To implement reflections for any class, create a template specialization of the `reflect_traits` struct.
Make sure you are in the `stamp::reflect` namespace when creating the specialization.
```cpp
template<>
struct stamp::reflect::reflect_traits<my_class> {
	using type = my_class;
};
```

**Note** that you must add the `using type = my_type` to the reflections to make a valid reflection.

Next, add the class name to the reflect struct.
```cpp
template<>
struct stamp::reflect::reflect_traits<my_class> {
	using type = my_class;
	static constexpr string_literal name = "my_class";
};
```

Finally, construct a tuple of members you want to reflect. 
```cpp
template<>
struct stamp::reflect::reflect_traits<my_class> {
	using type = my_class;
	static constexpr string_literal name = "my_class";
	static constexpr auto properties = std::tuple{
		reflect("prop_1", my_class::prop_1),
		reflect("prop_2", my_class::prop_2)
		// etc.
	};
};
```

Once you're added your reflections, you can use any of the `stamp::reflect::traits` accessors on the new type.

## Private Member Reflections

To have private member reflections, you must add a friend statement to your class.
```cpp
template<typename T>
friend class stamp::reflect::reflect_traits;
```

If you **cannot** access the source code for a class, then I would recommend using Marton's [Access Private](https://github.com/martong/access_private?tab=readme-ov-file) library. The member pointer retrieved from the Access Private library can be placed in the second parameter of the `reflect` function.

If you need access to a protected member, then you could use a [Mixin](https://en.wikipedia.org/wiki/Mixin).
```cpp
template<typename T>
class expose_protected : public T {
	template<typename T>
	friend class stamp::reflect::reflect_traits;
};

//...
reflect("protected_prop"_rf, &expose_protected<my_class>::protected_prop)
//...
```

## Structure of reflect_traits

The full user definition of a `reflect_trait` is:

```cpp
template<typename T>
struct stamp::reflect::reflect_traits<my_class<T>> {
	using type = my_class<T>;
	static constexpr string_literal space = "my_namespace";
	static constexpr string_literal name = concat_cstring_v<"my_class<", traits::name_v<T>,">">;
	static constexpr string_literal basic_name = "my_class";
	static constexpr string_literal full_name = concat_cstring_v<"my_namespace::my_class<",traits::full_name_v<T>,">">;
	
	static constexpr auto properties = std::tuple{
		reflect("prop_1", &my_class::prop_1),
		reflect("prop_2", &my_class::prop_2)
		// etc.
	};
};
```

`full_name` and `basic_name` are optional members. 
When using trait accessors, these are defaulted to:
 - `full_name` = `space` + `"::"` + `name`.
 - `basic_name` = `name`

## Using Reflections

To use your reflections, use `stamp::reflect::traits::properties_v<T>`.
This accessor will return a constexpr tuple of the reflected properties.
Each reflected property will contain the following members:

```cpp
// reflected property members:

using ptr_type = /* member_ptr type */;
using value_type = /* value type of pointer */;
using class_type = /* base class type of pointer */;

// returns the name
constexpr static const name_type& name() noexcept;
// returns the member pointer
const ptr_type& member_ptr() const noexcept;
// returns the attributes as a std::tuple<attrib...>
const attrib_type& attributes() const noexcept;
```

To iterate through all members, use the `stamp::reflect::for_each_reflect_member_properties` function.
This function will iterate over each reflected property and call the function you provide.

```cpp
// reflected properties for: 
my_type obj;

stamp::reflect::for_each_reflect_member_properties<my_type>([&]<typename T>(const T& property) {
	using ptr_type = typename T::ptr_type;
	using value_type = typename T::value_type;
	using class_type = typename T::class_type; // same as 'my_type'

	std::cout << "Property Name: " << property.name() << std::endl;

	obj.*property.member_ptr() = /* assign value to property */;
});
```

## Traits Accessors

The `stamp::reflect::traits` namespace contains a set of static helper variables.
The accessors compile when no reflection are provided and are defaulted to empty strings for `string_literal` members, and empty `std::tuple` for member values.

**Note**, that trait accessors return an empty tuple or string when the type does not have reflection. 

Complete list of all `stamp::reflect::traits`:
- `space_v<T>`
- `name_v<T>`
- `full_name_v<T>`
- `basic_name_v<T>`
- `base_v<T>`
- `properties_v<T>`
- `functions_v<T>` - Unimplemented
- `constructors_v<T>` - Unimplemented
- `static_properties_v<T>` - Unimplemented
- `static_functions_v<T>` - Unimplemented

# string_literal

the `string_literal` type represents a compile-time string. 
It is used to store the name of the reflected type and properties.

The `string_literal` acts as a wrapper for compile time strings and can be used in template parameters.

```cpp
template<string_literal S>
struct my_struct {
	static constexpr string_literal name = S;
};

static_assert(my_struct<"hello world!">.name == "hello world!");
```


## Concatenate string_literal

The helper function `concat_cstring_v<str...>` can be used to concatenate any number of literals or `string_literal`  types at compile time.

```cpp
static_assert(concat_cstring_v<"Hello", " ", "World!"> == "Hello World!");
```

## Comma Separated Concatenate string_literal

The helper value `comma_list_string_literals_v<str...>` concatinates all strings with commas between each string.

```cpp
static_assert(comma_list_string_literals_v<"A", "B", "C"> == "A,B,C");
```

# Meta Tuple

the `stamp/reflect/meta_tuple.h` header contains server helper functions to iterate over and access members of tuples. this header is included in `stamp/reflect/reflect.h`.

## for_each

`stamp::reflect::for_each` function runs a _[function object](https://en.cppreference.com/w/cpp/named_req/FunctionObject.html)_ on each element of a tuple.

```cpp
#include <stamp/reflect/meta_tuple.h>
std::tuple<char,float> my_tuple = {'a',12.92};
stamp::reflect::for_each(my_tuple,[](auto& v) {
	std::cout << v << std::endl;
}); 
// example stdout:
// a
// 12.92

// lambda is called with parameter type, std::tuple_element
stamp::reflect::for_each<std::tuple<int, float>>(my_tuple,[]<typename P>(P v) {
	using type = P::type;
	std::cout << stamp::reflect::traits::name_v<type>;
}); 
// example stdout:
// int
// float
```

## for_each_construct

`stamp::reflect::for_each_construct` returns a tuple with members constructed from the return value from the _[function object](https://en.cppreference.com/w/cpp/named_req/FunctionObject.html)_.

```cpp
// function is called with parameter type: std::tuple_element
auto my_tuple = stamo::reflect::for_each_construct<std::tuple<short,int>>([]<typename P>(P v) {
	using type = P::type;

	return 1 + sizeof(type);
});

// my_type = std::tuple<short, int>(1+sizeof(short), 1+sizeof(int));
```

# Member Function Traits

`member_function_traits` provide a list of compile-time traits for member functions similar to the standard [iterator traits](https://en.cppreference.com/w/cpp/iterator/iterator_traits.html) class. `member_function_traits` is undefined for user specified overloads.

`member_function_traits` provide these traits:
- `class_type` - base class of member function
- `return_type` - return type of the member function
- `ptr_type` - member pointer type: `return_type(class_type::*)(Arg...)`
- `arg_type` - tuple of function arguments
- `arg_ref_type` - tuple of function arguments as references
- `is_const` - true if function is `const` in CV overload
- `is_noexcept` - true if function is `noexcept`
- `is_ref_qual_lvalue` - true if function is lvalue reference qualified overload
- `is_ref_qual_rvalue` - true if function is rvalue reference qualified overload
- `overload_tag_type` - one of the [[#member-function-overload-tags|overload tags]]

```cpp
template<typename T>
struct member_function_traits {
	using class_type = /* defined per overload */;
	using return_type = /* defined per overload */;
	using ptr_type = /* defined per overload */;
	using arg_type = /* defined per overload */;
	using arg_ref_type = /* defined per overload */;
	static constexpr bool is_const = /* defined per overload */;
	static constexpr bool is_noexcept = /* defined per overload */;
	static constexpr bool is_ref_qual_lvalue = /* defined per overload */;
	static constexpr bool is_ref_qual_rvalue = /* defined per overload */;
	using overload_tag_type = /* defined per overload */;
};
```
## Member Function Overload Tags

Overload tags are useful for [tag dispatching](https://iamsorush.com/posts/cpp-tag-dispatch/). All tags are in the `stamp::reflect::tag` namespace.

A complete list of tags:
- `none_overload_tag_t`  - basic overload with no keywords
- `const_overload_tag_t` - member function is const
- `lvalue_overload_tag_t` - member function is an lvalue reference overload
- `lvalue_overload_tag_t` - member function is an lvalue reference overload and const
- `rvalue_overload_tag_t` - member function is an rvalue reference overload
- `rvalue_overload_tag_t` - member function is an rvalue reference overload and const
