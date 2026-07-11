// NONMATCHING: div=18. Size matches; all logic correct. The Vector3 of
// coords lives on the stack (sp+0xc) exactly as ROM, but mwcc scalar-replaces
// a plain local struct into callee-saved regs; forcing it to memory needs
// `volatile`, which then serialises each store right after its value (ROM
// batches the three loads, the add/mla, then the three stores) and eagerly
// reads v[0] before the self->0xf8/0xfc load at each Particle call.
extern int _ZNK12WithMeshClsn10IsOnGroundEv(int self);
extern void _ZN5Enemy9SpawnCoinEv(int self);
extern void _ZN5Actor24KillAndTrackInDeathTableEv(int self);
extern int _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(int a, int b, int x, int y, int z, int vec, int cb);
extern int _ZN8Particle6System17NewUnkCallback818Ejj5Fix12IiES2_S2_PK11Vector3_16f(int a, int b, int x, int y, int z, int vec);

int func_ov002_020ae4cc(int self, int clsn)
{
    volatile int v[3];
    int t = *(int*)(self + 0x84);
    if (t == 0) {
        v[0] = *(int*)(self + 0x5c);
        v[1] = *(int*)(self + 0x60) + 0x50000;
        v[2] = *(int*)(self + 0x64);
    } else {
        v[0] = *(int*)(self + 0x5c);
        v[1] = t * 0x50 + *(int*)(self + 0x60);
        v[2] = *(int*)(self + 0x64);
    }
    if (_ZNK12WithMeshClsn10IsOnGroundEv(clsn) != 0) {
        _ZN5Enemy9SpawnCoinEv(self);
        _ZN5Actor24KillAndTrackInDeathTableEv(self);
        *(int*)(self + 0x10c) = 0;
        return 1;
    }
    *(int*)(self + 0xf8) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(int*)(self + 0xf8), 0x13a, v[0], v[1], v[2], 0, 0);
    *(int*)(self + 0xfc) = _ZN8Particle6System17NewUnkCallback818Ejj5Fix12IiES2_S2_PK11Vector3_16f(
        *(int*)(self + 0xfc), 0x13b, v[0], v[1], v[2], 0);
    return 0;
}
