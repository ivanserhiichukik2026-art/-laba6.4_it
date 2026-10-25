#include "pch.h"
#include "CppUnitTest.h"
#include "../laba6.4.it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int maxAbsIndex(const double a[], int n);
double sumAfterPositive(const double a[], int n);
void rearrange(double a[], int n, int low, int high);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMaxAbs)
        {
            double a[] = { -2.0, 5.0, -9.0, 3.0 };

            Assert::AreEqual(2, maxAbsIndex(a, 4));
        }

        TEST_METHOD(TestSum)
        {
            double a[] = { -3.0, 2.0, 4.0, -1.0, 5.0 };

            Assert::AreEqual(8.0,
                sumAfterPositive(a, 5), 0.000001);
        }

        TEST_METHOD(TestRearrange)
        {
            double a[] = { 5.2, -2.4, 3.7, 1.5, 8.1 };

            rearrange(a, 5, 1, 3);

            Assert::AreEqual(3.7, a[0], 0.000001);
            Assert::AreEqual(1.5, a[1], 0.000001);
            Assert::AreEqual(5.2, a[2], 0.000001);
            Assert::AreEqual(-2.4, a[3], 0.000001);
            Assert::AreEqual(8.1, a[4], 0.000001);
        }
    };
}