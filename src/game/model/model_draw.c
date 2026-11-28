#include "common.h"
typedef struct {
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 c0:1; u8 c1:7;
    u8 pad[2];
} F;
typedef union { F f; u32 w; } FU;
typedef struct {
    u8 a0:1; u8 a1:1; u8 a2:1; u8 a3:1; u8 a4:1; u8 a5:1; u8 a6:1; u8 a7:1;
    u8 pad1;
    u8 c0:1; u8 c1:2; u8 c3:1; u8 c4:1; u8 c5:1; u8 c6:2;
    u8 pad3;
} Arg;
typedef struct {
    u16 x0:7; u16 x7:4; u16 x11:1; u16 x12:1; u16 x13:3;
    u8 pad[2];
} Arg2;
typedef union { Arg a; Arg2 b; } AU;
typedef struct { Mtx m; u8 pad[0x134 - 0x40]; f32 s; u8 f0:3; u8 f3:1; u8 f4:1; u8 f5:1; u8 f6:2; u8 pad2[7]; } J;
typedef struct { u8 pad[0xC0]; J j[1]; } K;
typedef struct { s32 x0; s32 x4; } T;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } Ent_Mdl_DrawMeshesB_1_0016CD80;
typedef struct { u16 x0; u8 pad[8]; u16 xA; u8 padC[3]; u8 xF; Vec v10; } Hd;
typedef struct {
    Vec v0;
    T *x10;
    u16 x14;
    u16 x16;
    u8 pad18[0xC];
    s32 x24;
    u8 pad28[0x14];
    u8 g0:6; u8 g6:1; u8 g7:1;
    u8 pad3D[3];
    Ent_Mdl_DrawMeshesB_1_0016CD80 e[1];
} O_Mdl_DrawMeshesB_1_0016CD80;
typedef struct { u8 pad[0x24]; u8 g0:1; u8 g1:1; u8 g2:1; u8 g3:1; u8 g4:2; u8 g6:2; u8 h0:1; } S1;
typedef Bits8 BF;
typedef struct { s32 x0; s32 x4; u8 p8[8]; } E16;
typedef struct {
    u8 p0[0x10]; s32 *x10; u8 p14[0x10]; s32 x24; u8 p28[0x14]; Flags8 x3C; u8 p3D[3];
    E16 e[1];
} Obj;
typedef struct { u8 p0[0x24]; union { Flags8 f; struct { u8 lo:6; u8 hi:2; } h; } x24; } Oth;
typedef struct { u16 x0; u8 p2[8]; u16 xA; u8 pC[3]; u8 xF; Vec x10; } Ent_Mdl_DrawMeshesC_1_0016D380;
typedef union {
    u32 w;
    struct { u16 a:7; u16 b:4; u16 c:1; u16 d:1; u16 e:3; u8 g0:1; u8 g1:2; u8 g3:5; u8 pad3; } f;
} P_Mdl_DrawMeshesC_1_0016D380;
typedef union {
    u32 w;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; u8 pad[3]; } f;
} L;
typedef struct { u8 pad[0x134]; f32 x134; } M;
typedef union { u32 w; struct { u16 a:7; u16 f:4; u16 g:1; u16 h:1; u16 r:3; u16 hi; } s; } U;
typedef union { u32 w; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } f; } FL;
typedef struct { s32 x0; s32 x4; } Hdr;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } Ent_Mdl_DrawMeshesD_1_0016D830;
typedef struct { u8 pad[0x10]; Hdr *x10; u8 pad2[0x10]; s32 x24; u8 pad3[0x14]; Flags8 f3C; u8 pad4[3]; Ent_Mdl_DrawMeshesD_1_0016D830 tbl[1]; } O_Mdl_DrawMeshesD_1_0016D830;
typedef struct { u8 pad[0x24]; Flags8_6x2 f24; } P_Mdl_DrawMeshesD_1_0016D830;
typedef struct { u8 pad[0x130]; u8 x130; u8 p1[3]; f32 f134; u8 pad2[8]; } E;
typedef struct { u8 pad[0xA]; u16 hA; u8 pad2[3]; u8 xF; Vec v10; } Q;
extern BF D_00222A50[];
extern s32 D_00202008;
extern s32 D_00201F4C;
extern s32 D_00201F48;
void Mdl_DrawMeshesB_1_0016CD80(O_Mdl_DrawMeshesB_1_0016CD80 *o, S1 *s1, K *k2, Arg a);
void Mdl_DrawMeshesC_1_0016D380(Obj *o, Oth *b, s8 *c, s32 n, P_Mdl_DrawMeshesC_1_0016D380 p, s32 flag);
void Mdl_DrawMeshesD_1_0016D830(O_Mdl_DrawMeshesD_1_0016D830 *o, P_Mdl_DrawMeshesD_1_0016D830 *p, s8 *a2, s32 idx, U u);
void sceVu0CopyVector(Vec*, void *);
void sceVu0ApplyMatrix(Vec*, void *, Vec*);
s32 Gfx_SphereInFrustum_1_00153FA0(Vec *);
void Mdl_SetBlendMode_1_0016F280(Arg);
void Mdl_EmitStrip_1_0016DED0(Hd *, S1 *, K *, Arg);
void Mdl_BindTexture_0_0016F440(O_Mdl_DrawMeshesB_1_0016CD80 *, S1 *, s8 *, s32, F *);
void Mdl_EmitPolys_1_0016EF70(Hd *, s8 *, s8 *, u32, s32, FU);
void Mdl_EmitMeshVu1B_1_0016EB70(Hd *, s8 *, s8 *, u32, J *, s32, s32, FU);
void Mdl_EmitMeshVu1_1_0016E760(Hd *, s8 *, s8 *, u32, J *, s32, s32, s8 *, O_Mdl_DrawMeshesB_1_0016CD80 *, S1 *, FU);
void Mdl_EmitStripD_0_0016DC70(Q *, P_Mdl_DrawMeshesD_1_0016D830 *, s8 *, s32, U);

