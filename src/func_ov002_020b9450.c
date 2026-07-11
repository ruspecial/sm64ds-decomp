// NONMATCHING: the three Fix12<int> spawn coordinates are passed BY VALUE on the
// stack (target: compute into r1/r2/r3, then `sub sp,#0x10` + `str [sp]/[sp,#4]/[sp,#8]`
// before the call). That memory-argument marshaling is mwccarm's C++ ABI for a
// non-trivially-copyable class type (Fix12<int> has a user copy ctor). Pure C99 has no
// copy constructors, so mwccarm always passes small structs (int / 1-word struct /
// 12-byte Vec3 / array-member struct / direct rvalue all verified) in registers r1-r3
// with NO stack spill. Everything else in the function is byte-exact; the sole residual
// is this register-vs-memory struct-argument passing, which is not reachable from C.
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int id, int x, int y, int z);
extern int func_02012694();
extern char* data_0209f318;

struct Sub { char pad[0x7c]; short f7c; };

void func_ov002_020b9450(char* c){
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x102, *(int*)(c + 0x5c), *(int*)(c + 0x60) + 0x82000, *(int*)(c + 0x64));
    func_02012694(0x7d, c + 0x74);
    *(int*)(c + 0x3c4) = 0;
    *(short*)(c + 0x8e) = ((struct Sub*)(data_0209f318 + 0x100))->f7c;
    *(char*)(c + 0x3cb) = 0x1b;
}
