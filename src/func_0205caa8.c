int _ZN3IRQ7DisableEv(void);
void _ZN3IRQ7RestoreEj(unsigned int x);
int func_0205c864(int *thiz, int v);
void func_0205c788(int *p, int n);

int func_0205caa8(int *thiz)
{
    int saved = _ZN3IRQ7DisableEv();
    int b = (int)((thiz[4] & 2) != 0);
    if (b != 0) {
        int *p;
        func_0205c864(thiz, ((volatile int *)thiz)[4]);
        {
            int *q = (int *)(((long long)(int)((char *)thiz + 0x10)) & 0xFFFFFFFFFFFFFFFFLL);
            *q |= 0x80;
        }
        p = (int *)thiz[6];
        if (p != 0) {
            int n;
            do {
                n = p[1];
                func_0205c788(p, 3);
                p = (int *)n;
            } while (n != 0);
        }
        thiz[6] = 0;
        thiz[7] = 0;
        thiz[8] = 0;
        thiz[9] = 0;
        thiz[10] = 0;
        thiz[11] = 0;
        thiz[13] = 0;
        thiz[12] = thiz[13];
        {
            int *q2 = (int *)((unsigned long long)(unsigned int)((char *)thiz + 0x10) & 0xFFFFFFFFFFFFFFFFLL);
            *q2 &= ~0xa2;
        }
    }
    _ZN3IRQ7RestoreEj(saved);
    return 1;
}
