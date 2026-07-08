typedef struct Node Node;

struct Node {
    char _pad0[0x8];
    int field8;
    unsigned int fieldC;
    char _pad10[0x2C - 0x10];
    int field2C;
    int field30;
};

extern int func_0205cdf4(Node *node, int a, int b, int c);

int func_0205d568(Node *node, int b, int c, int d)
{
    if (&b == (int *)0) {
        return -1;
    }
    if (&c == (int *)0) {
        return -1;
    }
    if (b == 0) {
        return 0;
    }
    node->field8 = b;
    node->field2C = b;
    node->field30 = c;
    if (func_0205cdf4(node, 6, c, b) == 0) {
        return 0;
    }
    node->fieldC |= 0x10;
    node->fieldC &= ~0x20;
    return 1;
}
