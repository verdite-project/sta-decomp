#include "common.h"
#include "m2c.h"
#include "game/core.h"
#include "game/data.h"
#include "game/gfx.h"
#include "game/save.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/math.h"
typedef struct { char pad[0x40]; char sub[0x210]; } E_MenuLayout_GetSub_1_00189020;
typedef struct { char pad[0x250]; } E_MenuLayout_Get_1_00189050;
typedef struct { s32 pad0; s32 a0; u8 pad8[0x28]; } Item;
typedef struct { u32 n; Item *items; } Grp;
typedef struct { s32 idx; u8 pad4[0x3C]; } Ent_Menu_FreeSystemRes_0_00189080;
typedef struct { u32 n; Ent_Menu_FreeSystemRes_0_00189080 *e; } List;
typedef struct { s32 n; u8 *p; } Hdr;
typedef struct { s32 n; u8 *p; } Ent_Menu_LoadLayout_0_00189740;
typedef struct { Hdr *x[16]; Ent_Menu_LoadLayout_0_00189740 e[64]; u8 **a; s32 pad; u32 n; } Tbl;
typedef struct { s32 f0; s32 f4; u64 f8; u8 pad[0x28]; } E_MenuLayout_BindTextures_0_00189D50;
typedef struct { u32 n; E_MenuLayout_BindTextures_0_00189D50 *e; } T;
typedef struct { u32 idx; u8 pad[0x3C]; } I;
typedef struct { u32 n; I *i; } A;
typedef struct { u8 b[4]; } Buf;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } B_Menu_Draw_1_00189F40;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } B_Pause_Update_0_0018A650;
typedef struct { u8 pad[0x14]; B_Pause_Update_0_0018A650 x14; } Arg;
extern s32 gMenuSbss_002020DC;
extern u32 D_004A01D8[];
extern s32 D_004A01DC[];
extern u32 D_0049FF88[];
extern u32 D_0049FD38[];
extern s32 D_004A08C4[];
extern s32 D_0049FD3C[];
extern s32 D_0049FF8C[];
extern s32 D_004A08CC[];
extern u32 D_0049FAE8[];
extern s32 D_0049FAEC[];
extern u32 D_004A0428[];
extern s32 D_004A042C[];
extern u32 D_004A0678[];
extern s32 D_004A067C[];
extern M2C_UNK gMenuData_001F27B0[];
extern M2C_UNK gMenuData_001F27C0[];
extern B_Menu_Draw_1_00189F40 D_004A0B34[];
extern u8 D_004A0B2A[];
extern s8 gMenuBss_004A0B2C[];
extern s32 D_004A0AE8[];
extern s32 D_004A0AEC[];
extern s8 gMenuBss_004A0B20[];
extern void (*gMenuData_001F2930[])(void *);
extern void (*gMenuData_001F2880[])(void *);
extern u8 D_004A0B2B[];
extern void (*gMenuData_001F27D0[])(void *);
extern u8 gMenuBss_004A0B28[];
extern s8 D_004A0B2F[];
extern s8 D_004A0B29[];
extern s8 D_004A0B2E[];
extern s32 gMenuBss_004A0B30[];
#ifndef NONMATCHING
extern volatile u32 gMenuBss_004A0B0C[];
extern s32 gMenuSbss_002020E8;
extern s32 gMenuSbss_002020E0;
extern s32 gMenuBss_00497B60[];
extern f32 gMenuBss_004A0B10[];
extern f32 gMenuBss_004A0B14[];
extern f32 gMenuBss_004A0B18[];
extern f32 gMenuBss_004A0B1C[];
extern s32 gMenuSdata_00201CF0;
extern f32 gMenuSbss_0020210C;
extern f32 gMenuSbss_00202110;
extern f32 gMenuSbss_00202114;
extern s32 gMenuBss_004A0B24[];
extern s32 gMenuSbss_002020F0;
extern s32 gMenuSdata_00201CF4;
extern f32 gMenuSbss_002020D8;
extern f32 gMenuSbss_00202108;
extern f32 gMenuData_001F29E0[];
extern f32 gMenuData_001F29E4[];
extern f32 gMenuData_001F29E8[];
extern f32 gMenuData_001F29EC[];
extern f32 gMenuSbss_00202104;
extern s64 gMenuSbss_002020F8;
extern s32 gMenuSbss_00202100;
#else
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B0C */
static volatile u32 gMenuBss_004A0B0C[0x1];
/* data twins (src/game/data/sbss.c): gMenuSbss_002020E8 */
static s32 gMenuSbss_002020E8;
/* data twins (src/game/data/sbss.c): gMenuSbss_002020E0 */
static s32 gMenuSbss_002020E0;
/* data twins (src/game/data/ui_gauge_bss.c): gMenuBss_00497B60 */
static s32 gMenuBss_00497B60[0x8];
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B10 */
static f32 gMenuBss_004A0B10[0x1];
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B14 */
static f32 gMenuBss_004A0B14[0x1];
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B18 */
static f32 gMenuBss_004A0B18[0x1];
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B1C */
static f32 gMenuBss_004A0B1C[0x1];
/* data twins (src/game/data/sdata.c): gMenuSdata_00201CF0 */
static s32 gMenuSdata_00201CF0 = -1;
/* data twins (src/game/data/sbss.c): gMenuSbss_0020210C */
static f32 gMenuSbss_0020210C;
/* data twins (src/game/data/sbss.c): gMenuSbss_00202110 */
static f32 gMenuSbss_00202110;
/* data twins (src/game/data/sbss.c): gMenuSbss_00202114 */
static f32 gMenuSbss_00202114;
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B24 */
static s32 gMenuBss_004A0B24[0x1];
/* data twins (src/game/data/sbss.c): gMenuSbss_002020F0 */
static s32 gMenuSbss_002020F0;
/* data twins (src/game/data/sdata.c): gMenuSdata_00201CF4 */
static s32 gMenuSdata_00201CF4 = -1;
/* data twins (src/game/data/sbss.c): gMenuSbss_002020D8 */
static f32 gMenuSbss_002020D8;
/* data twins (src/game/data/sbss.c): gMenuSbss_00202108 */
static f32 gMenuSbss_00202108;
/* data twins (src/game/data/menu_draw_wrap_data.c): gMenuData_001F29E0 */
static f32 gMenuData_001F29E0[0x1] = { -2.89f };
/* data twins (src/game/data/menu_draw_wrap_data.c): gMenuData_001F29E4 */
static f32 gMenuData_001F29E4[0x1] = { -2.89f };
/* data twins (src/game/data/menu_draw_wrap_data.c): gMenuData_001F29E8 */
static f32 gMenuData_001F29E8[0x1] = { -2.89f };
/* data twins (src/game/data/menu_draw_wrap_data.c): gMenuData_001F29EC */
static f32 gMenuData_001F29EC[0x1] = { -2.89f };
/* data twins (src/game/data/sbss.c): gMenuSbss_00202104 */
static f32 gMenuSbss_00202104;
/* data twins (src/game/data/sbss.c): gMenuSbss_002020F8 */
static s64 gMenuSbss_002020F8;
/* data twins (src/game/data/sbss.c): gMenuSbss_00202100 */
static s32 gMenuSbss_00202100;
#endif
extern u16 gMenuBss_00317230[];
extern u16 gMapCommandBss_00317238[];
extern u16 D_0031723A[];
s32* Save_GetSlotInfo_0_00188FF0(void);
s32* Menu_GetStateBuf_0_00189000(s32 arg0);
void* MenuLayout_GetSub_1_00189020(s32 i);
E_MenuLayout_Get_1_00189050* MenuLayout_Get_1_00189050(s32 i);
void Menu_FreeSystemRes_0_00189080(void);
void Menu_FreeRes_0_00189270(void);
void Menu_LoadLayout_0_00189740(Tbl *t, u64 key);
void Menu_LoadGameRes_0_00189AD0(s32 *arg0);
s32 MenuLayout_BindTextures_0_00189D50(A *a, T *t, s32 k);
void MenuStack_Clear_1_00189E90(void);
s32 MenuStack_Pop_1_00189EA0(void);
void Camera_SetShake_0_00189F00(void *arg0);
void Menu_Draw_1_00189F40(void);
void Menu_Update_1_0018A200(void);
u8 Menu_GetMode_1_0018A320(void);
void Menu_SetSubMode_0_0018A330(s8 arg0);
void Menu_Open_1_0018A350(s8 arg0);
void Menu_SetParam_0_0018A410(s32 arg0);
void Menu_HandleEvent_0_0018A420(s32 *a0);
void Menu_DrawSlider_0_0018A580(s32 arg0, f32 *arg1, f32 min, f32 max, f32 step);
void Pause_Update_0_0018A650(Arg *arg0);
void Menu_UpdateFades_1_0018A910(void);
void Menu_WaitLoad_0_0018AAD0(s32 *arg0);
void Pool_Free_2_00128580(s32, s32);
void Tex_Release_1_00177570(s32);
void Arc_LoadFile_2_00159DD0(s32, s32, s32 *, s32 *);
void Ui_SetGlobalFlag_0_00182990(s32 *);
void Msg_SetParam_0_0018AEA0(s32 *);
void ImageLoader_SetFlag_0_001E1760(s32 *);
s32 Tex_Find_1_00177AF0(u64, s32);
s32 Tex_FindByHash_1_00177B20(u64);
void Ui_DrawSpriteRotated_1_00182080(f32, s32, void *, void *, void *, s32);
void GsPkt_SetReg_3_001543E0(s32, s32);
void Menu_DrawHelpText_1_001DD700(s32, s8);
void Menu_SaveOptions_1_0018E460(void);
void Menu_RestoreOptions_1_0018E450(void);
void Equip_Reset_0_00199170(s32 *);
void Hud_Reset_0_0019A7E0(s32 *);
void ItemMenu_Reset_0_0019DF80(s32 *);
void GameOver_Reset_0_0019E8A0(s32 *);
void Save_ParseOptions_1_001A8B90(s32);
void Save_ParseOptionsB_0_001A8F00(s32);
f32 fabsf(f32);

