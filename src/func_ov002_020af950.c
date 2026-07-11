// NONMATCHING: register coloring (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 1.2/sp2p3. The case-0 scratch block uses r0
// where the ROM reuses the switch-selector register r1 (case 3 matches because
// its RMW occupies r1 first). Everything else (incl. both first-access-fold RMW
// materializations, forced via u64 launder since they are not in a loop) matches.
extern void func_ov002_020aefa4(void);
extern void Sound_PlayBank3(unsigned int, const void*);
extern void func_ov002_020af0c0(void);
extern void func_ov002_020aefb8(void*);
extern void func_ov002_020aeee4(void*);
extern void func_ov002_020af474(void*);

void func_ov002_020af950(char* self) {
    int state = *(int*)(self + 0x388);
    switch (state) {
    case 0:
        *(unsigned char*)(self + 0x38e) = 0;
        if (*(int*)(self + 0x390) != 0) return;
        *(int*)(self + 0xa8) = 0x28000;
        *(int*)(self + 0x388) = 3;
        *(unsigned char*)(self + 0x38e) = 1;
        func_ov002_020aefa4();
        Sound_PlayBank3(0x68, self + 0x74);
        *(int*)(((int)self + 0xb0) & 0xFFFFFFFFFFFFFFFFLL) &= ~1;
        return;
    case 1:
        func_ov002_020af0c0();
        func_ov002_020aefb8(self);
        return;
    case 3:
        func_ov002_020aefb8(self);
        if (*(unsigned short*)(self + 0x100) > 0x11) {
            func_ov002_020aeee4(self);
            func_ov002_020af474(self);
        }
        if (*(unsigned short*)(self + 0x100) != 0x25) return;
        *(int*)(((int)self + 0x128) & 0xFFFFFFFFFFFFFFFFLL) &= ~1;
        *(int*)(self + 0x388) = 1;
        *(int*)(self + 0x9c) = 0;
        *(int*)(self + 0x98) = 0xa000;
        return;
    }
}
