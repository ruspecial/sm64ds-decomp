typedef short s16;
typedef unsigned short u16;

extern s16 data_ov006_02141fd0;
extern u16 data_ov006_02141fdc[];
extern u16 data_ov006_02141fd4;
extern u16 data_ov006_02141ff8[];
extern int data_0209e650;
extern int RandomIntInternal(int *seed);

void func_ov006_020ebc7c(int arg0, int arg1) {
    int found = 0;
    int i;
    int v;
    int j;
    s16 count = data_ov006_02141fd0;
    for (i = 0; i < count; i++) {
        if (arg0 == data_ov006_02141fdc[i]) {
            found = 1;
            break;
        }
    }
    v = (unsigned short)(arg1 & RandomIntInternal(&data_0209e650));
    v = found ? (data_ov006_02141fd4 | (v & 0xf0)) : v;
    for (j = 0; j < arg0; j++) {
        if (v == data_ov006_02141ff8[j]) {
            v = (unsigned short)(arg1 & RandomIntInternal(&data_0209e650));
            v = found ? (data_ov006_02141fd4 | (v & 0xf0)) : v;
            j = -1;
        }
    }
    data_ov006_02141ff8[arg0] = v;
}
