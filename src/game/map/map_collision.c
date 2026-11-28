#include "m2c.h"
#include "actor.h"
#include "common.h"
#include "game/collision.h"
#include "game/core.h"
#include "game/script.h"
typedef struct { f32 x, y, z, w; } V;
typedef struct { u8 pad[0x1A]; u16 v; u8 pad2[0x14]; } E30_MapObj_CheckActivate_0_001B1A20;
typedef struct { u8 pad[0x40]; s32 x40; u8 pad2[0x3C]; } E80_MapObj_CheckActivate_0_001B1A20;
typedef struct { s32 id; u8 pad[0x6A]; u16 n; u8 pad2[0xC8]; E30_MapObj_CheckActivate_0_001B1A20 *e30; u8 pad3[0x44]; E80_MapObj_CheckActivate_0_001B1A20 *e80; } Obj_MapObj_CheckActivate_0_001B1A20;
typedef struct { u8 pad[0x24]; f32 x24; } H;
typedef struct { s32 v; u8 pad[0x4C]; } T;
typedef struct { u8 pad[0x1A]; s16 f1A; u8 pad2[0x14]; } E;
typedef struct { s32 pad[3]; T *tbl; s32 pad2[4]; } L;
typedef struct { u8 pad[0x10]; s32 *f10; } O;
typedef struct { s32 pad; O **f4; u8 pad2[0x12C]; E *f134; } A0;
typedef struct { u8 pad[0x20]; O *f20; s32 f24; u8 pad2[0x14]; s32 f3C; } A1;
typedef struct { u8 pad[0x1C]; u16 x1C; } X;
typedef struct { X *x; } Y;
typedef struct { Y *y; } Mdl;
typedef struct { u8 pad[0x18]; u16 x18; u8 pad1A[0x16]; } E30_MapObj_QueryColliders_0_001B1DF0;
typedef struct { u8 pad[0x40]; Mdl **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0x2D]; } E80_MapObj_QueryColliders_0_001B1DF0;
typedef struct { u8 pad[0x1E]; Flags8 x1E; u8 pad1F[0x21]; } E40;
typedef struct {
    u8 pad[0x6E]; u16 n; u8 pad70[0xC8]; E30_MapObj_QueryColliders_0_001B1DF0 *e30; u8 pad13C[0x34]; E40 *e40; u8 pad174[4]; Mdl ***x178; u8 pad17C[4]; E80_MapObj_QueryColliders_0_001B1DF0 *e80;
    u8 pad184[0x54]; Flags8 x1D8;
} Obj_MapObj_QueryColliders_0_001B1DF0;
typedef struct { u8 pad[0x30]; Obj_MapObj_QueryColliders_0_001B1DF0 *o; E30_MapObj_QueryColliders_0_001B1DF0 *c; E80_MapObj_QueryColliders_0_001B1DF0 *e; u8 pad3C[4]; } Ent_MapObj_CheckActivate_0_001B1A20;
typedef struct { u8 pad[0x24]; s32 x24; u8 pad28[8]; Obj_MapObj_QueryColliders_0_001B1DF0 *o; E30_MapObj_QueryColliders_0_001B1DF0 *c; E80_MapObj_QueryColliders_0_001B1DF0 *e; u8 pad3C[0xC]; } Tgt;
typedef union { u128 q[2]; Vec v[2]; } Q2;
typedef struct { u8 pad0[0x24]; s32 x24; u8 pad28[8]; void *x30; void *x34; void *x38; } H_MapColl_RayVsObjects_0_001B2180;
typedef struct { u8 pad0[0x40]; s32 **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0x2D]; } E_MapColl_RayVsObjects_0_001B2180;
typedef struct { u8 pad0[0x18]; u16 x18; u8 pad1A[0x16]; } S;
typedef struct { u8 pad0[0x1E]; Flags8 x1E; u8 pad1F[0x21]; } T_MapColl_RayVsObjects_0_001B2180;
typedef struct {
    u8 pad0[0x6E];
    u16 x6E;
    u8 pad70[0xC8];
    S *x138;
    u8 pad13C[0x34];
    T_MapColl_RayVsObjects_0_001B2180 *x170;
    u8 pad174[4];
    s32 ***x178;
    u8 pad17C[4];
    E_MapColl_RayVsObjects_0_001B2180 *x180;
    u8 pad184[0x54];
    u8 x1D8;
} O_MapColl_RayVsObjects_0_001B2180;
typedef Bits8 BF_MapColl_RayCast_0_001B23E0;
typedef Bits8 BF_MapColl_CapsuleCast_1_001B2800;
typedef struct { s8 **pp; u16 x4; u16 x6; } H2;
typedef struct { H2 *h; } H_MapColl_CapsuleCast_1_001B2800;
typedef struct { s32 **x0; u16 x4; u16 x6; } HH;
typedef struct { u8 pad0[0x40]; HH **x40; u8 pad44[0xC]; u8 x50; u8 pad51; Flags8 x52; u8 pad53[0xD]; f32 x60; u8 pad64[0xC]; Vec x70; } E_MapColl_SphereCast_0_001B2B90;
typedef struct { u8 pad0[0x12]; Flags8 x12; u8 pad13[0xB]; Flags8 x1E; u8 pad1F[0x21]; } T_MapColl_SphereCast_0_001B2B90;
typedef struct { u8 pad0[0x10]; s32 *x10; u16 x14; u16 x16; u16 x18; u16 pad1A; u16 x1C; } C;
typedef struct { s32 x0; s32 x4; s32 x8; u8 pad[0x44]; } Ent_MapColl_ClampIndex_0_001B2160;
typedef struct { u8 pad0[0x20]; C *x20; u8 pad24[0xC]; void *x30; S *x34; E_MapColl_SphereCast_0_001B2B90 *x38; s32 x3C; } Out;
typedef struct {
    u8 pad0[0x6E];
    u16 x6E;
    u8 pad70[0xC8];
    S *x138;
    u8 pad13C[0x34];
    T_MapColl_SphereCast_0_001B2B90 *x170;
    u8 pad174[0xC];
    E_MapColl_SphereCast_0_001B2B90 *x180;
    u8 pad184[0x54];
    Flags8 x1D8;
} O_MapColl_SphereCast_0_001B2B90;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:6; } BF_MapColl_RayCastAll_0_001B2F30;
extern u16 gMapCommandBss_00317238[];
extern BF_MapColl_RayCast_0_001B23E0 D_00222A52__as_MapColl_RayCast_0_001B23E0[];
s32 MapObj_CheckActivate_0_001B1A20(Obj_MapObj_CheckActivate_0_001B1A20 *o, s32 idx, s32 a2);
s32 MapObj_GetSection_0_001B1CB0(s32 arg0, void *arg1, s32 *arg2);
E* MapObj_FindCollider_0_001B1D00(A0 *arg0, A1 *arg1);
void MapObj_QueryColliders_0_001B1DF0(Obj_MapObj_QueryColliders_0_001B1DF0 *o, Tgt *t, s32 a2, u8 a3, s32 t0, s32 *out, s32 n, Ent_MapObj_CheckActivate_0_001B1A20 *ents);
void MapColl_ClampIndex_0_001B2160(void *a, s32 *b, s32 *c, s32 d, s32 e);
s32 MapColl_RayVsObjects_0_001B2180(O_MapColl_RayVsObjects_0_001B2180 *o, H_MapColl_RayVsObjects_0_001B2180 *h, Q2 *src, void *a3, s32 flags);
s32 MapColl_RayCast_0_001B23E0(s8 *o, s8 *out, f32 *ray, u16 idx, u8 f1, u8 f2);
s32 MapColl_CapsuleCast_1_001B2800(s8 *o, s8 *out, Vec *ray, u16 idx, u8 f1, u8 f2);
s32 MapColl_SphereCast_0_001B2B90(O_MapColl_SphereCast_0_001B2B90 *o, Out *out, Vec *p, u16 idx, u8 f1, u8 f2);
s32 MapColl_RayCastAll_0_001B2F30(s8 *o, s8 *out, f32 *ray, u8 f1, u8 f2);
void sceVu0CopyVector(void *, void*);
s8* Mdl_GetFrameData_0_001715B0(s32);
void sceVu0CopyMatrix(V *, void *);
void sceVu0SubVector(V *, V *, V *);
f32 sceVu0InnerProduct(V *, V *);
f32 atan2f(f32, f32);
s32 Event_CheckTrigger_0_00179F80(Msg *);
f32 sqrtf(f32);
void Mdl_GetSectionPtrs_1_00171050(O *, L *);
void Coll_QueryMapCells_0_001520E0(Tgt *, Mdl *, s32, u8, s32, s32 *, s32, Ent_MapObj_CheckActivate_0_001B1A20 *, Obj_MapObj_QueryColliders_0_001B1DF0 *, s32);
s32 Coll_RayVsModel_1_0014FA30(H_MapColl_RayVsObjects_0_001B2180 *, s32 *, Q2 *, void *, O_MapColl_RayVsObjects_0_001B2180 *, s32);
void memset(void *, s32, s32);
s32 Coll_SphereVsSphere_0_0014EE10(f32 *, s8 *);
s32 Coll_RayVsMesh_1_0014DDE0(s32 *, s8 *, s32, f32 *, s8 *, u8, u8);
s32 Coll_CapsuleVsMesh_1_0014E230(s8 *, s8 *, s32, Vec *, Vec *, s8 *, u8, u8);
f32 Vec_DistSq_3_0015DF20(Vec *, Vec *);
s32 Coll_SphereVsMesh_1_0014E680(Out *, Ent_MapColl_ClampIndex_0_001B2160 *, s32, Vec *, s8 *, u8, u8);
void sceVu0CopyVector__as_MapColl_RayVsObjects_0_001B2180(Vec *, H_MapColl_RayVsObjects_0_001B2180 *);
void sceVu0CopyVector__as_MapColl_RayCast_0_001B23E0(s8 *, s32 *);
s8* Mdl_GetFrameData_0_001715B0__as_MapColl_CapsuleCast_1_001B2800(H_MapColl_CapsuleCast_1_001B2800 *);
s32 Coll_RayVsMesh_1_0014DDE0__as_MapColl_RayCastAll_0_001B2F30(s32 *, s8 *, s32, f32 *, s8 *, u8, s32);
void sceVu0CopyVector__as_MapColl_RayCastAll_0_001B2F30(s8 *, s32 *);

