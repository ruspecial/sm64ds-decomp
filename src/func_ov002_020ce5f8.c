extern void _ZN6Player11ChangeStateERNS_5StateE(void* thiz, void* state);
extern int func_ov002_020ceb54(char* p);
extern void _ZN5Sound9PlayBank0EjRK7Vector3(unsigned int a, void* v);
extern void func_ov002_020ce8bc(char* self, int a);
extern void func_ov002_020ceb7c(char* c);
extern unsigned int _ZNK6Player14GetBodyModelIDEjb(void* thiz, unsigned int a, int b);
extern void MulVec3Mat4x3(void* a, void* b, void* out);
extern int* Vec3_LslInPlace(int* v, int sh);
extern unsigned int func_020229f0(int x, int y, int z);
extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int a, void* v);

extern int data_0209f32c;
extern char data_ov002_0211013c;

int func_ov002_020ce5f8(char* self)
{
    int out[3];
    int r3 = data_0209f32c - 0x50000;
    int v60 = *(int*)(self + 0x60);

    if (v60 >= r3) {
        if ((*(unsigned char*)(self + 0x6e9) & 1) == 0) {
            if (*(int*)(self + 0xa8) >= 0) {
                *(int*)(self + 0x60) = r3;
                *(int*)(self + 0xa8) = 0;
            }
        } else if (r3 < v60 - 0xa000) {
            *(unsigned char*)(self + 0x706) = 0;
            _ZN6Player11ChangeStateERNS_5StateE(self, &data_ov002_0211013c);
            return 1;
        }
    }

    if (func_ov002_020ceb54(self) == 0) {
        if (*(unsigned char*)(self + 0x70c) == 0) {
            *(unsigned char*)(((int)self + 0x70c) & 0xFFFFFFFFFFFFFFFF) |= 1;
            _ZN5Sound9PlayBank0EjRK7Vector3(0x17, (void*)(self + 0x74));
            *(int*)(self + 0x628) = 0;
            func_ov002_020ce8bc(self, *(int*)(self + 0x640));
        } else {
            *(unsigned char*)(self + 0x70c) = 0;
            func_ov002_020ceb7c(self);
        }
        {
            unsigned int id = _ZNK6Player14GetBodyModelIDEjb(self, *(int*)(self + 8) & 0xff, 0);
            int r5 = *(int*)(*(int*)(self + (id << 2) + 0xdc) + 0x14) + 0x2d0;
            unsigned int id2 = _ZNK6Player14GetBodyModelIDEjb(self, *(int*)(self + 8) & 0xff, 0);
            MulVec3Mat4x3((void*)(r5 + 0x24), (void*)(*(int*)(self + (id2 << 2) + 0xdc) + 0x1c), out);
            Vec3_LslInPlace(out, 3);
            if (out[1] < data_0209f32c - 0x1e000) {
                func_020229f0(out[0], out[1], out[2]);
                if (*(unsigned short*)(self + 0x6a6) == 0) {
                    _ZN5Sound9PlayBank3EjRK7Vector3(0xb, (void*)(self + 0x74));
                    *(unsigned short*)(self + 0x6a6) = 0xa;
                }
            }
        }
    }
    return 0;
}
