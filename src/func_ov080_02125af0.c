typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry {
    int f0, f4, f8, fc, f10, f14;
} Entry;

void func_ov080_02125af0(void *thiz)
{
    unsigned char *c = (unsigned char *)thiz;
    int i;

    for (i = 0; i < *(u16 *)((c + 0x100) + 0xb8); i++) {
        Entry *e = *(Entry **)(c + 0x1a0) + i;
        int v = e->f0;
        if (v != 0) {
            u32 t = *(u32 *)(c + 8);
            if (v != ((u8)(t & 0xf) + 1) * 0x64000) {
                int v2 = e->f4;
                if (v2 != 0) {
                    if (v2 != ((u8)((t >> 4) & 0xf) + 1) * 0x64000) {
                        continue;
                    }
                }
            }
        }
        e->f8 = 0;
        (*(Entry **)(c + 0x1a0) + i)->f10 = 0x1ff00000;
    }
}