/* MapObj_CheckActivate_0_001B1A20 */
#define sceVu0CopyVector sceVu0CopyVector__as_MapObj_CheckActivate_0_001B1A20
void sceVu0CopyVector__as_MapObj_CheckActivate_0_001B1A20(V *, void *);

/* MapObj_CheckActivate_0_001B1A20 */
/* MapObj_CheckActivate_0_001B1A20 */
/* MapObj_CheckActivate_0_001B1A20 */
static inline s32 send(Msg *msg, s32 a2, s32 k, s32 id, s32 idx, V *q, f32 yaw, f32 b, f32 a, s32 fl) {
    if (D_00222A52[0].f.b4) return 0;
    msg->type = a2; msg->a = k; msg->b = id; msg->c = idx;
    msg->x = q->x; msg->y = q->y; msg->z = q->z; msg->w = q->w;
    msg->f = fl; msg->p = b; msg->h = yaw; msg->r = a;
    return Event_CheckTrigger_0_00179F80(msg);
}

s32 MapObj_CheckActivate_0_001B1A20(Obj_MapObj_CheckActivate_0_001B1A20 *o, s32 idx, s32 a2) {
    V p;
    V m[4];
    V q;
    Msg msg;
    s32 k;
    E80_MapObj_CheckActivate_0_001B1A20 *e;
    s8 *s;
    f32 t, yaw, a, b;
    s32 fl;
    s32 r;
    s32 id;
    E30_MapObj_CheckActivate_0_001B1A20 *c = &o->e30[idx];
    e = &o->e80[idx];
    k = c->v % 100;
    if (k != 0) {
    s = gPlayerSbss_002022E4->unk518 + 0x180;
    sceVu0CopyVector(&p, s + 0x40);
    t = 3.1415927f + (*(H **)(s + 0x18))->x24;
    yaw = 180.0f * ((t - 6.2831855f * (s32)(0.15915494f * t)) + (t < 0.0f ? 6.2831855f : 0.0f) - 3.1415927f) / 3.1415927f;
    sceVu0CopyMatrix(m, Mdl_GetFrameData_0_001715B0(e->x40) + 0x200);
    sceVu0SubVector(&q, &m[3], &p);
    { f32 d = sqrtf(sceVu0InnerProduct(&q, &q)); q.w = d; } a = 180.0f * atan2f(-q.x, -q.z) / 3.1415927f;
    b = 180.0f * atan2f(m[2].x, m[2].z) / 3.1415927f;
    fl = (gMapCommandBss_00317238[0] & 0x2000) != 0;
    r = send(&msg, a2, k, o->id, idx, &q, yaw, b, a, fl);
    } else {
        r = 0;
    }
    return r;
}

