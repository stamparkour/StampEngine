#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/math/matrix.h>
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_MATH_NAMESPACE;

namespace Math {

TEST_CLASS(MatrixTest) {
public:
    TEST_METHOD(DefaultConstructor) {
        Matrix<float, 2, 2> m{};
        Assert::AreEqual(m.m[0][0], 0.0f);
        Assert::AreEqual(m.m[0][1], 0.0f);
        Assert::AreEqual(m.m[1][0], 0.0f);
        Assert::AreEqual(m.m[1][1], 0.0f);
    }

    TEST_METHOD(ConstructorAndAssignmentr) {
        Matrix<float, 2, 2> m{ 0.0f, 1.0f, 2.0f, 3.0f };
        Assert::AreEqual(m.m[0][0], 0.0f);
        Assert::AreEqual(m.m[0][1], 1.0f);
        Assert::AreEqual(m.m[1][0], 2.0f);
        Assert::AreEqual(m.m[1][1], 3.0f);

        auto m2{ m };
        Assert::AreEqual(m2.m[0][0], 0.0f);
        Assert::AreEqual(m2.m[0][1], 1.0f);
        Assert::AreEqual(m2.m[1][0], 2.0f);
        Assert::AreEqual(m2.m[1][1], 3.0f);

    }
};

} // namespace Math

#endif