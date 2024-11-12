#include <cstddef>
#include <cstring>
#include "header.h"

// func01 函数实现
int func01(int a, int b) {
    return a + b;
}

// func01 函数实现
void func02(int c, DataInfo* d, MMCallBack cb) {
    cb(c, d->d);
}

// 定义获取 API 的函数
void GetAPI(MMAPIINFO* api) {
    if (api == NULL)
        return;
    memset(api, 0x00, sizeof(MMAPIINFO));
    api->func01 = func01;
    api->func02 = func02;
}