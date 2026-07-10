// NONMATCHING: scratch register rotation (div=4). Address materialization solved via the
// (long long) lever - all opcodes/order now correct, but the compiler allocates the RMW
// temps as r1/r0 where the ROM uses r2/r1; no source shape tried (var reuse, C++, inline
// helper, bitfield, double-materialize, extra params) flips the allocation.
// Logic verified correct vs ROM. Counts as decompiled, not matched.
extern int data_ov001_020ad470;

void func_ov001_020ab3c4(void *r0) {
    char *ptr = (char *)r0;
    unsigned char *q;
    unsigned char v;
    *(int *)ptr = (int)&data_ov001_020ad470;
    *(int *)(ptr + 0xc) = 0;
    *(int *)(ptr + 0x10) = 0;
    q = (unsigned char *)(int)(((long long)(int)(ptr + 0x1b)) & 0xFFFFFFFFFFFFFFFFLL);
    v = *q;
    *q = (unsigned char)(v | 4);
}
