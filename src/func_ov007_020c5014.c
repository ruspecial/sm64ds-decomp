extern int _ZN4cstd3divEii(int a, int b);

int func_ov007_020c5014(char* self, int k)
{
    *(unsigned short*)(self + 0xb4) = 0x1000;
    if (*(int*)(self + 0xac) < *(int*)(self + 8)) {
        char* r2 = *(char**)(*(char**)(self + 0x38) + *(int*)(self + 0xac) * 4);
        while (k >= (*(int**)(r2 + 0x20))[*(int*)(self + 0xb0)]) {
            *(int*)(int)(((long long)(int)(self + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
            if (*(int*)(self + 0xb0) >= *(unsigned short*)(r2 + 8)) {
                *(int*)(int)(((long long)(int)(self + 0xac)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
                if (*(int*)(self + 0xac) >= *(int*)(self + 8)) {
                    *(int*)(self + 0xac) = *(int*)(self + 8);
                    *(int*)(self + 0xb0) = *(unsigned short*)(r2 + 8);
                    return 2;
                }
                *(int*)(self + 0xb0) = 0;
                return 1;
            }
        }
        if (*(int*)(self + 0xb0) > 0) {
            int* arr = *(int**)(r2 + 0x20);
            int b0 = *(int*)(self + 0xb0);
            int hi = arr[(unsigned int)b0];
            int lo = arr[b0 - 1];
            int num = hi - k;
            int den = hi - lo;
            if (den == 0) den = 1;
            *(unsigned short*)(self + 0xb4) = 0x1000 - _ZN4cstd3divEii(num << 12, den);
        }
        return 0;
    }
    return 2;
}
