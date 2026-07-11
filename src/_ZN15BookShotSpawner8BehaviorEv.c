//cpp
// NEAR-MISS div=2: sole divergence is register coloring on the guard temp
// (ldrh/cmp use r0 vs ROM r1); logic byte-identical otherwise at mwccarm 1.2/sp2p3.
extern "C" {
struct Vector3 { int x, y, z; };
struct Vector3_16;
extern void* _ZN5Actor13ClosestPlayerEv(void);
extern int Vec3_HorzDist(const Vector3* a, const Vector3* b);
extern short Vec3_HorzAngle(const Vector3* a, const Vector3* b);
extern int _ZN5Actor14GetSubtractionEss(void* thiz, short a, short b);
extern void* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int a, unsigned int b, const Vector3& pos, const Vector3_16* r, int e, int f);

int _ZN15BookShotSpawner8BehaviorEv(char* c)
{
    char* p;
    if (*(unsigned short*)(c + 0xd4) > 0x28) {
        p = (char*)_ZN5Actor13ClosestPlayerEv();
        if (p != 0) {
            Vector3 tmp;
            Vector3* ps = (Vector3*)(int)(((long long)(int)(p + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
            tmp.x = ps->x;
            tmp.y = ps->y;
            tmp.z = ps->z;
            if (Vec3_HorzDist((Vector3*)(c + 0x5c), &tmp) < 0x258000) {
                short angle = Vec3_HorzAngle((Vector3*)(c + 0x5c), &tmp);
                if (_ZN5Actor14GetSubtractionEss(c, *(short*)(c + 0x8e), angle) < 0x2000) {
                    _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
                        0x145, 0, *(Vector3*)(c + 0x5c), (Vector3_16*)(c + 0x92),
                        *(signed char*)(c + 0xcc), -1);
                    *(short*)(c + 0xd4) = 0;
                }
            }
        }
    } else {
        *(unsigned short*)(((int)c + 0xd4) & 0xFFFFFFFFFFFFFFFFLL) += 1;
    }
    return 1;
}
}
