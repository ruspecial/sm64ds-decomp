struct Node {
    struct Node *next;
    char p4[4];
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    char p20[0x2c - 0x20];
    unsigned short f2c;
    unsigned short f2e;
};

extern void _ZN8Particle14SimpleCallback14SpawnParticlesERNS_6SystemE(void *thisp, void *sys);
extern void _ZN13RaycastGroundC1Ev(void *rg);
extern void _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(void *rg, void *v, void *actor);
extern int _ZN13RaycastGround10DetectClsnEv(void *rg);
extern int func_02037e38(unsigned int *p);
extern void _ZN13RaycastGroundD1Ev(void *rg);

void _ZN8Particle17CheckLavaCallback14SpawnParticlesERNS_6SystemE(void *thisp, void *sys) {
    struct Node *n;

    _ZN8Particle14SimpleCallback14SpawnParticlesERNS_6SystemE(thisp, sys);

    n = *(struct Node **)((char *)sys + 8);
    while (n != 0) {
        int sx = n->f14 + n->f8;
        int sy = n->f18 + n->fc;
        int sz = n->f1c + n->f10;
        char rg[0x50];
        int v[3];
        _ZN13RaycastGroundC1Ev(rg);
        v[1] = (sy << 3) + 0x12c000;
        v[0] = sx << 3;
        v[2] = sz << 3;
        _ZN13RaycastGround12SetObjAndPosERK7Vector3P5Actor(rg, v, 0);
        if (_ZN13RaycastGround10DetectClsnEv(rg) != 0) {
            if (func_02037e38((unsigned int *)(rg + 0x14)) != 1) {
                n->f2e = n->f2c;
            } else {
                n->f18 = ((*(int *)(rg + 0x44) + 0x7000) >> 3) - n->fc;
            }
        }
        _ZN13RaycastGroundD1Ev(rg);
        n = n->next;
    }
}
