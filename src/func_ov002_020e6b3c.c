struct A {
    char pad[0x24];
    unsigned int count;
};

struct B {
    char pad[0x1c];
    int idx;
    char pad2[0x10];
};

struct Outer {
    char pad[8];
    struct A *a;
    struct B *b;
};

void func_ov002_020e6b3c(struct Outer *o) {
    void **p = (void **)(((long long)(int)((char *)o + 8)) & 0xFFFFFFFFFFFFFFFFLL);
    struct A *a = (struct A *)p[0];
    struct B *b = (struct B *)p[1];
    unsigned int i;
    unsigned int n = a->count;
    for (i = 0; i < n; b++) {
        b->idx = i++;
    }
}
