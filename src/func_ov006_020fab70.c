extern void SetBg2Offset(int a, int b);

void func_ov006_020fab70(char *p, int i)
{
    int n = i * 0x14;
    int dv;
    *(int *)(p + 0x5bfc + n) += *(int *)(p + 0x5c04 + n);
    *(int *)(p + 0x5c00 + n) += *(int *)(p + 0x5c08 + n);
    if (*(int *)(p + 0x5c04 + n) <= -0x2000)
        *(int *)(p + 0x5c04 + n) -= 0x100;
    if (*(int *)(p + 0x5c08 + n) <= -0xc00)
        *(int *)(p + 0x5c08 + n) += 0x40;
    dv = *(int *)(p + 0x5c00 + n) >> 12;
    {
        int fv = *(int *)(p + 0x5bfc + n) >> 12;
        if (dv <= 0) {
            *(int *)(p + 0x5c00 + n) = 0;
            *(int *)(p + 0x5c08 + n) = 0;
            *(unsigned char *)(p + 0x5c0f + n) = 2;
            SetBg2Offset(fv, 0);
        }
    }
}
