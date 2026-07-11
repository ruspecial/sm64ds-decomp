typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern int func_ov006_020ebe6c(void);
extern int RandomIntInternal(int *seed);
extern void func_ov006_020ebd7c(int count);
extern void func_ov006_020ecdb8(char *self, int arg1, int arg2);
extern void func_ov004_020b0cac(int c, int a1, int a2, int a3, int arg5, short arg6);

extern s16 data_ov006_0212e80c[];
extern int data_ov006_0212e820[];
extern s16 data_ov006_02141fd8;
extern int data_ov006_0213c958;
extern int data_0209e650;
extern int data_ov006_0213c964[2];

void func_ov006_020ed8a4(char *r4) {
    int bc = *(s32 *)(r4 + 0xbc);

    if (bc < 0xa) {
        data_ov006_02141fd8 = data_ov006_0212e80c[bc];
        data_ov006_0213c958 = data_ov006_0212e820[bc];
    } else {
        int ret = func_ov006_020ebe6c();
        data_ov006_02141fd8 = ret;
        if (ret == 3) {
            data_ov006_0213c958 = 0xf;
        } else {
            unsigned int rnd = RandomIntInternal(&data_0209e650) & 0x7fffffff;
            data_ov006_0213c958 = ((int)(rnd >> 19) * 3 >> 12) + 3;
        }
    }

    if ((unsigned int)*(s32 *)(r4 + 0xbc) < 0xa)
        func_ov006_020ebd7c(2);
    else
        func_ov006_020ebd7c(3);

    {
        int i;
        char *p = (char *)(r4 + 0x4678);
        for (i = 0; i < data_ov006_0213c958; i++) {
            func_ov006_020ecdb8(p, i, *(s32 *)(r4 + 0xbc));
            p += 0x98;
        }
    }

    {
        unsigned int rnd = RandomIntInternal(&data_0209e650) & 0x7fffffff;
        int k = (int)(rnd >> 19) * data_ov006_0213c958 >> 12;
        int c0, c1;
        *(char **)(r4 + 0x4f60) = (char *)(r4 + 0x4678) + k * 0x98;
        *(s32 *)(*(char **)(r4 + 0x4f60) + 0x70) = 0;
        *(s32 *)(r4 + 0x4668) = 0x3c;
        func_ov004_020b0cac(0xd, 0x80, 0x50, 1, -1, 0xd);
        *(s32 *)(r4 + 0x4674) = 0x3c;
        *(u8 *)(r4 + 0x4f64) = 0;
        c0 = data_ov006_0213c964[0];
        c1 = data_ov006_0213c964[1];
        *(s32 *)(r4 + 0x4660) = c0;
        *(s32 *)(r4 + 0x4664) = c1;
    }
}
