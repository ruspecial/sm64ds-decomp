extern int _ZN5Sound12PlayBank2_2DEj();
extern unsigned char data_ov006_0212efd4[];

typedef struct Elem {
    int word0;              // 0x00
    short pad04;            // 0x04
    unsigned short cnt;     // 0x06
    unsigned short h08;     // 0x08
    short pad0a;            // 0x0a
    unsigned char b0c;      // 0x0c
    unsigned char pad0d;    // 0x0d
    unsigned char b0e;      // 0x0e
    unsigned char pad0f;    // 0x0f
    unsigned char pad10;    // 0x10
    unsigned char b11;      // 0x11
    unsigned char pad12[0xe]; // 0x12..0x1f
} Elem;

typedef struct S {
    char pad[0x4bac];
    Elem arr[2];
} S;

void func_ov006_0211dad0(S *s, int i) {
    s->arr[i].cnt++;
    if (s->arr[i].cnt < 8) {
        return;
    }
    s->arr[i].cnt = 0;
    s->arr[i].b11++;
    if (s->arr[i].b11 < 8) {
        s->arr[i].b0c = data_ov006_0212efd4[s->arr[i].b11];
        return;
    }
    s->arr[i].b11 = 0;
    s->arr[i].b0c = 0;
    s->arr[i].b0e = 3;
    s->arr[i].h08 = 0;
    s->arr[i].word0 = 0x1000;
    _ZN5Sound12PlayBank2_2DEj(0x1f9);
}
