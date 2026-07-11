// NEAR-MISS div=8: 7 diffs are pre-indexed writeback (ldr [r1,#off]!) vs mwcc
// offset-folding to ldr [r1,#off] (FIRST-ACCESS-FOLD wall); +1 guard test
// (ands r2,#0xff vs cmp r2,#0). Logic byte-identical at mwccarm 1.2/sp2p3.
typedef unsigned char u8;
typedef unsigned short u16;

extern short data_02082214[];

void func_ov080_0212758c(char *a0, char *a1)
{
    unsigned char b = (*(u16*)(a1 + 0xc) == 0xbf);
    int t = b;
    short *tbl;
    int w2;
    if (t == 0) return;
    tbl = data_02082214;
    *(int*)(a0 + 0x32c) = *(int*)(a1 += 0x5c);
    *(int*)(a0 + 0x330) = *(int*)(a1 + 4);
    *(int*)(a0 + 0x334) = *(int*)(a1 + 8);
    *(u8*)(a0 + 0x342) = 1;
    *(u8*)(a0 + 0x33e) = 0x78;
    w2 = *(int*)(a0 + 0x98) >> 1;
    *(int*)a1 = *(int*)a1 + (int)(((long long)w2 * tbl[(*(u16*)(a0 + 0x8e) >> 4) * 2] + 0x800) >> 12);
    *(int*)(a1 += 8) = *(int*)a1 + (int)(((long long)w2 * tbl[(*(u16*)(a0 + 0x8e) >> 4) * 2 + 1] + 0x800) >> 12);
}
