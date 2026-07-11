//cpp
// NONMATCHING: register coloring (div=17). Logic + control flow verified vs ROM
// (47/64 instructions match). Remaining diffs are a pure register permutation:
// the ROM colors bestAng=r7 / best=r8 / a=sb, but mwcc gives the hot loop var `a`
// the lowest callee reg r7 regardless of decl order; plus an r1/r2 swap in the
// tail store block. Not byte-matchable from C at mwccarm 1.2/sp2p3.
struct Actor {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual int  v18();   // vtable byte offset 0x48
    static Actor* Next(const Actor*);
};

extern "C" int Vec3_Dist(const void* a, const void* b);
extern "C" short Vec3_HorzAngle(const void* a, const void* b);
extern "C" short Vec3_VertAngle(const void* a, const void* b);

extern "C" Actor* func_ov002_020d708c(char* self);
Actor* func_ov002_020d708c(char* self) {
    int bestAng = 0x238e;
    Actor* best = 0;
    Actor* a = Actor::Next(best);
    if (a) {
        int thresh = bestAng;
        do {
            if (a != (Actor*)self) {
                if (a->v18()) {
                    if (Vec3_Dist(self + 0x5c, (char*)a + 0x5c) < 0x15e000) {
                        int diff = (short)(*(short*)(self + 0x8e) - Vec3_HorzAngle(self + 0x5c, (char*)a + 0x5c));
                        int ad = diff < 0 ? -diff : diff;
                        if (ad <= thresh) {
                            int ad2 = diff < 0 ? (short)(-diff) : diff;
                            if (ad2 < bestAng) {
                                bestAng = diff;
                                best = a;
                            }
                        }
                    }
                }
            }
            a = Actor::Next(a);
        } while (a);
    }
    if (best) {
        short v = Vec3_VertAngle(self + 0x5c, (char*)best + 0x5c);
        char* o = self + 0x700;
        *(short*)(o + 0x62) = 0;
        *(short*)(o + 0x64) = (short)bestAng;
        *(short*)(o + 0x66) = v;
        *(unsigned char*)(self + 0x742) = 1;
    }
    return best;
}
