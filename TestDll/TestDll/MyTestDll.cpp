#include "pch.h"
#include "MyTestDll.h"

#include <iostream>

//#ifdef __cplusplus
//extern "C" {
//#endif
//
//    // __cdecl ����Լ���ļӷ�����ʵ��
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

    // __stdcall ����Լ���ļӷ�����ʵ��
    __declspec(dllexport) int __stdcall Add(int a, int b)
    {
        return a + b;
    }

#ifdef __cplusplus
}
#endif
