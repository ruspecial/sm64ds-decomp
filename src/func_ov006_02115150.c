extern int func_0203d614(const void* v);
extern int func_0203d434(void* p);
extern void func_0203d630(void* p, int m);

void func_ov006_02115150(char* self)
{
    int i;
    char* obj = self + 0x48d4;
    for (i = 0; i < 0x10; i++) {
        unsigned char* flag = (unsigned char*)(int)(((long long)(int)(self + (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) + 0x4804)) & 0xFFFFFFFFFFFFFFFFLL);
        if (*flag != 0) {
            *(int*)(self + (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) * 8 + 0x4854) +=
                *(int*)(self + (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) * 8 + 0x48d4);
            *(int*)(self + (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) * 8 + 0x4858) +=
                *(int*)(self + (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) * 8 + 0x48d8);
            {
                int m = func_0203d614(obj) * 6 / 8;
                if (func_0203d434(obj)) {
                    func_0203d630(obj, m);
                }
            }
            {
                int* counter = (int*)(int)(((long long)(int)(self + (int)(((long long)i) & 0xFFFFFFFFFFFFFFFFLL) * 4 + 0x4814)) & 0xFFFFFFFFFFFFFFFFLL);
                *counter += 1;
                if (*counter >= 0xf) {
                    *flag = 0;
                    *counter = 0;
                }
            }
        }
        obj += 8;
    }
}
