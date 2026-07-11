//cpp
// NEAR-MISS (div: frame shape): same wall as func_02043288 — mwccarm 1.2/sp2p3
// lowers by-value 8-byte PTMF args with a dynamic sp adjust + fp frame, while
// the ROM has a static sub sp,#0xc frame with an unprotected below-sp
// split-struct copy. See src/func_02043288.cpp for the full sweep list.
struct ActorBase {
    int Process(int (ActorBase::*)(), bool (ActorBase::*)(), void (ActorBase::*)(unsigned int));
};

typedef int (ActorBase::*PMFi)();
typedef bool (ActorBase::*PMFb)();
typedef void (ActorBase::*PMFu)(unsigned int);

extern PMFi data_02099ebc;
extern PMFb data_02099ec4;
extern PMFu data_02099e94;

extern "C" int func_0204335c(ActorBase *self) {
    return self->Process(data_02099ebc, data_02099ec4, data_02099e94);
}
