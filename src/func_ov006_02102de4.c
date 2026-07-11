typedef unsigned char u8;
typedef unsigned short u16;

extern int data_ov006_021389ec[];
extern int data_ov006_02138d08[];
extern void func_ov004_020afdd0(int a0, int a1, int a2, int a3, int a4);
extern void func_ov004_020aff38(int a0, int a1, int a2, int a3, int a4, int a5, int a6);

void func_ov006_02102de4(char* self)
{
    char (*rows)[0x40] = (char (*)[0x40])self;
    int i;
    for (i = 0; i < 0x30; i++) {
        if (*(u8*)(rows[i] + 0x469a) != 0) {
            int sel = *(u8*)(rows[i] + 0x469c);
            int x = *(int*)(rows[i] + 0x4660) >> 12;
            int y = *(int*)(rows[i] + 0x4664) >> 12;
            if (sel != 0) {
                func_ov004_020afdd0(data_ov006_02138d08[sel - 1], x, y, -1, -1);
            } else {
                func_ov004_020aff38(data_ov006_021389ec[0], x, y, -1, -1, 0x1000, *(u16*)(rows[i] + 0x4690));
            }
        }
    }
}
