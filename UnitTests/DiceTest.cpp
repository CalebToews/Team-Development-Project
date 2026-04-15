#include "pch.h"
#include "CppUnitTest.h"
#include "../Dice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiceTests
{
	TEST_CLASS(DiceTests)
	{
	public:
		TEST_METHOD(D5test)
		{
			Dice d5(5);
			for (int i = 0; i < 100; ++i) {
				int result = d5.role();
				Assert::IsTrue(result >= 1 && result <= 5, L"inclusiveRand returned a value outside the specified range.");
			}
		}
	};
}