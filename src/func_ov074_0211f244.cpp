//cpp
struct Actor { static Actor *FindWithActorID(unsigned int id, Actor *after); };

extern "C" int RandomIntInternal(int *seed);
extern "C" int data_0209e650;

extern "C" void func_ov074_0211f244(Actor *self)
{
    Actor *a = Actor::FindWithActorID(0xc7, 0);
    if (a == 0)
        return;
    do {
        if (a != self) {
            char *t = (char *)a;
            short tmp[3];
            int rv;
            *(int *)(t + 0x9c) = -0xa000;
            rv = (unsigned int)RandomIntInternal(&data_0209e650) >> 8;
            *(short *)(t + 0x5fc) = 0x30;
            *(int *)(t + 0x98) = ((rv & 0xf) << 0xc) + 0x16000;
            *(int *)(t + 0xa4) = 0;
            *(int *)(t + 0xa8) = ((rv & 0x1f) << 0xc) + 0x60000;
            *(int *)(t + 0xac) = 0;
            tmp[0] = *(unsigned short *)(t + 0x92);
            tmp[1] = *(unsigned short *)(t + 0x94);
            tmp[2] = *(unsigned short *)(t + 0x96);
            tmp[1] += (rv & 0x1000);
            *(short *)(t + 0x92) = tmp[0];
            *(short *)(t + 0x94) = tmp[1];
            *(short *)(t + 0x96) = tmp[2];
            *(short *)(t + 0x8c) = tmp[0];
            *(short *)(t + 0x8e) = tmp[1];
            *(short *)(t + 0x90) = tmp[2];
            *(unsigned char *)(t + 0x609) = 1;
        }
        a = Actor::FindWithActorID(0xc7, a);
    } while (a != 0);
}
