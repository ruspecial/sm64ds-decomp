//cpp
typedef unsigned short u16;
typedef unsigned int u32;

struct Matrix2x2 {
    int m0, m1, m2, m3;
};

struct G2x {
    static void SetBGyAffine(volatile u16 *dst, Matrix2x2 *m, int px, int py, int cx, int cy);
};

void G2x::SetBGyAffine(volatile u16 *dst, Matrix2x2 *m, int px, int py, int cx, int cy) {
    u32 *d = (u32 *)dst;
    int a0 = (m->m0 << 12) >> 16;
    int a1 = (m->m1 << 12) >> 16;
    d[0] = (u16)a0 | ((u32)(u16)a1 << 16);
    int a2 = (m->m2 << 12) >> 16;
    int a3 = (m->m3 << 12) >> 16;
    d[1] = (u16)a2 | ((u32)(u16)a3 << 16);
    int dy = cy - py;
    int dx = cx - px;
    int nx = m->m0 * dx + m->m1 * dy + (px << 12);
    int ny = m->m2 * dx + m->m3 * dy + (py << 12);
    d[2] = nx >> 4;
    d[3] = ny >> 4;
}
