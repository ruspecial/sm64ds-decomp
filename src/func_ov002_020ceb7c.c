typedef unsigned char u8;

struct Obj;

struct Camera {
    char pad0[0x60];
    int f60;                       /* 0x60 */
    char pad64[0x6d8 - 0x64];
    u8 f6d8;                       /* 0x6d8 */
    char pad6d9[0x6e5 - 0x6d9];
    u8 f6e5;                       /* 0x6e5 */
};

extern struct Obj *data_0209f318;
extern int data_0209f32c;

extern void func_0200d768(struct Obj *o, u8 playerID);
extern void func_0200d72c(struct Obj *o, u8 playerID);

void func_ov002_020ceb7c(struct Camera *c)
{
    struct Obj *o = data_0209f318;
    if (c->f6e5 & 2) {
        if (data_0209f32c - 0x50000 - c->f60 >= 0x64000) {
            return;
        }
        func_0200d768(o, c->f6d8);
        *(u8 *)(int)(((long long)(int)((int)c + 0x6e5)) & 0xFFFFFFFFFFFFFFFFLL) ^= 2;
    } else {
        if (data_0209f32c - 0x50000 - c->f60 <= 0x12c000) {
            return;
        }
        func_0200d72c(o, c->f6d8);
        *(u8 *)(int)(((long long)(int)((int)c + 0x6e5)) & 0xFFFFFFFFFFFFFFFFLL) |= 2;
    }
}
