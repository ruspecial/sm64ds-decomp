// NONMATCHING: register-coloring near-miss (div=3). Only the entry cnt load
// differs: ROM loads cnt into r2 and computes cnt-1 into r0 (reserving r0 for
// the later ClosestPlayer return); mwcc loads cnt into r0 and decrements in
// place. Allocation heuristic, not steerable from source.
struct Vec3 { int x, y, z; };
extern void* ClosestPlayer(void);
extern int Vec3_Dist(struct Vec3* a, struct Vec3* b);
extern int StartTalk(void* thiz, void* ref, int b);
extern void* FindWithActorID(unsigned id, void* p);
extern short Vec3_HorzAngle(struct Vec3* a, struct Vec3* b);

void func_ov062_0211a9c4(char* c){
  unsigned short* hp = (unsigned short*)(c+0x100);
  unsigned short cnt = *hp;
  if (cnt != 0) { *hp = cnt - 1; return; }
  *(void**)(c+0x398) = ClosestPlayer();
  void* p = *(void**)(c+0x398);
  if (p == 0) return;
  struct Vec3* sp = (struct Vec3*)(((long long)(int)((char*)p + 0x5c)) & 0xFFFFFFFFFFFFFFFFLL);
  struct Vec3 v;
  v.x = sp->x;
  v.y = sp->y;
  v.z = sp->z;
  if (Vec3_Dist((struct Vec3*)(c+0x5c), &v) >= 0xc8000) return;
  if (StartTalk(*(void**)(c+0x398), c, 1) == 0) return;
  char* a = (char*)FindWithActorID(0xcd, 0);
  if (a == 0) return;
  *(int*)(c+0x394) = *(int*)(a+4);
  *(unsigned char*)(a+0x16e) = 0;
  *(int*)(c+0x38c) = 1;
  *(short*)(c+0x3a8) = Vec3_HorzAngle((struct Vec3*)(c+0x5c), &v);
  *(unsigned char*)(c+0x390) = 0;
}
