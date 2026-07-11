typedef struct {
    char pad0[4];
    int field_4;
    int field_8;
    unsigned short short_c;
    unsigned char flag_e;
    unsigned char flag_f;
    unsigned char flag_10;
    char pad11[3];
} Entry;

extern Entry data_ov006_02142044[];

void func_ov006_020ea71c(void) {
    int i;
    for (i = 0; i < 16; i++) {
        Entry *e = &data_ov006_02142044[i];
        if (e->flag_e != 0) {
            if (e->field_4 > 0xb8000)
                e->field_4 = 0xb8000;
            if (e->flag_10 == 0) {
                if (e->short_c != 0) {
                    unsigned short *psc = (unsigned short *)(((long long)(int)((char *)e + 0xc)) & 0xFFFFFFFFFFFFFFFFLL);
                    int *pf4 = (int *)(((long long)(int)((char *)e + 4)) & 0xFFFFFFFFFFFFFFFFLL);
                    int *pf8 = (int *)(((long long)(int)((char *)e + 8)) & 0xFFFFFFFFFFFFFFFFLL);
                    *psc -= 1;
                    if ((short)e->short_c < 0)
                        e->short_c = 0;
                    *pf4 += e->field_8;
                    *pf8 += 0x100;
                } else {
                    unsigned char *pf10 = (unsigned char *)(((long long)(int)((char *)e + 0x10)) & 0xFFFFFFFFFFFFFFFFLL);
                    e->short_c = 0x40;
                    *pf10 += 1;
                }
            } else {
                if (e->short_c != 0) {
                    unsigned short *psc = (unsigned short *)(((long long)(int)((char *)e + 0xc)) & 0xFFFFFFFFFFFFFFFFLL);
                    *psc -= 1;
                    if ((short)e->short_c < 0)
                        e->short_c = 0;
                } else {
                    e->short_c = 0;
                    e->flag_e = 0;
                    e->flag_f = 0;
                }
            }
        }
    }
}
