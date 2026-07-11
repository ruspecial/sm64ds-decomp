//cpp
struct C;
extern "C" void func_ov006_021050bc(C* c);

struct C { char dummy; };

typedef void (C::*PMF)(int);
extern PMF data_ov006_02142840[];

extern "C" void func_ov006_02106fdc(C* c) {
    int i = 0;
    int found = 0;
    func_ov006_021050bc(c);
    char *self = (char*)c;
    *(unsigned char*)(self + 0x4000 + 0xfe9) = 1;
    for (i = 0; i < *(int*)(self + 0x4000 + 0xcb8); i++) {
        unsigned char k = *(unsigned char*)(self + i + 0x4000 + 0xefa);
        (c->*data_ov006_02142840[k])(i);
        if (k != 0)
            found++;
    }
    if (found != 0)
        return;
    *(int*)(self + 0x4000 + 0xca8) = 4;
    *(unsigned char*)(self + 0x4000 + 0xfdf) = 1;
    *(short*)(self + 0x4e00 + 0xc4) = 0x40;
}
