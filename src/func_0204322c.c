//cpp
// NEAR-MISS (div: frame shape): same wall as func_02043288 / func_0204335c —
// mwccarm 1.2/sp2p3 lowers by-value 8-byte PTMF args with a dynamic sp adjust
// + fp frame (push {fp,lr}; sub sp,#0x10; mov fp,sp; mov sp,ip; add sp,ip,#4),
// while the ROM has a static sub sp,#0xc frame with an unprotected below-sp
// split-struct copy (sub ip,sp,#4; str/str; ldm ip,{r3}). Core 17 instructions
// are identical; only the frame/sp-safety shape diverges.
struct ActorBase {
    int Process(int (ActorBase::*)(), bool (ActorBase::*)(), void (ActorBase::*)(unsigned int));
};

typedef int (ActorBase::*PMFi)();
typedef bool (ActorBase::*PMFb)();
typedef void (ActorBase::*PMFu)(unsigned int);

extern PMFi data_02099ecc;
extern PMFb data_02099e74;
extern PMFu data_02099e9c;

extern "C" int func_0204322c(ActorBase *self) {
    return self->Process(data_02099ecc, data_02099e74, data_02099e9c);
}
