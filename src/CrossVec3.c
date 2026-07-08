typedef struct { int x, y, z; } Vec3_Fix12;

void CrossVec3(const Vec3_Fix12 *a, const Vec3_Fix12 *b, Vec3_Fix12 *out)
{
    int rx = (int)(((long long)a->y * b->z - (long long)a->z * b->y + 0x800) >> 12);
    int ry = (int)(((long long)a->z * b->x - (long long)a->x * b->z + 0x800) >> 12);
    int rz = (int)(((long long)a->x * b->y - (long long)a->y * b->x + 0x800) >> 12);
    out->x = rx;
    out->y = ry;
    out->z = rz;
}
