#include "m2c.h"
#include "common.h"
#include "game/gfx.h"
typedef union { u64 d[2]; u128 q; } T_TexAnim_InitTables_0_001746A0;
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C;
    s32 x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    s32 x44;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
typedef struct { u8 pad[0x10]; u16 x10; u16 x12; } T_TexAnim_DrawFrame_0_00174980;
typedef struct { u8 A:2; u8 B:2; u8 C:2; u8 D:2; } Al;
typedef struct {
    u8 pad[0xC]; s16 xC; s16 xE; u8 pad10[4]; s32 x14; u8 pad18[0x10];
    Al x28; u8 x29; struct { u8 b0:1; } x2A;
} M;
typedef struct { f32 x0, x4; u8 pad8[8]; f32 x10, x14, x18, x1C; s32 x20; u8 pad24[4]; u16 x28; } P;
typedef struct { u8 b[0x30]; } E30_TexAnim_Draw_0_00175150;
typedef struct { u8 b[0x2C]; } E2C_TexAnim_Draw_0_00175150;
typedef struct {
    u8 pad0[4];
    u32 n;
    u8 pad8[8];
    u16 w;
    u16 h;
    u8 pad14[0x14];
    u16 *tex;
    u8 pad2c[4];
    E30_TexAnim_Draw_0_00175150 a[8];
    E2C_TexAnim_Draw_0_00175150 b[8];
} T_TexAnim_Draw_0_00175150;
typedef struct { u8 pad0[8]; s16 x8, xA; u8 padC[4]; s16 x10; u8 pad12[0x1E]; } E30_TexAnim_Update_0_001752A0;
typedef struct { f32 x0, x4, x8, xC, x10, x14; u8 pad18[0xC]; u16 x24, x26; u8 pad28[4]; } E2C_TexAnim_Update_0_001752A0;
typedef struct {
    u8 pad0[4];
    u32 n;
    u8 pad8[0x28];
    E30_TexAnim_Update_0_001752A0 a[8];
    E2C_TexAnim_Update_0_001752A0 b[7];
    u8 pad2E4[0x24];
} T_TexAnim_Update_0_001752A0;
typedef struct { u8 pad[8]; T_TexAnim_Update_0_001752A0 t; } Elem;
typedef struct {
    u64 tbp0:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; u64 tcc:1; u64 tfx:2;
    u64 cbp:14; u64 cpsm:4; u64 csm:1; u64 csa:5; u64 cld:3;
} Tex0;
typedef struct { Tex0 t0; u64 t1; } Tex;
typedef struct { u64 key; u8 pad[4]; s16 xC; s16 xE; u8 pad2[8]; f32 x18, x1C, x20, x24; u8 pad3[8]; } ItemA;
typedef struct { f32 x0, x4, x8, xC, x10, x14, x18, x1C; Tex *x20; u16 x24, x26; s16 x28; } ItemB;
typedef struct {
    u8 pad0[4]; u32 count; u8 pad1[4]; s32 xC; s16 x10, x12; u8 pad2[4]; Tex0 x18; u64 x20; u8 pad3[4]; s32 x2C;
    ItemA a[8]; ItemB b[1];
} Obj;
typedef struct { f32 x; f32 y; u8 pad[0x24]; } V;
typedef struct { s32 id; u8 pad[0x1B4]; V v[8]; } S;
typedef struct { u8 pad[8]; S s; u8 pad2[0x310 - 8 - sizeof(S)]; } E_TexAnim_SetScroll_0_001757C0;
typedef struct { s32 x0; s32 pad[9]; s32 x28; } Sub_TexAnim_GetFrame_0_00175850;
typedef struct { u8 pad[8]; Sub_TexAnim_GetFrame_0_00175850 s; u8 rest[0x310 - 8 - 0x2C]; } E_TexAnim_GetFrame_0_00175850;
typedef struct { s8 *p; u8 pad[0x28]; } S2C;
typedef struct { s32 id; u32 n; u32 ref; u8 pad[0x20]; s32 key; u8 pad2[0x1D0-0x30]; S2C s[7]; u8 pad3[0xC]; } E_TexAnim_Release_0_001758B0;
typedef struct { s32 total; s32 pad; E_TexAnim_Release_0_001758B0 e[4]; } G_TexAnim_Release_0_001758B0;
typedef struct { s32 id; u32 n; u32 ref; u8 pad[0x20]; s32 key; u8 s[0x2E0]; } E_TexAnim_Register_0_001759D0;
typedef struct { s32 total; s32 pad; E_TexAnim_Register_0_001759D0 e[4]; } G_TexAnim_Register_0_001759D0;
typedef struct { s32 id; char p[0x24]; s32 h; } Sub_TexAnim_FreeAll_0_00175B40;
typedef struct { char pad[8]; Sub_TexAnim_FreeAll_0_00175B40 s; char rest[0x310 - 8 - sizeof(Sub_TexAnim_FreeAll_0_00175B40)]; } E_TexAnim_FreeAll_0_00175B40;
typedef struct { s32 x0; u8 pad4[8]; u16 xC; u8 padE[10]; u8 x18[8]; u8 x20[8]; s32 x28; } Sub_TexAnim_DrawAll_0_00175BB0;
typedef struct { u8 pad[8]; Sub_TexAnim_DrawAll_0_00175BB0 s; u8 pad2[0x310 - 8 - sizeof(Sub_TexAnim_DrawAll_0_00175BB0)]; } E_TexAnim_DrawAll_0_00175BB0;
typedef struct { int id; char pad[0x30C]; } Item;
typedef struct { int a, b; Item item[4]; } Mgr;
extern s32 D_00201F48;
#ifndef NONMATCHING
extern s32 D_00201FEC;
#else
/* data twins (src/game/data/sbss.c): D_00201FEC */
static s32 D_00201FEC;
#endif
extern s32 D_00202008;
extern T_TexAnim_InitTables_0_001746A0 D_0042D8C0[][2];
extern T_TexAnim_InitTables_0_001746A0 D_0042DDC0[][2];
extern Elem D_00437DC0[4];
void TexAnim_DrawFrame_0_00174980(T_TexAnim_DrawFrame_0_00174980 *t, s32 flag, M *m, P *p);
void TexAnim_Draw_0_00175150(T_TexAnim_Draw_0_00175150 *a0);
void TexAnim_Update_0_001752A0(void);
void TexAnim_Build_0_001754C0(Obj *arg0, s32 arg1);
s32 TexAnim_GetFrame_0_00175850(s32 id);
void TexAnim_Release_0_001758B0(s32 arg0, s32 arg1);
void TexAnim_Register_0_001759D0(s32 id, u32 n, void *src, s32 key);
void* memset(void*, s32, s32);
void GsPkt_SetReg_3_001543E0(s32, u64);
void Draw_Sprite_1_00155BD0(Buf *);
f32 sinf(f32);
Tex* Tex_Find_1_00177AF0(u64, s32);
void Tex_Release_1_00177570(s8 *);
void memcpy(u8 *, void *, u32);
s32 Tex_Resident_0_001777C0(u16, void *, void *);

