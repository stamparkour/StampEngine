#pragma once
#ifndef STAMP_REFLECT_VTABLE_H
#define STAMP_REFLECT_VTABLE_H

#include "reflect_traits.h"
#include "reflect_helpers.h"
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iterator>
#include <utility>
#include <stamp/reflect/member_function_traits.h>

// unified way to access class member attributes and methods and interact with them.

namespace stamp::reflect {
	class view_handle;

	class view_vtable_base {
	public:
		using key_type = std::size_t;
		using this_type = std::shared_ptr<void>;
		using const_iterator = std::vector<key_type>::const_iterator;
	protected:
		virtual view_handle do_fetch(const this_type&, key_type) const = 0;
		virtual view_handle do_call(const this_type&, const std::vector<view_handle>&) const = 0;

		virtual std::string do_name() const = 0;
		virtual std::string do_to_string(const this_type&) const = 0;
		virtual std::size_t do_type_hash() const = 0;

		// virtual const_iterator do_begin() const = 0;
		// virtual const_iterator do_end() const = 0;
	public:
		view_handle fetch(const this_type& t, key_type k) const;
		view_handle call(const this_type& t, const std::vector<view_handle>&) const;

		std::string name() const { return do_name(); }
		std::string to_string(const this_type&) const;
		std::size_t type_hash() const { return do_type_hash(); }

		// iterator through member views
		// const_iterator begin() const { return do_begin(); }
		// const_iterator end() const { return do_end(); }
	};


	class view_handle {
	public:
		using key_type = typename view_vtable_base::key_type;
		using const_iterator = typename view_vtable_base::const_iterator;
	private:
		std::shared_ptr<void> ptr = {};
		const view_vtable_base* vtable_v = nullptr;

	public:
		template<std::forward_iterator T>
		constexpr static key_type to_key(T begin, T end);
		constexpr static key_type to_key(const std::string_view&);

		constexpr view_handle() = default;
		view_handle(const std::shared_ptr<void>& ptr, const view_vtable_base* vtable) : ptr(ptr), vtable_v(vtable) {}

		// access members
		view_handle at(key_type) const;
		view_handle at(const std::string_view&) const;
		view_handle operator[](key_type v) const { return at(v); }
		view_handle operator[](const std::string_view& v) const { return at(v); }
		// call self
		template<typename... T>
		view_handle call(T&&...) const;
		template<typename... T>
		view_handle operator()(T&&... t) const { return call(std::forward<T>(t)...); }


		// access base type
		std::shared_ptr<void> lock() const;
		bool expired() const;

		// access vtable
		const view_vtable_base* vtable() const;

		std::string name() const;
		std::string to_string() const;
		std::size_t type_hash() const;

		// iterate through child members
		// const_iterator begin() const;
		// const_iterator end() const;
	};
	inline const view_handle view_none_v = view_handle{};

	// view definitions

	template<std::forward_iterator T>
	inline constexpr view_handle::key_type view_handle::to_key(T begin, T end) {
		//FNV-1 64bit
		view_handle::key_type FNV_offset_basis = 14695981039346656037;
		view_handle::key_type FNV_prime = 1099511628211;
		// add 32 bit variant possibly

		view_handle::key_type hash = FNV_offset_basis;
		for (auto p = begin; p != end; ++p) {
			view_handle::key_type data = *p;
			hash *= FNV_prime;
			hash ^= data;
		}
		return hash;
	}
	inline constexpr view_handle::key_type view_handle::to_key(const std::string_view& s) {
		return view_handle::to_key(s.cbegin(), s.cend());
	}
	inline view_handle view_handle::at(key_type k) const {
		return this->vtable_v->fetch(lock(),k);
	}
	inline view_handle view_handle::at(const std::string_view& s) const {
		return this->vtable_v->fetch(lock(), view_handle::to_key(s));
	}
	template<typename... T>
	inline view_handle view_handle::call(T&&... t) const {
		std::vector<view_handle> v{};
		(v.push_back(make_view_copy(std::forward<T>(t))), ...);
		return this->vtable_v->call(lock(), v);
	}
	inline std::shared_ptr<void> view_handle::lock() const {
		return ptr;
	}
	inline bool view_handle::expired() const {
		return false;
	}
	inline const view_vtable_base* view_handle::vtable() const {
		return vtable_v;
	}
	inline std::string view_handle::name() const {
		return vtable_v->name();
	}
	inline std::string view_handle::to_string() const {
		return vtable_v->to_string(ptr);
	}
	inline std::size_t view_handle::type_hash() const {
		return vtable_v->type_hash();
	}

	// view base definitions

	view_handle view_vtable_base::fetch(const this_type& t, key_type k) const {
		return do_fetch(t, k);
	}
	view_handle view_vtable_base::call(const this_type& t, const std::vector<view_handle>& array) const {
		return do_call(t, array);
	}
	std::string view_vtable_base::to_string(const this_type& t) const {
		return do_to_string(t);
	}

	// basic view types

	struct default_to_string {
		template<typename Q> requires requires(Q q) { std::to_string(std::forward<Q>(q));  }
		std::string operator()(Q&& q) {
			return std::to_string(std::forward<Q>(q));
		}
	};

	struct generic_view_generator;
	template<concepts::reflect_traits_c T, typename To_String = default_to_string, typename View_Base_Gen = generic_view_generator>
	class generic_view_vtable;
	template<typename P, typename To_String = default_to_string, typename View_Base_Gen = generic_view_generator>
	class generic_member_property_view_vtable;
	template<typename T, typename To_String = default_to_string, typename View_Base_Gen = generic_view_generator>
	class generic_member_function_view_vtable;

