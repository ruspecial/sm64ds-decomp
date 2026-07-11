extern void func_ov060_021150d0(char *);
extern void func_ov060_021150c4(char *);

void func_ov060_02115060(char *c) {
    unsigned char t;
    unsigned char v;
    unsigned char w;
    unsigned char *p;
    v = *(unsigned char *)(c + 0x415);
    if (v == 0) {
        w = *(unsigned char *)(c + 0x416);
        if (w == 0) {
            func_ov060_021150d0(c);
        } else {
            func_ov060_021150c4(c);
        }
        p = (unsigned char *)(((long long)(int)(c + 0x415)) & 0xFFFFFFFFFFFFFFFFLL);
        t = *p;
        t += 1;
        *p = t;
        return;
    }
    *(unsigned char *)(c + 0x415) = 0;
    *(int *)(c + 0x40c) = 0xe;
}
