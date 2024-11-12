using System;
using System.Runtime.InteropServices;

namespace ConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // 实例化一个 GetApi 类
            GetApi ss = new GetApi();

            Console.WriteLine(ss.Ffunc01(1, 2));

            GetApi.DataInfo data = new GetApi.DataInfo
            {
                a = 1,
                b = 2,
                c = 'x'
            };
            string str1 = "adbcd";
            data.d = str1;

            ss.Ffunc02(1024, ref data);

            Console.WriteLine("Hello World!");
            Console.ReadKey();
        }
    }

    class GetApi
    {
        // 特性定义了 MMAPIINFO 函数指针结构体的序列化方式和字符集
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        public struct MMAPIINFO
        {
            public IntPtr func01;
            public IntPtr func02;
        }

        // 特性定义了 DataInfo 结构体的序列化方式和字符集
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        public struct DataInfo
        {
            public int a;
            public int b;
            public char c;
            // char* 要使用 MarshalAs
            [MarshalAs(UnmanagedType.LPStr)]
            public string d;
        }


        // 委托函数MMCB的定义用于传入回调函数，对应于 header.h 中的
        // int(MMAPI *MMCallBack)(int handle, char* UserData)
        // 特别注意：C# 回调函数的调用约定必须声明为 CallingConvention.Cdecl
        // 因为 C# 的调用约定是 __stdcall， 如果不指定调用约定，会默认 __stdcall，
        // 不同的调用约定会导致冲突
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void MMCB(int handle, string userData);

        // 定义 MMAPIINFO.func01 的委托函数
        public delegate int Func01(int a, int b);

        // 定义 MMAPIINFO.func02 的委托函数
        public delegate void Func02(int c, ref DataInfo data, MMCB cbMmcb);


        // 封装函数，封装调用 MMAPIINFO.func01
        public int Ffunc01(int aa, int bb)
        {
            Func01 func = (Func01)Marshal.GetDelegateForFunctionPointer(A.func01, typeof(Func01));
            return func(aa, bb);

        }

        // 封装函数，封装调用 MMAPIINFO.func02
        public void Ffunc02(int c, ref DataInfo dat)
        {
            Func02 func = (Func02)Marshal.GetDelegateForFunctionPointer(A.func02, typeof(Func02));
            func(c, ref dat, apiCB);
        }

        // 成员变量 MMAPIINFO A 作为指针结构体
        public static MMAPIINFO A = new MMAPIINFO();


        // 声明 dsp.dll 的导出函数，注意调用约定 __cdecl 和字符集
        [DllImport("MyDll.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern void GetAPI(ref MMAPIINFO param);

        // 构造函数用于从 dsp.dll 中获取api函数结构体
        public GetApi()
        {
            GetAPI(ref A);
        }

        // 实际传入的回调(被委托)函数
        public void apiCB(int handle, string userData)
        {
            Console.WriteLine(handle);
            Console.WriteLine(userData);
        }
    }
}
