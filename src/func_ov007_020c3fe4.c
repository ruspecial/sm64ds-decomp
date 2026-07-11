typedef struct Sub {
    int x;      // 0x00
    int y;      // 0x04
    int flag;   // 0x08
} Sub;

typedef struct Obj {
    Sub *sub;           // 0x00
    char pad04[6];      // 0x04..0x09
    unsigned char b;    // 0x0a
} Obj;

void func_ov007_020c3fe4(Obj *p) {
    unsigned char b = p->b;
    int x = p->sub->x >> 12;
    int y = p->sub->y >> 12;
    int visible = 0;
    int inx = 0;
    int flag;
    if (-b <= x) inx = x <= b + 0xff;
    if (inx) {
        if (-b <= y) {
            if (y <= b + 0xbf) visible = 1;
        }
    }
    flag = p->sub->flag;
    if ((flag == 0 && visible) || (flag != 0 && !visible)) {
        p->sub->flag = (flag == 0);
    }
}
