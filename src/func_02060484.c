//cpp
// NONMATCHING: only the IRQ-guarded flag test diverges (1 extra `mov r1,r6`;
// mwcc defers the flag load past `mov r5,r0` and copies the base instead of
// loading the word into a scratch reg like the ROM). RMW + rest match byte-exact.
// Register-allocation/scheduling wall at mwccarm 1.2/sp2p3.
typedef unsigned int u32;
extern "C" {
extern char data_020a8180[];
extern int data_020a6134[];
void func_020580f0(void* p);
void func_02060228(void* fn);
int func_0206062c(void* g);
}
namespace IRQ { unsigned int Disable(); void Restore(unsigned int); }

extern "C" int func_02060484(int a, int b, int c, int d, int e, int f)
{
    char* g = data_020a8180;
    unsigned int irq = IRQ::Disable();
    if (*(u32*)(g + 0x34) & 4) {
        do {
            func_020580f0(g + 0xd4);
        } while (*(u32*)(g + 0x34) & 4);
    }
    *(u32*)(((int)g + 0x34) & 0xFFFFFFFFFFFFFFFFLL) |= 4;
    IRQ::Restore(irq);
    *(int*)(g + 0x18) = b;
    *(int*)(g + 0x1c) = a;
    *(int*)(g + 0x20) = c;
    *(int*)(g + 0x28) = d;
    *(int*)(g + 0x2c) = e;
    if (f != 0) {
        func_02060228((void*)func_0206062c);
        return 1;
    }
    *(int*)(data_020a8180 + 0xd0) = data_020a6134[2];
    func_0206062c(g);
    return (*(int**)g)[0] == 0;
}
