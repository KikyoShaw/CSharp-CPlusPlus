#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#ifdef MYCLASS_EXPORTS
#define MYCLASS_EXPORTS __declspec(dllexport)
#else
#define MYCLASS_EXPORTS __declspec(dllimport)
#endif

extern "C" MYCLASS_EXPORTS int Add(int numberA, int numberB);

extern "C" MYCLASS_EXPORTS int Subtract(int numberA, int numberB);

extern "C" MYCLASS_EXPORTS int Multiplication(int numberA, int numberB);

extern "C" MYCLASS_EXPORTS  int Divided(int numberA, int numberB);

class MyClass
{

public:
    MyClass();
    ~MyClass();

};

#endif // !HEADER_H

