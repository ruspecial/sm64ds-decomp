// NONMATCHING: logic verified vs ROM, but far from byte-match (equal=15/53).
// Same "base materialization / addressing" wall as twin func_02065c2c: ROM
// hoists partial dst-address computation above the early-return branch, keeps
// two separate data_020a9db8[0] base copies, and the register allocation
// differs throughout. Not byte-matchable from C at mwccarm 1.2/sp2p3.
extern char *data_020a9db8[];
extern void func_0205a61c(const void *src, void *dst, unsigned int size);

int func_02065de4(unsigned char *arg0, int arg1)
{
    char *base = data_020a9db8[0];
    unsigned char idx = arg0[2];
    int slot = arg1 - 1;
    if (idx > *(int *)(base + 0x1320)) return 0;
    func_0205a61c(arg0 + 3,
                  base + 0x1538 + slot * 0x20 + idx * *(int *)(base + 0x131c),
                  *(int *)(base + 0x131c));
    *(unsigned int *)(base + 0x1718 + slot * 4) |= 1 << idx;
    {
        char *b = data_020a9db8[0];
        int N = *(int *)(b + 0x1320);
        unsigned int word = *(unsigned int *)(base + 0x1718 + slot * 4);
        unsigned char count = 0;
        unsigned char i;
        for (i = 0; i < N; i++) {
            if ((1 << i) & word) count++;
        }
        return count == N;
    }
}
