extern void func_0202f290(void *o);
extern unsigned char data_0209f5f8;
extern unsigned char data_0209f5fc;
extern int data_0209f608;
extern int data_0209f60c;

void func_0202f58c(char *o)
{
    int v;

    *(unsigned char *)(o + 0xe) = 1;

    v = *(volatile unsigned short *)0x4000048;
    v = (v & ~0x3f) | 0x1f;
    v |= 0x20;
    *(volatile unsigned short *)0x4000048 = v;

    v = *(volatile unsigned short *)0x4001048;
    v = (v & ~0x3f) | 0x1f;
    v |= 0x20;
    *(volatile unsigned short *)0x4001048 = v;

    v = *(volatile unsigned short *)0x4000048;
    v = (v & ~0x3f00) | 0x1f00;
    v |= 0x2000;
    *(volatile unsigned short *)0x4000048 = v;

    v = *(volatile unsigned short *)0x4001048;
    v = (v & ~0x3f00) | 0x1f00;
    v |= 0x2000;
    *(volatile unsigned short *)0x4001048 = v;

    *(volatile unsigned short *)0x400004a &= ~0x3f;
    *(volatile unsigned short *)0x400104a &= ~0x3f;

    *(volatile int *)0x4000000 = (*(volatile int *)0x4000000 & ~0xe000) | 0x6000;
    if (data_0209f5f8 != 0) {
        *(volatile int *)0x4001000 &= ~0xe000;
    } else {
        *(volatile int *)0x4001000 = (*(volatile int *)0x4001000 & ~0xe000) | 0x6000;
    }
    data_0209f608 = 0;
    data_0209f60c = 0;
    func_0202f290(o);
    data_0209f608 = 1;
    data_0209f60c = 1;
    data_0209f5fc = 0;
    func_0202f290(o);
    if ((*(volatile unsigned short *)0x4000050 & 0x80) == 0x80) {
        *(volatile unsigned short *)0x4000050 = 0;
    }
    if ((*(volatile unsigned short *)0x4001050 & 0x80) == 0x80) {
        *(volatile unsigned short *)0x4001050 = 0;
    }
}