/* .bss from 0x00497B80, defined from the top down (CodeWarrior writes
   uninitialised objects in reverse order) */
s16 D_004A0AF0[0xe];
s32 D_004A0AE0[0x4];      /* also D_004A0AE8, D_004A0AEC */
u8 D_004A0950[0x190];
u8 D_004A0900[0x50];
u32 D_004A08C8[0xe] __attribute__((aligned(8)));
u8 D_004A06C0[0x208];      /* also D_004A08C4 */
s32 D_004A0680[0x10];
s32 D_004A0674[0x3] __attribute__((aligned(4)));      /* also D_004A0678, D_004A067C */
s32 D_004A0470[0x81];
s32 D_004A0430[0x10];
s32 D_004A0424[0x3] __attribute__((aligned(4)));      /* also D_004A0428, D_004A042C */
s32 D_004A0220[0x81];
s32 D_004A01E0[0x10];
s32 D_004A01D4[0x3] __attribute__((aligned(4)));      /* also D_004A01D8, D_004A01DC */
u8 D_0049FFD0[0x204];
s32 D_0049FF90[0x10];
s32 D_0049FF84[0x3] __attribute__((aligned(4)));      /* also D_0049FF88, D_0049FF8C */
u8 D_0049FD80[0x204];
s32 D_0049FD40[0x10];
s32 D_0049FD34[0x3] __attribute__((aligned(4)));      /* also D_0049FD38, D_0049FD3C */
u8 D_0049FB30[0x204];
s32 D_0049FAF0[0x10];
s32 D_0049FAE4[0x3] __attribute__((aligned(4)));      /* also D_0049FAE8, D_0049FAEC */
s32 D_0049F8E0[0x81];
/* 0x0049F8E0..0x004A06C0 is six 0x250-byte records, likely one
   struct { u8 buf[0x204]; s32 a; u32 b; s32 c; s32 d[0x10]; } [6]
   (buf at +0, a/b/c at +0x204, d at +0x210); the code still names each
   field of each record, so the objects stay separate until it is
   rewritten to index the records. */
