void func_0204c194(int a, int b)
{
    int sa = (int)(0x1000 << a << 8) >> 0x10;
    int sb = (int)(0x1000 << b << 8) >> 0x10;

    *(volatile int*)0x4000500 = 1;
    *(volatile int*)0x4000488 = 0;
    *(volatile int*)0x4000490 = 0x40003c0;
    *(volatile int*)0x4000488 = (unsigned short)sa;
    *(volatile int*)0x4000490 = 0x4000040;
    *(volatile int*)0x4000488 = (unsigned short)sa | ((unsigned short)sb << 0x10);
    *(volatile int*)0x4000490 = 0x3c000040;
    *(volatile int*)0x4000488 = (unsigned short)sb << 0x10;
    *(volatile int*)0x4000490 = 0x3c0003c0;
    *(volatile int*)0x4000504 = 0;
}
