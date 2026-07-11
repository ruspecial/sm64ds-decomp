typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern int func_020124c4(int a, int b, int c, int d);

void func_ov006_02101224(char* self, int idx)
{
    char* p = self + (idx << 6);
    *(int*)(p + 0x528c) = func_020124c4(*(int*)(p + 0x528c), 2, 0x198, 0);
    if (*(u16*)(p + 0x5292) != 0) {
        *(u16*)(self + 0x5292 + (idx << 6)) -= 1;
        if (*(s16*)(p + 0x5292) < 0) {
            *(s16*)(p + 0x5292) = 0;
        }
    } else {
        if (*(int*)(self + 0x5668) == 3) {
            *(u8*)(p + 0x5296) = 3;
        } else {
            *(u8*)(p + 0x5296) = 2;
        }
    }
}
