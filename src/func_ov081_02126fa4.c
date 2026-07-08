typedef unsigned int u32;

enum { false, true };

extern void func_ov081_0212777c(char* c, int a);
extern void func_ov081_021265c8(void* c);

int func_ov081_02126fa4(char* c)
{
    int b;

    b = (*(u32*)(c + 0xb0) & 0x40000) != 0;
    if (b != false) {
        int* src = (int*)(((long long)(int)(*(char**)(c + 0xd0) + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
        *(int*)(c + 0x5c) = src[0];
        *(int*)(c + 0x60) = src[1];
        *(int*)(c + 0x64) = src[2];
    }

    b = (*(u32*)(c + 0xb0) & 0x80000) != 0;
    if (b != false) {
        func_ov081_0212777c(c, 7);
    } else {
        b = (*(u32*)(c + 0xb0) & 0x20000) != 0;
        if (b == false) {
            b = (*(u32*)(c + 0xb0) & 0x40000) != 0;
            if (b == false) {
                func_ov081_021265c8(c);
            }
        }
    }
    return 1;
}
