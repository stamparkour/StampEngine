#pragma once
#ifndef STAMP_REFLECT_VIEW_HANDLE_H
#define STAMP_REFLECT_VIEW_HANDLE_H

#include <memory>
#include <utility>
#include <string>
#include <string_view>
#include <memory>
#include <concepts>
#include <unordered_map>
#include <vector>
#include <functional>
#include <stdexcept>

#include "reflect_traits.h"
#include "reflect_helpers.h"

namespace stamp::reflect {
	class view_handle;
	struct default_view_generator;


	class view_desc_base {
	public:
		using self_type = std::shared_ptr<void>;
	private:
		virtual view_handle do_fetch(const self_type&, const std::string_view&) const = 0;
		virtual view_handle do_invoke(const self_type&, const std::vector<view_handle>&) const = 0;
		virtual std::string do_to_string(const self_type&) const = 0;
		virtual std::string do_name(const self_type&) const = 0;
		virtual const reflect_info_t& do_reflect_info(const self_type&) const = 0;
	public:
		view_desc_base() = default;
		~view_desc_base() = default;

		view_handle fetch(const self_type& self, const std::string_view& name) const;
		view_handle invoke(const self_type& self, const std::vector<view_handle>& param) const;
		std::string to_string(const self_type& self) const {
			return do_to_string(self);
		}
		std::string name(const self_type& self) const {
			return do_name(self);
		}
		const reflect_info_t& reflect_info(const self_type& self) const {
			return do_reflect_info(self);
		}
	};

	class view_handle {
		std::shared_ptr<void> ptr;
		const view_desc_base* desc;
	public:
		view_handle() {}
		template<typename T>
		std::shared_ptr<T> static_view_cast() const {
			return std::static_pointer_cast<T>(ptr);
		}
		view_handle(const std::shared_ptr<T>& ptr, const view_desc_base* desc) {
			this->ptr = std::static_pointer_cast<void>(ptr);
			this->desc = desc;
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

		view_handle fetch(const std::string_view& str) {
			return desc->fetch(ptr, str);
		}
		const view_handle fetch(const std::string_view& str) const {
			return desc->fetch(ptr, str);
		}
		template<typename... Arg>
		view_handle invoke(Arg&&... args) {
			std::vector<view_handle> param{};
			((param.emplace_back(std::shared_ptr(&args, [](auto p) {}))), ...);
			return desc->invoke(ptr, param);
		}
		std::string to_string() const {
			return desc->to_string(ptr);
		}
		std::string name() const {
			return desc->name(ptr);
		}
		const reflect_info_t& reflect_info() const {
			return desc->reflect_info(ptr);
		}
	};

	view_handle view_desc_base::fetch(const self_type& self, const std::string_view& name) const {
		return do_fetch(self, name);
	}
	view_handle view_desc_base::invoke(const self_type& self, const std::vector<view_handle>& param) const {
		return do_invoke(self, param);
	}

	template<typename T, typename ViewGen = default_view_generator>
	inline view_handle make_view_handle(const std::shared_ptr<T>& ptr) {
		return view_handle(ptr, ViewGen::template view_desc_f<T>());
	}

	template<typename ValT, typename ToString, typename ViewGen>
	class default_view_desc : public view_desc_base {
	public:
		using type = ValT;
		using self_type = view_desc_base::self_type;
	private:
		std::unordered_map<std::string_view, view_desc_base*> members{};

		virtual view_handle do_fetch(const self_type& void_self, const std::string_view& target) const override {
			auto self = static_cast<type*>(void_self.get());

			if (auto p = members.find(target); p != members.end()) {
				return view_handle{ void_self, p->second };
			}
			else {
				throw std::runtime_error("member not found: " + std::string(target));
			}
		}
		virtual view_handle do_invoke(const self_type&, const std::vector<view_handle>&) const override {
			throw std::runtime_error(std::string("cannot invoke an object view: ") + std::string(traits::full_name_v<ValT>));
		}
		virtual std::string do_to_string(const self_type& void_self) const override {
			auto self = static_cast<type*>(void_self.get());
			ToString to_string_f{};

			return to_string_f(*self);
		}
		virtual std::string do_name(const self_type&) const override {
			return std::string(traits::full_name_v<type>);
		}
		virtual const reflect_info_t& do_reflect_info(const self_type&) const override {
			return reflect_info_v<type>;
		}
	public:
		default_view_desc() {
			for_each_reflect_member_properties<type>([&]<typename T>(const T& property) {
				using ptr_type = typename T::ptr_type;
				using value_type = typename T::value_type;
				using class_type = typename T::class_type;
				using view_desc_base_t = typename ViewGen::template property_view_desc<value_type, class_type>;

				std::string_view name = property.name();
				auto ptr = property.member_ptr();

				members.emplace(name, new view_desc_base_t{name, ptr});
			});
		}
	};


