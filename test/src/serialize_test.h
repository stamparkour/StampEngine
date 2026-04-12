#ifndef STAMP_TEST_SERIALIZE_TEST_H
#define STAMP_TEST_SERIALIZE_TEST_H

#include <gtest/gtest.h>

#include <stamp/serialize/serialize_helpers.h>
#include <stamp/serialize/ordered_binary.h>
#include <bit>
#include <sstream>

using namespace stamp::serialize;

TEST(stamp_serialize, helpers_byte_order) {
	int val = 0x12345678;
	int expected = 0x78563412;
	std::array<char, sizeof(int)> val_arr = reinterpret_cast<std::array<char, sizeof(int)>&>(val);
	std::array<char, sizeof(int)> expected_arr = reinterpret_cast<std::array<char, sizeof(int)>&>(expected);

	//reverse test
	auto rev = reverse_bytes_arr(val);
	EXPECT_EQ(rev, expected_arr);

	// endainness test
	auto endian_arr = to_little_endian_arr(val);
	if constexpr (std::endian::native == std::endian::little) {
		EXPECT_EQ(endian_arr, val_arr);
	}
	else {
		EXPECT_EQ(endian_arr, expected_arr);
	}
}


struct my_struct {
	int a;
	float b;
};

namespace stamp::reflect {
	template<>
	struct reflect_traits<my_struct> {
		using type = my_struct;
		static constexpr string_literal name = "my_struct";

	};
}

TEST(stamp_serialize, ordered_binary) {
	if (std::endian::native != std::endian::little) return; // test not made for big endian machine

	int val = 0x12345678;
	std::stringstream out{};
	
	out << ordered_binary(val);

	auto view = out.view();
	std::string_view val_view{reinterpret_cast<const char*>(&val), sizeof(val)};
	EXPECT_EQ(view, val_view);

}

#endif // STAMP_TEST_SERIALIZE_TEST_H