u8 D_0049F8A0[0x40];
s32 D_00497C80[0x1f08];
s32 D_00497B80[0x40];

/* Menu_ResetTimers_0_00188F80 */
void Menu_ResetTimers_0_00188F80(void)
{
    gMenuBss_004A0B0C[0] = 60;
    gHudDrawSbss_002020D4 += 60.0f / gMenuBss_004A0B0C[0];
    Menu_Update_1_0018A200();
}

/* Save_GetSlotInfo_0_00188FF0 */
s32 *Save_GetSlotInfo_0_00188FF0(void) {
    return &gMenuSbss_002020E8;
}

/* Menu_GetStateBuf_0_00189000 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */

s32 *Menu_GetStateBuf_0_00189000(s32 arg0) {
    if (arg0 != 0) {
        return D_00497B80;
    }
    return D_00497C80;
}

/* MenuLayout_GetSub_1_00189020 */
#define D_0049F8A0 D_0049F8A0__as_MenuLayout_GetSub_1_00189020
extern E_MenuLayout_GetSub_1_00189020 D_0049F8A0__as_MenuLayout_GetSub_1_00189020[];

void *MenuLayout_GetSub_1_00189020(s32 i)
{
    return D_0049F8A0[i].sub;
}
#undef D_0049F8A0

/* MenuLayout_Get_1_00189050 */
#define D_0049F8A0 D_0049F8A0__as_MenuLayout_Get_1_00189050
extern E_MenuLayout_Get_1_00189050 D_0049F8A0__as_MenuLayout_Get_1_00189050[];

E_MenuLayout_Get_1_00189050 *MenuLayout_Get_1_00189050(s32 i)
{
    return &D_0049F8A0[i];
}
#undef D_0049F8A0

/* Menu_FreeSystemRes_0_00189080 */

void Menu_FreeSystemRes_0_00189080(void) {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;

    i = 0;
    if (i < D_004A01D8[0]) {
        pl = D_0049F8A0;
        grps = D_0049FFD0;
        do {
            l = pl[0x1BC];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            Tex_Release_1_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_004A01D8[0]);
    }
    Pool_Free_2_00128580(gMenuSbss_002020DC, D_004A01D4[0]);
}

/* Menu_LoadSystemRes_0_001891C0 */
#define MenuLayout_BindTextures_0_00189D50 MenuLayout_BindTextures_0_00189D50__as_Menu_LoadSystemRes_0_001891C0
void MenuLayout_BindTextures_0_00189D50__as_Menu_LoadSystemRes_0_001891C0(s32, s32 *, s32);
void Menu_LoadSystemRes_0_001891C0(void) {
    u32 i;
    s32 *pl;
    s32 *g;
    s32 a;
    s32 b;
    a = 0;
    b = 0;
    Arc_LoadFile_2_00159DD0(0x45E87010, gMenuSbss_002020DC, &a, &b);
    i = 0;
    if (i < D_004A01D8[0]) {
        pl = D_0049F8A0;
        g = D_0049FFD0;
        do {
            MenuLayout_BindTextures_0_00189D50(pl[0x1BC], g, a);
            i++;
            pl++;
        } while (i < D_004A01D8[0]);
    }
    D_004A01D4[0] = a;
    D_004A01DC[0] = b;
}
#undef MenuLayout_BindTextures_0_00189D50

/* Menu_FreeRes_0_00189270 */

void Menu_FreeRes_0_00189270(void) {

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_0049FF88[0]) {
        pl = D_0049F8A0;
        grps = D_0049FD80;
        do {
            l = pl[0x128];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            Tex_Release_1_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_0049FF88[0]);
    }
    }
    Pool_Free_2_00128580(gMenuSbss_002020DC, D_0049FF84[0]);

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_0049FD38[0]) {
        pl = D_0049F8A0;
        grps = D_0049FB30;
        do {
            l = pl[0x94];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            Tex_Release_1_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_0049FD38[0]);
    }
    }
    Pool_Free_2_00128580(gMenuSbss_002020DC, D_0049FD34[0]);

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_004A08C8[0]) {
        pl = D_0049F8A0;
        grps = D_004A06C0;
        do {
            l = pl[0x378];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            Tex_Release_1_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_004A08C8[0]);
    }
    }
    Pool_Free_2_00128580(gMenuSbss_002020DC, D_004A08C4[0]);
}

/* Menu_LoadTitleRes_0_00189580 */
#define gMenuSbss_002020DC gMenuSbss_002020DC__as_Menu_LoadTitleRes_0_00189580
extern s32 *gMenuSbss_002020DC__as_Menu_LoadTitleRes_0_00189580;
#define Arc_LoadFile_2_00159DD0 Arc_LoadFile_2_00159DD0__as_Menu_LoadTitleRes_0_00189580
void Arc_LoadFile_2_00159DD0__as_Menu_LoadTitleRes_0_00189580(s32, s32 *, s32 *, s32 *);
#define MenuLayout_BindTextures_0_00189D50 MenuLayout_BindTextures_0_00189D50__as_Menu_LoadTitleRes_0_00189580
void MenuLayout_BindTextures_0_00189D50__as_Menu_LoadTitleRes_0_00189580(s32, s32 *, s32);

