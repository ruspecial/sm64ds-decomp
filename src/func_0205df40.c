extern int data_020a8064[2];
extern int data_020a806c[2];
extern int data_020a8074;
extern void func_0205a61c(void *dst, void *src, int n);
extern int func_0205dffc(void *p0, int p1, int idx, void *p3, int a, int b, int c, int d);

int func_0205df40(int *thiz, int flag, int index)
{
    int *base = (flag == 0) ? data_020a8064 : data_020a806c;
    int ptr = base[0];
    if (ptr != 0) {
        int off = index << 5;
        if ((unsigned int)off >= (unsigned int)base[1]) return 0;
        func_0205a61c((void*)(ptr + off), thiz, 0x20);
        thiz[8] = flag;
        return 1;
    }
    {
        int *p = (int*)0x27ffe50;
        int *q = (int*)0x27ffe58;
        return func_0205dffc(thiz, flag, index, &data_020a8074,
                             p[0], p[1], q[0], q[1]);
    }
}
