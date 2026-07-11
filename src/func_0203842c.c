extern int func_020393b4(void *p);
extern int func_020393ac(void *p);
extern int func_0203939c(void *p);
extern int func_0203938c(void *p);
extern int func_02035354(void *a, void *b);
extern void func_02037fec(void *c, int p1, int p2, int p3, void *e);
extern int Vec3_Dist(const void *a, const void *b);

extern void *data_020a0c80[];

struct Vec3 { int x, y, z; };

struct Info {
    char pad0[0x5c];
    struct Vec3 pos;
    char pad1[0xb0 - 0x68];
    int pB0;
    int pB4;
    int pB8;
};

typedef int (*VFN)(void *self, void *arg);

int func_0203842c(void *self)
{
    int result = 0;
    int i;
    void *o;
    struct Info *info;
    int m;
    char *base;
    int threshold;

    char *p64 = (char *)self + 0x64;
    base = p64 + 4;
    threshold = *(int *)(p64 + 0x10);
    for (i = 1; i < 0x18; i++) {
        o = data_020a0c80[i];
        if (o == 0) continue;
        info = (struct Info *)func_020393b4(o);
        if (func_02035354(self, info) != 0) continue;
        if (info != 0) {
            int active = (info->pB0 & 2) ? 1 : 0;
            if (active != 0) {
                struct Vec3 v;
                struct Vec3 *src = (struct Vec3 *)((unsigned long long)(unsigned int)((char *)info + 0x5c) & 0xFFFFFFFFFFFFFFFFULL);
                v.x = src->x;
                v.y = src->y;
                v.z = src->z;
                m = func_0203939c(o);
                if (m == -0x1000) {
                    int b4 = info->pB4;
                    int b8 = info->pB8;
                    v.y += b4;
                    m = b8 << 3;
                } else {
                    v.y += func_0203938c(o);
                }
                if (Vec3_Dist(base, &v) > m + threshold)
                    continue;
            }
        }
        {
            int mask = (*(VFN **)o)[7](o, self);
            if (mask != 0) {
                func_02037fec((char *)self + 0x10, i, func_020393ac(o), func_020393b4(o), o);
                result = 1;
            }
        }
    }
    return result;
}
