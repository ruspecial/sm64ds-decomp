extern int func_0205fb1c(int a, void *b);

int func_0205f8e0(int *a0, int *a1)
{
    unsigned short local;
    int r = func_0205fb1c(0, &local);
    if (r != 0) return r;
    if (a0 != 0)
        *a0 = (local & 8) ? 1 : 0;
    if (a1 != 0)
        *a1 = (local & 4) ? 1 : 0;
    return 0;
}
