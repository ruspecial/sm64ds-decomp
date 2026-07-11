//cpp
extern "C" {
extern int func_ov002_020ec654(unsigned char *p);
extern void func_ov002_020edca4(char *self);
extern void *_ZN5Actor4NextEPKS_(const void *prev);
extern int Vec3_Dist(const void *a, const void *b);

#pragma opt_strength_reduction off
int func_ov002_020edb3c(char *self, int a1, int best)
{
    char *found;
    char *actor;
    int matched;
    int b;

    if (*(unsigned char *)(self + 0x41c) >= 5) {
        if (func_ov002_020ec654((unsigned char *)self) == 0) {
            func_ov002_020edca4(self);
        }
        return 0;
    }

    found = 0;
    actor = (char *)_ZN5Actor4NextEPKS_(0);
    if (actor == 0) goto end;

loop:
    if (actor == self) goto next;
    if (actor == *(char **)(self + 0x38c)) goto next;
    b = (*(int *)(actor + 0xb0) & 0x10000000) != 0;
    if (!b) goto next;
    b = (*(int *)(actor + 0xb0) & 8) != 0;
    if (b) goto next;
    matched = 0;
    for (int i = 0; i < 5; i++) {
        if (*(int *)(actor + 4) == *(int *)(self + (i << 2) + 0x3fc)) matched = 1;
    }
    if (matched != 0) goto next;
    if (func_ov002_020ec654((unsigned char *)self) != 0) {
        if ((*(int (**)(char *))(*(char **)actor + 0x50))(actor) == 0) goto next;
    }
    {
        int d = Vec3_Dist(self + 0x5c, actor + 0x5c);
        if (d < best) {
            best = d;
            found = actor;
        }
    }
next:
    actor = (char *)_ZN5Actor4NextEPKS_(actor);
    if (actor != 0) goto loop;

end:
    if (found != 0) {
        int idx = *(unsigned char *)(self + 0x41c);
        *(int *)(self + (idx << 2) + 0x3fc) = *(int *)(found + 4);
        *(int *)(self + 0x410) = *(int *)(found + 4);
        *(unsigned char *)(((long long)(int)(self + 0x41c)) & 0xffffffffffffffffLL) += 1;
    }
    return (int)found;
}
}