/* MapObj_GetSection_0_001B1CB0 */
s32 MapObj_GetSection_0_001B1CB0(s32 arg0, void *arg1, s32 *arg2) {
    s32 temp_2;

    temp_2 = M2C_FIELD(arg1, s32 *, 0x34);
    if (temp_2 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg1, s32 *, 0x30) != arg0) {
        return 0;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(arg1, s32 *, 0x38);
    }
    return temp_2;
}

/* MapObj_FindCollider_0_001B1D00 */
E *MapObj_FindCollider_0_001B1D00(A0 *arg0, A1 *arg1) {
    L l;
    E *r = NULL;
    O *o;
    s32 t;
    s32 base;
    s32 idx;
    E *e;

    if (arg1->f24 == 0) {
        return NULL;
    }
    o = *arg0->f4;
    if (arg1->f20 != o) {
        return NULL;
    }
    base = *o->f10;
    Mdl_GetSectionPtrs_1_00171050(o, &l);
    idx = arg1->f3C;
    if (idx != -1) {
        e = (E *)((u8 *)(idx * sizeof(E)) + (s32)arg0->f134);
        t = base + l.tbl[e->f1A].v;
        if (t == arg1->f24) {
            r = e;
        }
    }
    return r;
}

/* MapObj_QueryColliders_0_001B1DF0 */
void MapObj_QueryColliders_0_001B1DF0(Obj_MapObj_QueryColliders_0_001B1DF0 *o, Tgt *t, s32 a2, u8 a3, s32 t0, s32 *out, s32 n, Ent_MapObj_CheckActivate_0_001B1A20 *ents) {
    s32 j;
    s32 cnt;
    s32 got;
    Tgt buf;
    s32 i;
    E80_MapObj_QueryColliders_0_001B1DF0 *e;
    E30_MapObj_QueryColliders_0_001B1DF0 *c;
    E40 *d;
    Mdl **pp;
    X *x;

    cnt = 0;
    if (o->x1D8.f.b0) {
        Coll_QueryMapCells_0_001520E0(t, **o->x178, a2, a3, t0, &cnt, n, ents, o, 0);
        for (j = 0; j < n; j++) {
            ents[j].o = o;
        }
        t->o = o;
        if (t0 >= 0 && cnt != 0) {
            if (out) {
                *out = cnt;
            }
            return;
        }
        if (!D_00222A52[0].f.b4) {
            for (i = 0; i < o->n; i++) {
                e = &o->e80[i];
                c = &o->e30[i];
                d = &o->e40[c->x18];
                if (!(e->x50 & 3) && !e->x52.f.b4 && e->x52.f.b3) {
                    pp = e->x40;
                    x = **(X ***)*pp;
                    got = 0;
                    if (x->x1C) {
                        if (t->x24) {
                            Coll_QueryMapCells_0_001520E0(&buf, *pp, a2, a3, t0, &got, n - cnt, &ents[cnt], 0, d->x1E.f.b3);
                        } else {
                            Coll_QueryMapCells_0_001520E0(t, *pp, a2, a3, t0, &got, n - cnt, &ents[cnt], 0, d->x1E.f.b3);
                            if (t->x24) {
                                t->o = o;
                                t->e = e;
                                t->c = c;
                            }
                        }
                        for (j = 0; j < got; j++) {
                            (&ents[cnt])[j].o = o;
                            (&ents[cnt])[j].c = c;
                            (&ents[cnt])[j].e = e;
                        }
                        cnt += got;
                    }
                }
            }
        }
        if (out) {
            *out = cnt;
        }
    }
}
#undef sceVu0CopyVector

