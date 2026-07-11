typedef unsigned char u8;

struct Obj {
  char pad00[0x14];
  int f14;       // 0x14
  int f18;       // 0x18
  int f1c;       // 0x1c
  u8 buf[0x40];  // 0x20
  int f60;       // 0x60
  int f64;       // 0x64
};

extern void func_0205e3d4(struct Obj*);

int func_0205e6e4(struct Obj* obj, u8* p, int count) {
  if (count == 0) return 0;
  if (obj == 0 || p == 0) return 1;
  if (obj->f60 != 0) { obj->f64 = 3; return 3; }
  if (obj->f64 != 0) return obj->f64;
  goto test;

body:
  // NOTE: 49/63 instructions match. Remaining divergence = the three RMW
  // increments (f1c/f14/f18) where the ROM materializes `add r1,r6,#off;
  // ldr [r1]; add; str [r1]` inline each iteration. This is the
  // FIRST-ACCESS-FOLD wall: word-width RMW, encodable offset, address never
  // passed as a value -> C either folds to direct [base,#off] (this form) or,
  // if laundered to force materialization, mwcc hoists it out of the loop.
  obj->buf[obj->f1c] = *p;
  obj->f1c++;
  obj->f14 += 8;
  if (obj->f14 == 0) {
    obj->f18++;
    if (obj->f18 == 0) obj->f64 = 1;
  }
  if (obj->f1c == 0x40) func_0205e3d4(obj);
  p++;

test:
  if (count-- == 0) return 0;
  if (obj->f64 != 0) return 0;
  goto body;
}
