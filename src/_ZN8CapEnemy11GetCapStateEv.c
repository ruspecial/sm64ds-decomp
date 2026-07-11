extern char data_0209f2d8;
extern int *_ZN5Actor13ClosestPlayerEv();

int _ZN8CapEnemy11GetCapStateEv(char *self)
{
    unsigned char val;
    int check;
    unsigned int b;
    int tmp;
    unsigned char *p2;

    if (*(unsigned char *)(self + 0x111) == 0) {
        return 2;
    }
    val = *(unsigned char *)&data_0209f2d8;
    check = 1;
    if (val != 1) check = 0;
    if (check == 0) {
        int *p = _ZN5Actor13ClosestPlayerEv(self);
        if (p != 0) {
            if ((*(unsigned char *)(self + 0x113) & 7) == p[2]) {
                return 0;
            }
        }
    }
    b = *(unsigned char *)(self + 0x17f);
    b = (b << 0x1e) >> 0x1f;
    if (b == 0) {
        return 0;
    }
    *(unsigned char *)(self + 0x111) = 0;
    p2 = (unsigned char *)(((long long)(int)(self + 0x113)) & 0xFFFFFFFFFFFFFFFFLL);
    tmp = *(int *)(self + 0xf4);
    *(int *)(self + 0xb0) = tmp;
    *p2 = *p2 & 7;
    return 1;
}
