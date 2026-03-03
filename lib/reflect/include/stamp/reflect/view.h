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

// unified way to access class member attributes and methods and interact with them.

namespace stamp::reflect {
	class view;

	class view_base {
	public:
		using key_type = std::size_t;
		using this_type = std::shared_ptr<void>;
		using call_iterator = std::vector<view>::iterator;
		using const_iterator = std::vector<key_type>::const_iterator;
	protected:
		virtual view do_fetch(const this_type&, key_type) const = 0;
		virtual view do_call(const this_type&, call_iterator begin, call_iterator end) const = 0;

		virtual std::string do_name() const = 0;
		virtual std::string do_to_string(const this_type&) const = 0;
		virtual std::size_t do_type_hash() const = 0;

		// virtual const_iterator do_begin() const = 0;
		// virtual const_iterator do_end() const = 0;
	public:
		view fetch(const this_type& t, key_type k) const;
		view call(const this_type& t, call_iterator begin, call_iterator end) const;

		std::string name() const { return do_name(); }
		std::string to_string(const this_type&) const;
		std::size_t type_hash() const { return do_type_hash(); }

		// iterator through member views
		// const_iterator begin() const { return do_begin(); }
		// const_iterator end() const { return do_end(); }
	};


	class view {
	public:
		using key_type = typename view_base::key_type;
		using const_iterator = typename view_base::const_iterator;
	private:
		std::shared_ptr<void> ptr = {};
		const view_base* vtable = nullptr;

	public:
		template<std::forward_iterator T>
		constexpr static key_type to_key(T begin, T end);
		constexpr static key_type to_key(const std::string_view&);

		constexpr view() = default;
		view(const std::shared_ptr<void>& ptr, const view_base* vtable) : ptr(ptr), vtable(vtable) {}

		// access members
		view operator[] (key_type) const;
		view operator[] (const std::string_view&) const;
		// call self
		template<typename... T>
		view operator() (T...) const;

		// access base type
		std::shared_ptr<void> lock() const;
		bool expired() const;

		std::string name() const;
		std::size_t type_hash() const;

		// iterate through child members
		// const_iterator begin() const;
		// const_iterator end() const;
	};
	inline const view view_none = view{};

	// view definitions

	template<std::forward_iterator T>
	inline constexpr view::key_type view::to_key(T begin, T end) {
		//FNV-1 64bit
		view::key_type FNV_offset_basis = 14695981039346656037;
		view::key_type FNV_prime = 1099511628211;
		// add 32 bit variant possibly

		view::key_type hash = FNV_offset_basis;
		for (auto p = begin; p != end; ++p) {
			view::key_type data = *p;
			hash *= FNV_prime;
			hash ^= data;
		}
		return hash;
	}
	inline constexpr view::key_type view::to_key(const std::string_view& s) {
		return view::to_key(s.cbegin(), s.cend());
	}
	inline view view::operator[](key_type k) const {
		return this->vtable->fetch(lock(),k);
	}
	inline view view::operator[](const std::string_view& s) const {
		return this->vtable->fetch(lock(), view::to_key(s));
	}
	template<typename... T>
	inline view view::operator()(T... t) const {
		std::vector<view> v{};
		(v.push_back(make_view_copy(std::forward(t))), ...);
		return this->vtable->call(lock(), v.begin(), v.end());
	}
	inline std::shared_ptr<void> view::lock() const {
		return ptr;
	}
	inline bool view::expired() const {
		return false;
	}
	inline std::string view::name() const {
		return vtable->name();
	}
	inline std::size_t view::type_hash() const {
		return vtable->type_hash();
	}

	// view base definitions

	view view_base::fetch(const this_type& t, key_type k) const {
		return do_fetch(t, k);
	}
	view view_base::call(const this_type& t, call_iterator begin, call_iterator end) const {
		return do_call(t, begin, end);
	}
	std::string view_base::to_string(const this_type& t) const {
		return do_to_string(t);
	}

	// basic view types

	template<typename T>
	struct default_to_string {
		template<typename Q>
		std::string operator()(Q q) {
			return std::to_string(std::forward(q));
		}
	};

