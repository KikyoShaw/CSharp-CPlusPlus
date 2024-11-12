#include "header.h"

MyClrClass::MyClrClass()
{
}

int MyClrClass::AddCli(int numberA, int numberB)
{
    return Add(numberA, numberB);
}

int MyClrClass::SubtractCli(int numberA, int numberB)
{
    return Subtract(numberA, numberB);
}

int MyClrClass::MultiplicationCli(int numberA, int numberB)
{
    return Multiplication(numberA, numberB);
}

int MyClrClass::DividedCli(int numberA, int numberB)
{
    return Divided(numberA, numberB);
}
