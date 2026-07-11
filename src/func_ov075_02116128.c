extern unsigned short *_ZN2G212GetBG1ScrPtrEv(void);
extern int func_02030958(int val);
extern unsigned char data_0209fc50;

void func_ov075_02116128(int unused, int r6, int r5)
{
    int b = data_0209fc50;
    unsigned short *bg = _ZN2G212GetBG1ScrPtrEv();
    int a = func_02030958(r6);
    int t = 4 - b;
    int m = r6 * (t * 0x20 + 0xa0) + (t * 0x40 + 0x84);
    unsigned int hi;
    unsigned int angle;
    int i;
    unsigned short *p;
    p = bg + m;
    angle = (unsigned short)(a + 0xa);
    if (r5 != 0)
        angle = (unsigned short)(angle - 4);
    hi = angle << 0x1c;
    p[0x20] = (unsigned short)((p[0x20] & 0xfff) | (hi >> 16));
    p[0x40] = (unsigned short)((p[0x40] & 0xfff) | (hi >> 16));
    p[0x37] = (unsigned short)((p[0x37] & 0xfff) | (hi >> 16));
    p[0x57] = (unsigned short)((p[0x57] & 0xfff) | (hi >> 16));
    for (i = 0; i < 0x18; i++) {
        p[0] = (unsigned short)((p[0] & 0xfff) | (hi >> 16));
        p[0x60] = (unsigned short)((p[0x60] & 0xfff) | (hi >> 16));
        p++;
    }
}
