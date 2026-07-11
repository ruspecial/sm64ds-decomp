// NEAR-MISS (div 14): every instruction matches; the sole divergence is a stable
// register rotation of three callee-saved values in the digit loop -- the shared
// constant 0, the &b[4] cursor pc, and the old-count oldc map to {r5,r6,r7} in a
// different permutation than the ROM (ROM: pc=r5, 0=r6, oldc=r7; we get 0=r5,
// oldc=r6, pc=r7). Immune to decl order, stmt order, zero-store order, pointer
// vs index digit form, ull divisor, and increment spelling. Pure-coloring wall.
void func_02071510(unsigned char* b, unsigned long long value)
{
    unsigned char* start;
    unsigned char* end;

    b[0] = 0;
    b[4] = 0;
    if (value != 0) {
        unsigned char* pc = b + 4;
        do {
            unsigned int oldc = b[4];
            *pc = *pc + 1;
            b[5 + oldc] = (unsigned char)(value % 10);
            value /= 10;
        } while (value != 0);
    }

    start = b + 5;
    end = start + b[4] - 1;
    while (start < end) {
        unsigned char t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }

    *(unsigned short*)(b + 2) = b[4] - 1;
}