/* TexAnim_InitTables_0_001746A0 */
#define SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) \
    ((u64)(prim) | ((u64)(iip) << 3) | ((u64)(tme) << 4) | ((u64)(fge) << 5) | ((u64)(abe) << 6) | \
     ((u64)(aa1) << 7) | ((u64)(fst) << 8) | ((u64)(ctxt) << 9) | ((u64)(fix) << 10))
#define SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | ((u64)(flg) << 58) | \
     ((u64)(nreg) << 60))

void TexAnim_InitTables_0_001746A0(void) {
    T_TexAnim_InitTables_0_001746A0 t;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 aa1;
    s32 abe;
    u32 prim;

    if (D_00201FEC == 0) {
        t.d[1] = 0x412;
        for (i = 0; i < 40; i++) {
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    for (c = 0; c < 2; c++) {
                        for (d = 0; d < 2; d++) {
                            for (e = 0; e < 2; e++) {
                                aa1 = e;
                                abe = d;
                                if (d) {
                                    aa1 = 0;
                                }
                                if (aa1) {
                                    abe = 1;
                                }
                                prim = SET_PRIM(4, a, b, c, abe, aa1, 0, 0, 0);
                                t.d[0] = SET_TAG(i, 1, 1, prim, 0, 3);
                                D_0042DDC0[(i << 5) | (a << 4) | (b << 3) | (c << 2) | (d << 1) | e][0] = t;
                                prim = SET_PRIM(5, a, b, c, abe, aa1, 0, 0, 0);
                                t.d[0] = SET_TAG(i, 1, 1, prim, 0, 3);
                                D_0042DDC0[(i << 5) | (a << 4) | (b << 3) | (c << 2) | (d << 1) | e][1] = t;
                            }
                        }
                    }
                }
            }
            t.d[0] = SET_TAG(i, 1, 1, 0x25C, 0, 3);
            D_0042D8C0[i][0] = t;
            t.d[0] = SET_TAG(i, 1, 1, 0x25D, 0, 3);
            D_0042D8C0[i][1] = t;
        }
        D_00201FEC = 1;
        D_00202008 = D_00201F48;
    }
}

