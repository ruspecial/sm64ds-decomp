/* func_02016e70 at 0x02016e70
 *
 * Fetches (or creates) the CommonModelDataEntry for a BMD_File.  When the
 * entry's unk4 slot is empty it allocates unk4 (operator new, 0x14 bytes)
 * and unk8 (Memory::operator_new2), initializing unk4 via func_020462d0.
 * Returns unk4, or 0 on allocation failure.
 */

struct CommonModelDataEntry {
    void *unk0;   /* 0x0 */
    void *unk4;   /* 0x4 */
    void *unk8;   /* 0x8 */
};

extern struct CommonModelDataEntry *_ZN5Model23AddToCommonModelDataArrER8BMD_File(void *bmd);
extern void *_Znwj(unsigned int size);
extern int func_02046564(void *bmd);
extern void *_ZN6Memory13operator_new2Ej(unsigned int size);
extern void _ZN6Memory16operator_delete2EPv(void *ptr);
extern void func_020462d0(void *dst, void *bmd);

void *func_02016e70(void *bmd)
{
    struct CommonModelDataEntry *e = _ZN5Model23AddToCommonModelDataArrER8BMD_File(bmd);

    if (e->unk4 == 0) {
        e->unk4 = _Znwj(0x14);
        if (e->unk4 == 0)
            return 0;

        e->unk8 = _ZN6Memory13operator_new2Ej((unsigned int)func_02046564(bmd));
        if (e->unk8 == 0) {
            _ZN6Memory16operator_delete2EPv(e->unk4);
            e->unk4 = 0;
            return 0;
        }

        func_020462d0(e->unk4, bmd);
    }

    return e->unk4;
}
