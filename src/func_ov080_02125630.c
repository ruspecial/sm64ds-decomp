//cpp
// NONMATCHING: register coloring (div=12, of which 3 are pool-word relocs).
// Logic + structure verified correct vs ROM; remaining diffs are an i-in-r0/r1
// cascade and an sfp<->b (r7<->r9) swap, immune to source reordering at
// mwccarm 1.2/sp2p3 (see notes/matching-style.md). Counts as decompiled.
struct SharedFilePtr { int w[2]; };
extern "C" void *func_0201787c(SharedFilePtr *sfp);
extern "C" int func_02045ad8(void *p);
extern "C" unsigned int func_02045a50(const void *src, unsigned int size);
extern "C" int _ZN5Model27LoadCompressedTextureToVramEPcjPc(char *, unsigned int, char *);
extern "C" void _ZN13SharedFilePtr7ReleaseEv(SharedFilePtr *self);
extern unsigned char data_ov080_0212869c[];
extern unsigned char data_ov080_02128688[];
extern SharedFilePtr *data_ov080_0212775c[];
extern "C" unsigned char *func_ov080_02125630(int i)
{
    int off = i * 0x18;
    unsigned char *e = &data_ov080_02128688[off];
    unsigned char *fl = &data_ov080_0212869c[off];
    if (data_ov080_0212869c[off] == 0) {
        SharedFilePtr *sfp = data_ov080_0212775c[i];
        char *o = (char *)func_0201787c(sfp);
        char *a = *(char **)(o + 0x18);
        char *c = *(char **)(o + 0x20);
        char *b = *(char **)(o + 0x28);
        *(int *)(e + 0) = _ZN5Model27LoadCompressedTextureToVramEPcjPc(
            *(char **)(a + 4), *(unsigned int *)(a + 8),
            *(char **)(a + 4) + *(unsigned int *)(a + 8));
        unsigned int len = *(unsigned int *)(c + 8);
        if ((int)len <= 8)
            *(int *)(e + 4) = func_02045ad8(*(void **)(c + 4));
        else
            *(int *)(e + 4) = func_02045a50(*(const void **)(c + 4), len);
        *(int *)(e + 8) = *(int *)(b + 0x28);
        *(int *)(e + 0xc) = *(int *)(b + 0x2c);
        *(int *)(e + 0x10) = *(int *)(a + 0x10);
        *fl = 1;
        _ZN13SharedFilePtr7ReleaseEv(sfp);
    }
    return e;
}
