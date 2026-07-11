void _ZN3G2x13SetBlendAlphaEPVttttt(
    volatile unsigned short *p, unsigned short a, unsigned short b,
    unsigned short c, int d);
void func_ov006_020e9374(void *c);

void func_ov006_020e96f4(char *thiz)
{
    unsigned short *pt = (unsigned short*)(((long long)(int)(thiz + 0x554a)) & 0xFFFFFFFFFFFFFFFFLL);
    *pt = *pt + 1;
    if (*(unsigned short*)(thiz + 0x554a) >= 4) {
        unsigned char *pf = (unsigned char*)(((long long)(int)(thiz + 0x554e)) & 0xFFFFFFFFFFFFFFFFLL);
        *(unsigned short*)(thiz + 0x554a) = 0;
        *pf = *pf + 1;
        _ZN3G2x13SetBlendAlphaEPVttttt(
            (volatile unsigned short*)0x4001050, 0, 4,
            *(unsigned char*)(thiz + 0x554e), 0x10 - *(unsigned char*)(thiz + 0x554e));
    }
    func_ov006_020e9374(thiz);
    if (*(unsigned char*)(thiz + 0x554e) < 0x10)
        return;
    *(unsigned char*)(thiz + 0x554e) = 0;
    *(unsigned short*)(thiz + 0x554a) = 0;
    *(int*)(thiz + 0x5540) = 2;
    *(unsigned short*)(thiz + 0x5548) = 0;
}
