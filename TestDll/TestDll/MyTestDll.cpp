#include "pch.h"
#include "MyTestDll.h"

#include <iostream>

//#ifdef __cplusplus
//extern "C" {
//#endif
//
//    // __cdecl 调用约定的加法函数实现
//    __declspec(dllexport) int __cdecl Add(int a, int b)
//    {
//        return a + b;
//    }
//
//#ifdef __cplusplus
//}
//#endif

#ifdef __cplusplus
extern "C" {
#endif

    // __stdcall 调用约定的加法函数实现
    __declspec(dllexport) int __stdcall Add(int a, int b)
    {
        return a + b;
    }

#ifdef __cplusplus
}
#endif
