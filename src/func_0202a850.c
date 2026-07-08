// NONMATCHING: 9/9 instrs byte-identical; only a pure-scheduling swap remains -
// ROM computes `sub ip,r0,#0x64000` before `str r1,[r2]`, mwccarm emits it after.
// Store order is exact; no statement/temp reorder flips the scheduler (known wall).
extern volatile int data_02092138;
extern volatile int data_0209212c;

void func_0202a850(int a, int b)
{
    data_02092138 = a;
    data_0209212c = b;
    data_02092138 = a - 0x64000;
    data_0209212c = b + 0x64000;
}
