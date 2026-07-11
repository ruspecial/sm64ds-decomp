typedef unsigned int u32;
typedef unsigned char u8;

extern u8 *_ZN5Actor10FindWithIDEj(u32 id);

void func_ov064_02118ee4(void *thiz)
{
    u8 *c = (u8 *)thiz;
    u8 *a;

    if (*(u8 *)(c + 0x338) != 0) {
        u32 id = *(u32 *)(c + 0x320);
        if (id != 0) {
            a = _ZN5Actor10FindWithIDEj(id);
            if (a) {
                *(u8 *)(a + 0xd4) = 1;
            }
        }
    }

    if (*(u8 *)(c + 0x339) != 0) {
        return;
    }

    {
        u8 idx = *(u8 *)(c + 0x328);
        signed char *tbl = (signed char *)*(u32 *)(c + 0x324);
        u8 *p = (u8 *)(((long long)(int)(c + 0x328)) & 0xFFFFFFFFFFFFFFFFLL);
        *(signed char *)(c + 0x336) = tbl[idx];
        *p = *p + 1;
    }

    if (((signed char *)*(u32 *)(c + 0x324))[*(u8 *)(c + 0x328)] == -1) {
        *(u8 *)(c + 0x328) = 0;
        if (*(u32 *)(c + 0x320) != 0) {
            a = _ZN5Actor10FindWithIDEj(*(u32 *)(c + 0x320));
            if (a) {
                u8 *f = (u8 *)((unsigned long long)(unsigned int)(a + 0xd4) & 0xFFFFFFFFFFFFFFFFLL);
                *f |= 2;
            }
        }
    }

    *(u8 *)(c + 0x339) = 1;
    *(unsigned short *)((c + 0x300) + 0x34) = 0;
}