	struct generic_view_generator {
		template<typename T>
		inline static generic_view_vtable<T, default_to_string, generic_view_generator> view_v{};
		template<typename P>
		using member_property_view_type = generic_member_property_view_vtable<P, default_to_string, generic_view_generator>;
		template<typename T>
		using member_function_view_type = generic_member_function_view_vtable<T, default_to_string, generic_view_generator>;
	};

	template<typename View_Base_Gen = generic_view_generator, typename T>
	view_handle make_view_shared(const std::shared_ptr<T>& t) {
		return view_handle(t, &(View_Base_Gen::template view_v<T>));
	}
	template<typename View_Base_Gen = generic_view_generator, typename T>
	view_handle make_view_copy(const T& t) {
		return make_view_shared<View_Base_Gen>(std::make_shared<T>(t));
	}
	template<typename View_Base_Gen = generic_view_generator, typename T>
	view_handle make_view_shallow(T* t) {
		return make_view_shared<View_Base_Gen>(std::shared_ptr<T>(t, [](T*) {}));
	}

	template<concepts::reflect_traits_c T, typename To_String, typename View_Base_Gen>
	class generic_view_vtable : public view_vtable_base {
	public:
		using value_type = T;
		std::unordered_map <std::size_t, std::unique_ptr<view_vtable_base>> member_properties_map{};
		generic_view_vtable() {
			for_each_reflect_member_properties<value_type>([&]<typename Q>(Q prop) {
				using type = Q;
				using ptr_type = typename type::ptr_type;

				member_properties_map.emplace(
					view_handle::to_key(prop.name()),
					std::make_unique<View_Base_Gen::template member_view_type<ptr_type>>(prop._name, prop.member_ptr())
				);
			});
			for_each_reflect_member_functions<value_type>([&]<typename Q>(Q prop) {
				using type = Q;
				using ptr_type = typename type::ptr_type;
				member_properties_map.emplace(
					view_handle::to_key(prop.name()),
					std::make_unique<View_Base_Gen::template member_view_type<ptr_type>>(prop.name(), prop.member_ptr())
				);
			});
		}
		virtual view_handle do_fetch(const this_type& self, key_type key) const override {
			auto itter = member_properties_map.find(key);
			if (itter != member_properties_map.end()) {
				auto& vtable = itter->second;
				return view_handle(self, vtable.get());
			}
			// manage getting subobjects
			return view_none_v;
		}
		virtual view_handle do_call(const this_type& self, const std::vector<view_handle>&) const override {
			//manage calls
			return view_none_v;
		}

		virtual std::string do_name() const override {
			return traits::full_name_v<T>;
		}
		virtual std::string do_to_string(const this_type& _self) const override {
			auto self = static_pointer_cast<T>(_self);
			To_String to_string_v{};
			if constexpr (requires (T t, To_String s) { s(t); }) {
				return to_string_v(*self);
			}
			else {
				return "";
			}
		}
		virtual std::size_t do_type_hash() const override {
			return typeid(T).hash_code();
		}
	};

	template<typename P, typename To_String, typename View_Base_Gen>
	class generic_member_property_view_vtable : public view_vtable_base {
	public:
		using ptr_type = P;
		using ptr_reflect_type = reflect_traits<P>;
		using class_type = ptr_reflect_type::class_type;
		using value_type = ptr_reflect_type::value_type;

		const view_vtable_base* view_ptr;
		std::string_view name;
		ptr_type ptr;
		generic_member_property_view_vtable(const std::string_view& name, ptr_type ptr) : ptr(ptr) {
			this->view_ptr = &View_Base_Gen::template view_v<value_type>;
			this->name = name;
		}
		virtual view_handle do_fetch(const this_type& _self, key_type key) const override {
			auto self = static_pointer_cast<class_type>(_self);
			return view_ptr->fetch(std::shared_ptr<value_type>(self, &(self.get()->*ptr)), key);
		}
		virtual view_handle do_call(const this_type& _self, const std::vector<view_handle>& param) const override {
			auto self = static_pointer_cast<class_type>(_self);
			return view_ptr->call(std::shared_ptr<value_type>(self, &(self.get()->*ptr)), param);
		}

		virtual std::string do_name() const override {
			return std::string{ name };
		}
		virtual std::string do_to_string(const this_type& _self) const override {
			auto self = static_pointer_cast<class_type>(_self);
			auto& val = self.get()->*ptr;
			To_String to_string_v{};
			if constexpr (requires (value_type t, To_String s) { s(t); }) {
				return to_string_v(val);
			}
			else {
				return "";
			}
		}
		virtual std::size_t do_type_hash() const override {
			return typeid(ptr_type).hash_code();
		}
	};

	// view reference type

	class view {
	public:
		using key_type = typename view_vtable_base::key_type;
	private:
		view_handle handle;
	public:
		view() : handle(view_none_v) {}
		view(const view_handle& h) : handle(h) {}

		// access members
		view_handle at(key_type key) const {
			return handle.at(key);
		}
		view_handle at(const std::string_view& str) const {
			return handle.at(str);
		}
		// call self
		template<typename... T>
		view_handle call(T&&... t) const {
			return handle.call(std::forward<T>(t)...);
		}

		// access base type
		std::shared_ptr<void> lock() const { 
			return handle.lock();
		}
		bool expired() const { 
			return handle.expired();
		}
		const view_vtable_base* vtable() const {
			return handle.vtable();
		}

		std::string name() const { 
			return handle.name();
		}
		std::string to_string() const {
			return handle.to_string();
		}
		std::size_t type_hash() const {
			return handle.type_hash();
		}
	};
}

#endif // STAMP_REFLECT_VTABLE_H
