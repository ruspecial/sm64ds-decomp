extern void func_02038420(void *p);
extern int func_02037e38(unsigned int *p);
extern void func_ov071_0211f498(char *c);
extern void func_ov071_021202ec(char *c, int x);
extern void func_ov071_0211f29c(char *c);
extern int WithMeshClsn_JustHitGround(void *p);
extern void *WithMeshClsn_GetFloorResult(void *p);
extern int WithMeshClsn_IsOnGround(void *p);
extern void WithMeshClsn_ClearLimMovFlag(void *p);
extern void Actor_UpdatePos(void *self, void *c);
extern void CylinderClsn2_Clear(void *p);
extern void CylinderClsn2_Update(void *p);

int func_ov071_0211f7d4(void *self)
{
    char *s = (char*)self;
    func_02038420(s + 0x194);
    *(short*)(s + 0x8c) = *(short*)(s + 0x8c) + 0x1000;
    if (WithMeshClsn_JustHitGround(s + 0x194)) {
        if (func_02037e38((unsigned int*)((char*)WithMeshClsn_GetFloorResult(s + 0x194) + 4)) == 4) {
            func_ov071_0211f498(s);
        } else {
            *(int*)(s + 0xa8) = (*(int*)(s + 0xa8) * -0x3c) / 0x64;
        }
    } else {
        if (WithMeshClsn_IsOnGround(s + 0x194)) {
            short v94;
            *(int*)(s + 0xa8) = 0;
            WithMeshClsn_ClearLimMovFlag(s + 0x194);
            *(int*)(((long long)(int)(s + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) |= 1;
            v94 = *(short*)(s + 0x94);
            *(short*)(s + 0x8c) = 0;
            *(short*)(s + 0x8e) = v94;
            *(short*)(s + 0x90) = 0;
            func_ov071_021202ec(s, 2);
        }
    }
    Actor_UpdatePos(self, s + 0x160);
    func_ov071_0211f29c(s);
    CylinderClsn2_Clear(s + 0x160);
    CylinderClsn2_Update(s + 0x160);
    return 1;
}
