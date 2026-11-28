#include "common.h"
#include "m2c.h"
#include "game/data.h"
#include "game/gfx.h"
#include "game/model.h"
typedef struct { u8 lo : 2; u8 rest : 6; u8 pad[3]; } P_Mdl_SetLayerTex_0_0016B2D0;
typedef union { u32 w; struct { u8 lo:2; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:3; u8 pad[3]; } f; } F;
typedef struct M { struct M *x0; u16 p4; u16 n; } M;
typedef struct { M *m; s32 x4; } H_Mdl_SetLayerForMesh_0_0016B360;
typedef struct { u8 p[0xB0]; s32 xB0; u8 pB4[0x3C]; Vec xF0; } R;
typedef struct { u8 lo:2; u8 rest:6; u8 pad[3]; } P_Mdl_SetLayerSimple_0_0016B480;
typedef struct { u8 lo:2; u8 r:6; u8 pad[3]; } P_Mdl_SetLayerForBounds_0_0016B500;
typedef struct { f32 x, y, z; } V3;
typedef struct { s16 x, y, z; } S3;
typedef struct { u8 pad[6]; u16 bits; } H_Mdl_DecodeVerts_0_0016B600;
typedef struct { s16 x, y, z; } SV;
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { Vec amb; Vec dir[4]; Vec col[4]; Vec x90; } L;
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[8];
    L x10;
} O;
#ifndef NONMATCHING
extern s32 D_00201FF8;
#else
/* data twins (src/game/data/sbss.c): D_00201FF8 */
static s32 D_00201FF8;
#endif
#ifndef NONMATCHING
extern s32 D_00201FFC;
#else
/* data twins (src/game/data/sbss.c): D_00201FFC */
static s32 D_00201FFC;
#endif
#ifndef NONMATCHING
extern s32 D_00202000;
#else
/* data twins (src/game/data/sbss.c): D_00202000 */
static s32 D_00202000;
#endif
#ifndef NONMATCHING
extern s32 D_00202004;
#else
/* data twins (src/game/data/sbss.c): D_00202004 */
static s32 D_00202004;
#endif
extern u8 D_002F1840[];
#ifndef NONMATCHING
extern s32 D_00201FF4;
#else
/* data twins (src/game/data/sbss.c): D_00201FF4 */
static s32 D_00201FF4;
#endif
void Mdl_SetLayerTex_0_0016B2D0(s32 a, P_Mdl_SetLayerTex_0_0016B2D0 p, s32 base, s32 n);
s32 Mdl_SetLayerForMesh_0_0016B360(H_Mdl_SetLayerForMesh_0_0016B360 *h, F f, s32 a2);
s32 Mdl_SetLayerSimple_0_0016B480(P_Mdl_SetLayerSimple_0_0016B480 p, s32 b);
s32 Mdl_SetLayerForBounds_0_0016B500(void *a0, P_Mdl_SetLayerForBounds_0_0016B500 a1, s32 a2);
void Mdl_DecodeVerts_0_0016B600(V3 *out, u32 n, s32 mode, H_Mdl_DecodeVerts_0_0016B600 *h, u16 *idx, void *tbl);
void Mdl_DecodeVertsScaled_0_0016B730(Vec *out, s32 mode, u16 *hdr, u16 *idx, void *data, f32 scale);
void Mdl_DrawLitWrap_0_0016B960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void Mdl_DrawLit_0_0016B970(O *o, L *m, Vec *v, s8 *a3, s32 t0, s32 t1, s32 t2);
void sceVu0AddVector(Vec*, void *, void *);
void sceVu0CopyVector(Vec*, void *);
void sceVu0ApplyMatrix(Vec *, void *, Vec *);
void sceVu0SubVector(Vec *, void *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0ScaleVector(Vec *, void *, f32);
s32 Glow_FindNear_0_0015DA00(s64, u8, s32 *, Vec *, s32);
s8* TextColour_Get_1_0015D580(s32);
Q* GsPkt_Alloc_3_00154A80(s32);

/* Mdl_FlushLayer_0_0016B280 */
#define GsPkt_CloseChain_1_001549D0 GsPkt_CloseChain_1_001549D0__as_Mdl_FlushLayer_0_0016B280
int GsPkt_CloseChain_1_001549D0__as_Mdl_FlushLayer_0_0016B280();
#define GsPkt_EndLayer_1_00155900 GsPkt_EndLayer_1_00155900__as_Mdl_FlushLayer_0_0016B280
int GsPkt_EndLayer_1_00155900__as_Mdl_FlushLayer_0_0016B280();
#define GsPkt_SetLayerTop_0_001548F0 GsPkt_SetLayerTop_0_001548F0__as_Mdl_FlushLayer_0_0016B280
int GsPkt_SetLayerTop_0_001548F0__as_Mdl_FlushLayer_0_0016B280();

void Mdl_FlushLayer_0_0016B280(void) {
    if (D_00201FF8 != 0) {
        GsPkt_CloseChain_1_001549D0();
        GsPkt_EndLayer_1_00155900();
        GsPkt_SetLayerTop_0_001548F0(0);
        D_00201FF8 = 0;
    }
    D_00201FFC = 0;
    D_00202000 = 0;
}
#undef GsPkt_CloseChain_1_001549D0
#undef GsPkt_EndLayer_1_00155900
#undef GsPkt_SetLayerTop_0_001548F0

/* Mdl_SetLayerTex_0_0016B2D0 */
void Mdl_SetLayerTex_0_0016B2D0(s32 a, P_Mdl_SetLayerTex_0_0016B2D0 p, s32 base, s32 n) {
    s32 v = p.lo + base;
    if (D_00201FFC != v || D_00202004 != n + 8 || D_00202000 != 0) {
        D_00201FFC = v;
        GsPkt_CloseChain_1_001549D0();
        GsPkt_EndLayer_1_00155900();
        GsPkt_SetLayer_1_00154700(D_00201FFC, n);
        D_00201FF8 = 1;
    }
    D_00202004 = n + 8;
    D_00202000 = 0;
}

/* Mdl_SetLayerForMesh_0_0016B360 */
#define sceVu0AddVector sceVu0AddVector__as_Mdl_SetLayerForMesh_0_0016B360
void sceVu0AddVector__as_Mdl_SetLayerForMesh_0_0016B360(Vec *, M *, s8 *);
#define Mdl_SetLayerForBounds_0_0016B500 Mdl_SetLayerForBounds_0_0016B500__as_Mdl_SetLayerForMesh_0_0016B360
s32 Mdl_SetLayerForBounds_0_0016B500__as_Mdl_SetLayerForMesh_0_0016B360(Vec *, F, s32);

s32 Mdl_SetLayerForMesh_0_0016B360(H_Mdl_SetLayerForMesh_0_0016B360 *h, F f, s32 a2) {
    Vec v;
    F g;
    s32 k;
    s32 ret;
    s32 d;
    M *m;
    R *r;

    if (f.f.b4) {
        d = D_00201F2C;
        if (h == NULL || (m = h->m) == NULL) {
            r = NULL;
        } else {
            r = (R *)((s8 *)((s32)m + 0x40) + d * (m->n * 0x140 + 0x200));
            r->xB0 = h->x4 - (s32)m;
        }
        sceVu0AddVector(&v, h->m->x0->x0, (s8 *)&r->xF0);
        return Mdl_SetLayerForBounds_0_0016B500(&v, f, a2);
    }
    g = f;
    k = (g.f.lo) + a2;
    ret = 0;
    if (D_00201FFC != k || D_00202004 != 0 || D_00202000 != 0) {
        D_00201FFC = k;
        GsPkt_CloseChain_1_001549D0();
        GsPkt_EndLayer_1_00155900();
        GsPkt_SetLayerTop_0_001548F0(D_00201FFC);
        ret = 1;
        D_00201FF8 = 1;
    }
    D_00202000 = 0;
    D_00202004 = 0;
    return ret;
}
#undef sceVu0AddVector
#undef Mdl_SetLayerForBounds_0_0016B500

/* Mdl_SetLayerSimple_0_0016B480 */
#define GsPkt_CloseChain_1_001549D0 GsPkt_CloseChain_1_001549D0__as_Mdl_SetLayerSimple_0_0016B480
void GsPkt_CloseChain_1_001549D0__as_Mdl_SetLayerSimple_0_0016B480(s32);
s32 Mdl_SetLayerSimple_0_0016B480(P_Mdl_SetLayerSimple_0_0016B480 p, s32 b) {
    s32 t = p.lo + b;
    s32 r = 0;
    if (D_00201FFC != t || D_00202004 != 0 || D_00202000 != 0) {
        D_00201FFC = t;
        GsPkt_CloseChain_1_001549D0(t);
        GsPkt_EndLayer_1_00155900();
        GsPkt_SetLayerTop_0_001548F0(D_00201FFC);
        r = 1;
        D_00201FF8 = r;
    }
    D_00202000 = 0;
    D_00202004 = 0;
    return r;
}
#undef GsPkt_CloseChain_1_001549D0

/* Mdl_SetLayerForBounds_0_0016B500 */
s32 Mdl_SetLayerForBounds_0_0016B500(void *a0, P_Mdl_SetLayerForBounds_0_0016B500 a1, s32 a2) {
    f32 *w;
    s32 n;
    s32 k;
    Vec v;
    n = a1.lo + a2;
    sceVu0CopyVector(&v, a0);
    w = &v.w;
    *w = 1.0f;
    sceVu0ApplyMatrix(&v, D_002F1840, &v);
    if (*w < 0.0f) *w = 0.0f;
    if (!(*w <= 32000.0f)) *w = 32000.0f;
    k = 511.0f - 512.0f * *w / 32000.0f;
    D_00201FFC = n;
    GsPkt_CloseChain_1_001549D0();
    GsPkt_EndLayer_1_00155900();
    GsPkt_SetLayerB_0_00154610(D_00201FFC, k);
    D_00201FF8 = 1;
    D_00202000 = 1;
    return 1;
}

/* Mdl_DecodeVerts_0_0016B600 */
void Mdl_DecodeVerts_0_0016B600(V3 *out, u32 n, s32 mode, H_Mdl_DecodeVerts_0_0016B600 *h, u16 *idx, void *tbl) {
    u32 i;
    u16 bits = h->bits;
    s32 j;
    V3 *v;
    u32 k;
    S3 *s;

    for (i = 0; i < n; i++) {
        k = bits;
        switch (k & 3) {
        case 0:
            out->x = 0.0f;
            out->y = 0.0f;
            out->z = 0.0f;
            break;
        case 1:
            out->x = 1.0f;
            out->y = 1.0f;
            out->z = 1.0f;
            break;
        case 3:
            j = *idx++;
            if (mode == 2) {
                v = &((V3 *)tbl)[j]; out->x = v->x; out->y = v->y; out->z = v->z;
            } else if (mode == 3) {
                s = &((S3 *)tbl)[j];
                out->x = 0.00024414062f * s->x;
                out->y = 0.00024414062f * s->y;
                out->z = 0.00024414062f * s->z;
            }
            break;
        }
        bits = (s32)k >> 2;
        out++;
    }
}

/* Mdl_DecodeVertsScaled_0_0016B730 */
#define sceVu0CopyVector sceVu0CopyVector__as_Mdl_DecodeVertsScaled_0_0016B730
void sceVu0CopyVector__as_Mdl_DecodeVertsScaled_0_0016B730(Vec *, Vec *);

void Mdl_DecodeVertsScaled_0_0016B730(Vec *out, s32 mode, u16 *hdr, u16 *idx, void *data, f32 scale) {
    u32 i;
    Vec *o;
    s32 m;
    u16 bits = hdr[3];
    if (D_00201FF4 != bits) {
        D_00201FF4 = bits;
    }
    for (i = 0, o = out; i < 7; i++, o++) {
        m = bits;
        switch (m & 3) {
        case 0:
            o->x = 0.0f;
            o->y = 0.0f;
            o->z = 0.0f;
            o->w = 1.0f;
            break;
        case 1:
            o->x = 1.0f;
            o->y = 1.0f;
            o->z = 1.0f;
            o->w = 1.0f;
            break;
        case 2:
            sceVu0CopyVector(o, &out[i - 1]);
            break;
        case 3: {
            s32 k = *idx++;
            if (mode == 2) {
                Vec *v = (Vec *)((u8 *)data + k * 12);
                o->x = v->x;
                o->y = v->y;
                o->z = v->z;
            } else if (i < 3) {
                SV *v = (SV *)data + k;
                o->x = scale * v->x;
                o->y = scale * v->y;
                o->z = scale * v->z;
            } else {
                SV *v = (SV *)data + k;
                o->x = (1.0f / 4096.0f) * v->x;
                o->y = (1.0f / 4096.0f) * v->y;
                o->z = (1.0f / 4096.0f) * v->z;
            }
            break;
        }
        }
        bits = m >> 2;
    }
}
#undef sceVu0CopyVector

/* Mdl_DrawLitWrap_0_0016B960 */
#define Mdl_DrawLit_0_0016B970 Mdl_DrawLit_0_0016B970__as_Mdl_DrawLitWrap_0_0016B960
int Mdl_DrawLit_0_0016B970__as_Mdl_DrawLitWrap_0_0016B960();
void Mdl_DrawLitWrap_0_0016B960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Mdl_DrawLit_0_0016B970((void *) arg0, (void *) arg1, arg2, arg3, arg4, arg5, 1);
}
#undef Mdl_DrawLit_0_0016B970

