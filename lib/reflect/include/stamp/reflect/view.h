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
		view_handle handle;
	public:

		//creates a reference view
		template<typename T>
		view(T& t) {
			handle = view_handle{ std::shared_ptr<T>(&t, [](T*) {}) };
		}
		//creates a copy view
		template<typename T>
		view(const T& t) {
			handle = view_handle{ std::make_shared<T>(t) };
		}
		template<typename T>
		view(T&& t) {
			handle = view_handle{ std::make_shared<T>(t) };
		}
		//create from handle
		view(const view_handle& handle) {
			this->handle = handle;
		}

		view_handle fetch(const std::string_view& str) {
			return handle.fetch(str);
		}
		template<typename... Arg>
		view_handle invoke(Arg&&... args) {
			return handle.invoke(std::forward<Arg>(args)...);
		}
	};
}

#endif // STAMP_REFLECT_VIEW_H
