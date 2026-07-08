extern int ApproachLinear2(short *r, short a, short b);
extern int func_ov004_020b37f0(void *c);

int func_ov004_020b3834(char *c)
{
    int r;
    /* NEAR-MISS (18/21): predicated increment folds the store + re-reads for the
       return; forcing base materialization (u64 launder) flips mwcc to a branch.
       Can't get predication + materialized base + no return re-read together. */
    if (*(int *)(c + 0x24) < 0x30)
        return *(int *)(c + 0x24) += 1;
    r = ApproachLinear2((short *)(c + 0x12), *(short *)(c + 0x16), 0x10);
    if (r == 0)
        return r;
    return func_ov004_020b37f0(c);
}
