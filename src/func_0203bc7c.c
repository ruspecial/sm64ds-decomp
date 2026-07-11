#pragma opt_strength_reduction off
#pragma opt_common_subs off

typedef unsigned short u16;

typedef struct InputPair
{
    u16 cur;
    u16 pressed;
} InputPair;

extern unsigned char data_020a0e44;
extern u16 data_020a0e48[4];
extern u16 data_020a0e50[4];
extern InputPair data_020a0e58[4];

extern u16 func_0203dae4(int idx);

void func_0203bc7c(void)
{
    InputPair *p = data_020a0e58;
    int i;
    data_020a0e44 = 0;
    for (i = 0; i < 4; i++)
    {
        u16 keys = func_0203dae4(i);
        int ofs;
        u16 old;
        int changed;
        if ((keys & 0x30) == 0x30)
            keys &= ~0x30;
        if ((keys & 0xc0) == 0xc0)
            keys &= ~0xc0;
        ofs = i * 2;
        old = *(u16 *)((int)data_020a0e50 + ofs);
        if (keys == 0x30c)
            data_020a0e44 = 1;
        changed = keys ^ old;
        p->pressed = keys & changed;
        *(u16 *)((int)data_020a0e48 + ofs) = old & changed;
        *(u16 *)((int)data_020a0e50 + ofs) = keys;
        p->cur = keys;
        p++;
    }
}
