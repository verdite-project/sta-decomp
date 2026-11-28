#include "m2c.h"
#include "common.h"
#include "game/gfx.h"
typedef struct { s32 x, y, z, w; } V4;
typedef struct {
    V4 xy[4];
    s32 prim;
    s32 pad[3];
    V4 uv[3];
    s32 col[4];
} Pkt;
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 col;
    s32 x48;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
} Src;
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { s32 x, y, z, w; } V_Draw_Prim_1_00155DB0;
typedef struct { V_Draw_Prim_1_00155DB0 v[3]; s32 x30[4]; u32 fl; s32 x44[3]; V_Draw_Prim_1_00155DB0 uv[3]; u32 col[3]; } Tri;
typedef struct { Vec a; Vec b; s32 mode; u32 c0; u32 c1; s32 pad; } V_Draw_SelectionRing_0_00156450;
typedef f32 Mtx_Draw_ShadowDisc_0_00156920[4][4];
typedef struct { f32 x0[3]; f32 xC; f32 x10[3]; f32 x1C; Mtx_Draw_ShadowDisc_0_00156920 x20; s32 x60; } S;
extern s32 D_00201F3C;
extern f32 D_001F2140[];
extern f32 D_001F2130[];
extern Mtx_Draw_ShadowDisc_0_00156920 D_002F1840;
void Draw_Sprite_1_00155BD0(Src *s);
void Draw_Prim_1_00155DB0(Tri *t);
void Draw_SelectionRing_0_00156450(void *p, u32 col, f32 h);
void Draw_ShadowDisc_0_00156920(S *s);
Q* GsPkt_Alloc_3_00154A80(s32);
void memcpy(void *, void *, s32);
void Vu0_LoadMatrixVf1_3_001DC348(void *);
void Vu0_ProjectToScreen_5_001DC398(void *, Vec *);
void sceVu0CopyVector(void *, void *);
f32 cosf(f32);
f32 sinf(f32);
void sceVu0UnitMatrix(Mtx_Draw_ShadowDisc_0_00156920);
void sceVu0MulMatrix(Mtx_Draw_ShadowDisc_0_00156920, Mtx_Draw_ShadowDisc_0_00156920, Mtx_Draw_ShadowDisc_0_00156920);
void sceVu0OuterProduct(f32 *, f32 *, f32 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
void sceVu0Normalize(f32 *, f32 *);
f32 sqrtf(float);

/* Draw_Rect_1_00155AC0 */
#define Draw_Prim_1_00155DB0 Draw_Prim_1_00155DB0__as_Draw_Rect_1_00155AC0
void Draw_Prim_1_00155DB0__as_Draw_Rect_1_00155AC0(Pkt *);

void Draw_Rect_1_00155AC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 col) {
    Pkt p;
    s32 x0, y0, x1, y1;
    p.prim = 0x46;
    p.col[0] = col;
    p.xy[0].z = 0;
    p.xy[0].w = 0x10;
    p.col[1] = col;
    p.xy[1].z = 0;
    p.xy[1].w = 0x10;
    p.col[2] = col;
    p.xy[2].z = 0;
    p.xy[2].w = 0x10;
    p.col[3] = col;
    p.xy[3].z = 0;
    p.xy[3].w = 0x10;
    x0 = a0 * 16 + 0x6C00;
    y0 = a1 * 16 + 0x7200;
    x1 = a2 * 16 + 0x6C00;
    y1 = a3 * 16 + 0x7200;
    p.xy[0].x = x0;
    p.xy[0].y = y0;
    p.xy[1].x = x1;
    p.xy[1].y = y0;
    p.xy[2].x = x0;
    p.xy[2].y = y1;
    Draw_Prim_1_00155DB0(&p);
    p.xy[0].x = x1;
    p.xy[0].y = y0;
    p.xy[1].x = x1;
    p.xy[1].y = y1;
    p.xy[2].x = x0;
    p.xy[2].y = y1;
    Draw_Prim_1_00155DB0(&p);
}
#undef Draw_Prim_1_00155DB0

