using System;
using System.Runtime.InteropServices;

namespace ConsoleTestDll
{
    internal class Program
    {
        // 导入 DLL 的加法函数
        [DllImport("TestDll.dll")]
        public static extern int Add(int a, int b);

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int a = 100;
            int b = 200;
            int num = Add(a, b);
            Console.WriteLine("num = {0}", num);
            Console.ReadKey();
        }
    }
}
