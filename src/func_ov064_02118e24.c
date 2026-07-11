struct Vector3 { int x, y, z; };

extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int n, const struct Vector3 *v);

void func_ov064_02118e24(void *thiz, int a1, int a2, int a3)
{
    unsigned char *c = (unsigned char *)thiz;
    unsigned int st = *(unsigned short *)((c + 0x300) + 0x34);

    if (st < 0x14) {
        if (st & 1) {
            *(int *)(c + 0x330) = -0x6000;
        } else {
            *(int *)(c + 0x330) = 0;
        }
        return;
    }

    if (st == 0x14) {
        *(int *)(c + 0x330) = 0;
        _ZN5Sound9PlayBank3EjRK7Vector3(0xe7, (const struct Vector3 *)(c + 0x74));
    }

    if ((int)*(unsigned short *)((c + 0x300) + 0x34) >= a3 + 0x14) {
        *(unsigned char *)(c + 0x336) = 1;
        *(unsigned char *)(c + 0x339) = 0;
        return;
    }

    {
        int *px = (int *)(((long long)(int)(c + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
        int *pz = (int *)((unsigned long long)(unsigned int)(c + 0x64) & 0xFFFFFFFFFFFFFFFFLL);
        px[0] += a1;
        pz[0] += a2;
    }
}
