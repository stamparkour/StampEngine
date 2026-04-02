#pragma once
#ifndef STAMP_REFLECT_VIEW_HANDLE_H
#define STAMP_REFLECT_VIEW_HANDLE_H

#include <memory>
#include <utility>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <functional>
#include <type_traits>

#include "member_function_traits.h"
#include "reflect.h"

namespace stamp::reflect {
	class view_handle;
	class default_view_desc_generator;
	template<typename T, typename ViewGen = default_view_desc_generator>
	view_handle make_view_handle(const std::shared_ptr<T>& ptr);
	template<typename Y, typename T, typename ViewGen = default_view_desc_generator>
	view_handle make_view_handle_explicit(const std::shared_ptr<T>& ptr);

	// might need changing in order to accomodate 
	using type_hash_t = std::size_t;
	template<typename T>
	const type_hash_t type_hash_v = typeid(T).hash_code();

	class view_desc_base {
		template<typename T, typename ViewGen>
		friend inline view_handle make_view_handle(const std::shared_ptr<T>& ptr);

		virtual view_handle do_fetch(const std::shared_ptr<void>& self, const std::string_view& key) const = 0;
		virtual view_handle do_invoke(const std::shared_ptr<void>& self, const std::vector<view_handle>& vec) const = 0;
		virtual std::string do_name(const std::shared_ptr<void>& self) const { return {}; }
		virtual std::string do_type_name(const std::shared_ptr<void>& self) const { return {}; }
		virtual std::string do_to_string(const std::shared_ptr<void>& self) const { return {}; }
		virtual type_hash_t do_type_hash(const std::shared_ptr<void>& self) const = 0;
	public:
		view_handle fetch(const std::shared_ptr<void>& self, const std::string_view& key) const;
		view_handle invoke(const std::shared_ptr<void>& self, const std::vector<view_handle>& vec) const;
		std::string name(const std::shared_ptr<void>& self) const;
		std::string type_name(const std::shared_ptr<void>& self) const;
		std::string to_string(const std::shared_ptr<void>& self) const;
		type_hash_t type_hash(const std::shared_ptr<void>& self) const;
	};

	class view_handle {
		std::shared_ptr<void> ptr;
		const view_desc_base* desc;
	public:
		view_handle(const std::shared_ptr<void>& ptr, const view_desc_base* desc) : ptr(ptr), desc(desc) {}

		view_handle() : ptr(nullptr), desc(nullptr) {}
		view_handle(nullptr_t) : view_handle() {}

		view_handle fetch(const std::string_view& str) const {
			return desc->fetch(ptr, str);
		}
		template<typename... Arg>
		view_handle invoke(Arg&&... args) const {
			std::vector<view_handle> param{};
			((
				param.emplace_back(
					make_view_handle_explicit<Arg>(
						std::shared_ptr<std::remove_cvref_t<Arg>>(&static_cast<std::remove_cvref_t<Arg>&>(args), [](auto p) {})
					)
				)
			) , ...);
			return desc->invoke(ptr, param);
		}

		std::shared_ptr<void> data() {
			return ptr;
		}
		template<typename T>
		std::shared_ptr<T> static_view_cast() const {
			return std::static_pointer_cast<T>(ptr);
		}

		template<typename... Arg>
		std::string name() const {
			return desc->name(ptr);
		}
		template<typename... Arg>
		std::string type_name() const {
			return desc->type_name(ptr);
		}
		template<typename... Arg>
		std::string to_string() const {
			return desc->to_string(ptr);
		}
		type_hash_t type_hash() const {
			return desc->type_hash(ptr);
		}
		const view_desc_base* desc_base() const {
			return desc;
		}
		bool is_void() const {
			return ptr != nullptr && desc == nullptr;
		}
		bool operator ==(nullptr_t) {
			return ptr == nullptr && desc == nullptr;
		}
	};


	template<typename T, typename ViewGen>
	view_handle make_view_handle(const std::shared_ptr<T>& ptr) {
		return view_handle{std::static_pointer_cast<void>(ptr), &ViewGen::template value_desc_v<T>()};
	}
	template<typename Y, typename T, typename ViewGen>
	view_handle make_view_handle_explicit(const std::shared_ptr<T>& ptr) {
		return view_handle{std::static_pointer_cast<void>(ptr), &ViewGen::template value_desc_v<Y>()};
	}
	namespace detail {
		using view_void_t = int;
		inline constexpr view_void_t view_void_v{};
	}
	inline const view_handle& view_handle_void_f() {
		static auto v = view_handle(std::shared_ptr<detail::view_void_t>{const_cast<detail::view_void_t*>(&detail::view_void_v), [](auto p) {}}, nullptr);
		return v;
	}