	template<typename ValT, typename BaseT, typename ToString, typename ViewGen>
	class default_property_view : public view_desc_base {
	public:
		using self_type = view_desc_base::self_type;
		using base_type = BaseT;
		using value_type = ValT;
		using ptr_type = value_type base_type::*;
	private:
		std::string_view name;
		ptr_type member_ptr;

		virtual view_handle do_fetch(const self_type& void_self, const std::string_view& target) const override {
			auto self = static_cast<base_type*>(void_self.get());

			auto next_ptr = std::shared_ptr<void>{ void_self, (void*)(self->*member_ptr) };
			return ViewGen::template view_desc_f<value_type>()->fetch(next_ptr, target);
		}
		virtual view_handle do_invoke(const self_type&, const std::vector<view_handle>&) const override {
			throw std::runtime_error("cannot invoke an object view: " + std::string{ traits::full_name_v<ValT> });
		}
		virtual std::string do_to_string(const self_type& void_self) const override {
			auto self = static_cast<base_type*>(void_self.get());
			ToString to_string_f{};

			return to_string_f(self->*member_ptr);
		}
		virtual std::string do_name(const self_type&) const override {
			return std::string{ name };
		}
		virtual const reflect_info_t& do_reflect_info(const self_type&) const override {
			return reflect_info_v<value_type>;
		}
	public:
		default_property_view(const std::string_view& name, ptr_type member_ptr) {
			this->name = name;
			this->member_ptr = member_ptr;
		}
	};

	template<typename BaseT, typename ToString, typename ViewGen>
	class default_function_view : public view_desc_base {
	public:
		using self_type = view_desc_base::self_type;
		using base_type = BaseT;
	private:
		using function_type = std::function<view_handle(base_type*, const std::vector<view_handle>&)>;
		std::string_view name;
		struct function_entry_t {
			std::vector<std::size_t> param_hashes;
			function_type function;
		};
		std::vector<function_entry_t> overloads{};

		virtual view_handle do_fetch(const self_type& void_self, const std::string_view& target) const override {
			throw std::runtime_error("cannot fetch a function view: " + std::string{ traits::full_name_v<ValT> });
		}
		virtual view_handle do_invoke(const self_type& void_self, const std::vector<view_handle>& handles) const override {
			auto self = static_cast<base_type*>(void_self.get());

			std::vector<std::size_t> param_hashes{};
			param_hashes.reserve(handles.size());
			for (cost auto& h : handles) {
				param_hashes.push_back(h.reflect_info().hash_code);
			}


		}
		virtual std::string do_to_string(const self_type& void_self) const override {
			auto self = static_cast<base_type*>(void_self.get());
			ToString to_string_f{};

			return to_string_f(self->*member_ptr);
		}
		virtual std::string do_name(const self_type&) const override {
			return std::string{ name };
		}
		virtual const reflect_info_t& do_reflect_info(const self_type&) const override {
			return reflect_info_v<value_type>;
		}
	public:
		default_property_view(const std::string_view& name) {
			this->name = name;
		}
		template<typename T>
		void push(T func) {

		}

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

				if constexpr (std::same_as<result_type, void>) {
					std::apply([&]<typename... Args>(Args&&... args) {
						+(self->*func_ptr)(args...);
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
		std::string operator()(const T& value) const {
			if constexpr (std::is_same_v<T, std::string>) {
				return value;
			}
			else if constexpr (requires(T t) { { std::string(t) } -> std::same_as<std::string>; }) {
				return std::string(value);
			}
			else if constexpr (requires(T t) { { std::to_string(t) } -> std::same_as<std::string>; }) {
				return std::to_string(value);
			}
			else if constexpr (requires(T t) { { t.to_string() } -> std::same_as<std::string>; }) {
				return value.to_string();
			}
			else {
				return {};
			}
		}
	};

	struct default_view_generator {
		template<typename ValT>
		static const view_desc_base* view_desc_f() {
			static_assert(concepts::reflect_traits_c<ValT>, "Type must have reflect_traits specialization");
			static default_view_desc<ValT, default_to_string, default_view_generator> desc{};
			return &desc;
		};
		template<typename ValT, typename BaseT>
		using property_view_desc = default_property_view<ValT, BaseT, default_to_string, default_view_generator>;
		template<typename BaseT>
		using function_view_desc = default_function_view<BaseT, default_to_string, default_view_generator>;
	};
}


#endif // STAMP_REFLECT_VIEW_HANDLE_H