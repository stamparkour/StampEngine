#ifndef STAMP_REFLECT_REFLECT_PRIVATE_H
#define STAMP_REFLECT_REFLECT_PRIVATE_H

namespace stamp::reflect {
	namespace detail {
		
	}

	template<auto Ptr>
	struct reflect_private_declare_t {
		static constexpr auto ptr = Ptr;
	};
}

#endif // STAMP_REFLECT_REFLECT_PRIVATE_H