// NONMATCHING: div=16. Logic verified vs ROM. Residual: mwcc lays out the
// v==0 message block AFTER the switch default (0x133) block; ROM places it
// between the 0x134 and 0x133 blocks. Same instructions, only block layout +
// two commutative add / pool-load register allocations differ. (The switch
// defeats the moveq/ldrne cmov merge of the 0x134/0x133 returns.)
extern signed char data_0209f2f8;
extern int func_020138dc(void);
extern int func_02013a44(void);
extern unsigned short ObjectMessageIDToActualMessageID(short);

unsigned short func_ov085_021290b4(char* c) {
    int* r5 = *(int**)(c + 0x1f8);
    int r4 = *(unsigned short*)(c + 0x208);
    if (data_0209f2f8 == 0x32) {
        int v = func_020138dc();
        if (v != 0) {
            switch (v) {
                case 0x1c: return 0x134;
                default: return 0x133;
            }
        }
        return ObjectMessageIDToActualMessageID((short)r4) + r5[2];
    }
    if (*(unsigned char*)(c + 0x20b) == 1) {
        if (func_02013a44() != 0) {
            return ObjectMessageIDToActualMessageID((unsigned short)(0xb0a + r5[2]));
        }
    }
    return ObjectMessageIDToActualMessageID((short)r4) + r5[2];
}
