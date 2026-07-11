//cpp
// NONMATCHING: scratch register rotation (div=29, was 52). All RMWs/structure now correct via
// address-materialization levers; remaining diffs are (a) the ldrh-value/table-pool register
// swap in the two idx blocks (ROM value->r0 table->r1, compiler emits r1/r0) and (b) case 3's
// increment pointer r2-vs-r1 from call-setup scheduling. Same rotation wall as ov001 cluster.
// Logic verified correct vs ROM. Counts as decompiled, not matched.
extern "C" {
extern short data_02082214[];
extern void _ZN8Platform21UpdateModelPosAndRotYEv(char *);
extern int _ZN8Platform13IsClsnInRangeE5Fix12IiES1_(char *, int, int);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(char *);
}

extern "C" int func_ov025_02112288(char *c)
{
    unsigned short raw;
    int idx, s, d, v, lim;
    short *tb;

    switch (*(unsigned char *)(c + 0x3f6)) {
    case 0:
        if (*(unsigned char *)(c + 0x3f7) != 0) {
            *(unsigned char *)(c + 0x3f6) = 1;
            *(short *)(c + 0x3f4) = 0;
        }
        break;
    case 1:
        raw = *(unsigned short *)(c + 0x3f4);
        tb = data_02082214;
        idx = (int)(raw << 0x1c) >> 0x10;
        idx = (int)((unsigned)(idx << 0x10) >> 0x10) >> 4;
        s = tb[idx << 1];
        d = (int)(((long long)s * 0xa + 0x800) >> 0xc);
        *(int *)(c + 0x60) = *(int *)(c + 0x374) + d;
        if (*(unsigned short *)(c + 0x3f4) == 8) {
            *(unsigned char *)(c + 0x3f6) = 2;
            *(int *)(c + 0xa8) = -0xa000;
        }
        *(unsigned short *)(int)(((long long)(int)(c + 0x3f4)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
        break;
    case 2:
        v = *(int *)(c + 0x60);
        lim = *(int *)(c + *(unsigned char *)(c + 0x3f8) * 0xc + 0x380) + 0x14000;
        if (v <= lim)
            *(unsigned char *)(int)(((long long)(int)(c + 0x3f8)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
        {
            int *q = (int *)(int)(((long long)(int)(c + 0x60)) & 0xFFFFFFFFFFFFFFFFLL);
            *q = *q + *(int *)(c + 0xa8);
        }
        if (*(int *)(c + 0x60) < 0x80000) {
            *(int *)(c + 0x60) = 0x80000;
            *(unsigned char *)(c + 0x3f6) = 3;
            *(short *)(c + 0x3f4) = 0;
        }
        break;
    case 3:
        raw = *(unsigned short *)(c + 0x3f4);
        tb = data_02082214;
        idx = (int)(raw << 0x1c) >> 0x10;
        idx = (int)((unsigned)(idx << 0x10) >> 0x10) >> 4;
        s = tb[idx << 1];
        d = (int)(((long long)s * 0xa + 0x800) >> 0xc);
        *(int *)(c + 0x60) = d + 0x80000;
        if (*(unsigned short *)(c + 0x3f4) >= 8) {
            *(int *)(c + 0xa8) = 0;
            *(int *)(c + 0x60) = 0x80000;
        }
        *(unsigned short *)(int)(((long long)(int)(c + 0x3f4)) & 0xFFFFFFFFFFFFFFFFLL) += 1;
        _ZN8Platform21UpdateModelPosAndRotYEv(c);
        if (_ZN8Platform13IsClsnInRangeE5Fix12IiES1_(c, 0, 0))
            _ZN8Platform19UpdateClsnPosAndRotEv(c);
        *(unsigned char *)(c + 0x3f7) = 0;
        break;
    }
    return 1;
}
