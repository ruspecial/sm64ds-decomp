//cpp
// NEAR-MISS (div: frame shape): correct logic, but mwccarm 1.2/sp2p3 lowers the
// by-value 8-byte PTMF args with a dynamic sp adjust + fp frame (push {fp,lr};
// mov fp,sp; mov sp,ip; add sp,ip,#4) while the ROM has a static sub sp,#0xc
// frame with an unprotected below-sp split-struct copy. Swept: C struct args,
// u64 scalars (static frame but no mem round-trip, 0x54), unions, PTMF constants,
// local temps, variadic/unprototyped callee, #pragma exceptions off; also
// versions 1.2/base,sp2,sp3,sp4 (0x64-0x68) and 2.0/base,sp1 (0x58). Target 0x5c
// unreachable; same wall parked for func_0204322c/020432e4/0204335c in nearmiss db.
struct ActorBase {
    int Process(int (ActorBase::*)(), bool (ActorBase::*)(), void (ActorBase::*)(unsigned int));
};

typedef int (ActorBase::*PMFi)();
typedef bool (ActorBase::*PMFb)();
typedef void (ActorBase::*PMFu)(unsigned int);

extern PMFi data_02099ea4;
extern PMFb data_02099eac;
extern PMFu data_02099eb4;

extern "C" int func_02043288(ActorBase *self) {
    return self->Process(data_02099ea4, data_02099eac, data_02099eb4);
}
