//cpp
typedef unsigned short u16;
typedef short s16;
extern "C" {
extern int data_020a4d30;
}
struct EffectData { s16 x, y, z; u16 div; };
struct Vector3 { int x, y, z; };

extern "C" void _ZN8Particle6Jitter4FuncERNS_10EffectDataEPcR7Vector3(EffectData& e, char* p, Vector3& v)
{
    if (*(u16*)(p + 0x2e) % e.div != 0) return;
    data_020a4d30 = data_020a4d30 * 0x5eedf715 + 0x1b0cb173;
    v.x += (e.x * (int)((unsigned)data_020a4d30 >> 0x17) - (e.x << 8)) >> 8;
    data_020a4d30 = data_020a4d30 * 0x5eedf715 + 0x1b0cb173;
    v.y += (e.y * (int)((unsigned)data_020a4d30 >> 0x17) - (e.y << 8)) >> 8;
    data_020a4d30 = data_020a4d30 * 0x5eedf715 + 0x1b0cb173;
    v.z += (e.z * (int)((unsigned)data_020a4d30 >> 0x17) - (e.z << 8)) >> 8;
}
