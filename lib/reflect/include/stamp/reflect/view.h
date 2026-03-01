#pragma once
#ifndef STAMP_REFLECT_VTABLE_H
#define STAMP_REFLECT_VTABLE_H

#include "reflect_traits.h"
#include "reflect_helpers.h"
#include <string>
#include <vector>
#include <memory>

// unified way to access class member attributes and methods and interact with them.

namespace reflect::stamp {
	class view;
	using reflect_member_fetch_ptr_v = view(*)(const std::shared_ptr<void>&, std::size_t);
	using reflect_member_call_ptr_v = view(*)(const std::shared_ptr<void>&, const std::vector<view>&);

	class view_vtable {
		reflect_member_fetch_ptr_v fetch;
		reflect_member_call_ptr_v call;
	};

	class view {
	private:
		std::weak_ptr<void> ptr;
		const view_vtable* vtable;
	public:
		view() = default;
		virtual ~view() = default;

		view operator[](std::size_t i) {}
		const view operator[](std::size_t i) const {}
		template<typename... T>
		view operator()(T... t) {}
		template<typename... T>
		const view operator()(T... t) const {}
	};
}

#endif // STAMP_REFLECT_VTABLE_H
