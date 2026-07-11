extern int Vec3_Dist(void* a, void* b);
extern short Vec3_HorzAngle(void* a, void* b);
extern int func_ov095_0213579c(void* self, void* other);
extern int AngleDiff(int a, int b);
extern short data_02082214[];

void func_ov095_021357d8(char* self, char* other)
{
    char* o5c = other + 0x5c;
    int d = Vec3_Dist(self + 0x5c, o5c);
    int ang = Vec3_HorzAngle(self + 0x5c, o5c);
    int k;
    int ad;
    int idx;
    int dk;
    int val;
    int tv;
    int r2;
    short f8c;
    short* p8c;

    self[0x326] = 1;
    k = func_ov095_0213579c(self, other);
    ad = AngleDiff(ang, *(short*)(self + 0x8e));
    idx = (((int)(unsigned short)(short)ad) >> 4) << 1;
    dk = (int)(((long long)d * k + 0x800) >> 12);
    tv = data_02082214[idx + 1];
    val = (int)(((long long)dk * tv + 0x800) >> 12);
    p8c = (short*)(self + 0x8c);
    f8c = *p8c;
    r2 = val + ((unsigned)(val >> 11) >> 20);
    r2 = r2 << 4;
    *p8c = (short)(f8c + (r2 >> 16));
    if (*(short*)(self + 0x8c) > 0x2000) *(short*)(self + 0x8c) = 0x2000;
    if (*(short*)(self + 0x8c) < -0x2000) *(short*)(self + 0x8c) = -0x2000;
}
