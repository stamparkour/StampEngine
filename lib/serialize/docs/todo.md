
todo list:
- make base level 'serialization' framework where all other serializers build on top.
	- data stream using `stamp::task::co_stream_strand`
	- create a serialization virtual object
	- design questions: prioritize speed and ease of use.
		- should the serializer object be determined at runtime or compile-time? probably be compile-time due to compile time reflections. faster
		- should this system be the base for other tools (debugger gui, python bindings)? probably not.
		- should this focus on portability, speed, or runtime polymorphism? speed probably.
		- 
	- 