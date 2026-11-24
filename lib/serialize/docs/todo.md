@page serialize_todo Serializer Todo List

todo list:
- make base level 'serialization' framework where all other serializers build on top.
	- data stream using `stamp::task::co_stream_strand`
	- create a serialization virtual object
	- design questions: prioritize speed and ease of use.
		- should the serializer object be determined at runtime or compile-time? probably be compile-time due to compile time reflections. faster
		- should this system be the base for other tools (debugger gui, python bindings)? probably not.
		- should this focus on portability, speed, or runtime polymorphism? speed probably.
		- 


goal:
- serializer that uses stamp::reflect
- several serializer/deserializer interfaces that can be swapped out
- simple usage

```cpp

json my_serializer{/* settings */};

co_await my_serializer.serialize(strand_i, target_object);
co_await strand_i; // finalize sync to stream.

co_await my_serializer.deserialize(strand_o, target_object);

```