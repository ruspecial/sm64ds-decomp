// NONMATCHING: loop register allocation. The pmf dispatch block and both tail calls
// match; the 3-iteration counter loop diverges - the ROM uses self+i*4 as the base with
// the array offset constants (0x5434/0x5440/0x544c) hoisted into registers, while mwcc
// mirrors it (hoisted array base pointers + i*4 offset) and colors self to r8 not r6.
// Not steerable from C at mwccarm 1.2/sp2p3. Counts as decompiled, not matched.
struct DispEntry {
    int f0;
    int f4;
};

extern struct DispEntry data_ov006_02141870[];
extern int data_ov006_0213c0d8[];

extern void func_ov006_020dedfc(char *self, int a, int b, int i);
extern void func_ov006_020debfc(char *c);
extern void func_ov006_020c2b8c(char *c);

int func_ov006_020e0204(char *self)
{
    int idx = *(int *)(self + 0x5418);
    struct DispEntry *e = &data_ov006_02141870[idx];
    int f4 = e->f4;
    char *thisp = self + (f4 >> 1);
    int fn;
    int i;

    if (f4 & 1) {
        fn = *(int *)(*(char **)thisp + e->f0);
    } else {
        fn = e->f0;
    }
    ((void (*)(char *))fn)(thisp);

    {
        int *arrA = (int *)(self + 0x5434);
        int *arrB = (int *)(self + 0x5440);
        int *arrC = (int *)(self + 0x544c);
        for (i = 0; i < 3; i++) {
            int base = data_ov006_0213c0d8[arrA[i]];
            int limit = *(int *)(base + arrB[i] * 8 + 4);
            if (limit != 0) {
                arrC[i] = arrC[i] + 1;
                if (arrC[i] >= limit) {
                    arrC[i] = 0;
                    arrB[i] = arrB[i] + 1;
                    func_ov006_020dedfc(self, arrA[i], arrB[i], i);
                }
            }
        }
    }

    func_ov006_020debfc(self + 0x50e8);
    func_ov006_020c2b8c(self + 0x4f38);
    return 1;
}
