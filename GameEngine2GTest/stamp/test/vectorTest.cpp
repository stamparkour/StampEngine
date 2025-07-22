#include <pch.h>
#include <stamp/math/vector.h>
#include <gtest/gtest.h>

using namespace STAMP_MATH_NAMESPACE;

TEST(Vector2Test, DefaultConstructor) {
    Vector2<float> v{};
    EXPECT_FLOAT_EQ(v.x, 0.0f);
    EXPECT_FLOAT_EQ(v.y, 0.0f);
}
TEST(Vector3Test, DefaultConstructor) {
    Vector3<float> v{};
    EXPECT_FLOAT_EQ(v.x, 0.0f);
    EXPECT_FLOAT_EQ(v.y, 0.0f);
    EXPECT_FLOAT_EQ(v.z, 0.0f);
}
TEST(Vector4Test, DefaultConstructor) {
    Vector4<float> v{};
    EXPECT_FLOAT_EQ(v.x, 0.0f);
    EXPECT_FLOAT_EQ(v.y, 0.0f);
    EXPECT_FLOAT_EQ(v.z, 0.0f);
    EXPECT_FLOAT_EQ(v.w, 0.0f);
}
TEST(Vector2Test, ConstructorAndAssignment) {
    Vector2<float> a(1.0f), b(2.0f, 3.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 1.0f);
    EXPECT_FLOAT_EQ(b.x, 2.0f);
    EXPECT_FLOAT_EQ(b.y, 3.0f);
    auto c(a);
    EXPECT_FLOAT_EQ(c.x, 1.0f);
    EXPECT_FLOAT_EQ(c.y, 1.0f);
    auto d = a;
    EXPECT_FLOAT_EQ(d.x, 1.0f);
    EXPECT_FLOAT_EQ(d.y, 1.0f);
}
TEST(Vector3Test, ConstructorAndAssignment) {
    Vector3<float> a(1.0f), b(2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 1.0f);
    EXPECT_FLOAT_EQ(a.z, 1.0f);
    EXPECT_FLOAT_EQ(b.x, 2.0f);
    EXPECT_FLOAT_EQ(b.y, 3.0f);
    EXPECT_FLOAT_EQ(b.z, 4.0f);
    auto c(a);
    EXPECT_FLOAT_EQ(c.x, 1.0f);
    EXPECT_FLOAT_EQ(c.y, 1.0f);
    EXPECT_FLOAT_EQ(c.z, 1.0f);
    auto d = a;
    EXPECT_FLOAT_EQ(d.x, 1.0f);
    EXPECT_FLOAT_EQ(d.y, 1.0f);
    EXPECT_FLOAT_EQ(d.z, 1.0f);
}
TEST(Vector4Test, ConstructorAndAssignment) {
    Vector4<float> a(1.0f), b(2.0f,3.0f), c(2.0f, 3.0f, 4.0f, 5.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 1.0f);
    EXPECT_FLOAT_EQ(a.z, 1.0f);
    EXPECT_FLOAT_EQ(a.w, 1.0f);
    EXPECT_FLOAT_EQ(b.x, 2.0f);
    EXPECT_FLOAT_EQ(b.y, 3.0f);
    EXPECT_FLOAT_EQ(b.z, 2.0f);
    EXPECT_FLOAT_EQ(b.w, 3.0f);
    EXPECT_FLOAT_EQ(c.x, 2.0f);
    EXPECT_FLOAT_EQ(c.y, 3.0f);
    EXPECT_FLOAT_EQ(c.z, 4.0f);
    EXPECT_FLOAT_EQ(c.w, 5.0f);
    auto d(a);
    EXPECT_FLOAT_EQ(d.x, 1.0f);
    EXPECT_FLOAT_EQ(d.y, 1.0f);
    EXPECT_FLOAT_EQ(d.z, 1.0f);
    EXPECT_FLOAT_EQ(d.w, 1.0f);
    auto e = a;
    EXPECT_FLOAT_EQ(e.x, 1.0f);
    EXPECT_FLOAT_EQ(e.y, 1.0f);
    EXPECT_FLOAT_EQ(e.z, 1.0f);
    EXPECT_FLOAT_EQ(e.w, 1.0f);
}
TEST(Vector3Test, NestedConstructor) {
    Vector3<float> a(Vector2<float>(1.0f, 2.0f), 3.0f),
        b(1.0f, Vector2<float>(2.0f, 3.0f));

    // v3(v2,z)
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 2.0f);
    EXPECT_FLOAT_EQ(a.z, 3.0f);
    // v3(x,v2)
    EXPECT_FLOAT_EQ(b.x, 1.0f);
    EXPECT_FLOAT_EQ(b.y, 2.0f);
    EXPECT_FLOAT_EQ(b.z, 3.0f);
}

