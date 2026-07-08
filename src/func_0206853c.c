extern void MultiCopyHalf(int a, void* dst, int n);

void func_0206853c(char* c, int arg1, unsigned int flags, int arg3)
{
    int i;
    unsigned char n = 1;
    MultiCopyHalf(arg1, c + 0x35e, 0x14a);
    for (i = 0; i < 15; i++) {
        if (flags & (2 << i)) {
            n = (unsigned char)(n + 1);
        }
    }
    *(unsigned char*)(c + 0x358) = n;
    *(unsigned short*)(c + 0x35a) = (unsigned short)(flags | 1);
    *(unsigned short*)(c + 0x35c) = (unsigned short)arg3;
    (*(unsigned char*)(c + 0x4ac))++;
}
