typedef int s32;

struct Node;

extern struct Node *func_0205d23c(void *a, int b);
extern unsigned int _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(unsigned int state);
extern void func_020580f0(int a);
extern int func_0205d5e8(char *self, int a1, int a2, int a3, int a4);
extern void func_0205d3d4(char *a, char *b, int c);
extern void func_02041d28(char *base, char *node, int a);
extern int func_0205d4cc(char *self);
extern void func_02041a94(char *base, char *node);

extern int data_02099e6c;
extern char data_020a1fc0[];
extern char data_020a2400[];

void func_02042254(void) {
    struct Node *node = func_0205d23c(&data_02099e6c, 3);
    int v8 = 2;
    int vc = 3;
    int v10 = 1;
    char *base = (char *)data_020a2400 + 0x2000;

    for (;;) {
        unsigned int irq = _ZN3IRQ7DisableEv();
        char *sb = *(char **)(base + 0x708);

        while (sb == 0) {
            if (*(s32 *)(data_020a1fc0 + 0xc) == 0) {
                _ZN3IRQ7RestoreEj(irq);
                return;
            }
            func_020580f0(0);
            sb = *(char **)(base + 0x708);
        }

        _ZN3IRQ7RestoreEj(irq);

        if (*(s32 *)(sb + 0x7c) == 1) {
            int sl;
            func_0205d5e8(sb + 0x38, (int)node, *(s32 *)(sb + 0x8c),
                          *(s32 *)(sb + 0x8c) + *(s32 *)(sb + 0x90), *(s32 *)(sb + 0x88));
            for (sl = 0; sl < 3; sl++) {
                *(s32 *)(sb + sl * 4 + 0xa0) = sl * 0x400;
                func_0205d3d4(sb + 0x38, sb + 0xc0 + sl * 0x400, 0x400);
            }
            *(s32 *)(sb + 0x94) = 0;
            *(s32 *)(sb + 0x9c) = v8;
            *(s32 *)(sb + 0x98) = vc;
            irq = _ZN3IRQ7DisableEv();
            func_02041d28((char *)data_020a2400, sb, v10);
            _ZN3IRQ7RestoreEj(irq);
        } else {
            func_0205d4cc(sb + 0x38);
            irq = _ZN3IRQ7DisableEv();
            func_02041a94((char *)data_020a2400, sb);
            _ZN3IRQ7RestoreEj(irq);
        }
    }
}
