#include "m2c.h"
#include "common.h"
#include "game/ui.h"
#include "game/math.h"
#include "game/data.h"
#include "game/save.h"
typedef union { u32 w; u8 b[4]; } Col;
typedef struct { f32 v[4]; } H;
typedef struct { u8 pad[4]; u16 x4; } R;
typedef struct { f32 x, y; } V2;
typedef struct { u32 idx; s32 f4; u8 pad8[0x24]; f32 x; f32 y; u8 pad34[0xC]; } Ent;
typedef struct { u32 n; Ent *p; } L;
typedef struct { u8 pad[0x24]; L *l; } O;
#ifndef NONMATCHING
extern f32 gDatabookCharDrawSdata_00201D34;
#else
/* data twins (src/game/data/sdata.c): gDatabookCharDrawSdata_00201D34 */
static f32 gDatabookCharDrawSdata_00201D34 = -2.99f;
#endif
extern s32 gDbCharProcDrawInfoSbss_00202188;
void DbChar_Draw_0_00195E30(u8 *arg0);
void DbChar_DrawStats_1_00195F70(f32 f);
void DbChar_DrawRing_0_00196070(s32 arg, f32 ang);
s32 DbChar_FindEntry_0_00195900(s32);
void Text_Draw_2_001875C0(s32, s32, Col, f32, f32, f32);
void memset(void *, s32, s32);
void Menu_DrawFrame_0_00185390(f32, s32, s32, s32);
void Menu_DrawStatRing_0_00186440(f32, H *, H *, H *, H *);
R* DbChar_Find_0_00195770(s32);
void DbChar_CalcStatBars_0_00196D10(H *, H *, H *, H *, R *);
O* MenuLayout_Get_1_00189050(s32);
s8* MenuLayout_GetSub_1_00189020(s32);
f32 Vec2_Angle_1_00187460(V2 *, V2 *);
f32 sinf(f32);
f32 cosf(f32);
f32 sqrtf(f32);
void DbCharProc_DrawInfo_0_00196330(void);
void Ui_DrawList_1_001829B0(Ent *, s8 *, void (*)(void), s32);

/* DbChar_Draw_0_00195E30 */
void DbChar_Draw_0_00195E30(u8 *arg0) {
    Col c;
    s32 h;
    s32 id;

    id = gDatabookCharUpdateWrapBss_004A11A0[gDatabookCharUpdateWrapBss_004A13E0[0]];
    Menu_SetFlags_0_0018A310(0xE);
    if (arg0[8] == 0x1A) {
        gDatabookCharDrawSdata_00201D34 = Approachf_3_00187770(gDatabookCharDrawSdata_00201D34, -0.02f, 3.5f);
    } else {
        gDatabookCharDrawSdata_00201D34 = Approachf_3_00187770(gDatabookCharDrawSdata_00201D34, -2.99f, 3.5f);
    }
    UiAnim_UpdateAll_1_0017F5C0();
    if (!(gDatabookCharDrawSdata_00201D34 <= -2.99f)) {
        DbChar_DrawRing_0_00196070(id, gDatabookCharDrawSdata_00201D34);
        DbChar_DrawStats_1_00195F70(gDatabookCharDrawSdata_00201D34);
    }
    h = DbChar_FindEntry_0_00195900(id);
    c.w = 0x80FFFFFF;
    if (Bestiary_IsSeen_2_001A9EC0(id)) {
        Text_Draw_2_001875C0(h, 2, c, 622.0f, 17.0f, 1.0f);
    }
}

/* DbChar_DrawStats_1_00195F70 */
void DbChar_DrawStats_1_00195F70(f32 f) {
    H a;
    H b;
    H c;
    H d;
    R *r;
    s32 id;
    id = gDatabookCharUpdateWrapBss_004A11A0[gDatabookCharUpdateWrapBss_004A13E0[0]];
    r = DbChar_Find_0_00195770(id);
    DbChar_CalcStatBars_0_00196D10(&a, &b, &c, &d, r);
    if (Bestiary_IsSeen_2_001A9EC0(id)) {
        Menu_DrawStatRing_0_00186440(f, &a, &b, &c, &d);
        gDbCharProcDrawInfoSbss_00202188 = r->x4;
    } else {
        memset(&a, -1, 0x10);
        memset(&b, -1, 0x10);
        Menu_DrawStatRing_0_00186440(f, &a, &b, 0, 0);
        gDbCharProcDrawInfoSbss_00202188 = 0;
    }
    Menu_DrawFrame_0_00185390(f, 1, gDatabookCharUpdateWrapSbss_0020218C, gDatabookCharUpdateWrapBss_004A13E0[0]);
}

/* DbChar_DrawRing_0_00196070 */
void DbChar_DrawRing_0_00196070(s32 arg, f32 ang) {
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
        Ui_DrawList_1_001829B0(&e, base + l->p[i].idx * 8, DbCharProc_DrawInfo_0_00196330, arg);
    }
}
