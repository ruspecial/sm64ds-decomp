extern void* func_ov007_020c3df4(int a, int b);
extern void func_ov007_020c78b0(void* obj);
extern void* func_ov007_020c844c(int p, int q);
extern void* func_ov007_020c80a4(void);

void* func_ov007_020c798c(int a, int b, int c, int d)
{
    char* obj;
    int i;
    obj = (char*)func_ov007_020c3df4(0, 0x14);
    func_ov007_020c78b0(obj);
    *(int*)(obj + 0x10) = a;
    *(int*)(obj + 4) = b;
    *(int*)(obj + 0xc) = d;
    *(void**)obj = func_ov007_020c3df4(0, *(int*)(obj + 4) << 2);
    if (*(int*)(obj + 0xc) & 1) {
        i = 0;
        if (*(int*)(obj + 4) > 0) {
            do {
                ((void**)*(int*)obj)[i] = func_ov007_020c844c(i, c);
            } while (++i < *(int*)(obj + 4));
        }
    }
    if (b > 1) {
        int count2;
        if (*(int*)(obj + 4) <= 1) {
            count2 = 0;
        } else {
            int t = (*(int*)(obj + 0xc) & 2) ? 0 : 1;
            count2 = *(int*)(obj + 4) - t;
        }
        *(void**)(obj + 8) = func_ov007_020c3df4(0, count2 << 2);
        i = 0;
        if (count2 > 0) {
            do {
                ((void**)*(int*)(obj + 8))[i] = func_ov007_020c80a4();
            } while (++i < count2);
        }
    }
    return obj;
}
