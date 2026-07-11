/* func_0206a928 - oversized compiled-C MSL-style __pformatter (printf core).
 * Integer / string / char / flag-width-precision path reconstructed from disasm;
 * IEEE-double %e/%f/%g path present as faithful-signature stubs.
 * NOTE: NEAR-MISS. The ~0x1dc-byte stack frame layout (dozens of compiler-assigned
 * slot offsets) and whole-function regalloc/EBB-CSE over ~1240 instructions are not
 * reproducible without the exact upstream MSL source. Best-effort draft only. */

typedef void (*WriteFn)(void *self, const char *buf, int n);

struct Prn {
    char pad[0x10];
    WriteFn write;
};

extern void func_0206c9f4(struct Prn *self, int n);        /* emit n pad chars */
extern int  func_0206ca44(unsigned p);                     /* odd-byte strlen */
extern int  func_0206c93c(int num, int den);               /* signed divide */
extern int  func_0206c8b4(int lo, int hi);                 /* double: exponent test */
extern void func_0206bdb4(void);                           /* double: mul */
extern void func_0206c244(void);                           /* double: helper */
extern void func_0206c51c(void);                           /* double: helper */
extern void func_0206bc8c(void);                           /* double: helper */

extern int data_020a0000;

/* Read one byte from a possibly odd-aligned pointer (DS 16-bit access trick). */
static int rdb(unsigned p)
{
    if (p & 1) return (*(unsigned short *)(p - 1) & 0xff00) >> 8;
    return *(unsigned short *)p & 0xff;
}

static void wrb(unsigned p, int c)
{
    if (p & 1) {
        int h = *(unsigned short *)(p - 1) & 0xff;
        *(unsigned short *)(p - 1) = (unsigned short)(h | ((c & 0xff) << 8));
    } else {
        int h = *(unsigned short *)p & 0xff00;
        *(unsigned short *)p = (unsigned short)(h | (c & 0xff));
    }
}

void func_0206a928(struct Prn *self, const char *format, char **ap)
{
    const char *fmt = format;
    unsigned char buf[0x50];
    int flags;
    int width;
    int prec;
    int radix;
    int c;

    flags = 0;
    width = 0;
    prec = -1;

    for (;;) {
        c = rdb((unsigned)fmt);
        if (c == 0) break;
        fmt++;

        if (c != '%') {
            wrb((unsigned)buf, c);
            self->write(self, (const char *)buf, 1);
            continue;
        }

        /* flags */
        flags = 0;
        width = 0;
        prec = -1;
        for (;;) {
            c = rdb((unsigned)fmt);
            fmt++;
            if (c == '-') { flags |= 4; continue; }
            if (c == '+') { flags |= 1; continue; }
            if (c == ' ') { flags |= 8; continue; }
            if (c == '#') { flags |= 0x10; continue; }
            if (c == '0') { flags |= 2; continue; }
            break;
        }

        /* width */
        while (c >= '0' && c <= '9') {
            if (width < 0) width = 0;
            width = width * 10 + (c - '0');
            c = rdb((unsigned)fmt);
            fmt++;
        }

        /* precision */
        if (c == '.') {
            prec = 0;
            c = rdb((unsigned)fmt);
            fmt++;
            while (c >= '0' && c <= '9') {
                prec = prec * 10 + (c - '0');
                c = rdb((unsigned)fmt);
                fmt++;
            }
        }

        radix = 10;
        switch (c) {
        case 'd':
        case 'i': {
            int v = *(int *)(*ap - 4 + 4);
            *ap += 4;
            v = *(int *)(*ap - 4);
            {
                unsigned char *d = &buf[0x4f];
                int neg = 0;
                if (v < 0) { neg = 1; v = -v; }
                do {
                    int q = func_0206c93c(v, 10);
                    *--d = (unsigned char)('0' + (v - q * 10));
                    v = q;
                } while (v != 0);
                if (neg) *--d = '-';
                self->write(self, (const char *)d, &buf[0x4f] - d + 1);
            }
            break;
        }
        case 'u':
        case 'o':
        case 'x':
        case 'X':
        case 'p': {
            unsigned v;
            *ap += 4;
            v = *(unsigned *)(*ap - 4);
            if (c == 'o') radix = 8;
            else if (c != 'u') radix = 16;
            {
                unsigned char *d = &buf[0x4f];
                do {
                    unsigned q = (unsigned)func_0206c93c((int)v, radix);
                    unsigned dig = v - q * radix;
                    *--d = (unsigned char)(dig < 10 ? '0' + dig : 'a' + dig - 10);
                    v = q;
                } while (v != 0);
                self->write(self, (const char *)d, &buf[0x4f] - d + 1);
            }
            break;
        }
        case 'c': {
            int v;
            *ap += 4;
            v = *(int *)(*ap - 4);
            wrb((unsigned)buf, v);
            self->write(self, (const char *)buf, 1);
            break;
        }
        case 's': {
            const char *s;
            int len;
            *ap += 4;
            s = *(const char **)(*ap - 4);
            if (s == 0) s = (const char *)&data_020a0000;
            len = func_0206ca44((unsigned)s);
            if (!(flags & 4) && len < width)
                func_0206c9f4(self, width - len);
            self->write(self, s, len);
            if ((flags & 4) && len < width)
                func_0206c9f4(self, width - len);
            break;
        }
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            /* IEEE-double path: reads 8 bytes; full decomposition omitted in draft */
            *ap += 8;
            (void)func_0206c8b4(0, 0);
            func_0206bdb4();
            func_0206c244();
            func_0206c51c();
            func_0206bc8c();
            break;
        default:
            break;
        }
    }
}
