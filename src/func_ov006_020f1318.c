void func_ov006_020f1318(char *c, int idx)
{
    unsigned short cnt = *(unsigned short *)(c + 0x506c + idx * 2);
    unsigned char *q;
    *(unsigned short *)(c + 0x506c + idx * 2) = cnt - 1;
    if (((short *)(c + idx * 2 + 0x5000))[0x36] < 0)
        ((short *)(c + idx * 2 + 0x5000))[0x36] = 0;
    if ((((unsigned short *)(c + idx * 2 + 0x5000))[0x36] >> 2) & 1) {
        char *p = c + 0x53dd;
        p[idx] = 0;
        q = (unsigned char *)(p + idx);
    } else {
        char *p = c + 0x53dd;
        p[idx] = 1;
        q = (unsigned char *)(p + idx);
    }
    if (((unsigned short *)(c + idx * 2 + 0x5000))[0x36] != 0) return;
    *(unsigned char *)(c + idx + 0x5000 + 0x1fd) = 0;
    *q = 1;
}
