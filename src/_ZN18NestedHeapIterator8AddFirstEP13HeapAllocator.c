struct HeapAllocator;
extern void _ZN18NestedHeapIterator4InitEP13HeapAllocator(char* it, char* a);
void _ZN18NestedHeapIterator8AddFirstEP13HeapAllocator(char* it, char* a) {
    unsigned short* cnt;
    int ofs;
    if (*(char**)it == 0) { _ZN18NestedHeapIterator4InitEP13HeapAllocator(it, a); return; }
    ofs = *(unsigned short*)(it + 0xa);
    *(int*)(a + ofs) = 0;
    *(int*)(a + ofs + 4) = *(int*)it;
    *(int*)(*(char**)it + *(volatile unsigned short*)(it + 0xa)) = (int)a;
    *(char**)it = a;
    cnt = (unsigned short*)(((long long)(int)(it + 8)) & 0xFFFFFFFFFFFFFFFFLL);
    *cnt = *cnt + 1;
}
