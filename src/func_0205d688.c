extern void func_0205cdf4(char *self, int a);
extern int func_0205d3f4(char *self);

int func_0205d688(char *self, int arg1, int arg2, int arg3)
{
    int saved28 = *(int*)(self+0x28);
    int r6 = arg2;
    int avail = *(int*)(self+0x24) - saved28;
    if (r6 > avail) r6 = avail;
    *(int*)(self+0x2c) = arg1;
    if (r6 < 0) r6 = 0;
    *(int*)(self+0x30) = arg2;
    *(int*)(self+0x34) = r6;
    if (arg3 == 0)
        *(int*)(self+0xc) |= 4;
    func_0205cdf4(self, 0);
    if (arg3 == 0) {
        if (func_0205d3f4(self) != 0)
            r6 = *(int*)(self+0x28) - saved28;
        else
            r6 = -1;
    }
    return r6;
}
