extern void func_ov004_020adb1c(int self);
extern void func_ov006_020c72b4(void);
extern void func_ov006_020c72c8(void);
extern int RandomIntInternal(int *seed);
extern void func_ov006_020c719c(int a, int b);
extern void func_ov006_020c44b4(int a, int b);
extern void func_ov006_020ee658(char *c);

#pragma optimize_for_size on

extern char *func_020beb68;
extern int data_0209e650;
extern int data_ov006_0213cb48;
extern int data_ov006_02140328;

void func_ov006_020ee994(char *self, int flag)
{
    int r4;

    if (flag == 0) {
        int *q = (int *)(((int)self + 0xbc) & 0xFFFFFFFFFFFFFFFF);
        *q += 1;
        if (*(unsigned int *)(self + 0xbc) > 0x270e)
            *(int *)(self + 0xbc) = 0x270e;
    } else if (flag == 0x12) {
        *(int *)(self + 0xbc) = 0;
        if (*(unsigned int *)(self + 0xbc) > 0x270e)
            *(int *)(self + 0xbc) = 0x270e;
        if (func_020beb68 != 0)
            *(int *)(func_020beb68 + 0xb4) = 0;
        func_ov004_020adb1c(*(int *)(self + 0xb4));
    } else {
        if (func_020beb68 != 0)
            *(int *)(func_020beb68 + 0xb4) = *(int *)(self + 0xbc);
    }

    if (*(int *)(self + 0xbc) != 0)
        func_ov006_020c72b4();
    else
        func_ov006_020c72c8();

    r4 = *(int *)(self + 0xbc);
    if ((unsigned int)r4 >= 0xf) {
        for (;;) {
            unsigned int rnd = (unsigned int)RandomIntInternal(&data_0209e650) & 0x7fffffff;
            r4 = (int)((rnd >> 0x13) * 0xa) >> 0xc;
            if (r4 != data_ov006_0213cb48)
                break;
        }
        data_ov006_0213cb48 = r4;
        func_ov006_020c719c(*(int *)(self + 0xbc), r4);
    }

    {
        unsigned int v = *(unsigned int *)(self + 0xbc);
        if (v < 0xf)
            data_ov006_02140328 = 3;
        else if (v < 0x14)
            data_ov006_02140328 = 4;
        else if (v < 0x19)
            data_ov006_02140328 = 5;
        else
            data_ov006_02140328 = 6;
    }
    func_ov006_020c44b4(*(int *)(self + 0xbc), r4);
    func_ov006_020ee658(self);
}
