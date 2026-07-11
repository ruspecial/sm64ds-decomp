extern void _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(int b, void *attr, int x, int y, int a4, int a5, int sx, int sy, int a8, int a9);
extern void *data_ov006_0213a964[];

typedef struct Elem {
    int x;                  // 0x00
    int y;                  // 0x04
    char pad08[0x0e];       // 0x08
    unsigned char flip;     // 0x16
    char pad17[3];          // 0x17
    unsigned char active;   // 0x1a
    unsigned char pal;      // 0x1b
    char pad1c;             // 0x1c
    unsigned char frame;    // 0x1d
    unsigned char anim;     // 0x1e
    char pad1f[5];          // 0x1f..0x23
} Elem;

typedef struct S {
    char pad[0x4660];
    Elem arr[16];
} S;

void func_ov006_0211e72c(S *s) {
    int i = 0;
    do {
        if (s->arr[i].active != 0) {
            int flip = s->arr[i].flip;
            int x = s->arr[i].x;
            int fr = s->arr[i].frame;
            int an = s->arr[i].anim;
            int y = s->arr[i].y;
            int pal = s->arr[i].pal;
            int idx = an * 7 + fr;
            int a9 = -1;
            if (flip != 0) a9 = 1;
            _ZN3OAM6RenderEbP7OamAttriiii5Fix12IiES3_ii(
                1,
                data_ov006_0213a964[idx],
                x >> 12,
                y >> 12,
                -1,
                pal,
                0x1000,
                0x1000,
                0,
                a9);
        }
    } while (++i < 16);
}
