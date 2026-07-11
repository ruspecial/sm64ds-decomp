// NONMATCHING: div=11. Size matches; all logic correct. Residual is a pure
// register-coloring swap in the self+0x5c store/RMW block: ROM holds the RMW
// pointer in ip and the v.x/v.y/v.z store temps in r3; mwcc reverses them
// (pointer->r3, temps->ip) and reads the v.z compare via ip (&v) instead of sp.
// Resistant to declaration order, launder spelling, and deref-vs-index.
struct V3 { int x, y, z; };

extern int _ZN5Actor13ClosestPlayerEv(void);
extern int _ZN6Player17SetNoControlStateEhih(int self, unsigned char a, int b, unsigned char c);
extern void func_ov085_0212e728(int c, int a, int b);

extern int data_0209caa0[];
extern int data_ov085_02130800[];

int func_ov085_0212e4a4(int self)
{
    int p = _ZN5Actor13ClosestPlayerEv();
    if (p != 0) {
        struct V3 v = *(struct V3*)(p + 0x5c);
        if ((data_0209caa0[2] & 0x10000) != 0 &&
            *(int*)((int)&v + 8) > -0x28000 &&
            _ZN6Player17SetNoControlStateEhih(p, 0x12, -1, 0) != 0) {
            *(int*)(p + 0x744) = *(int*)(self + 0x5c);
            *(int*)(p + 0x748) = *(int*)(self + 0x60);
            *(int*)(p + 0x74c) = *(int*)(self + 0x64);
            *(int*)(self + 0x5c) = v.x;
            *(int*)(self + 0x60) = v.y;
            *(int*)(self + 0x64) = v.z;
            {
                int *q = (int*)(((long long)(int)(self + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
                q[0] = q[0] - 0x3e8000;
            }
            *(int*)(self + 0x60) = *(int*)(p + 0x644) + 0x3e8000;
            *(int*)(self + 0x2a4) = *(int*)(self + 0x5c);
            *(int*)(self + 0x2a8) = *(int*)(self + 0x60);
            *(int*)(self + 0x2ac) = *(int*)(self + 0x64);
            *(signed char*)(self + 0x2dc) = 0;
            func_ov085_0212e728(self, (int)data_ov085_02130800, 0);
        }
    }
    return 1;
}
