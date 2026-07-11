extern void func_ov004_020b0104(void* a0, int a1, int a2, int a3, int a4, void* a5);

extern char data_ov006_0213c264[];
extern char data_ov006_0213c2ac[];
extern int data_ov006_0212e468[];

void func_ov006_020e1c68(char* self)
{
    int i;
    char* p = self;
    for (i = 0; i < 5; i++) {
        char* base = p + 0x4000;
        if (*(unsigned char*)(base + 0x689) != 0 && *(unsigned char*)(base + 0x68a) != 0) {
            int x = *(int*)(base + 0x660) >> 12;
            int y = *(int*)(base + 0x664) >> 12;
            func_ov004_020b0104(data_ov006_0213c264, x, y, -1, 1, 0);
            func_ov004_020b0104(data_ov006_0213c2ac, x, y + 8, -1, 2, 0);
        }
        p += 0x2c;
    }
    {
        int n = 5 - *(unsigned char*)(self + 0x4ee6);
        int k;
        if (n < 0)
            n = 0;
        if (n <= 0)
            return;
        for (k = 0; k < n; k++) {
            int v = data_ov006_0212e468[k];
            func_ov004_020b0104(data_ov006_0213c264, v, 0xb0, -1, 1, 0);
            func_ov004_020b0104(data_ov006_0213c2ac, v, 0xb8, -1, 2, 0);
        }
    }
}
