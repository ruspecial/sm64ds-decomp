extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);
extern void SetSubBg0Offset(int a, int b);
extern int data_ov006_0212ecec[];

void func_ov006_02104a10(char *c, int idx)
{
    int m = idx * 0xc;
    char *base = c + 0x4690;
    unsigned short h = *(unsigned short*)(base + m);
    unsigned short v;
    *(unsigned short*)(base + m) = h + 1;
    v = *(unsigned short*)(base + m);
    if (v >= 0x20) {
        *(short*)(base + m) = 0;
        *(unsigned char*)(c + m + 0x4000 + 0x693) = 2;
        return;
    }
    {
        int t = data_ov006_0212ecec[v >> 3];
        int *dst = (int*)(c + 0x468c + m);
        unsigned short st;
        *dst = t;
        st = *(unsigned short*)(c + m + 0x4600 + 0x90);
        if (st == 1 || st == 0x11) _ZN5Sound12PlayBank2_2DEj(0x1fc);
        SetSubBg0Offset(0, *dst);
    }
}
