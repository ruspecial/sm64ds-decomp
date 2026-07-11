// NONMATCHING: structural near-miss (66 insns vs 63). Logic verified vs ROM.
// mwcc spills the constant 1 to stack and strength-reduces the cheap i*4
// field-0x168 store into a 3rd induction pointer (ROM keeps it indexed via
// add sl,r8,lsl#2), raising the frame to 0x1c vs 0x14 and shifting bmd to fp
// vs sb. Register-pressure/IV-reduction difference, not steerable from source.
extern char data_ov006_02141e94;
extern char data_ov006_02141e6c;
extern char data_ov006_0213c7f4;
extern void* Model_LoadFile(void* p);
extern void* Animation_LoadFile(void* p);
extern void MaterialChanger_Prepare(void* bmd, void* bma);
extern void ModelBase_SetFile(void* self, void* bmd, int a, int b);
extern void ModelAnim_SetAnim(void* self, void* bca, int a, int f, unsigned u);
extern void MaterialChanger_SetFile(void* self, void* bma, int a, int f, unsigned u);
extern void Model_SetPolygonID(void* self, int id);

struct Model { char pad[0x64]; };
struct MatChg { char pad[0x14]; };

void func_ov006_020e7954(char* self)
{
    void* bmd;
    void* bca;
    struct Model* models = (struct Model*)self;
    struct MatChg* matchg = (struct MatChg*)(self + 0x12c);
    int i;
    *(int*)(self + 0x174) = 0x800;
    bmd = Model_LoadFile(&data_ov006_02141e94);
    bca = Animation_LoadFile(&data_ov006_02141e6c);
    MaterialChanger_Prepare(bmd, &data_ov006_0213c7f4);
    for (i = 0; i < 3; i++) {
        ModelBase_SetFile(&models[i], bmd, 1, -1);
        ModelAnim_SetAnim(&models[i], bca, 0x40000000, *(int*)(self + 0x174), 0);
        MaterialChanger_SetFile(&matchg[i], &data_ov006_0213c7f4, 0x40000000, *(int*)(self + 0x174), 0);
        Model_SetPolygonID(&models[i], (i + 1) & 0xff);
        *(int*)(self + i * 4 + 0x168) = 0;
    }
    *(short*)(self + 0x178) = 0;
    *(short*)(self + 0x17a) = 0;
}
