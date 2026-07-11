static inline void clearflags(char *p) {
    p[0x15c] = 0;
    p[0x15e] = 0;
}

void func_ov002_020f340c(char *o, int i) {
    int idx = i * 0x30;
    int *fld = (int *)(o + 0x144 + idx);
    int v;
    int a, b, c, w;
    char *p;
    *fld += 0x1800;
    v = *fld;
    if (v >= 0x66000) {
        v = 0x66000;
        *fld = v;
        clearflags(o + idx);
    }
    p = o + idx;
    a = *(int *)(p + 0x140) >> 0xc;
    b = *(int *)(p + 0x148) >> 0xc;
    c = *(int *)(p + 0x14c) >> 0xc;
    w = *fld >> 0xc;
    *(volatile unsigned short *)0x4001042 = (unsigned short)(((a << 8) & 0xff00) | (b & 0xff));
    *(volatile unsigned short *)0x4001046 = (unsigned short)(((w << 8) & 0xff00) | (c & 0xff));
}