/* TexAnim_DrawFrame_0_00174980 */
#define memset memset__as_TexAnim_DrawFrame_0_00174980
void memset__as_TexAnim_DrawFrame_0_00174980(void *, s32, s32);
static inline f32 u2f(u32 x) { return x; }
#define WRAP(x) (((3.1415927f + (x)) - 6.2831855f * (f32)(s32)(0.15915494f * (3.1415927f + (x))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)

void TexAnim_DrawFrame_0_00174980(T_TexAnim_DrawFrame_0_00174980 *t, s32 flag, M *m, P *p) {
    Buf b;
    s32 im;
    f32 sx, sy, ox, oy;
    f32 c0, c1, c2, c3;
    f32 u0, u1, x0, x1;
    s32 i, j, i1m;
    u64 al;
    u64 fog;

    fog = m->x2A.b0;
    memset(&b, 0, 0x50);
    b.f4C.b0 = 1;
    b.f4C.b1 = 1;
    al = (u64)m->x28.A | ((u64)m->x28.B << 2) | ((u64)m->x28.C << 4) | ((u64)m->x28.D << 6) | ((u64)m->x29 << 32);
    if (flag == 0) {
        b.f4C.b2 = 0;
    } else {
        b.f4C.b2 = 1;
    }
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x42, al);
    GsPkt_SetReg_3_001543E0(0x49, fog);
    GsPkt_Flush_1_001544C0();
    Tex_BindFlush_1_00176BC0(p->x20);
    b.x44 = m->x14;
    if (p->x28 != 0) {
        sx = u2f(t->x10) / 4.0f;
        sy = u2f(t->x12) / 4.0f;
        ox = p->x18 / 4.0f;
        oy = p->x1C / 4.0f;
        for (i = 0; i < 4; i++) {
            j = 0;
            im = i % 4;
            i1m = (i + 1) % 4;
            u0 = sx * i;
            x0 = ox * i;
            u1 = sx * (i + 1);
            x1 = ox * (i + 1);
            for (; j < 4; j++) {
                c0 = sinf(WRAP(p->x10 + im));
                c1 = sinf(WRAP(p->x14 + j % 4));
                c2 = sinf(WRAP(p->x10 + i1m));
                c3 = sinf(WRAP(p->x14 + (j + 1) % 4));
                c0 *= c0;
                c2 *= c2;
                c1 *= c1;
                c3 *= c3;
                c0 *= m->xC;
                c2 *= m->xC;
                c1 *= m->xE;
                c3 *= m->xE;
                b.x0 = (s32)((0x800 - (s32)((u32)t->x10 >> 1)) + u0) << 4;
                b.x4 = (s32)((0x800 - (s32)((u32)t->x12 >> 1)) + sy * j) << 4;
                b.x8 = 0;
                b.x10 = (s32)((0x800 - (s32)((u32)t->x10 >> 1)) + u1) << 4;
                b.x14 = (s32)((0x800 - (s32)((u32)t->x12 >> 1)) + sy * (j + 1)) << 4;
                b.x18 = 0;
                b.x20 = c0 + (p->x0 + x0);
                b.x24 = c1 + (p->x4 + oy * j);
                b.x30 = c2 + (p->x0 + x1);
                b.x34 = c3 + (p->x4 + oy * (j + 1));
                Draw_Sprite_1_00155BD0(&b);
            }
        }
    } else {
        b.x0 = (0x800 - (s32)((u32)t->x10 >> 1)) << 4;
        b.x4 = (0x800 - (s32)((u32)t->x12 >> 1)) << 4;
        b.x8 = 0;
        b.x10 = ((s32)((u32)t->x10 >> 1) + 0x800) << 4;
        b.x14 = ((s32)((u32)t->x12 >> 1) + 0x800) << 4;
        b.x18 = 0;
        b.x20 = p->x0;
        b.x24 = p->x4;
        b.x30 = p->x0 + p->x18;
        b.x34 = p->x4 + p->x1C;
        Draw_Sprite_1_00155BD0(&b);
    }
}
#undef memset

