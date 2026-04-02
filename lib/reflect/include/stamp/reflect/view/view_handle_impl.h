#ifndef STAMP_REFLECT_VIEW_VIEW_HANDLE_IMPL_H
#define STAMP_REFLECT_VIEW_VIEW_HANDLE_IMPL_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <stdexcept>
#include <utility>

#include "../reflect_helpers.h"

namespace stamp::reflect {
	class view_handle;
	struct default_view_generator;
	template<typename T, typename ViewGen = default_view_generator>
	inline view_handle make_view_handle(const std::shared_ptr<T>& ptr);


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
		std::shared_ptr<void> ptr = nullptr;
		const view_desc_base* desc = nullptr;
	public:
		constexpr view_handle() {}
		template<typename T>
		std::shared_ptr<T> static_view_cast() const {
			return std::static_pointer_cast<T>(ptr);
		}
		template<typename T>
		constexpr view_handle(const std::shared_ptr<T>& ptr, const view_desc_base* desc) {
			this->ptr = std::static_pointer_cast<void>(ptr);
			this->desc = desc;
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
			((
				param.emplace_back(
					make_view_handle(
						std::shared_ptr<std::remove_cvref_t<Arg>>(&std::forward<Arg>(args), [](auto p) {})
					)
				)
			), ...);
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

		bool operator ==(const view_handle& other) const {
			return ptr == other.ptr && desc == other.desc;
		}
		bool operator ==(nullptr_t) const {
			return ptr == nullptr && desc == nullptr;;
		}
		bool is_void() {
			return desc->reflect_info(ptr).hash_code == reflect_info_v<void>.hash_code;
		}
	};

	view_handle view_desc_base::fetch(const self_type& self, const std::string_view& name) const {
		return do_fetch(self, name);
	}
	view_handle view_desc_base::invoke(const self_type& self, const std::vector<view_handle>& param) const {
		return do_invoke(self, param);
	}
	template<typename T, typename ViewGen>
	inline view_handle make_view_handle(const std::shared_ptr<T>& ptr) {
		return view_handle(ptr, ViewGen::template view_desc_f<T>());
	}

	namespace detail {
		class view_handle_void : public view_desc_base {
			virtual view_handle do_fetch(const self_type&, const std::string_view&) const override {
				throw std::runtime_error("cannot fetch from void view");
			}
			virtual view_handle do_invoke(const self_type&, const std::vector<view_handle>&) const override {
				throw std::runtime_error("cannot invoke void view");
			}
			virtual std::string do_to_string(const self_type&) const override {
				return "void";
			}
			virtual std::string do_name(const self_type&) const override {
				return "void";
			}
			virtual const reflect_info_t& do_reflect_info(const self_type&) const override {
				return reflect_info_v<void>;
			}
		public:
			view_handle_void() = default;
		};

		constexpr view_handle_void view_handle_void_v{};
	}

	inline const view_handle view_handle_void_v = view_handle(std::shared_ptr<void>(nullptr), &detail::view_handle_void_v);
}

#endif // STAMP_REFLECT_VIEW_VIEW_HANDLE_IMPL_H
