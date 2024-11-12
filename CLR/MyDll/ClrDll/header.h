#pragma once

#pragma once
#include <iostream>
#include "../MyDll/header.h"//引用库声明对应文件路径

public ref class MyClrClass
{
public:
    MyClrClass();

    int AddCli(int numberA, int numberB);
    int SubtractCli(int numberA, int numberB);
    int MultiplicationCli(int numberA, int numberB);
    int DividedCli(int numberA, int numberB);
};