/* MapColl_ClampIndex_0_001B2160 */
#define MapObj_QueryColliders_0_001B1DF0 MapObj_QueryColliders_0_001B1DF0__as_MapColl_ClampIndex_0_001B2160
void MapObj_QueryColliders_0_001B1DF0__as_MapColl_ClampIndex_0_001B2160(void *a, s32 *b, s32 *c, s32 d, s32 e, void *f, s32 g, void *h);

/* MapColl_ClampIndex_0_001B2160 */
void MapColl_ClampIndex_0_001B2160(void *a, s32 *b, s32 *c, s32 d, s32 e)
{
    if (e < -1)
        e = -1;
    MapObj_QueryColliders_0_001B1DF0(a, b, c, d, e, NULL, 0, NULL);
}

/* MapColl_RayVsObjects_0_001B2180 */

s32 MapColl_RayVsObjects_0_001B2180(O_MapColl_RayVsObjects_0_001B2180 *o, H_MapColl_RayVsObjects_0_001B2180 *h, Q2 *src, void *a3, s32 flags) {
    Q2 buf;
    s32 i;
    E_MapColl_RayVsObjects_0_001B2180 *e;
    S *s;
    T_MapColl_RayVsObjects_0_001B2180 *t;
    u8 f;

    if (o == NULL) return 0;
    if (h == NULL) return 0;
    if (src == NULL) return 0;
    if (a3 == NULL) return 0;
    if (flags == 0) return 0;
    if (!(o->x1D8 & 1)) return 0;
    buf = *src;
    f = flags;
    if (f & 1) {
        if (Coll_RayVsModel_1_0014FA30(h, **o->x178, &buf, a3, o, 0)) {
            sceVu0CopyVector__as_MapColl_RayVsObjects_0_001B2180(&buf.v[1], h);
            h->x30 = o;
            if (f & 4) return 1;
        }
    }
    if (!(f & 2)) return h->x24;
    if (D_00222A52[0].f.b4) return h->x24;
    for (i = 0; i < o->x6E; i++) {
        e = &o->x180[i];
        s = &o->x138[i];
        t = &o->x170[s->x18];
        if (e->x50 & 3) continue;
        if (e->x52.f.b4) continue;
        if (!e->x52.f.b3) continue;
        if (Coll_RayVsModel_1_0014FA30(h, *e->x40, &buf, a3, 0, t->x1E.f.b3)) {
            sceVu0CopyVector__as_MapColl_RayVsObjects_0_001B2180(&buf.v[1], h);
            h->x30 = o;
            h->x38 = e;
            h->x34 = s;
            if (f & 4) return 1;
        }
    }
    return h->x24;
}

