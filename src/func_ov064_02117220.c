struct V3 { int x, y, z; };
extern int func_ov064_0211616c(void *c);
extern int RandomIntInternal(int *seed);
extern void *_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned a, unsigned b, void *v, void *r, int f, int g);
extern void *_ZN5Actor10FindWithIDEj(unsigned id);
extern int data_0209e650[];

void func_ov064_02117220(char *c) {
    struct V3 vec;
    short v16[3];
    unsigned int r;
    void *a;

    if (func_ov064_0211616c(c) == 0) {
        return;
    }
    {
        int vx = *(int *)(c + 0x5c);
        int vy = *(int *)(c + 0x60) + 0x136000;
        int vz = *(int *)(c + 0x64);
        vec.x = vx;
        vec.y = vy;
        vec.z = vz;
    }
    r = (unsigned int)RandomIntInternal(data_0209e650);
    {
        int val = *(short *)(c + 0x94) + 0x8000 + ((r >> 8) & 0x3ff);
        v16[0] = 0;
        v16[2] = 0;
        v16[1] = (short)val;
    }
    a = _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x120, 2, &vec, v16, *(signed char *)(c + 0xcc), -1);
    if (a == 0) {
        return;
    }
    *(int *)((char *)a + 0x98) = 0xa000;
    *(int *)((char *)a + 0xa4) = 0;
    *(int *)((char *)a + 0xa8) = 0x50000;
    *(int *)((char *)a + 0xac) = 0;
    {
        void *f = _ZN5Actor10FindWithIDEj(*(int *)(c + 0x3fc));
        if (f != 0) {
            unsigned char *p = (unsigned char *)(int)(((long long)(int)((char *)f + 0x3fe)) & 0xFFFFFFFFFFFFFFFFLL);
            *p = *p + 1;
        }
    }
}
