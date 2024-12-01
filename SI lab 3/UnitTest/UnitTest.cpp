#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\kravc\source\repos\SI lab 3\SI lab 3\FileName.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(calcY_Tests)
	{
	public:
		TEST_METHOD(calculate_get4and7_minus29returned)
		{
			int n = 4;
			int x = 7;
			int expected = -29;
			int actual = calcY(n, x);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculate_get15and6_minus170returned)
		{
			int n = 15;
			int x = 6;
			int expected = -170;
			int actual = calcY(n, x);

			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams_get10_exceptionNotThrown)
		{
			int n = 10;
			double a = 5;
			double b = 7;
			double h = 1;
			try
			{
				checkValidParams(a, b , h, n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(checkValidParams_getMinus10_exceptionThrown)
		{
			int n = -10;
			double a = 5;
			double b = 7;
			double h = 1;
			try
			{
				checkValidParams(a, b , h, n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}
