#include "common.h"
#include "m2c.h"
#include "game/model.h"
#include "game/data.h"
typedef struct { u8 pad[6]; u16 n; u8 p8[0x38]; u8 d[1]; } Hd;
typedef struct { u8 pad[0xB0]; s32 off; } E_Mdl_GetFrameData_0_001715B0;
typedef struct { Hd *h; u8 *p; } O_Mdl_GetFrameData_0_001715B0;
typedef struct { u8 pad[0x14]; u16 cnt; } P;
typedef struct { P **pp; u16 pad4; u16 n; s8 pad8[0x38]; s8 data[1]; } O_Mdl_ResetBones_0_00171610;
typedef struct { O_Mdl_ResetBones_0_00171610 *o; s32 base; } H_Mdl_ResetBones_0_00171610;
typedef struct { u8 pad[0x10]; s32 *base; u16 n14; u16 n16; u8 pad18[0x28]; } Q;
typedef struct { Q **q; u16 x4; u16 n6; } O_Mdl_RunMotionEvents_0_001717A0;
typedef struct { u16 a; u16 b; u16 n; u16 c; u16 d; } E_Mdl_RunMotionEvents_0_001717A0;
typedef void (*CB)(O_Mdl_RunMotionEvents_0_001717A0 *, s32, u8, u8 *, f32, u8 *, u8);
typedef struct { s8 d[0x140]; } E_Mdl_BlendMotion_0_00171980;
typedef struct { s8 pad[6]; u16 n; s8 pad2[0x38]; s8 data[1]; } O_Mdl_BlendMotion_0_00171980;
typedef struct { u8 pad[6]; u16 x6; } A0;
typedef struct { s8 pad[4]; u8 x4; u8 p5; u16 n; s8 pad2[0x38]; s8 data[1]; } O_Mdl_AnimateSel_0_00171B30;
typedef struct { char p[4]; u8 b4; char p5; u16 h6; } H_Mdl_AnimateWrap_0_00171B70;
E_Mdl_GetFrameData_0_001715B0* Mdl_GetFrameData_0_001715B0(O_Mdl_GetFrameData_0_001715B0 *o);
inline s8* get(H_Mdl_ResetBones_0_00171610 *h, s32 sel);
void Mdl_ResetBones_0_00171610(H_Mdl_ResetBones_0_00171610 *h);
void Mdl_RunMotionEvents_0_001717A0(O_Mdl_RunMotionEvents_0_001717A0 *o, s32 idx, f32 t0, f32 t1, CB cb);
void Mdl_BlendMotion_0_00171980(O_Mdl_BlendMotion_0_00171980 *obj, u16 a1, s32 start, s32 count, f32 f, f32 g);
void Mdl_AnimateCur_0_00171AF0(A0 *a, s32 b, s32 c, s32 d);
void Mdl_AnimateSel_0_00171B30(O_Mdl_AnimateSel_0_00171B30 *obj, u16 a1, s32 sel, f32 f);
void Mdl_AnimateWrap_0_00171B70(H_Mdl_AnimateWrap_0_00171B70 *h, s32 a, f32 f);
void sceVu0CopyMatrix(s8 *, s8 *);
void memcpy(void *, void *, s32);
void Mtx_Lerp_2_0015EB20(E_Mdl_BlendMotion_0_00171980 *, E_Mdl_BlendMotion_0_00171980 *, E_Mdl_BlendMotion_0_00171980 *, f32);

/* Mdl_GetFrameData_0_001715B0 */
E_Mdl_GetFrameData_0_001715B0 *Mdl_GetFrameData_0_001715B0(O_Mdl_GetFrameData_0_001715B0 *o) {
    s32 k = gSfxAllSbss_00201F2C; Hd *h; E_Mdl_GetFrameData_0_001715B0 *e; if (o == NULL || (h = o->h) == NULL) return NULL;
    e = (E_Mdl_GetFrameData_0_001715B0 *)((s32)h + 0x40 + k * (h->n * 0x140 + 0x200)); e->off = o->p - (u8 *)h; return e;
}

/* Mdl_ResetBones_0_00171610 */
inline s8 *get(H_Mdl_ResetBones_0_00171610 *h, s32 sel) {
    O_Mdl_ResetBones_0_00171610 *o;
    s8 *p;
    if (h == NULL || (o = h->o) == NULL) {
        return NULL;
    }
    p = (s8 *)((s32)o->data + sel * (o->n * 0x140 + 0x200));
    *(s32 *)(p + 0xB0) = h->base - (s32)o;
    return p;
}

void Mdl_ResetBones_0_00171610(H_Mdl_ResetBones_0_00171610 *h) {
    P **pp;
    s32 i;
    s8 *b;
    s8 *a;

    a = get(h, gSfxAllSbss_00201F2C);
    b = get(h, !gSfxAllSbss_00201F2C);
    if (a == NULL || b == NULL) {
        return;
    }
    if (h == NULL || h->o == NULL) {
        return;
    }
    pp = h->o->pp;
    if (pp == NULL || *pp == NULL) {
        return;
    }
    for (i = 0; i < (*pp)->cnt + 1; i++) {
        sceVu0CopyMatrix(a + 0x140, b + 0x140);
        sceVu0CopyMatrix(a + 0xC0, b + 0xC0);
        b += 0x140;
        a += 0x140;
    }
}

