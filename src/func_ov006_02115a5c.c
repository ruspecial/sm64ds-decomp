extern void func_ov006_02115830(char *self, int i, int j, int a, int b);

void func_ov006_02115a5c(char *self)
{
    int i, j;

    for (i = 0; i < *(int *)(self + 0x4668); i++) {
        for (j = 0; j < *(int *)(self + 0x4668); j++) {
            int a = (i < 0xd) ? *(int *)(self + i * 4 + 0x4688) : 0;
            int b = (j < 0xd) ? ((int *)(self + 0x4688))[j] : 0;
            func_ov006_02115830(self, i, j, a, b);
        }
    }
}
