typedef struct { int n; char *p; } Q;

void func_02057d30(Q *q, signed char *src, int count)
{
    unsigned int c;
    int i;
    if (count <= 0) return;
    c = (unsigned int)q->n;
    if (c > (unsigned int)count) c = (unsigned int)count;
    for (i = 0; (unsigned int)i < c; i++)
        q->p[i] = src[i];
    q->n -= c;
    q->p += count;
}
