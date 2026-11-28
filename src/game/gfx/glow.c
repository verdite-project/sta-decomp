#include "common.h"
#include "m2c.h"
#include "game/gfx.h"
#include "game/data.h"
typedef struct { char pad[0x40]; f32 v[3]; f32 f4c; unsigned char on : 1; char p51[3]; f32 f54; char rest[8]; } E;
typedef struct { u16 n; u16 idx[64]; } G;
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { char pad[0x50]; unsigned char b0 : 1; unsigned char b1 : 1; char pad2[0xF]; } BF;
extern E gTextColourBss_0030D9A0[256];
extern s8 gGlowInitBss_0030D180[];
extern s32 D_0030D188[];
void Glow_GetParams_0_0015D760(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4);
void Glow_SetParams_0_0015D800(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0, f32 fparg1);
s32 Glow_FindNear_0_0015DA00(s64 arg0, s32 arg1, s32 *arg2, f32 *arg3);
void sceVu0AddVector(f32 *v0, f32 *v1, f32 *v2);
void sceVu0CopyVector(s8 *, s8 *);
Q* GsPkt_Alloc_3_00154A80(s32);
f32 Vec_DistSq_3_0015DF20(s8 *, f32 *);

/* Glow_OffsetAll_0_0015D5A0 */
void Glow_OffsetAll_0_0015D5A0(f32 *d)
{
    s32 i;
    E *e = gTextColourBss_0030D9A0;
    for (i = 0; i < 256; i++, e++) {
        if (e->on) {
            f32 s = e->f54;
            sceVu0AddVector(e->v, e->v, d);
            e->f4c = -1.0 / (s * s);
        }
    }
}

/* Glow_Reset_0_0015D650 */
#define gTextColourBss_0030D9A0 gTextColourBss_0030D9A0__as_Glow_Reset_0_0015D650
extern s8 gTextColourBss_0030D9A0__as_Glow_Reset_0_0015D650[];

void Glow_Reset_0_0015D650(void) {
    s32 i;
    s32 j;
    G *g;
    s32 k;
    s8 *e;

    for (i = 0; i < 8; i++) {
        g = (G *)(gGlowInitBss_0030D180 + i * 0x82 + 0x408);
        k = 0;
        for (j = 0; j < g->n; j++) {
            u16 v = g->idx[j];
            e = gTextColourBss_0030D9A0 + v * 0x60;
            if (k != j) g->idx[k] = v;
            if (((u64)((s64)M2C_FIELD(e, u8 *, 0x50) << 0x3E) >> 0x3F) == 0) k++;
        }
        g->n = k;
    }
    for (i = 0; i < 0x100; i++) {
        e = gTextColourBss_0030D9A0 + i * 0x60;
        if (M2C_FIELD(e, u8 *, 0x50) & 1) {
            sceVu0CopyVector(e + (gSfxAllSbss_00201F2C << 5), e + 0x40);
        }
    }
}
#undef gTextColourBss_0030D9A0

/* Glow_GetParams_0_0015D760 */
#define sceVu0CopyVector sceVu0CopyVector__as_Glow_GetParams_0_0015D760
void sceVu0CopyVector__as_Glow_GetParams_0_0015D760(s32, u8 *);
#define gTextColourBss_0030D9A0 gTextColourBss_0030D9A0__as_Glow_GetParams_0_0015D760
extern s32 gTextColourBss_0030D9A0__as_Glow_GetParams_0_0015D760[];

void Glow_GetParams_0_0015D760(s32 arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4) {
    u8 *temp_16;

    temp_16 = (u8 *) ((s32 *)((u8 *)gTextColourBss_0030D9A0 + (arg0 * 0x60)));
    sceVu0CopyVector(arg1, temp_16 + 0x40);
    sceVu0CopyVector(arg2, temp_16 + (gSfxAllSbss_00201F2C << 5) + 0x10);
    if (arg3 != NULL) {
        *arg3 = M2C_FIELD(temp_16, f32 *, 0x54);
    }
    if (arg4 != NULL) {
        *arg4 = M2C_FIELD(temp_16, f32 *, 0x58);
    }
}
#undef sceVu0CopyVector
#undef gTextColourBss_0030D9A0

/* Glow_SetParams_0_0015D800 */
#define sceVu0CopyVector sceVu0CopyVector__as_Glow_SetParams_0_0015D800
void sceVu0CopyVector__as_Glow_SetParams_0_0015D800(u8 *, u8 *);
#define gTextColourBss_0030D9A0 gTextColourBss_0030D9A0__as_Glow_SetParams_0_0015D800
extern s32 gTextColourBss_0030D9A0__as_Glow_SetParams_0_0015D800[];

