//cpp
// NONMATCHING: div=17, pure callee-saved register rotation (c/b/p6/zero want
// r5/r4/r7/r6 but mwcc gives r6/r5/r4/r7). Every instruction otherwise
// byte-identical incl. the C++ virtual dispatch and pooled-arg reload.
// This is the documented short-web-first coloring-inversion wall.
typedef short s16;
struct Obj { virtual void v0(); virtual void v1(); virtual int v2(void* a); };

extern "C" int func_02044284(char* c, int b)
{
    void** table = *(void***)(c + 8);
    int idx;
    if (table == 0 || *(s16*)(c + 4) == 2)
        return 2;
    idx = *(s16*)(c + 6);
    if (table[idx] != 0) {
        s16* p6 = (s16*)(c + 6);
        do {
            *(s16*)(c + 4) = ((Obj*)c)->v2(table[(unsigned int)idx]);
            if (*(s16*)(c + 4) != 2)
                break;
            *p6 = *p6 + 1;
            *(s16*)(c + 0x12) = 0;
            if (b == 0)
                break;
            idx = *(s16*)(c + 6);
            table = *(void***)(c + 8);
        } while (table[idx] != 0);
    }
    return *(s16*)(c + 4);
}
