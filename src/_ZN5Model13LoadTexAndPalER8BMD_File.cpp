//cpp
typedef unsigned int u32;

extern "C" {
u32 _ZN5Model27LoadCompressedTextureToVramEPcjPc(char* data, u32 size, char* end);
u32 _ZN5Model17LoadTextureToVramEPcj(char* data, u32 size);
void _ZN2GX16BeginLoadTexPlttEv();
void Crash();
void _ZN2GX11LoadTexPlttEPKvjj(const void* p, u32 a, u32 b);
void _ZN2GX14EndLoadTexPlttEv();
extern u32 data_020a4bd8;
extern u32 data_020a4bcc;
}

extern "C" void _ZN5Model13LoadTexAndPalER8BMD_File(char* f)
{
    u32 i;
    u32 j;

    for (i = 0; i < *(u32*)(f + 0x14); i++) {
        char* tex = *(char**)(f + 0x18) + i * 0x14;
        u32 sz = *(u32*)(tex + 8);
        u32 result;
        if (((*(u32*)(tex + 0x10) >> 0x1a) & 7) == 5) {
            char* d = *(char**)(tex + 4);
            result = _ZN5Model27LoadCompressedTextureToVramEPcjPc(d, sz, d + sz);
        } else {
            result = _ZN5Model17LoadTextureToVramEPcj(*(char**)(tex + 4), sz);
        }
        *(u32*)(tex + 0x10) = (*(u32*)(tex + 0x10) & 0xffff0000) | ((result >> 3) & 0xffff);
    }

    _ZN2GX16BeginLoadTexPlttEv();

    for (j = 0; j < *(u32*)(f + 0x1c); j++) {
        char* pal = *(char**)(f + 0x20) + j * 0x10;
        u32 size = *(u32*)(pal + 8);
        if (data_020a4bcc + size > data_020a4bd8)
            Crash();
        if (size <= 8) {
            _ZN2GX11LoadTexPlttEPKvjj(*(void**)(pal + 4), data_020a4bcc, size);
            *(u32*)(pal + 0xc) = data_020a4bcc;
            data_020a4bcc = data_020a4bcc + ((size + 7) & 0xfff8);
        } else {
            data_020a4bd8 = data_020a4bd8 - ((size + 0xf) & 0xfff0);
            _ZN2GX11LoadTexPlttEPKvjj(*(void**)(pal + 4), data_020a4bd8, size);
            *(u32*)(pal + 0xc) = data_020a4bd8;
        }
    }

    _ZN2GX14EndLoadTexPlttEv();
}
