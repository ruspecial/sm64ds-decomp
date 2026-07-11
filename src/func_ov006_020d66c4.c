// NONMATCHING: register coloring (div=4). Instructions identical; ROM wants
// the flag address temp in r1 and the const 1 in r2, mwcc always colors them
// r2/r1. Same 2-temp swap wall family as func_ov001_020ab3c4. Tried: named
// temps, decl order, laundered address, laundered const, flag pointer var,
// C++ frontend - all byte-identical. NOTE: #pragma opt_propagation off with
// `int one = 1;` at function top DOES flip the coloring to ROM's (r1/r2) but
// pins the mov #1 in the pre-guard block (div=6); no way found to keep the
// pragma coloring with the mov after the guard.
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);
extern void func_ov006_020d5d90(char *base, int idx);

void func_ov006_020d66c4(char *base, int idx) {
    char *p = base + (idx << 4) + 0x6000;
    if (*(unsigned char *)(p + 0x26c) != 0) {
        return;
    }
    *(unsigned char *)(p + 0x26c) = 1;
    _ZN5Sound12PlayBank2_2DEj(0x1e2);
    if (idx != 0) {
        return;
    }
    func_ov006_020d5d90(base, idx);
}
