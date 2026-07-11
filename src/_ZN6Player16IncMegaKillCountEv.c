struct Vec3 { int x, y, z; };
extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int a, void* v);
extern void GiveLives(int delta);
extern void* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(unsigned int id, unsigned int p, struct Vec3* pos, void* rot, int a, int b);
extern void func_ov002_020f0e54(char* a, char* b);
void _ZN6Player16IncMegaKillCountEv(char* c){
  struct Vec3 v;
  char* a;
  char* st;
  int y;
  if(*(unsigned char*)(c+0x703) == 0) return;
  ++*(unsigned short*)(int)(((long long)(int)(c+0x6d0)) & 0xFFFFFFFFFFFFFFFFLL);
  if(*(unsigned short*)(c+0x600+0xd0) >= 8){
    *(unsigned short*)(c+0x600+0xd0) = 8;
    _ZN5Sound9PlayBank3EjRK7Vector3(0x6e, c+0x74);
    GiveLives(1);
  }
  v.x = *(int*)(c+0x5c);
  y = *(int*)(c+0x60);
  v.y = y;
  v.z = *(int*)(c+0x64);
  v.y = y + 0x190000;
  a = (char*)_ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(0x14b, *(unsigned short*)(c+0x600+0xd0), &v, 0, *(signed char*)(c+0xcc), -1);
  if(a == 0) return;
  *(unsigned short*)(a+0x100+0x4c) = 0;
  func_ov002_020f0e54(a, 0);
}
