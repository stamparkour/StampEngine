#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/math/quaternion.h>
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_MATH_NAMESPACE;

namespace Math {

	TEST_CLASS(QuaternionTest) {
public:
	TEST_METHOD(DefaultConstructor) {
		Quaternion<float> q{};

		Assert::AreEqual(q.x, 0.0f);
		Assert::AreEqual(q.i, 0.0f);
		Assert::AreEqual(q.j, 0.0f);
		Assert::AreEqual(q.k, 0.0f);
	}

	TEST_METHOD(ConstructorAndAssignment) {
		Quaternion<float> a{ 1.0f }, b{ 2.0f, 3.0f, 4.0f, 5.0f };
		Assert::AreEqual(a.x, 1.0f);
		Assert::AreEqual(a.i, 0.0f);
		Assert::AreEqual(a.j, 0.0f);
		Assert::AreEqual(a.k, 0.0f);
		Assert::AreEqual(b.x, 2.0f);
		Assert::AreEqual(b.i, 3.0f);
		Assert::AreEqual(b.j, 4.0f);
		Assert::AreEqual(b.k, 5.0f);
		auto c = b;
		Assert::AreEqual(c.x, 2.0f);
		Assert::AreEqual(c.i, 3.0f);
		Assert::AreEqual(c.j, 4.0f);
		Assert::AreEqual(c.k, 5.0f);
	}

	TEST_METHOD(NestedConstructor) {
		Quaternion<float> a{ 2.0f, Vector3f{3.0f, 4.0f, 5.0f} };
		Assert::AreEqual(a.x, 2.0f);
		Assert::AreEqual(a.i, 3.0f);
		Assert::AreEqual(a.j, 4.0f);
		Assert::AreEqual(a.k, 5.0f);
	}

	TEST_METHOD(TypeCast) {
		Quaternion<float> a{ 1.0f, 2.0f, 3.0f, 4.0f };
		auto b = (float)a;
		Assert::AreEqual(b, 1.0f);
	}

	TEST_METHOD(ArithmeticOperations) {
		Quaternion<float> a{ 1.0f, 2.0f, 3.0f, 4.0f },
			b{ 5.0f, 6.0f, 7.0f, 8.0f };
		auto c = a + b;
		Assert::AreEqual(c.x, 6.0f);
		Assert::AreEqual(c.i, 8.0f);
		Assert::AreEqual(c.j, 10.0f);
		Assert::AreEqual(c.k, 12.0f);
		c = a - b;
		Assert::AreEqual(c.x, -4.0f);
		Assert::AreEqual(c.i, -4.0f);
		Assert::AreEqual(c.j, -4.0f);
		Assert::AreEqual(c.k, -4.0f);
		c = a * b;
		Assert::AreEqual(c.x, 1.0f * 5 - 2 * 6 - 3 * 7 - 4 * 8);
		Assert::AreEqual(c.i, 1.0f * 6 + 2 * 5 + 3 * 8 - 4 * 7);
		Assert::AreEqual(c.j, 1.0f * 7 - 2 * 8 + 3 * 5 + 4 * 6);
		Assert::AreEqual(c.k, 1.0f * 8 + 2 * 7 - 3 * 6 + 4 * 5);
		c = 1.0f / a;
		Assert::AreEqual(c.x, 1.0f / 30, FLT_EPSILON);
		Assert::AreEqual(c.i, -2.0f / 30, FLT_EPSILON);
		Assert::AreEqual(c.j, -3.0f / 30, FLT_EPSILON);
		Assert::AreEqual(c.k, -4.0f / 30, FLT_EPSILON);
	}

	TEST_METHOD(QuaternionOperations) {
		Quaternion<float> a{ 1.0f, 2.0f, 3.0f, 4.0f };
		auto c = unit(a);
		Assert::AreEqual(c.x, 1.0f / sqrt(30.0f), FLT_EPSILON);
		Assert::AreEqual(c.i, 2.0f / sqrt(30.0f), FLT_EPSILON);
		Assert::AreEqual(c.j, 3.0f / sqrt(30.0f), FLT_EPSILON);
		Assert::AreEqual(c.k, 4.0f / sqrt(30.0f), FLT_EPSILON);
	}
};

} // namespace Math

#endif