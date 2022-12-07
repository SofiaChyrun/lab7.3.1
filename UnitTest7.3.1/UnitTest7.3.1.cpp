#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab7.3.1/ChyrunSofialab7.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest731
{
	TEST_CLASS(UnitTest731)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int l = 6, n = 1;
		    int** a = new int* [l];
			for (int i = 0; i < l; i++)
				a[i] = new int[n];
			for (int i = 0; i < l; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = i + j;
			t = Part1_Count(a, l, n);
			Assert::AreEqual(t, 1);
		}
	};
}
