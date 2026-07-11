typedef struct B3 {
    unsigned char b0, b1, b2;
} B3;

typedef union BufU {
    B3 s;
    unsigned char a[3];
} BufU;

extern B3 data_02099f80;

int func_020457f0(int a, int b, int c, int d, int *e)
{
    BufU buf;
    int i, i1;
    int n, p, frac, w;

    if (d == 0)
        return e[0];
    if (c == 0)
        return e[b];

    a -= 1;
    a >>= c;
    a <<= c;
    i = b >> c;
    if (b >= a) {
        a = b - a;
        a += i;
        return e[a];
    }

    i1 = i + 1;
    n = e[i1];
    p = e[i];
    buf.s = data_02099f80;
    frac = b - (i << c);
    w = buf.a[c] - frac;
    if (frac != 0)
        p = (p * w + n * frac) >> c;
    return p;
}
