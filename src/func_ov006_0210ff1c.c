extern void func_ov004_020afdd0(void* a0, int a1, int a2, int a3, int a4);

extern void* data_ov006_021379dc;
extern void* data_ov006_021379e8;
extern void* data_ov006_02137a00;
extern void* data_ov006_021379f4;

void func_ov006_0210ff1c(char* self)
{
    int i, j;
    int y;
    int yb;

    y = 0;
    for (i = 0; i < 3; i++) {
        func_ov004_020afdd0(data_ov006_021379dc,
            (y - 0x18) + (*(int*)(self + 8) >> 12),
            *(int*)(self + 0xc) >> 12, -1, 2);
        y += 0x18;
    }

    yb = 0;
    for (j = 0; j < 3; j++) {
        int r7 = yb - 0x18;
        func_ov004_020afdd0(data_ov006_021379e8,
            (*(int*)(self + 8) >> 12) + (*(int*)(self + j * 8 + 0x34) >> 12) + r7,
            (*(int*)(self + 0xc) >> 12) + (*(int*)(self + j * 8 + 0x38) >> 12), -1, 3);
        func_ov004_020afdd0(data_ov006_02137a00,
            (*(int*)(self + 8) >> 12) + (*(int*)(self + j * 8 + 0x34) >> 12) + r7,
            (*(int*)(self + 0xc) >> 12) + (*(int*)(self + j * 8 + 0x38) >> 12) - 0x10, -1, 3);
        func_ov004_020afdd0(data_ov006_021379f4,
            (*(int*)(self + 8) >> 12) + (*(int*)(self + j * 8 + 0x34) >> 12) + r7,
            (*(int*)(self + 0xc) >> 12) + (*(int*)(self + j * 8 + 0x38) >> 12) - 0x20, -1, 3);
        func_ov004_020afdd0(data_ov006_021379e8,
            (*(int*)(self + 8) >> 12) + (*(int*)(self + j * 8 + 0x34) >> 12) + r7,
            (*(int*)(self + 0xc) >> 12) + (*(int*)(self + j * 8 + 0x38) >> 12) - 0x30, -1, 3);
        yb += 0x18;
    }
}