/* Mdl_RunMotionEvents_0_001717A0 */
void Mdl_RunMotionEvents_0_001717A0(O_Mdl_RunMotionEvents_0_001717A0 *o, s32 idx, f32 t0, f32 t1, CB cb) {
    u8 *tbl;
    u8 *fp;
    s32 i;
    u8 *p;
    u32 cnt;
    u32 a;
    u32 b;
    u8 *end;
    u32 j;
    E_Mdl_RunMotionEvents_0_001717A0 *e;
    s32 base;
    Q *q;
    f32 s;
    f32 en;

    q = *o->q;
    base = *q->base;
    tbl = (u8 *)((s32)q + 0x40 + q->n14 * 16);
    b = idx;
    fp = tbl + q->n16 * 8;
    if (q->n16 != 0) {
        tbl += (b & 0xFFFF) * 8;
        fp += *(u16 *)(tbl + 4) * 4;
        for (i = 0; i < o->n6; i++) {
            e = (E_Mdl_RunMotionEvents_0_001717A0 *)(base + ((s32 *)fp)[i + o->x4]);
            a = e->a;
            b = e->b;
            cnt = e->n;
            p = (u8 *)e + 0x10;
            if (a != 0) {
                p += e->c;
            }
            if (b != 0) {
                p += e->d;
            }
            if (cnt != 0) {
                end = p + cnt * 16;
                for (j = 0; j < cnt; j++, p += 16) {
                    s = 0.00041666668f * ((s32 *)p)[0];
                    en = 0.00041666668f * ((s32 *)p)[1];
                    if (!(t0 <= t1) && !(t0 <= s) && t1 <= en) {
                        cb(o, idx, i, p, t0, end, t1 <= s);
                    }
                }
            }
        }
    }
}

/* Mdl_BlendMotion_0_00171980 */
void Mdl_BlendMotion_0_00171980(O_Mdl_BlendMotion_0_00171980 *obj, u16 a1, s32 start, s32 count, f32 f, f32 g) {
    s8 buf[0x13F80];
    E_Mdl_BlendMotion_0_00171980 *src;
    s32 i;

    if (g == 1.0f) {
        Mdl_Animate_2_00171BB0((void *)((s32)obj->data + gSfxAllSbss_00201F2C * (obj->n * 0x140 + 0x200)), obj, start, count, a1, f);
        return;
    }
    src = (E_Mdl_BlendMotion_0_00171980 *)((s32)obj->data + gSfxAllSbss_00201F2C * (obj->n * 0x140 + 0x200));
    memcpy(buf, src, obj->n * 0x140 + 0x200);
    Mdl_Animate_2_00171BB0(buf, obj, start, count, a1, f);
    for (i = start; i < start + count; i++) {
        Mtx_Lerp_2_0015EB20(src + i + 1, src + i + 1, (E_Mdl_BlendMotion_0_00171980 *)buf + i + 1, g);
    }
}

/* Mdl_AnimateCur_0_00171AF0 */
#define Mdl_Animate_2_00171BB0 Mdl_Animate_2_00171BB0__as_Mdl_AnimateCur_0_00171AF0
void Mdl_Animate_2_00171BB0__as_Mdl_AnimateCur_0_00171AF0(void *, A0 *, u8, u8, s32);
void Mdl_AnimateCur_0_00171AF0(A0 *a, s32 b, s32 c, s32 d) {
    Mdl_Animate_2_00171BB0((u8 *)((s32)a + 0x40) + gSfxAllSbss_00201F2C * (a->x6 * 0x140 + 0x200), a, c, d, b);
}
#undef Mdl_Animate_2_00171BB0

/* Mdl_AnimateSel_0_00171B30 */
#define Mdl_Animate_2_00171BB0 Mdl_Animate_2_00171BB0__as_Mdl_AnimateSel_0_00171B30
void Mdl_Animate_2_00171BB0__as_Mdl_AnimateSel_0_00171B30(void *, O_Mdl_AnimateSel_0_00171B30 *, u8, u8, u16, f32);
void Mdl_AnimateSel_0_00171B30(O_Mdl_AnimateSel_0_00171B30 *obj, u16 a1, s32 sel, f32 f) {
    Mdl_Animate_2_00171BB0((void *)((s32)obj->data + sel * (obj->n * 0x140 + 0x200)), obj, obj->x4, obj->n, a1, f);
}
#undef Mdl_Animate_2_00171BB0

/* Mdl_AnimateWrap_0_00171B70 */
#define Mdl_Animate_2_00171BB0 Mdl_Animate_2_00171BB0__as_Mdl_AnimateWrap_0_00171B70
void Mdl_Animate_2_00171BB0__as_Mdl_AnimateWrap_0_00171B70(s32, H_Mdl_AnimateWrap_0_00171B70 *, u8, u8, s32, f32);
void Mdl_AnimateWrap_0_00171B70(H_Mdl_AnimateWrap_0_00171B70 *h, s32 a, f32 f) {
    Mdl_Animate_2_00171BB0((s32)((u8 *)((s32)h + 0x40) + gSfxAllSbss_00201F2C * (h->h6 * 0x140 + 0x200)), h, h->b4, h->h6, a, f);
}
#undef Mdl_Animate_2_00171BB0
