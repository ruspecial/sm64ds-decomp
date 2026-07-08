// NONMATCHING: pure addressing-mode selection. Registers, instruction count and
// semantics match the ROM exactly (27/37 insns identical). The only residual is
// mwccarm 1.2/sp2p3 emitting the field load as displacement `ldr r5,[r1,#0x24]`
// (repeated) where the ROM folds the +0x24 into a pre-indexed writeback
// `ldr r5,[r1,#0x24]!` + `[r1]`. Both encodings are equal-cost and semantically
// identical; every natural C formulation (inline pointer, two-step pointer
// advance, struct member access) compiles to the displacement form. This is the
// documented pure-scheduling / addressing-mode wall, not a logic difference.
void func_02046120(void *r0, int arg1)
{
    int i;
    int count = *(int *)((char *)*(void **)r0 + 0x24);

    for (i = 0; i < count; i++) {
        volatile unsigned int *p =
            (volatile unsigned int *)((char *)*(void **)((char *)r0 + 4) + i * 0x30 + 0x24);
        *p &= 0xc0ffff0f;
        *p |= 0x40;
        *p |= 0x30;
        *p &= ~0x1f0000u;
        *p |= (unsigned int)(arg1 << 16);
    }
}
