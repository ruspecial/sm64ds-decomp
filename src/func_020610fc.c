/* func_020610fc at 0x020610fc
 * IPC send loop: call IPCSend(0xd, 2, 0) until it returns 0.
 *
 * NONMATCHING: loop (insns 0-9) + `data_020a89a4 = res` store are byte-identical.
 * The ROM emits an unreachable `b .` (infinite spin) at insn 10 BEFORE the store
 * and omits the epilogue pop - i.e. it retained dead code after an infinite loop.
 * mwccarm 1.2/sp2p3 here DCEs any source infinite loop (`while(1);`/`for(;;);`),
 * dropping the trailing store, so the `b .; <dead store>; bx` shape (no pop) is
 * not reproducible from C. Compiler dead-code-behavior wall.
 */

typedef int s32;

extern s32 IPCSend(s32 cmd, s32 arg1, s32 arg2);
extern s32 data_020a89a4;

void func_020610fc(void)
{
    s32 r6 = 0xd;
    s32 r5 = 2;
    s32 r4 = 0;
    s32 res;
    while ((res = IPCSend(r6, r5, r4)) != 0)
        ;
    data_020a89a4 = res;
}