void Menu_LoadTitleRes_0_00189580(void) {
    s32 a; s32 b; s32 c; s32 d; s32 e; s32 f;
    u32 i; s32 *p; s32 *q;
    a = 0; b = 0;
    Arc_LoadFile_2_00159DD0(0x0EBC6141, gMenuSbss_002020DC, &a, &b);
    i = 0; if (i < D_0049FF88[0]) { p = D_0049F8A0; q = D_0049FD80; do { MenuLayout_BindTextures_0_00189D50(p[0x128], q, a); i++; p++; } while (i < D_0049FF88[0]); }
    c = 0; d = 0;
    D_0049FF84[0] = a; D_0049FF8C[0] = b;
    Arc_LoadFile_2_00159DD0(0xF732041D, gMenuSbss_002020DC, &c, &d);
    i = 0; if (i < D_0049FD38[0]) { p = D_0049F8A0; q = D_0049FB30; do { MenuLayout_BindTextures_0_00189D50(p[0x94], q, c); i++; p++; } while (i < D_0049FD38[0]); }
    e = 0; f = 0;
    D_0049FD34[0] = c; D_0049FD3C[0] = d;
    Arc_LoadFile_2_00159DD0(0x90BC19D0, gMenuSbss_002020DC, &e, &f);
    i = 0; if (i < D_004A08C8[0]) { p = D_0049F8A0; q = D_004A06C0; do { MenuLayout_BindTextures_0_00189D50(p[0x378], q, e); i++; p++; } while (i < D_004A08C8[0]); }
    D_004A08C4[0] = e; D_004A08CC[0] = f;
}
#undef Arc_LoadFile_2_00159DD0
#undef MenuLayout_BindTextures_0_00189D50
#undef gMenuSbss_002020DC

/* Menu_LoadLayout_0_00189740 */
#define gMenuSbss_002020DC gMenuSbss_002020DC__as_Menu_LoadLayout_0_00189740
extern s32 *gMenuSbss_002020DC__as_Menu_LoadLayout_0_00189740;
#define Arc_LoadFile_2_00159DD0 Arc_LoadFile_2_00159DD0__as_Menu_LoadLayout_0_00189740
void Arc_LoadFile_2_00159DD0__as_Menu_LoadLayout_0_00189740(s32, s32 *, u8 ***, s32 *);

static inline u8 *hdr2(Tbl *t, u32 j, u8 *p) { u8 *q; t->x[j] = (Hdr *)p; q = p + 0x10; t->x[j]->p = q; return q + t->x[j]->n * 0x40; }
void Menu_LoadLayout_0_00189740(Tbl *t, u64 key) {
    s32 b;
    u8 **a;
    u32 i;
    u32 n;
    u8 *p; u32 j; u32 m;
    b = 0;
    a = 0;
    Arc_LoadFile_2_00159DD0((s32)key, gMenuSbss_002020DC, &a, &b);
    p = *a;
    n = *(u32 *)p;
    p += 0x10;
    for (i = 0; i < n; i++) {
        t->e[i].n = *(s32 *)p;
        t->e[i].p = p + 0x10;
        p += t->e[i].n * 0x30 + 0x10;
    }
    m = *(u32 *)p;
    p += 0x10;
    for (j = 0; j < m; j++) {
p = hdr2(t, j, p);
    }
    t->n = m;
    t->a = a;
}
#undef Arc_LoadFile_2_00159DD0
#undef gMenuSbss_002020DC

/* Menu_LoadGameRes_0_00189AD0 */
#define gMenuSbss_002020DC gMenuSbss_002020DC__as_Menu_LoadGameRes_0_00189AD0
extern s32 *gMenuSbss_002020DC__as_Menu_LoadGameRes_0_00189AD0;
#define Arc_LoadFile_2_00159DD0 Arc_LoadFile_2_00159DD0__as_Menu_LoadGameRes_0_00189AD0
void Arc_LoadFile_2_00159DD0__as_Menu_LoadGameRes_0_00189AD0(s32, s32 *, s32 *, s32 *);
#define MenuLayout_BindTextures_0_00189D50 MenuLayout_BindTextures_0_00189D50__as_Menu_LoadGameRes_0_00189AD0
void MenuLayout_BindTextures_0_00189D50__as_Menu_LoadGameRes_0_00189AD0(s32, s32 *, s32);
#define Menu_SetParam_0_0018A410 Menu_SetParam_0_0018A410__as_Menu_LoadGameRes_0_00189AD0
void Menu_SetParam_0_0018A410__as_Menu_LoadGameRes_0_00189AD0(s32 *);

void Menu_LoadGameRes_0_00189AD0(s32 *arg0) {
    s32 a; s32 b; s32 c; s32 d; s32 e; s32 f;
    u32 i; s32 *p; s32 *r; s32 *q; u32 j;
    gMenuSbss_002020DC = arg0;
    Menu_LoadLayout_0_00189740(D_0049F8A0, 0x13BCC6E4);
    a = 0; b = 0;
    Arc_LoadFile_2_00159DD0(0x13BD5472, gMenuSbss_002020DC, &a, &b);
    i = 0; if (i < D_0049FAE8[0]) { p = D_0049F8A0; do { MenuLayout_BindTextures_0_00189D50(p[0], D_0049F8E0, a); i++; p++; } while (i < D_0049FAE8[0]); }
    D_0049FAE4[0] = a; D_0049FAEC[0] = b;
    Menu_LoadLayout_0_00189740(D_004A0430, 0x9D2D9756);
    c = 0; d = 0;
    Arc_LoadFile_2_00159DD0(0x9D2C05C0, gMenuSbss_002020DC, &c, &d);
    j = 0; if (j < D_004A0678[0]) { r = D_0049F8A0; q = D_004A0470; do { MenuLayout_BindTextures_0_00189D50(r[0x2E4], q, c); j++; r++; } while (j < D_004A0678[0]); }
    D_004A0674[0] = c; D_004A067C[0] = d;
    Menu_LoadLayout_0_00189740(D_004A01E0, 0x0178F67D);
    e = 0; f = 0;
    Arc_LoadFile_2_00159DD0(0x017964EB, gMenuSbss_002020DC, &e, &f);
    j = 0; if (j < D_004A0428[0]) { r = D_0049F8A0; q = D_004A0220; do { MenuLayout_BindTextures_0_00189D50(r[0x250], q, e); j++; r++; } while (j < D_004A0428[0]); }
    D_004A0424[0] = e; D_004A042C[0] = f;
    Menu_LoadLayout_0_00189740(D_0049FD40, 0x0EBDF3D7);
    Menu_LoadLayout_0_00189740(D_0049FAF0, 0xF733968B);
    Menu_LoadLayout_0_00189740(D_004A0680, 0x90BD8B46);
    Menu_LoadLayout_0_00189740(D_0049FF90, 0x45E9E286);
    Ui_SetGlobalFlag_0_00182990(gMenuSbss_002020DC);
    Menu_SetParam_0_0018A410(gMenuSbss_002020DC);
    Msg_SetParam_0_0018AEA0(gMenuSbss_002020DC);
    Ui_Nop_2_00180F40();
    ImageLoader_SetFlag_0_001E1760(gMenuSbss_002020DC);
}
#undef Arc_LoadFile_2_00159DD0
#undef MenuLayout_BindTextures_0_00189D50
#undef Menu_SetParam_0_0018A410
#undef gMenuSbss_002020DC

