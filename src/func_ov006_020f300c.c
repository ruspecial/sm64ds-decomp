struct Pmf { int off; int adj; };
typedef void (*PmfFn)(void *, int);

extern struct Pmf data_ov006_02142254[];
extern void func_ov006_020f0044(char *c);
extern void func_ov006_020f10ec(char *c);
extern void func_ov006_020f0274(char *c);
extern void func_ov004_020b0a54(int arg);

void func_ov006_020f300c(char *c)
{
    int i;
    int count;

    func_ov006_020f0044(c);
    func_ov006_020f10ec(c);
    func_ov006_020f0274(c);

    count = 0;
    for (i = 0; i < 0x78; i++) {
        char *base = c + i + 0x5000;
        if (*(unsigned char *)(base + 0x2ed) != 0) {
            unsigned char idx = *(unsigned char *)(base + 0x1fd);
            if (idx == 9) {
                struct Pmf *e = &data_ov006_02142254[idx];
                int adj = e->adj;
                char *thisp = c + (adj >> 1);
                PmfFn fn;
                count++;
                if (adj & 1) {
                    fn = *(PmfFn *)(*(char **)thisp + e->off);
                } else {
                    fn = (PmfFn)e->off;
                }
                fn(thisp, i);
            }
        }
    }
    if (count != 0) return;

    for (i = 0; i < 0x78; i++) {
        char *p = c + i + 0x53dd;
        if (*(unsigned char *)p == 1) *(unsigned char *)p = 0;
    }

    if (*(unsigned short *)(c + 0x516a) == 0) return;
    *(unsigned short *)(c + 0x5164) = 1;
    *(unsigned short *)(((long long)(int)(c + 0x516a)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
    if (*(short *)(c + 0x516a) > 0) return;
    *(unsigned short *)(c + 0x516a) = 0;
    *(unsigned short *)(c + 0x5164) = 0;

    if (*(unsigned char *)(c + 0x5459) != 0) {
        int v = *(int *)(c + 0xbc);
        if (v < 5) {
            char *vp = *(char **)c;
            (*(void (**)(void *, int))(vp + 0x48))(c, -1);
        } else if (v - 5 >= 5) {
            func_ov004_020b0a54(1);
        } else if (v - 5 == 4) {
            func_ov004_020b0a54(0x12);
        } else {
            char *vp = *(char **)c;
            (*(void (**)(void *, int))(vp + 0x48))(c, -1);
        }
    } else {
        *(unsigned char *)(c + 0xc3) = 0;
    }
}
