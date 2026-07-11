// NONMATCHING (structural): target builds a frame-pointer frame
// (push {...,fp,lr}; mov fp,sp) and does `str sp,[fp,#0x14]` — an mwcc
// alloca/scoped-object idiom not reproducible from plain C. Control flow and
// both loop variants match the ROM; the fp frame shifts the whole encoding.
extern void func_02073534(void *a, void *p, int stride, int arg5);
extern void func_020717c0(void);
extern void func_02071ba0(void *obj);

struct Local { int f[7]; };

void func_020733a8(char *a, int count, int stride, void (*fn)(void *), int arg5)
{
    struct Local local;
    char *p;

    if (fn == 0)
        return;
    if (*(int *)((char *)&arg5) != 0) {
        p = a;
        *(void **)((char *)&local + 0x14) = &local;
        if (count == 0)
            return;
        do {
            fn(p);
            p += stride;
        } while (--count);
        func_02073534(a, p, stride, arg5);
        func_020717c0();
        func_02071ba0(&local);
        return;
    }
    if (count == 0)
        return;
    do {
        fn(a);
        a += stride;
    } while (--count);
}
