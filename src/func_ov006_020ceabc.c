typedef struct { int x, y, z; } Vec3;

extern void func_020731dc(int a, int b, void** node);
extern void func_0203cc28(int* p, int angle);
extern void Quaternion_FromVector3(int* q, Vec3* axis, Vec3* v);
extern void func_ov006_020ce0ac(void* c);
extern int func_020072c0(void);

extern int data_ov006_0214081c;
extern Vec3 data_ov006_021408a8;
extern void* data_ov006_0214089c;
extern int data_02092768[4];
extern int data_020a0ebc[3];

void func_ov006_020ceabc(char* c, Vec3* arg1, Vec3* arg2, short arg3, short arg4)
{
    if (!(data_ov006_0214081c & 1)) {
        data_ov006_021408a8.x = 0;
        data_ov006_021408a8.y = 0x1000;
        data_ov006_021408a8.z = 0;
        func_020731dc((int)&data_ov006_021408a8, (int)&func_020072c0, (void**)&data_ov006_0214089c);
        data_ov006_0214081c |= 1;
    }

    *(int*)(c + 8) = arg1->x;
    *(int*)(c + 0xc) = arg1->y;
    *(int*)(c + 0x10) = arg1->z;
    *(int*)(c + 0x38) = arg2->x;
    *(int*)(c + 0x3c) = arg2->y;
    *(int*)(c + 0x40) = arg2->z;
    *(int*)(c + 0x44) = *(int*)(c + 0x38);
    *(int*)(c + 0x48) = *(int*)(c + 0x3c);
    *(int*)(c + 0x4c) = *(int*)(c + 0x40);
    func_0203cc28((int*)(c + 0x44), -0x4000);

    *(int*)(c + 0x14) = *(int*)(c + 8);
    *(int*)(c + 0x18) = *(int*)(c + 0xc);
    *(int*)(c + 0x1c) = *(int*)(c + 0x10);
    *(int*)(c + 0x20) = *(int*)(c + 0x14);
    *(int*)(c + 0x24) = *(int*)(c + 0x18);
    *(int*)(c + 0x28) = *(int*)(c + 0x1c);
    *(int*)(c + 0x50) = *(int*)(c + 0x38);
    *(int*)(c + 0x54) = *(int*)(c + 0x3c);
    *(int*)(c + 0x58) = *(int*)(c + 0x40);
    *(int*)(c + 0x5c) = *(int*)(c + 0x44);
    *(int*)(c + 0x60) = *(int*)(c + 0x48);
    *(int*)(c + 0x64) = *(int*)(c + 0x4c);
    *(int*)(c + 0x74) = data_02092768[0];
    *(int*)(c + 0x78) = data_02092768[1];
    *(int*)(c + 0x7c) = data_02092768[2];
    *(int*)(c + 0x80) = data_02092768[3];
    Quaternion_FromVector3((int*)(c + 0x74), &data_ov006_021408a8, (Vec3*)(c + 0x38));

    *(short*)(c + 0x96) = arg3;
    *(short*)(c + 0x98) = arg4;
    *(int*)(c + 0x84) = 1;

    switch (*(short*)(c + 0x96)) {
    case 0:
        *(void**)(c + 0x190) = (void*)(c + 0xa0);
        break;
    case 1:
        *(void**)(c + 0x190) = (void*)(c + 0xf0);
        break;
    case 2:
        *(void**)(c + 0x190) = (void*)(c + 0x140);
        break;
    default:
        break;
    }

    *(int*)(c + 0x68) = data_020a0ebc[0];
    *(int*)(c + 0x6c) = data_020a0ebc[1];
    *(int*)(c + 0x70) = data_020a0ebc[2];
    *(int*)(c + 0x88) = 0;
    *(short*)(c + 0x92) = 0x5a;
    func_ov006_020ce0ac(c);
}
