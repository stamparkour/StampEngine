#pragma once
#ifndef STAMP_REFLECT_VIEW_H
#define STAMP_REFLECT_VIEW_H

#include "view_handle.h"
#include <memory>
#include <string>
#include <string_view>
#include <utility>

// unified way to access class member attributes and methods and interact with them.

namespace stamp::reflect {
	class view {
		view_handle handle_v;
	public:

		//creates a reference view
		template<typename T>
		view(T& t) {
			handle_v = make_view_handle( std::shared_ptr<T>(&t, [](T*) {}) );
		}
		//creates a copy view
		template<typename T>
		view(const T& t) {
			handle_v = make_view_handle(std::make_shared<T>(t) );
		}
		//create from handle
		view(const view_handle& handle) {
			this->handle_v = handle;
		}

		view_handle fetch(const std::string_view& str) {
			return handle_v.fetch(str);
		}
		template<typename... Arg>
		view_handle invoke(Arg&&... args) {
			return handle_v.invoke(std::forward<Arg>(args)...);
		}
		std::string name() const {
			return handle_v.name();
		}
		std::string to_string() const {
			return handle_v.to_string();
		}
		reflect_info_t reflect_info() const {
			return handle_v.reflect_info();
		}
		view_handle& handle() {
			return handle_v;
		}
		const view_handle& handle() const {
			return handle_v;
		}
	};
}

#endif // STAMP_REFLECT_VIEW_H
