void func_0205c448(char* c)
{
    char* obj = *(char**)(c + 0x8);
    unsigned b = *(unsigned*)(c + 0x28);
    unsigned a = *(unsigned*)(c + 0x2c);
    unsigned inc = *(unsigned*)(c + 0x34);
    *(unsigned*)(((long long)(int)(c + 0x28)) & 0xFFFFFFFFFFFFFFFFLL) += inc;
    (*(void (**)(char*, unsigned, unsigned))(obj + 0x3c))(obj, a, b);
}
