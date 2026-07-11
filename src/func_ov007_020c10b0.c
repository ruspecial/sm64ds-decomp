struct N {
    char pad34[0x34];
    struct N* owner;   /* 0x34 */
    struct N* head;    /* 0x38 */
    struct N* next;    /* 0x3c */
};

void func_ov007_020c10b0(struct N* a, struct N* b) {
    struct N* nx;
    b->owner = a;
    if (a->head == 0) {
        a->head = b;
        return;
    }
    nx = a->head->next;
    a = a->head;
    while (nx != 0) {
        a = nx;
        nx = nx->next;
    }
    a->next = b;
}
