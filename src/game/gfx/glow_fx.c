#include "common.h"
#include "game/gfx.h"
#include "game/data.h"
typedef struct { s32 h; f32 t; f32 d; s32 pad; u8 a[0x10]; u8 b[0x10]; f32 x; f32 y; s32 pad2[2]; } E_GlowFx_Update_0_001E0C10;
typedef struct { s32 h; f32 x4; f32 x8; char p[0x34]; } E_GlowFx_Stop_0_001E0D30;
typedef struct { s32 h; char p[0x3C]; } E_GlowFx_StopAll_0_001E0E80;
typedef struct { s32 h; s32 pad[3]; f32 a[4]; f32 b[4]; f32 x; f32 y; s32 pad2[2]; } E_GlowFx_SetParams_0_001E0F30;
typedef struct { s32 h; s32 x4, x8, xC; char p[0x20]; f32 x30, x34; char q[8]; } E_GlowFx_Start_0_001E1050;
typedef struct { s32 v; char p[0x3C]; } F;
typedef struct { s32 v; char pad[0x3C]; } E_GlowFx_Init_0_001E1200;
extern E_GlowFx_Update_0_001E0C10 D_004BAC50[16];
#ifndef NONMATCHING
extern u8 D_002023AC;
#else
/* data twins (src/game/data/sbss.c): D_002023AC */
static u8 D_002023AC;
#endif
extern Vec D_001F2160;
s32 GlowFx_Stop_0_001E0D30(s32 i, s32 unused, f32 t);
s32 GlowFx_SetParams_0_001E0F30(s32 i, s32 p, s32 q, f32 x, f32 y);
s32 GlowFx_Start_0_001E1050(void);
void Glow_SetParams_0_0015D800(s32, u8 *, u8 *, f32, f32);
void sceVu0CopyVector(void *, s32);
s32 Glow_Add_0_0015DBF0(s32, Vec *, Vec *, f32, f32);

/* GlowFx_Update_0_001E0C10 */
void GlowFx_Update_0_001E0C10(f32 dt)
{
    s32 i;
    E_GlowFx_Update_0_001E0C10 *e = D_004BAC50;
    for (i = 0; i < 16; i++, e++) {
        if (e->h != -1 && e->d != 0.0f) {
            f32 t = e->t - dt;
            e->t = t;
            if (t < 0.0f) {
                s32 ok;
                if (i < 0 || i >= 16)
                    ok = 0;
                else if (e->h == -1)
                    ok = 0;
                else
                    ok = 1;
                if (ok) {
                    Glow_Enable_0_0015DB60(e->h);
                    e->h = -1;
                    D_002023AC--;
                }
            } else {
                f32 r = t / e->d;
                Glow_SetParams_0_0015D800(e->h, e->a, e->b, r * e->x, r * e->y);
            }
        }
    }
}

/* GlowFx_Stop_0_001E0D30 */
#define D_004BAC50 D_004BAC50__as_GlowFx_Stop_0_001E0D30
extern E_GlowFx_Stop_0_001E0D30 D_004BAC50__as_GlowFx_Stop_0_001E0D30[16];

static inline s32 valid_GlowFx_Stop_0_001E0D30(s32 i)
{
    s32 ok;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    return ok;
}

static inline s32 release(s32 i)
{
    s32 ok;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    if (!ok)
        return 0;
    Glow_Enable_0_0015DB60(D_004BAC50[i].h);
    D_004BAC50[i].h = -1;
    D_002023AC--;
    return 1;
}

s32 GlowFx_Stop_0_001E0D30(s32 i, s32 unused, f32 t)
{
    if (!valid_GlowFx_Stop_0_001E0D30(i))
        return 0;
    if (t == 0.0f)
        return release(i);
    D_004BAC50[i].x4 = t;
    D_004BAC50[i].x8 = t;
    return 1;
}
#undef D_004BAC50

/* GlowFx_StopAll_0_001E0E80 */
#define D_004BAC50 D_004BAC50__as_GlowFx_StopAll_0_001E0E80
extern E_GlowFx_StopAll_0_001E0E80 D_004BAC50__as_GlowFx_StopAll_0_001E0E80[16];

s32 GlowFx_StopAll_0_001E0E80(void)
{
    s32 i;
    E_GlowFx_StopAll_0_001E0E80 *e = D_004BAC50;
    for (i = 0; i < 16; i++, e++) {
        s32 ok;
        if (i < 0 || i >= 16)
            ok = 0;
        else if (e->h == -1)
            ok = 0;
        else
            ok = 1;
        if (ok) {
            Glow_Enable_0_0015DB60(e->h);
            e->h = -1;
            D_002023AC--;
        }
    }
    return 1;
}
#undef D_004BAC50

