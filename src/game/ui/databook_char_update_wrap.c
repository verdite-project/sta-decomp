#include "include_asm.h"
#include "common.h"
#include "m2c.h"
#include "game/ui.h"
#include "game/data.h"
#include "game/save.h"
typedef union { u128 q[2]; u32 w[8]; } Q2;
typedef UiArg Arg;
typedef struct { s32 id; s32 o1; s32 o2; } Ent;
typedef struct { s32 x0; u32 n; s32 x8; s32 xC; Ent e[1]; } Tbl;
typedef struct { s32 x0; s32 x4; u8 x8; u8 pad9[5]; u8 xE; } Ev;
extern Q2 gDatabookCharUpdateWrapData_001F2EC0;
extern u32 gDatabookCharUpdateWrapSbss_00202184;
void DbChar_UpdateWrap_0_00196930(s32 arg0);
void DbChar_Update_0_00196940(Ev *arg0);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void Snd_PlaySe_3_00131600(s32, u8);
Tbl* DbChar_GetCount_0_001958C0(void);
void DbChar_GetListName_1_00196C50(void);
void DbCharProc_Pos_0_00196CB0(void);

/* text_00196330 */
#ifdef NONMATCHING
/* best-effort C: db_char_proc_draw_info.c */
#else
INCLUDE_ASM(DbCharProc_DrawInfo_0_00196330);
#endif

/* DbChar_UpdateWrap_0_00196930 */
/* DbChar_UpdateWrap_0_00196930 */
void DbChar_UpdateWrap_0_00196930(s32 arg0) {
    DbChar_Update_0_00196940((void *) arg0);
}

/* DbChar_Update_0_00196940 */

void DbChar_Update_0_00196940(Ev *arg0) {
    Q2 q;
    Arg a;
    Tbl *t2;
    Ent *e2;
    u32 i2;
    s32 cnt;
    u32 j;
    u32 i;
    Tbl *t;
    Ent *e;
    s32 n;
    s32 k;

    switch (arg0->x0) {
    case 0x19:
        gDatabookCharUpdateWrapBss_004A13E0[0] = 0;
        t = DbChar_GetCount_0_001958C0();
        gDatabookCharUpdateWrapSbss_0020218C = 0;
        e = t->e;
        for (i = 0; i < t->n; i++, e++) {
            if (Bestiary_IsSeen_2_001A9EC0(e->id)) {
                gDatabookCharUpdateWrapBss_004A11A0[gDatabookCharUpdateWrapSbss_0020218C] = e->id;
            } else {
                gDatabookCharUpdateWrapBss_004A11A0[gDatabookCharUpdateWrapSbss_0020218C] = -1;
            }
            gDatabookCharUpdateWrapSbss_0020218C++;
        }
        t2 = DbChar_GetCount_0_001958C0();
        if (t2 == 0) {
            break;
        }
        cnt = 0;
        j = 0;
        e2 = t2->e;
        for (i2 = 0; i2 < t2->n; i2++, e2++) {
            if (Bestiary_IsSeen_2_001A9EC0(e2->id)) {
                cnt++;
            }
            j++;
        }
        gDatabookCharUpdateWrapSbss_00202184 = (u32)(cnt * 100) / j;
        q = gDatabookCharUpdateWrapData_001F2EC0;
        a.p = (s32)gDatabookCharUpdateWrapBss_004A11A0;
        a.fn = DbChar_GetListName_1_00196C50;
        a.f = -3.0f;
        a.cb = DbCharProc_Pos_0_00196CB0;
        a.a = 0;
        a.b = 0;
        a.n = gDatabookCharUpdateWrapSbss_0020218C;
        UiAnim_SetColor_0_0017F890(0, &q, &a);
        UiAnim_SetVisible_1_0017F7C0(0, 1, 0);
        UiAnim_SetTarget_1_0017F470(gDatabookCharUpdateWrapBss_004A13E0[0], 0, 1);
        break;
    case 0x16:
        n = gDatabookCharUpdateWrapBss_004A13E0[0];
        k = n;
        if (arg0->x4 & 0x4000) {
            Snd_PlaySe_3_00131600(0x69, arg0->xE);
            arg0->x8 = 0x18;
            arg0->x4 = 0;
            arg0->x0 = 0x1A;
            UiAnim_SetVisible_1_0017F7C0(0, 0, 1);
            return;
        }
        if (arg0->x4 & 0x10) {
            k = n - 1;
        } else if (arg0->x4 & 0x40) {
            k = n + 1;
        }
        if (gDatabookCharUpdateWrapSbss_0020218C != 0) {
            k = (k + gDatabookCharUpdateWrapSbss_0020218C) % gDatabookCharUpdateWrapSbss_0020218C;
        }
        if (UiAnim_SetTarget_1_0017F470(n, 0, 0)) {
            if (gDatabookCharUpdateWrapBss_004A13E0[0] != k) {
                Snd_PlaySe_3_00131600(0x66, arg0->xE);
            }
            gDatabookCharUpdateWrapBss_004A13E0[0] = k;
        }
        break;
    }
    Ui_LoadCharImage_3_00183B90(gDatabookCharUpdateWrapBss_004A11A0[gDatabookCharUpdateWrapBss_004A13E0[0]]);
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gDatabookCharUpdateWrapSbss_00202184, gDatabookCharUpdateWrapSbss_0020218C */
u32 gDatabookCharUpdateWrapSbss_00202184;
s32 gDatabookCharUpdateWrapSbss_0020218C;
/* data twins (src/game/data/load_menu_bss_004A1120.c): gDatabookCharUpdateWrapBss_004A11A0 */
s32 gDatabookCharUpdateWrapBss_004A11A0[0x80];
/* data twins (src/game/data/load_menu_bss_004A1120.c): gDatabookCharUpdateWrapBss_004A13E0 */
s32 gDatabookCharUpdateWrapBss_004A13E0[0x4];
extern u8 gDatabookCharUpdateWrapData_001F2E80[];
/* data group (src/game/data/databook_item_reset_data.c): D_001F2EC0__grp: gDatabookCharUpdateWrapData_001F2EC0@0x0 */
s32 D_001F2EC0__grp[0x8] __attribute__((aligned(16))) = { 0, 5, 0, (s32)gDatabookCharUpdateWrapData_001F2E80, 7, -0x3fc00000, 0, 0 };
/* data twins (src/game/data/databook_item_reset_data.c): gDatabookCharUpdateWrapData_001F2E80 */
u8 gDatabookCharUpdateWrapData_001F2E80[0x40] = { 0, 0, 0x40, 0xc0, 0xa6, 0xf, 0, 0, 0, 0, 0, 0xc0, 0xa5, 0xf, 0, 0, 0, 0, 0x80, 0xbf, 0xa4, 0xf, 0, 0, 0, 0, 0, 0, 0xa3, 0xf, 0, 0, 0, 0, 0x80, 0x3f, 0xa2, 0xf, 0, 0, 0, 0, 0, 0x40, 0xa1, 0xf, 0, 0, 0, 0, 0x40, 0x40, 0xa0, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
