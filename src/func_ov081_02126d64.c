extern void func_02038414(char *p);
extern int _ZNK12WithMeshClsn13JustHitGroundEv(char *c);
extern int _ZNK12WithMeshClsn10IsOnGroundEv(char *c);
extern void _ZN12WithMeshClsn15ClearLimMovFlagEv(char *c);
extern void func_ov081_021265c8(char *self);
extern void _ZN5Actor9UpdatePosEP12CylinderClsn(char *self, char *c);
extern void func_ov081_02126758(char *self);
extern void _ZN12CylinderClsn5ClearEv(char *c);
extern void _ZN12CylinderClsn6UpdateEv(char *c);

int func_ov081_02126d64(char *self)
{
    func_02038414(self + 0x1e4);
    *(short *)(self + 0x8c) += 0x1000;
    if (_ZNK12WithMeshClsn13JustHitGroundEv(self + 0x1e4) != 0) {
        *(int *)(self + 0xa8) = *(int *)(self + 0xa8) * -0x3c / 100;
    } else if (_ZNK12WithMeshClsn10IsOnGroundEv(self + 0x1e4) != 0) {
        short v94;
        *(int *)(self + 0xa8) = 0;
        _ZN12WithMeshClsn15ClearLimMovFlagEv(self + 0x1e4);
        v94 = *(short *)(self + 0x94);
        *(short *)(self + 0x8c) = 0;
        *(short *)(self + 0x8e) = v94;
        *(short *)(self + 0x90) = 0;
        func_ov081_021265c8(self);
    }
    _ZN5Actor9UpdatePosEP12CylinderClsn(self, self + 0x1b0);
    func_ov081_02126758(self);
    _ZN12CylinderClsn5ClearEv(self + 0x1b0);
    _ZN12CylinderClsn6UpdateEv(self + 0x1b0);
    return 1;
}
