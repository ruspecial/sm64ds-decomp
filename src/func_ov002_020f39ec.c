// NONMATCHING: div=57. Size matches (0xfc); every instruction and operation is
// present and correct. Residual is a whole-function register-allocation cascade:
// ROM does `mov sl,r0` and keeps `self` in sl across the loop, folding
// [sl,#0x510]; mwcc instead hoists the loop-invariant address self+0x510 into a
// callee-saved reg (LICM), freeing self, which renames nearly every register.
// Not steerable from C source structure at mwccarm 1.2/sp2p3.
extern int data_ov002_021002a0[];
extern void MultiCopyHalf(int dst, int src, int len);

void func_ov002_020f39ec(int self, int i)
{
    int off = i * 0x4c;
    unsigned short* cnt1 = (unsigned short*)(self + 0x32 + off);
    *cnt1 = *cnt1 + 1;
    if (*cnt1 < 4) return;
    *cnt1 = 0;
    {
        unsigned short* cnt2 = (unsigned short*)(self + 0x3a + off);
        *cnt2 = *cnt2 + 1;
        if (*(unsigned char*)(self + off + 0x4a) != 0) {
            if (*cnt2 >= 0x10) *cnt2 = 0x10;
        } else {
            if (*cnt2 >= 0x20) *cnt2 = 0;
        }
    }
    {
        int sb = 0;
        int r8 = 0;
        int r7 = 0;
        int base5 = 0x6602000 + (i << 8);
        do {
            unsigned int v = data_ov002_021002a0[*(unsigned short*)(self + off + 0x3a)];
            int r3 = r8 + ((v & 7) << 8);
            if (v & 8) r3 += 0x2000;
            MultiCopyHalf(*(int*)(self + 0x510) + r3, base5 + r7, 0x100);
            sb += 1;
            r8 += 0x800;
            r7 += 0x400;
        } while (sb < 4);
    }
}