/* Draw_Sprite_1_00155BD0 */
#define Draw_Prim_1_00155DB0 Draw_Prim_1_00155DB0__as_Draw_Sprite_1_00155BD0
void Draw_Prim_1_00155DB0__as_Draw_Sprite_1_00155BD0(Pkt *);

void Draw_Sprite_1_00155BD0(Src *s) {
    Pkt p;

    p.prim = (u64)6 | ((u64)s->b0 << 3) | ((u64)s->b1 << 4) | ((u64)0 << 5) | ((u64)s->b2 << 6) | ((u64)0 << 7) | ((u64)1 << 8);
    p.col[0] = s->col;
    p.xy[0].z = 0;
    p.xy[0].w = 0x10;
    p.col[1] = s->col;
    p.xy[1].z = 0;
    p.xy[1].w = 0x10;
    p.col[2] = s->col;
    p.xy[2].z = 0;
    p.xy[2].w = 0x10;
    p.col[3] = s->col;
    p.xy[3].z = 0;
    p.xy[3].w = 0x10;
    p.xy[0].x = s->x0;
    p.xy[0].y = s->x4;
    p.xy[1].x = s->x10;
    p.xy[1].y = s->x4;
    p.xy[2].x = s->x0;
    p.xy[2].y = s->x14;
    if (s->b1) {
        p.uv[0].x = s->x20;
        p.uv[0].y = s->x24;
        p.uv[1].x = s->x30;
        p.uv[1].y = s->x24;
        p.uv[2].x = s->x20;
        p.uv[2].y = s->x34;
    }
    Draw_Prim_1_00155DB0(&p);
    p.xy[0].x = s->x10;
    p.xy[0].y = s->x4;
    p.xy[1].x = s->x10;
    p.xy[1].y = s->x14;
    p.xy[2].x = s->x0;
    p.xy[2].y = s->x14;
    if (s->b1) {
        p.uv[0].x = s->x30;
        p.uv[0].y = s->x24;
        p.uv[1].x = s->x30;
        p.uv[1].y = s->x34;
        p.uv[2].x = s->x20;
        p.uv[2].y = s->x34;
    }
    Draw_Prim_1_00155DB0(&p);
}
#undef Draw_Prim_1_00155DB0