void Glow_SetParams_0_0015D800(s32 arg0, u8 *arg1, u8 *arg2, f32 fparg0, f32 fparg1) {
    f32 var_f21;
    s32 var_20;
    u8 *temp_16;
    u8 *var_19;

    temp_16 = (u8 *) ((s32 *)((u8 *)gTextColourBss_0030D9A0 + (arg0 * 0x60)));
    var_f21 = fparg1;
    if (!(M2C_FIELD(temp_16, u8 *, 0x50) & 1)) {
        var_f21 = -1.0f;
    }
    var_20 = 0;
    var_19 = (u8 *) (temp_16);
    do {
        sceVu0CopyVector(var_19, arg1);
        sceVu0CopyVector(var_19 + 0x10, arg2);
        M2C_FIELD(var_19, f32 *, 0xC) = (f32) (-1.0f / (fparg0 * fparg0));
        var_20 += 1;
        M2C_FIELD(var_19, f32 *, 0x1C) = var_f21;
        var_19 += 0x20;
    } while (var_20 < 2);
    sceVu0CopyVector(temp_16 + 0x40, temp_16);
    M2C_FIELD(temp_16, f32 *, 0x54) = fparg0;
    M2C_FIELD(temp_16, f32 *, 0x58) = var_f21;
}
#undef sceVu0CopyVector
#undef gTextColourBss_0030D9A0

/* Glow_DrawList_0_0015D900 */
#define gTextColourBss_0030D9A0 gTextColourBss_0030D9A0__as_Glow_DrawList_0_0015D900
extern u8 gTextColourBss_0030D9A0__as_Glow_DrawList_0_0015D900[];

s32 Glow_DrawList_0_0015D900(s32 n, s32 *ids) {
    s32 i;
    s32 cnt;
    u8 *base;
    s32 m;
    Q *p;
    s32 *q;
    s32 k;
    Q t;

    i = 0;
    cnt = 0;
    if (i < n) {
        q = ids;
        m = n;
        k = 0x3C;
        do {
            base = gTextColourBss_0030D9A0 + *q * 0x60;
            p = GsPkt_Alloc_3_00154A80(1);
            t.q = 0;
            t.w[0] = 0x30000002;
            t.w[1] = (u32)(base + gSfxAllSbss_00201F2C * 0x20);
            t.w[3] = k | 0x6C020000;
            p->q = t.q;
            i++;
            cnt++;
            q++;
            k += 2;
        } while (i < m);
    }
    GsPkt_Commit_1_00154A70();
    return cnt;
}
#undef gTextColourBss_0030D9A0

/* Glow_FindNear_0_0015DA00 */
#define gTextColourBss_0030D9A0 gTextColourBss_0030D9A0__as_Glow_FindNear_0_0015DA00
extern s8 gTextColourBss_0030D9A0__as_Glow_FindNear_0_0015DA00[];

s32 Glow_FindNear_0_0015DA00(s64 arg0, s32 arg1, s32 *arg2, f32 *arg3) {
    s32 j;
    s32 i;
    s32 n;
    s32 id;
    s8 *s1;
    u16 *cnt;
    u16 *fp;
    s8 *e;
    f32 r;

    n = 0;
    s1 = gGlowInitBss_0030D180;
    for (i = 0; i < 8; i++, s1 += 0x82) {
        cnt = (u16 *)(s1 + 0x408);
        if (arg0 & (1 << i)) {
            for (j = 0, fp = cnt; j < *cnt; j++, fp++) {
                id = fp[1];
                e = gTextColourBss_0030D9A0 + id * 0x60;
                r = M2C_FIELD(e, f32 *, 0x54) + arg3[3];
                if (Vec_DistSq_3_0015DF20(e + (gSfxAllSbss_00201F2C << 5), arg3) < r * r) {
                    arg2[n++] = id;
                    if (n == arg1) return n;
                }
            }
        }
    }
    return n;
}
#undef gTextColourBss_0030D9A0

/* Glow_Enable_0_0015DB60 */
#define gGlowInitBss_0030D180 gGlowInitBss_0030D180__as_Glow_Enable_0_0015DB60
extern s32 gGlowInitBss_0030D180__as_Glow_Enable_0_0015DB60[];
#define gTextColourBss_0030D9A0 gTextColourBss_0030D9A0__as_Glow_Enable_0_0015DB60
extern BF gTextColourBss_0030D9A0__as_Glow_Enable_0_0015DB60[];

void Glow_Enable_0_0015DB60(s32 arg0) {
    BF *t = &gTextColourBss_0030D9A0[arg0];
    s32 temp_5;
    t->b1 = 1;
    t->b0 = 0;
    temp_5 = *gGlowInitBss_0030D184;
    (*gGlowInitBss_0030D184) += 1;
    D_0030D188[temp_5] = arg0;
    (*gGlowInitBss_0030D180) -= 1;
}
#undef gGlowInitBss_0030D180
#undef gTextColourBss_0030D9A0

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif
