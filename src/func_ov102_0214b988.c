typedef struct Vector3 { int x, y, z; } Vector3;

extern void *_ZN5Actor13ClosestPlayerEv(void *thiz);
extern int Vec3_Dist(const Vector3 *a, const Vector3 *b);
extern short Vec3_HorzAngle(const Vector3 *a, const Vector3 *b);
extern int AngleDiff(int a, int b);
extern void func_ov102_0214b384(void *thiz, int a);

void func_ov102_0214b988(void *thiz)
{
    unsigned char *c = (unsigned char *)thiz;
    unsigned char *pl;
    Vector3 v;

    *(int *)(c + 0x38c) = 0;
    pl = (unsigned char *)_ZN5Actor13ClosestPlayerEv(c);
    if (!pl) return;
    if (Vec3_Dist((Vector3 *)(c + 0x5c), (Vector3 *)(pl + 0x5c)) > 0x190000) return;
    {
        Vector3 *plp = (Vector3 *)(int)(((long long)(int)(pl + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
        v.x = plp->x;
        v.y = plp->y;
        v.z = plp->z;
    }
    if (AngleDiff(Vec3_HorzAngle((Vector3 *)(c + 0x5c), &v), *(short *)(c + 0x8e)) >= *(unsigned short *)(c + 0x3ec)) return;
    *(int *)(c + 0x38c) = (int)pl;
    func_ov102_0214b384(c, 0x96);
}