	view_handle view_desc_base::fetch(const std::shared_ptr<void>& self, const std::string_view& key) const {
		return do_fetch(self, key);
	}
	view_handle view_desc_base::invoke(const std::shared_ptr<void>& self, const std::vector<view_handle>& vec) const {
		return do_invoke(self, vec);
	}
	std::string view_desc_base::name(const std::shared_ptr<void>& self) const {
		return do_name(self);
	}
	std::string view_desc_base::type_name(const std::shared_ptr<void>& self) const {
		return do_type_name(self);
	}
	std::string view_desc_base::to_string(const std::shared_ptr<void>& self) const {
		return do_to_string(self);
	}
	inline type_hash_t view_desc_base::type_hash(const std::shared_ptr<void>& self) const {
		return do_type_hash(self);
	}

	template<typename T, typename ToString, typename ViewGen>
	class default_value_desc_t : public view_desc_base {
	public:
		using type = std::remove_cvref_t<T>;
	private:
		std::unordered_map<std::string_view, view_desc_base*> map{};
	protected:
		virtual view_handle do_fetch(const std::shared_ptr<void>& void_self, const std::string_view& key) const override {
			auto p = map.find(key);
			if (p == map.end()) return nullptr;

			auto& v = p->second;

			return view_handle{void_self, v};
		}
		virtual view_handle do_invoke(const std::shared_ptr<void>& void_self, const std::vector<view_handle>& vec) const override {
			throw std::runtime_error("failed to invoke view_handle");
		}
		virtual std::string do_name(const std::shared_ptr<void>& self) const override {
			return {};
		}
		virtual std::string do_type_name(const std::shared_ptr<void>& self) const override {
			return stamp::reflect::traits::full_name_v<type>;
		}
		virtual std::string do_to_string(const std::shared_ptr<void>& void_self) const override {
			auto self = static_cast<type*>(void_self.get());
			ToString to_string_v{};
			return to_string_v(*self);
		}
		virtual type_hash_t do_type_hash(const std::shared_ptr<void>& void_self) const override {
			return type_hash_v<type>;
		}
	public:
		default_value_desc_t() {
			// used 'new,' because this class is never deleted.
			for_each_reflect_member_properties<type>([&]<typename P>(const P& property) -> void {
				// P is a stamp::reflect::property
				std::string_view str = property.name();
				auto ptr = property.member_ptr();
				//														base type, child type
				view_desc_base* desc = new ViewGen::template property_desc_t<type, typename P::value_type>{
					str,
					ptr
				};
				map.emplace(str, desc);
			});

			for_each_reflect_member_functions<type>([&]<typename P>(const P& function) -> void {
				using func_desc_t = ViewGen::template function_desc_t<type>;
				// P is a stamp::reflect::property
				std::string_view str = function.name();
				auto ptr = function.member_ptr();
				func_desc_t* desc = nullptr;

				if (auto map_i = map.find(str); map_i != map.end() ) {
					view_desc_base* k = map_i->second;
					desc = static_cast<func_desc_t*>(k);
				}
				else {
					desc = new func_desc_t{str};
					map.emplace(str, desc);
				}
				// desc is now a valid target

				desc->insert(ptr);

			});
		}
		~default_value_desc_t() {
			map.clear();
			auto k = std::move(map);
		}
	};

	template<typename BaseT, typename ValT, typename ToString, typename ViewGen>
	class default_property_desc_t : public view_desc_base {
	public:
		using type = ValT;
		using base_type = BaseT;
	private:
		std::string_view name_v;
		type base_type::* ptr;
	protected:
		virtual view_handle do_fetch(const std::shared_ptr<void>& void_self, const std::string_view& key) const override {
			auto self = static_cast<base_type*>(void_self.get());

			auto& mem_v = self->*ptr;
			auto void_ptr_v = std::shared_ptr<void>(void_self, static_cast<void*>(&mem_v));
			auto desc_v = &ViewGen::template value_desc_v<type>();
			return desc_v->fetch(void_ptr_v, key);
		}
		virtual view_handle do_invoke(const std::shared_ptr<void>& void_self, const std::vector<view_handle>& vec) const override {
			throw std::runtime_error("failed to invoke view_handle");
		}
		virtual std::string do_name(const std::shared_ptr<void>& self) const override {
			return std::string{name_v};
		}
		virtual std::string do_type_name(const std::shared_ptr<void>& self) const override {
			return stamp::reflect::traits::full_name_v<type>;
		}
		virtual std::string do_to_string(const std::shared_ptr<void>& void_self) const override {
			auto self = static_cast<base_type*>(void_self.get());
			auto& mem_v = self->*ptr;
			ToString to_string_v{};
			return to_string_v(mem_v);
		}
		virtual type_hash_t do_type_hash(const std::shared_ptr<void>& void_self) const override {
			return type_hash_v<type>;
		}
	public:
		default_property_desc_t(const std::string_view& name, type base_type::* ptr) : name_v(name), ptr(ptr) {}
	};

