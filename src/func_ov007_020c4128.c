extern void func_ov007_020c4388(char *b, int p2);
extern void SubVec3(void *dst, void *a, void *b);
extern void func_ov007_020c421c(char *b);

void func_ov007_020c4128(char *a, char *b, int p2)
{
    int save4;
    int save8;
    int save10;
    *(int *)(b + 0x3c) = *(int *)(a + 0x3c);
    *(int *)(b + 0x40) = *(int *)(a + 0x40);
    *(unsigned short *)(b + 0x44) = *(unsigned short *)(a + 0x44);
    *(int *)(b + 0x50) = *(int *)(a + 0x50);
    save10 = *(int *)(b + 0x10);
    save4 = *(int *)(b + 4);
    save8 = *(int *)(b + 8);
    *(int *)(b + 4) += *(int *)(a + 4);
    *(int *)(b + 8) += *(int *)(a + 8);
    *(int *)(b + 0x10) += *(int *)(a + 0x10);
    func_ov007_020c4388(b, p2);
    SubVec3(b + 0x14, a + 0x14, b + 0x14);
    func_ov007_020c421c(b);
    *(int *)(b + 4) = save4;
    *(int *)(b + 8) = save8;
    *(int *)(b + 0x10) = save10;
}
