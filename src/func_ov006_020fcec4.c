typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;

extern s16 data_02082214[];
extern int func_020124c4(int a, int b, int c, int d);

void func_ov006_020fcec4(char *base, int i)
{
    int n = i * 0x38;
    int x, y;
    *(int *)(base + 0x4660 + n) = *(int *)(base + 0x4660 + n) + *(int *)(base + 0x4668 + n);
    *(int *)(base + 0x4664 + n) = *(int *)(base + 0x4664 + n) + *(int *)(base + 0x466c + n);
    *(u16 *)(base + 0x4684 + n) = *(u16 *)(base + 0x4684 + n) + 0x800;
    if (*(int *)(base + 0x4678 + n) <= 0x30000)
        *(int *)(base + 0x4678 + n) = *(int *)(base + 0x4678 + n) + 0x800;
    *(int *)(base + 0x4670 + n) = (int)(((s64)data_02082214[((*(u16 *)(base + 0x4684 + n) >> 4) << 1) + 1] * *(int *)(base + 0x4678 + n) + 0x800) >> 0xc);
    *(int *)(base + 0x4674 + n) = (int)(((s64)data_02082214[(*(u16 *)(base + 0x4684 + n) >> 4) << 1] * *(int *)(base + 0x4678 + n) + 0x800) >> 0xc);
    x = (*(int *)(base + 0x4660 + n) + *(int *)(base + 0x4670 + n)) >> 0xc;
    y = (*(int *)(base + 0x4664 + n) + *(int *)(base + 0x4674 + n)) >> 0xc;
    *(int *)(base + 0x467c + n) = func_020124c4(*(int *)(base + 0x467c + n), 2, 0x187, 0);
    {
        int cnt = 0;
        if (x >= 0x130 || x <= -0x30) cnt++;
        if (y >= 0xf0 || y <= -0x110) cnt++;
        if (cnt != 0) {
            *(u8 *)(base + 0x468c + n) = 0;
            *(u8 *)(base + 0x468d + n) = 0;
        }
    }
}
