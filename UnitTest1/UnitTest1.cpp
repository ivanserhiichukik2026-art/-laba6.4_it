#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\qq\source\repos\6.4 it\6.4 it\FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMaxAbs)
        {
            double a[] = { -2.0, 5.0, -9.0, 3.0 };

            Assert::AreEqual(2, Max(a, 4));
        }

        TEST_METHOD(TestSum)
        {
            double a[] = { -3.0, 2.0, 4.0, -1.0, 5.0 };

            Assert::AreEqual(8.0, Sum(a, 5), 0.000001);
        }

        TEST_METHOD(TestRearrange)
        {
            double a[] = { 5.2, -2.4, 3.7, 1.5, 8.1 };

            Change(a, 5, 1, 3);

            Assert::AreEqual(3.7, a[0], 0.000001);
            Assert::AreEqual(1.5, a[1], 0.000001);
            Assert::AreEqual(5.2, a[2], 0.000001);
            Assert::AreEqual(-2.4, a[3], 0.000001);
            Assert::AreEqual(8.1, a[4], 0.000001);
        }
    };
}
