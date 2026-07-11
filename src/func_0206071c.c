// NEAR-MISS div=7: KNOWN-WALL pure scheduling. All instructions and register
// coloring match the ROM; the 8 loop-invariant prologue defs (3 pointer adds,
// 2 constant movs, mov/str of the literal 1 arg) are emitted adds-first by the
// compiler where the ROM has constants-first. Immune to decl order, assignment
// order, entry/loop-top/loop-tail placement, volatile, #pragma scheduling off.
#pragma opt_propagation off
extern void _ZN4CP1519InvalidateDataCacheEjj(unsigned int a, unsigned int b);
extern int func_02060f60(void *thiz, int a, int b);
extern void func_0205a61c(void *a, int b, unsigned int c);
extern void func_0206081c(void *thiz);

void func_0206071c(char *thiz)
{
    int six;
    unsigned int n;
    char *e0;
    unsigned int cap;
    int *p18;
    int *p1c;
    int *p20;
    e0 = thiz + 0xe0;
    cap = 0x100;
    six = 6;
    do {
        p18 = (int *)(thiz + 0x18);
        p1c = (int *)(thiz + 0x1c);
        p20 = (int *)(thiz + 0x20);
        n = *(unsigned int *)(thiz + 0x20);
        if (n > 0x100) n = cap;
        _ZN4CP1519InvalidateDataCacheEjj((unsigned int)e0, cap);
        *(int *)(*(int *)thiz + 0xc) = *(int *)(thiz + 0x18);
        *(char **)(*(int *)thiz + 0x10) = e0;
        *(unsigned int *)(*(int *)thiz + 0x14) = n;
        if (func_02060f60(thiz, six, 1) == 0) break;
        func_0205a61c(e0, *(int *)(thiz + 0x1c), n);
        *p18 = *p18 + n;
        *p1c = *p1c + n;
        *p20 = *p20 - n;
    } while (*(int *)(thiz + 0x20) != 0);
    func_0206081c(thiz);
}
