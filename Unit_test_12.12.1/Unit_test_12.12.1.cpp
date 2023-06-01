#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.12.1/Lab_12.12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittest12121
{
	TEST_CLASS(Unittest12121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Zodiac* head = nullptr;

            Zodiac* newNode = createNode();
            newNode->surname = "Doe";
            newNode->name = "John";
            newNode->zodiacSign = "Leo";
            newNode->birthday[0] = 25;
            newNode->birthday[1] = 7;
            newNode->birthday[2] = 1990;

            insertNode(head);

            
            Assert::IsNotNull(head);
            Assert::AreEqual(std::string("Doe"), head->surname);
            Assert::AreEqual(std::string("John"), head->name);
            delete head;
		}
	};
}
