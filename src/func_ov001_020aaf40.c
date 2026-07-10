// NONMATCHING: scratch register rotation (div=3). 113/116 instructions byte-identical; the
// only divergence is in the final byte loop where the ldrb value/test temps get r1/r0
// instead of the ROM's r0/r1 (ands r1,r0,#2 vs ands r0,r1,#2 + ldrb/bicne operands).
// No source shape tried (named/fresh/reused vars, expression temps, volatile, identity
// casts, for/do-while, decl order) flips the allocation. Logic verified correct vs ROM.
// Counts as decompiled, not matched.
extern void func_ov001_020aa6b0(void *node, int v);
extern void func_ov001_020aa420(void);
extern int _ZN6Player8HasNoCapEv(char *p);
extern int _ZN6Player15IsCollectingCapEv(char *p);
extern void func_ov001_020aadac(void);
extern void func_ov001_020aaa54(void);

typedef struct SubT SubT;
struct SubT {
    int f00;
    char *f04;
    int f08;
    SubT *f0c;
    SubT *f10;
    int f14;
    unsigned char f18, f19, f1a, f1b;
};

extern unsigned char data_ov001_020ad620;
extern SubT *data_ov001_020ad634[];
extern unsigned char data_0209f284;
extern unsigned char data_0209f2d8;
extern char *data_0209f394[];
extern unsigned char data_ov001_020ad624;
extern unsigned char data_ov001_020ad62c[];

void func_ov001_020aaf40(void)
{
    int slot;
    SubT *t;
    int v;
    int tst;
    int flag;
    char *pl;
    int n;
    unsigned char *p;

    if (data_ov001_020ad620 != 0) {
        data_ov001_020ad620 -= 1;
        for (slot = 0; slot < 3; slot++) {
            for (t = data_ov001_020ad634[slot]; t != 0; t = t->f10) {
                if (t->f14 == -1)
                    continue;
                if (t->f1a == 0)
                    continue;
                *(unsigned char *)(int)(((long long)(int)((char *)t + 0x1a)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
                v = t->f1a;
                if (v == 0) {
                    func_ov001_020aa6b0(t, 1);
                } else if (v % 10 == 0) {
                    func_ov001_020aa6b0(t, ((v / 10) & 1) == 0 ? 1 : 0);
                }
            }
        }
        if (data_ov001_020ad620 == 0)
            data_0209f284 = 0;
    }
    flag = (data_0209f2d8 == 1) ? 1 : 0;
    if ((int)(((long long)flag) & 0xFFFFFFFFFFFFFFFFLL) != 0) {
        func_ov001_020aa420();
        return;
    }
    pl = data_0209f394[0];
    if (_ZN6Player8HasNoCapEv(pl) != 0 && _ZN6Player15IsCollectingCapEv(pl) == 0) {
        func_ov001_020aadac();
        data_ov001_020ad624 = 1;
        return;
    }
    n = 0;
    p = data_ov001_020ad62c;
    do {
        v = *p;
        n++;
        if (v & 2)
            *p = (unsigned char)(v & ~3);
        p++;
    } while (n < 3);
    func_ov001_020aaa54();
    data_ov001_020ad624 = 0;
}
