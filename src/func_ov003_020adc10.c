/* func_ov003_020adc10 @ 0x020adc10 (ov003, size 0x64)
 * Allocate + construct a 0x54-byte ActorBase-derived object: new, ctor,
 * install intermediate vtables, set flag bits 1|4 at +0x13, install final
 * vtable, return the object.
 */
extern char data_0208e4b8[];
extern char data_02092680[];
extern char data_ov003_020b1650[];

extern void *_ZN9ActorBasenwEj(unsigned int);
extern void _ZN9ActorBaseC1Ev(void *);

void *func_ov003_020adc10(void)
{
    char *p = (char *)_ZN9ActorBasenwEj(0x54);
    if (p != 0) {
        _ZN9ActorBaseC1Ev(p);
        *(char **)p = data_0208e4b8;
        *(char **)p = data_02092680;
        *(unsigned char *)(((long long)(int)(p + 0x13)) & 0xFFFFFFFFFFFFFFFFLL) |= 1;
        *(unsigned char *)(((long long)(int)(p + 0x13)) & 0xFFFFFFFFFFFFFFFFLL) |= 4;
        *(char **)p = data_ov003_020b1650;
    }
    return p;
}
