extern void _ZN5Sound12PlayBank2_2DEj(unsigned int);
extern void func_ov004_020b0aa0(int arg);
extern void func_ov004_020ae20c(void);
extern void func_ov004_020b0a54(void* c);
extern unsigned char data_020a0e40[];
extern unsigned char data_020a0de8[];
extern unsigned char data_020a0de9[];

void func_ov006_020de0e0(char* self)
{
  int flag;
  unsigned int idx;
  if (*(int*)(self + 0x51cc) == 0) return;
  *(int*)(int)(((long long)(int)(self + 0x51cc)) & 0xFFFFFFFFFFFFFFFFLL) -= 1;
  idx = data_020a0e40[0];
  flag = 0;
  if (data_020a0de8[idx * 4] != 0) {
    if (data_020a0de9[idx * 4] != 0) flag = 1;
  }
  if (flag != 0 && *(int*)(self + 0x51cc) <= 0x80) {
    *(int*)(self + 0x51cc) = 0;
    _ZN5Sound12PlayBank2_2DEj(0x62);
  } else {
    *(int*)(self + 0x51cc) = 0x80;
  }
  if (*(int*)(self + 0x51cc) > 0) return;
  *(int*)(self + 0x51cc) = 0;
  if (*(unsigned char*)(self + 0x51df) != 0) {
    func_ov004_020b0aa0(6);
    func_ov004_020ae20c();
  }
  func_ov004_020b0a54((void*)0x10);
  *(unsigned char*)(self + 0xc3) = 0;
}
