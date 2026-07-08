typedef struct T {
    char _pad[0xc];
    int fc;
    void* f10;
} T;

typedef struct S {
    char _pad[4];
    T* f4;
} S;

typedef struct Obj {
    char _pad[0xdc];
    S* fdc;
} Obj;

extern Obj* data_ov007_0210342c;

void func_ov007_020c02d8(void* r0, int r1, unsigned short r2);
void func_ov007_020c1d78(int i);

void func_ov007_020adb84(void)
{
    S* s = data_ov007_0210342c->fdc;
    func_ov007_020c02d8(s->f4->f10, 0x18, 0x300);
    s->f4->fc = 1;
    func_ov007_020c1d78(0);
}