/* Draw_Prim_1_00155DB0 */
void Draw_Prim_1_00155DB0(Tri *t) {
    Q q;
    Q *p;
    u32 fl;
    u32 c;

    if (t->v[0].z < 0 || t->v[0].z > 0xFFFF0) return;
    if (t->v[1].z < 0 || t->v[1].z > 0xFFFF0) return;
    if (t->v[2].z < 0 || t->v[2].z > 0xFFFF0) return;
    q.q = 0;
    fl = t->fl;
    if (fl & 0x10) {
        p = GsPkt_Alloc_3_00154A80(12);
        q.w[0] = 0x1000000B;
        q.w[3] = 0x6C0AC000;
        p[0] = q;
        if (!(t->fl & 0x100)) {
            q.d[0] = ((u64)(u32)(fl & ~6 | 3) << 47) | (0x8001 | ((u64)0x90004000 << 32));
            q.d[1] = 0x21521521 | ((u64)5 << 32);
            p[1] = q;
            c = t->col[0];
            q.w[0] = c & 0xFF;
            q.w[1] = (c >> 8) & 0xFF;
            q.w[2] = (c >> 16) & 0xFF;
            q.w[3] = (c >> 24) & 0xFF;
            p[2] = q;
            q.w[0] = t->uv[0].x;
            q.w[1] = t->uv[0].y;
            q.w[2] = t->uv[0].z;
            q.w[3] = 0;
            p[3] = q;
            q.w[0] = t->v[0].x;
            q.w[1] = t->v[0].y;
            q.w[2] = t->v[0].z >> 4;
            q.w[3] = 0x8000;
            p[4] = q;
            c = t->col[1];
            q.w[0] = c & 0xFF;
            q.w[1] = (c >> 8) & 0xFF;
            q.w[2] = (c >> 16) & 0xFF;
            q.w[3] = (c >> 24) & 0xFF;
            p[5] = q;
            q.w[0] = t->uv[1].x;
            q.w[1] = t->uv[1].y;
            q.w[2] = t->uv[1].z;
            q.w[3] = 0;
            p[6] = q;
            q.w[0] = t->v[1].x;
            q.w[1] = t->v[1].y;
            q.w[2] = t->v[1].z >> 4;
            q.w[3] = 0x8000;
            p[7] = q;
            c = t->col[2];
            q.w[0] = c & 0xFF;
            q.w[1] = (c >> 8) & 0xFF;
            q.w[2] = (c >> 16) & 0xFF;
            q.w[3] = (c >> 24) & 0xFF;
            p[8] = q;
            q.w[0] = t->uv[2].x;
            q.w[1] = t->uv[2].y;
            q.w[2] = t->uv[2].z;
            q.w[3] = 0;
            p[9] = q;
            q.w[0] = t->v[2].x;
            q.w[1] = t->v[2].y;
            q.w[2] = t->v[2].z >> 4;
            q.w[3] = 0;
            p[10] = q;
            p += 11;
        } else {
            q.d[0] = ((u64)(u32)(fl & ~6 | 3) << 47) | (0x8001 | ((u64)0x90004000 << 32));
            q.d[1] = 0x31531531 | ((u64)5 << 32);
            p[1] = q;
            c = t->col[0];
            q.w[0] = c & 0xFF;
            q.w[1] = (c >> 8) & 0xFF;
            q.w[2] = (c >> 16) & 0xFF;
            q.w[3] = (c >> 24) & 0xFF;
            p[2] = q;
            q.w[0] = t->uv[0].x;
            q.w[1] = t->uv[0].y;
            q.d[1] = 0;
            p[3] = q;
            q.w[0] = t->v[0].x;
            q.w[1] = t->v[0].y;
            q.w[2] = t->v[0].z >> 4;
            q.w[3] = 0x8000;
            p[4] = q;
            c = t->col[0];
            q.w[0] = c & 0xFF;
            q.w[1] = (c >> 8) & 0xFF;
            q.w[2] = (c >> 16) & 0xFF;
            q.w[3] = (c >> 24) & 0xFF;
            p[5] = q;
            q.w[0] = t->uv[1].x;
            q.w[1] = t->uv[1].y;
            q.d[1] = 0;
            p[6] = q;
            q.w[0] = t->v[1].x;
            q.w[1] = t->v[1].y;
            q.w[2] = t->v[1].z >> 4;
            q.w[3] = 0x8000;
            p[7] = q;
            c = t->col[2];
            q.w[0] = c & 0xFF;
            q.w[1] = (c >> 8) & 0xFF;
            q.w[2] = (c >> 16) & 0xFF;
            q.w[3] = (c >> 24) & 0xFF;
            p[8] = q;
            q.w[0] = t->uv[2].x;
            q.w[1] = t->uv[2].y;
            q.d[1] = 0;
            p[9] = q;
            q.w[0] = t->v[2].x;
            q.w[1] = t->v[2].y;
            q.w[2] = t->v[2].z >> 4;
            q.w[3] = 0;
            p[10] = q;
            p += 11;
        }
    } else {
        p = GsPkt_Alloc_3_00154A80(9);
        q.w[0] = 0x10000008;
        q.w[3] = 0x6C07C000;
        p[0] = q;
        q.d[0] = ((u64)(u32)(fl & ~6 | 3) << 47) | (0x8001 | ((u64)0x60004000 << 32));
        q.d[1] = 0x515151;
        p[1] = q;
        c = t->col[0];
        q.w[0] = c & 0xFF;
        q.w[1] = (c >> 8) & 0xFF;
        q.w[2] = (c >> 16) & 0xFF;
        q.w[3] = (c >> 24) & 0xFF;
        p[2] = q;
        q.w[0] = t->v[0].x;
        q.w[1] = t->v[0].y;
        q.w[2] = t->v[0].z >> 4;
        q.w[3] = 0x8000;
        p[3] = q;
        c = t->col[1];
        q.w[0] = c & 0xFF;
        q.w[1] = (c >> 8) & 0xFF;
        q.w[2] = (c >> 16) & 0xFF;
        q.w[3] = (c >> 24) & 0xFF;
        p[4] = q;
        q.w[0] = t->v[1].x;
        q.w[1] = t->v[1].y;
        q.w[2] = t->v[1].z >> 4;
        q.w[3] = 0x8000;
        p[5] = q;
        c = t->col[2];
        q.w[0] = c & 0xFF;
        q.w[1] = (c >> 8) & 0xFF;
        q.w[2] = (c >> 16) & 0xFF;
        q.w[3] = (c >> 24) & 0xFF;
        p[6] = q;
        q.w[0] = t->v[2].x;
        q.w[1] = t->v[2].y;
        q.w[2] = t->v[2].z >> 4;
        q.w[3] = 0;
        p[7] = q;
        p += 8;
    }
    q.q = 0;
    q.w[3] = D_00201F3C | 0x15000000;
    p[0] = q;
    GsPkt_CloseChain_1_001549D0();
}

