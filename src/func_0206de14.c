// NONMATCHING: variadic arg-forwarding. Prologue homing (push {r0-r3}) and the full
// flags switch match; remaining diff is register coloring of {a,s,flags} (ROM keeps a
// in r4 via mov r4,r0 giving s=r5/flags=r6; mwcc reloads a from its home slot and uses
// one fewer callee-saved reg) plus the outgoing-arg block assembly at the blx forward.
// Not steerable from C at mwccarm 1.2/sp2p3. Counts as decompiled, not matched.
struct Dispatch {
    int f0;
    void (*f4)(int, int, int, int, int, unsigned int);
    void (*f8)(int, int, int, int, int, unsigned int);
    void (*fc)(int, int, int, int, int, unsigned int);
    void (*f10)(int, int, int, int, int, unsigned int);
    void (*f14)(int, int, int, int, int, unsigned int);
};

extern struct Dispatch *func_02073238(void);
extern int func_01ffb008(int a, int b);
extern int func_0207037c(int idx);

void func_0206de14(int a, ...)
{
    unsigned int flags = ((unsigned int *)&a)[5];
    struct Dispatch *s = func_02073238();
    void (*fn)(int, int, int, int, int, unsigned int);

    if ((flags & 0xc00000) == 0) {
        flags |= func_01ffb008(0, 0) & 0xc00000;
    }

    switch (flags & 0x7c000000) {
    case 0x04000000: fn = s->f4; break;
    case 0x08000000: fn = s->f8; break;
    case 0x10000000: fn = s->fc; break;
    case 0x20000000: fn = s->f10; break;
    case 0x40000000: fn = s->f14; break;
    default: fn = 0; break;
    }

    if (fn == 0) {
        func_0207037c(2);
    }

    fn(a, ((int *)&a)[1], ((int *)&a)[2], ((int *)&a)[3], ((int *)&a)[4], flags);
}