/* Mdl_DrawMeshesB_1_0016CD80 */
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Mdl_DrawMeshesB_1_0016CD80
void sceVu0ApplyMatrix__as_Mdl_DrawMeshesB_1_0016CD80(Vec *, Mtx *, Vec *);

void Mdl_DrawMeshesB_1_0016CD80(O_Mdl_DrawMeshesB_1_0016CD80 *o, S1 *s1, K *k2, Arg a) {
    Vec V;
    Vec W;
    FU fl;
    AU b;
    FU g;
    s8 *base;
    Ent_Mdl_DrawMeshesB_1_0016CD80 *ents;
    s8 *hb;
    J *jt;
    s32 res;
    s8 *q;
    u32 hdr;
    u8 on;
    s8 *ji;
    s32 sz;
    u32 i;
    u8 k;
    s32 r;
    Hd *h;
    s8 *p;

    base = (s8 *)o->x10->x0;
    sz = o->x10->x4 - (s32)base;
    hb = base + o->x24;
    ents = o->e;
    jt = k2->j;
    res = 2;
    fl.w = 0;
    fl.f.b0 = 1;
    fl.f.b1 = 0;
    fl.f.b2 = 0;
    fl.f.b3 = 0;
    fl.f.b4 = 1;
    fl.f.b5 = 0;
    fl.f.b6 = D_00222A50[0].b4;
    fl.f.b7 = 0;
    fl.f.c0 = a.c5;
    if (s1->g6 == 0) {
        b.a = a;
        D_00202008 = D_00201F4C;
        if (!D_00222A50[0].b1 && !(b.b.x7 | b.b.x11 | b.b.x12) && o->g6) {
            D_00202008 = D_00201F48;
        }
        if (!s1->g1) return;
        if (o->x16 == 0 && !s1->h0) {
            if (D_00222A50[0].b3) {
                res = 2;
            } else {
                sceVu0CopyVector(&V, o);
                V.w = 1.0f;
                sceVu0ApplyMatrix(&V, &jt->m, &V);
                V.w = o->v0.w * jt->s;
                res = Gfx_SphereInFrustum_1_00153FA0(&V);
            }
            if (res < 0) return;
        }
        if (a.c4) {
            a.c1 = 0;
            a.a6 = 1;
            fl.f.b7 = 1;
        }
        Mdl_SetBlendMode_1_0016F280(a);
        i = 0;
        if (i < o->x14) {
            on = a.c3;
            do {
                if (i == 0 && on) continue;
                r = res;
                k = i;
                p = base + ents[k].x0;
                q = base + ents[k].x4;
                ji = (s8 *)k2 + (k + 1) * 0x140;
                hdr = *(u16 *)p;
                h = (Hd *)p;
                if (((J *)(ji + 0xC0))->f3) continue;
                if (((J *)(ji + 0xC0))->f5) continue;
                p += 0x10;
                if (h->xF & 1) {
                    if (r == 2) {
                        if (D_00222A50[0].b3) {
                            r = 2;
                        } else {
                            sceVu0CopyVector(&W, &h->v10);
                            W.w = 1.0f;
                            sceVu0ApplyMatrix(&W, &((J *)(ji + 0xC0))->m, &W);
                            W.w = h->v10.w * (&k2->j[k] + 1)->s;
                            r = Gfx_SphereInFrustum_1_00153FA0(&W);
                        }
                        if (r < 0) continue;
                    }
                    p += 0x10;
                }
                Mdl_EmitStrip_1_0016DED0(h, s1, k2, a);
                if (h->xA != 0xFFFF || !s1->g3) {
                    Mdl_BindTexture_0_0016F440(o, s1, hb + (u16)h->xA * 64, sz, &fl.f);
                    g = fl;
                    if (r < 2 && !g.f.b5) {
                        Mdl_EmitPolys_1_0016EF70(h, p, q, hdr, sz, g);
                    } else {
                        Mdl_EmitMeshVu1B_1_0016EB70(h, p, q, hdr, &jt[k] + 1, r, sz, g);
                    }
                } else {
                    Mdl_EmitMeshVu1_1_0016E760(h, p, q, hdr, &jt[k] + 1, r, sz, hb, o, s1, fl);
                }
            } while (++i < o->x14);
        }
    }
}
#undef sceVu0ApplyMatrix

