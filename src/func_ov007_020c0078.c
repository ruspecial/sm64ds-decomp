extern short data_02082214[];
extern void _ZN3G3i13PerspectiveW_E5Fix12IiES1_S1_S1_S1_S1_bP9Matrix4x3(
    int a0, int a1, int a2, int a3, int a4, int a5, int a6, void *a7);

void func_ov007_020c0078(char *c)
{
    *(int *)0x4000580 = *(unsigned char *)(c + 0xb8)
                      | (*(unsigned char *)(c + 0xba) << 8)
                      | (*(unsigned char *)(c + 0xb9) << 16)
                      | (*(unsigned char *)(c + 0xbb) << 24);

    int a = (int)*(unsigned short *)(c + 0xd4) >> 4;
    _ZN3G3i13PerspectiveW_E5Fix12IiES1_S1_S1_S1_S1_bP9Matrix4x3(
        data_02082214[a * 2],
        data_02082214[a * 2 + 1],
        ((unsigned int)*(int *)(c + 0xbc) >> 0x14) | (*(int *)(c + 0xc0) << 12),
        *(int *)(c + 0xc4),
        *(int *)(c + 0xc8),
        0x1000,
        1,
        (void *)(c + 0x74));

    *(int *)0x400044c = 0;
}
