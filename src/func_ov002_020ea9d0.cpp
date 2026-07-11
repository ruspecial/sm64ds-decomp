//cpp
#pragma opt_propagation off
struct Vector3 { int x, y, z; };

extern "C" {
void func_ov002_020e9590(char *self);
void _ZN9ActorBase18MarkForDestructionEv(void *self);
void func_02012694(unsigned int id, const Vector3 *v);
void func_ov002_020e9448(unsigned char *p);
char *_ZN5Actor10FindWithIDEj(unsigned int id);
int Vec3_HorzDist(const Vector3 *a, const Vector3 *b);
void func_ov002_020e947c(char *a0, char *a1, int a2);
int func_ov002_020e8dd8(unsigned char *self);
void func_ov002_020e7e24(void *self);
void func_ov002_020e7d08(char *self);
extern int data_0209b454;
extern signed char data_0209f2f8;

void func_ov002_020ea9d0(char *self)
{
    if (*(unsigned char *)(self + 0x49d) != 0) {
        func_ov002_020e9590(self);
        if (*(int *)(self + 0x434) == 0) {
            _ZN9ActorBase18MarkForDestructionEv(self);
            return;
        }
    }

    *(int *)(((long long)(int)(self + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) |= 0x4000000;
    data_0209b454 |= 0x4000000;
    *(unsigned short *)(self + 0x496) = 0;
    func_02012694(0x57, (const Vector3 *)(self + 0x74));
    *(int *)(self + 0xa8) = 0x20000;
    func_ov002_020e9448((unsigned char *)self);

    {
        char *other = _ZN5Actor10FindWithIDEj(*(unsigned int *)(self + 0x434));
        if (*(int *)(self + 0x43c) == 4) {
            if (other == 0 || Vec3_HorzDist((const Vector3 *)(self + 0x5c), (const Vector3 *)(other + 0x5c)) == 0) {
                *(int *)(self + 0xa8) = 0x18000;
                *(int *)(self + 0x440) = 3;
            } else {
                Vector3 v0, v1, v2;
                signed char state;
                int bx, by, bz;
                *(int *)(self + 0x440) = 2;
                bx = *(int *)(other + 0x5c);
                by = *(int *)(other + 0x60);
                bz = *(int *)(other + 0x64);
                by += 0xc8000;
                state = data_0209f2f8;
                if (state == 0x11) {
                    v0.x = bx;
                    v0.y = by;
                    v0.z = bz;
                    func_ov002_020e947c(self, (char *)&v0, 0x64000);
                } else if (state == 0xb && *(unsigned char *)(self + 0x49d) == 3) {
                    v1.x = bx;
                    v1.y = by;
                    v1.z = bz;
                    func_ov002_020e947c(self, (char *)&v1, 0x46000);
                } else {
                    v2.x = bx;
                    v2.y = by;
                    v2.z = bz;
                    func_ov002_020e947c(self, (char *)&v2, 0x190000);
                }
            }
        } else {
            *(int *)(self + 0x440) = 1;
        }
    }

    func_ov002_020e8dd8((unsigned char *)self);
    func_ov002_020e7e24(self);
    func_ov002_020e7d08(self);
}
}