/* TexAnim_Draw_0_00175150 */
#define TexAnim_DrawFrame_0_00174980 TexAnim_DrawFrame_0_00174980__as_TexAnim_Draw_0_00175150
extern void TexAnim_DrawFrame_0_00174980__as_TexAnim_Draw_0_00175150(T_TexAnim_Draw_0_00175150 *, u32, E30_TexAnim_Draw_0_00175150 *, E2C_TexAnim_Draw_0_00175150 *);

void TexAnim_Draw_0_00175150(T_TexAnim_Draw_0_00175150 *a0) {
    u32 w = a0->w;
    u32 h = a0->h;
    u64 v = (s64)(s32)((u32)(*a0->tex & 0x3FFF) >> 5) | ((s64)(s32)((u32)w >> 6) << 16);
    u32 i;
    GsPkt_BeginAD_3_001545D0();
    GsPkt_SetReg_3_001543E0(0x4C, v);
    GsPkt_SetReg_3_001543E0(0x40, ((s64)(s32)((u16)w - 1) << 16) | ((s64)(s32)((u16)h - 1) << 48));
    GsPkt_SetReg_3_001543E0(0x18, (s32)((0x800 - (w >> 1)) << 4) | ((s64)(s32)((0x800 - ((u32)(u16)h >> 1)) << 4) << 32));
    GsPkt_SetReg_3_001543E0(8, 0);
    GsPkt_SetReg_3_001543E0(0x47, 0x31001);
    GsPkt_Flush_1_001544C0();
    for (i = 0; i < a0->n; i++) {
        TexAnim_DrawFrame_0_00174980(a0, i, &a0->a[i], &a0->b[i]);
    }
}
#undef TexAnim_DrawFrame_0_00174980

/* TexAnim_Update_0_001752A0 */
static inline f32 mu(s32 x, f32 k) { f32 f = x; return f * k; }

void TexAnim_Update_0_001752A0(void) {
    E30_TexAnim_Update_0_001752A0 *a;
    s32 k;
    u32 i;
    E2C_TexAnim_Update_0_001752A0 *b;
    T_TexAnim_Update_0_001752A0 *t;
    f32 *p;
    f32 fw, fh;
    for (k = 0; k < 4; k++) {
        t = &D_00437DC0[k].t;
        for (i = 0; i < t->n; i++) {
            a = &t->a[i];
            b = &t->b[i];
            p = &b->x0;
            fw = b->x24 << 4;
            fh = b->x26 << 4;
            b->x0 += a->x8 * b->x8;
            b->x4 += a->xA * b->xC;
            b->x10 += 0.05f + 0.0005f * a->x10;
            b->x14 += 0.05f + 0.0005f * a->x10;
            if (p[0] > fw) p[0] = p[0] - mu((s32)(p[0] / fw), fw);
            if (p[1] > fh) p[1] = p[1] - mu((s32)(p[1] / fh), fh);
            if (p[0] < 0.0f) p[0] = p[0] - mu((s32)(p[0] / fw) - 1, fw);
            if (p[1] < 0.0f) p[1] = p[1] - mu((s32)(p[1] / fh) - 1, fh);
        }
    }
}

/* TexAnim_Build_0_001754C0 */
void TexAnim_Build_0_001754C0(Obj *arg0, s32 arg1) {
    ItemB *b;
    ItemA *a;
    u32 i;
    for (i = 0; i < arg0->count; i++) {
        a = &arg0->a[i];
        b = &arg0->b[i];
        if (arg1 != 0) {
            b->x20 = Tex_Find_1_00177AF0(a->key, arg0->x2C);
            b->x26 = 1 << b->x20->t0.th;
            b->x24 = 1 << b->x20->t0.tw;
        }
        b->x0 = 16.0f * (a->x20 * (f32)b->x24);
        b->x4 = 16.0f * (a->x24 * (f32)b->x26);
        *(s32 *)&b->x8 = 0x3F800000;
        *(s32 *)&b->xC = 0x3F800000;
        *(s32 *)&b->x10 = 0;
        *(s32 *)&b->x14 = 0;
        b->x18 = 16.0f * ((f32)b->x24 * a->x18);
        b->x1C = 16.0f * ((f32)b->x26 * a->x1C);
        b->x28 = 0;
        if (a->xC != 0 || a->xE != 0) b->x28 = 1;
        if (i == 0) {
            Tex *t = b->x20;
            s32 h = 1 << t->t0.th;
            s32 w = 1 << t->t0.tw;
            arg0->x10 = w;
            arg0->x12 = h;
            arg0->x18 = b->x20->t0;
            arg0->x18.psm = 0;
            arg0->x18.cbp = 0;
            arg0->x20 = b->x20->t1;
            arg0->xC = (w * h * 4 + 0xFF) / 256;
        }
    }
}

