extern void *_ZN5Model8LoadFileER13SharedFilePtr(void *filePtr);
extern void _ZN9ModelBase7SetFileEP8BMD_Fileii(void *self, void *file, int a, int b);
extern void func_ov013_02111430(void *c);

extern void *data_ov013_021116b0[];

int func_ov013_021115cc(void *c)
{
    unsigned char *pc = (unsigned char *)c;
    void *file;
    int eq = (*(unsigned short *)(pc + 0xc) == 0x125);

    *(pc + 0x124) = eq ? 0 : 1;
    file = _ZN5Model8LoadFileER13SharedFilePtr(data_ov013_021116b0[*(pc + 0x124)]);
    _ZN9ModelBase7SetFileEP8BMD_Fileii(pc + 0xd4, file, 1, -1);
    func_ov013_02111430(c);
    return 1;
}
