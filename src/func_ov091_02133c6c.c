extern void Matrix4x3_FromRotationY(void*, short);
extern void Matrix4x3_ApplyInPlaceToRotationX(void*, short);
extern void MulVec3Mat4x3(void*, void*, void*);
extern int _ZNK12WithMeshClsn10IsOnGroundEv(void*);
extern int _ZNK12WithMeshClsn8IsOnWallEv(void*);
extern void _ZN9ActorBase18MarkForDestructionEv(void*);
extern char data_020a0e68[];

int func_ov091_02133c6c(char* c) {
    int v[3];
    short* a = (short*)(((long long)(int)(c + 0x92)) & 0xFFFFFFFFFFFFFFFFLL);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0x1e000;
    *a = *a - 0x80;
    Matrix4x3_FromRotationY((void*)data_020a0e68, *(short*)(c + 0x94));
    Matrix4x3_ApplyInPlaceToRotationX((void*)data_020a0e68, *(short*)(c + 0x92));
    MulVec3Mat4x3((void*)v, (void*)data_020a0e68, (void*)(c + 0xa4));
    if (*(unsigned short*)(c + 0x100) == 0
        || _ZNK12WithMeshClsn10IsOnGroundEv(c + 0x144) != 0
        || _ZNK12WithMeshClsn8IsOnWallEv(c + 0x144) != 0
        || (*(int*)(c + 0xb0) & 8))
        _ZN9ActorBase18MarkForDestructionEv(c);
    return 1;
}
