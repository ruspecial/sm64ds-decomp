typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern int data_ov006_02140428;

extern void _Z14ApproachLinearRiii(int* r, int target, int step);
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int id);
extern void func_ov006_020c8c78(int a, int b);
extern void func_ov006_020c8768(char* p);

void func_ov006_020c78ec(char* c)
{
    (*(s16*)(int)(((long long)(int)(c + 0x32)) & 0xFFFFFFFFFFFFFFFFLL))--;
    if (*(s16*)(c + 0x32) == 0) {
        _Z14ApproachLinearRiii(&data_ov006_02140428, 0, 1);
        _ZN5Sound12PlayBank2_2DEj(0x130);
        func_ov006_020c8c78(*(s16*)(c + 0x36), 0xc0);
        func_ov006_020c8768(c);
    } else {
        int m = 0x6c000;
        *(int*)(c + 0x20) = (int)((*(int*)(c + 0x20) * 0xc00LL + 0x800) >> 12);
        if (*(int*)(c + 0x14) < -m)
            *(int*)(c + 0x14) = -m;
        else if (*(int*)(c + 0x14) > m)
            *(int*)(c + 0x14) = m;
    }
}
