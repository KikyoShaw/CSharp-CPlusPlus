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

    // ����һ���ص�
    typedef int(MMAPI* MMCallBack)(int handle, char* UserData);

    // һ���ṹ��
    typedef struct
    {
        int a;
        int b;
        char c;
        char* d;
    }DataInfo;

    // API ����ָ����ɵĽṹ��
    typedef struct
    {
        int (MMAPI* func01)(int a, int b);
        void (MMAPI* func02)(int c, DataInfo* d, MMCallBack cb);
    }MMAPIINFO;

    // ����һ����ȡ API�ĺ��������� API ͨ���ú�����ȡ��ע�⣬MMAPIEXP  ����ָ��WIN�µ�����������
    MMAPIEXP  void  MMAPI GetAPI(MMAPIINFO* api);

#ifdef __cplusplus
}


#endif // __cplusplus

#endif // !HEADER_H

