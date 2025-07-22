#include <pch.h>
#include <stamp/math/matrix.h>
#include <gtest/gtest.h>

using namespace STAMP_MATH_NAMESPACE;

TEST(Matrix, DefaultConstructor) {
    Matrix<float, 2, 2> m{};
    EXPECT_FLOAT_EQ(m.m[0][0], 0.0f);
    EXPECT_FLOAT_EQ(m.m[0][1], 0.0f);
    EXPECT_FLOAT_EQ(m.m[1][0], 0.0f);
    EXPECT_FLOAT_EQ(m.m[1][1], 0.0f);
}

TEST(Matrix, ConstructorAndAssignmentr) {
    Matrix<float, 2, 2> m{0.0f, 1.0f, 2.0f, 3.0f};
    EXPECT_FLOAT_EQ(m.m[0][0], 0.0f);
    EXPECT_FLOAT_EQ(m.m[0][1], 1.0f);
    EXPECT_FLOAT_EQ(m.m[1][0], 2.0f);
    EXPECT_FLOAT_EQ(m.m[1][1], 3.0f);

    auto m2{ m };
    EXPECT_FLOAT_EQ(m2.m[0][0], 0.0f);
    EXPECT_FLOAT_EQ(m2.m[0][1], 1.0f);
    EXPECT_FLOAT_EQ(m2.m[1][0], 2.0f);
    EXPECT_FLOAT_EQ(m2.m[1][1], 3.0f);

}