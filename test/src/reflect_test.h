#ifndef TEST_REFLECT_TEST_H
#define TEST_REFLECT_TEST_H

#include <gtest/gtest.h>
#include <stamp/reflect/reflect.h>

using namespace stamp::reflect;

static_assert(concepts::reflect_traits_c<int>, "int should satisfy reflect_traits_c");

static_assert(concat_cstring_v<"test", "ing"> == "testing", "concat_cstring_v should concatenate string literals");


#endif // TEST_REFLECT_TEST_H