/* MapColl_RayCast_0_001B23E0 */

s32 MapColl_RayCast_0_001B23E0(s8 *o, s8 *out, f32 *ray, u16 idx, u8 f1, u8 f2) {
    s32 buf[16] __attribute__((aligned(16)));
    s8 *g;
    s8 *s3;
    s8 *c;
    s32 i;
    s32 found;
    s8 *v;
    s8 *e;
    s8 *h;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;
    f32 best;

    found = 0;
    if (D_00222A52__as_MapColl_RayCast_0_001B23E0[0].b4) return 0;
    if (!f1 || o == NULL) return 0;
    if (((BF_MapColl_RayCast_0_001B23E0 *)(o + 0x1D8))->b1 || !((BF_MapColl_RayCast_0_001B23E0 *)(o + 0x1D8))->b0) return 0;
    if (idx >= *(u16 *)(o + 0x6E)) return 0;
    e = *(s8 **)(o + 0x138) + idx * 0x30;
    s3 = *(s8 **)(o + 0x180) + idx * 0x80;
    g = *(s8 **)(o + 0x170) + *(u16 *)(e + 0x18) * 0x40;
    if (!((BF_MapColl_RayCast_0_001B23E0 *)(g + 0x12))->b6) return 0;
    if ((*(u8 *)(s3 + 0x50) & 3) || ((BF_MapColl_RayCast_0_001B23E0 *)(s3 + 0x52))->b4 || !((BF_MapColl_RayCast_0_001B23E0 *)(s3 + 0x52))->b3) return 0;
    if (!Coll_SphereVsSphere_0_0014EE10(ray, s3 + 0x70)) return 0;
    if (*(s8 **)(s3 + 0x40) == NULL || (h = **(s8 ***)(s3 + 0x40)) == NULL) return 0;
    if (*(s8 **)h == NULL || (c = **(s8 ***)h) == NULL) return 0;
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = Mdl_GetFrameData_0_001715B0(*(s32 *)(s3 + 0x40));
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    memset(buf, 0, 0x40);
    best = 1.0f;
    if (!(ray[7] <= 0.0f)) {
        best += ray[3] / ray[7];
    }
    for (i = ((BF_MapColl_RayCast_0_001B23E0 *)(g + 0x1E))->b3 != 0; i < *(u16 *)(h + 6); i++) {
        k = *(u8 *)(v + i * 0x140 + 0x332);
        if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
            ent = tbl + k * 0x50;
            if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                Coll_RayVsMesh_1_0014DDE0(buf, ent, a2, ray, v + (i + 1) * 0x140 + 0xC0, f1, !(*(f32 *)(s3 + 0x60) > 1.0f)) != 0 && *(f32 *)&buf[3] < best) {
                best = *(f32 *)&buf[3];
                sceVu0CopyVector__as_MapColl_RayCast_0_001B23E0(out, buf);
                sceVu0CopyVector__as_MapColl_RayCast_0_001B23E0(out + 0x10, buf + 4);
                *(s8 **)(out + 0x20) = c;
                *(s32 *)(out + 0x24) = buf[9];
                *(s32 *)(out + 0x28) = buf[10];
                *(s32 *)(out + 0x2C) = buf[11];
                *(s32 *)(out + 0x3C) = i;
                *(s8 **)(out + 0x30) = o;
                *(s8 **)(out + 0x38) = s3;
                *(s8 **)(out + 0x34) = e;
                found = 1;
                if (f2) return found;
            }
        }
    }
    return found;
}

