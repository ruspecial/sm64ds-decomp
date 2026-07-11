extern int _ZN5Model8LoadFileER13SharedFilePtr();
extern int _ZN9ModelBase7SetFileEP8BMD_Fileii();
extern int _ZN9Animation8LoadFileER13SharedFilePtr();
extern int _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj();
extern int _ZN11ShadowModel12InitCylinderEv();
extern char data_ov009_02113c20[];
extern char data_ov009_02113c28[];

void _ZN4Bird13InitResourcesEv(char *self)
{
    void *m;
    void *a;
    m = (void *)_ZN5Model8LoadFileER13SharedFilePtr(data_ov009_02113c20);
    _ZN9ModelBase7SetFileEP8BMD_Fileii(self + 0xd4, m, 1, 1);
    a = (void *)_ZN9Animation8LoadFileER13SharedFilePtr(data_ov009_02113c28);
    _ZN9ModelAnim7SetAnimEP8BCA_Filei5Fix12IiEj(self + 0xd4, a, 0, 0x1000, 0);
    _ZN11ShadowModel12InitCylinderEv(self + 0x138);
    *(int *)(((long long)(int)(self + 0x60)) & 0xFFFFFFFFFFFFFFFFLL) += 0xa000;
    *(int *)(self + 0x9c) = 0;
    *(int *)(self + 0xa0) = -0x32000;
    *(unsigned char *)(self + 0x180) = 1;
    *(int *)(self + 0x178) = *(int *)(self + 4);
    *(int *)(self + 0x160) = *(int *)(self + 0x5c);
    *(int *)(self + 0x164) = *(int *)(self + 0x60);
    *(int *)(self + 0x168) = *(int *)(self + 0x64);
    *(int *)(self + 0x17c) = 0;
}
