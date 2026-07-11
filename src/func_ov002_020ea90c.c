struct Vector3 { int x, y, z; };

char *_ZN5Actor10FindWithIDEj(unsigned int id);
int Vec3_HorzDist(const struct Vector3 *a, const struct Vector3 *b);
void func_ov002_020e947c(char *a0, struct Vector3 *a1, int a2);
void func_ov002_020e81e0(char *self);
void func_ov002_020e7e24(char *self);
void func_ov002_020e7d08(char *self);

void func_ov002_020ea90c(char *self)
{
    if (*(int *)(self + 0xa8) <= -0x20000) {
        char *other = _ZN5Actor10FindWithIDEj(*(unsigned int *)(self + 0x434));
        if (other == 0 ||
            Vec3_HorzDist((const struct Vector3 *)(self + 0x5c),
                          (const struct Vector3 *)(other + 0x5c)) == 0) {
            *(int *)(self + 0xa8) = 0x18000;
            *(int *)(self + 0x440) = 3;
        } else {
            struct Vector3 *op = (struct Vector3 *)(other + 0x5c);
            struct Vector3 t, v;
            t.x = op->x;
            t.y = op->y;
            t.z = op->z;
            t.y += 0xc8000;
            v = t;
            func_ov002_020e947c(self, &v, 0x190000);
            *(int *)(self + 0x440) = 2;
        }
    }
    func_ov002_020e81e0(self);
    func_ov002_020e7e24(self);
    func_ov002_020e7d08(self);
}
