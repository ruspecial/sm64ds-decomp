extern int func_ov074_0212229c();
extern void _ZN13SharedFilePtr7ReleaseEv();
extern void UnloadKeyModels();
extern char data_ov002_0210da30;
extern char data_ov084_02130cf8;
extern void *data_ov074_0212292c[];
extern char data_ov074_02123000;
extern void *data_ov074_02122948[];
extern char data_ov074_02123040;

int _ZN8Goomboss16CleanupResourcesEv(int *c)
{
    int i;
    if (c[2] == 0x1111) {
        return func_ov074_0212229c(c);
    }
    _ZN13SharedFilePtr7ReleaseEv(&data_ov002_0210da30);
    UnloadKeyModels(2);
    _ZN13SharedFilePtr7ReleaseEv(&data_ov084_02130cf8);
    for (i = 0; i < 7; i++)
        _ZN13SharedFilePtr7ReleaseEv(data_ov074_0212292c[i]);
    _ZN13SharedFilePtr7ReleaseEv(&data_ov074_02123000);
    for (i = 0; i < 0xc; i++)
        _ZN13SharedFilePtr7ReleaseEv(data_ov074_02122948[i]);
    _ZN13SharedFilePtr7ReleaseEv(&data_ov074_02123040);
    return 1;
}