/* MenuLayout_BindTextures_0_00189D50 */
s32 MenuLayout_BindTextures_0_00189D50(A *a, T *t, s32 k) {
    u32 i, j;
    if (a == 0) return 1;
    for (i = 0; i < a->n; i++) {
        T *tt = &t[a->i[i].idx];
        for (j = 0; j < tt->n; j++) {
            E_MenuLayout_BindTextures_0_00189D50 *e = (E_MenuLayout_BindTextures_0_00189D50 *)((u8 *)tt->e + j * 0x30);
            e->f4 = 0;
            if (e->f8 != -1 && e->f8 != 0) {
                if (k) e->f4 = Tex_Find_1_00177AF0(e->f8, k);
                else e->f4 = Tex_FindByHash_1_00177B20(e->f8);
            }
        }
    }
    return 0;
}

/* MenuStack_Clear_1_00189E90 */
void MenuStack_Clear_1_00189E90(void) {
    gMenuSbss_002020E0 = 0;
}

/* MenuStack_Pop_1_00189EA0 */
s32 MenuStack_Pop_1_00189EA0(void)
{
    gMenuSbss_002020E0--;
    return gMenuBss_00497B60[gMenuSbss_002020E0];
}

/* MenuStack_Push_1_00189ED0 */
void MenuStack_Push_1_00189ED0(s32 v)
{
    gMenuBss_00497B60[gMenuSbss_002020E0] = v;
    gMenuSbss_002020E0++;
}

/* Camera_SetShake_0_00189F00 */
void Camera_SetShake_0_00189F00(void *arg0) {
    (*gMenuBss_004A0B10) = M2C_FIELD(arg0, f32 *, 0);
    (*gMenuBss_004A0B14) = M2C_FIELD(arg0, f32 *, 4);
    (*gMenuBss_004A0B18) = M2C_FIELD(arg0, f32 *, 8);
    (*gMenuBss_004A0B1C) = M2C_FIELD(arg0, f32 *, 0xC);
}

/* Menu_Draw_1_00189F40 */

void Menu_Draw_1_00189F40(void) {
    Buf s;

    GsPkt_SetLayer_1_00154700(5, 0);
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, 0x44);
    GsPkt_Flush_1_001544C0();
    Menu_DrawSlider_0_0018A580(gMenuSdata_00201CF0 != 0x12 && gMenuSdata_00201CF0 != 0x28, &gMenuSbss_0020210C, 0.0f, 64.0f, 4.0f);
    Menu_DrawSlider_0_0018A580(D_004A0B34[0].b4, &gMenuSbss_00202114, 0.0f, 128.0f, 2.0f);
    if (gMenuData_001F2930[gMenuSdata_00201CF0] != NULL) {
        D_004A0AE8[0] = 0;
        D_004A0AEC[0] = 0;
        gMenuData_001F2930[gMenuSdata_00201CF0](gMenuBss_004A0B20);
        Ui_BeginSprites_1_00181420();
    }
    Menu_UpdateFades_1_0018A910();
    Menu_DrawHelpText_1_001DD700(gMenuSdata_00201CF0, gMenuBss_004A0B2C[0]);
    Ui_BeginSprites_1_00181420();
    if (gMenuData_001F2880[gMenuSdata_00201CF0] != NULL) {
        D_004A0AE8[0] = 0;
        D_004A0AEC[0] = 0;
        gMenuData_001F2880[gMenuSdata_00201CF0](gMenuBss_004A0B20);
        Ui_BeginSprites_1_00181420();
    }
    if (!D_004A0B34[0].b3) {
        Menu_DrawSlider_0_0018A580(D_004A0B2A[0], &gMenuSbss_00202110, 0.0f, 64.0f, 4.0f);
        if (D_004A0B2A[0]) {
            gMenuData_001F2880[0](gMenuBss_004A0B20);
            Menu_DrawBackground_0_00187B20(0);
            Ui_BeginSprites_1_00181420();
        }
        Pause_Update_0_0018A650(gMenuBss_004A0B20);
        Menu_DrawBackground_0_00187B20(0);
        Ui_BeginSprites_1_00181420();
        ScreenFx_DrawBars_0_00157110((Option_GetSoundMode_0_001A9430() - 0x20) * 2 + 0x80);
        if (!(gMenuBss_004A0B1C[0] <= 0.0f)) {
            s.b[0] = (s32)(gMenuBss_004A0B10[0] / 2.0f);
            s.b[1] = (s32)(gMenuBss_004A0B14[0] / 2.0f);
            s.b[2] = (s32)(gMenuBss_004A0B18[0] / 2.0f);
            s.b[3] = (s32)(gMenuBss_004A0B1C[0] / 2.0f);
            Ui_DrawSpriteRotated_1_00182080(0.0f, 0, gMenuData_001F27B0, gMenuData_001F27C0, &s, 0);
            Ui_BeginSprites_1_00181420();
        }
    } else {
        D_004A0B34[0].b3 = 0;
    }
    GsPkt_EndLayer_1_00155900();
}

/* Menu_Update_1_0018A200 */
#define gMenuBss_004A0B20 gMenuBss_004A0B20__as_Menu_Update_1_0018A200
extern s32 gMenuBss_004A0B20__as_Menu_Update_1_0018A200[];

