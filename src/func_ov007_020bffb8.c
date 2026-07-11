extern short data_02082214[];

void func_ov007_020bffb8(char *o)
{
    int a = *(unsigned short *)(o + 0x30) >> 4;
    int b = *(unsigned short *)(o + 0x32) >> 4;
    int *out = (int *)(((long long)(int)(o + 8)) & 0xFFFFFFFFFFFFFFFFLL);
    int *in = (int *)(((long long)(int)(o + 0x14)) & 0xFFFFFFFFFFFFFFFFLL);
    out[0] = (data_02082214[a * 2 + 1] * *(int *)(o + 0x2c)) >> 12;
    out[0] = in[0] + ((out[0] * data_02082214[b * 2]) >> 12);
    out[1] = in[1] + ((data_02082214[a * 2] * *(int *)(o + 0x2c)) >> 12);
    out[2] = (data_02082214[a * 2 + 1] * *(int *)(o + 0x2c)) >> 12;
    out[2] = in[2] + ((out[2] * data_02082214[b * 2 + 1]) >> 12);
}
