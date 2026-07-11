typedef unsigned short u16;

typedef struct UnkStruct0203faa8 {
    char pad[0x14];
    u16 unk14;
} UnkStruct0203faa8;

extern UnkStruct0203faa8 *data_020a0f44;
extern int data_020a0f58;
extern int data_020a0f60;
extern int data_020a0f64;
extern int data_020a0f68;

extern int func_020625fc(int arg0, int arg1, u16 arg2, int arg3, u16 arg4, u16 arg5, u16 arg6, int arg7, int arg8, int arg9, int arg10);
extern void func_0203fdac(void);

int func_0203faa8(void) {
    // NEAR-MISS div=2: final bool emits moveq#1/movne#0, ROM has movne#0/moveq#1
    // (cond-move polarity scheduling wall; ==/!=/ternary/if-else/goto/launder all tried)
    if (func_020625fc((int)&func_0203fdac, data_020a0f68, (u16)data_020a0f64, data_020a0f60,
                      (u16)data_020a0f58, data_020a0f44->unk14 == 0, 0, 0, 0, 0, 1) != 2) {
        return 0;
    }
    return 1;
}
