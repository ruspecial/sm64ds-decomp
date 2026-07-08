extern int func_ov006_0210e120(void *self);

void func_ov006_0210e3e8(char *self)
{
    *(int*)(self+0x10) = *(int*)(self+8);
    *(int*)(self+0x14) = *(int*)(self+0xc);
    if (*(int*)(self+0x34) > 0)
        (*(int*)(self+0x34))--;
    if (*(unsigned char*)(self+0x31) != 1)
        return;
    if (func_ov006_0210e120(self) != 0) {
        if (*(int*)(self+0x34) == 0)
            *(unsigned char*)(self+0x31) = 0;
    } else {
        *(int*)(self+0x34) = 0xa;
    }
}
