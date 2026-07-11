extern void func_ov060_02113564(char *c);
extern void func_ov060_021134ac(char *c);
extern int func_ov060_02113404(char *c);
extern int func_ov060_021130c0(char *c);
extern int func_ov060_02112ee0(char *c);

void func_ov060_02112ddc(char *self) {
    switch (*(unsigned char *)(self + 0x423)) {
    case 0:
        func_ov060_02113564(self);
        return;
    case 1:
        func_ov060_021134ac(self);
        return;
    case 2:
        if (func_ov060_02113404(self) != 0) {
            unsigned char *p;
            *(short *)(self + 0x3fe) = 0;
            if (*(unsigned char *)(self + 0x414) == 2) {
                *(unsigned char *)(self + 0x423) = 0xa;
                return;
            }
            p = (unsigned char *)(((int)self + 0x423) & 0xFFFFFFFFFFFFFFFFLL);
            (*p)++;
        }
        return;
    case 3: {
        unsigned char *p;
        if (func_ov060_021130c0(self) == 0) return;
        p = (unsigned char *)(((int)self + 0x423) & 0xFFFFFFFFFFFFFFFFLL);
        (*p)++;
        return;
    }
    case 10:
        if (func_ov060_02112ee0(self) != 0) {
            unsigned char *p = (unsigned char *)(((int)self + 0x423) & 0xFFFFFFFFFFFFFFFFLL);
            (*p)++;
        }
        return;
    case 11:
        return;
    }
}
