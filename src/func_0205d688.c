extern void func_0205cdf4(char *self, int a);
extern int func_0205d3f4(char *self);

int func_0205d688(char *self, int arg1, int arg2, int arg3)
{
    int a3 = arg3;
    int work = arg2;
    int saved28 = *(int*)(self+0x28);
    int avail = *(int*)(self+0x24) - saved28;
    if (work > avail) work = avail;
    *(int*)(self+0x2c) = arg1;
    if (work < 0) work = 0;
    *(int*)(self+0x30) = arg2;
    *(int*)(self+0x34) = work;
    if (a3 == 0) {
        int *p = (int*)(((long long)(int)(self+0xc)) & 0xFFFFFFFFFFFFFFFFLL);
        *p |= 4;
    }
    func_0205cdf4(self, 0);
    if (a3 == 0) {
        if (func_0205d3f4(self) != 0)
            work = *(int*)(self+0x28) - saved28;
        else
            work = -1;
    }
    return work;
}
