// NEAR-MISS (~div 8): logic verified vs ROM. Sole remaining wall is mwcc CSE-
// hoisting the halfword truncation of the loop counter i (lsl/lsr) for the four
// strh field stores, where the ROM strh's the counter register directly. Immune
// to signed/unsigned counter, short vs u16 field cast, and store reordering
// (store order is fixed by the ROM). Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;

extern int data_020a94c0;
extern unsigned int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int);
extern void func_02065a84(int x);
extern void func_02065ad0(int v);
extern char *func_02065b94(void);
extern int func_02065af0(int *thiz);
extern void func_02065be0(void);
extern void func_02065ba0(int v);
extern void func_02065bb0(int v);

void func_020652fc(int a, int b, int c)
{
    unsigned int saved = _ZN3IRQ7DisableEv();
    int i;
    int j;
    char *p;
    int local[0x27];

    if (data_020a94c0 == 1) {
        _ZN3IRQ7RestoreEj(saved);
        return;
    }
    data_020a94c0 = 1;
    func_02065a84(0);
    func_02065ad0(0);
    p = func_02065b94();
    for (i = 0; i < 0x10; i++) {
        *(int *)(p + 0) = i;
        *(u16 *)(p + 8) = i;
        *(u16 *)(p + 0xa) = i;
        *(int *)(p + 0x10) = i;
        *(int *)(p + 0x138) = i;
        *(u16 *)(p + 0x140) = i;
        *(u16 *)(p + 0x142) = i;
        *(int *)(p + 0x148) = c;
        j = i;
        *(u8 *)(p + 0x1d7) = j;
        p += 0x68;
    }
    local[0] = j;
    func_02065af0(local);
    func_02065be0();
    func_02065ba0(a - 0xe);
    func_02065bb0(b - 0xe);
    _ZN3IRQ7RestoreEj(saved);
}
