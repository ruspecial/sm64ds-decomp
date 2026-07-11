typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_ov006_020f3f10(char *c);
extern void func_ov006_020f3964(char *c);
extern void func_02012790(int a);
extern void func_ov006_020f39fc(char *c);

extern u8 data_020a0e40;
extern u8 data_020a0de8[];
extern u8 data_020a0de9[];

void func_ov006_020f456c(char *self) {
    func_ov006_020f3f10(self);
    func_ov006_020f3964(self);

    if (*(u16 *)(self + 0x5322) != 0) {
        (*(u16 *)(((long long)(int)(self + 0x5322)) & 0xFFFFFFFFFFFFFFFFLL))--;
        return;
    }

    {
        u8 v = data_020a0e40;
        int flag = 0;
        if (data_020a0de8[v * 4] != 0) {
            if (data_020a0de9[v * 4] != 0)
                flag = 1;
        }
        if (flag == 0)
            return;
    }

    func_02012790(0x62);

    if (*(s32 *)(self + 0xa8) == 0) {
        int i, j;
        if (*(u8 *)(self + 0x533c) == 1) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 5; j++) {
                    int n = j + i * 5 + 2;
                    u8 *p = (u8 *)(self + n * 0x18 + 0x5000);
                    if (p[0x1bb] != 0) {
                        p[0x1bc] = 6;
                        break;
                    }
                }
            }
        } else {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 4; j++) {
                    int n = j + i * 4;
                    u8 *p = (u8 *)(self + n * 0x18 + 0x5000);
                    if (p[0x1bb] != 0) {
                        p[0x1bc] = 6;
                        break;
                    }
                }
            }
        }
        *(u8 *)(self + 0x533d) = 0;
        func_ov006_020f39fc(self);
    }

    *(s32 *)(self + 0x5314) = 4;
}