	namespace detail {
		template<typename A>
		A ref_qual_cast(A&& v) {
			if constexpr (std::is_rvalue_reference_v<A>) {
				return std::move(v);
			}
			else {
				return std::forward<A>(v);
			}
		}
	}

	template<typename BaseT, typename ToString, typename ViewGen>
	class default_function_desc_t : public view_desc_base {
	public:
		using base_type = std::remove_cvref_t<BaseT>;
		using function_type = std::function<view_handle(base_type*, const std::vector<view_handle>&)>;
	private:
		struct function_desc_t {
			std::vector<size_t> args_hash;
			function_type ptr;

			bool match(const std::vector<view_handle>& vec) const {
				if (args_hash.size() != vec.size()) return false;

				auto vec_i = vec.begin();
				auto args_i = args_hash.begin();
				for (; vec_i != vec.end() && args_i != args_hash.end(); (void)(++vec_i), (void)(++args_i)) {
					if (vec_i->type_hash() != *args_i) return false;
				}
				return true;
			}
		};

		std::string_view name_v;
		std::vector<function_desc_t> functions{};
	protected:
		virtual view_handle do_fetch(const std::shared_ptr<void>& void_self, const std::string_view& key) const override {
			return nullptr;
		}
		virtual view_handle do_invoke(const std::shared_ptr<void>& void_self, const std::vector<view_handle>& vec) const override {
			auto self = static_cast<base_type*>(void_self.get());

			for (const auto& i : functions) {
				if (i.match(vec)) {
					return i.ptr(self, vec);
				}
			}
			throw std::runtime_error("failed to invoke view_handle");
		}
		virtual std::string do_name(const std::shared_ptr<void>& self) const override {
			return std::string{name_v};
		}
		virtual std::string do_type_name(const std::shared_ptr<void>& self) const override {
			return stamp::reflect::traits::full_name_v<base_type>;
		}
		virtual std::string do_to_string(const std::shared_ptr<void>& void_self) const override {
			auto self = static_cast<base_type*>(void_self.get());
			return {};
		}
		virtual type_hash_t do_type_hash(const std::shared_ptr<void>& void_self) const override {
			return type_hash_v<function_type>;
		}
	public:
		default_function_desc_t(const std::string_view& name) : name_v(name) {}
		void insert_base(const std::vector<size_t>& args_hash, function_type ptr) {
			functions.emplace_back(args_hash, ptr);
		}

		template<typename T>
		void insert(T func_ptr) {
			using result_type = member_function_traits<T>::result_type;
			using arg_type = member_function_traits<T>::arg_type;
			using arg_ref_type = member_function_traits<T>::arg_type;

			std::vector<size_t> hashs{};

			for_each<arg_type>([&]<typename TupleElement>(TupleElement) {
				using type = TupleElement::type;
				hashs.emplace_back(type_hash_v<type>);
			});

			insert_base(hashs, [func_ptr](BaseT* self, const std::vector<view_handle>& vec) -> view_handle {

				if (vec.size() != std::tuple_size_v<arg_ref_type>) {
					throw std::runtime_error("must have equal size for runtime function execution");
				}

				auto vec_i = vec.begin();
				arg_type args{for_each_construct<arg_type>([&]<typename P>(P p) -> P::type {
					using type = P::type;
					auto vec_pointer = vec_i->static_view_cast<std::remove_cvref_t<type>>();
					++vec_i;
					return *vec_pointer;
				})};

				if constexpr (std::same_as<result_type,void>) {
					std::apply([&]<typename... Args>(Args&&... args) {
+						(self->*func_ptr)(args...);
					}, args);
					return view_handle_void_f();
				}
				else {
					std::shared_ptr<result_type> t = std::make_shared(std::apply([&]<typename... Args>(Args&&... args) {
						return self->*func_ptr(std::forward<Args>(args)...);
					}, args));
					return make_view_handle(t);
				}
			});
		}
	};


	struct default_to_string {
		template<typename T>
		std::string operator ()(T&& val) {
			if constexpr (requires (T & t) { std::to_string(t); }) {
				return std::to_string(std::forward<T>(val));
			}
			else if constexpr (requires (T & t) { t.to_string(); }) {
				return std::forward<T>(val).to_string();
			}
			else {
				return {};
			}
		}
	};

	struct default_view_desc_generator {
		template<typename ValT>
		static const auto& value_desc_v() {
			static auto val = default_value_desc_t<ValT, default_to_string, default_view_desc_generator>{};
			return val;
		}
		template<typename BaseT, typename ValT>
		using property_desc_t = default_property_desc_t<BaseT, ValT, default_to_string, default_view_desc_generator>;
		template<typename BaseT>
		using function_desc_t = default_function_desc_t<BaseT, default_to_string, default_view_desc_generator>;
	};
}

#endif // STAMP_REFLECT_VIEW_HANDLE_H