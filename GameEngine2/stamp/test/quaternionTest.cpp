//#include <stamp/math/quaternion.h>
//#include <gtest/gtest.h>
//
//using namespace STAMP_MATH_NAMESPACE;
//
//TEST(QuaternionTest, DefaultConstructor) {
//	Quaternion<float> q{};
//
//	EXPECT_FLOAT_EQ(q.x, 0.0f);
//	EXPECT_FLOAT_EQ(q.i, 0.0f);
//	EXPECT_FLOAT_EQ(q.j, 0.0f);
//	EXPECT_FLOAT_EQ(q.k, 0.0f);
//}
//
//TEST(QuaternionTest, ConstructorAndAssignment) {
//	Quaternion<float> a{ 1.0f }, b{ 2.0f, 3.0f, 4.0f, 5.0f };
//	EXPECT_FLOAT_EQ(a.x, 1.0f);
//	EXPECT_FLOAT_EQ(a.i, 0.0f);
//	EXPECT_FLOAT_EQ(a.j, 0.0f);
//	EXPECT_FLOAT_EQ(a.k, 0.0f);
//	EXPECT_FLOAT_EQ(b.x, 2.0f);
//	EXPECT_FLOAT_EQ(b.i, 3.0f);
//	EXPECT_FLOAT_EQ(b.j, 4.0f);
//	EXPECT_FLOAT_EQ(b.k, 5.0f);
//	auto c = b;
//	EXPECT_FLOAT_EQ(c.x, 2.0f);
//	EXPECT_FLOAT_EQ(c.i, 3.0f);
//	EXPECT_FLOAT_EQ(c.j, 4.0f);
//	EXPECT_FLOAT_EQ(c.k, 5.0f);
//}
//
//TEST(QuaternionTest, NestedConstructor) {
//	Quaternion<float> a{ 2.0f, Vector3f{3.0f, 4.0f, 5.0f} };
//	EXPECT_FLOAT_EQ(a.x, 2.0f);
//	EXPECT_FLOAT_EQ(a.i, 3.0f);
//	EXPECT_FLOAT_EQ(a.j, 4.0f);
//	EXPECT_FLOAT_EQ(a.k, 5.0f);
//}
//
//TEST(QuaternionTest, TypeCast) {
//	Quaternion<float> a{ 1.0f, 2.0f, 3.0f, 4.0f };
//	auto b = (float)a;
//	EXPECT_FLOAT_EQ(b, 1.0f);
//}
//
//TEST(QuaternionTest, ArithmeticOperations) {
//	Quaternion<float> a{ 1.0f, 2.0f, 3.0f, 4.0f },
//		b{ 5.0f, 6.0f, 7.0f, 8.0f };
//	auto c = a + b;
//	EXPECT_FLOAT_EQ(c.x, 6.0f);
//	EXPECT_FLOAT_EQ(c.i, 8.0f);
//	EXPECT_FLOAT_EQ(c.j, 10.0f);
//	EXPECT_FLOAT_EQ(c.k, 12.0f);
//	c = a - b;
//	EXPECT_FLOAT_EQ(c.x, -4.0f);
//	EXPECT_FLOAT_EQ(c.i, -4.0f);
//	EXPECT_FLOAT_EQ(c.j, -4.0f);
//	EXPECT_FLOAT_EQ(c.k, -4.0f);
//	c = a * b;
//	EXPECT_FLOAT_EQ(c.x, 1.0f * 5 - 2 * 6 - 3 * 7 - 4 * 8);
//	EXPECT_FLOAT_EQ(c.i, 1.0f * 6 + 2 * 5 + 3 * 8 - 4 * 7);
//	EXPECT_FLOAT_EQ(c.j, 1.0f * 7 - 2 * 8 + 3 * 5 + 4 * 6);
//	EXPECT_FLOAT_EQ(c.k, 1.0f * 8 + 2 * 7 - 3 * 6 + 4 * 5);
//	c = 1.0f / a;
//	EXPECT_FLOAT_EQ(c.x, 1.0f / 30);
//	EXPECT_FLOAT_EQ(c.i, -2.0f / 30);
//	EXPECT_FLOAT_EQ(c.j, -3.0f / 30);
//	EXPECT_FLOAT_EQ(c.k, -4.0f / 30);
//}
//
//TEST(QuaternionTest, QuaternionOperations) {
//	Quaternion<float> a{ 1.0f, 2.0f, 3.0f, 4.0f };
//	auto c = unit(a);
//	EXPECT_FLOAT_EQ(c.x, 1.0f / sqrt(30.0f));
//	EXPECT_FLOAT_EQ(c.i, 2.0f / sqrt(30.0f));
//	EXPECT_FLOAT_EQ(c.j, 3.0f / sqrt(30.0f));
//	EXPECT_FLOAT_EQ(c.k, 4.0f / sqrt(30.0f));
//}