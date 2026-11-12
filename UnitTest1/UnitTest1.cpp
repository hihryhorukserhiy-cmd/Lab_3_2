#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_03_2/MenuWindow.h"
#include "../lab_03_2/MenuWindow.cpp"
#include "../lab_03_2/Window.h"
#include "../lab_03_2/Window.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Window w(10, 20, 800, 600, "Red");
			Assert::AreEqual(10, w.GetX1());
			Assert::AreEqual(20, w.GetY1());
			Assert::AreEqual(800, w.GetX2());
			Assert::AreEqual(600, w.GetY2());
			Assert::AreEqual(string("Red"), w.GetBgColor());
		
		}
	};
}
