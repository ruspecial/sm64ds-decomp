//cpp
struct WithMeshClsn;
struct OneUpMushroom;
typedef void (OneUpMushroom::*PMF)();
extern PMF data_ov002_0210dc00[];
extern "C" {
extern int _ZN5Enemy14UpdateYoshiEatER12WithMeshClsn(OneUpMushroom *thiz, WithMeshClsn *clsn);
extern void func_ov002_020af4ec(OneUpMushroom *thiz);
extern void _ZN12CylinderClsn5ClearEv(void *thiz);
extern void _ZN12CylinderClsn6UpdateEv(void *thiz);
}
struct OneUpMushroom { char pad[0x500]; };
extern "C" int _ZN13OneUpMushroom8BehaviorEv(OneUpMushroom *thiz)
{
    char *c = (char *)thiz;
    if (_ZN5Enemy14UpdateYoshiEatER12WithMeshClsn(thiz, (WithMeshClsn *)(c + 0x144)) != 0) {
        func_ov002_020af4ec(thiz);
        _ZN12CylinderClsn5ClearEv(c + 0x110);
        return 1;
    }
    *(int *)(c + 0xd0) = 0;
    {
        int old = *(int *)(c + 0x388);
        (thiz->*data_ov002_0210dc00[*(int *)(c + 0x384)])();
        {
            unsigned short *p100 = (unsigned short *)(c + 0x100);
            unsigned short *p38c = (unsigned short *)(int)(((long long)(int)(c + 0x38c)) & 0xFFFFFFFFFFFFFFFFLL);
            *p100 += 1;
            *p38c += 1;
            if (old != *(int *)(c + 0x388)) {
                *p100 = 0;
                *(unsigned short *)(c + 0x38c) = 0;
            }
        }
    }
    _ZN12CylinderClsn5ClearEv(c + 0x110);
    _ZN12CylinderClsn6UpdateEv(c + 0x110);
    func_ov002_020af4ec(thiz);
    return 1;
}
