#include "header.h"

//#define MYCLASS_EXPORTS __declspec(dllexport)

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

MYCLASS_EXPORTS int Add(int numberA, int numberB)
{
	return numberA + numberB;
}

MYCLASS_EXPORTS int Subtract(int numberA, int numberB)
{
	return numberA - numberB;
}

MYCLASS_EXPORTS int Multiplication(int numberA, int numberB)
{
	return numberA * numberB;
}

MYCLASS_EXPORTS int Divided(int numberA, int numberB)
{
	if (numberB == 0) {
		std::cout << "除数不能为空" << std::endl;
	}
	return numberA / numberB;
}