#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/math/vector.h>
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_MATH_NAMESPACE;

namespace Math {

TEST_CLASS(Vector2Test) {
public:
    TEST_METHOD(DefaultConstructor) {
        Vector2<float> v{};
        Assert::AreEqual(v.x, 0.0f);
        Assert::AreEqual(v.y, 0.0f);
	}
    TEST_METHOD(ConstructorAndAssignment) {
        Vector2<float> a(1.0f), b(2.0f, 3.0f);
        Assert::AreEqual(a.x, 1.0f);
        Assert::AreEqual(a.y, 1.0f);
        Assert::AreEqual(b.x, 2.0f);
        Assert::AreEqual(b.y, 3.0f);
        auto c(a);
        Assert::AreEqual(c.x, 1.0f);
        Assert::AreEqual(c.y, 1.0f);
        auto d = a;
        Assert::AreEqual(d.x, 1.0f);
        Assert::AreEqual(d.y, 1.0f);
    }
    TEST_METHOD(TypeCast) {
        Vector2<float> v1(3.0f, 4.0f);
        Vector2<int> v2 = static_cast<Vector2<int>>(v1); // conversion to int
        Assert::AreEqual(v2.x, 3);
        Assert::AreEqual(v2.y, 4);
        Vector3<float> v3 = static_cast<Vector3<float>>(v1); // conversion to Vector3
        Assert::AreEqual(v3.x, 3.0f);
        Assert::AreEqual(v3.y, 4.0f);
        Assert::AreEqual(v3.z, 0.0f); // Default z value
        Vector4<float> v4 = static_cast<Vector4<float>>(v1); // conversion to Vector4
        Assert::AreEqual(v4.x, 3.0f);
        Assert::AreEqual(v4.y, 4.0f);
        Assert::AreEqual(v4.z, 0.0f); // Default z value
        Assert::AreEqual(v4.w, 0.0f); // Default w value
    }
    TEST_METHOD(ArithmeticOperations) {
        Vector2<float> a(1.0f, 2.0f), b(3.0f, 4.0f);
        auto c = a + b;
        Assert::AreEqual(c.x, 4.0f);
        Assert::AreEqual(c.y, 6.0f);
        c = a - b;
        Assert::AreEqual(c.x, -2.0f);
        Assert::AreEqual(c.y, -2.0f);
        c = a * b;
        Assert::AreEqual(c.x, 3.0f);
        Assert::AreEqual(c.y, 8.0f);
        c = a / b;
        Assert::AreEqual(c.x, 1.0f / 3.0f);
        Assert::AreEqual(c.y, 2.0f / 4.0f);
    }
    TEST_METHOD(ComparisonOperators) {
        Vector2<float> a(1.0f, 2.0f), b(1.0f, 4.0f), c(2.0f, 3.0f);
        Vector2<bool> r = a == b;
        Assert::IsTrue(r.x);
        Assert::IsFalse(r.y);
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        r = a != c;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = a < c;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = c > b;
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        r = a <= b;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = a >= b;
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        Assert::IsFalse(_or(Vector2<bool>(false)));
    }
    TEST_METHOD(LogicalOperators) {
        Vector2<bool> a(true, false), b(true, true);
        Vector2<bool> r = a && b;
        Assert::IsTrue(r.x);
        Assert::IsFalse(r.y);
        Assert::IsFalse(static_cast<bool>(r));
        r = a || b;
        Assert::IsTrue(r.x);
        Assert::IsTrue(r.y);
        Assert::IsTrue(static_cast<bool>(r));
        r = ~a;
        Assert::IsFalse(r.x);
        Assert::IsTrue(r.y);
        Assert::IsFalse(static_cast<bool>(r));
    }
    TEST_METHOD(VectorOperations) {
        Vector2<float> a(3.0f, 4.0f), b(6.0f, 7.0f);
        Assert::AreEqual(summation(a), 7.0f);
        Assert::AreEqual(magnitude(a), 5.0f);
        Assert::AreEqual(magnitude2(a), 25.0f);
        auto n = normal(a);
        Assert::AreEqual(n.x, 3.0f / 5.0f);
        Assert::AreEqual(n.y, 4.0f / 5.0f);
        Assert::AreEqual(dot(a, b), 3.0f * 6.0f + 4.0f * 7.0f);
        Assert::AreEqual(cross(a, b), 3.0f * 7.0f - 4.0f * 6.0f);
    }
};
TEST_CLASS(Vector3Test) {
public:
    TEST_METHOD(DefaultConstructor) {
        Vector3<float> v{};
        Assert::AreEqual(v.x, 0.0f);
        Assert::AreEqual(v.y, 0.0f);
        Assert::AreEqual(v.z, 0.0f);
    }
    TEST_METHOD(ConstructorAndAssignment) {
        Vector3<float> a(1.0f), b(2.0f, 3.0f, 4.0f);
        Assert::AreEqual(a.x, 1.0f);
        Assert::AreEqual(a.y, 1.0f);
        Assert::AreEqual(a.z, 1.0f);
        Assert::AreEqual(b.x, 2.0f);
        Assert::AreEqual(b.y, 3.0f);
        Assert::AreEqual(b.z, 4.0f);
        auto c(a);
        Assert::AreEqual(c.x, 1.0f);
        Assert::AreEqual(c.y, 1.0f);
        Assert::AreEqual(c.z, 1.0f);
        auto d = a;
        Assert::AreEqual(d.x, 1.0f);
        Assert::AreEqual(d.y, 1.0f);
        Assert::AreEqual(d.z, 1.0f);
    }
    TEST_METHOD(NestedConstructor) {
        Vector3<float> a(Vector2<float>(1.0f, 2.0f), 3.0f),
            b(1.0f, Vector2<float>(2.0f, 3.0f));

        // v3(v2,z)
        Assert::AreEqual(a.x, 1.0f);
        Assert::AreEqual(a.y, 2.0f);
        Assert::AreEqual(a.z, 3.0f);
        // v3(x,v2)
        Assert::AreEqual(b.x, 1.0f);
        Assert::AreEqual(b.y, 2.0f);
        Assert::AreEqual(b.z, 3.0f);
    }
    TEST_METHOD(TypeCast) {
        Vector3<float> v1(3.0f, 4.0f, 5.0f);
        Vector2<float> v2 = static_cast<Vector2<float>>(v1); // conversion to Vector2
        Assert::AreEqual(v2.x, 3.0f);
        Assert::AreEqual(v2.y, 4.0f);
        Vector3<int> v3 = static_cast<Vector3<int>>(v1); // conversion to int
        Assert::AreEqual(v3.x, 3);
        Assert::AreEqual(v3.y, 4);
        Assert::AreEqual(v3.z, 5);
        Vector4<float> v4 = static_cast<Vector4<float>>(v1); // conversion to Vector4
        Assert::AreEqual(v4.x, 3.0f);
        Assert::AreEqual(v4.y, 4.0f);
        Assert::AreEqual(v4.z, 5.0f);
        Assert::AreEqual(v4.w, 0.0f); // Default w value
    }
    TEST_METHOD(ArithmeticOperations) {
        Vector3<float> a(1.0f, 2.0f, 3.0f), b(4.0f, 5.0f, 6.0f);
        auto c = a + b;
        Assert::AreEqual(c.x, 5.0f);
        Assert::AreEqual(c.y, 7.0f);
        Assert::AreEqual(c.z, 9.0f);
        c = a - b;
        Assert::AreEqual(c.x, -3.0f);
        Assert::AreEqual(c.y, -3.0f);
        Assert::AreEqual(c.z, -3.0f);
        c = a * b;
        Assert::AreEqual(c.x, 4.0f);
        Assert::AreEqual(c.y, 10.0f);
        Assert::AreEqual(c.z, 18.0f);
        c = a / b;
        Assert::AreEqual(c.x, 1.0f / 4.0f);
        Assert::AreEqual(c.y, 2.0f / 5.0f);
        Assert::AreEqual(c.z, 3.0f / 6.0f);
    }
    TEST_METHOD(ComparisonOperators) {
        Vector3<float> a(1.0f, 2.0f, 3.0f), b(1.0f, 4.0f, 3.0f), c(2.0f, 3.0f, 5.0f);
        Vector3<bool> r = a == b;
        Assert::IsTrue(r.x);
        Assert::IsFalse(r.y);
        Assert::IsTrue(r.z);
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        r = a != c;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = a < c;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = c > b;
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        r = a <= b;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = a >= b;
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        Assert::IsFalse(_or(Vector3<bool>(false)));
    }
    TEST_METHOD(LogicalOperators) {
        Vector3<bool> a(true, false, false), b(true, true, false);
        Vector3<bool> r = a && b;
        Assert::IsTrue(r.x);
        Assert::IsFalse(r.y);
        Assert::IsFalse(r.z);
        Assert::IsFalse(static_cast<bool>(r));
        r = a || b;
        Assert::IsTrue(r.x);
        Assert::IsTrue(r.y);
        Assert::IsFalse(r.z);
        Assert::IsFalse(static_cast<bool>(r));
        r = ~a;
        Assert::IsFalse(r.x);
        Assert::IsTrue(r.y);
        Assert::IsTrue(r.z);
        Assert::IsFalse(static_cast<bool>(r));
    }
    TEST_METHOD(VectorOperations) {
        Vector3<float> a(0.0f, 3.0f, 4.0f), b(2.0f, 6.0f, 7.0f);
        Assert::AreEqual(summation(a), 7.0f);
        Assert::AreEqual(magnitude(a), 5.0f);
        Assert::AreEqual(magnitude2(a), 25.0f);
        auto n = normal(a);
        Assert::AreEqual(n.x, 0.0f);
        Assert::AreEqual(n.y, 3.0f / 5.0f);
        Assert::AreEqual(n.z, 4.0f / 5.0f);
        Assert::AreEqual(dot(a, b), 3.0f * 6.0f + 4.0f * 7.0f);
        n = cross(a, b);
        Assert::AreEqual(n.x, 3.0f * 7.0f - 4.0f * 6.0f);
        Assert::AreEqual(n.y, 4.0f * 2.0f);
        Assert::AreEqual(n.z, -3.0f * 2.0f);
    }
};
TEST_CLASS(Vector4Test) {
public:
    TEST_METHOD(DefaultConstructor) {
        Vector4<float> v{};
        Assert::AreEqual(v.x, 0.0f);
        Assert::AreEqual(v.y, 0.0f);
        Assert::AreEqual(v.z, 0.0f);
        Assert::AreEqual(v.w, 0.0f);
    }
    TEST_METHOD(ConstructorAndAssignment) {
        Vector4<float> a(1.0f), b(2.0f, 3.0f), c(2.0f, 3.0f, 4.0f, 5.0f);
        Assert::AreEqual(a.x, 1.0f);
        Assert::AreEqual(a.y, 1.0f);
        Assert::AreEqual(a.z, 1.0f);
        Assert::AreEqual(a.w, 1.0f);
        Assert::AreEqual(b.x, 2.0f);
        Assert::AreEqual(b.y, 3.0f);
        Assert::AreEqual(b.z, 2.0f);
        Assert::AreEqual(b.w, 3.0f);
        Assert::AreEqual(c.x, 2.0f);
        Assert::AreEqual(c.y, 3.0f);
        Assert::AreEqual(c.z, 4.0f);
        Assert::AreEqual(c.w, 5.0f);
        auto d(a);
        Assert::AreEqual(d.x, 1.0f);
        Assert::AreEqual(d.y, 1.0f);
        Assert::AreEqual(d.z, 1.0f);
        Assert::AreEqual(d.w, 1.0f);
        auto e = a;
        Assert::AreEqual(e.x, 1.0f);
        Assert::AreEqual(e.y, 1.0f);
        Assert::AreEqual(e.z, 1.0f);
        Assert::AreEqual(e.w, 1.0f);
    }
    TEST_METHOD(NestedConstructor) {
        Vector4<float> a(Vector2<float>(1.0f, 2.0f), 3.0f, 4.0f),
            b(1.0f, 2.0f, Vector2<float>(3.0f, 4.0f)),
            c(Vector2<float>(1.0f, 2.0f), Vector2<float>(3.0f, 4.0f)),
            d(1.0f, Vector2<float>(2.0f, 3.0f), 4.0f),
            e(Vector3<float>(1.0f, 2.0f, 3.0f), 4.0f),
            f(1.0f, Vector3<float>(2.0f, 3.0f, 4.0f));
        // v4(v2,z,w)
        Assert::AreEqual(a.x, 1.0f);
        Assert::AreEqual(a.y, 2.0f);
        Assert::AreEqual(a.z, 3.0f);
        Assert::AreEqual(a.w, 4.0f);
        // v4(x,y,v2)
        Assert::AreEqual(b.x, 1.0f);
        Assert::AreEqual(b.y, 2.0f);
        Assert::AreEqual(b.z, 3.0f);
        Assert::AreEqual(b.w, 4.0f);
        // v4(v2,v2)
        Assert::AreEqual(c.x, 1.0f);
        Assert::AreEqual(c.y, 2.0f);
        Assert::AreEqual(c.z, 3.0f);
        Assert::AreEqual(c.w, 4.0f);
        // v4(x,v2,w)
        Assert::AreEqual(d.x, 1.0f);
        Assert::AreEqual(d.y, 2.0f);
        Assert::AreEqual(d.z, 3.0f);
        Assert::AreEqual(d.w, 4.0f);
        // v4(v3,w)
        Assert::AreEqual(e.x, 1.0f);
        Assert::AreEqual(e.y, 2.0f);
        Assert::AreEqual(e.z, 3.0f);
        Assert::AreEqual(e.w, 4.0f);
        // v4(x,v3)
        Assert::AreEqual(f.x, 1.0f);
        Assert::AreEqual(f.y, 2.0f);
        Assert::AreEqual(f.z, 3.0f);
        Assert::AreEqual(f.w, 4.0f);
    }
    TEST_METHOD(TypeCast) {
        Vector4<float> v1(3.0f, 4.0f, 5.0f, 6.0f);
        Vector2<float> v2 = static_cast<Vector2<float>>(v1); // conversion to Vector2
        Assert::AreEqual(v2.x, 3.0f);
        Assert::AreEqual(v2.y, 4.0f);
        Vector3<float> v3 = static_cast<Vector3<float>>(v1); // conversion to Vector3
        Assert::AreEqual(v3.x, 3.0f);
        Assert::AreEqual(v3.y, 4.0f);
        Assert::AreEqual(v3.z, 5.0f);
        Vector4<int> v4 = static_cast<Vector4<int>>(v1); // conversion to int
        Assert::AreEqual(v4.x, 3);
        Assert::AreEqual(v4.y, 4);
        Assert::AreEqual(v4.z, 5);
        Assert::AreEqual(v4.w, 6);
    }
    TEST_METHOD(ArithmeticOperations) {
        Vector4<float> a(1.0f, 2.0f, 3.0f, 4.0f), b(5.0f, 6.0f, 7.0f, 8.0f);
        auto c = a + b;
        Assert::AreEqual(c.x, 6.0f);
        Assert::AreEqual(c.y, 8.0f);
        Assert::AreEqual(c.z, 10.0f);
        Assert::AreEqual(c.w, 12.0f);
        c = a - b;
        Assert::AreEqual(c.x, -4.0f);
        Assert::AreEqual(c.y, -4.0f);
        Assert::AreEqual(c.z, -4.0f);
        Assert::AreEqual(c.w, -4.0f);
        c = a * b;
        Assert::AreEqual(c.x, 5.0f);
        Assert::AreEqual(c.y, 12.0f);
        Assert::AreEqual(c.z, 21.0f);
        Assert::AreEqual(c.w, 32.0f);
        c = a / b;
        Assert::AreEqual(c.x, 1.0f / 5.0f);
        Assert::AreEqual(c.y, 2.0f / 6.0f);
        Assert::AreEqual(c.z, 3.0f / 7.0f);
        Assert::AreEqual(c.w, 4.0f / 8.0f);
    }
    TEST_METHOD(ComparisonOperators) {
        Vector4<float> a(1.0f, 2.0f, 3.0f, 4.0f), b(1.0f, 4.0f, 3.0f, 10.0f), c(2.0f, 3.0f, 5.0f, 7.0f);
        Vector4<bool> r = a == b;
        Assert::IsTrue(r.x);
        Assert::IsFalse(r.y);
        Assert::IsTrue(r.z);
        Assert::IsFalse(r.w);
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        r = a != c;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = a < c;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = c > b;
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        r = a <= b;
        Assert::IsTrue(_and(r));
        Assert::IsTrue(_or(r));
        r = a >= b;
        Assert::IsFalse(_and(r));
        Assert::IsTrue(_or(r));
        Assert::IsFalse(_or(Vector4<bool>(false)));
    }
    TEST_METHOD(LogicalOperators) {
        Vector4<bool> a(true, false, false, true), b(true, true, false, true);
        Vector4<bool> r = a && b;
        Assert::IsTrue(r.x);
        Assert::IsFalse(r.y);
        Assert::IsFalse(r.z);
        Assert::IsTrue(r.w);
        Assert::IsFalse(static_cast<bool>(r));
        r = a || b;
        Assert::IsTrue(r.x);
        Assert::IsTrue(r.y);
        Assert::IsFalse(r.z);
        Assert::IsTrue(r.w);
        Assert::IsFalse(static_cast<bool>(r));
        r = ~a;
        Assert::IsFalse(r.x);
        Assert::IsTrue(r.y);
        Assert::IsTrue(r.z);
        Assert::IsFalse(r.w);
        Assert::IsFalse(static_cast<bool>(r));
    }
    TEST_METHOD(VectorOperations) {
        Vector4<float> a(0.0f, 3.0f, 4.0f, 0.0f), b(2.0f, 6.0f, 7.0f, 4.0f);
        Assert::AreEqual(summation(a), 7.0f);
        Assert::AreEqual(magnitude(a), 5.0f);
        Assert::AreEqual(magnitude2(a), 25.0f);
        auto n = normal(a);
        Assert::AreEqual(n.x, 0.0f);
        Assert::AreEqual(n.y, 3.0f / 5.0f);
        Assert::AreEqual(n.z, 4.0f / 5.0f);
        Assert::AreEqual(n.w, 0.0f);
        Assert::AreEqual(dot(a, b), 3.0f * 6.0f + 4.0f * 7.0f);
    }
};

} // namespace Math

#endif