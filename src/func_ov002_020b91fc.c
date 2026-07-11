typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u8 DecIfAbove0_Byte(u8* p);
extern void _ZN9ActorBase18MarkForDestructionEv(void* p);
extern int _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    int id, u32 a, int x, int y, int z, int rot, int cb);

void func_ov002_020b91fc(char* c)
{
    int f;
    int v[3];

    do {
        if (*(int*)(c + 8) == 0xffff) break;
        if (DecIfAbove0_Byte((u8*)(c + 0x3ca)) != 0) break;
        f = *(int*)(c + 0xb0);
        if ((int)((f & 0x40000) != 0) != 0) break;
        if ((int)((f & 0x20000) != 0) != 0) break;
        _ZN9ActorBase18MarkForDestructionEv(c);
    } while (0);

    {
        int x = *(int*)(c + 0x5c);
        int z = *(int*)(c + 0x64);
        int y = *(int*)(c + 0x60) + 0x82000;
        v[0] = x;
        v[1] = y;
        v[2] = z;
        *(int*)(c + 0x3c4) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
            *(volatile int*)(c + 0x3c4), 0x104,
            ((volatile int*)v)[0], ((volatile int*)v)[1], z,
            0, 0);
    }
}