void Menu_Update_1_0018A200(void) {
    Menu_SaveOptions_1_0018E460();
    Menu_WaitLoad_0_0018AAD0(gMenuBss_004A0B20);
    switch (gMenuBss_004A0B20[0]) {
    case 0:
        gMenuBss_004A0B24[0] = 0;
        break;
    case 31:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
        break;
    }
    if (D_004A0B2B[0] == 0) {
        gMenuData_001F27D0[gMenuSdata_00201CF0](gMenuBss_004A0B20);
    }
    if (D_004A0B2A[0] != 0) {
        gMenuData_001F27D0[0](gMenuBss_004A0B20);
    }
    gMenuBss_004A0B24[0] = 0;
    Menu_HandleEvent_0_0018A420(gMenuBss_004A0B20);
    Strm_Update_1_001304C0();
    Menu_RestoreOptions_1_0018E450();
}
#undef gMenuBss_004A0B20

/* Menu_SetFlags_0_0018A310 */
void Menu_SetFlags_0_0018A310(s32 arg0) {
    gMenuSbss_002020F0 |= arg0;
}

/* Menu_GetMode_1_0018A320 */
u8 Menu_GetMode_1_0018A320(void) {
    return (*gMenuBss_004A0B28);
}

/* Menu_SetSubMode_0_0018A330 */
void Menu_SetSubMode_0_0018A330(s8 arg0) {
    if (gMenuSdata_00201CF0 == 0x12) {
        (*D_004A0B2F) = arg0;
    }
}

/* Menu_Open_1_0018A350 */
#define gMenuBss_004A0B20 gMenuBss_004A0B20__as_Menu_Open_1_0018A350
extern s32 gMenuBss_004A0B20__as_Menu_Open_1_0018A350[];
#define D_004A0B34 D_004A0B34__as_Menu_Open_1_0018A350
extern s32 D_004A0B34__as_Menu_Open_1_0018A350[];

void Menu_Open_1_0018A350(s8 arg0) {
    (*gMenuBss_004A0B28) = arg0;
    (*D_004A0B29) = 0;
    (*gMenuBss_004A0B20) = 0x1F;
    (*D_004A0B2E) = 0x7F;
    (*D_004A0B2F) = 0;
    (*gMenuBss_004A0B2C) = 0;
    (*D_004A0B34) = 0;
    Ui_SetAlphaClamped_0_00182050(0x80);
    Hud_Reset_0_0019A7E0(gMenuBss_004A0B20);
    GameOver_Reset_0_0019E8A0(gMenuBss_004A0B20);
    ItemMenu_Reset_0_0019DF80(gMenuBss_004A0B20);
    Equip_Reset_0_00199170(gMenuBss_004A0B20);
    Msg_Close_1_0018B0C0();
    (*gMenuBss_004A0B10) = 0;
    (*gMenuBss_004A0B14) = 0;
    (*gMenuBss_004A0B18) = 0;
    (*gMenuBss_004A0B1C) = 0;
}
#undef gMenuBss_004A0B20
#undef D_004A0B34

/* Menu_SetParam_0_0018A410 */
void Menu_SetParam_0_0018A410(s32 arg0) {
    (*gMenuBss_004A0B30) = arg0;
}

/* Menu_HandleEvent_0_0018A420 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */

void Menu_HandleEvent_0_0018A420(s32 *a0) {
    switch (*a0) {
    case 0:
        *a0 = 0x16;
        break;
    case 0x19:
        if (gMenuSdata_00201CF4 != *a0) {
            D_004A0AE0[0] = 0;
            D_004A0AF0[0] = 3;
            gMenuSbss_002020D8 = gHudDrawSbss_002020D4;
        }
        *a0 = 0x1B;
        break;
    case 0x1A:
        *a0 = 0x1C;
        break;
    case 0x1B:
        if (!(gMenuSbss_00202108 <= 5.0f)) {
            gMenuSbss_00202108 = 0.0f;
            *a0 = 0;
        } else {
            gMenuSbss_00202108 += 1.0f;
        }
        break;
    case 0x1C:
        if (!(gMenuSbss_00202108 <= 12.0f)) {
            gMenuSbss_00202108 = 0.0f;
            *a0 = 0x1E;
        } else {
            gMenuSbss_00202108 += 1.0f;
        }
        break;
    case 0x1E:
        *a0 = 0x1F;
        break;
    case 0x21:
        gMenuSbss_002020D8 = gHudDrawSbss_002020D4;
        *a0 = 0x16;
        break;
    case 0x20:
        break;
    }
    gMenuSdata_00201CF4 = *a0;
}

/* Menu_DrawSlider_0_0018A580 */
void Menu_DrawSlider_0_0018A580(s32 arg0, f32 *arg1, f32 min, f32 max, f32 step) {
    f32 v = *arg1; Buf s = {0};
    if (arg0 != 0) {
        v += step;
        if (v > max) v = max;
    } else {
        v -= step;
        if (v < min) v = min;
    }
    s.b[3] = (s32)v;
    *arg1 = v;
    if (s.b[3] > 0) {
        Ui_DrawSpriteRotated_1_00182080(0.0f, 0, gMenuData_001F27B0, gMenuData_001F27C0, &s, 0);
        Ui_BeginSprites_1_00181420();
    }
}

/* Pause_Update_0_0018A650 */
#define Menu_GetStateBuf_0_00189000 Menu_GetStateBuf_0_00189000__as_Pause_Update_0_0018A650
s32 Menu_GetStateBuf_0_00189000__as_Pause_Update_0_0018A650(s32);

