// NONMATCHING: 0x64/0x66 overlay IDs are pooled (ldr) in ROM, not mov; mwcc
// 1.2/sp2p3 always emits mov for these encodable immediates. Also a 3-insn
// r0/r1 coloring diff in the flag test. Logic verified vs ROM.
typedef unsigned int u32;
extern int LoadArchive(int idx);
extern void func_0201a458(void);
extern void *_ZN4Heap10SetDefaultEv(void);
extern void *HeapUse(void *h);
extern void LoadTextNarcs(void);
extern void func_0201a5f8(int);
extern void LoadOverlay(int id);
extern void *func_0201a3e4(void);

extern u32 data_020a0c60;
extern void *data_020a0c5c;

void func_02034fbc(void)
{
    LoadArchive(0);
    func_0201a458();
    if (!(data_020a0c60 & 1)) {
        data_020a0c5c = _ZN4Heap10SetDefaultEv();
        data_020a0c60 |= 1;
    }
    LoadTextNarcs();
    LoadArchive(1);
    HeapUse(data_020a0c5c);
    func_0201a5f8(6);
    LoadOverlay(0x64);
    LoadOverlay(0x66);
    data_020a0c5c = HeapUse(func_0201a3e4());
    LoadArchive(7);
    HeapUse(data_020a0c5c);
}
