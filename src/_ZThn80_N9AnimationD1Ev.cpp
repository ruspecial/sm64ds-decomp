//cpp
// This-adjusting virtual destructor thunk (adjustment -0x50). Compiler-generated
// for the secondary base (Mixin) vtable of Animation, whose primary base is
// 0x50 bytes; the tail-branch target is a relocation wildcard.
struct AnimBase {
    char pad[0x50 - 4];
    virtual ~AnimBase();
    virtual void f1();
};
struct Mixin {
    int x;
    virtual ~Mixin();
    virtual void g1();
};
struct Animation : AnimBase, Mixin {
    virtual ~Animation();
};
Animation::~Animation() {}
