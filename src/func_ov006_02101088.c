void func_ov006_02101088(char *p, int i)
{
    char *q = p + 0x5264;
    char *b = p + (i << 6) + 0x5000;
    int t = (i << 6) & 0xFFFFFFFFFFFFFFFFLL;
    int v = *(int *)(q + (i << 6));
    int d;
    *(int *)(q + (i << 6)) = v + *(int *)(b + 0x26c);
    d = (*(int *)(b + 0x264) - *(int *)(b + 0x280)) >> 12;
    if (d >= 0x40)
    {
        if (*(int *)(b + 0x26c) >= 0x1000)
        {
            *(int *)(p + 0x526c + t) -= 0x100;
        }
    }
    else if (*(int *)(b + 0x26c) <= 0x4000)
    {
        *(int *)(p + 0x526c + t) += 0x200;
    }
    if (d < 0x60)
    {
        return;
    }
    *(unsigned short *)(p + ((unsigned int)i << 6) + 0x5292) = 0x10;
    *(int *)(p + ((unsigned int)i << 6) + 0x526c) = 0;
    *(unsigned char *)(p + ((unsigned int)i << 6) + 0x5296) = 0xb;
}