TEST(Vector4Test, NestedConstructor) {
    Vector4<float> a(Vector2<float>(1.0f, 2.0f), 3.0f, 4.0f),
        b(1.0f, 2.0f, Vector2<float>(3.0f, 4.0f)),
        c(Vector2<float>(1.0f, 2.0f), Vector2<float>(3.0f, 4.0f)),
        d(1.0f, Vector2<float>(2.0f, 3.0f), 4.0f),
        e(Vector3<float>(1.0f, 2.0f, 3.0f), 4.0f),
        f(1.0f, Vector3<float>(2.0f, 3.0f, 4.0f));
    // v4(v2,z,w)
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 2.0f);
    EXPECT_FLOAT_EQ(a.z, 3.0f);
    EXPECT_FLOAT_EQ(a.w, 4.0f);
    // v4(x,y,v2)
    EXPECT_FLOAT_EQ(b.x, 1.0f);
    EXPECT_FLOAT_EQ(b.y, 2.0f);
    EXPECT_FLOAT_EQ(b.z, 3.0f);
    EXPECT_FLOAT_EQ(b.w, 4.0f);
    // v4(v2,v2)
    EXPECT_FLOAT_EQ(c.x, 1.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f);
    EXPECT_FLOAT_EQ(c.z, 3.0f);
    EXPECT_FLOAT_EQ(c.w, 4.0f);
    // v4(x,v2,w)
    EXPECT_FLOAT_EQ(d.x, 1.0f);
    EXPECT_FLOAT_EQ(d.y, 2.0f);
    EXPECT_FLOAT_EQ(d.z, 3.0f);
    EXPECT_FLOAT_EQ(d.w, 4.0f);
    // v4(v3,w)
    EXPECT_FLOAT_EQ(e.x, 1.0f);
    EXPECT_FLOAT_EQ(e.y, 2.0f);
    EXPECT_FLOAT_EQ(e.z, 3.0f);
    EXPECT_FLOAT_EQ(e.w, 4.0f);
    // v4(x,v3)
    EXPECT_FLOAT_EQ(f.x, 1.0f);
    EXPECT_FLOAT_EQ(f.y, 2.0f);
    EXPECT_FLOAT_EQ(f.z, 3.0f);
    EXPECT_FLOAT_EQ(f.w, 4.0f);
}

TEST(Vector2Test, TypeCast) {
    Vector2<float> v1(3.0f, 4.0f);
    Vector2<int> v2 = static_cast<Vector2<int>>(v1); // conversion to int
    EXPECT_EQ(v2.x, 3);
    EXPECT_EQ(v2.y, 4);
    Vector3<float> v3 = static_cast<Vector3<float>>(v1); // conversion to Vector3
    EXPECT_FLOAT_EQ(v3.x, 3.0f);
    EXPECT_FLOAT_EQ(v3.y, 4.0f);
    EXPECT_FLOAT_EQ(v3.z, 0.0f); // Default z value
    Vector4<float> v4 = static_cast<Vector4<float>>(v1); // conversion to Vector4
    EXPECT_FLOAT_EQ(v4.x, 3.0f);
    EXPECT_FLOAT_EQ(v4.y, 4.0f);
    EXPECT_FLOAT_EQ(v4.z, 0.0f); // Default z value
    EXPECT_FLOAT_EQ(v4.w, 0.0f); // Default w value
}