	struct basic_view_generator;
	template<concepts::reflect_traits_c T, typename To_String = default_to_string<T>, typename View_Base_Gen = basic_view_generator>
	class basic_view;
	template<concepts::reflect_traits_c T, typename P, string_literal S, typename To_String = default_to_string<T>, typename View_Base_Gen = basic_view_generator>
	class basic_member_view;

	struct basic_view_generator {
		template<typename T>
		static const auto view = basic_view<T, default_to_string<T>, basic_view_generator>{};
		template<typename T, typename P>
		using member_view_type = basic_member_view<T, P, default_to_string<T>, basic_view_generator>;
	};

	template<typename View_Base_Gen = basic_view_generator, typename T>
	view make_view_shared(const std::shared_ptr<T>& t) {
		return view{ t, &View_Base_Gen::view<T> };
	}
	template<typename View_Base_Gen = basic_view_generator, typename T>
	view make_view_copy(const T& t) {
		return make_view_shared<View_Base_Gen>(std::make_shared(t));
	}
	template<typename View_Base_Gen = basic_view_generator, typename T>
	view make_view_shallow(T* t) {
		return make_view_shared<View_Base_Gen>(std::shared_ptr(t, [](T*) {}));
	}

	template<concepts::reflect_traits_c T, typename To_String, typename View_Base_Gen>
	class basic_view : view_base {
	public:
		using value_type = T;
		std::unordered_map <std::size_t, const view_base*> member_properties_map{};
		basic_view() {
			for_each_reflect_member_properties([&]<typename T>(T prop) {
				using type = T;
				using ptr_type = typename type::ptr_type;
				auto key = view::to_key(prop.name());
				auto value = View_Base_Gen::member_view_type<type, ptr_type>(prop.name(), prop.member_ptr());
				member_properties_map.insert(key, value);
			});
		}
	protected:
		virtual view do_fetch(const this_type& self, key_type key) const override {
			// manage getting subobjects
			return {};
		}
		virtual view do_call(const this_type& self, call_iterator begin, call_iterator end) const override {
			//manage calls
			return {};
		}

		virtual std::string do_name() const override {
			return reflect_full_name_v<T>;
		}
		virtual std::string do_to_string(const this_type& _self) const override {
			auto self = static_pointer_cast<T>(_self);
			To_String to_string_v{};
			if constexpr (requires (T t, To_String s) { s(t); }) {
				return to_string_v(*self);
			}
			else {
				return "no to string available.";
			}
		}
		virtual std::size_t do_type_hash() const override {
			return typeid(T).hash_code();
		}
	};

	template<stamp::reflect::concepts::reflect_traits_c T, typename P, typename To_String, template<typename> typename View_Base_Gen>
	class basic_member_view : view_base {
	public:
		using value_type = T;
		using ptr_type = P;

		const view_base* view;
		std::string_view name;
		ptr_type ptr;
		basic_member_view(const std::string_view& name, ptr_type ptr) : ptr(ptr) {
			view = &View_Base_Gen::view<T>;
			name = name;
		}
	protected:
		virtual view do_fetch(const this_type& self, key_type key) const override {
			auto self = static_pointer_cast<T>(_self);
			return view->do_fetch(std::shared_ptr(self, &(self.get()->*ptr)), key);
		}
		virtual view do_call(const this_type& self, iterator begin, iterator end) const override {
			auto self = static_pointer_cast<T>(_self);
			return view->do_call(std::shared_ptr(self, &(self.get()->*ptr)), key);
		}

		virtual std::string do_name() const override {
			return name;
		}
		virtual std::string do_to_string(const this_type& _self) const override {
			auto self = static_pointer_cast<T>(_self);
			To_String to_string_v{};
			if constexpr (requires (T t, To_String s) { s(t); }) {
				return to_string_v(*self);
			}
			else {
				return "no to string available.";
			}
		}
		virtual std::size_t do_type_hash() const override {
			return typeid(T).hash_code();
		}
	};
}

#endif // STAMP_REFLECT_VTABLE_H
