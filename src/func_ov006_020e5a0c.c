typedef unsigned char u8;

extern u8 data_020a0e40;
extern u8 data_020a0de8[];
extern u8 data_020a0dea[];
extern u8 data_020a0deb[];

void func_ov006_020e5a0c(char *self, int idx)
{
    unsigned int i = data_020a0e40;

    if (data_020a0de8[i * 4] != 0) {
        int n = idx * 0x30;
        int t;
        *(int *)(self + 0x4660 + n) = *(int *)(self + 0x4674 + n) + (data_020a0dea[i * 4] << 12);
        t = *(int *)(self + 0x4660 + n) >> 12;
        if (t < 0xe)
            *(int *)(self + 0x4660 + n) = 0xe000;
        if (t > 0xf2)
            *(int *)(self + 0x4660 + n) = 0xf2000;
        *(int *)(self + 0x4674 + n) = ((*(int *)(self + 0x4660 + n) >> 12) - data_020a0dea[i * 4]) << 12;
        *(int *)(self + 0x4678 + n) = ((*(int *)(self + 0x4664 + n) >> 12) - data_020a0deb[i * 4]) << 12;
    } else {
        int n = idx * 0x30;
        int b0, c0, dx, dy;
        *(u8 *)(self + 0x4688 + n) = 0;
        b0 = *(int *)(self + 0x4660 + n);
        c0 = *(int *)(self + 0x4664 + n);
        dx = (*(int *)(self + 0x5584) - b0) >> 12;
        dy = (*(int *)(self + 0x5588) - c0) >> 12;
        if (dx < -0x2e)
            return;
        if (dx > 0x2e)
            return;
        if (dy < -0x14)
            return;
        if (dy <= 0x14)
            *(int *)(self + 0x5588) = c0 + 0x15000;
    }
}
