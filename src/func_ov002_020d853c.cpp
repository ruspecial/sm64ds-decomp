//cpp
// NONMATCHING (div=6): short-web/long-web coloring inversion. Structure, branch
// layout, mp+0x50 materialization and sub/tbl coloring all match; the v/k long web
// wants r3 but mwcc reuses sub's r1 (data[j] takes r0). Documented unfixable family.
struct State;
extern "C" {
extern int _ZN6Player7IsStateERNS_5StateE(void* self, struct State* s);
extern unsigned _ZNK6Player14GetBodyModelIDEjb(void* self, unsigned a, int b);
extern short Vec3_HorzAngle(void* v0, void* v1);
extern int AngleDiff(int a, int b);
extern struct State data_ov002_02110574;
extern unsigned short data_ov002_0210a5dc[];
int func_ov002_020d853c(char* c, char* o) {
    if (_ZN6Player7IsStateERNS_5StateE(c, &data_ov002_02110574)) {
        int j = (*(unsigned char*)(c+0x6e2) << 1) & 0xff;
        unsigned idx = _ZNK6Player14GetBodyModelIDEjb(c, *(int*)(c+8) & 0xff, 0);
        char* mp = *(char**)(c + 0xdc + idx*4);
        char* sub = (char*)(int)(((long long)(int)(mp+0x50)) & 0xFFFFFFFFFFFFFFFFLL);
        unsigned short* tbl = (unsigned short*)(int)(((long long)(int)(data_ov002_0210a5dc)) & 0xFFFFFFFFFFFFFFFFLL);
        int v = *(int*)(sub + 8);
        int k = (int)((unsigned)(v << 4) >> 16);
        if (k < tbl[j]) goto retA;
        if (k <= tbl[j+1]) goto ang;
retA:
        return 1;
ang:
        if (AngleDiff(Vec3_HorzAngle(c+0x5c, o+0x5c), *(short*)(c+0x8e)) < 0x4000) return 0;
    }
    return 1;
}
}
