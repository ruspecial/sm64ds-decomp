//cpp
// NEAR-MISS: logic verified vs ROM. mwccarm 1.2/sp2p3 does not reproduce the
// by-value Fix12 argument stack-home (sub sp,#0x10 + 3 spilled stores that are
// never reloaded) from any struct/int form tried; register-passing gives 0x64,
// struct-by-value gives 0x80. Hand to permuter.
typedef int Fix12i;
extern "C" {
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int a, Fix12i x, Fix12i y, Fix12i z);
extern void func_02012694(int a, void* b);
extern char* data_0209f318;

int func_ov002_020b9450(char* actor){
  _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x102, *(Fix12i*)(actor+0x5c), *(Fix12i*)(actor+0x60)+0x82000, *(Fix12i*)(actor+0x64));
  func_02012694(0x7d, actor+0x74);
  *(int*)(actor+0x3c4) = 0;
  *(short*)(actor+0x8e) = *(short*)(data_0209f318 + 0x17c);
  *(unsigned char*)(actor+0x3cb) = 0x1b;
  return 1;
}
}
