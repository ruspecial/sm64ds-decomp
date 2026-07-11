// NONMATCHING: logic verified correct vs ROM. ROM keeps a per-iteration element
// pointer computed as (c+i)+0x53fd with pre-indexed writeback (ldrb [r0,r6]!),
// reused for the 0xff store. mwcc 1.2/sp2p3 instead hoists the loop-invariant
// c+0x53fd and uses base+index addressing; direct/q-split/launder all fail to
// reproduce the writeback idiom. ~28 word div, all cascade from this.
extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);

void func_ov006_020f6904(char *c)
{
    int cntA = 0;
    int cntB = 0;
    int i;
    for (i = 0; i < 8; i++) {
        unsigned char id = *(unsigned char*)(c + 0x53fd + i);
        if (id == 0xff) continue;
        if (*(unsigned char*)(c + id * 24 + 0x51bb) == 0) {
            *(unsigned char*)(c + 0x53fd + i) = 0xff;
        } else if (*(unsigned char*)(c + id * 24 + 0x51bc) == 1) {
            *(unsigned char*)(c + id * 24 + 0x51bc) = 3;
            *(unsigned char*)(c + 0x53fd + i) = 0xff;
            cntB++;
        }
        cntA++;
    }
    if (cntB == 1) _ZN5Sound12PlayBank2_2DEj(0x148);
    else if (cntB == 2) _ZN5Sound12PlayBank2_2DEj(0x145);
    else if (cntB >= 3) _ZN5Sound12PlayBank2_2DEj(0x146);
    if (cntA != 0) return;
    *(int*)(c + 0x53d8) = 6;
    *(short*)(c + 0x53ec) = *(unsigned char*)(c + 0x540a) * 20 + 0x50;
}
