typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    int x;                // 0x00
    int y;                // 0x04
    int unk08;
    int unk0c;
    u8 idx;               // 0x10
    u8 unk11;
    u8 active;            // 0x12
    u8 unk13;
    u8 unk14;
    u8 sub;               // 0x15
    u8 unk16;
    u8 unk17;
} Entry;

typedef struct Ctx {
    char pad[0x51a8];
    Entry entries[20];    // 0x51a8
    char pad2[0x4c];
    int mode;             // 0x53d4
} Ctx;

extern u16 data_ov006_0213d45c[];
extern int data_ov006_02142490[];
extern void func_ov004_020af68c(int a0, int a1, int a2, int a3, int a4);

void func_ov006_020f5b98(Ctx* ctx)
{
    int i;
    int f;
    for (i = 0; i < 20; i++) {
        if (ctx->entries[i].active != 0) {
            f = 0;
            if (ctx->mode != 2) {
                f = 1;
            }
            func_ov004_020af68c(
                data_ov006_02142490[data_ov006_0213d45c[ctx->entries[i].idx * 5 + ctx->entries[i].sub]],
                ctx->entries[i].x >> 12,
                ctx->entries[i].y >> 12,
                -1,
                f);
        }
    }
}
