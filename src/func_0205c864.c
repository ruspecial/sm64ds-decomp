extern int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int);
extern void func_020580f0(void *p);

int func_0205c864(int *thiz)
{
    unsigned int saved;
    int notset, ret, b, loop;
    saved = (unsigned int)_ZN3IRQ7DisableEv();
    notset = (thiz[4] & 8) ? 1 : 0;
    ret = (notset == 0) ? 1 : 0;
    if (ret) {
        b = (((volatile int*)thiz)[4] & 0x10) ? 1 : 0;
        if (b != 0) {
            *(int*)(((long long)(int)((char*)thiz + 0x10)) & 0xFFFFFFFFFFFFFFFFLL) |= 0x40;
            do {
                func_020580f0((char*)thiz + 0xe);
                loop = (thiz[4] & 0x40) ? 1 : 0;
            } while (loop);
        } else {
            *(int*)(((long long)(int)((int*)thiz + 4)) & 0xFFFFFFFFFFFFFFFFLL) |= 8;
        }
    }
    _ZN3IRQ7RestoreEj(saved);
    return ret;
}
