// NONMATCHING: KNOWN-WALL PURE SCHEDULING (~13 diffs). Logic verified correct vs ROM.
// mwcc always if-converts the clamp (movge/strge) where ROM branches (blt;mov;str), and
// hoists o+idx into one register where ROM rematerializes the base twice. Neither is
// steerable from C at mwccarm 1.2/sp2p3. Counts as decompiled, not matched.
void func_ov002_020f335c(char *o, int i) {
    int idx = i * 0x30;
    int *fld = (int *)(o + 0x144 + idx);
    int v;
    int a, b, c;
    unsigned char *bp;
    int *lp;
    *fld += 0x1800;
    if (*fld >= 0x66000) {
        *fld = 0x66000;
    }
    bp = (unsigned char *)(o + idx);
    bp[0x15c] = 0;
    bp[0x15e] = 0;
    lp = (int *)(o + idx);
    a = lp[0x140 / 4] >> 0xc;
    v = *fld >> 0xc;
    b = lp[0x148 / 4] >> 0xc;
    c = lp[0x14c / 4] >> 0xc;
    *(volatile unsigned short *)0x4001042 = (unsigned short)(((a << 8) & 0xff00) | (b & 0xff));
    *(volatile unsigned short *)0x4001046 = (unsigned short)(((v << 8) & 0xff00) | (c & 0xff));
}
