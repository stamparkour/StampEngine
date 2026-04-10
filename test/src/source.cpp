// #include "math_test.h"
#include <gtest/gtest.h>

#include "serialize_test.h"
#include  "reflect_test.h"

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}