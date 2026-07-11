// NONMATCHING: pure register-coloring wall (div=6). All instructions match;
// o (c+0x300) colors r3 vs r2 and the laundered decrement ptr (c+0x3c6, same
// addr as o->f) colors r2 vs r3. Pool-loaded launder always claims the low
// register; resists decl-order/launder/spelling permutation.
struct S300 { char pad[0xc6]; unsigned short f; };
extern int IsOnWall(void* thiz);
extern void* GetWallResult(void* thiz);
extern void CopyNormalTo(void* thiz, void* v);
extern short ReflectAngle(void* thiz, int a, int b, short c);
extern void func_ov062_02118004(void* c, int a1);
extern void func_ov062_02117994(char* c, int idx);
extern int WillHitFrame(void* thiz, int f);
extern void func_ov062_021175c0(void* c);
extern int Finished(void* thiz);

void func_ov062_02118a50(char* c){
  if (*(int*)(c+0x98) != 0) {
    if (IsOnWall(c+0x144)) {
      void* sr = GetWallResult(c+0x144);
      CopyNormalTo((char*)sr+4, c+0xe0);
      *(short*)(c+0x94) = ReflectAngle(c, *(int*)(c+0xe0), *(int*)(c+0xe8), *(short*)(c+0x94));
    }
    func_ov062_02118004(c, 0x4cc);
    return;
  }
  struct S300* o = (struct S300*)(c+0x300);
  if (o->f != 0) {
    unsigned short* t = (unsigned short*)(((long long)(int)(c+0x3c6)) & 0xFFFFFFFFFFFFFFFFLL); *t = *t - 1;
    if (o->f != 0) return;
    func_ov062_02117994(c, 8);
    return;
  }
  if (WillHitFrame(c+0x350, 0x1e)) {
    func_ov062_021175c0(c);
  }
  if (Finished(c+0x350) == 0) return;
  *(int*)(c+0x38c) = 1;
  func_ov062_02117994(c, 2);
}
