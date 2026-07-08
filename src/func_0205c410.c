void func_0205c410(char* c)
{
    char* obj = *(char**)(c + 0x8);
    unsigned b = *(unsigned*)(c + 0x28);
    unsigned a = *(unsigned*)(c + 0x2c);
    *(unsigned*)(((long long)(int)(c + 0x28)) & 0xFFFFFFFFFFFFFFFFLL) += *(unsigned*)(c + 0x34);
    (*(void (**)(char*, unsigned, unsigned))(obj + 0x40))(obj, a, b);
}
