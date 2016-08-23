#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication3/ConsoleApplication3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Разместите здесь код своего теста
			Assert::AreEqual(3.0, Calc("1+2"), 0.01);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: Разместите здесь код своего теста
				
			double actual = 0;
			std::string inputString = "1-3,14+7*(10/9999)-785,977+1.1";
			HandleString(inputString);
			try {
				if (CheckString(inputString)) {
					actual = Calc(inputString);
				}
				else {}
			}
			catch (...) {}

			double	expected = -787.01;
			Assert::AreEqual(expected, actual, 0.01);
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: Разместите здесь код своего теста

			double actual = 0;
			std::string inputString = "(1.1/3-(2,991*7443.1) + 1  + 3) * (3.5/2,11 - 100)";
			HandleString(inputString);
			try {
				if (CheckString(inputString)) {
					actual = Calc(inputString);
				}
				else {}
			}
			catch (...) {}

			double	expected = 2188873.78;
			Assert::AreEqual(expected, actual, 0.01);
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: Разместите здесь код своего теста

			double actual = 0;
			std::string inputString = "(10.5+8)*(12.4/9.3)*(81/5.8) + 1/(0.01*500-20)";
			HandleString(inputString);
			try {
				if (CheckString(inputString)) {
					actual = Calc(inputString);
				}
				else {}
			}
			catch (...) {}

			double	expected = 344.42;
			Assert::AreEqual(expected, actual, 0.1);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: Разместите здесь код своего теста

			double actual = 0;
			std::string inputString = "2+2*2-2/2.2+1,2*222";
			HandleString(inputString);
			try {
				if (CheckString(inputString)) {
					actual = Calc(inputString);
				}
				else {}
			}
			catch (...) {}

			double	expected = 271.49;
			Assert::AreEqual(expected, actual, 0.1);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: Разместите здесь код своего теста

			double actual = 0;
			std::string inputString = "1+(2*(2.5+2.5+(3-2)))-(3/1.5)";
			HandleString(inputString);
			try {
				if (CheckString(inputString)) {
					actual = Calc(inputString);
				}
				else {}
			}
			catch (...) {}

			double	expected = 11.0;
			Assert::AreEqual(expected, actual, 0.1);
		}

	};
}