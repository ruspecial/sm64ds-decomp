extern void func_020167a4(void* p);
extern void func_ov075_02114b60(void* self);
extern void func_0204531c(void* a, int b);
extern void _ZN5Model6RenderEPK7Vector3(void* self, void* v);
extern void _ZN15TextureSequence6UpdateER15ModelComponents(void* a, void* b);

typedef struct Counted { char _pad[0x24]; unsigned int count; } Counted;
typedef struct Slot { char _pad[0x20]; int val; char _pad2[0xc]; } Slot;
typedef struct Blk48 { int w[12]; } Blk48;

void func_ov075_02114be4(char* self)
{
    Counted* A;
    Slot* B;
    Counted* C;
    Slot* D;
    unsigned int i;
    unsigned int k;
    char* p8;
    char* p78;

    func_020167a4(self);
    func_ov075_02114b60(self);
    func_0204531c(self + 8, *(int*)(self + 0x64));
    p8 = self + 8;
    A = *(Counted**)p8;
    B = *(Slot**)(p8 + 4);
    for (i = 0; i < A->count; i++) {
        B->val = *(int*)(self + 0x148);
        B++;
    }
    _ZN5Model6RenderEPK7Vector3(self, 0);
    (*(void (**)(char*, int))(*(char**)(self + 0x70) + 0x10))(self + 0x70, *(int*)(p8 + 0xc) + 0x2d0);
    *(Blk48*)(self + 0x8c) = *(Blk48*)(self + 0x1c);
    p78 = self + 0x78;
    C = *(Counted**)p78;
    D = *(Slot**)(p78 + 4);
    for (k = 0; k < C->count; k++) {
        D->val = *(int*)(self + 0x148);
        D++;
    }
    _ZN5Model6RenderEPK7Vector3(self + 0x70, 0);
    _ZN15TextureSequence6UpdateER15ModelComponents(self + 0xd4, self + 0x78);
}
