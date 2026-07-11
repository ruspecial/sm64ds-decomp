typedef unsigned char u8;
typedef unsigned short u16;

extern unsigned func_02054de8(void);
extern void MultiStore16(u16 val, char *dst, int nbytes);

void func_ov006_02102718(char *p)
{
    volatile u16 v;
    char *q = p + 0x5000;
    int count = *(u8*)(q + 0x676);
    int x, y, ix, iy;
    char *dst;
    if (count == 0) return;
    p = p + (count - 1) * 0x40 + 0x4000;
    x = *(int*)(p + 0x660);
    y = *(int*)(p + 0x664);
    ix = 0x80 - (x >> 12);
    iy = 0x20 - (y >> 12);
    if (ix < -6) return;
    if (ix > 6) return;
    if (iy < -6) return;
    if (iy > 6) return;
    if (*(u8*)(p + 0x699) != 2) return;
    *(u8*)(q + 0x676) = 0;
    dst = (char*)func_02054de8();
    v = 0;
    MultiStore16(v, dst, 0x6000);
}
