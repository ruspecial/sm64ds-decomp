// NEAR-MISS div=6: two pure coloring/scheduling spots (first 0x460 load uses r0
// vs target r1; preheader mov/ldr order) plus their branch-displacement fallout.
// Logic verified correct vs ROM; decrement + double-load idioms match exactly.
extern void UnloadBlueCoinModel(void);
extern void _ZN13SharedFilePtr7ReleaseEv(void* p);
extern void UnloadSilverStarAndNumber(void);
extern void _ZN8CapEnemy14UnloadCapModelEv(char* c);
extern char* _ZN5Actor10FindWithIDEj(unsigned int id);
extern char data_ov084_02130cf8[];
extern void* data_ov084_02130278[];

int _ZN6Goomba16CleanupResourcesEv(char* c) {
  if (*(int*)(c+0x460) == 2) {
    UnloadBlueCoinModel();
    _ZN13SharedFilePtr7ReleaseEv(data_ov084_02130cf8);
  }
  {
    int i;
    for (i = 0; i < 7; i++) {
      _ZN13SharedFilePtr7ReleaseEv(data_ov084_02130278[i]);
    }
  }
  if ((unsigned char)(*(unsigned char*)(c+0x464) + 0xff) <= 1) {
    UnloadSilverStarAndNumber();
    _ZN8CapEnemy14UnloadCapModelEv(c);
  }
  if (*(int*)(c+0x460) == 3) {
    int id = *(int*)(c+0x43c);
    if (id != 0) {
      char* a = _ZN5Actor10FindWithIDEj(id);
      if (a != 0) {
        unsigned char* p = (unsigned char*)(int)(((long long)(int)(a+0x602)) & 0xFFFFFFFFFFFFFFFFLL);
        (*p)--;
      }
    }
  }
  return 1;
}
