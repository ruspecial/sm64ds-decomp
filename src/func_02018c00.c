// NEAR-MISS div=12/47: logic verified correct vs ROM. Whole divergence is the tail
// argument-marshalling schedule for func_02018cbc's two by-value Pairs. ROM materializes
// thiz->r0 and flag->r1 mid-copy, freeing the callee-saved r5/r4 (thiz/flag) so the 2nd
// struct copy reuses them; mwcc defers both moves to the end and copies via r0/ip instead.
// Pure scheduling/coloring wall. Tried: named locals (13), inlined both (12), name m only,
// name n only -- all stable at 12.
extern int data_020a8064[2];
extern int data_020a806c[2];
extern int data_020a8074;
extern void func_0205a61c(void *dst, void *src, int n);
struct Pair { int a, b; };
extern int func_02018cbc(void *p0, int p1, int idx, void *p3, struct Pair m, struct Pair n);

int func_02018c00(int *thiz, int flag, int index)
{
    int *base = (flag == 0) ? data_020a8064 : data_020a806c;
    int ptr = base[0];
    if (ptr != 0) {
        int off = index << 5;
        if ((unsigned int)off >= (unsigned int)base[1]) return 0;
        func_0205a61c((void*)(ptr + off), thiz, 0x20);
        thiz[8] = flag;
        return 1;
    }
    return func_02018cbc(thiz, flag, index, &data_020a8074,
                         *(struct Pair*)0x27ffe50, *(struct Pair*)0x27ffe58);
}