/* TexAnim_SetScroll_0_001757C0 */
#define D_00437DC0 D_00437DC0__as_TexAnim_SetScroll_0_001757C0
extern E_TexAnim_SetScroll_0_001757C0 D_00437DC0__as_TexAnim_SetScroll_0_001757C0[];
static inline S *find_TexAnim_SetScroll_0_001757C0(s32 id) {
    s32 i;
    E_TexAnim_SetScroll_0_001757C0 *e;
    S *s;
    i = 0;
    e = D_00437DC0;
    for (; i < 4; i++, e++) {
        s = &e->s;
        if (s->id == id) return s;
    }
    return NULL;
}
void TexAnim_SetScroll_0_001757C0(s32 id, s32 k, f32 x, f32 y) {
    S *s;
    if (k < 0 || k >= 8) return;
    s = find_TexAnim_SetScroll_0_001757C0(id);
    if (s != NULL) {
        s->v[k].x = x;
        s->v[k].y = y;
    }
}
#undef D_00437DC0

/* TexAnim_GetFrame_0_00175850 */
#define D_00437DC0 D_00437DC0__as_TexAnim_GetFrame_0_00175850
extern E_TexAnim_GetFrame_0_00175850 D_00437DC0__as_TexAnim_GetFrame_0_00175850[];
static inline Sub_TexAnim_GetFrame_0_00175850 *find_TexAnim_GetFrame_0_00175850(s32 id) {
    s32 i;
    E_TexAnim_GetFrame_0_00175850 *e = D_00437DC0;
    Sub_TexAnim_GetFrame_0_00175850 *s;
    for (i = 0; i < 4; i++, e++) {
        s = &e->s;
        if (s->x0 == id) return s;
    }
    return NULL;
}
s32 TexAnim_GetFrame_0_00175850(s32 id) {
    Sub_TexAnim_GetFrame_0_00175850 *s = find_TexAnim_GetFrame_0_00175850(id);
    return s ? s->x28 : 0;
}
#undef D_00437DC0

/* TexAnim_Release_0_001758B0 */
#define D_00437DC0 D_00437DC0__as_TexAnim_Release_0_001758B0
extern G_TexAnim_Release_0_001758B0 D_00437DC0__as_TexAnim_Release_0_001758B0;
static inline E_TexAnim_Release_0_001758B0 *find_TexAnim_Release_0_001758B0(s32 a0, s32 a1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        E_TexAnim_Release_0_001758B0 *e = &D_00437DC0.e[i];
        if (a1 != 0) {
            if (e->id == a0 && e->key == a1) return e;
        } else {
            if (e->id == a0) return e;
        }
    }
    return NULL;
}

void TexAnim_Release_0_001758B0(s32 arg0, s32 arg1) {
    E_TexAnim_Release_0_001758B0 *e = find_TexAnim_Release_0_001758B0(arg0, arg1);
    u32 i;
    if (e->ref >= 2) {
        e->ref--;
        return;
    }
    if (e->ref == 1) {
        D_00437DC0.total--;
        e->ref = 0;
        e->id = -1;
        for (i = 0; i < e->n; i++) {
            if (e->s[i].p != NULL) Tex_Release_1_00177570(e->s[i].p);
        }
    }
}
#undef D_00437DC0

/* TexAnim_Register_0_001759D0 */
#define D_00437DC0 D_00437DC0__as_TexAnim_Register_0_001759D0
extern G_TexAnim_Register_0_001759D0 D_00437DC0__as_TexAnim_Register_0_001759D0;
#define TexAnim_Build_0_001754C0 TexAnim_Build_0_001754C0__as_TexAnim_Register_0_001759D0
void TexAnim_Build_0_001754C0__as_TexAnim_Register_0_001759D0(E_TexAnim_Register_0_001759D0 *, s32);
static inline E_TexAnim_Register_0_001759D0 *find_TexAnim_Register_0_001759D0(s32 a0, s32 a1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        E_TexAnim_Register_0_001759D0 *e = &D_00437DC0.e[i];
        if (a1 != 0) {
            if (e->id == a0 && e->key == a1) return e;
        } else {
            if (e->id == a0) return e;
        }
    }
    return NULL;
}
static inline E_TexAnim_Register_0_001759D0 *findfree(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        E_TexAnim_Register_0_001759D0 *e = &D_00437DC0.e[i];
        if (e->id == -1) return e;
    }
    return NULL;
}

