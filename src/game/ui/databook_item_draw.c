#include "m2c.h"
#include "include_asm.h"
#include "actor.h"
#include "game/data.h"
#include "game/ui.h"
#include "game/math.h"
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { u8 pad[0x20]; L *l; } O;
typedef struct { u128 q[2]; } Q2;
typedef UiArg Arg;
typedef struct { s32 state; s32 btn; s8 x8; s8 pad[5]; u8 xE; } P;
extern s32 *D_00201D3C;
#ifdef NONMATCHING
extern u8 D_00495B60[];
#endif
#ifndef NONMATCHING
extern f32 D_0020219C;
#else
/* data twins (src/game/data/sbss.c): D_0020219C */
static f32 D_0020219C;
#endif
#ifndef NONMATCHING
extern f32 D_002021A0;
#else
/* data twins (src/game/data/sbss.c): D_002021A0 */
static f32 D_002021A0;
#endif
extern s32 D_004A1434[];
extern Q2 D_001F2F40;
extern s32 D_004A1438[];
extern f32 D_004A143C[];
extern Flags8 D_004A1444[];
#ifndef NONMATCHING
extern s32 D_00202194;
#else
/* data twins (src/game/data/sbss.c): D_00202194 */
static s32 D_00202194;
#endif
void DbItem_Open_0_001979C0(s32 arg0);
void DbItem_Update_0_00197B80(P *p);
void memset(void *, s32, s32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Menu_DrawStatRing_0_00186440(f32, f32 *, f32 *, f32 *, f32 *);
void Equip_CalcStatBars_0_0019A370(f32 *, f32 *, f32 *, f32 *, s32);
s32 Save_TestItemBit_1_001A9B40(s16);
void Menu_DrawItemFrame_0_001DF470(f32, s32);
O* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
f32 Vec2_Angle_1_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void DbItemProc_DrawInfo_0_001973F0(void);
void Ui_DrawList_1_001829B0(Ent *, s8 *, void (*)(void), s32);
void UiAnim_SetColor_0_0017F890(s32, Q2 *, Arg *);
s32 UiAnim_SetTarget_1_0017F470(f32, s32, s32);
void DbItem_GetListName_1_00197F30(void);
void DbItemProc_Pos_0_00198100(void);
void Ui_LoadItemImage_3_00183DC0(s32);
s32 ItemSort_GetEntry_0_00195B80(s32, s32 *);
void Snd_PlaySe_3_00131600(s32, u8);

/* DbItem_DrawStats_0_00196F90 */
/* DbItem_DrawStats_0_00196F90 */

void DbItem_DrawStats_0_00196F90(f32 arg0) {
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    s32 id;
    s32 ok;
    s32 m;
    f32 t;

    Equip_CalcStatBars_0_0019A370(a, b, c, d, D_00201D3C[D_004A1430[0]]);
    id = D_00201D3C[D_004A1430[0]];
    if (id < 0) {
        ok = 0;
    } else {
        ok = Save_TestItemBit_1_001A9B40(id);
    }
    if (ok != 0) {
        Menu_DrawStatRing_0_00186440(arg0, a, b, c, d);
    } else {
        memset(a, -1, 0x10);
        memset(b, -1, 0x10);
        Menu_DrawStatRing_0_00186440(arg0, a, b, NULL, NULL);
    }
    if (D_004A1434[0] == 1) {
        D_002021A0 = 10.0f;
    }
    if (!(D_002021A0 <= 0.0f)) {
        D_002021A0 -= 1.0f;
        D_0020219C = Approachf_3_00187770(D_0020219C, -2.99f, 3.5f);
    } else {
        D_0020219C = Approachf_3_00187770(D_0020219C, -0.02f, 3.5f);
    }
    Menu_DrawFrame_0_00185390(arg0 + D_0020219C, 1, D_00202198, D_004A1430[0]);
    t = arg0 + D_0020219C;
    m = D_00201D38;
    Menu_DrawItemFrame_0_001DF470(t, m == 1 ? -1 : m);
}

/* DbItem_DrawRing_0_00197130 */

void DbItem_DrawRing_0_00197130(s32 arg, f32 ang) {
    u32 i;
    L *l;
    s8 *base;
    Ent e;
    V2 q;
f32 d, a, t, dx, dy;
    l = MenuLayout_Get_1_00189050(2)->l;
    base = MenuLayout_GetSub_1_00189020(2);
    Menu_DrawBackground_0_00187B20(0);
    for (i = 0; i < l->n; i++) {
        e = l->p[i];
        {
        V2 p = {0};
        if (e.f4 == 100) {
            p.x = -70.0f;
            p.y = 276.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - -70.0f;
        dy = e.y - 276.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = -70.0f + d * sinf(a);
        e.y = 276.0f + d * cosf(a);
        } else {
            p.x = 735.0f;
            p.y = 129.0f;
        q.x = e.x;
        q.y = e.y;
        dx = e.x - 735.0f;
        dy = e.y - 129.0f;
        d = sqrtf(dx * dx + dy * dy);
        t = Vec2_Angle_1_00187460(&q, &p);
        a = t + ang;
        e.x = 735.0f + d * sinf(a);
        e.y = 129.0f + d * cosf(a);
        }
        }
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, DbItemProc_DrawInfo_0_001973F0, arg);
    }
}

