void func_ov002_020e6b3c(char *c)
{
    char *base = (char *)(((long long)(int)(c + 8)) & 0xFFFFFFFFFFFFFFFFLL);
    void *obj = *(void **)base;
    char *dst = *(char **)(base + 4);
    unsigned int n = *(unsigned int *)((char *)obj + 0x24);
    /* NEAR-MISS (13/14): ROM copies the counter (mov r0,r1) and increments it
       before the store; mwccarm stores the counter register directly. Pure
       scheduling of the loop-index store. */
    unsigned int i;
    for (i = 0; i < n; i++) {
        *(int *)(dst + 0x1c) = i;
        dst += 0x30;
    }
}
