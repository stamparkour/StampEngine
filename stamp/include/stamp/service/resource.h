#ifndef STAMP_SERVICE_RESOURCE_H
#define STAMP_SERVICE_RESOURCE_H

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <cstdint>
#include <vector>
#include <boost/asio.hpp>
#include <stdexcept>
#include <stamp/type_traits.h>

namespace stamp {
	//write out specializations for trivial (int, float, etc), standard library and for pointer types. 
	template<typename T>
	class serializer_traits;

	class binary_blob {
		template<typename T>
		friend class serializer_traits;
	private:
		using packet_ptr_type = size_t;
		std::vector<uint8_t> buffer;
		size_t read_pos = 0;

		// ptr -> index in data
		std::unordered_map<const void*, packet_ptr_type> ptr_back_map{};
		std::unordered_map<packet_ptr_type, std::shared_ptr<void>> ptr_front_map{};

		// the pointer will be valid until the next call to reserve_back. assumes same src has same size
		void* alloc_back(size_t size) {
			size_t index = buffer.size();
			buffer.resize(index + size);
			return buffer.data() + index;
		}
		// if true, then the next write will be the src object
		// else, the src object has already been written
		bool alloc_ptr_back(const void* src) {
			bool ret;
			packet_ptr_type* buf_ptr = (packet_ptr_type*)alloc_back(sizeof(packet_ptr_type));
			if (src == nullptr) {
				*buf_ptr = 0;
				ret = false;
			}
			else {
				auto it = ptr_back_map.find(src);
				if (it == ptr_back_map.end()) { // not in map
					ret = true;
					ptr_back_map[src] = buffer.size();
					*buf_ptr = static_cast<packet_ptr_type>(buffer.size());
				}
				else {
					ret = false;
					*buf_ptr = it->second;
				}
			}
			return ret;
		}
		// the pointer will be valid until the next call to reserve_back. assumes same dst has same size
		void* alloc_front(size_t size) {
			if (size + read_pos > buffer.size()) {
				return nullptr;
			}
			size_t index = read_pos;
			read_pos += size;
			return (buffer.data() + index);
		}
		// 0 -> object is nullptr
		// offset -> object is valid
		//      - o_ptr = nullptr -> object is next, and must be deserialized
		//      - o_ptr != nullptr -> object has already been deserialized, o_ptr points to object
		packet_ptr_type alloc_ptr_front(std::shared_ptr<void>* o_ptr) {
			if (o_ptr == nullptr) return false;
			packet_ptr_type* buf_ptr = (packet_ptr_type*)alloc_front(sizeof(packet_ptr_type));
			if (buf_ptr == nullptr || *buf_ptr == 0 || *buf_ptr >= buffer.size()) {
				return false;
			}
			auto it = ptr_front_map.find(*buf_ptr);
			if (it != ptr_front_map.end()) { // object is next
				*o_ptr = it->second;
			}
			else { // object has already been read
				*o_ptr = nullptr;
			}
			return true;
		}
		void finalize_ptr_front(packet_ptr_type offset, const std::shared_ptr<void>& obj) {
			ptr_front_map[offset] = obj;
		}
	public:
		template<typename T>
		void push_back(const T& val) {
			using stamp::serializer_traits;
			buffer.reserve(buffer.size() + serializer_traits<T>::min_packet_size); // mitigates multiple resizing buffer
			serializer_traits<T>::serialize(*this, val);
		}
		template<typename T>
		T pop_front() {
			using stamp::serializer_traits;
			return serializer_traits<T>::deserialize(*this, val);
		}
		template<typename T>
		T* pop_front(T* ptr) {
			using stamp::serializer_traits;
			return serializer_traits<T>::deserialize(*this, val, ptr);
		}
	};

	template<typename Base, auto... MemPtrs>
	class serializer_generator {
	public:
		using value_type = Base;
	private:
		template<typename ValT, T value_type::* MemPtr>
		void serialize_member(binary_blob& p, value_type* obj) {
			using stamp::serializer_traits;
			serializer_traits<ValT>::serialize(obj.*MemPtr, p);
		}
		template<typename ValT, T value_type::* MemPtr>
		void deserialize_member(binary_blob& p, value_type* obj) {
			using stamp::serializer_traits;
			obj.*MemPtr = serializer_traits<ValT>::deserialize(p);
		}
	public:
		static inline void serialize(binary_blob& pkt, const value_type* src) {
			(serialize_member<MemPtrs>(pkt, src), ...);
		}
		static inline value_type deserialize(const binary_blob& pkt, const value_type* dst) {
			(deserialize_member<MemPtrs>(pkt, dst), ...);
		}
	};

