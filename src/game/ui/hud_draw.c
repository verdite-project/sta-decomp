#include "common.h"
#include "actor.h"
#include "m2c.h"
#include "game/data.h"
#include "game/item.h"
#include "game/player.h"
#include "game/sound.h"
#include "game/ui.h"
#include "game/math.h"
typedef struct { char p[8]; s32 v; char q[4]; } E_Hud_ClearTimers_0_0019A840;
typedef union { u32 w; struct { u8 r, g, b, a; } c; } Col;
typedef struct { s32 x0; s32 x4; u8 pad8[0x24]; f32 x2C; f32 x30; f32 x34; f32 x38; Col x3C; } E_Hud_DrawStatus_1_0019A920;
typedef struct { u32 n; E_Hud_DrawStatus_1_0019A920 *e; } L;
typedef struct { u8 pad[0x28]; f32 x28; } P_Hud_DrawStatus_1_0019A920;
typedef struct { s32 x0; P_Hud_DrawStatus_1_0019A920 *p; } T_Hud_DrawStatus_1_0019A920;
typedef struct { u8 pad[8]; f32 x8; u8 padC[4]; } F;
typedef struct { u8 pad[0x394]; s8 x394; s8 x395; s8 x396; s8 x397; } S;
typedef struct { s32 state; s32 x4; u8 x8; u8 x9; u8 pad[4]; u8 xE; u8 xF; } P_Hud_HandleInput_0_0019B590;
typedef Bits8 B8;
typedef struct { f32 a; f32 t; u8 pad8[4]; B8 f; u8 padD[3]; } T_Hud_UpdateGauges_0_0019B8D0;
typedef struct { u8 pad[4]; s16 x4; s16 x6; } G;
typedef struct { u32 w[15]; Col col; } Buf;
typedef struct { u8 pad[0x94]; u8 x94; } P_Hud_DrawShortcuts_0_0019BBE0;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[0x6E]; } E_Hud_DrawShortcuts_0_0019BBE0;
typedef struct { s32 k0; s32 k4; u8 t8; u8 pad[7]; } K;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[0x6E]; } E_Hud_UpdateShortcuts_0_0019BFF0;
typedef struct { u8 pad0[0xA]; u16 type; u8 pad1[0x30]; u8 max; u8 pad2[0x53]; } Rec;
typedef struct { u8 pad[8]; s8 st; u8 pad2[7]; } Out;
#ifndef NONMATCHING
extern s32 gHudDrawSbss_002021C0;
#else
/* data twins (src/game/data/sbss.c): gHudDrawSbss_002021C0 */
static s32 gHudDrawSbss_002021C0;
#endif
#ifndef NONMATCHING
extern s32 gHudDrawSbss_002021CC;
#else
/* data twins (src/game/data/sbss.c): gHudDrawSbss_002021CC */
static s32 gHudDrawSbss_002021CC;
#endif
#ifndef NONMATCHING
extern s32 gHudDrawSbss_002021D8;
#else
/* data twins (src/game/data/sbss.c): gHudDrawSbss_002021D8 */
static s32 gHudDrawSbss_002021D8;
#endif
#ifndef NONMATCHING
extern s32 gHudDrawSbss_002021DC;
#else
/* data twins (src/game/data/sbss.c): gHudDrawSbss_002021DC */
static s32 gHudDrawSbss_002021DC;
#endif
extern s32 gHudDrawSbss_002021C4;
extern s32 gHudDrawSbss_002021C8;
extern struct { unsigned char f : 1; char pad[15]; } gHudDrawData_001F306C, gHudDrawData_001F307C;
extern E_Hud_ClearTimers_0_0019A840 gHudDrawBss_004A28E0[64];
extern E_Hud_ClearTimers_0_0019A840 gHudDrawBss_004A2CE0[64];
extern s8 gHudDrawRodata_001FD408[];
extern s8 gHudDrawRodata_001FD410[];
#ifndef NONMATCHING
extern s8 gHudDrawRodata_001FD418[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): gHudDrawRodata_001FD418 */
static s8 gHudDrawRodata_001FD418[0x8] = { 0x25, 0x64, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 gHudDrawRodata_001FD420[];
#else
/* data twins (src/game/data/databook_item_reset_rodata.c): gHudDrawRodata_001FD420 */
static s8 gHudDrawRodata_001FD420[0xd] = "MP\000\000\000\000\000\000\000\000\000\000\000";
#endif
extern f32 gHudDrawData_001F3060[];
extern f32 gHudDrawData_001F3070[];
#ifndef NONMATCHING
extern s32 gHudDrawSdata_00201D60;
#else
/* data twins (src/game/data/sdata.c): gHudDrawSdata_00201D60 */
static s32 gHudDrawSdata_00201D60 = -1;
#endif
#ifndef NONMATCHING
extern s32 gHudDrawSdata_00201D64;
#else
/* data twins (src/game/data/sdata.c): gHudDrawSdata_00201D64 */
static s32 gHudDrawSdata_00201D64 = -1;
#endif
#ifndef NONMATCHING
extern f32 gHudDrawSbss_002021D0;
#else
/* data twins (src/game/data/sbss.c): gHudDrawSbss_002021D0 */
static f32 gHudDrawSbss_002021D0;
#endif
extern K gItemMenuProcDrawInfoBss_004A30E0[];
extern s16 gHudDrawRodata_001FD3F8[];
void Hud_Reset_0_0019A7E0(void);
void Hud_DrawStatus_1_0019A920(L *l, T_Hud_DrawStatus_1_0019A920 *t);
void Hud_HandleInput_0_0019B590(P_Hud_HandleInput_0_0019B590 *p);
void Hud_UpdateGauges_0_0019B8D0(void);
void Hud_DrawShortcuts_0_0019BBE0(Buf *src, s32 a1, s32 key);
void Hud_UpdateShortcuts_0_0019BFF0(void);
void Hud_UpdateWeaponSlots_0_0019C560(void);
s32 Menu_GetMode_1_0018A320(void);
s32* MenuLayout_Get_1_00189050(s32 i);
void* MenuLayout_GetSub_1_00189020(s32 i);
s16* PlayerData_Get_2_001C9BA0(void);
void Ui_DrawElem_1_00182C10(E_Hud_DrawStatus_1_0019A920 *, T_Hud_DrawStatus_1_0019A920 *);
void Text_Draw_2_001875C0(f32, s8 *, f32, f32, s32, u32);
void Text_DrawCentered_1_00187680(f32, s8 *, f32, f32, s32, s32, u32);
void sprintf(s8 *, s8 *, ...);
void SndEmit_SetEnabled_0_0012F6E0(s32);
void Snd_PlaySe_3_00131600(s32, u8);
s32 Equip_GetSlotItem_1_001CCD90(s32);
E_Hud_DrawShortcuts_0_0019BBE0* Item_GetTable_1_001AFC90(void);
void Color_Pulse_1_00187960(f32, Col *);
void Color_Double_0_001878A0(f32, Col *);
u8* Equip_GetSlotEntry_0_001CCD30(s32);

/* Hud_IsHidden_0_0019A790 */
s32 Hud_IsHidden_0_0019A790(void)
{
    s32 r = gHudDrawSbss_002021C0;
    if (r)
        gHudDrawSbss_002021CC = 0;
    if (gHudDrawSbss_002021CC)
        return Menu_GetMode_1_0018A320() == 0x12;
    return r;
}

/* Hud_Reset_0_0019A7E0 */
void Hud_Reset_0_0019A7E0(void)
{
    gHudDrawSbss_002021D8 = -1;
    gHudDrawSbss_002021DC = -1;
    gHudDrawSbss_002021CC = 1;
    gHudDrawSbss_002021C4 = 0;
    gHudDrawSbss_002021C8 = 0;
    gHudDrawData_001F306C.f = 1;
    gHudDrawData_001F307C.f = 1;
}

/* Hud_ClearTimers_0_0019A840 */
void Hud_ClearTimers_0_0019A840(void)
{
    s32 i;
    for (i = 63; i >= 0; i--) {
        gHudDrawBss_004A2CE0[i].v = 0;
        gHudDrawBss_004A28E0[i].v = 0;
    }
}

/* Hud_DrawMain_0_0019A8B0 */
#define Hud_DrawStatus_1_0019A920 Hud_DrawStatus_1_0019A920__as_Hud_DrawMain_0_0019A8B0
void Hud_DrawStatus_1_0019A920__as_Hud_DrawMain_0_0019A8B0(s32 a, void *b);

void Hud_DrawMain_0_0019A8B0(void)
{
    s32 a = *MenuLayout_Get_1_00189050(1);
    void *b = MenuLayout_GetSub_1_00189020(1);
    Msg_Draw_0_0018ACA0();
    Ui_BeginSprites_1_00181420();
    Hud_DrawStatus_1_0019A920(a, b);
    Menu_DrawBackground_0_00187B20(0);
    Ui_BeginSprites_1_00181420();
}
#undef Hud_DrawStatus_1_0019A920

/* Hud_DrawStatus_1_0019A920 */
#define gHudDrawBss_004A2CE0 gHudDrawBss_004A2CE0__as_Hud_DrawStatus_1_0019A920
extern F gHudDrawBss_004A2CE0__as_Hud_DrawStatus_1_0019A920[];
#define gHudDrawBss_004A28E0 gHudDrawBss_004A28E0__as_Hud_DrawStatus_1_0019A920
extern F gHudDrawBss_004A28E0__as_Hud_DrawStatus_1_0019A920[];
#define gHudDrawSbss_002021C4 gHudDrawSbss_002021C4__as_Hud_DrawStatus_1_0019A920
extern f32 gHudDrawSbss_002021C4__as_Hud_DrawStatus_1_0019A920;
#define gHudDrawSbss_002021C8 gHudDrawSbss_002021C8__as_Hud_DrawStatus_1_0019A920
extern f32 gHudDrawSbss_002021C8__as_Hud_DrawStatus_1_0019A920;
#define Hud_DrawShortcuts_0_0019BBE0 Hud_DrawShortcuts_0_0019BBE0__as_Hud_DrawStatus_1_0019A920
void Hud_DrawShortcuts_0_0019BBE0__as_Hud_DrawStatus_1_0019A920(E_Hud_DrawStatus_1_0019A920 *, T_Hud_DrawStatus_1_0019A920 *, s32);
#define O o

void Hud_DrawStatus_1_0019A920(L *l, T_Hud_DrawStatus_1_0019A920 *t) {
    f32 o = 0.0f;

    s16 *fp;
    S *s;
    u32 i;
    s32 id;
    u8 j;
    E_Hud_DrawStatus_1_0019A920 *e;
    Col col;
    s8 buf1[0x100];
    s8 buf2[0x100];

    fp = PlayerData_Get_2_001C9BA0();
    Hud_UpdateGauges_0_0019B8D0();
    if (Player_Exists_3_001C9BF0()) {
        s = (S *)(gPlayerSbss_002022E4->unk518 + 0x180);
    } else {
        return;
    }
    for (i = 0; i < l->n; i++) {
        id = l->e[i].x4;
        if (id == 5000) {
            for (j = 0; j < s->x394; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 16 + (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                Ui_DrawElem_1_00182C10(&l->e[i], &t[j % 3 + 8]);
            }
            for (j = 0; j < s->x396; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 16 + (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                gHudDrawBss_004A2CE0[j].x8 += 16.0f;
                if (gHudDrawBss_004A2CE0[j].x8 > 128.0f) gHudDrawBss_004A2CE0[j].x8 = 128.0f;
                l->e[i].x3C.c.a = (s32)gHudDrawBss_004A2CE0[j].x8;
                Ui_DrawElem_1_00182C10(&l->e[i], &t[j % 3 + 5]);
            }
            for (; j < s->x394; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 16 + (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                gHudDrawBss_004A2CE0[j].x8 -= 16.0f;
                if (gHudDrawBss_004A2CE0[j].x8 < 0.0f) gHudDrawBss_004A2CE0[j].x8 = 0.0f;
                l->e[i].x3C.c.a = (s32)gHudDrawBss_004A2CE0[j].x8;
                Ui_DrawElem_1_00182C10(&l->e[i], &t[j % 3 + 5]);
            }
        }
        if (id == 6000) {
            for (j = 0; j < s->x395; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 69 - (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                Ui_DrawElem_1_00182C10(&l->e[i], &t[j % 3 + 14]);
            }
            for (j = 0; j < s->x397; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 69 - (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                gHudDrawBss_004A28E0[j].x8 += 16.0f;
                if (gHudDrawBss_004A28E0[j].x8 > 128.0f) gHudDrawBss_004A28E0[j].x8 = 128.0f;
                l->e[i].x3C.c.a = (s32)gHudDrawBss_004A28E0[j].x8;
                Ui_DrawElem_1_00182C10(&l->e[i], &t[j % 3 + 11]);
            }
            for (; j < s->x395; j++) {
                l->e[i].x34 = 1.2f;
                l->e[i].x38 = 1.2f;
                l->e[i].x2C = 28 + j * 13;
                l->e[i].x30 = 69 - (j % 2) * 2;
                l->e[i].x3C.w = 0x80FFFFFF;
                gHudDrawBss_004A28E0[j].x8 -= 16.0f;
                if (gHudDrawBss_004A28E0[j].x8 < 0.0f) gHudDrawBss_004A28E0[j].x8 = 0.0f;
                l->e[i].x3C.c.a = (s32)gHudDrawBss_004A28E0[j].x8;
                Ui_DrawElem_1_00182C10(&l->e[i], &t[j % 3 + 11]);
            }
        }
        if (id == 3000) {
            l->e[i].x2C = 33.0f;
            col = l->e[i].x3C;
            col.c.a = (s32)gHudDrawData_001F3060[0];
            Text_Draw_2_001875C0(O + l->e[i].x2C, gHudDrawRodata_001FD408, O + l->e[i].x30, 1.0f, 0, col.w);
        }
        if (id == 3010) {
            sprintf(buf1, gHudDrawRodata_001FD410, gHudDrawSbss_002021D8);
            col = l->e[i].x3C;
            col.c.a = (s32)gHudDrawData_001F3060[0];
            Text_DrawCentered_1_00187680(O + (l->e[i].x2C - 120.0f), buf1, O + l->e[i].x30, 1.0f, 0, 16, col.w);
            sprintf(buf1, gHudDrawRodata_001FD418, fp[0]);
            Text_DrawCentered_1_00187680(O + (l->e[i].x2C - 36.0f), buf1, O + l->e[i].x30, 1.0f, 0, 16, col.w);
        }
        if (id == 4000) {
            l->e[i].x2C = 28.0f;
            col = l->e[i].x3C;
            col.c.a = (s32)gHudDrawData_001F3070[0];
            Text_Draw_2_001875C0(l->e[i].x2C, gHudDrawRodata_001FD420, l->e[i].x30, 1.0f, 0, col.w);
        }
        if (id == 4010) {
            sprintf(buf2, gHudDrawRodata_001FD410, gHudDrawSbss_002021DC);
            col = l->e[i].x3C;
            col.c.a = (s32)gHudDrawData_001F3070[0];
            Text_DrawCentered_1_00187680(l->e[i].x2C - 120.0f, buf2, l->e[i].x30, 1.0f, 0, 16, col.w);
            sprintf(buf2, gHudDrawRodata_001FD418, fp[1]);
            Text_DrawCentered_1_00187680(l->e[i].x2C - 36.0f, buf2, l->e[i].x30, 1.0f, 0, 16, col.w);
        }
        if (id == 1010) {
            gHudDrawSbss_002021C4 = Approachf_3_00187770(gHudDrawSbss_002021C4, (f32)fp[2] / (f32)fp[0], 4.0f);
            l->e[i].x3C.w = 0x80A0A0A0;
            l->e[i].x34 = gHudDrawSbss_002021C4;
            t[l->e[i].x0].p->x28 = 170.0f * gHudDrawSbss_002021C4;
            Ui_DrawElem_1_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 2010) {
            gHudDrawSbss_002021C8 = Approachf_3_00187770(gHudDrawSbss_002021C8, (f32)fp[3] / (f32)fp[1], 4.0f);
            l->e[i].x3C.w = 0x80A0A0A0;
            l->e[i].x34 = gHudDrawSbss_002021C8;
            t[l->e[i].x0].p->x28 = 170.0f * gHudDrawSbss_002021C8;
            Ui_DrawElem_1_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 1000) {
            l->e[i].x3C.w = 0x80A0A0A0;
            Ui_DrawElem_1_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 2000) {
            l->e[i].x3C.w = 0x80A0A0A0;
            Ui_DrawElem_1_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        if (id == 0) {
            Ui_DrawElem_1_00182C10(&l->e[i], &t[l->e[i].x0]);
        }
        Hud_DrawShortcuts_0_0019BBE0(&l->e[i], &t[l->e[i].x0], id);
    }
}
#undef Hud_DrawShortcuts_0_0019BBE0
#undef gHudDrawBss_004A2CE0
#undef gHudDrawBss_004A28E0
#undef gHudDrawSbss_002021C4
#undef gHudDrawSbss_002021C8
#undef O

/* Hud_Update_1_0019B560 */
#define Hud_HandleInput_0_0019B590 Hud_HandleInput_0_0019B590__as_Hud_Update_1_0019B560
void Hud_HandleInput_0_0019B590__as_Hud_Update_1_0019B560(void);

void Hud_Update_1_0019B560(void)
{
    Hud_HandleInput_0_0019B590();
    Hud_UpdateWeaponSlots_0_0019C560();
    Hud_UpdateShortcuts_0_0019BFF0();
}
#undef Hud_HandleInput_0_0019B590

/* Hud_HandleInput_0_0019B590 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Hud_HandleInput_0_0019B590
s8 *PlayerData_Get_2_001C9BA0__as_Hud_HandleInput_0_0019B590(void);

void Hud_HandleInput_0_0019B590(P_Hud_HandleInput_0_0019B590 *p) {
    s8 *b;

    b = PlayerData_Get_2_001C9BA0();
    if (p->state == 0x19) {
        SndEmit_SetEnabled_0_0012F6E0(1);
        SndCh_ResumePaused_1_0012C260();
    }
    if (p->state == 0) {
        Ui_SetScrollSpeed_0_00180F50(90.0f);
        gHudDrawSbss_002021D8 = *(s16 *)(b + 4);
        gHudDrawSbss_002021DC = *(s16 *)(b + 6);
    }
    gHudDrawSbss_002021C0 = 0;
    if (p->state == 0x16) {
        gHudDrawSbss_002021C0 = 1;
        if (p->xF) {
            SndEmit_StopAllA_1_0012F640();
            SndEmit_SetEnabled_0_0012F6E0(0);
            SndCh_PauseAll_1_0012C2C0();
            SndCh_StopAllUnlooped_1_0012C210();
        }
        switch (p->xF) {
        case 0x1F:
            p->x8 = p->xF;
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BD, p->xE);
            break;
        case 0x28:
            p->x8 = p->xF;
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0xA:
            p->x8 = p->xF;
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            LoadMenu_SetFromTitle_0_00193850(0);
            MenuStack_Push_1_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BC, p->xE);
            break;
        case 0x14:
            p->x8 = p->xF;
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x64, p->xE);
            break;
        case 0x80:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            gShopDrawBss_004A3320[0] = 5;
            p->x8 = 0x22;
            MenuStack_Push_1_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BD, p->xE);
            break;
        case 0x81:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            gShopDrawBss_004A3320[0] = 6;
            p->x8 = 0x22;
            MenuStack_Push_1_00189ED0(0x12);
            p->x4 = 0;
            p->state = 0x1F;
            Snd_PlaySe_3_00131600(0x2BD, p->xE);
            break;
        case 0x29:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x29;
            MenuStack_Push_1_00189ED0(1);
            p->x4 = 0;
            p->state = 0x1A;
            break;
        case 0x13:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x13;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x11:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x11;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x25:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x25;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        case 0x24:
            p->xF = 0;
            gHudDrawSbss_002021C0 = 0;
            p->x9 = 0;
            p->x8 = 0x24;
            p->x4 = 0;
            p->state = 0x1F;
            break;
        }
    }
}
#undef PlayerData_Get_2_001C9BA0

/* Hud_UpdateGauges_0_0019B8D0 */
#define gHudDrawData_001F3060 gHudDrawData_001F3060__as_Hud_UpdateGauges_0_0019B8D0
extern T_Hud_UpdateGauges_0_0019B8D0 gHudDrawData_001F3060__as_Hud_UpdateGauges_0_0019B8D0;
#define gHudDrawData_001F3070 gHudDrawData_001F3070__as_Hud_UpdateGauges_0_0019B8D0
extern T_Hud_UpdateGauges_0_0019B8D0 gHudDrawData_001F3070__as_Hud_UpdateGauges_0_0019B8D0;
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Hud_UpdateGauges_0_0019B8D0
G *PlayerData_Get_2_001C9BA0__as_Hud_UpdateGauges_0_0019B8D0(void);
static inline void upd(T_Hud_UpdateGauges_0_0019B8D0 *t, s32 *last, s16 *src) {
    if (t->f.b0) {
        if (*last != *src) {
            t->t = 0.0f;
            *last = *src;
            t->f.b0 = 0;
            t->a = 0.0f;
        }
        return;
    }
    if (*last != *src) {
        *last = *src;
        t->t = 0.0f;
    }
    if (t->t < 20.0f) {
        t->a += 8.0f;
        if (t->a > 128.0f) t->a = 128.0f;
    }
    if (t->t > 120.0f) {
        t->a -= 8.0f;
        if (t->a < 0.0f) t->a = 0.0f;
    }
    if (t->t > 160.0f) {
        t->f.b0 = 1;
    }
    t->t += 1.0f;
}

void Hud_UpdateGauges_0_0019B8D0(void) {
    G *g = PlayerData_Get_2_001C9BA0();
    upd(&gHudDrawData_001F3060, &gHudDrawSbss_002021D8, &g->x4);
    upd(&gHudDrawData_001F3070, &gHudDrawSbss_002021DC, &g->x6);
}
#undef PlayerData_Get_2_001C9BA0
#undef gHudDrawData_001F3060
#undef gHudDrawData_001F3070

/* Hud_DrawShortcuts_0_0019BBE0 */
#define PlayerData_Get_2_001C9BA0 PlayerData_Get_2_001C9BA0__as_Hud_DrawShortcuts_0_0019BBE0
P_Hud_DrawShortcuts_0_0019BBE0 *PlayerData_Get_2_001C9BA0__as_Hud_DrawShortcuts_0_0019BBE0(void);
#define Ui_DrawElem_1_00182C10 Ui_DrawElem_1_00182C10__as_Hud_DrawShortcuts_0_0019BBE0
void Ui_DrawElem_1_00182C10__as_Hud_DrawShortcuts_0_0019BBE0(Buf *, s32);
static inline s32 kind(s32 idx, E_Hud_DrawShortcuts_0_0019BBE0 *e) {
    if (idx < 0) return -1;
    Item_GetCategory_0_001AFBD0(idx);
    switch (e->x20) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 14:
        return 1;
    case 2: case 4: case 6: case 9: case 11: case 12: case 13: case 15: case 16: case 17: case 18: case 19:
        return 2;
    }
    return -1;
}

void Hud_DrawShortcuts_0_0019BBE0(Buf *src, s32 a1, s32 key) {
    u32 i;
    P_Hud_DrawShortcuts_0_0019BBE0 *p;
    s32 idx;
    K *k;
    E_Hud_DrawShortcuts_0_0019BBE0 *e;
    Buf buf;

    p = PlayerData_Get_2_001C9BA0();
    if (gHudDrawSdata_00201D64 != (p->x94 & 1) || gHudDrawSdata_00201D60 != (s16)Equip_GetSlotItem_1_001CCD90(0)) {
        gHudDrawSdata_00201D64 = p->x94 & 1;
        gHudDrawSdata_00201D60 = (s16)Equip_GetSlotItem_1_001CCD90(0);
        gHudDrawSbss_002021D0 = 150.0f;
    }
    i = 0;
    k = gItemMenuProcDrawInfoBss_004A30E0;
    do {
        if (key == k->k0 || key == k->k4) {
            buf = *src;
            if (k->t8 == 2) {
                buf.col.c.a = buf.col.c.a * 48 / 128;
            } else if (k->t8 == 1) {
                buf.col.w = 0x80101080;
                Color_Pulse_1_00187960(gHudDrawSbss_002020D4, &buf.col);
            }
            idx = (s16)Equip_GetSlotItem_1_001CCD90(0);
            e = &Item_GetTable_1_001AFC90()[idx];
            switch (kind(idx, e)) {
            case 0:
                break;
            case 1:
                if (i == 6 && !(p->x94 & 1)) {
                    Color_Double_0_001878A0(gHudDrawSbss_002020D4, &buf.col);
                    if (!(gHudDrawSbss_002021D0 <= 0.0f)) gHudDrawSbss_002021D0 -= 1.0f;
                }
                if (i == 5 && (p->x94 & 1) == 1) {
                    if (!(gHudDrawSbss_002021D0 <= 0.0f)) gHudDrawSbss_002021D0 -= 1.0f;
                }
                break;
            case 2:
                if (i == 6 || i == 5) {
                    Color_Double_0_001878A0(gHudDrawSbss_002020D4, &buf.col);
                    if (!(gHudDrawSbss_002021D0 <= 0.0f)) gHudDrawSbss_002021D0 -= 1.0f;
                }
                break;
            }
            idx = (s16)Equip_GetSlotItem_1_001CCD90(1);
            e = &Item_GetTable_1_001AFC90()[idx];
            switch (kind(idx, e)) {
            case 1:
                if (i == 5 && (p->x94 & 1) == 1) {
                    Color_Double_0_001878A0(gHudDrawSbss_002020D4, &buf.col);
                    if (!(gHudDrawSbss_002021D0 <= 0.0f)) gHudDrawSbss_002021D0 -= 1.0f;
                }
                break;
            }
            Ui_DrawElem_1_00182C10(&buf, a1);
        }
        i++;
        k++;
    } while (i < 7);
}
#undef PlayerData_Get_2_001C9BA0
#undef Ui_DrawElem_1_00182C10

/* Hud_UpdateShortcuts_0_0019BFF0 */
/* MATCH only with MWCC=mwcps2-3.0b38-030307 (b52 emits addiu at the switch range check) */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Hud_UpdateShortcuts_0_0019BFF0
E_Hud_UpdateShortcuts_0_0019BFF0 *Item_GetTable_1_001AFC90__as_Hud_UpdateShortcuts_0_0019BFF0(void);
static inline void sub5(E_Hud_UpdateShortcuts_0_0019BFF0 *e1) {
    switch (e1->x20) {
    case 5:
        gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2717;
        break;
    case 6:
        gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2727;
        break;
    case 7: case 8: case 10: case 14:
        break;
    case 9:
        gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2713;
        break;
    case 11: case 12: case 13: case 15: case 16: case 17: case 18: case 19:
        gItemMenuProcDrawInfoBss_004A30E0[4].k4 = -1;
        break;
    }
}

void Hud_UpdateShortcuts_0_0019BFF0(void) {
    s32 i1;
    u8 *c1;
    u8 *c0;
    E_Hud_UpdateShortcuts_0_0019BFF0 *e0;
    s32 i0;
    E_Hud_UpdateShortcuts_0_0019BFF0 *e1;

    gItemMenuProcDrawInfoBss_004A30E0[0].k0 = 0x2715;
    gItemMenuProcDrawInfoBss_004A30E0[1].k0 = 0x2716;
    gItemMenuProcDrawInfoBss_004A30E0[2].k0 = 0x272D;
    i0 = (s16)Equip_GetSlotItem_1_001CCD90(gHudDrawRodata_001FD3F8[5]);
    c0 = Equip_GetSlotEntry_0_001CCD30(gHudDrawRodata_001FD3F8[5]);
    if (i0 != -1) {
        e0 = &Item_GetTable_1_001AFC90()[i0];
    } else {
        e0 = 0;
    }
    i1 = (s16)Equip_GetSlotItem_1_001CCD90(gHudDrawRodata_001FD3F8[6]);
    c1 = Equip_GetSlotEntry_0_001CCD30(gHudDrawRodata_001FD3F8[6]);
    if (i1 != -1) {
        e1 = &Item_GetTable_1_001AFC90()[i1];
    } else {
        e1 = 0;
    }
    if (c0 == 0 && c1 == 0) {
        gItemMenuProcDrawInfoBss_004A30E0[6].k0 = -1;
        gItemMenuProcDrawInfoBss_004A30E0[5].k0 = -1;
        gItemMenuProcDrawInfoBss_004A30E0[6].k4 = -1;
        gItemMenuProcDrawInfoBss_004A30E0[5].k4 = -1;
        gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x271B;
        gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x271F;
        gItemMenuProcDrawInfoBss_004A30E0[3].k0 = 0x2711;
        return;
    }
    gItemMenuProcDrawInfoBss_004A30E0[3].k0 = 0x2714;
    if (e1 != 0 && e1->x20 == 10) {
        gItemMenuProcDrawInfoBss_004A30E0[3].k0 = 0x2711;
    }
    gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x271B;
    if (e1 != 0) {
        switch (e1->x20) {
        case 7: case 8: case 9: case 10: case 14:
            gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x2721;
            break;
        case 1: case 2: case 3: case 4: case 5: case 6:
            gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x272F;
            break;
        case 11: case 12: case 13: case 16: case 17: case 18: case 19:
            gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x2725;
            break;
        case 15:
            gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x2730;
            break;
        default:
            gItemMenuProcDrawInfoBss_004A30E0[4].k0 = 0x271B;
            break;
        }
    }
    gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x271F;
    if (e0 != 0) {
        switch (e0->x20) {
        case 1:
            if (e1 != 0) {
                if (e1->x20 == 1) {
                    gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2726;
                } else {
                    gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2717;
                }
            } else {
                gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2717;
            }
            break;
        case 14: case 7: case 8: case 10:
            gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2726;
            break;
        case 3: case 5:
            gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x2717;
            break;
        case 2: case 4:
            gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x272B;
            break;
        default:
            gItemMenuProcDrawInfoBss_004A30E0[4].k4 = 0x271F;
            if (e1 != 0) {
                sub5(e1);
            }
            break;
        }
    }
    gItemMenuProcDrawInfoBss_004A30E0[6].k0 = -1;
    gItemMenuProcDrawInfoBss_004A30E0[6].k4 = -1;
    if (e1 != 0) {
        switch (e1->x20) {
        case 0:
            break;
        case 7: case 8: case 10: case 14:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2723;
            break;
        case 9:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2710;
            break;
        case 1:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x271A;
            break;
        case 2:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x271D;
            break;
        case 3:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2724;
            break;
        case 4:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x271E;
            break;
        case 5:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2718;
            break;
        case 6:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2722;
            break;
        case 19:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2712;
            break;
        case 11: case 12: case 13: case 16: case 17:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x271C;
            break;
        case 15:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2734;
            gItemMenuProcDrawInfoBss_004A30E0[6].k4 = 0x2735;
            break;
        case 18:
            gItemMenuProcDrawInfoBss_004A30E0[6].k0 = 0x2731;
            gItemMenuProcDrawInfoBss_004A30E0[6].k4 = 0x2732;
            break;
        }
    }
    gItemMenuProcDrawInfoBss_004A30E0[5].k0 = -1;
    gItemMenuProcDrawInfoBss_004A30E0[5].k4 = -1;
    if (e0 != 0) {
        switch (e0->x20) {
        case 14: case 7: case 8: case 10:
            gItemMenuProcDrawInfoBss_004A30E0[5].k0 = 0x272C;
            break;
        case 1:
            gItemMenuProcDrawInfoBss_004A30E0[5].k0 = 0x2729;
            if (gItemMenuProcDrawInfoBss_004A30E0[6].k0 == 0x271A) {
                gItemMenuProcDrawInfoBss_004A30E0[5].k0 = 0x272E;
            }
            break;
        case 3:
            gItemMenuProcDrawInfoBss_004A30E0[5].k0 = 0x2728;
            break;
        case 5:
            gItemMenuProcDrawInfoBss_004A30E0[5].k0 = 0x2719;
            break;
        case 18:
            gItemMenuProcDrawInfoBss_004A30E0[5].k0 = 0x2733;
            break;
        }
    }
}
#undef Item_GetTable_1_001AFC90

/* Hud_UpdateWeaponSlots_0_0019C560 */
#define Item_GetTable_1_001AFC90 Item_GetTable_1_001AFC90__as_Hud_UpdateWeaponSlots_0_0019C560
Rec *Item_GetTable_1_001AFC90__as_Hud_UpdateWeaponSlots_0_0019C560(void);
#define gItemMenuProcDrawInfoBss_004A30E0 gItemMenuProcDrawInfoBss_004A30E0__as_Hud_UpdateWeaponSlots_0_0019C560
extern Out gItemMenuProcDrawInfoBss_004A30E0__as_Hud_UpdateWeaponSlots_0_0019C560[];

void Hud_UpdateWeaponSlots_0_0019C560(void) {
    s32 i;
    s32 idx;
    s32 max;
    u8 *cur;
    s16 *id;
    Out *o;
    Rec *r;
    u8 v;

    i = 0;
    max = 0;
    id = gHudDrawRodata_001FD3F8;
    o = gItemMenuProcDrawInfoBss_004A30E0;
    do {
        idx = (s16)Equip_GetSlotItem_1_001CCD90(*id);
        cur = Equip_GetSlotEntry_0_001CCD30(*id);
        r = &Item_GetTable_1_001AFC90()[idx];
        switch (r->type) {
        case 1:
            max = r->max;
            break;
        case 2:
            max = r->max;
            break;
        }
        if (cur != NULL) {
            v = *cur;
            if ((s32)(100.0f * ((f32)v / (f32)max)) < 20 || (v & 0xFF) < 5) {
                o->st = 1;
            } else {
                o->st = 0;
            }
        } else {
            o->st = 2;
        }
        i++;
        id++;
        o++;
    } while (i < 7);
}
#undef Item_GetTable_1_001AFC90
#undef gItemMenuProcDrawInfoBss_004A30E0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gHudDrawSbss_002020D4, gHudDrawSbss_002021C4, gHudDrawSbss_002021C8 */
f32 gHudDrawSbss_002020D4;
s32 gHudDrawSbss_002021C4;
s32 gHudDrawSbss_002021C8;
#endif



#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/databook_item_reset_data.c): D_001F306C__grp: gHudDrawData_001F306C@0x0 */
s32 D_001F306C__grp[0x1] __attribute__((aligned(4))) = { 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/databook_item_reset_data.c): D_001F307C__grp: gHudDrawData_001F307C@0x0 */
s32 D_001F307C__grp[0x1] __attribute__((aligned(4))) = { 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/item_menu_draw_bss.c): D_004A28E0__grp: gHudDrawBss_004A28E0@0x0 */
u8 D_004A28E0__grp[0x3f0] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/item_menu_draw_bss.c): D_004A2CE0__grp: gHudDrawBss_004A2CE0@0x0 */
u8 D_004A2CE0__grp[0x3f0] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/databook_item_reset_data.c): gHudDrawData_001F3060, gHudDrawData_001F3070 */
f32 gHudDrawData_001F3060[0x1] = { 0.0f };
f32 gHudDrawData_001F3070[0x1] = { 0.0f };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/databook_item_reset_rodata.c): D_001FD3F8__grp: gHudDrawRodata_001FD3F8@0x0, gHudDrawRodata_001FD402@0xa, gHudDrawRodata_001FD404@0xc, gHudDrawRodata_001FD408@0x10, gHudDrawRodata_001FD410@0x18 */
char D_001FD3F8__grp[0x20] __attribute__((aligned(8))) = "\002\000\003\000\006\000\005\000\004\000\001\000\000\000\000\000HP\000\000\000\000\000\000%4d/\000\000\000\000";
#endif
