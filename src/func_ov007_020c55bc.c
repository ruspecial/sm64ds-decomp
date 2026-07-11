typedef struct { int x, y, z; } V3;

struct Elem { int _0; int count; };

struct Self {
    int _0[2];
    int f8;
    int _c[8];
    V3 **f2c;
    int _30;
    int ***f34;
    int _38;
    struct Elem **f3c;
    int _40[15];
    int f7c;
    int f80;
};

void func_ov007_020c55bc(struct Self *self, int m1, int m2) {
    int i, j;
    for (i = 0; i < self->f8; i++) {
        for (j = 0; j < self->f3c[i]->count; j++) {
            int dx = self->f7c - self->f2c[i][j].x;
            int dy = self->f80 - self->f2c[i][j].y;
            int *p = self->f34[i][j];
            p[3] = (int)(((long long)m1 * dx + 0x800) >> 12);
            p[4] = (int)(((long long)m2 * dy + 0x800) >> 12);
        }
    }
}
