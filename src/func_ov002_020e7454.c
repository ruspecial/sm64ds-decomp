extern void* FindWithID(unsigned int);
extern void func_02035860(void*, void*);
extern void func_ov002_020e9464(char* p);

void func_ov002_020e7454(char* self) {
    char* a = (char*)FindWithID(*(unsigned int*)(self + 0x434));
    *(unsigned short*)(((long long)(int)(self + 0x4a2)) & 0xFFFFFFFFFFFFFFFFLL) &= ~0x30;
    {
        int* src = (int*)(((int)a + 0x5c) & 0xFFFFFFFFFFFFFFFFLL);
        *(int*)(self + 0x5c) = src[0];
        *(int*)(self + 0x60) = src[1];
        *(int*)(self + 0x64) = src[2];
    }
    func_02035860(self + 0x150, self + 0x5c);
    if (*(unsigned char*)(a + 0x1d8) == 3) {
        *(int*)(self + 0x444) = *(unsigned char*)(a + 0x1da);
        *(int*)(self + 0x440) = *(int*)(self + 0x444);
        if (*(int*)(self + 0x440) != 4) return;
        func_ov002_020e9464(self);
    } else {
        unsigned char* q = (unsigned char*)(((int)a + 0x1db) & 0xFFFFFFFFFFFFFFFFLL);
        *q &= ~1;
        *q |= 2;
        *(int*)(self + 0x440) = 9;
        *(int*)(((int)self + 0x128) & 0xFFFFFFFFFFFFFFFFLL) |= 1;
        {
            unsigned short* f = (unsigned short*)(((int)self + 0x4a2) & 0xFFFFFFFFFFFFFFFFLL);
            *f &= ~2;
            *f |= 8;
        }
    }
}
