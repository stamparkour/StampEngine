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
Once your done, you can use any of the `stamp::reflect` accessors on the new type.

### Using Reflections

