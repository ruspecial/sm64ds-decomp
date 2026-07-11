// NEAR-MISS div=16/47: pure r5/r6 coloring swap (param web vs count-pointer web) plus the
// downstream 3-insn preheader schedule rotation (ldr r4 pool slot). Wall family: short-web-first
// coloring inversion (mwcc colors the short cnt web before the long param web; ROM has the
// opposite). Shapes tried: decl/stmt orders, param copy, register kw, launder spellings,
// id-var vs literal, inline vs var RMW pointer, opt_propagation pragma, C++ frontend.
typedef unsigned char u8;

extern void* _ZN5Actor15FindWithActorIDEjPS_(unsigned int id, void* after);

void func_ov080_02123fcc(char* param)
{
    register char* c = param;
    u8* cnt;
    void* a;
    *(int*)(int)(((long long)(int)(c + 0x150)) & 0xFFFFFFFFFFFFFFFFLL) |= 1;
    *(int*)(int)(((long long)(int)(c + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) &= ~0x10000000;
    if (*(u8*)(c + 0x180) != 0) {
        a = 0;
        cnt = (u8*)(c + 0x183);
        for (;;) {
            a = _ZN5Actor15FindWithActorIDEjPS_(0x136, a);
            if (a == 0) break;
            if (a == (void*)c) continue;
            if (*(u8*)(c + 0x182) != *(u8*)((char*)a + 0x182)) continue;
            *(int*)(c + *(u8*)(c + 0x183) * 4 + 0x16c) = *(int*)((char*)a + 4);
            *cnt += 1;
            if (*(u8*)(c + 0x183) == 4) break;
        }
        *(int*)(c + 0x17c) = 1;
        return;
    }
    *(int*)(c + 0x17c) = 1;
}