/* text_001973F0 */
#ifdef NONMATCHING
/* best-effort C: db_item_proc_draw_info.c */
#else
INCLUDE_ASM(DbItemProc_DrawInfo_0_001973F0);
#endif

/* DbItem_Open_0_001979C0 */
#define DbItem_Update_0_00197B80 DbItem_Update_0_00197B80__as_DbItem_Open_0_001979C0
void DbItem_Update_0_00197B80__as_DbItem_Open_0_001979C0();

/* DbItem_Open_0_001979C0 */
void DbItem_Update_0_00197B80__as_DbItem_Open_0_001979C0();

void DbItem_Open_0_001979C0(s32 arg0) {
    Q2 q;
    Arg a;

    if (!(D_004A143C[0] <= 0.0f)) {
        D_004A143C[0] -= 1.0f;
        D_004A1444[0].f.b1 = 0;
    } else {
        switch (D_004A1434[0]) {
        case 1:
            D_004A1430[0] = 0;
            D_00201D38 = D_004A1438[0];
            DbItem_LoadEntry_0_00197F90(D_00201D38);
            q = D_001F2F40;
            a.fn = DbItem_GetListName_1_00197F30;
            a.f = -3.0f;
            a.cb = DbItemProc_Pos_0_00198100;
            a.a = 0;
            a.b = 0;
            a.p = (s32)D_00201D3C;
            a.n = D_00202198;
            UiAnim_SetColor_0_0017F890(D_00201D38, &q, &a);
            UiAnim_SetVisible_1_0017F7C0(D_00201D38, 1, 1);
            UiAnim_SetTarget_1_0017F470(D_004A1430[0], D_00201D38, 1);
        }
        D_004A1434[0] = 0;
        D_004A1438[0] = 0;
        D_004A1444[0].f.b1 = 1;
        D_004A1440[0] += 8.0f;
        if (!(D_004A1440[0] <= 128.0f)) {
            D_004A1440[0] = 128.0f;
        }
    }
    if (D_004A1444[0].f.b1) {
        DbItem_Update_0_00197B80(arg0);
    }
}

/* DbItem_Update_0_00197B80 */

#undef DbItem_Update_0_00197B80
void DbItem_Update_0_00197B80(P *p) {
    s32 sel;

    switch (p->state) {
    case 25:
        D_00201D38 = 6;
        D_004A1430[0] = 0;
        D_00202194 = 0;
        DbItem_LoadEntry_0_00197F90(6);
        DbItem_ResetLayout_0_00197DD0();
        break;
    case 22:
        sel = D_004A1430[0];
        if (p->btn & 0x4000) {
            Snd_PlaySe_3_00131600(0x69, p->xE);
            p->x8 = 0x18;
            p->btn = 0;
            p->state = 0x1A;
            UiAnim_SetVisible_1_0017F7C0(D_00201D38, 0, 1);
            return;
        }
        if (p->btn & 0x10) {
            sel--;
        } else if (p->btn & 0x40) {
            sel++;
        } else if (p->btn & 0x480) {
            D_004A1430[0] = 0;
            D_004A1434[0] = 1;
            D_00202194--;
            D_004A1438[0] = ItemSort_GetEntry_0_00195B80(7, &D_00202194);
            *(s32 *)D_004A1440 = 0;
            UiAnim_SetVisible_1_0017F7C0(D_00201D38, 0, 1);
            Snd_PlaySe_3_00131600(0x66, p->xE);
            p->btn = 0;
        } else if (p->btn & 0x820) {
            D_004A1430[0] = 0;
            D_004A1434[0] = 1;
            D_00202194++;
            D_004A1438[0] = ItemSort_GetEntry_0_00195B80(7, &D_00202194);
            *(s32 *)D_004A1440 = 0;
            UiAnim_SetVisible_1_0017F7C0(D_00201D38, 0, 1);
            Snd_PlaySe_3_00131600(0x66, p->xE);
            p->btn = 0;
        }
        if (D_00202198 != 0) {
            sel = (sel + D_00202198) % D_00202198;
        }
        if (UiAnim_SetTarget_1_0017F470(D_004A1430[0], D_00201D38, 0) != 0) {
            if (D_004A1430[0] != sel) {
                Snd_PlaySe_3_00131600(0x66, p->xE);
            }
            D_004A1430[0] = sel;
        }
        p->btn = 0;
        break;
    }
    Ui_LoadItemImage_3_00183DC0(D_00201D3C[D_004A1430[0]]);
}
#undef DbItem_Update_0_00197B80

#ifdef NONMATCHING
#pragma explicit_zero_data on
extern u8 D_00495B60[];
/* data twins (src/game/data/sdata.c): D_00201D38, D_00201D3C */
s32 D_00201D38 = 6;
s32 *D_00201D3C = (s32 *)D_00495B60;
/* data twins (src/game/data/sbss.c): D_00202198 */
s32 D_00202198;
#endif
