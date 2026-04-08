#ifndef STAMP_SERIALIZE_ORDERED_BINARY_H
#define STAMP_SERIALIZE_ORDERED_BINARY_H

#include <iostream>

namespace stamp::serialize {
	class pointer_tracker {

	};

	template<typename T>
	struct ordered_binary_serializer {
		struct formatter {

		};
	};

	template<typename T>
	inline ordered_binary_serializer<T> ordered_binary(const T&, const ordered_binary_serializer<T>::formatter&, pointer_tracker&) {

	}

	template<typename T>
	inline std::ostream& operator <<(std::ostream& os, const ordered_binary_serializer<T>& serializer) {
		return os;
	}
	template<typename T>
	inline std::istream& operator >>(std::istream& is, const ordered_binary_serializer<T>& serializer) {
		return is;
	}
}

#endif // STAMP_SERIALIZE_ORDERED_BINARY_H