/* Draw_SelectionRing_0_00156450 */
#define sceVu0CopyVector sceVu0CopyVector__as_Draw_SelectionRing_0_00156450
void sceVu0CopyVector__as_Draw_SelectionRing_0_00156450(Vec *, Vec *);

void Draw_SelectionRing_0_00156450(void *p, u32 col, f32 h) {
    V_Draw_SelectionRing_0_00156450 v180;
    V_Draw_SelectionRing_0_00156450 v150;
    V_Draw_SelectionRing_0_00156450 v120;
    f32 sn[4];
    f32 cs[4];
    Vec f0;
    Vec e0;
    Vec d0;
    Vec c0;
    Vec b0;
    s32 i;
    s32 j;
    s32 k;
    f32 a;
    f32 b;
    s32 x;
    f32 tx;
    f32 ty;

    x = 0;
    if ((col >> 24) < 0x80) x = 1;
    v180.c0 = col;
    v180.c1 = col;
    v180.mode = ((u64)x << 6) | 2;
    memcpy(&v120, &v180, 0x30);
    memcpy(&v150, &v180, 0x30);
    Vu0_LoadMatrixVf1_3_001DC348(p);
    for (i = 0, a = 0.39269908f; i < 4; i++, a += 0.39269908f) {
        sn[i] = sinf(a);
        cs[i] = cosf(a);
    }
    for (i = 0, a = 0.0f; i < 7; i++, a += 0.8975979f) {
        if (i != 0) {
            memcpy(&v180, &v180.b, 0x10);
        } else {
            tx = cosf(a);
            ty = sinf(a);
            f0.x = tx;
            f0.y = ty;
            f0.z = 0.0f;
            f0.w = 1.0f;
            Vu0_ProjectToScreen_5_001DC398(&v180, &f0);
        }
        b = 0.8975979f + a;
        tx = cosf(b);
        ty = sinf(b);
        e0.x = tx;
        e0.y = ty;
        e0.z = 0.0f;
        e0.w = 1.0f;
        Vu0_ProjectToScreen_5_001DC398(&v180.b, &e0);
        for (j = 0; j < 4; j++) {
            if (j == 0) {
                memcpy(&v150, &v180.b, 0x10);
            } else {
                memcpy(&v150, &v150.b, 0x10);
            }
            d0.x = e0.x * cs[j];
            d0.y = e0.y * cs[j];
            if (h < 0.0f) d0.z = sn[j];
            else d0.z = -sn[j];
            d0.w = 1.0f;
            Vu0_ProjectToScreen_5_001DC398(&v150.b, &d0);
        }
        if (h != 0.0f) {
            if (i != 0) {
                memcpy(&v120, &v120.b, 0x10);
            } else {
                sceVu0CopyVector(&c0, &f0);
                c0.z = h;
                Vu0_ProjectToScreen_5_001DC398(&v120, &c0);
            }
            sceVu0CopyVector(&b0, &e0);
            b0.z = h;
            Vu0_ProjectToScreen_5_001DC398(&v120.b, &b0);
            memcpy(&v150, &v180, 0x10);
            memcpy(&v150.b, &v120, 0x10);
            for (j = 0; j < 4; j++) {
                if (j == 0) {
                    memcpy(&v150, &v120.b, 0x10);
                } else {
                    memcpy(&v150, &v150.b, 0x10);
                }
                d0.x = b0.x * cs[j];
                d0.y = b0.y * cs[j];
                if (h < 0.0f) d0.z = b0.z - sn[j];
                else d0.z = b0.z + sn[j];
                d0.w = 1.0f;
                Vu0_ProjectToScreen_5_001DC398(&v150.b, &d0);
            }
        } else {
            for (j = 0; j < 4; j++) {
                if (j == 0) {
                    memcpy(&v150, &v180.b, 0x10);
                } else {
                    memcpy(&v150, &v150.b, 0x10);
                }
                d0.x = e0.x * cs[j];
                d0.y = e0.y * cs[j];
                d0.z = sn[j];
                d0.w = 1.0f;
                Vu0_ProjectToScreen_5_001DC398(&v150.b, &d0);
            }
        }
    }
}
#undef sceVu0CopyVector

