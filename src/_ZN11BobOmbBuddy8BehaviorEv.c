// NEAR-MISS div=8/47: struct-copy scheduling block only. ROM materializes the source
// pointer (p+0x5c) into a reg and loads [r3],[r3,#4],[r3,#8]; mwcc folds the first load
// into [p,#0x5c] and materializes the base for fields 2-3, plus hoists the two HorzDist
// arg addresses (&v, thiz+0x5c) into the copy in a different order. Pure scheduling /
// instruction-selection wall. Tried: field copy, index copy, struct assign (=> memcpy,
// 0xb0), by-value marshalling (=> 0xa4), pointer reassignment, load-all-then-store.
struct Vector3 { int x, y, z; };
extern void func_ov084_0212c9a8(void *c);
extern void *_ZN5Actor13ClosestPlayerEv(void *thiz);
extern int Vec3_HorzDist(const struct Vector3* a, const struct Vector3* b);
extern short Vec3_HorzAngle(const struct Vector3 *v0, const struct Vector3 *v1);
extern void _Z14ApproachLinearRsss(short *r, short b, short c);
extern void _ZN9Animation7AdvanceEv(void *a);
extern void func_02012694(int a0, void *a1);
extern void func_ov084_0212ce50(void *c);
extern void _ZN12CylinderClsn5ClearEv(void *c);
extern void _ZN12CylinderClsn6UpdateEv(void *c);

int _ZN11BobOmbBuddy8BehaviorEv(char *thiz)
{
    struct Vector3 v;
    char *p;
    func_ov084_0212c9a8(thiz);
    p = (char*)_ZN5Actor13ClosestPlayerEv(thiz);
    if (p != 0) {
        struct Vector3 *pv = (struct Vector3*)(p + 0x5c);
        v.x = pv->x;
        v.y = pv->y;
        v.z = pv->z;
        if (Vec3_HorzDist((struct Vector3*)(thiz + 0x5c), &v) < 0x12c000) {
            short ang = Vec3_HorzAngle((struct Vector3*)(thiz + 0x5c), &v);
            _Z14ApproachLinearRsss((short*)(thiz + 0x8e), ang, 0x100);
        }
    }
    _ZN9Animation7AdvanceEv(thiz + 0x158);
    if ((unsigned short)(*(int*)(thiz + 0x160) >> 12) == 0) {
        func_02012694(0xd7, thiz + 0x74);
    }
    func_ov084_0212ce50(thiz);
    _ZN12CylinderClsn5ClearEv(thiz + 0xd4);
    _ZN12CylinderClsn6UpdateEv(thiz + 0xd4);
    return 1;
}
