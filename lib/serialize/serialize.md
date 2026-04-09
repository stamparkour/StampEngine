# Serialize Library

The Serialize library provides functions for serializing and deserializing data using `std::iostream`.

## Serialize Formats

### Ordered Binary Packing

The ordered binary packing removes all labeling in the binary representation in exchange for consistent ordering of fields.

```cpp
struct my_struct {
	int a;
	float b;
	std::string c;
};

my_cout << stamp::serialize::ordered_binary( my_struct { 1, 4.0f, "hello" } );
my_cin >> stamp::serialize::ordered_binary( my_struct { 1, 4.0f, "hello" } );
```


| field | offset | output                                     | value         |
|-------|--------|--------------------------------------------|---------------|
| `a`   | 0      | `01 00 00 00`                              | `1`           |
| `b`   | 4      | `40 80 00 00`                              | `4.0f`        |
| `c`   | 8      | `05 00 00 00 00 00 00 00` `68 65 6C 6C 6F` | `5` `"hello"` |


The serializer function recursively calls `stamp::serialize::ordered_binary<T>()` for each member of the struct.
The basic implemention uses `stamp:reflect` to iterate over members.
This generic can be overriden for custom behavior.

Full syntax for `ordered_binary`:
```
ordered_binary_serializer ordered_binary(
	const T& data,
	const format& fmt = format {},
	pointer_track_registry& overriden_pointer_tracker = /* local registry */
);
ordered_binary_serializer ordered_binary(
	T& data,
	const format& fmt = format {},
	pointer_track_registry& overriden_pointer_tracker = /* local registry */
);
```

#### Format

an optional format can be passed to the `ordered_binary` function.


formatter flags:
- **`big_endian`** — data uses big endian
- **`little_endian`** — data uses little endian (default)
- **`no_align`** — data is packed with no padding (default)
- **`align`** — data is aligned with padding 
- **`smart_align`** — data is aligned to the next power of two based on its size with max padding defined by `padding` value.
- **`size_with_varint`** — sized data (length of array and pointers) is encoded as a varint instead of a fixed size integer.

formatter attributes:
- **`padding`** — the padding value used for alignment. must be a power of 2. default is 8. disabled when `smart_align` is not used.
- **`size`** — the length of the size fields. must be a power of 2. default is 8. disabled when `size_with_varint` is used.

```cpp
using namespace stamp::serialize;
namespace obp = ordered_binary_serializer::format::flags;
my_cout << ordered_binary( 
	my_struct { 1, 4.0f, "hello" }, 
	ordered_binary_serializer::format { 
		.flags = obp::big_endian | obp::aligned,
		.padding = 8 // aligns all fields to 8 bytes or higher. must be power of 2.
	}
);
```

#### Pointer Tracking

The `ordered_binary` serializer tracks pointers and will only serialize the data at the first time it is seen. 
The deserializer has two passes, one pass that deserializes objects, and the second fills in pointers.

the wrapper `track_pointers<T>` provides pointer tracking for a type that satisfies the `std::iostream` concept.
If you do not use this wrapper, the serializer will serialize each object directly after each pointer.

When wanting to track an object by pointer, you must pass it as a pointer. 
Although the function might accept a reference, parameter references are not tracked and will be serialized as normal data.

References and pointers are stored as a 64-bit integer offset relative to the left of the current field.

```cpp
struct my_struct {
	uint32_t* ptr;
};

int main() {
	std::uint32_t value = 0x1234;
	my_struct s1 { &value };
	my_struct s2 { &value };
	my_cout 
		<< stamp::serialize::ordered_binary( s1 )
		<< stamp::serialize::ordered_binary( s2 );
}
```

Output:

| field    | offset | output                    | value      |
|----------|--------|---------------------------|------------|
| `s1.ptr` | 0      | `08 00 00 00 00 00 00 00` | `(int*)8`  |
| `value`  | 8      | `34 12 00 00`             | `1`        |
| `s2.ptr` | 12     | `FC FF FF FF FF FF FF FF` | `(int*)-4` |

#### Piping

The `ordered_binary` function returns a `ordered_binary_serializer` object. 
This object contains two templated functions, `serialize` and `deserialize`. 
The parameter is a type that satisfies the `std::iostream` concept.

If you want to track pointers, use the overload for `serialize` and `deserialize` that takes a `pointer_track_registry` object as a parameter.

The operators `<<` and `>>` are overloaded for the `ordered_binary_serializer` object to call the `serialize` and `deserialize` functions respectively. 


#### Ordered Binary Serializer Object

`ordered_binary_serializer<T>` is an object that holds the information to serialize the target object.

`ordered_binary_serializer<T>` contains:
- `out` — serializes data to a type that matches an ostream.
- `in` — deserializes data from a type that matches an istream.
- `data` — the data to be serialized or deserialized.
- `format` — the format used for serialization and deserialization.
- `pointer_tracker` — the pointer track registry used for serialization and deserialization when tracking pointers. If not set, a default pointer track registry is used.
