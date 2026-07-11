struct Vector3 { int x, y, z; };
struct Vector3_16 { short x, y, z; };
extern int RandomIntInternal(int *seed);
extern int data_0209e650;
extern void *_ZN5Actor10FindWithIDEj(unsigned int id);
extern void _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
    unsigned int a, unsigned int b, struct Vector3 *pos, struct Vector3_16 *rot, int e, int f);

void func_ov020_02111340(char *self)
{
    int coin = (unsigned int)RandomIntInternal(&data_0209e650) >> 16 & 1;
    char *found;
    struct Vector3 pos;
    struct Vector3_16 rot;
    if (*(char **)(self + 0x41c) == 0) return;
    found = (char *)_ZN5Actor10FindWithIDEj(*(unsigned int *)(self + 0x418));
    if (found == 0) return;
    {
        int *fp = (int *)(int)(((long long)(int)(found + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
        int fx, fy, fz;
        pos.x = fx = fp[0];
        pos.y = fy = fp[1];
        pos.z = fz = fp[2];
        pos.x = fx + ((coin * 0x1f4 - 0xfa) << 12);
        pos.y = fy + 0x41000;
        pos.z = *(int *)(*(char **)(self + 0x41c) + 0x64);
    }
    rot.x = 0;
    rot.y = (short)((coin << 0xf) + 0x4000);
    rot.z = 0;
    _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
        0x145, 0, &pos, &rot, *(signed char *)(self + 0xcc), -1);
}
