#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/yanmi/source/repos/SmartPtr/SmartPtr/SmartPtr/SingleList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSmartPtr
{
	TEST_CLASS(TestSmartPtr)
	{
	public:

		TEST_METHOD(ValidDataLIsts)
		{
			SingleList<int> listone;
			listone.pushFront(0);
			SingleList<int> listtwo;
			listtwo.pushFront(0);
			Assert::IsTrue(listone.toString() == listtwo.toString());
		}

		TEST_METHOD(ValidDataLIst)
		{
			SingleList<int> listone;
			listone.pushFront(0);
			Assert::IsFalse(listone.toString() == "1");
		}

	};
}