/* Mdl_DrawLit_0_0016B970 */
#define sceVu0AddVector sceVu0AddVector__as_Mdl_DrawLit_0_0016B970
void sceVu0AddVector__as_Mdl_DrawLit_0_0016B970(Vec *, Vec *, Vec *);

void Mdl_DrawLit_0_0016B970(O *o, L *m, Vec *v, s8 *a3, s32 t0, s32 t1, s32 t2) {
    s32 buf[12];
    Vec p;
    Vec d;
    Q tag;
    Q tag2;
    L *dst;
    s32 n;
    u32 cnt;
    s32 k;
    s32 *b;
    s32 idx;
    s8 *e;
    f32 dot;
    f32 w;
    f32 r;
    f32 f;
    s32 fl;
    Q *q;

    if (t0 != 0 || t1 != 0) {
        sceVu0CopyVector(&p, a3 + 0x30);
        p.w = 0.0f;
        sceVu0AddVector(&p, &p, v);
        if (t0) {
            cnt = o->x4 = Glow_FindNear_0_0015DA00(0xFFFF, t0, buf, &p, 0);
        } else {
            cnt = o->x4 = Glow_FindNear_0_0015DA00(0xFFFF, t1, buf, &p, 0);
        }
        if (cnt != 0) {
            if (t0) {
                Glow_DrawList_0_0015D900(cnt, buf);
            } else {
                dst = m ? m : &o->x10;
                if ((u8)t1 < cnt) cnt = (u8)t1;
                o->x4 = 0;
                for (k = 0; k < (n = cnt); k++) {
                    e = TextColour_Get_1_0015D580(buf[k]);
                    r = *(f32 *)(e + 0x54);
                    w = -((Vec *)(e + (D_00201F2C << 5)))->w;
                    sceVu0SubVector(&d, e + (D_00201F2C << 5), &p);
                    d.w = 0.0f;
                    dot = sceVu0InnerProduct(&d, &d);
                    sceVu0Normalize(&d, &d);
                    idx = 4 - (u8)t1 + k;
                    sceVu0CopyVector(&dst->dir[idx], &d);
                    f = w * (r * r - dot);
                    if (f < 0.0f) f = 0.0f;
                    f = f * f;
                    f = f * f;
                    sceVu0ScaleVector(&dst->col[idx], e + (D_00201F2C << 5) + 0x10, f);
                    dst->dir[idx].w = *(f32 *)(e + 0x58);
                }
            }
        }
    }
    if (m != NULL) {
        fl = t2 & 1;
        q = GsPkt_Alloc_3_00154A80(fl ? 0xD : 3);
        tag.w[0] = 0x10000001;
        tag.w[1] = 0;
        tag.w[2] = 0x10000000;
        tag.w[3] = 0x6C01002A;
        q[0].q = tag.q;
        q[1].q = *(u128 *)o;
        if (fl) {
            tag.q = 0;
            tag.w[0] = 0x1000000A;
            tag.w[3] = 0x6C0A002B;
            q[2].q = tag.q;
            q[3].q = ((Q *)m)[0].q;
            q[4].q = ((Q *)m)[1].q;
            q[5].q = ((Q *)m)[2].q;
            q[6].q = ((Q *)m)[3].q;
            q[7].q = ((Q *)m)[4].q;
            q[8].q = ((Q *)m)[5].q;
            q[9].q = ((Q *)m)[6].q;
            q[10].q = ((Q *)m)[7].q;
            q[11].q = ((Q *)m)[8].q;
            q[12].q = ((Q *)m)[9].q;
        } else {
            tag.w[0] = 0x3000000A;
            tag.w[1] = (u32)m;
            tag.w[2] = 0;
            tag.w[3] = 0x6C0A002B;
            q[2].q = tag.q;
        }
        D_00201FF0 = (s32)m;
    } else {
        q = GsPkt_Alloc_3_00154A80(1);
        tag2.w[0] = 0x3000000B;
        tag2.w[1] = (u32)((s8 *)o + *(s32 *)((s8 *)o + 0xB0));
        tag2.w[2] = 0x10000000;
        tag2.w[3] = 0x6C0B002A;
        q[0].q = tag2.q;
        D_00201FF0 = tag2.w[1] + 0x10;
    }
}
#undef sceVu0AddVector

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201FF0 */
s32 D_00201FF0;
#endif
