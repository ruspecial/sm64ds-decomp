extern int func_02064b2c(int off, short b, int c, int d);

int func_02063da0(char *base, int idx, int arg2)
{
    char *elem = base + 0x1d4 + idx * 0x68;
    unsigned short bit = (unsigned short)(1 << idx);
    if (*(unsigned char*)elem != 2) return 0;
    if (*(unsigned char*)(elem+1) != 8) return 0;
    {
        int r = func_02064b2c(arg2, bit, *(unsigned char*)(elem+2), *(int*)(elem+0x10));
        *(unsigned char*)elem = 1;
        return r;
    }
}
