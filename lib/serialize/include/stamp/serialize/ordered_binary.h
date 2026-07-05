#ifndef STAMP_SERIALIZE_ORDERED_BINARY_H
#define STAMP_SERIALIZE_ORDERED_BINARY_H

#include "serialize_helpers.h"
#include <stamp/reflect/reflect.h>
#include <stamp/serialize/concepts.h>

#include <iostream>
#include <type_traits>
#include <cstdint>
#include <cstring>
#include <bit>
#include <unordered_map>
#include <cstdint>
#include <memory_resource>

// finished (untested):
// ob in: shared_ptr, T*, reflected object, integers, floats
// ob out: T*, reflected object, integers, floats

// need to do:
// ob out: shared_ptr
// unique_ptr, weak_ptr
// error code
// config to prevent any memory leaks
// iterator support


namespace stamp::serialize {
	//using ordered_binary_error_code_t = std::uint32_t;
	//using obec_t = ordered_binary_error_code_t;
	//namespace ordered_binary_error_code {
	//	obec_t ok = (obec_t)0;
	//	obec_t unspecified_error = (obec_t)1;
	//	obec_t pointer_request_failed = (obec_t)2; // pointer_tracker does not contain target pointer
	//	obec_t missing_pointer_tracker = (obec_t)3; // pointer_tracker is not specified
	//}
	//namespace obec = ordered_binary_error_code;

	using ptroffset_t = std::ptrdiff_t;

	template<typename T>
	struct ordered_binary_serializer;

	template<typename OS, typename T>
	void ordered_binary_out(OS&, const ordered_binary_serializer<T>&);

	class pointer_track_registry {
		std::unordered_map<void*, std::size_t> track_out;
		std::unordered_map<std::size_t, void*> track_in;
		std::size_t offset_v = 0;
	public:
		bool emplace(void* ptr) {
			if (fetch(ptr).second) return false;
			track_out.emplace(ptr, offset_v);
			track_in.emplace(offset_v, ptr);
			return true;
		}
		std::pair<void*, bool> fetch(std::size_t offset) const {
			if (auto v = track_in.find(offset); v != track_in.end()) {
				return {v->second, true};
			}
			return {nullptr, false};
		}
		std::pair<std::size_t, bool> fetch(void* ptr) const {
			if (auto v = track_out.find(ptr); v != track_out.end()) {
				return {v->second, true};
			}
			return {0, false};
		}
		std::size_t& offset() {
			return offset_v;
		}
		std::size_t offset() const {
			return offset_v;
		}
	};

	struct ordered_binary_formatter {
	};

	template<typename T>
	struct ordered_binary_serializer {
		using type = T;

		type* data;
		const ordered_binary_formatter* format;
		pointer_track_registry* pointer_tracker;
		std::pmr::polymorphic_allocator<>* allocator;

		constexpr ordered_binary_serializer(type* data, const ordered_binary_formatter* format, pointer_track_registry* pointer_tracker, std::pmr::polymorphic_allocator<>* allocator) :
			data(data),
			format(format),
			pointer_tracker(pointer_tracker),
			allocator(allocator) {}
	};

	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(T& val) {
		return {&val, nullptr, nullptr, nullptr};
	}
	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(T& val, pointer_track_registry& pointer_tracker) {
		return {&val, nullptr, &pointer_tracker, nullptr};
	}
	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(T& val, const ordered_binary_formatter& format) {
		return {&val, &format, nullptr, nullptr};
	}
	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(T& val, const ordered_binary_formatter& format, pointer_track_registry& pointer_tracker) {
		return {&val, &format, &pointer_tracker, nullptr};
	}
	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(T& val, const ordered_binary_formatter& format, pointer_track_registry& pointer_tracker, std::pmr::polymorphic_allocator<>& allocator) {
		return {&val, &format, &pointer_tracker, &allocator};
	}

	template<typename T1, typename T2>
	inline ordered_binary_serializer<T1> ordered_binary(T1& val, const ordered_binary_serializer<T2>& source) {
		return {&val, source.format, source.pointer_tracker, source.allocator};
	}

