# Reflect Library

The reflect library is a header-only library that provides noninvasive compile-time reflections.

## Todo

- Implement reflections for static members
- Implement views for methods

## CMake

To use the reflect library, add the following to your `CMakeLists.txt`:
```cmake
# import the stamp package
find_package(stamp REQUIRED)

#include the reflect library
target_link_libraries(your_target PRIVATE stamp::reflect)
```


## Usage Guide

include  `stamp/reflect/reflect.h` header file in your code to access reflections.

### Creating Reflections

To implement reflections for any class, create a template specialization of the `reflect_traits` struct.
Make sure you are in the `stamp::reflect` namespace when creating the specialization.
```cpp
template<>
struct reflect_traits<my_class> {
	using type = my_class;
};
```

*Note* that you must add the `using type = my_type` to the reflections to make a valid reflection.

Next, add the class name to the reflect struct.
```cpp
template<>
struct reflect_traits<my_class> {
	using type = my_class;
	static constexpr string_literal name = "my_class";
};
```
Finally, construct a tuple of members you want to reflect. 
```cpp
template<>
struct reflect_traits<my_class> {
	using type = my_class;
	static constexpr string_literal name = "my_class";
	static constexpr auto properties = std::tuple{
		reflect("prop_1", my_class::prop_1),
		reflect("prop_2", my_class::prop_2)
		// etc.
	};
};
```
Once your done, you can use any of the `stamp::reflect::traits` accessors on the new type.

The full declaration of a reflection is:

```cpp
template<typename T>
struct reflect_traits<my_class<T>> {
	using type = my_class;
	static constexpr string_literal space = "my_namespace";
	static constexpr string_literal name = concat_cstring_v<"my_class<", traits::name_v<T>,">">;
	static constexpr string_literal basic_name = "my_class";
	static constexpr string_literal full_name = concat_cstring_v<"my_namespace::my_class<", traits::full_name_v<T>,">">;
	
	static constexpr auto properties = std::tuple{
		reflect("prop_1", my_class::prop_1),
		reflect("prop_2", my_class::prop_2)
		// etc.
	};
};
```

`full_name` and `basic_name` are optional members. 
They are defaulted to:
 - `full_name` = `space` + `"::"` + `name`.
 - `basic_name` = `name`

### Using Reflections

To use your reflections, use `stamp::reflect::traits::properties_v<T>`.
This accessor will return a constexpr tuple of the reflected properties.
Each reflected property will contain the following members:

```cpp
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

Note, that trait accessors return an empty tuple or string when the type does not have reflection. 

To iterate through all members, use the `stamp::reflect::for_each_reflect_member_properties` function.
This function will iterate over each reflected property and call the function you provide.
an example use:

```cpp
my_type obj;

stamp::reflect::for_each_reflect_member_properties<my_type>([&]<typename T>(const T& property) {
	using ptr_type = typename T::ptr_type;
	using value_type = typename T::value_type;
	using class_type = typename T::class_type;

	std::cout << "Property Name: " << property.name() << std::endl;

	obj.*property.member_ptr() = /* assign value to property */;
});
```

### Traits Accessors

The `stamp::reflect::traits` namespace contains a set of static helper variables.
The accessors compile when no reflection are provided and are defaulted to empty strings for `string_literal` members, and empty `std::tuple` for member values.

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

## Helper Functions and Types

### string_literal

the `string_literal` type represents a compile-time string. 
It is used to store the name of the reflected type and properties.

The `string_literal` acts as a wrapper for compile time strings and can be used in template parameters.

```cpp
template<string_literal S>
struct my_struct {
	static constexpr string_literal name = S;
};
```


### Concatenate string_literal

The helper function `concat_cstring_v<str...>` can be used to concatenate two `string_literal` types at compile time.

```cpp
static_assert(concat_cstring_v<"Hello", " ", "World!"> == "Hello World!");
```

### Comma Seperated Concatenate string_literal

The helper value `comma_list_string_literals_v<str...>` concats all strings with commas between each string.

```cpp
static_assert(concat_cstring_v<"A", "B", "C"> == "A,B,C");
```

