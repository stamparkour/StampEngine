#ifndef TEST_REFLECT_TEST_H
#define TEST_REFLECT_TEST_H

#include <gtest/gtest.h>
#include <stamp/reflect/reflect.h>

using namespace stamp::reflect;

static_assert(concepts::reflect_traits_c<int>, "int should satisfy reflect_traits_c");

static_assert(concat_cstring_v<"test", "ing"> == "testing", "concat_cstring_v should concatenate string literals");

class my_class {
	int my_private_member = 12;
};
template struct reflect_private_declare_t<&my_class::my_private_member>;

TEST(stamp_reflect, retrieve_private_member_ptr) {
	

	auto v = reflect_private_declare_t<&my_class::my_private_member>::ptr;

	my_class my_obj{};
	EXPECT_EQ(my_obj.*v, 12);
}

#endif // TEST_REFLECT_TEST_H