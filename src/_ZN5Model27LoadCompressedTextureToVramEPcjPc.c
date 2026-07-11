typedef unsigned int u32;

extern void Crash(void);
extern void _ZN2GX12BeginLoadTexEv(void);
extern void _ZN2GX7LoadTexEPKvjj(const void* texData, u32 vramOffset, u32 size);
extern void _ZN2GX10EndLoadTexEv(void);

extern u32 data_020a4be8;
extern u32 data_020a4bc8;
extern u32 data_020a4be4;
extern u32 data_020a4be0;

void _ZN5Model27LoadCompressedTextureToVramEPcjPc(char* src, u32 size, char* dst) {
    if ((data_020a4be8 - data_020a4bc8) < size) Crash();
    _ZN2GX12BeginLoadTexEv();
    _ZN2GX7LoadTexEPKvjj((const void*)src, data_020a4bc8, size);
    data_020a4be4 += size;
    _ZN2GX7LoadTexEPKvjj((const void*)dst, data_020a4be0, size >> 1);
    data_020a4be4 += size >> 1;
    _ZN2GX10EndLoadTexEv();
    data_020a4bc8 += size;
    data_020a4be0 += size >> 1;
}
