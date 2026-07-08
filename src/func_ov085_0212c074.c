extern signed char data_0209f2f8;
extern signed char data_02092120;
extern void func_ov085_0212c150(void* self);

int func_ov085_0212c074(char* c)
{
    unsigned int i;
    int* r3;
    char* r1;

    if (*(unsigned char*)(c + 0x428) == 1) return 1;

    {
        int b = (*(int*)(c + 0xb0) & 0x40000) != 0;
        if (b) return 1;
    }

    *(int*)(c + 0x80) = 0x1500;
    *(int*)(c + 0x88) = *(int*)(c + 0x80);
    *(int*)(c + 0x84) = *(int*)(c + 0x88);

    r3 = *(int**)(c + 0x308);
    r1 = *(char**)(c + 0x30c);
    for (i = 0; i < *(unsigned int*)((char*)r3 + 0x24); i++) {
        *(int*)(r1 + 0x20) = *(int*)(c + 0x468);
        r1 += 0x30;
    }

    if (data_0209f2f8 == 5 && data_02092120 == 3) {
        func_ov085_0212c150(c);
    }

    {
        char* obj = c + 0x300;
        char* vp = *(char**)obj;
        (*(void (**)(void*, void*))(vp + 0x14))(obj, c + 0x80);
    }
    return 1;
}
