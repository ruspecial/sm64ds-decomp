typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_ov006_0212231c(void* c);
extern void _ZN3G3X6SetFogEbiii(int a, int b, int c, int d);
extern void InitialiseVramGlobals(void);
extern int _ZN4cstd4fdivEii(int a, int b);
extern void func_ov006_020c0134(void* self);
extern int func_ov006_020cd658(u8* a0, int a1);
extern void func_ov006_02120d8c(void* a, int b);
extern void func_ov006_020d0b2c(void);
extern void func_ov004_020b04d0(int v);

extern u8 data_0209d45c;
extern short data_02082414;

int func_ov006_02122198(char* c)
{
    int q;

    *(int*)(c + 0x5d94) = 0x20;
    *(int*)(c + 0x5d98) = *(int*)(c + 0x5d94);
    func_ov006_0212231c(c);

    data_0209d45c = 0x1d;
    _ZN3G3X6SetFogEbiii(0, 0, 2, 0x1000);

    *(volatile u16*)0x4000060 = (*(volatile u16*)0x4000060 & ~0x3000) | 8;
    InitialiseVramGlobals();

    *(volatile u16*)0x4000008 = (*(volatile u16*)0x4000008 & ~3) | 1;
    q = _ZN4cstd4fdivEii(0xc0000, data_02082414);

    *(int*)(c + 0x470c) = 0;
    *(int*)(c + 0x4710) = -0x64000;
    *(int*)(c + 0x4714) = 0;
    *(int*)(c + 0x4718) = 0;
    *(int*)(c + 0x471c) = 0;
    *(int*)(c + 0x4720) = q;
    *(u16*)(c + 0x4724) = 0x400;
    func_ov006_020c0134((void*)(c + 0x466c));

    *(int*)(c + 0x47c8) = 0;
    *(int*)(c + 0x47cc) = 0x82000;
    *(int*)(c + 0x47d0) = 0;
    *(int*)(c + 0x47d4) = 0;
    *(int*)(c + 0x47d8) = 0;
    *(int*)(c + 0x47dc) = q;
    *(u16*)(c + 0x47e0) = 0x400;
    func_ov006_020c0134((void*)(c + 0x4728));

    if (func_ov006_020cd658((u8*)(c + 0x500c), 4) == 0)
        return 0;

    func_ov006_02120d8c((void*)(c + 0x5cd0), 5);
    func_ov006_020d0b2c();
    func_ov004_020b04d0(0x10);
    ((void (**)(char*, int))(*(int*)c))[0x12](c, -1);
    return 1;
}
