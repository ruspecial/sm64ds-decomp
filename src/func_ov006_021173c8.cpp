//cpp

#pragma opt_common_subs off
#pragma opt_strength_reduction off

struct DispObj {
    virtual void f0();
    virtual void f1();
};

extern "C" {
void func_02018f8c(void *p, int a);
void func_ov004_020afdd0(int a0, int a1, int a2, int a3, int a4);
void func_ov004_020b1ea4(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
int func_ov004_020ad674(void);
int func_ov004_020adbc0(void);
int func_ov004_020adc1c(void);
void func_ov004_020b1a5c(int a0, int a1);
int func_ov004_020b19f0(void *self);
void func_ov004_020b0d8c(void *c, int a1, int a2);
void func_ov006_02114b10(void *self);
void func_ov006_02113c14(void *self);

extern int data_ov006_02138ae0[];
extern char *data_ov006_0213ecb8[];
extern int data_ov006_0212edfc[];
extern int data_ov006_0213765c[];
extern int data_ov006_02137a78[];
extern int data_ov006_02137a6c[];
extern int data_ov006_021382e0[];
extern int data_ov006_02138bd0[];
extern int data_ov006_02138bf4[];
extern int data_ov006_02137a0c[];
extern int data_ov006_02137a60[];
extern int data_ov006_02138a40[];
extern int data_ov006_02138a88[];
}

#define I(off) (*(int *)(g + (off)))
#define UC(off) (*(unsigned char *)(g + (off)))

extern "C" int func_ov006_021173c8(void *this_)
{
    char *g = (char *)this_;
    int col;
    int xpos;
    int r7;
    int limit;
    int i;

    func_02018f8c(*(void **)(g + 0x5998), 0);
    col = 0;

    if (I(0x4660) == 1 && I(0x5998) <= 0) {
        xpos = 0x18;

        /* Block B: row 0 */
        if (I(0x5964) > 0) {
            func_ov004_020afdd0(data_ov006_02138ae0[0], 0x30, xpos, -1, -1);
            func_ov004_020b1ea4(0x80, xpos, 0x64, 0, 0, 1, 0);
            i = func_ov004_020ad674();
            func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
            func_ov004_020b1ea4(0xa0, xpos, I(0x5964), 0, 0, 1, 0);
            func_ov004_020b1ea4(0xe0, xpos, I(0x5964) * 0x64, 0, 0, 1, 0);
            xpos += 0x18;
            col++;
        }

        /* Loop C: rows 1..4 */
        limit = col * 0x14;
        for (r7 = 0; r7 < 4; r7++) {
            if (I(0x5960) >= limit && I(r7 * 4 + 0x5968) > 0) {
                func_ov004_020afdd0(data_ov006_02138ae0[r7 + 1], 0x30, xpos, -1, -1);
                func_ov004_020b1ea4(0x80, xpos, data_ov006_0212edfc[r7], 0, 0, 1, 0);
                i = func_ov004_020ad674();
                func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
                func_ov004_020b1ea4(0xa0, xpos, I(r7 * 4 + 0x5968), 0, 0, 0, 0);
                func_ov004_020b1ea4(0xe0, xpos, data_ov006_0212edfc[r7] * I(r7 * 4 + 0x5968), 0, 0, 1, 0);
                xpos += 0x18;
                limit += 0x14;
                col++;
            }
        }

        /* Block D */
        if (I(0x597c) > 0 && I(0x5960) >= col * 0x14) {
            func_ov004_020afdd0(data_ov006_0213765c[0], 0x30, xpos, -1, -1);
            func_ov004_020b1ea4(0x80, xpos, 0x12c, 0, 0, 1, 0);
            i = func_ov004_020ad674();
            func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
            func_ov004_020b1ea4(0xa0, xpos, I(0x597c), 0, 0, 0, 0);
            func_ov004_020b1ea4(0xe0, xpos, I(0x597c) * 0x12c, 0, 0, 1, 0);
            xpos += 0x18;
            col++;
        }

        /* Block E */
        if (I(0x5984) > 0 && I(0x5960) >= col * 0x14) {
            func_ov004_020afdd0(data_ov006_02137a78[0], 0x30, xpos, -1, -1);
            func_ov004_020b1ea4(0x80, xpos, 0xbb8, 0, 0, 1, 0);
            i = func_ov004_020ad674();
            func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
            func_ov004_020b1ea4(0xa0, xpos, I(0x5984), 0, 0, 0, 0);
            func_ov004_020b1ea4(0xe0, xpos, I(0x5984) * 0xbb8, 0, 0, 1, 0);
            xpos += 0x18;
            col++;
        }

        /* Block F */
        if (I(0x5980) > 0 && I(0x5960) >= col * 0x14) {
            func_ov004_020afdd0(data_ov006_02137a6c[0], 0x30, xpos, -1, -1);
            func_ov004_020b1ea4(0x80, xpos, 0x7d0, 0, 0, 1, 0);
            i = func_ov004_020ad674();
            func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
            func_ov004_020b1ea4(0xa0, xpos, I(0x5980), 0, 0, 0, 0);
            func_ov004_020b1ea4(0xe0, xpos, I(0x5980) * 0x7d0, 0, 0, 1, 0);
            xpos += 0x18;
            col++;
        }

        /* Loop G: rows with per-row multiplier */
        limit = col * 0x14;
        for (r7 = 0; r7 < 3; r7++) {
            if (I(r7 * 4 + 0x5988) > 0 && I(0x5960) >= limit) {
                int mult;
                switch (r7) {
                case 0:
                    func_ov004_020afdd0(data_ov006_02137a0c[1], 0x20, xpos, -1, -1);
                    func_ov004_020afdd0(data_ov006_02137a0c[1], 0x30, xpos, -1, -1);
                    func_ov004_020afdd0(data_ov006_02137a0c[1], 0x40, xpos, -1, -1);
                    mult = 5000;
                    break;
                case 1:
                    func_ov004_020afdd0(data_ov006_02137a0c[0], 0x20, xpos, -1, -1);
                    func_ov004_020afdd0(data_ov006_02137a0c[0], 0x30, xpos, -1, -1);
                    func_ov004_020afdd0(data_ov006_02137a0c[0], 0x40, xpos, -1, -1);
                    mult = 8000;
                    break;
                case 2:
                    func_ov004_020afdd0(data_ov006_02137a0c[2], 0x20, xpos, -1, -1);
                    func_ov004_020afdd0(data_ov006_02137a0c[2], 0x30, xpos, -1, -1);
                    func_ov004_020afdd0(data_ov006_02137a0c[2], 0x40, xpos, -1, -1);
                    mult = 10000;
                    break;
                }
                func_ov004_020b1ea4(0x80, xpos, mult, 0, 0, 1, 0);
                i = func_ov004_020ad674();
                func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
                func_ov004_020b1ea4(0xa0, xpos, I(r7 * 4 + 0x5988), 0, 0, 0, 0);
                func_ov004_020b1ea4(0xe0, xpos, mult * I(r7 * 4 + 0x5988), 0, 0, 1, 0);
                xpos += 0x18;
                limit += 0x14;
                col++;
            }
        }

        /* Block H */
        if (I(0x5978) > 0 && I(0x5960) >= col * 0x14) {
            func_ov004_020afdd0(data_ov006_02138ae0[5], 0x30, xpos, -1, -1);
            func_ov004_020b1ea4(0x80, xpos, 0x2710, 0, 0, 1, 0);
            i = func_ov004_020ad674();
            func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
            func_ov004_020b1ea4(0xa0, xpos, I(0x5978), 0, 0, 0, 0);
            func_ov004_020b1ea4(0xe0, xpos, I(0x5978) * 0x2710, 0, 0, 1, 0);
            xpos += 0x18;
            col++;
        }

        /* Block I */
        if (I(0x5994) > 0 && I(0x5960) >= col * 0x14) {
            func_ov004_020afdd0(data_ov006_021382e0[0], 0x30, xpos, -1, -1);
            func_ov004_020b1ea4(0x80, xpos, 0x7d0, 0, 0, 1, 0);
            i = func_ov004_020ad674();
            func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54), 0x90, xpos, -1, -1);
            func_ov004_020b1ea4(0xa0, xpos, I(0x5994), 0, 0, 0, 0);
            func_ov004_020b1ea4(0xe0, xpos, I(0x5994) * 0x7d0, 0, 0, 1, 0);
            xpos += 0x18;
            col++;
        }

        /* Block J: timer */
        if (I(0x5960) >= col * 0x14) {
            if ((I(8) & 0xff) == 0)
                func_ov004_020afdd0(data_ov006_02138bd0[0], 0x40, xpos, -1, -1);
            else
                func_ov004_020afdd0(data_ov006_02138bf4[0], 0x40, xpos, -1, -1);
            func_ov004_020b1ea4(0xe0, xpos, func_ov004_020adbc0(), 0, 0, 1, 0);
            col++;
            if (I(0x5960) < 0x118)
                I(0x5960) = 0x118;
        }

        /* Block K */
        if (I(0x4660) == 1 && I(0x5960) >= 0x12c) {
            if (col >= 7)
                func_ov004_020b0d8c(g, 0x80, 0xa8);
            else if (col == 6)
                func_ov004_020b0d8c(g, 0xe0, 0xa8);
            else
                func_ov004_020b0d8c(g, 0xe0, 0xa0);
        }
    }

    /* merge */
    if ((I(8) & 0xff) != 0 || UC(0x595c) == 0)
        func_ov006_02114b10(g);

    /* Section 2 */
    func_ov004_020b1a5c(func_ov004_020adbc0(), 6);
    func_ov004_020b19f0((void *)func_ov004_020adc1c());

    /* Loop 2: item list (sb reused as index) */
    {
        int sb;
        for (sb = 0; sb < 5; sb++) {
            int cnt = I(sb * 4 + 0x478c);
            if (cnt > 0) {
                int mode = I(sb * 4 + 0x47a0);
                if (mode >= 2) {
                    int x = I(sb * 8 + 0x47c8);
                    int y = I(sb * 8 + 0x47cc);
                    unsigned int u;
                    int nd;
                    func_ov004_020b1ea4((x >> 12) - 0x10, y >> 12, cnt, -1, 0, 0, 0);
                    nd = 0;
                    u = (unsigned int)cnt;
                    if (u != 0) {
                        do {
                            u /= 10;
                            nd++;
                        } while (u != 0);
                    }
                    i = func_ov004_020ad674();
                    func_ov004_020afdd0(*(int *)(data_ov006_0213ecb8[i] + 0x54),
                                        (x >> 12) + nd * 8 - 8, y >> 12, -1, -1);
                    nd = 0;
                    u = (unsigned int)cnt;
                    if (u != 0) {
                        do {
                            u /= 10;
                            nd++;
                        } while (u != 0);
                    }
                    func_ov004_020b1ea4((x >> 12) + nd * 8 + 8, y >> 12, mode, -1, 0, 0, 0);
                } else {
                    int x = I(sb * 8 + 0x47c8);
                    int y = I(sb * 8 + 0x47cc);
                    func_ov004_020b1ea4(x >> 12, y >> 12, cnt, -1, 0, 0, 0);
                }
            }
        }
    }

    /* Loop 3: 16 slots */
    {
        int r4;
        for (r4 = 0; r4 < 0x10; r4++) {
            if (UC(r4 + 0x4804) == 1) {
                int idx = I(r4 * 4 + 0x4814) / 5;
                if (idx > 3)
                    idx = 2;
                func_ov004_020afdd0(data_ov006_02137a60[idx], I(r4 * 8 + 0x4854) >> 12,
                                    I(r4 * 8 + 0x4858) >> 12, -1, 0);
            }
        }
    }

    /* Block M */
    {
        int v = I(0x5958);
        int flag = 0;
        if (v > 0) {
            if (v % 30 > 0xf)
                flag = 1;
        } else {
            if (I(0x4784) > 0)
                flag = 1;
        }
        if ((I(8) & 0xff) == 0)
            func_ov004_020afdd0(data_ov006_02138a40[flag], 0x18, -0x90, -1, 0);
        else
            func_ov004_020afdd0(data_ov006_02138a88[flag], 0x18, -0x90, -1, 0);
    }

    /* Block N */
    {
        int v = I(0x5958);
        int flag = 0;
        if (v > 0) {
            if (v % 30 > 0xf)
                flag = 1;
        } else {
            if (I(0x4788) > 0)
                flag = 1;
        }
        if ((I(8) & 0xff) == 0)
            func_ov004_020afdd0(data_ov006_02138a40[flag], 0xe8, -0x90, -1, -1);
        else
            func_ov004_020afdd0(data_ov006_02138a88[flag], 0xe8, -0x90, -1, -1);
    }

    /* Dispatch loops */
    {
        int r4;
        for (r4 = 0; r4 < I(0x4674); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x4740))->f1();
    }
    if (*(void **)(g + 0x4778) != 0)
        ((DispObj *)*(void **)(g + 0x4778))->f1();
    {
        int r4;
        for (r4 = 0; r4 < I(0x4668); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x4688))->f1();
    }
    {
        int r4;
        for (r4 = 0; r4 < I(0x466c); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x4720))->f1();
    }
    {
        int r4;
        for (r4 = 0; r4 < I(0x4670); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x46bc))->f1();
    }
    {
        int r4;
        for (r4 = 0; r4 < I(0x4678); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x474c))->f1();
    }
    {
        int r4;
        for (r4 = 0; r4 < I(0x467c); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x4764))->f1();
    }
    {
        int r4;
        for (r4 = 0; r4 < I(0x4680); r4++)
            ((DispObj *)*(void **)(g + r4 * 4 + 0x4770))->f1();
    }
    ((DispObj *)*(void **)(g + 0x4684))->f1();
    if (*(void **)(g + 0x477c) != 0)
        ((DispObj *)*(void **)(g + 0x477c))->f1();
    if (*(void **)(g + 0x4780) != 0)
        ((DispObj *)*(void **)(g + 0x4780))->f1();
    {
        int r5;
        for (r5 = 0; r5 < I(0x4668); r5++)
            func_ov006_02113c14(*(void **)(g + r5 * 4 + 0x4688));
    }

    if ((I(8) & 0xff) == 0 && UC(0x595c) != 0)
        func_ov006_02114b10(g);

    return 1;
}
