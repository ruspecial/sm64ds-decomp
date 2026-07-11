typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

extern int _ZN4cstd5atan2E5Fix12IiES1_(int y, int x);
extern void func_ov006_020fbbe8(char *self);
extern void func_ov006_020fbd38(char *self);

void func_ov006_020fe750(char *self, int i) {
    int off = i * 0x38;
    int d;
    int t;
    int cs;

    *(s32 *)(self + 0x4ed8 + off) += *(s32 *)(self + 0x4ee0 + off);
    *(s32 *)(self + 0x4edc + off) += *(s32 *)(self + 0x4ee4 + off);
    *(s32 *)(self + 0x4efc + off) += 0x10;

    d = *(s32 *)(self + 0x4ee4 + off);
    *(s32 *)(self + 0x4ee4 + off) = d + *(s32 *)(self + 0x4efc + off);
    if (*(s32 *)(self + 0x4ee4 + off) >= 0x8000)
        *(s32 *)(self + 0x4ee4 + off) = 0x8000;

    *(u16 *)(self + 0x4f08 + off) = (u16)_ZN4cstd5atan2E5Fix12IiES1_(
        *(s32 *)(self + 0x4ee4 + off) >> 12,
        *(s32 *)(self + 0x4ee0 + off) >> 12);

    if (d < 0) {
        if (*(s32 *)(self + 0x4ee4 + off) >= 0)
            *(u16 *)(self + 0x4f0a + off) = 0x40;
    }

    if (*(u16 *)(self + 0x4f0a + off) != 0) {
        char *pb = (char *)(((long long)(int)(self + 0x4f0a)) & 0xFFFFFFFFFFFFFFFFLL) + off;
        *(u16 *)pb = *(u16 *)pb - 1;
        if (*(s16 *)pb <= 0)
            *(u8 *)(self + 0x4f0d + off) = 4;
    }

    cs = *(s32 *)(self + 0x4edc + off) >> 12;
    if (cs <= -0x120)
        *(u8 *)(self + 0x4f0d + off) = 4;
    if (cs >= 0xd0)
        *(u8 *)(self + 0x4f0d + off) = 4;

    t = *(s32 *)(self + 0x4ed8 + off) >> 12;
    if (t >= 0x140)
        goto call_bbe8;
    if (t > -0x40)
        goto call_bd38;
    *(u8 *)(self + 0x4f0d + off) = 4;
call_bbe8:
    func_ov006_020fbbe8(self);
    if (*(u8 *)(self + 0x5c2f) == 0)
        return;
call_bd38:
    func_ov006_020fbd38(self);
}
