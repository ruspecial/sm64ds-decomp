extern void MultiStore32Bytes(unsigned val, int *dst, int len);
extern void _ZN4CP1527FlushAndInvalidateDataCacheEjj(unsigned int a, unsigned int b);
extern void func_02058200(void *a, void *fn, int c, void *d, int e, int f);
extern void func_02058048(void *a);
extern void func_0205ba64(int a, void *fn);

extern void func_020602bc(void);
extern void func_02060310(void);

extern int data_020a8180[];
extern int data_020a8160[];
extern int data_020a81bc;
extern int data_020a8760;

void func_0206002c(void)
{
    volatile int local;

    *(volatile int *)((char *)data_020a8180 + 8) = ~2;
    *(volatile int *)((char *)data_020a8180 + 0xc) = 0;
    local = 0;
    data_020a8180[5] = 0;
    data_020a8180[0] = (int)data_020a8160;
    MultiStore32Bytes(local, data_020a8160, 0x20);

    _ZN4CP1527FlushAndInvalidateDataCacheEjj((unsigned int)data_020a8160, 0x20);

    *(short *)((char *)data_020a8180 + 0x10) = 0;
    *(short *)((char *)data_020a8180 + 0xd4) = 0;
    data_020a8180[0xe] = 4;

    func_02058200(&data_020a81bc, (void *)func_020602bc, 0, &data_020a8760, 0x400,
                  *(volatile int *)((char *)data_020a8180 + 0x38));
    func_02058048(&data_020a81bc);
    func_0205ba64(0xb, (void *)func_02060310);
}
