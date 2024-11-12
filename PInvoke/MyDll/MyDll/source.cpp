#include <cstddef>
#include <cstring>
#include "header.h"

// func01 ����ʵ��
int func01(int a, int b) {
    return a + b;
}

// func01 ����ʵ��
void func02(int c, DataInfo* d, MMCallBack cb) {
    cb(c, d->d);
}

// �����ȡ API �ĺ���
void GetAPI(MMAPIINFO* api) {
    if (api == NULL)
        return;
    memset(api, 0x00, sizeof(MMAPIINFO));
    api->func01 = func01;
    api->func02 = func02;
}