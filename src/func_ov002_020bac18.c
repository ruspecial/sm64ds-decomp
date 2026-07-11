extern int _ZN5Event6GetBitEj(unsigned int bit);
extern unsigned char DecIfAbove0_Byte(unsigned char* p);
extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int id, void* pos);
extern void _ZN8Platform21UpdateModelPosAndRotYEv(void* self);

int func_ov002_020bac18(char* self)
{
    switch (*(unsigned char*)(self + 0x31f)) {
    case 0:
        if (_ZN5Event6GetBitEj(*(unsigned char*)(self + 0x321)) != 0 &&
            DecIfAbove0_Byte((unsigned char*)(self + 0x320)) == 0) {
            *(unsigned char*)(self + 0x320) = 0x40;
            (*(unsigned char*)(int)(((long long)(int)(self + 0x31f)) & 0xFFFFFFFFFFFFFFFFLL))++;
            *(int*)(int)(((long long)(int)(self + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) &= ~1;
            _ZN5Sound9PlayBank3EjRK7Vector3(0x3f, self + 0x74);
        }
        break;
    case 1:
        if (DecIfAbove0_Byte((unsigned char*)(self + 0x320)) != 0) {
            if (*(unsigned char*)(self + 0x31e) != 0)
                *(short*)(int)(((long long)(int)(self + 0x8e)) & 0xFFFFFFFFFFFFFFFFLL) += 0x100;
            else
                *(short*)(int)(((long long)(int)(self + 0x8e)) & 0xFFFFFFFFFFFFFFFFLL) -= 0x100;
        }
        break;
    case 2:
        break;
    }
    (*(unsigned char*)(int)(((long long)(int)(self + 0x31f)) & 0xFFFFFFFFFFFFFFFFLL))++;
    *(int*)(int)(((long long)(int)(self + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) |= 1;
    _ZN8Platform21UpdateModelPosAndRotYEv(self);
    return 1;
}
