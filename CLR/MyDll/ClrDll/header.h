#pragma once

#pragma once
#include <iostream>
#include "../MyDll/header.h"//���ÿ�������Ӧ�ļ�·��

public ref class MyClrClass
{
public:
    MyClrClass();

    int AddCli(int numberA, int numberB);
    int SubtractCli(int numberA, int numberB);
    int MultiplicationCli(int numberA, int numberB);
    int DividedCli(int numberA, int numberB);
};