/* Draw_ShadowDisc_0_00156920 */
#define sceVu0CopyVector sceVu0CopyVector__as_Draw_ShadowDisc_0_00156920
void sceVu0CopyVector__as_Draw_ShadowDisc_0_00156920(f32 *, f32 *);
#define Draw_SelectionRing_0_00156450 Draw_SelectionRing_0_00156450__as_Draw_ShadowDisc_0_00156920
void Draw_SelectionRing_0_00156450__as_Draw_ShadowDisc_0_00156920(Mtx_Draw_ShadowDisc_0_00156920, f32, s32);

void Draw_ShadowDisc_0_00156920(S *s) {
    Mtx_Draw_ShadowDisc_0_00156920 a;
    Mtx_Draw_ShadowDisc_0_00156920 b;
    Mtx_Draw_ShadowDisc_0_00156920 d;
    Mtx_Draw_ShadowDisc_0_00156920 c;
    sceVu0UnitMatrix(a);
    a[0][0] = s->xC;
    a[1][1] = s->xC;
    a[2][2] = s->xC;
    sceVu0UnitMatrix(b);
    b[0][0] = 1.0f;
    b[1][1] = 1.0f;
    b[2][2] = 1.0f;
    sceVu0CopyVector(b[2], s->x10);
    b[2][3] = 0.0f;
    sceVu0CopyVector(b[1], D_001F2140);
    sceVu0OuterProduct(b[0], b[1], b[2]);
    if (sqrtf(sceVu0InnerProduct(b[0], b[0])) < 1e-5f) {
        sceVu0CopyVector(b[0], D_001F2130);
    } else {
        sceVu0Normalize(b[0], b[0]);
    }
    sceVu0OuterProduct(b[1], b[2], b[0]);
    if (sqrtf(sceVu0InnerProduct(b[1], b[1])) < 1e-5f) {
        sceVu0CopyVector(b[0], D_001F2140);
    } else {
        sceVu0Normalize(b[1], b[1]);
    }
    sceVu0MulMatrix(a, a, b);
    sceVu0CopyVector(a[3], s->x0);
    a[3][3] = 1.0f;
    sceVu0MulMatrix(c, s->x20, a);
    sceVu0MulMatrix(d, D_002F1840, c);
    Draw_SelectionRing_0_00156450(d, s->x1C / s->xC, s->x60);
}
#undef sceVu0CopyVector
#undef Draw_SelectionRing_0_00156450

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F3C */
s32 D_00201F3C;
#endif
