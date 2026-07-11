typedef struct { int x, y, z; } Vec3;

typedef struct {
    Vec3 vecB;
    Vec3 vecA;
    int counter;
    int pad1c;
    unsigned char flag;
    char pad[3];
} Elem;

typedef struct {
    char pad[0xba14];
    Elem elems[32];
} Obj;

extern void AddVec3(Vec3 *a, Vec3 *b, Vec3 *c);

void func_ov006_02125890(Obj *this) {
    int i;
    for (i = 0; i < 32; i++) {
        if (this->elems[i].flag) {
            if (this->elems[i].counter > 0) {
                this->elems[i].counter--;
                if (this->elems[i].counter <= 0) {
                    this->elems[i].flag = 0;
                    return;
                }
            }
            this->elems[i].vecA.z -= 0x200;
            AddVec3(&this->elems[i].vecB, &this->elems[i].vecA, &this->elems[i].vecB);
            if (this->elems[i].vecA.z < 0 && this->elems[i].vecB.z < 0) {
                this->elems[i].flag = 0;
                return;
            }
        }
    }
}
