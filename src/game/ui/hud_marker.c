#include "common.h"
#include "m2c.h"
#include "actor.h"
#include "game/ui.h"
typedef struct { s32 a; s32 wait; s32 c; char pc[4]; f32 f; char p14[0x18]; } E;
typedef struct { s32 x0, x4, x8; f32 xC, x10, x14, x18; s32 x1C, x20, x24; u8 c[4]; } P_Hud_RandomizeMarker_0_001BC170;
typedef struct { u8 pad[0x18]; s8 *o; u8 pad2[0x3A1 - 0x1C]; u8 r:7; u8 b7:1; } P_Hud_AddMarker_0_001BC320;
extern E gHudMarkerBss_004B4BE0[2];
void Hud_RandomizeMarker_0_001BC170(u8 *col);
void Hud_AddMarker_0_001BC320(f32 *a0, s32 a1);
s32 rand(void);
u32 Rand_Next_3_0015ED20(void);
f32 sqrtf(f32);
s32 Game_GetFlag54b6_0_001A9410(void);
void sceVu0SubVector(Vec *, f32 *, s8 *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 atan2f(f32, f32);
f32 fabsf(f32);

/* Hud_ResetMarkers_0_001BC0E0 */
void Hud_ResetMarkers_0_001BC0E0(void)
{
    s32 i;
    E *e = gHudMarkerBss_004B4BE0;
    for (i = 0; i < 2; i++, e++) {
        if (e->wait > 0) {
            e->wait--;
        } else if (e->a > 0) {
            if (e->a < e->c)
                e->f += (f32)e->a / (f32)e->c;
            e->a--;
        }
    }
}

/* Hud_RandomizeMarker_0_001BC170 */
#define gHudMarkerBss_004B4BE0 gHudMarkerBss_004B4BE0__as_Hud_RandomizeMarker_0_001BC170
extern P_Hud_RandomizeMarker_0_001BC170 gHudMarkerBss_004B4BE0__as_Hud_RandomizeMarker_0_001BC170[];

void Hud_RandomizeMarker_0_001BC170(u8 *col) {
    s32 i;
    P_Hud_RandomizeMarker_0_001BC170 *p;
    for (i = 0, p = gHudMarkerBss_004B4BE0; i < 2; i++, p++) {
        p->x0 = 60;
        p->x4 = i * 2;
        p->x8 = 55 - (1 - i) * 2;
        p->xC = rand() % 100 - 50;
        p->x10 = rand() % 60 - 30;
        p->x14 = p->x18 = 1.5f + (u16)Rand_Next_3_0015ED20() * 1.5259022e-05f;
        p->x1C = rand() % 2 ? 1 : -1;
        p->x20 = rand() % 2 ? 1 : -1;
        p->x24 = i;
        p->c[0] = col[0];
        p->c[1] = col[1];
        p->c[2] = col[2];
        p->c[3] = col[3];
    }
}
#undef gHudMarkerBss_004B4BE0

/* Hud_AddMarker_0_001BC320 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define Hud_RandomizeMarker_0_001BC170 Hud_RandomizeMarker_0_001BC170__as_Hud_AddMarker_0_001BC320
void Hud_RandomizeMarker_0_001BC170__as_Hud_AddMarker_0_001BC320(s32 *);
s32 D_001F38C0[0xc] = { -0x7fffdfc0, -0x7fffcdce, -0x7fffbfce, -0x7fffd800, -0x7fcdf000, -0x7fd5fff0, -0x80000000, -0x7fbfbfc0, -0x80000000 };
static inline P_Hud_AddMarker_0_001BC320 *cur(void) {
    if (gPlayerSbss_002022E4 == 0) return 0;
    if (gPlayerSbss_002022E4->unk518 == 0) return 0;
    return (P_Hud_AddMarker_0_001BC320 *)(gPlayerSbss_002022E4->unk518 + 0x180);
}

void Hud_AddMarker_0_001BC320(f32 *a0, s32 a1) {
    P_Hud_AddMarker_0_001BC320 *p;
    f32 y;
    f32 t;
    Vec v;
    p = cur();
    if (p == 0) return;
    if (p->b7) return;
    if (!Game_GetFlag54b6_0_001A9410()) return;
    if (a1 < 0 || a1 == 6 || a1 == 8) return;
    sceVu0SubVector(&v, a0, p->o);
    if (!(sqrtf(sceVu0InnerProduct(&v, &v)) <= 400.0f)) return;
    sceVu0SubVector(&v, a0, p->o);
    t = atan2f(-v.x, -v.z) - WRAP(*(f32 *)(p->o + 0x24));
    if (fabsf(WRAP(t)) <= 0.69813174f) {
        y = v.y;
        v.y = 0.0f;
        t = atan2f(-y, sqrtf(sceVu0InnerProduct(&v, &v))) - *(f32 *)(p->o + 0x20);
        if (fabsf(WRAP(t)) <= 0.69813174f) {
            Hud_RandomizeMarker_0_001BC170(&D_001F38C0[a1]);
        }
    }
}
#undef Hud_RandomizeMarker_0_001BC170

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): gHudMarkerBss_004B4BE0 */
E gHudMarkerBss_004B4BE0[2];
#endif
