//cpp
// NONMATCHING: instruction stream is byte-identical to the ROM; only a pure
// register-coloring 3-way rotation on {v, irq, r7res} = {r8, r6, r7} remains
// (mwcc gives v r6 instead of r8). Coloring wall at mwccarm 1.2/sp2p3. div=8.
typedef unsigned short u16;
typedef unsigned int u32;
extern "C" {
int func_02057020(void);
int func_020570b8(u16 *p);
int func_02057158(int x);
int func_02057178(int a);
}
namespace IRQ { u32 Disable(); void Restore(u32); }

extern "C" int func_02058690(void)
{
    int sl;
    int sb;
    u16 v;
    int r7;
    u32 irq;
    sb = 0;
    v = (u16)func_02057020();
    sl = sb;
    do {
        r7 = -1;
        irq = IRQ::Disable();
        if ((func_020570b8((u16*)0x27fffe8) & 0x40) != 0 || (r7 = func_02057158(v)) == 0) {
            if (*(int*)0x8000000 == 0x544e494e && *(int*)0x8000004 == 0x4f444e45)
                sl = 0x1000000;
            else
                sl = 0x2000000;
            if (r7 == 0) {
                func_02057178(v);
                sb = 1;
            }
        }
        IRQ::Restore(irq);
    } while (sb == 0);
    return sl;
}
