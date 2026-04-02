# Reflect Library

The reflect library is a header-only library that provides noninvasive compile-time reflections.

## Usage Guide

include  `stamp/reflect/reflect.h` header file in your code to access reflections.

### Creating Reflections

To implement reflections for any class, create a template specialization of the `reflect_traits` struct.
Make sure you are in the `stamp::reflect` namespace when creating the specialization.
```cpp
template<>
struct reflect_traits_<your_class> {
};
```

Next, add the class name to the reflect struct.
```cpp
template<>
struct reflect_traits_<your_class> {
	static constexpr string_literal name = "your_class";
};
```
Finally, construct a tuple of members you want to reflect. 
```cpp
template<>
struct reflect_traits_<your_class> {
	static constexpr string_literal name = "your_class";
	static constexpr auto properties = std::tuple{
		reflect("prop_1", your_class::prop_1),
		reflect("prop_2", your_class::prop_2)
		// etc.
	};
};
```
Once your done, you can use any of the `stamp::reflect::traits` accessors on the new type.

### Using Reflections

To use your reflections, simply access the `stamp::reflect::traits::properties_v<T>`.
This accessor will return a tuple of the reflected properties.
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

An alternative way to access the properties is to use the `stamp::reflect::for_each_reflect_member_properties` function.
This function will iterate over each reflected property and call the function you provide.
Here is a common use case example:

```cpp
stamp::reflect::for_each_reflect_member_properties<my_type>([&]<typename T>(const T& property) {
	using ptr_type = typename T::ptr_type;
	using value_type = typename T::value_type;
	using class_type = typename T::class_type;

	std::cout << "Property Name: " << property.name() << std::endl;
});
```

## Helper Functions and Types

### string_literal

the `string_literal` type represents a compile-time string. 
It is used to store the name of the reflected type and properties.



The helper function `concat_cstring_v<str1, str2>` can be used to concatenate two `string_literal` types at compile time.

```cpp
static_assert(concat_cstring_v<"Hello", " ", "World!"> == "Hello World!");
```