void TexAnim_Register_0_001759D0(s32 id, u32 n, void *src, s32 key) {
    E_TexAnim_Register_0_001759D0 *e = find_TexAnim_Register_0_001759D0(id, key);
    if (e != NULL) {
        e->ref++;
        return;
    }
    e = findfree();
    e->id = id;
    e->ref = 1;
    if (n >= 8) n = 8;
    e->n = n;
    e->key = key;
    memcpy(e->s, src, n * 0x30);
    TexAnim_Build_0_001754C0(e, 1);
    D_00437DC0.total++;
}
#undef TexAnim_Build_0_001754C0
#undef D_00437DC0

/* TexAnim_Tick_0_00175B10 */
#define TexAnim_Update_0_001752A0 TexAnim_Update_0_001752A0__as_TexAnim_Tick_0_00175B10
int TexAnim_Update_0_001752A0__as_TexAnim_Tick_0_00175B10();
void TexAnim_Tick_0_00175B10(f32 fparg0) {
    if (fparg0 != 0.0f) {
        TexAnim_Update_0_001752A0();
    }
}
#undef TexAnim_Update_0_001752A0

/* TexAnim_FreeAll_0_00175B40 */
#define D_00437DC0 D_00437DC0__as_TexAnim_FreeAll_0_00175B40
extern E_TexAnim_FreeAll_0_00175B40 D_00437DC0__as_TexAnim_FreeAll_0_00175B40[4];
#define Tex_Release_1_00177570 Tex_Release_1_00177570__as_TexAnim_FreeAll_0_00175B40
void Tex_Release_1_00177570__as_TexAnim_FreeAll_0_00175B40(s32 h);

void TexAnim_FreeAll_0_00175B40(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        Sub_TexAnim_FreeAll_0_00175B40 *s = &D_00437DC0[i].s;
        if (s->id != -1) {
            Tex_Release_1_00177570(s->h);
            s->h = 0;
        }
    }
}
#undef Tex_Release_1_00177570
#undef D_00437DC0

/* TexAnim_DrawAll_0_00175BB0 */
#define D_00437DC0 D_00437DC0__as_TexAnim_DrawAll_0_00175BB0
extern E_TexAnim_DrawAll_0_00175BB0 D_00437DC0__as_TexAnim_DrawAll_0_00175BB0[4];
#define TexAnim_Draw_0_00175150 TexAnim_Draw_0_00175150__as_TexAnim_DrawAll_0_00175BB0
void TexAnim_Draw_0_00175150__as_TexAnim_DrawAll_0_00175BB0(Sub_TexAnim_DrawAll_0_00175BB0 *);

void TexAnim_DrawAll_0_00175BB0(void) {
    s32 i;
    Sub_TexAnim_DrawAll_0_00175BB0 *s;
    E_TexAnim_DrawAll_0_00175BB0 *e;
    E_TexAnim_DrawAll_0_00175BB0 *f;
    s32 j;
    GsPkt_SetLayerRange_0_001547F0(0, 0);
    for (i = 0, e = D_00437DC0; i < 4; i++, e++) {
        s = &e->s;
        if (e->s.x0 != -1) {
            s->x28 = Tex_Resident_0_001777C0(s->xC, s->x18, s->x20);
        }
    }
    GsPkt_CloseChain_1_001549D0();
    for (j = 0, f = D_00437DC0; j < 4; j++, f++) {
        if (f->s.x0 != -1) {
            TexAnim_Draw_0_00175150(&f->s);
        }
    }
    Tex_FlushAll_1_00176AE0();
    GsPkt_EndLayer_1_00155900();
}
#undef TexAnim_Draw_0_00175150
#undef D_00437DC0

/* TexAnim_Init_0_00175C80 */
/* Clear a manager of four 0x310-byte items and mark each item unused. */

#define memset memset__as_TexAnim_Init_0_00175C80
void *memset__as_TexAnim_Init_0_00175C80(void *, int, unsigned int);

#define D_00437DC0 D_00437DC0__as_TexAnim_Init_0_00175C80
extern Mgr D_00437DC0__as_TexAnim_Init_0_00175C80;

void TexAnim_Init_0_00175C80(void)
{
    int i;

    memset(&D_00437DC0, 0, sizeof(Mgr));
    for (i = 3; i >= 0; i--)
        D_00437DC0.item[i].id = -1;
}
#undef memset
#undef D_00437DC0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/texture_bss.c): D_00437DC0 */
Elem D_00437DC0[4];
#endif
