#include "common.h"
typedef struct { char pad[0x1C]; void *p; } Obj_Res_Free_0_0014DC10;
typedef struct { s32 x0; s32 x4; s32 x8; char pc[0x10]; s32 x1c; char x20[0x14]; s32 x34; } Obj_Res_Open_0_0014DC70;
extern s32 gGameMainSbss_00201E94;
void Res_ReleaseHandle_0_0014DC00(void *arg0);
s32 Res_Free_0_0014DC10(Obj_Res_Free_0_0014DC10 *o);
void Res_Read_1_0014DC50(void *arg0);
s32 Res_Open_0_0014DC70(Obj_Res_Open_0_0014DC70 *o, s32 a);
void File_Close_2_0015AB80(void *p);
s32 File_HashName_3_00159D10(s32 a);
s32 Arc_FindByHash_2_0015ABD0(s32 a);
s32 File_GetOffset_0_0015A350(s32 a);
void File_GetSize_1_0015A2F0(s32 a, void *b);

/* Res_ReleaseHandle_0_0014DC00 */
void Res_ReleaseHandle_0_0014DC00(void *arg0) {
    File_WaitRead_1_0015A3A0(M2C_FIELD(arg0, void **, 0x1C), 0);
}

/* Res_Free_0_0014DC10 */
s32 Res_Free_0_0014DC10(Obj_Res_Free_0_0014DC10 *o)
{
    if (o->p)
        File_Close_2_0015AB80(o->p);
    o->p = NULL;
    return 1;
}

/* Res_Read_1_0014DC50 */
void Res_Read_1_0014DC50(void *arg0) {
    File_Read_2_0015A470(M2C_FIELD(arg0, void **, 0x1C), M2C_FIELD(arg0, s32 **, 0x14), 0x80000, 0);
}

/* Res_Open_0_0014DC70 */
s32 Res_Open_0_0014DC70(Obj_Res_Open_0_0014DC70 *o, s32 a)
{
    s32 h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(a));
    o->x1c = h;
    o->x4 = File_GetOffset_0_0015A350(h);
    o->x8 = o->x4;
    o->x34 = gGameMainSbss_00201E94;
    File_GetSize_1_0015A2F0(o->x1c, o->x20);
    return 1;
}
