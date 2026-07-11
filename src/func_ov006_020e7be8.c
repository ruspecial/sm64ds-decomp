//cpp
struct C;
typedef void (C::*PMF)();
extern PMF data_ov006_0213c704;
extern "C" {
extern void _ZN9Animation7AdvanceEv(void*);
extern void func_ov006_020e7818(void*);
extern void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(unsigned int, unsigned int, int, int, int, const void*, void*);
}
struct C {
    char pad0[0x204];
    unsigned int f204;
    int f208;
    int f20c;
    PMF pmf;
};
extern "C" void func_ov006_020e7be8(C* c)
{
    {
        int* p = (int*)(int)(((long long)(int)((char*)c + 0x210)) & 0xFFFFFFFFFFFFFFFFLL);
        int* d = (int*)&data_ov006_0213c704;
        if (p[0] == d[0]) {
            if (p[1] == d[1]) return;
            if (*(int*)((char*)c + 0x210) == 0) return;
        }
    }
    (c->*(c->pmf))();
    _ZN9Animation7AdvanceEv((char*)c + 0x5c);
    func_ov006_020e7818((char*)c + 0x84);
    if (c->f208 == 0) return;
    c->f204 = (unsigned int)_ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(c->f204, 0xec, 0x48c000, 0x140000, 0x200000, 0, 0);
}
