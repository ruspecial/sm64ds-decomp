typedef unsigned short u16;

extern u16 func_02061960(void);

int func_0206a29c(u16 *self) {
    u16 mask = func_02061960();
    if (mask == 0)
        return 0;
    {
        u16 cur = self[2];
        unsigned int i = 0;
        u16 pos = cur;
        do {
            if (mask & (1 << (pos - 1))) {
                if (cur != pos)
                    self[2] = pos;
                break;
            }
            pos = (pos == 0x10) ? 1 : (pos + 1);
            i++;
        } while (i < 0x10);
    }
    return 1;
}