void Pause_Update_0_0018A650(Arg *arg0) {
    Buf s = {0};

    if (arg0->x14.b2) {
        gMenuSbss_00202104 += 4.0f;
        if (gMenuSbss_00202104 > 128.0f) {
            MenuStack_Clear_1_00189E90();
            Save_ParseOptions_1_001A8B90(Menu_GetStateBuf_0_00189000(1));
            Save_ParseOptionsB_0_001A8F00(Menu_GetStateBuf_0_00189000(0));
            Game_RequestMode12A_0_0012C0A0();
            Strm_Stop_2_00130440();
            gMenuData_001F29EC[0] = -2.89f;
            gMenuData_001F29E8[0] = -2.89f;
            gMenuData_001F29E4[0] = -2.89f;
            gMenuData_001F29E0[0] = -2.89f;
            D_004A0B34[0].b2 = 0;
        }
    } else if (D_004A0B34[0].b0) {
        gMenuSbss_00202104 += 4.0f;
        if (gMenuSbss_00202104 > 128.0f) {
            MenuStack_Clear_1_00189E90();
            Game_RequestExit_0_0012C070(0);
            Save_InitOptions_1_001AB280();
            Strm_Stop_2_00130440();
            gMenuData_001F29EC[0] = -2.89f;
            gMenuData_001F29E8[0] = -2.89f;
            gMenuData_001F29E4[0] = -2.89f;
            gMenuData_001F29E0[0] = -2.89f;
            D_004A0B34[0].b0 = 0;
        }
    } else if (D_004A0B34[0].b1) {
        gMenuSbss_00202104 += 4.0f;
        if (gMenuSbss_00202104 > 128.0f) {
            MenuStack_Clear_1_00189E90();
            Game_RequestExit_0_0012C070(1);
            gMenuData_001F29EC[0] = -2.89f;
            gMenuData_001F29E8[0] = -2.89f;
            gMenuData_001F29E4[0] = -2.89f;
            gMenuData_001F29E0[0] = -2.89f;
            D_004A0B34[0].b0 = 0;
        }
    } else {
        gMenuSbss_00202104 -= 4.0f;
        if (gMenuSbss_00202104 < 0.0f) {
            gMenuSbss_00202104 = 0.0f;
        }
    }
    s.b[3] = (s32)gMenuSbss_00202104;
    if (s.b[3] > 0) {
        Ui_DrawSpriteRotated_1_00182080(0.0f, 0, gMenuData_001F27B0, gMenuData_001F27C0, &s, 0);
        Ui_BeginSprites_1_00181420();
    }
}
#undef Menu_GetStateBuf_0_00189000

/* Menu_UpdateFades_1_0018A910 */
void Menu_UpdateFades_1_0018A910(void) {
    s32 bit;
    f32 *p;

    bit = 1;
    p = gMenuData_001F29E0;
    do {
        if (gMenuSbss_002020F0 & bit) {
            *p = Approachf_3_00187770(*p, -0.01f, 3.5f);
        } else {
            *p = Approachf_3_00187770(*p, -2.89f, 3.5f);
        }
        bit += bit;
        p++;
    } while (bit < 0x10);
    if (!(fabsf(gMenuData_001F29E0[0] - -2.89f) <= 0.005f)) {
        Menu_FadeListB_0_00186F20(0.7f + gMenuData_001F29E0[0]);
    }
    if (!(fabsf(gMenuData_001F29E4[0] - -2.89f) <= 0.005f)) {
        Menu_FadeListA_0_00186E70(-gMenuData_001F29E4[0]);
    }
    if (!(fabsf(gMenuData_001F29E8[0] - -2.89f) <= 0.005f)) {
        Menu_FadeListD_0_00187080(gMenuData_001F29E8[0]);
    }
    if (!(fabsf(gMenuData_001F29EC[0] - -2.89f) <= 0.005f)) {
        Menu_FadeListC_0_00186FD0(-gMenuData_001F29EC[0]);
    }
    gMenuSbss_002020F0 = 0;
}

