extern int atan2i(int y, int x);
extern int Vec3_Dist(const void *a, const void *b);
extern int PathPtr_GetNode(void *self, void *v, unsigned int i);

int func_ov062_02119af0(char *p) {
    int dx = *(int *)(p + 0x3cc) - *(int *)(p + 0x5c);
    int dz = *(int *)(p + 0x3d4) - *(int *)(p + 0x64);
    int dxc = *(int *)(p + 0x3cc) - *(int *)(p + 0x3c0);
    int dzc = *(int *)(p + 0x3d4) - *(int *)(p + 0x3c8);
    *(short *)(p + 0x3a8) = (short)atan2i(dx, dz);
    if ((dzc >> 0xc) * (dz >> 0xc) + (dxc >> 0xc) * (dx >> 0xc) > 0) {
        if (Vec3_Dist(p + 0x5c, p + 0x3cc) < (*(int *)(p + 0x98) >> 1)) {
            *(int *)(p + 0x3c0) = *(int *)(p + 0x3cc);
            *(int *)(p + 0x3c4) = *(int *)(p + 0x3d0);
            *(int *)(p + 0x3c8) = *(int *)(p + 0x3d4);
            {
                int *cnt = (int *)(int)(((long long)(int)(p + 0x3bc)) & 0xFFFFFFFFFFFFFFFFLL);
                *cnt += 1;
            }
            if (*(int *)(p + 0x3bc) >= *(int *)(p + 0x3b8)) {
                *(int *)(p + 0x3bc) = 0;
            }
            if (*(int *)(p + 0x3bc) == 0) {
                return -1;
            }
            PathPtr_GetNode(p + 0x3d8, p + 0x3cc, *(int *)(p + 0x3bc));
            return 1;
        }
    }
    return 0;
}
