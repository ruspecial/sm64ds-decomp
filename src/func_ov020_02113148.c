int func_ov020_02113148(int arg0, short *p1, short *p2, int r3, short a5, int a6, short a7)
{
    int A = *p1;
    int B = *p2;
    int t = a6;
    int S;

    *p1 = A + B;
    S = *p1;
    if (S != r3) {
        if ((S - r3) * (A - r3) < 0) {
            int B2 = *p2;
            if (B2 > -a5 && B2 < a5) {
                *p1 = r3;
                *p2 = 0;
                return 1;
            }
        }
    } else if (S >= r3) {
        t = (short)(-a6);
    }

    {
        int prod = (short)*p2 * (short)t;
        if (prod < 0)
            t = (short)t * a7;
        *p2 = *p2 + t;
    }
    return 0;
}
