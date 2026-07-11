//cpp
// NONMATCHING (div=13): prologue, frame (0x20), double-buffered V3 (tmp/pos),
// v=a+0x5c materialization, 0x4a2 pool-load and tail all match. Remaining diff is a
// pure scheduling/coloring difference in the middle bool block: the ROM materializes
// the (!=0xb2) bool into r0 immediately (cmp r0,#0) and keeps flags across the pos
// stores; mwcc defers the same movne/moveq/cmp into ip. Identical instructions,
// early-r0 vs late-ip. Pure-scheduling wall.
struct V3 { int x, y, z; };
struct Buf { struct V3 tmp; struct V3 pos; };
extern "C" {
extern void _ZN5Actor11SpawnNumberERK7Vector3jbtPS_(void* self, struct V3* pos, unsigned a, bool b, unsigned short c, void* d);
extern void func_ov002_020e7554(void* self);
extern signed char data_0209f310[];
void func_ov002_020e7218(char* c, char* a, int gate) {
    if (gate == 0) {
        int bb;
        struct Buf info;
        int* v = (int*)(int)(((long long)(int)(a + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
        info.tmp.x = v[0];
        info.tmp.y = v[1];
        info.tmp.z = v[2];
        bb = (*(unsigned short*)(c+0xc) != 0xb2);
        info.pos.x = info.tmp.x;
        info.tmp.y += 0xc8000;
        info.pos.z = info.tmp.z;
        info.pos.y = info.tmp.y;
        _ZN5Actor11SpawnNumberERK7Vector3jbtPS_(c, &info.pos, data_0209f310[*(unsigned char*)(a+0x6d8)], bb, 0x15, a);
    }
    *(unsigned short*)(int)(((long long)(int)(c+0x4a2)) & 0xFFFFFFFFFFFFFFFFLL) |= 0x40;
    func_ov002_020e7554(c);
}
}
