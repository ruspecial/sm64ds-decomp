extern int func_0205e280(char *c);

int func_0205e7e0(unsigned int *thiz, unsigned char *out)
{
    unsigned int v;
    int i;

    if (thiz == 0 || out == 0) return 1;
    v = thiz[0x19];
    if (v != 0) return v;
    v = thiz[0x18];
    if (v == 0) {
        char *p = (char*)thiz;
        func_0205e280(p);
        i = 0;
        v = 0;
        for (; i < 0x40; i++)
            (p + i)[0x20] = v;
        thiz[5] = v;
        thiz[6] = v;
        thiz[0x18] = 1;
    }
    for (i = 0; i < 0x14; i++) {
        v = i >> 2;
        v = thiz[v];
        out[i] = (unsigned char)(v >> ((3 - (i & 3)) * 8));
    }
    return 0;
}
