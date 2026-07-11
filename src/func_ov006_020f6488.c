extern void func_ov004_020b56c8(int);
extern short data_ov004_020bf9e4;

struct S5300 {
    char pad[0xe2];
    unsigned short timer;   /* 0xe2 */
    char pad2[0xea - 0xe4];
    unsigned short fea;     /* 0xea */
};

void func_ov006_020f6488(char *c)
{
    struct S5300 *s = (struct S5300 *)(c + 0x5300);
    unsigned char *h;
    unsigned short *t;
    if (s->timer != 0) {
        t = (unsigned short *)(int)(((long long)(int)(c + 0x53e2)) & 0xFFFFFFFFFFFFFFFFLL);
        t[0] = t[0] - 1;
        if (s->timer != 0)
            return;
        c += 0x5000;
        if (((unsigned char *)c)[0x405] < s->fea)
            return;
        func_ov004_020b56c8((5 - ((unsigned char *)c)[0x408]) * 5);
        return;
    }
    if (data_ov004_020bf9e4 == 1) {
        s->timer = 0;
        h = (unsigned char *)(c + 0x5000);
        *(int *)(h + 0x3d8) = 2;
    }
}
