#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/ui.h"
#include "game/math.h"
#include "game/save.h"
typedef union { u32 w; u8 b[4]; } Col;
#ifndef NONMATCHING
extern char D_001FD358[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): D_001FD358 */
static char D_001FD358[0x10] __attribute__((aligned(8))) = { -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, -0x7f, 0x48, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
extern s32 *D_00201D3C;
#ifndef NONMATCHING
extern f32 D_00201D40;
#else
/* data twins (src/game/data/sdata.c): D_00201D40 */
static f32 D_00201D40 = -2.99f;
#endif
char* DbChar_GetListName_1_00196C50(s32 i);
void DbCharProc_Pos_0_00196CB0(s32 arg0, void *arg1, void *arg2);
void DbChar_CalcStatBars_0_00196D10(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
void DbItem_Draw_0_00196E20(u8 *arg0);
char* DbChar_GetName_0_00195970(s32 i);
void memset(void *, s32, s32);
s32 DbItem_FindA_1_0019D4A0(s32);
void Text_Draw_2_001875C0(s32, s32, u32, f32, f32, f32);

/* DbChar_GetListName_1_00196C50 */
/* DbChar_GetListName_1_00196C50 */
/* DbChar_GetListName_1_00196C50 */
char *DbChar_GetListName_1_00196C50(s32 i)
{
    if (i < 0)
        return D_001FD358;
    if (Bestiary_IsSeen_2_001A9EC0(i))
        return DbChar_GetName_0_00195970(i);
    return D_001FD358;
}

/* DbCharProc_Pos_0_00196CB0 */
void DbCharProc_Pos_0_00196CB0(s32 arg0, void *arg1, void *arg2) {
    void *sp4C;

    UiAnim_Get_1_0017F840(0, &sp4C);
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) (M2C_FIELD(arg2, f32 *, 8) - (f32) arg0);
}

/* DbChar_CalcStatBars_0_00196D10 */
void DbChar_CalcStatBars_0_00196D10(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    memset(arg1, 0, 0x10);
    memset(arg0, 0, 0x10);
    memset(arg3, 0, 0x10);
    memset(arg2, 0, 0x10);
    if (arg4 != NULL) {
        M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg4, u16 *, 8);
        M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg4, u16 *, 0xA);
        M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg4, u16 *, 0xC);
        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg4, u16 *, 0xE);
        M2C_FIELD(arg0, u16 *, 8) = (u16) M2C_FIELD(arg4, u16 *, 0x10);
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(arg4, u16 *, 0x12);
        M2C_FIELD(arg0, u16 *, 0xC) = (u16) M2C_FIELD(arg4, u16 *, 0x14);
        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg4, u16 *, 0x16);
        M2C_FIELD(arg1, u16 *, 0) = (u16) M2C_FIELD(arg4, u16 *, 0x18);
        M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg4, u16 *, 0x1A);
        M2C_FIELD(arg1, u16 *, 4) = (u16) M2C_FIELD(arg4, u16 *, 0x1C);
        M2C_FIELD(arg1, u16 *, 6) = (u16) M2C_FIELD(arg4, u16 *, 0x1E);
        M2C_FIELD(arg1, u16 *, 8) = (u16) M2C_FIELD(arg4, u16 *, 0x20);
        M2C_FIELD(arg1, u16 *, 0xA) = (u16) M2C_FIELD(arg4, u16 *, 0x22);
    }
}

/* DbItem_Draw_0_00196E20 */
void DbItem_Draw_0_00196E20(u8 *arg0) {
    Col c;
    s32 h;

    Menu_SetFlags_0_0018A310(0xE);
    if (arg0[8] == 0x1B) {
        D_00201D40 = Approachf_3_00187770(D_00201D40, -0.02f, 3.5f);
    } else {
        D_00201D40 = Approachf_3_00187770(D_00201D40, -2.99f, 3.5f);
    }
    h = DbItem_FindA_1_0019D4A0(D_00201D3C[D_004A1430[0]]);
    c.w = 0x80FFFFFF;
    c.b[3] = D_004A1440[0];
    Text_Draw_2_001875C0(h, 2, c.w, 622.0f, 17.0f, 1.0f);
    UiAnim_UpdateAll_1_0017F5C0();
    if (!(D_00201D40 <= -2.99f)) {
        DbItem_DrawRing_0_00197130(D_00201D3C[D_004A1430[0]], D_00201D40);
        DbItem_DrawStats_0_00196F90(D_00201D40);
    }
}
