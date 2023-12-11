#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_6.4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestProductOfEvenIndexElements)
        {
			int arr[] = { 1, 2, 3, 4, 5, 6 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int result = productOfEvenIndexElements(arr, size);
			Assert::AreEqual(48, result);
        }
	};
}