	// implemented serialize out: integers, floats, pointers(ish)
	template<stamp::serialize::concepts::ostream_c OS, typename T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<T>& serializer) {
		static_assert(stamp::reflect::concepts::reflect_traits_usertype_c<T>);
		using namespace stamp::reflect;
		for_each_reflect_member_properties<T>([&]<typename P>(const P & property) {
			using value_type = typename P::value_type;

			auto& val = (serializer.data->*property.member_ptr());
			auto obs = ordered_binary(val, serializer);
			ordered_binary_out(ostream, obs);
		});
	}
	template<stamp::serialize::concepts::ostream_c OS, typename T> requires std::integral<T> || std::floating_point<T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<T>& serializer) {
		auto out = to_little_endian_arr(*(serializer.data));
		ostream.write(out.data(), out.size());
		if (serializer.pointer_tracker != nullptr) serializer.pointer_tracker->offset() += out.size();
	}
	template<stamp::serialize::concepts::ostream_c OS, typename T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<T*>& serializer) {
		//nullptr
		if (*(serializer.data) == nullptr) {
			auto out = to_little_endian_arr((std::ptrdiff_t)0); // 0 for nullptr
			ostream.write(out.data(), out.size());
			if(serializer.pointer_tracker != nullptr) serializer.pointer_tracker->offset() += out.size();
			return;
		}
		
		// pointer tracking
		if (serializer.pointer_tracker != nullptr) {
			if (auto ptr = serializer.pointer_tracker->fetch(*(serializer.data)); ptr.second) {
				ptroffset_t offset_value = (ptroffset_t)(ptr.first - serializer.pointer_tracker->offset());
				auto out = to_little_endian_arr((ptroffset_t)offset_value); // negative for old pointer
				ostream.write(out.data(), out.size());
				serializer.pointer_tracker->offset() += out.size();
				return;
			}
		}

		// else
		auto out = to_little_endian_arr((ptroffset_t)sizeof(ptroffset_t)); // sizeof(ptroffset_t) for new pointer
		ostream.write(out.data(), out.size());
		
		if (serializer.pointer_tracker != nullptr) {
			serializer.pointer_tracker->offset() += out.size();
			serializer.pointer_tracker->emplace(*(serializer.data));
		}

		// deref twice to access value
		auto& val = **(serializer.data);
		auto obs = ordered_binary(val, serializer);
		ordered_binary_out(ostream, obs);
	}
	template<stamp::serialize::concepts::ostream_c OS, typename T>
	inline void ordered_binary_out(OS& ostream, const ordered_binary_serializer<std::shared_ptr<T>>& serializer) {
		//nullptr
		if (*(serializer.data) == nullptr) {
			auto out = to_little_endian_arr((std::ptrdiff_t)0); // 0 for nullptr
			ostream.write(out.data(), out.size());
			if (serializer.pointer_tracker != nullptr) serializer.pointer_tracker->offset() += out.size();
			return;
		}

		// pointer tracking
		if (serializer.pointer_tracker != nullptr) {
			if (auto ptr = serializer.pointer_tracker->fetch(serializer.data->get()); ptr.second) {
				ptroffset_t offset_value = (ptroffset_t)(ptr.first - serializer.pointer_tracker->offset());
				auto out = to_little_endian_arr((ptroffset_t)offset_value); // negative for old pointer
				ostream.write(out.data(), out.size());
				serializer.pointer_tracker->offset() += out.size();
				return;
			}
		}

		// else
		auto out = to_little_endian_arr((ptroffset_t)sizeof(ptroffset_t)); // sizeof(ptroffset_t) for new pointer
		ostream.write(out.data(), out.size());

		if (serializer.pointer_tracker != nullptr) {
			serializer.pointer_tracker->offset() += out.size();
			serializer.pointer_tracker->emplace(*(serializer.format));
		}

		// deref twice to access value
		auto& val = **(serializer.data);
		auto obs = ordered_binary(val, serializer);
		ordered_binary_out(ostream, obs);
	}

	// implemented serialize in: integers, floats
	template<stamp::serialize::concepts::istream_c IS, typename T>
	inline void ordered_binary_in(IS& istream, const ordered_binary_serializer<T>& serializer) {
		static_assert(stamp::reflect::concepts::reflect_traits_usertype_c<T>);
		using namespace stamp::reflect;
		for_each_reflect_member_properties<T>([&]<typename P>(const P & property) {
			using value_type = typename P::value_type;

			auto& val = (serializer.data->*property.member_ptr());
			auto obs = ordered_binary(val, serializer);
			ordered_binary_in(istream, obs);
		});
	}
	template<stamp::serialize::concepts::istream_c IS, typename T> requires std::integral<T> || std::floating_point<T>
	inline void ordered_binary_in(IS& istream, const ordered_binary_serializer<T>& serializer) {
		std::array<char, sizeof(T)> in;
		istream.read(in.data(), sizeof(T));
		*(serializer.data) = from_little_endian_arr<T>(in);
		if (serializer.pointer_tracker != nullptr) serializer.pointer_tracker->offset() += in.size();
	}
	template<stamp::serialize::concepts::istream_c IS, typename T>
	inline void ordered_binary_in(IS& istream, const ordered_binary_serializer<T*>& serializer) {
		ptroffset_t offset_value;
		auto obs = ordered_binary(offset_value, serializer);
		ordered_binary_in(istream, obs);

		//nullptr
		if (offset_value == 0) {
			*(serializer.data) = nullptr;
		}
		// old pointer
		else if (offset_value < 0) {
			if (serializer.pointer_tracker == nullptr) {
				return;
			}
			ptroffset_t true_offset = offset_value + serializer.pointer_tracker->offset();
			if (auto ptr = serializer.pointer_tracker->fetch((std::size_t)true_offset); ptr.second) {
				*(serializer.data) = (T*)ptr.first;
			}
			else {
				*(serializer.data) = nullptr;
				// should throw something
			}
		}
		// new pointer
		else {
			// memory leak here
			auto& val = *(serializer.data);
			if (serializer.allocator != nullptr) {
				val = serializer.allocator->new_object<T>();
			}
			else {
				val = new T();
			}
			if (serializer.pointer_tracker != nullptr) serializer.pointer_tracker->emplace(val);
			auto obs = ordered_binary(*val, serializer);
			ordered_binary_in(istream, obs);
		}
	}
	template<stamp::serialize::concepts::istream_c IS, typename T>
	inline void ordered_binary_in(IS& istream, const ordered_binary_serializer<std::shared_ptr<T>>& serializer) {
		ptroffset_t offset_value;
		auto obs = ordered_binary(offset_value, serializer);
		ordered_binary_in(istream, obs);

		//nullptr
		if (offset_value == 0) {
			*(serializer.data) = nullptr;
		}
		// old pointer
		else if (offset_value < 0) {
			ptroffset_t true_offset = offset_value + serializer.pointer_tracker->offset();
			if (auto ptr = serializer.pointer_tracker->fetch((std::size_t)true_offset); ptr.second) {
				*(serializer.data) = *(std::shared_ptr<T>*)ptr.first;
			}
			else {
				*(serializer.data) = nullptr;
				// should throw something
			}
		}
		// new pointer
		else {
			auto& val = *(serializer.data);
			if (serializer.allocator != nullptr) {
				val = std::allocate_shared<T>(*(serializer.allocator));
			}
			else {
				val = std::make_shared<T>();
			}
			serializer.pointer_tracker->emplace(&val); // emplace a pointer to the shared pointer
			auto obs = ordered_binary(*val, serializer);
			ordered_binary_in(istream, obs);
		}
	}

	template<stamp::serialize::concepts::ostream_c OS, typename T>
	inline OS& operator <<(OS& os, const ordered_binary_serializer<T>& serializer) {
		ordered_binary_out(os, serializer);
		return os;
	}
	template<stamp::serialize::concepts::istream_c IS, typename T>
	inline IS& operator >>(IS& is, const ordered_binary_serializer<T>& serializer) {
		ordered_binary_in(is, serializer);
		return is;
	}
}

#endif // STAMP_SERIALIZE_ORDERED_BINARY_H