/* MapColl_CapsuleCast_1_001B2800 */

s32 MapColl_CapsuleCast_1_001B2800(s8 *o, s8 *out, Vec *ray, u16 idx, u8 f1, u8 f2) {
    s8 *g;
    s8 *s2;
    s8 *c;
    s32 found;
    s32 i;
    s8 *v;
    s32 off;
    s8 *e;
    H_MapColl_CapsuleCast_1_001B2800 *p;
    H2 *h;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;

    found = 0;
    if (D_00222A52[0].f.b4) return 0;
    if (!f1 || o == NULL) return 0;
    if (((BF_MapColl_CapsuleCast_1_001B2800 *)(o + 0x1D8))->b1 || !((BF_MapColl_CapsuleCast_1_001B2800 *)(o + 0x1D8))->b0) return 0;
    if (!(idx < *(u16 *)(o + 0x6E))) return 0;
    e = *(s8 **)(o + 0x138) + idx * 0x30;
    s2 = *(s8 **)(o + 0x180) + idx * 0x80;
    g = *(s8 **)(o + 0x170) + *(u16 *)(e + 0x18) * 64;
    if (!((BF_MapColl_CapsuleCast_1_001B2800 *)(g + 0x12))->b6) return 0;
    if ((*(u8 *)(s2 + 0x50) & 3) || ((BF_MapColl_CapsuleCast_1_001B2800 *)(s2 + 0x52))->b4 || !((BF_MapColl_CapsuleCast_1_001B2800 *)(s2 + 0x52))->b3) return 0;
    if (!Coll_SegmentVsSphere_1_0014EF40(ray, ray + 1, (Vec *)(s2 + 0x70), 0.0f)) return 0;
    if ((p = *(H_MapColl_CapsuleCast_1_001B2800 **)(s2 + 0x40)) == NULL || (h = p->h) == NULL) return 0;
    if (h->pp == NULL || (c = *h->pp) == NULL) return 0;
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = Mdl_GetFrameData_0_001715B0__as_MapColl_CapsuleCast_1_001B2800(p);
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    for (i = ((BF_MapColl_CapsuleCast_1_001B2800 *)(g + 0x1E))->b3 != 0; i < h->x6; i++) {
        k = *(u8 *)(v + i * 0x140 + 0x332);
        if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
            ent = tbl + k * 0x50;
            if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                Coll_CapsuleVsMesh_1_0014E230(out, ent, a2, ray, ray + 1, v + (i + 1) * 0x140 + 0xC0, f1, !(*(f32 *)(s2 + 0x60) > 1.0f)) != 0) {
                *(s8 **)(out + 0x20) = c;
                *(s32 *)(out + 0x3C) = i;
                *(s8 **)(out + 0x30) = o;
                *(s8 **)(out + 0x38) = s2;
                *(s8 **)(out + 0x34) = e;
                found = 1;
                if (f2) return found;
            }
        }
    }
    return found;
}

