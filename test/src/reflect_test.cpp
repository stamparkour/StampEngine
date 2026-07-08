#include <gtest/gtest.h>
#include <stamp/reflect/reflect.h>

using namespace stamp::reflect;

static_assert(concepts::reflect_traits_c<int>, "int should satisfy reflect_traits_c");

static_assert(concat_cstring_v<"test", "ing"> == "testing", "concat_cstring_v should concatenate string literals");

class my_class {
	int my_private_member = 12;
};

TEST(stamp_reflect, retrieve_private_member_ptr) {

}
