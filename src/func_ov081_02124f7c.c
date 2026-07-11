extern void func_02012694(int a0, void *a1);
extern void *_ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    unsigned int a, unsigned int b, int c, int d, int e, const void *f, void *g);

int func_ov081_02124f7c(char *thiz)
{
    volatile int c, d, e;
    int ee, dd;
    *(int*)(thiz + 0xa8) = 0x3c000;
    *(int*)(thiz + 0x9c) = -0x4000;
    func_02012694(0xdc, thiz + 0x74);
    c = *(int*)(thiz + 0x44c);
    d = *(int*)(thiz + 0x450);
    e = *(int*)(thiz + 0x454);
    *(void**)(thiz + 0x460) =
        _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
            *(volatile unsigned int*)(thiz + 0x460), 0x11a, c, d, *(int*)(thiz + 0x454), 0, 0);
    dd = d + 0x1e000;
    ee = e;
    d = dd;
    *(void**)(thiz + 0x464) =
        _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
            *(volatile unsigned int*)(thiz + 0x464), 0x11b, c, d, ee, 0, 0);
    return 1;
}
