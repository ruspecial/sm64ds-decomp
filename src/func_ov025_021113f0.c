// NONMATCHING: scratch register rotation (div=11). 240/251 instructions byte-identical.
// Sole divergence: the sine-table lookup block (angle chain / table pool / 0x17 multiplier
// land in r2/r1/r0 where the ROM has r0/r2/r1, and the table ldrsh reuses the chain reg in
// ROM vs the pool reg here). Identical wall to func_ov025_02112288's idx blocks; ~6 shapes
// tried (var reuse, literal vs short var, decl order, statement order) - none rotate it.
// Logic verified correct vs ROM. Counts as decompiled, not matched.
typedef struct { int x, y, z; } Vec3;

extern void func_ov025_02111344(char *c);
extern int _ZN8Platform13IsClsnInRangeE5Fix12IiES1_(char *c, int a, int b);
extern void func_ov025_021112e0(char *c);
extern int func_ov025_0211123c(char *c);
extern int func_01ffabe4(int a, int b);
extern void func_02012694(unsigned int id, const Vec3 *v);
extern void _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(char *a, const Vec3 *v, int power);
extern unsigned int _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    unsigned int h, unsigned int id, int x, int y, int z, void *dir, void *cb);
extern short data_02082214[];

int func_ov025_021113f0(char *c)
{
    int chain;
    struct {
        Vec3 v;
        Vec3 q;
    } s;
    int s5;
    int lim;
    int idx;
    int prod;
    short sv;
    short k;
    short m;

    if (*(signed char *)(c + 0x328) == -1) {
        if (*(unsigned short *)(c + 0x326) == 0x20) {
            *(signed char *)(c + 0x328) = 0;
            *(unsigned short *)(c + 0x326) = 0;
        } else {
            *(unsigned short *)(int)(((long long)(int)(c + 0x326)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
            *(int *)(c + 0xac) = 0;
            *(short *)(c + 0x324) = 0;
            func_ov025_02111344(c);
            if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0, 0))
                func_ov025_021112e0(c);
            return 1;
        }
    }
    s5 = 10 - *(signed char *)(c + 0x328);
    if (s5 < 0) {
        m = -1;
        s5 = s5 * m;
    }
    s5 -= 6;
    if (s5 < 0)
        s5 = 0;
    if (*(unsigned short *)(c + 0x326) == s5 + 8) {
        *(unsigned short *)(c + 0x326) = 0;
        *(signed char *)(int)(((long long)(int)(c + 0x328)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
        if (*(signed char *)(c + 0x328) == 0x14) {
            *(unsigned char *)(int)(((long long)(int)(c + 0x329)) & 0xFFFFFFFFFFFFFFFFLL) ^= 1;
            *(signed char *)(c + 0x328) = -1;
        }
    }
    if ((unsigned int)(s5 - 3) <= 1)
        s5 = 4;
    else if ((unsigned int)(s5 - 1) <= 1)
        s5 = 2;
    else if (s5 == 0)
        s5 = 1;
    lim = s5 << 3;
    if (*(unsigned short *)(c + 0x326) < lim) {
        if (*(unsigned char *)(c + 0x329) == 0) {
            *(int *)(c + 0xac) = func_01ffabe4(0x14000, s5);
            *(short *)(c + 0x324) = (short)func_01ffabe4(0x400, s5);
        } else {
            *(int *)(c + 0xac) = func_01ffabe4(-0x14000, s5);
            *(short *)(c + 0x324) = (short)func_01ffabe4(-0x400, s5);
        }
        *(int *)(int)(((long long)(int)(c + 0x64)) & 0xFFFFFFFFFFFFFFFFLL) += *(int *)(c + 0xac);
        *(short *)(int)(((long long)(int)(c + 0x8c)) & 0xFFFFFFFFFFFFFFFFLL) += *(short *)(c + 0x324);
        if ((*(short *)(c + 0x8c) & 0x1fff) < 0x320) {
            if (*(short *)(c + 0x324) != 0)
                func_02012694(0x65, (const Vec3 *)(c + 0x74));
        }
        chain = *(short *)(c + 0x8c);
        chain = (int)(chain << 0x12) >> 0x10;
        chain = (int)((unsigned)(chain << 0x10) >> 0x10) >> 4;
        chain = data_02082214[chain << 1];
        prod = (short)chain * (short)0x17;
        if (prod < 0) {
            m = -1;
            prod = prod * m;
        }
        *(int *)(c + 0x60) = *(int *)(c + 0x320) + prod;
        if (*(unsigned short *)(c + 0x326) == lim - 1) {
            s.q.x = *(int *)(c + 0x5c);
            s.q.y = *(int *)(c + 0x60);
            s.q.z = *(int *)(c + 0x64);
            _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(c, &s.q, 0x3e8000);
        }
        s.v.x = *(int *)(c + 0x5c);
        s.v.y = *(int *)(c + 0x60);
        s.v.z = *(int *)(c + 0x64);
        s.v.x = *(int *)(c + 0x5c) + data_02082214[((*(unsigned short *)(c + 0x8e) >> 4) << 1) + 1] * 0x64;
        s.v.y = *(int *)(c + 0x320) - 0xb9000;
        s.v.z = *(int *)(c + 0x64) + data_02082214[(*(unsigned short *)(c + 0x8e) >> 4) << 1] * 0x64;
        *(unsigned int *)(c + 0x32c) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
            *(unsigned int *)(c + 0x32c), 0x2d, s.v.x, s.v.y, s.v.z, 0, 0);
        s.v.x = *(int *)(c + 0x5c) - data_02082214[((*(unsigned short *)(c + 0x8e) >> 4) << 1) + 1] * 0x64;
        s.v.z = *(int *)(c + 0x64) - data_02082214[(*(unsigned short *)(c + 0x8e) >> 4) << 1] * 0x64;
        *(unsigned int *)(c + 0x330) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
            *(unsigned int *)(c + 0x330), 0x2d, s.v.x, s.v.y, s.v.z, 0, 0);
    }
    func_ov025_02111344(c);
    if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0, 0) || func_ov025_0211123c(c) != 0)
        func_ov025_021112e0(c);
    *(unsigned short *)(int)(((long long)(int)(c + 0x326)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
    return 1;
}