/* GlowFx_SetParams_0_001E0F30 */
#define D_004BAC50 D_004BAC50__as_GlowFx_SetParams_0_001E0F30
extern E_GlowFx_SetParams_0_001E0F30 D_004BAC50__as_GlowFx_SetParams_0_001E0F30[16];
#define Glow_SetParams_0_0015D800 Glow_SetParams_0_0015D800__as_GlowFx_SetParams_0_001E0F30
void Glow_SetParams_0_0015D800__as_GlowFx_SetParams_0_001E0F30(s32, s32, s32, f32, f32);

s32 GlowFx_SetParams_0_001E0F30(s32 i, s32 p, s32 q, f32 x, f32 y)
{
    s32 ok;
    s32 off;
    E_GlowFx_SetParams_0_001E0F30 *e;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    if (!ok)
        return 0;
    off = i << 6;
    e = (E_GlowFx_SetParams_0_001E0F30 *)((u8 *)D_004BAC50 + off);
    sceVu0CopyVector(e->a, p);
    sceVu0CopyVector(e->b, q);
    *(f32 *)((u8 *)&D_004BAC50[0].x + off) = x;
    *(f32 *)((u8 *)&D_004BAC50[0].y + off) = y;
    Glow_SetParams_0_0015D800(e->h, p, q, x, y);
    return 1;
}
#undef Glow_SetParams_0_0015D800
#undef D_004BAC50

/* GlowFx_Start_0_001E1050 */
#define D_004BAC50 D_004BAC50__as_GlowFx_Start_0_001E1050
extern E_GlowFx_Start_0_001E1050 D_004BAC50__as_GlowFx_Start_0_001E1050[16];

#define Glow_SetParams_0_0015D800 Glow_SetParams_0_0015D800__as_GlowFx_Start_0_001E1050
void Glow_SetParams_0_0015D800__as_GlowFx_Start_0_001E1050(s32, Vec *, Vec *, f32, f32);
#define sceVu0CopyVector sceVu0CopyVector__as_GlowFx_Start_0_001E1050
void sceVu0CopyVector__as_GlowFx_Start_0_001E1050(void *, void *);
static inline s32 find(void) {
    s32 i;
    E_GlowFx_Start_0_001E1050 *e;
    if (D_002023AC == 16) return -1;
    for (i = 0, e = D_004BAC50; i < 16; i++, e++) if (e->h == -1) return i;
    return -1;
}
static inline s32 valid_GlowFx_Start_0_001E1050(s32 i) {
    s32 ok;
    if (i < 0 || i >= 16)
        ok = 0;
    else if (D_004BAC50[i].h == -1)
        ok = 0;
    else
        ok = 1;
    return ok;
}
static inline void setup(s32 i) {
    s32 ok;
    E_GlowFx_Start_0_001E1050 *f;
    if (i < 0 || i >= 16) ok = 0; else if (D_004BAC50[i].h == -1) ok = 0; else ok = 1;
    if (ok) {
        f = (E_GlowFx_Start_0_001E1050 *)((s32)D_004BAC50 + (i << 6));
        sceVu0CopyVector(f->p, &D_001F2160);
        sceVu0CopyVector(f->p + 0x10, &D_003139A0);
        D_004BAC50[i].x30 = 0.0f;
        D_004BAC50[i].x34 = 0.0f;
        Glow_SetParams_0_0015D800(f->h, &D_001F2160, &D_003139A0, 0.0f, 0.0f);
    }
}
s32 GlowFx_Start_0_001E1050(void) {
    s32 i = find();
    if (i != -1) {
        s32 h = Glow_Add_0_0015DBF0(0, &D_001F2160, &D_003139A0, 0.0f, 0.0f); E_GlowFx_Start_0_001E1050 *e = &D_004BAC50[i]; e->h = h; D_004BAC50[i].x4 = 0; D_004BAC50[i].x8 = 0;
        setup(i);
        D_002023AC++;
    }
    return i;
}
#undef Glow_SetParams_0_0015D800
#undef sceVu0CopyVector
#undef D_004BAC50

/* GlowFx_Init_0_001E1200 */
#define D_004BAC50 D_004BAC50__as_GlowFx_Init_0_001E1200
extern E_GlowFx_Init_0_001E1200 D_004BAC50__as_GlowFx_Init_0_001E1200[16];

void GlowFx_Init_0_001E1200(void)
{
    s32 i;
    for (i = 15; i >= 0; i--)
        D_004BAC50[i].v = -1;
}
#undef D_004BAC50
