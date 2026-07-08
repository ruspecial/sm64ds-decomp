// NONMATCHING: 41/42 instrs match (whole f14/fc--/cleanup/tail core is byte-exact).
// Only the first g->f8 load differs: ROM emits a redundant `mov r1,r5; ldr r0,[r1,#8]`
// (base copied to r1 then abandoned) where mwccarm folds to `ldr r1,[r5,#8]`. The
// matched sibling func_02060188 emits the same folded form, so this build cannot
// produce the redundant base-copy from source (register-allocation quirk).
unsigned int _ZN3IRQ7DisableEv(void);
void _ZN3IRQ7RestoreEj(unsigned int);
void Crash(void);
void func_0205807c(void* p);
typedef struct { int* f0; char pad4[4]; int f8; int fc; int f10; int f14; } G;
extern G data_020a8180;
void func_020600e0(int a0, int a1)
{
    int gi = (int)&data_020a8180;
    unsigned int s = _ZN3IRQ7DisableEv();
    G* g = (G*)gi;
    if (g->f8 != a0 || *(int*)(gi + 0xc) == 0) {
        Crash();
    } else {
        if (g->f14 != a1) Crash();
        { int* pc = (int*)((gi + 0xc) & 0xFFFFFFFFFFFFFFFF); *pc = *pc - 1; }
        if (*(int*)(gi + 0xc) == 0) {
            g->f8 = -3;
            g->f14 = 0;
            func_0205807c(&g->f10);
        }
    }
    *g->f0 = 0;
    _ZN3IRQ7RestoreEj(s);
}
