@page serialize_page Serialize

# Overview

stamp::serialize is a C++20 library that provides several ways to serialize objects. 
<!-- 
Each serialization can use [awaitable objects](https://en.cppreference.com/cpp/language/coroutines) to allow for asynchronous execution.
-->

Current supported serializers:
- json.h
- ordered_binary.h


Design
- use reflect lib and serialize
- awaitables and coroutines varients
- data chunking (memory lib)
