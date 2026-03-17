#pragma once
#ifndef STAMP_REFLECT_VIEW_HANDLE_H
#define STAMP_REFLECT_VIEW_HANDLE_H

#include <memory>
#include <utility>
#include <string>
#include <string_view>

namespace stamp::reflect {
	class view_desc_base {
	public:

	};
	class view_handle {
		std::shared_ptr<void> ptr;
		const view_desc_base* desc;
	public:
		template<typename T>
		view_handle(const std::shared_ptr<T>& ptr) {
			this->ptr = std::static_pointer_cast<void>(ptr);
			//desc = 
		}
		template<typename T>
		view_handle(std::shared_ptr<T>&& ptr) {
			this->ptr = std::static_pointer_cast<void>(ptr);
			//desc =
		}

		view_handle fetch(const std::string_view& str) {

		}
		template<typename... Arg>
		view_handle invoke(Arg&&... args) {
			std::vector<view_handle> param{};
			((param.emplace_back(std::shared_ptr(&args, [](){}))), ...);
		}
	};


}

#endif // STAMP_REFLECT_VIEW_HANDLE_H