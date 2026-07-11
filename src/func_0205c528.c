typedef int (*M44)(void *self, int a, int b, int c);

extern int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int);
extern void func_020580f0(void *p);

void func_0205c528(char *thiz, int r1, int r7)
{
    char *o = *(char**)thiz;
    int res;
    *(int*)(int)(((long long)(int)(o + 0x10)) & 0xFFFFFFFFFFFFFFFFLL) |= 0x200;
    res = (*(M44*)(o + 0x44))(o, r1, *(int*)(thiz + 4), r7);
    switch (res) {
    case 0:
    case 1:
        *(int*)(int)(((unsigned long long)(unsigned)(o + 0x10)) & 0xFFFFFFFFFFFFFFFFULL) &= ~0x200;
        break;
    case 6: {
        unsigned int saved = (unsigned int)_ZN3IRQ7DisableEv();
        int loop;
        while ((loop = ((*(int*)(o + 0x10) & 0x200) ? 1 : 0)) != 0) {
            func_020580f0(o + 0xc);
        }
        _ZN3IRQ7RestoreEj(saved);
        break;
    }
    }
    *(int*)(int)(((long long)(int)(thiz + 4)) & 0xFFFFFFFFFFFFFFFFLL) += r7;
}
