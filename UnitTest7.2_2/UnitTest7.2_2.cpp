#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2_2/lab_7.2_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest722
{
	TEST_CLASS(UnitTest722)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = main();
			Assert::AreEqual(t, 0);
		}
	};
}
