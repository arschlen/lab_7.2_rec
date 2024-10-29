#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2_rec/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int row[] = { 3, 5, 2, 8, 7 };
			int expectedMinIndex = 2;
			Assert::AreEqual(expectedMinIndex, FindMinIndex(row, 5));
		}
	};
}
