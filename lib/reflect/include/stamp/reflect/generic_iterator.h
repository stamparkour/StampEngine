// stamp/reflect/generic_iterator.h
#ifndef STAMP_REFLECT_GENERIC_ITERATOR_H
#define STAMP_REFLECT_GENERIC_ITERATOR_H

namespace stamp::reflect {
	template<typename T>
	class generic_forward_iterator {
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::input_iterator_tag;
		virtual ~generic_iterator() = default;
		virtual reference operator*() const = 0;
		virtual pointer operator->() const = 0;
		virtual generic_iterator& operator++() = 0;
		virtual generic_iterator operator++(int) = 0;
		virtual bool operator==(const generic_iterator& other) const = 0;
		virtual bool operator!=(const generic_iterator& other) const = 0;
	};
}

#endif // STAMP_REFLECT_GENERIC_ITERATOR_H