/* Menu_WaitLoad_0_0018AAD0 */
void Menu_WaitLoad_0_0018AAD0(s32 *arg0) {
    s64 v;

    if (arg0[0] == 0x1F) {
        if (Ui_IsImageLoading_0_00183FF0() != 0) return;
        arg0[0] = 0x19;
        gMenuSdata_00201CF0 = ((u8 *)arg0)[8];
    }
    arg0[1] = D_0031723A[0] | gMapCommandBss_00317238[0];
    v = 0;
    if (gPlayerBss_00317244[0] < -0.9f && !(gMenuBss_00317230[0] & 0x80)) v |= 0x80;
    if (!(gPlayerBss_00317244[0] <= 0.9f) && !(gMenuBss_00317230[0] & 0x20)) v |= 0x20;
    if (gPlayerBss_00317248[0] < -0.9f && !(gMenuBss_00317230[0] & 0x10)) v |= 0x10;
    if (!(gPlayerBss_00317248[0] <= 0.9f) && !(gMenuBss_00317230[0] & 0x40)) v |= 0x40;
    if (v != 0) {
        if (gMenuSbss_002020F8 == v) {
            gMenuSbss_00202100++;
        } else {
            gMenuSbss_002020F8 = v;
            gMenuSbss_00202100 = 0;
        }
        if (gMenuSbss_00202100 != 0) {
            if (gMenuSbss_00202100 > 0xC) goto f;
        } else {
f:
            if (gMenuSbss_00202100 % 4 == 0) {
                arg0[1] |= (s32)v;
            }
        }
    } else {
        gMenuSbss_002020F8 = v;
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gMenuSbss_002020DC */
s32 gMenuSbss_002020DC;
/* data twins (src/game/data/vibration_bss.c): gMenuBss_00317230 */
u16 gMenuBss_00317230[0x4];
/* data twins (src/game/data/option_bss.c): gMenuBss_004A0B20, gMenuBss_004A0B28, gMenuBss_004A0B2C, gMenuBss_004A0B30 */
s8 gMenuBss_004A0B20[0x4];
u8 gMenuBss_004A0B28[0x4];
s8 gMenuBss_004A0B2C[0x4];
s32 gMenuBss_004A0B30[0x8] __attribute__((aligned(4)));
/* data group (src/game/data/menu_draw_wrap_data.c): D_001F27B0__grp: gMenuData_001F27B0@0x0 */
f32 D_001F27B0__grp[0x4] __attribute__((aligned(16))) = { 0.0f, 0.0f, 640.0f, 448.0f };
/* data group (src/game/data/menu_draw_wrap_data.c): D_001F27C0__grp: gMenuData_001F27C0@0x0 */
f32 D_001F27C0__grp[0x4] __attribute__((aligned(16))) = { 0.0f, 0.0f, 256.0f, 256.0f };
void Credits_Update_0_001DCC30(void);
void Databook_UpdateWrap_0_00195410(void);
void DbChar_UpdateWrap_0_00196930(void);
void DbItem_Open_0_001979C0(void);
void DbMap_UpdateWrap_0_00198BD0(void);
void Ending_HandleEvent_0_001EDCC0(void);
void Ending_OpenLoadMenu_0_00194F60(void);
void Ending_Update_0_001ED9A0(void);
void Equip_Open_0_001997A0(void);
void GameOver_Update_2_0019EDC0(void);
void Hud_Update_1_0019B560(void);
void ItemMenu_Open_0_0019D290(void);
void LoadMenu_HandleEvent_0_00192900(void);
void LoadMenu_Open_0_001939B0(void);
void Loading_Nop_0_0018E440(void);
void MapSheet_Update_0_001ED740(void);
void MenuProc_CheckReady_0_0018B2E0(void);
void Option_Update_2_0018EAE0(void);
void PauseMenu_Open_0_0019E2F0(void);
void Pause_HandleEvent_0_0019E810(void);
void SaveMenu_HandleEvent_0_0018C4C0(void);
void SaveMenu_Open_1_0018D360(void);
void Shop_Open_1_001A1B40(void);
void Storage_Open_0_001A32A0(void);
void TitleMenu_Update_1_001A4010(void);
void Title_LoadGame_0_001A35B0(void);
void Title_ResetOnEvent_0_001A3C70(void);
void Title_StartNewGame_0_001A4930(void);
void Title_UpdateWrap_0_001A3EB0(void);
/* data group (src/game/data/menu_draw_wrap_data.c): D_001F27D0__grp: gMenuData_001F27D0@0x0 */
s32 D_001F27D0__grp[0x2c] __attribute__((aligned(16))) = { (s32)MenuProc_CheckReady_0_0018B2E0, (s32)Title_LoadGame_0_001A35B0, 0, (s32)Title_UpdateWrap_0_001A3EB0, (s32)Title_ResetOnEvent_0_001A3C70, (s32)Credits_Update_0_001DCC30, (s32)TitleMenu_Update_1_001A4010, (s32)Title_StartNewGame_0_001A4930, 0, (s32)SaveMenu_Open_1_0018D360, (s32)LoadMenu_Open_0_001939B0, (s32)SaveMenu_HandleEvent_0_0018C4C0, (s32)LoadMenu_HandleEvent_0_00192900, (s32)Option_Update_2_0018EAE0, 0, 0, 0, (s32)MapSheet_Update_0_001ED740, (s32)Hud_Update_1_0019B560, (s32)Pause_HandleEvent_0_0019E810, (s32)PauseMenu_Open_0_0019E2F0, (s32)ItemMenu_Open_0_0019D290, (s32)Equip_Open_0_001997A0, 0, (s32)Databook_UpdateWrap_0_00195410, (s32)DbMap_UpdateWrap_0_00198BD0, (s32)DbChar_UpdateWrap_0_00196930, (s32)DbItem_Open_0_001979C0, 0, 0, 0, (s32)Storage_Open_0_001A32A0, 0, 0, (s32)Shop_Open_1_001A1B40, 0, (s32)Ending_Update_0_001ED9A0, (s32)Ending_HandleEvent_0_001EDCC0, 0, (s32)Loading_Nop_0_0018E440, (s32)GameOver_Update_2_0019EDC0, (s32)Ending_OpenLoadMenu_0_00194F60, 0, 0 };
void Credits_DrawFrame_0_001DC900(void);
void Hud_DrawMain_0_0019A8B0(void);
void Hud_Draw_0_0018E480(void);
void LoadMenu_DrawFrame_0_00193880(void);
void LoadMenu_DrawList_0_00191CB0(void);
void MapSheet_Draw_0_001ED630(void);
void MenuProc_DrawItemList_0_0018B860(void);
void MenuProc_DrawList_0_0018B180(void);
void Pause_DrawText_2_0019E7C0(void);
void SaveMenu_DrawFrame_0_0018D1F0(void);
void Title_DrawLogo_0_001A3CC0(void);
void Title_Draw_0_001A3FB0(void);
void Title_Nop_2_001A35A0(void);
void Title_PlayOpening_2_001A3C10(void);
void Title_PlayPrologue_2_001A4890(void);
/* data group (src/game/data/menu_draw_wrap_data.c): D_001F2880__grp: gMenuData_001F2880@0x0 */
s32 D_001F2880__grp[0x14] __attribute__((aligned(16))) = { (s32)MenuProc_DrawList_0_0018B180, (s32)Title_Nop_2_001A35A0, 0, (s32)Title_DrawLogo_0_001A3CC0, (s32)Title_PlayOpening_2_001A3C10, (s32)Credits_DrawFrame_0_001DC900, (s32)Title_Draw_0_001A3FB0, (s32)Title_PlayPrologue_2_001A4890, 0, (s32)SaveMenu_DrawFrame_0_0018D1F0, (s32)LoadMenu_DrawFrame_0_00193880, (s32)MenuProc_DrawItemList_0_0018B860, (s32)LoadMenu_DrawList_0_00191CB0, (s32)Hud_Draw_0_0018E480, 0, 0, 0, (s32)MapSheet_Draw_0_001ED630, (s32)Hud_DrawMain_0_0019A8B0, (s32)Pause_DrawText_2_0019E7C0 };
void Credits_DrawBg_0_001DCE70(void);
void Option_DrawFrame_0_0018E980(void);
/* data group (src/game/data/menu_draw_wrap_data.c): D_001F2930__grp: gMenuData_001F2930@0x0 */
s32 D_001F2930__grp[0x2c] __attribute__((aligned(16))) = { 0, 0, 0, 0, 0, (s32)Credits_DrawBg_0_001DCE70, (s32)Credits_DrawBg_0_001DCE70, 0, 0, (s32)Option_DrawFrame_0_0018E980, 0, (s32)Option_DrawFrame_0_0018E980, 0, (s32)Option_DrawFrame_0_0018E980, 0, 0, 0, (s32)Hud_DrawMain_0_0019A8B0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
