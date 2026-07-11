typedef signed int s32;
typedef unsigned int u32;

extern int SDK_AUTOLOAD_DTCM_START[];
extern int SDK_SYS_STACKSIZE;
extern int SDK_IRQ_STACKSIZE;
extern int SDK_SECTION_ARENA_DTCM_START[];

void *func_02058df4(u32 id)
{
    switch (id) {
    case 0:
        return (void *)0x023c0000;
    case 2:
        return (void *)0x02700000;
    case 3:
        return (void *)0x02000000;
    case 4:
    {
        u32 lo = (u32)SDK_AUTOLOAD_DTCM_START;
        u32 irqStackLo = (lo + 0x3f80) - (s32)&SDK_IRQ_STACKSIZE;
        s32 sysStackSize = (s32)&SDK_SYS_STACKSIZE;
        if (sysStackSize == 0) {
            sysStackSize = (s32)SDK_SECTION_ARENA_DTCM_START;
            if (lo < (u32)sysStackSize) {
                lo = (u32)sysStackSize;
            }
            return (void *)lo;
        }
        if (sysStackSize < 0) {
            return (void *)(lo - sysStackSize);
        }
        return (void *)(irqStackLo - sysStackSize);
    }
    case 5:
        return (void *)0x027ff800;
    case 6:
        return (void *)0x037f8000;
    default:
        return 0;
    }
}