TEST(Vector3Test, TypeCast) {
    Vector3<float> v1(3.0f, 4.0f, 5.0f);
    Vector2<float> v2 = static_cast<Vector2<float>>(v1); // conversion to Vector2
    EXPECT_FLOAT_EQ(v2.x, 3.0f);
    EXPECT_FLOAT_EQ(v2.y, 4.0f);
    Vector3<int> v3 = static_cast<Vector3<int>>(v1); // conversion to int
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 4);
    EXPECT_EQ(v3.z, 5);
    Vector4<float> v4 = static_cast<Vector4<float>>(v1); // conversion to Vector4
    EXPECT_FLOAT_EQ(v4.x, 3.0f);
    EXPECT_FLOAT_EQ(v4.y, 4.0f);
    EXPECT_FLOAT_EQ(v4.z, 5.0f);
    EXPECT_FLOAT_EQ(v4.w, 0.0f); // Default w value
}

TEST(Vector4Test, TypeCast) {
    Vector4<float> v1(3.0f, 4.0f, 5.0f, 6.0f);
    Vector2<float> v2 = static_cast<Vector2<float>>(v1); // conversion to Vector2
    EXPECT_FLOAT_EQ(v2.x, 3.0f);
    EXPECT_FLOAT_EQ(v2.y, 4.0f);
    Vector3<float> v3 = static_cast<Vector3<float>>(v1); // conversion to Vector3
    EXPECT_FLOAT_EQ(v3.x, 3.0f);
    EXPECT_FLOAT_EQ(v3.y, 4.0f);
    EXPECT_FLOAT_EQ(v3.z, 5.0f);
    Vector4<int> v4 = static_cast<Vector4<int>>(v1); // conversion to int
    EXPECT_EQ(v4.x, 3);
    EXPECT_EQ(v4.y, 4);
    EXPECT_EQ(v4.z, 5);
    EXPECT_EQ(v4.w, 6);
}
TEST(Vector2Test, ArithmeticOperations) {
    Vector2<float> a(1.0f, 2.0f), b(3.0f, 4.0f);
    auto c = a + b;
    EXPECT_FLOAT_EQ(c.x, 4.0f);
    EXPECT_FLOAT_EQ(c.y, 6.0f);
    c = a - b;
    EXPECT_FLOAT_EQ(c.x, -2.0f);
    EXPECT_FLOAT_EQ(c.y, -2.0f);
    c = a * b;
    EXPECT_FLOAT_EQ(c.x, 3.0f);
    EXPECT_FLOAT_EQ(c.y, 8.0f);
    c = a / b;
    EXPECT_FLOAT_EQ(c.x, 1.0f / 3.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f / 4.0f);
}
TEST(Vector3Test, ArithmeticOperations) {
    Vector3<float> a(1.0f, 2.0f, 3.0f), b(4.0f, 5.0f, 6.0f);
    auto c = a + b;
    EXPECT_FLOAT_EQ(c.x, 5.0f);
    EXPECT_FLOAT_EQ(c.y, 7.0f);
    EXPECT_FLOAT_EQ(c.z, 9.0f);
    c = a - b;
    EXPECT_FLOAT_EQ(c.x, -3.0f);
    EXPECT_FLOAT_EQ(c.y, -3.0f);
    EXPECT_FLOAT_EQ(c.z, -3.0f);
    c = a * b;
    EXPECT_FLOAT_EQ(c.x, 4.0f);
    EXPECT_FLOAT_EQ(c.y, 10.0f);
    EXPECT_FLOAT_EQ(c.z, 18.0f);
    c = a / b;
    EXPECT_FLOAT_EQ(c.x, 1.0f / 4.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f / 5.0f);
    EXPECT_FLOAT_EQ(c.z, 3.0f / 6.0f);
}
TEST(Vector4Test, ArithmeticOperations) {
	Vector4<float> a(1.0f, 2.0f, 3.0f, 4.0f), b(5.0f, 6.0f, 7.0f, 8.0f);
    auto c = a + b;
    EXPECT_FLOAT_EQ(c.x, 6.0f);
    EXPECT_FLOAT_EQ(c.y, 8.0f);
    EXPECT_FLOAT_EQ(c.z, 10.0f);
    EXPECT_FLOAT_EQ(c.w, 12.0f);
    c = a - b;
    EXPECT_FLOAT_EQ(c.x, -4.0f);
    EXPECT_FLOAT_EQ(c.y, -4.0f);
    EXPECT_FLOAT_EQ(c.z, -4.0f);
    EXPECT_FLOAT_EQ(c.w, -4.0f);
    c = a * b;
    EXPECT_FLOAT_EQ(c.x, 5.0f);
    EXPECT_FLOAT_EQ(c.y, 12.0f);
    EXPECT_FLOAT_EQ(c.z, 21.0f);
    EXPECT_FLOAT_EQ(c.w, 32.0f);
    c = a / b;
    EXPECT_FLOAT_EQ(c.x, 1.0f / 5.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f / 6.0f);
    EXPECT_FLOAT_EQ(c.z, 3.0f / 7.0f);
    EXPECT_FLOAT_EQ(c.w, 4.0f / 8.0f);
}
TEST(Vector2Test, ComparisonOperators) {
    Vector2<float> a(1.0f, 2.0f), b(1.0f, 4.0f), c(2.0f, 3.0f);
    Vector2<bool> r = a == b;
    EXPECT_TRUE(r.x);
    EXPECT_FALSE(r.y);
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a != c;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a < c;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = c > b;
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a <= b;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a >= b;
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    EXPECT_FALSE(_or(Vector2<bool>(false)));
}
TEST(Vector3Test, ComparisonOperators) {
    Vector3<float> a(1.0f, 2.0f, 3.0f), b(1.0f, 4.0f, 3.0f), c(2.0f, 3.0f, 5.0f);
    Vector3<bool> r = a == b;
    EXPECT_TRUE(r.x);
    EXPECT_FALSE(r.y);
    EXPECT_TRUE(r.z);
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a != c;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a < c;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = c > b;
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a <= b;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a >= b;
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    EXPECT_FALSE(_or(Vector3<bool>(false)));
}
TEST(Vector4Test, ComparisonOperators) {
    Vector4<float> a(1.0f, 2.0f, 3.0f,4.0f), b(1.0f, 4.0f, 3.0f, 10.0f), c(2.0f, 3.0f, 5.0f, 7.0f);
    Vector4<bool> r = a == b;
    EXPECT_TRUE(r.x);
    EXPECT_FALSE(r.y);
    EXPECT_TRUE(r.z);
    EXPECT_FALSE(r.w);
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a != c;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a < c;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = c > b;
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a <= b;
    EXPECT_TRUE(_and(r));
    EXPECT_TRUE(_or(r));
    r = a >= b;
    EXPECT_FALSE(_and(r));
    EXPECT_TRUE(_or(r));
    EXPECT_FALSE(_or(Vector4<bool>(false)));
}
TEST(Vector2Test, LogicalOperators) {
    Vector2<bool> a(true, false), b(true, true);
    Vector2<bool> r = a && b;
    EXPECT_TRUE(r.x);
    EXPECT_FALSE(r.y);
    EXPECT_FALSE(static_cast<bool>(r));
    r = a || b;
    EXPECT_TRUE(r.x);
    EXPECT_TRUE(r.y);
    EXPECT_TRUE(static_cast<bool>(r));
    r = ~a;
    EXPECT_FALSE(r.x);
    EXPECT_TRUE(r.y);
    EXPECT_FALSE(static_cast<bool>(r));
}
TEST(Vector3Test, LogicalOperators) {
    Vector3<bool> a(true, false, false), b(true, true, false);
    Vector3<bool> r = a && b;
    EXPECT_TRUE(r.x);
    EXPECT_FALSE(r.y);
    EXPECT_FALSE(r.z);
    EXPECT_FALSE(static_cast<bool>(r));
    r = a || b;
    EXPECT_TRUE(r.x);
    EXPECT_TRUE(r.y);
    EXPECT_FALSE(r.z);
    EXPECT_FALSE(static_cast<bool>(r));
    r = ~a;
    EXPECT_FALSE(r.x);
    EXPECT_TRUE(r.y);
    EXPECT_TRUE(r.z);
    EXPECT_FALSE(static_cast<bool>(r));
}
TEST(Vector4Test, LogicalOperators) {
    Vector4<bool> a(true, false, false, true), b(true, true, false, true);
    Vector4<bool> r = a && b;
    EXPECT_TRUE(r.x);
    EXPECT_FALSE(r.y);
    EXPECT_FALSE(r.z);
    EXPECT_TRUE(r.w);
    EXPECT_FALSE(static_cast<bool>(r));
    r = a || b;
    EXPECT_TRUE(r.x);
    EXPECT_TRUE(r.y);
    EXPECT_FALSE(r.z);
    EXPECT_TRUE(r.w);
    EXPECT_FALSE(static_cast<bool>(r));
    r = ~a;
    EXPECT_FALSE(r.x);
    EXPECT_TRUE(r.y);
    EXPECT_TRUE(r.z);
    EXPECT_FALSE(r.w);
    EXPECT_FALSE(static_cast<bool>(r));
}
TEST(Vector2Test, VectorOperations) {
    Vector2<float> a(3.0f, 4.0f), b(6.0f, 7.0f);
    EXPECT_FLOAT_EQ(summation(a), 7.0f);
    EXPECT_FLOAT_EQ(magnitude(a), 5.0f);
    EXPECT_FLOAT_EQ(magnitude2(a), 25.0f);
    auto n = normal(a);
    EXPECT_FLOAT_EQ(n.x, 3.0f / 5.0f);
    EXPECT_FLOAT_EQ(n.y, 4.0f / 5.0f);
    EXPECT_FLOAT_EQ(dot(a, b), 3.0f * 6.0f + 4.0f * 7.0f);
    EXPECT_FLOAT_EQ(cross(a, b), 3.0f * 7.0f - 4.0f * 6.0f);
}
TEST(Vector3Test, VectorOperations) {
    Vector3<float> a(0.0f, 3.0f, 4.0f), b(2.0f, 6.0f, 7.0f);
    EXPECT_FLOAT_EQ(summation(a), 7.0f);
    EXPECT_FLOAT_EQ(magnitude(a), 5.0f);
    EXPECT_FLOAT_EQ(magnitude2(a), 25.0f);
    auto n = normal(a);
    EXPECT_FLOAT_EQ(n.x, 0.0f);
    EXPECT_FLOAT_EQ(n.y, 3.0f / 5.0f);
    EXPECT_FLOAT_EQ(n.z, 4.0f / 5.0f);
    EXPECT_FLOAT_EQ(dot(a, b), 3.0f * 6.0f + 4.0f * 7.0f);
    n = cross(a, b);
    EXPECT_FLOAT_EQ(n.x, 3.0f * 7.0f - 4.0f * 6.0f);
    EXPECT_FLOAT_EQ(n.y, 4.0f * 2.0f);
    EXPECT_FLOAT_EQ(n.z, -3.0f * 2.0f);
}
TEST(Vector4Test, VectorOperations) {
    Vector4<float> a(0.0f, 3.0f, 4.0f, 0.0f), b(2.0f, 6.0f, 7.0f, 4.0f);
    EXPECT_FLOAT_EQ(summation(a), 7.0f);
    EXPECT_FLOAT_EQ(magnitude(a), 5.0f);
    EXPECT_FLOAT_EQ(magnitude2(a), 25.0f);
    auto n = normal(a);
    EXPECT_FLOAT_EQ(n.x, 0.0f);
    EXPECT_FLOAT_EQ(n.y, 3.0f / 5.0f);
    EXPECT_FLOAT_EQ(n.z, 4.0f / 5.0f);
    EXPECT_FLOAT_EQ(n.w, 0.0f);
    EXPECT_FLOAT_EQ(dot(a, b), 3.0f * 6.0f + 4.0f * 7.0f);
}