	template<typename T>
	class serializer_traits {
	public:
		using value_type = T;
		static constexpr bool is_trivial = false;
		static constexpr bool is_serializable = false;
		static constexpr bool min_packet_size = 0;

		// static inline void serialize(const value_type& obj, packet& pkt) {}
		// static inline value_type deserialize(const packet& pkt) {}
	};

	// primitive types
	template<typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	class serializer_traits {
	public:
		using value_type = T;
		static constexpr bool is_trivial = true;
		static constexpr bool is_serializable = true;
		static constexpr bool min_packet_size = sizeof(value_type);

		static inline void serialize(const value_type& obj, binary_blob& pkt) {
			value_type *ptr = (value_type*)pkt.alloc_back(min_packet_size);
			*ptr = obj;
		}
		static inline value_type deserialize(const binary_blob& pkt) {
			value_type* ptr = (value_type*)pkt.alloc_front(min_packet_size);
			return *ptr;
		}
	};


	

	template<typename T>
	class serializer_traits<T*> {
	public:
		using value_type = T*;
		using base_type = T;
		using base_serializer_traits = serializer_traits<base_type>;
		static constexpr bool is_trivial = base_serializer_traits::is_trivial;
		static constexpr bool is_serializable = base_serializer_traits::is_serializable;
		static constexpr bool min_packet_size = sizeof(value_type);
		static_assert(is_serializable, "cannot serialize pointer to non-serializable type");

		static inline void serialize(value_type ptr, binary_blob& pkt) {
			if (pkt.alloc_ptr_back(ptr)) {
				base_serializer_traits::serialize(*ptr, pkt);
			}
		}
		static inline value_type deserialize(const binary_blob& pkt, value_type* o_ptr = nullptr) {
			// NEED TO FINISH THIS // NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS// NEED TO FINISH THIS
			// use the shared ptr instead of pointer.
			std::shared_ptr<void> ptr = nullptr;
			auto off = ptr.alloc_ptr_front(&ptr);
			if (off == 0) {
				retuern nullptr;
			}
			if (ptr == nullptr) { // needs to be deserialized
				if (o_ptr == nullptr) {
					throw std::runtime_error("no o_ptr provided when needed, packet is now invalid. o_ptr can be nullptr if the target object has already been deserialized.")
				}
				**o_ptr = base_serializer_traits::deserialize(pkt);
				ptr = *ptr;
				pkt.finalize_ptr_front(off, ptr);
			}
			return *ptr;
		}
	};

	class resource_definition_base {
	public:
		using key_type = std::string_view;
		using hash_type = size_t;
		using flags_type = size_t;
		enum : flags_type {
			read_only = 1 << 0,
		};
	private:
	public:
		resource_definition_base(const key_type& key, flags_type flags = 0);
		virtual ~resource_definition_base();

		key_type get_key() const;
		hash_type get_key_hash() const;
	};

	template<typename ResourceT>
	class resource_definition : resource_definition_base {
	public:
		using resource_type = ResourceT;
		using ptr_type = std::shared_ptr<resource_type>;
	private:
		virtual ptr_type do_get_resource() = 0;
		virtual void do_push_resource() = 0;
		virtual boost::asio::awaitable<ptr_type> do_co_get_resource() = 0;
		virtual boost::asio::awaitable<void> do_co_push_resource() = 0;
	public:
		resource_definition(const key_type& key, flags_type flags = 0);
		virtual ~resource_definition();

		ptr_type get_resource();
		void push_resource();
		boost::asio::awaitable<ptr_type> co_get_resource();
		boost::asio::awaitable<void> co_push_resource();
	};

	template<typename ResourceT>
	class filesystem_resource_definition : public resource_definition<ResourceT> {
		ptr_type do_get_resource() override;
		void do_push_resource() override;
	public:
		filesystem_resource_definition(const key_type& key, flags_type flags = 0);
		~filesystem_resource_definition();
	};

	class resource_service {
	public:
		using key_type = resource_definition_base::key_type;
		using hash_type = resource_definition_base::hash_type;
		using flags_type = resource_definition_base::flags_type;
		template<typename ResourceT>
		using default_resource_definition_type = filesystem_resource_definition<ResourceT>;
	private:
		std::unordered_map<hash_type, std::shared_ptr<resource_definition_base>> m_resources;
	public:
		resource_service();
		~resource_service();

		// all resources registered are persistant for the lifetime of the service
		// returns nullptr if already registered
		template<typename ResourceDef>
		std::shared_ptr<ResourceDef> register_resource(const std::string_view& key, flags_type flags = 0);
		// if you do not register the resource, the default resource definition will be used.
		template<typename ResourceT>
		std::shared_ptr<resource_definition<ResourceT>> get_resource(hash_type key);
	};
}

#endif // STAMP_SERVICE_RESOURCE_H
