#ifndef HEADER_H
#define HEADER_H

#ifdef __cplusplus

extern "C" {

#endif // __cplusplus

#if (defined _WIN32) || (defined _WINDOWS) || (defined WIN32)
#ifdef MM_EXPORTS
#define MMAPIEXP __declspec(dllexport)
#else
#define MMAPIEXP __declspec(dllimport)
#endif
#define MMAPI __cdecl
#else
#define MMAPIEXP
#define MMAPI
#endif

    // 定义一个回调
    typedef int(MMAPI* MMCallBack)(int handle, char* UserData);

    // 一个结构体
    typedef struct
    {
        int a;
        int b;
        char c;
        char* d;
    }DataInfo;

    // API 函数指针组成的结构体
    typedef struct
    {
        int (MMAPI* func01)(int a, int b);
        void (MMAPI* func02)(int c, DataInfo* d, MMCallBack cb);
    }MMAPIINFO;

    // 定义一个获取 API的函数，所有 API 通过该函数获取，注意，MMAPIEXP  用于指定WIN下导出函数名称
    MMAPIEXP  void  MMAPI GetAPI(MMAPIINFO* api);

#ifdef __cplusplus
}


#endif // __cplusplus

#endif // !HEADER_H

