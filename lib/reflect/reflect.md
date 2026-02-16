# Reflect Library

The reflect library is a header-only library that provides noninvasive compile-time reflections.

## Usage

To use the reflect library, simply include the `stamp/reflect.h` header file in your code.



### Custom Reflections

To implement reflections for any class, create a template specialization of the `stamp::reflect` struct.
Make sure you are in the `stamp` namespace when creating the specialization.
```cpp
template<>
struct reflect<your_class> {
};
```

Next, add the class name to the reflect struct.
```cpp
template<>
struct reflect<your_class> {
	static constexpr auto name = "your_class";
};
```
Finally, construct a tuple of members you want to reflect. 
```cpp
template<>
struct reflect<your_class> {
	static constexpr auto name = "your_class";
	static constexpr auto members = std::tuple{
		reflect::member("member1", &your_class::member1),
		reflect::function("function1", &your_class::function1),
		reflect::base<base1>("base1"),
		/* etc. */
	};
};
```
Once your done, you can use any of the `stamp::reflect` functions on the new type.