/* Mdl_DrawMeshesC_1_0016D380 */
#define D_00222A50 D_00222A50__as_Mdl_DrawMeshesC_1_0016D380
extern Flags8 D_00222A50__as_Mdl_DrawMeshesC_1_0016D380[];
#define Mdl_SetBlendMode_1_0016F280 Mdl_SetBlendMode_1_0016F280__as_Mdl_DrawMeshesC_1_0016D380
void Mdl_SetBlendMode_1_0016F280__as_Mdl_DrawMeshesC_1_0016D380(P_Mdl_DrawMeshesC_1_0016D380);
#define Mdl_EmitStrip_1_0016DED0 Mdl_EmitStrip_1_0016DED0__as_Mdl_DrawMeshesC_1_0016D380
void Mdl_EmitStrip_1_0016DED0__as_Mdl_DrawMeshesC_1_0016D380(Ent_Mdl_DrawMeshesC_1_0016D380 *, Oth *, s8 *, P_Mdl_DrawMeshesC_1_0016D380);
#define sceVu0CopyVector sceVu0CopyVector__as_Mdl_DrawMeshesC_1_0016D380
void sceVu0CopyVector__as_Mdl_DrawMeshesC_1_0016D380(Vec *, Vec *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Mdl_DrawMeshesC_1_0016D380
void sceVu0ApplyMatrix__as_Mdl_DrawMeshesC_1_0016D380(Vec *, s8 *, Vec *);
#define Mdl_BindTexture_0_0016F440 Mdl_BindTexture_0_0016F440__as_Mdl_DrawMeshesC_1_0016D380
void Mdl_BindTexture_0_0016F440__as_Mdl_DrawMeshesC_1_0016D380(Obj *, Oth *, s8 *, s32, L *);
#define Mdl_EmitPolys_1_0016EF70 Mdl_EmitPolys_1_0016EF70__as_Mdl_DrawMeshesC_1_0016D380
void Mdl_EmitPolys_1_0016EF70__as_Mdl_DrawMeshesC_1_0016D380(Ent_Mdl_DrawMeshesC_1_0016D380 *, s8 *, s8 *, u32, s32, L);
#define Mdl_EmitMeshVu1B_1_0016EB70 Mdl_EmitMeshVu1B_1_0016EB70__as_Mdl_DrawMeshesC_1_0016D380
void Mdl_EmitMeshVu1B_1_0016EB70__as_Mdl_DrawMeshesC_1_0016D380(Ent_Mdl_DrawMeshesC_1_0016D380 *, s8 *, s8 *, u32, s8 *, s32, s32, L);
#define Mdl_EmitMeshVu1_1_0016E760 Mdl_EmitMeshVu1_1_0016E760__as_Mdl_DrawMeshesC_1_0016D380
void Mdl_EmitMeshVu1_1_0016E760__as_Mdl_DrawMeshesC_1_0016D380(Ent_Mdl_DrawMeshesC_1_0016D380 *, s8 *, s8 *, u32, s8 *, s32, s32, s8 *, Obj *, Oth *, L);

static inline s32 chk(P_Mdl_DrawMeshesC_1_0016D380 q) { return q.f.b | q.f.c | q.f.d; }

void Mdl_DrawMeshesC_1_0016D380(Obj *o, Oth *b, s8 *c, s32 n, P_Mdl_DrawMeshesC_1_0016D380 p, s32 flag) {
    s8 *base;
    E16 *e;
    E16 *ep;
    s8 *tbl;
    s8 *cc;
    s8 *fp;
    u32 d0;
    u8 idx;
    s32 len;
    s8 *ce;
    s32 r;
    s8 *s0;
    Ent_Mdl_DrawMeshesC_1_0016D380 *h;
    s32 k;
    L l;
    P_Mdl_DrawMeshesC_1_0016D380 sv;
    P_Mdl_DrawMeshesC_1_0016D380 q;
    L l2;
    Vec v;

    base = (s8 *)o->x10[0];
    ep = o->e;
    tbl = base + o->x24;
    len = o->x10[1] - (s32)base;
    cc = c + 0xC0;
    r = 2;
    l.w = 0; l.f.b0 = 1; l.f.b1 = 0; l.f.b2 = 0; l.f.b3 = 0; l.f.b4 = 1; l.f.b5 = 0; l.f.b6 = D_00222A50[0].f.b4; idx = flag; l.f.b7 = idx;
    if (b->x24.h.hi) return;
    q = p;
    D_00202008 = D_00201F4C;
    if (!D_00222A50[0].f.b1 && !(q.f.b | q.f.c | q.f.d) && o->x3C.f.b6) {
        D_00202008 = D_00201F48;
    }
    if (!b->x24.f.f.b1) return;
    if (flag) {
        sv = p;
        p.f.g1 = 0;
        Mdl_SetBlendMode_1_0016F280(p);
        p = sv;
    } else {
        Mdl_SetBlendMode_1_0016F280(p);
    }
    idx = n;
    e = ep + idx;
    ce = c + (idx + 1) * 0x140;
    s0 = base + e->x0;
    fp = base + e->x4;
    d0 = *(u16 *)s0;
    h = (Ent_Mdl_DrawMeshesC_1_0016D380 *)s0;
    if (((Flags8 *)(ce + 0x1F8))->f.b3) return;
    if (((Flags8 *)(ce + 0x1F8))->f.b5) return;
    s0 += 0x10;
    if (h->xF & 1) {
        if (D_00222A50[0].f.b3) {
            r = 2;
        } else {
            sceVu0CopyVector(&v, &h->x10);
            v.w = 1.0f;
            sceVu0ApplyMatrix(&v, ce + 0xC0, &v);
            v.w = h->x10.w * *(f32 *)((u8 *)(idx * 0x140) + (s32)c + 0x334);
            r = Gfx_SphereInFrustum_1_00153FA0(&v);
        }
        if (r < 0) return;
        s0 += 0x10;
    }
    Mdl_EmitStrip_1_0016DED0(h, b, c, p);
    k = h->xA;
    if (k != 0xFFFF || !b->x24.f.f.b3) {
        Mdl_BindTexture_0_0016F440(o, b, tbl + (u16)k * 64, len, &l);
        l2 = l;
        if (r < 2 && !l2.f.b5) {
            Mdl_EmitPolys_1_0016EF70(h, s0, fp, d0, len, l2);
        } else {
            Mdl_EmitMeshVu1B_1_0016EB70(h, s0, fp, d0, cc + idx * 0x140 + 0x140, r, len, l2);
        }
    } else {
        Mdl_EmitMeshVu1_1_0016E760(h, s0, fp, d0, cc + idx * 0x140 + 0x140, r, len, tbl, o, b, l);
    }
}
#undef Mdl_SetBlendMode_1_0016F280
#undef Mdl_EmitStrip_1_0016DED0
#undef sceVu0CopyVector
#undef sceVu0ApplyMatrix
#undef Mdl_BindTexture_0_0016F440
#undef Mdl_EmitPolys_1_0016EF70
#undef Mdl_EmitMeshVu1B_1_0016EB70
#undef Mdl_EmitMeshVu1_1_0016E760
#undef D_00222A50

/* Mdl_DrawMeshesD_1_0016D830 */
#define D_00222A50 D_00222A50__as_Mdl_DrawMeshesD_1_0016D830
extern Flags8 D_00222A50__as_Mdl_DrawMeshesD_1_0016D830[];
#define Mdl_SetBlendMode_1_0016F280 Mdl_SetBlendMode_1_0016F280__as_Mdl_DrawMeshesD_1_0016D830
void Mdl_SetBlendMode_1_0016F280__as_Mdl_DrawMeshesD_1_0016D830(U);
#define sceVu0CopyVector sceVu0CopyVector__as_Mdl_DrawMeshesD_1_0016D830
void sceVu0CopyVector__as_Mdl_DrawMeshesD_1_0016D830(Vec *, Vec *);
#define sceVu0ApplyMatrix sceVu0ApplyMatrix__as_Mdl_DrawMeshesD_1_0016D830
void sceVu0ApplyMatrix__as_Mdl_DrawMeshesD_1_0016D830(Vec *, s8 *, Vec *);
#define Mdl_BindTexture_0_0016F440 Mdl_BindTexture_0_0016F440__as_Mdl_DrawMeshesD_1_0016D830
void Mdl_BindTexture_0_0016F440__as_Mdl_DrawMeshesD_1_0016D830(O_Mdl_DrawMeshesD_1_0016D830 *, P_Mdl_DrawMeshesD_1_0016D830 *, s32, s32, FL *);
#define Mdl_EmitPolys_1_0016EF70 Mdl_EmitPolys_1_0016EF70__as_Mdl_DrawMeshesD_1_0016D830
void Mdl_EmitPolys_1_0016EF70__as_Mdl_DrawMeshesD_1_0016D830(Q *, s8 *, s32, s32, s32, FL);
#define Mdl_EmitMeshVu1B_1_0016EB70 Mdl_EmitMeshVu1B_1_0016EB70__as_Mdl_DrawMeshesD_1_0016D830
void Mdl_EmitMeshVu1B_1_0016EB70__as_Mdl_DrawMeshesD_1_0016D830(Q *, s8 *, s32, s32, s8 *, s32, s32, FL);
#define Mdl_EmitMeshVu1_1_0016E760 Mdl_EmitMeshVu1_1_0016E760__as_Mdl_DrawMeshesD_1_0016D830
void Mdl_EmitMeshVu1_1_0016E760__as_Mdl_DrawMeshesD_1_0016D830(Q *, s8 *, s32, s32, s8 *, s32, s32, s32, O_Mdl_DrawMeshesD_1_0016D830 *, P_Mdl_DrawMeshesD_1_0016D830 *, FL);

void Mdl_DrawMeshesD_1_0016D830(O_Mdl_DrawMeshesD_1_0016D830 *o, P_Mdl_DrawMeshesD_1_0016D830 *p, s8 *a2, s32 idx, U u) {
    s32 size;
    s32 x0;
    E *m;
    s32 j;
    u16 hv;
    s32 off;
    Ent_Mdl_DrawMeshesD_1_0016D830 *tbl;
    s32 k;
    Q *e;
    s8 *q;
    s32 r;
    Hdr *h;
    s32 base;
    s32 w;
    Vec v;
    FL fl;
    U u2;
    FL fl2;

    tbl = o->tbl;
    h = o->x10;
    m = (E *)(a2 + 0xC0);
    x0 = h->x0;
    size = h->x4 - x0;
    base = x0 + o->x24;
    fl.w = 0;
    fl.f.b0 = 1;
    fl.f.b1 = 0;
    fl.f.b2 = 0;
    fl.f.b3 = 0;
    fl.f.b4 = 1;
    fl.f.b5 = 0;
    fl.f.b6 = D_00222A50[0].f.b4;
    fl.f.b7 = 0;
    k = 2;
    if (p->f24.f.b6 != 0) return;
    u2 = u;
    D_00202008 = D_00201F4C;
    if (!D_00222A50[0].f.b1) {
        if ((u2.s.f | u2.s.g | u2.s.h) == 0 && o->f3C.f.b6) D_00202008 = D_00201F48;
    }
    if (!p->f24.f.b1) return;
    j = m[idx].x130;
    q = (s8 *)(x0 + tbl[j].x0);
    e = (Q *)q;
    r = x0 + tbl[j].x4;
    w = *(u16 *)e;
    if (j == 0xFF) return;
    if (((Flags8 *)(a2 + idx * 0x140 + 0x1F8))->f.b3) return;
    if (((Flags8 *)(a2 + idx * 0x140 + 0x1F8))->f.b5) return;
    Mdl_SetBlendMode_1_0016F280(u);
    q += 0x10;
    if (e->xF & 1) {
        if (D_00222A50[0].f.b3) {
            k = 2;
        } else {
            sceVu0CopyVector(&v, &e->v10);
            v.w = 1.0f;
            sceVu0ApplyMatrix(&v, (s8 *)&m[idx], &v);
            v.w = e->v10.w * m[idx].f134;
            k = Gfx_SphereInFrustum_1_00153FA0(&v);
        }
        if (k < 0) return;
        q += 0x10;
    }
    Mdl_EmitStripD_0_0016DC70(e, p, a2, idx, u);
    if ((hv = e->hA) != 0xFFFF || !p->f24.f.b3) {
        Mdl_BindTexture_0_0016F440(o, p, base + hv * 64, size, &fl);
        fl2 = fl;
        if (k < 2 && !fl2.f.b5) {
            Mdl_EmitPolys_1_0016EF70(e, q, r, w, size, fl2);
        } else {
            Mdl_EmitMeshVu1B_1_0016EB70(e, q, r, w, (s8 *)&m[idx], k, size, fl2);
        }
    } else {
        Mdl_EmitMeshVu1_1_0016E760(e, q, r, w, (s8 *)&m[idx], k, size, base, o, p, fl);
    }
}
#undef Mdl_SetBlendMode_1_0016F280
#undef sceVu0CopyVector
#undef sceVu0ApplyMatrix
#undef Mdl_BindTexture_0_0016F440
#undef Mdl_EmitPolys_1_0016EF70
#undef Mdl_EmitMeshVu1B_1_0016EB70
#undef Mdl_EmitMeshVu1_1_0016E760
#undef D_00222A50

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F48 */
s32 D_00201F48;
#endif
