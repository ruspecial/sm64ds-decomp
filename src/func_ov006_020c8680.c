extern int RandomIntInternal(int* seed);
extern void _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(void* self, void* bca, int a, int fix, unsigned int flags);
extern void func_ov006_020c802c(char* p);

extern int data_0209e650;
extern int data_ov006_0213b01c;
extern void* data_ov006_02140424;

void func_ov006_020c8680(char* self)
{
    int t;
    (*(short*)(self + 0x32))--;
    if (*(short*)(self + 0x32) != 0) {
        *(int*)(self + 0x18) = 0x100000;
        *(int*)(self + 0x24) = 0;
        return;
    }
    *(int*)(self + 0x18) = 0x100000;
    *(int*)(self + 0x14) =
        (((((unsigned int)RandomIntInternal(&data_0209e650) & 0x7fffffff) >> 0x13) - 0x800) * 0xc0);
    *(int*)(self + 0x24) = 0;
    t = data_ov006_0213b01c;
    *(int*)(self + 0x20) = (int)(((long long)(int)(((((unsigned int)RandomIntInternal(&data_0209e650) & 0x7fffffff) >> 0x13) - 0x800) << 1) * t + 0x800) >> 0xc);
    _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj((void*)(self + 0x4c), data_ov006_02140424, 0x40000000, 0x800, 0);
    func_ov006_020c802c(self);
}
