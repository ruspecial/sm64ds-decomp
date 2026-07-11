typedef struct
{
    unsigned int w0;
    unsigned int field : 10;
    unsigned int hi : 22;
} Entry;

int func_ov004_020af5e0(Entry *src, Entry *dst, unsigned int a2)
{
    Entry *d = dst;
    int count = 1;
    int i;
    for (i = 0; i < 0x20; i++)
    {
        dst[i] = *src;
        {
            unsigned int *p = (unsigned int *)(int)(((long long)(int)((char *)d + 4)) & 0xFFFFFFFFFFFFFFFFLL);
            unsigned int old = *p;
            *p = (old & ~0x3ff) | ((a2 + src->field) & 0x3ff);
        }
        if (*(unsigned short *)((char *)src + 6) == 0xffff)
            break;
        if (i == 0x1f)
        {
            *(unsigned short *)((char *)&dst[i] + 6) = 0xffff;
            break;
        }
        src++;
        count++;
        d++;
    }
    return count;
}
