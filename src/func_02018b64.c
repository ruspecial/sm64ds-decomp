// NONMATCHING: 4/39 residual, pure-scheduling wall in the func_0206d32c arg setup.
// The two conditional moves (moveq r0,#0 / movne r0,#1) for `self->f20 != 0` and the
// two same-base loads (ldr r1,[r4,#4] / ldr r3,[r4,#8]) are emitted in the opposite
// order vs ROM (arg2 local8.f20 -> r2 is stable). All registers/values are correct;
// this is only mwcc's list-scheduler tie-break, not steerable from C. Verified: 4
// source formulations of the boolean (!=0, ==0?0:1, temp, !!) all yield identical bytes.
struct Pair { int a, b; };

struct Local8 {
    char _pad0[0x20];
    int f20;
    int f24;
    char _pad1[0x20];
};

struct Self {
    int f0;
    int f4;
    int f8;
    char _pad[0x14];
    int f20;
};

extern void func_0205d874(void *s);
extern void func_0205e088(struct Pair *dst, void *src);
extern int func_02018dc4(void *a, struct Pair p, ...);
extern void func_0205e0b0(void *info);
extern int func_02018d48(void *a, int b, int c);
extern void func_0206d32c(int a, int b, int c, int d);
extern int func_0205d4cc(void *self);

int func_02018b64(struct Self *self)
{
    struct Pair pair;
    struct Local8 local8;

    func_0205d874(&local8);
    func_0205e088(&pair, self);
    if (func_02018dc4(&local8, pair) == 0) {
        return 0;
    }
    func_0205e0b0(self);
    func_02018d48(&local8, self->f4, local8.f24 - local8.f20);
    func_0206d32c(self->f20 != 0, self->f4, local8.f20, self->f8);
    func_0205d4cc(&local8);
    return 1;
}