/* MapColl_SphereCast_0_001B2B90 */
s32 MapColl_SphereCast_0_001B2B90(O_MapColl_SphereCast_0_001B2B90 *o, Out *out, Vec *p, u16 idx, u8 f1, u8 f2) {
    s8 *v;
    E_MapColl_SphereCast_0_001B2B90 *e;
    C *c;
    T_MapColl_SphereCast_0_001B2B90 *t;
    s32 i;
    s32 found;
    S *s;
    HH *h;
    Ent_MapColl_ClampIndex_0_001B2160 *tbl;
    Ent_MapColl_ClampIndex_0_001B2160 *ent;
    s32 a2;
    u32 k;
    f32 r;

    found = 0;
    if (D_00222A52[0].f.b4) return 0;
    if (!f1 || o == NULL) return 0;
    if (o->x1D8.f.b1 || !o->x1D8.f.b0) return 0;
    if (!(idx < o->x6E)) return 0;
    s = &o->x138[idx];
    e = &o->x180[idx];
    t = &o->x170[s->x18];
    if (!t->x12.f.b6) return 0;
    if ((e->x50 & 3) || e->x52.f.b4 || !e->x52.f.b3) return 0;
    r = e->x70.w + p->w;
    if (!(Vec_DistSq_3_0015DF20(p, &e->x70) <= r * r)) return 0;
    if (e->x40 == NULL || (h = *e->x40) == NULL) return 0;
    if (h->x0 == NULL || (c = (C *)*h->x0) == NULL) return 0;
    tbl = (Ent_MapColl_ClampIndex_0_001B2160 *)((u32)c + 0x40 + c->x14 * 16 + c->x16 * 8 + c->x18 * 4);
    a2 = *c->x10;
    v = Mdl_GetFrameData_0_001715B0((s32)e->x40);
    if (v == NULL || c->x1C == 0) return 0;
    for (i = t->x1E.f.b3 != 0; i < h->x6; i++) {
        k = *(u8 *)(v + i * 0x140 + 0x332);
        if (k != 0xFF && k < c->x1C) {
            ent = &tbl[k];
            if (ent->x0 != 0 && ent->x8 != 0 &&
                Coll_SphereVsMesh_1_0014E680(out, ent, a2, p, v + (i + 1) * 0x140 + 0xC0, f1, !(e->x60 > 1.0f)) != 0) {
                out->x20 = c;
                out->x3C = i;
                out->x30 = o;
                out->x38 = e;
                out->x34 = s;
                found = 1;
                if (f2) return found;
            }
        }
    }
    return found;
}

