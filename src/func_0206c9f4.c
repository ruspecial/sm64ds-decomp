typedef void (*Fn)(void*, void*, int);

extern char data_02086880[];

void func_0206c9f4(void* thiz, unsigned int count)
{
    while (count != 0) {
        unsigned int n = count < 0x10 ? count : 0x10;
        Fn fn = *(Fn*)((char*)thiz + 0x10);
        fn(thiz, data_02086880, (int)n);
        count -= n;
    }
}
