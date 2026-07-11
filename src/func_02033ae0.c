extern int _ZN3G2S13GetBG0CharPtrEv(void);
extern int _ZN3G2S12GetBG0ScrPtrEv(void);
extern void MultiStore_Int(int val, int *dst, int len);
extern void MultiStore16(unsigned short val, void *dst, int nbytes);
extern void func_02033a80(int arg0);
extern void func_02033e50(int a, int b);
extern void func_020341a8(int a, int b);

extern volatile short data_0209fce8;
extern unsigned char data_0209fcb0;
extern volatile unsigned char data_0209fc78;

void func_02033ae0(int a)
{
    volatile unsigned short fill;
    volatile int zero;
    int p1;
    int p2;

    p1 = _ZN3G2S13GetBG0CharPtrEv();
    zero = 0;
    MultiStore_Int(zero, (int *)p1 + 0x1000, 0x2000);

    p2 = _ZN3G2S12GetBG0ScrPtrEv();
    fill = 0x2ff;
    MultiStore16(fill, (void *)p2, 0x800);

    func_02033a80(a);

    data_0209fce8 = 0xc;
    data_0209fcb0 = 1;
    func_02033e50(0x18f, 0x28);

    data_0209fce8 = data_0209fce8 + 1;
    func_02033e50(0x197, 0x28);

    {
        unsigned char t = data_0209fc78;
        data_0209fce8 = 8;
        data_0209fc78 = t << 1;
    }
    func_020341a8(0x280, 0x20);
}