/* MapColl_RayCastAll_0_001B2F30 */

s32 MapColl_RayCastAll_0_001B2F30(s8 *o, s8 *out, f32 *ray, u8 f1, u8 f2) {
    s32 buf[16] __attribute__((aligned(16)));
    s8 *s3;
    s8 *c;
    s32 i;
    s32 found;
    s8 *v;
    s8 *e;
    s8 *tbl;
    s32 a2;
    s8 *ent;
    u32 k;
    f32 best;

    found = 0;
    if (!f1 || o == NULL) return 0;
    if (((BF_MapColl_RayCastAll_0_001B2F30 *)(o + 0x1D8))->b1 || !((BF_MapColl_RayCastAll_0_001B2F30 *)(o + 0x1D8))->b0) return 0;
    if (*(s8 ***)(o + 4) == NULL || (c = **(s8 ***)(o + 4)) == NULL) return 0;
    e = *(s8 **)(o + 0x134);
    s3 = *(s8 **)(o + 0x178);
    tbl = (s8 *)((u32)c + 0x40 + *(u16 *)(c + 0x14) * 16 + *(u16 *)(c + 0x16) * 8 + *(u16 *)(c + 0x18) * 4);
    a2 = **(s32 **)(c + 0x10);
    v = Mdl_GetFrameData_0_001715B0(*(s32 *)s3);
    if (v == NULL || *(u16 *)(c + 0x1C) == 0) return 0;
    memset(buf, 0, 0x40);
    best = 1.0f;
    if (!(ray[7] <= 0.0f)) {
        best += ray[3] / ray[7];
    }
    for (i = 0; i < *(u16 *)(o + 0x6C); i++, e += 0x30, s3 += 8) {
        if (*(s16 *)(e + 0x1A) != -1 && ((BF_MapColl_RayCastAll_0_001B2F30 *)(s3 + 4))->b0 && !((BF_MapColl_RayCastAll_0_001B2F30 *)(s3 + 4))->b1) {
            k = *(u8 *)(v + i * 0x140 + 0x332);
            if (k != 0xFF && k < *(u16 *)(c + 0x1C)) {
                ent = tbl + k * 0x50;
                if (*(s32 *)ent != 0 && *(s32 *)(ent + 8) != 0 &&
                    Coll_RayVsMesh_1_0014DDE0__as_MapColl_RayCastAll_0_001B2F30(buf, ent, a2, ray, v + (i + 1) * 0x140 + 0xC0, f1, 1) != 0 && *(f32 *)&buf[3] < best) {
                    best = *(f32 *)&buf[3];
                    sceVu0CopyVector__as_MapColl_RayCastAll_0_001B2F30(out, buf);
                    sceVu0CopyVector__as_MapColl_RayCastAll_0_001B2F30(out + 0x10, buf + 4);
                    *(s8 **)(out + 0x20) = c;
                    *(s32 *)(out + 0x24) = buf[9];
                    *(s32 *)(out + 0x28) = buf[10];
                    *(s32 *)(out + 0x2C) = buf[11];
                    *(s32 *)(out + 0x3C) = i;
                    *(s8 **)(out + 0x30) = o;
                    *(s32 *)(out + 0x38) = 0;
                    *(s32 *)(out + 0x34) = 0;
                    found = 1;
                    if (f2) return found;
                }
            }
        }
    }
    return found;
}
#undef MapObj_QueryColliders_0_001B1DF0
