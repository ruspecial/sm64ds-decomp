// NONMATCHING: register coloring (div=5). Instructions identical; mwcc colors
// the a+4 temp to r3 and b-0x40 to r1 where ROM has them in-place (r1/r2).
// Tried: param reuse, named temps, decl-order permutations, identity casts,
// ternary/if-else, register keyword, C++ frontend, pointer-typed params,
// 4th param - all compile to byte-identical candidates. Pure-coloring wall.
typedef struct {
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44;
} S;

void func_02058568(S *p, int a, int b) {
    int v;
    a += 4;
    p->f40 = a;
    p->f44 = b;
    b -= 0x40;
    p->f38 = b;
    v = a & 1;
    if (v != 0) {
        v = 0x3f;
    } else {
        v = 0x1f;
    }
    p->f00 = v;
    p->f04 = 0;
    p->f08 = 0;
    p->f0c = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1c = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = 0;
    p->f2c = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f3c = 0;
}
