#include "common.h"
#include "game/gfx.h"
#include "game/effect.h"
#include "game/data.h"
typedef union { u128 q; u32 w[4]; } Q;
typedef struct { u8 pad[0x16]; u16 x16; } P3;
typedef struct { u8 pad[0x188]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad189[0x180 - 0x189 + 0x10]; } Edummy;
typedef struct { u8 pad[0x180]; f32 x180; u8 pad184[4]; u8 b0:1; u8 b1:1; u8 b2:1; } E;
typedef struct { u8 pad[8]; u16 x8; } Sub;
typedef struct { u8 pad[0xA]; u8 b0:1; u8 pad0B; f32 pad0C[14]; f32 x44; } M;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 rest:3; u8 pad[3]; } F4;
typedef struct { u8 pad[4]; F4 x4; } S;
typedef struct { u8 pad[0xC]; P3 ****xC; u8 pad10[0x1D]; u8 b0:1; u8 b1:1; u8 b2:1; u8 pad2E[0x32]; } N;
typedef struct { f32 x0, x4, x8; s32 xC; u8 pad10[0x18]; u8 x28, x29, x2A, x2B; u8 pad2C[4]; } NS;
typedef struct { u8 pad[0x70]; f32 x70, x74, x78; u8 pad7C[8]; f32 x84; u8 pad88[0x98]; } B;
typedef struct { u16 prev; u16 next; u16 x4; } L;
typedef struct { Vec v[10]; } __attribute__((aligned(16))) V10;
typedef struct { u8 pad[0x10]; V10 v; u8 padB0[0x10]; u8 xC0[0x30]; Vec xF0; } O;
typedef struct { u8 pad[0x20]; f32 x20, x24, x28, x2C; } R;
typedef struct { u8 pad[0x518]; s8 *x518; } Act;
extern N *D_00201FD0;
extern B *D_00201FC0;
extern L *D_00201FD4;
extern Act *D_002022E4;
extern s8 D_001F2160[];
extern Vec D_001F2130;
extern Vec D_001F2140;
extern Vec D_001F2150;
O *Mdl_GetFrameData_0_001715B0(P3 ****);
void sceVu0AddVector(Vec *, P3 *, Vec *);
void Mdl_SetLayerForBounds_0_0016B500(Vec *, u32, s32);
void GsPkt_SetReg_3_001543E0(s32, u64);
R *Map_GetDefaultLight_0_001B72F0(void);
void sceVu0CopyVector(Vec *, Vec *);
Q *GsPkt_Alloc_3_00154A80(s32);
void Mdl_AnimateWrap_0_00171B70(P3 ***, f32, s32);
void sceVu0UnitMatrix(Mtx *);
void Fx_GetWorldMatrix_1_00163C80(B *, Mtx *);
void sceVu0MulMatrix(Mtx *, Mtx *, Mtx *);
void Mdl_UpdateBoneMatricesCur_0_00171540(P3 ***, Mtx *);
void Mdl_DrawLitWrap_0_0016B960(O *, s32, P3 *, u8 *, s32, s32);
void Mdl_DrawMeshesB_1_0016CD80(P3 *, P3 ***, O *, u32);
void Gfx_ResetBlendState_0_00145790(void);

static inline f32 u2f(u32 x) { return x; }
static inline O *getO(N *n) { if (n) return Mdl_GetFrameData_0_001715B0(n->xC); return 0; }

void Sfx_DrawMesh_0_00167C90(E *e, Sub *sub, M *m, S *s) {
    u16 idx;
    s32 k;
    N *n;
    B *b;
    NS *ns;
    O *o;
    f32 f;
    f32 lo, hi, a, c;
    union { u32 w; F4 f; } w;
    Vec v;
    V10 lt;
    Vec q;
    Q tag;
    Mtx m2;
    Mtx m1;
    Q *pk;
    f32 d, t, g;

    idx = sub->x8;
    if (m->x44 == 0.0f && !e->b2) return;
    goto cond;
body:
    {
        k = idx;
        n = &D_00201FD0[k];
        b = &D_00201FC0[k];
        ns = (NS *)n + D_00201F2C;
        o = getO(n);
        if (o && n->xC && ns->xC && o && n->b2) {
            w.w = *(u32 *)&s->x4;
            if (w.f.b4) {
                sceVu0AddVector(&v, ***n->xC, &o->xF0);
                Mdl_SetLayerForBounds_0_0016B500(&v, w.w, 5);
            }
            GsPkt_BeginAD_3_001545D0();
            GsPkt_SetReg_3_001543E0(0, 0x5D);
            GsPkt_SetReg_3_001543E0(0x1B, 0x58);
            GsPkt_SetReg_3_001543E0(0x1A, 0);
            GsPkt_SetReg_3_001543E0(0x42, 0x44);
            GsPkt_SetReg_3_001543E0(0x49, 0);
            GsPkt_Flush_1_001544C0();
            f = u2f(ns->x2B) / 127.0f;
            if (!m->b0) {
                R *r;
                q.x = ns->x0;
                q.y = ns->x4;
                q.z = ns->x8;
                q.w = 1.0f;
                r = Map_GetDefaultLight_0_001B72F0();
                lo = r->x20;
                hi = r->x24;
                a = r->x28;
                c = r->x2C;
                d = Vec_Distance_3_00146940((D_002022E4 != 0 && D_002022E4->x518 != 0) ? D_002022E4->x518 + 0x1C0 : D_001F2160, &q);
                t = (d - lo) / (hi - lo);
                if (1.0f < t) t = 1.0f;
                if (0.0f < t) { g = c - a; g = a + t * g; g = 1.0f - g; }
                else g = 1.0f;
                f *= 0.05f + g;
            }
            if (1.0f < f) f = 1.0f;
            lt.v[0].x = 0.0f;
            lt.v[0].y = 0.0f;
            lt.v[0].z = f;
            lt.v[0].w = 0.0f;
            sceVu0CopyVector(&lt.v[1], &D_001F2130);
            sceVu0CopyVector(&lt.v[2], &D_001F2140);
            sceVu0CopyVector(&lt.v[3], &D_001F2150);
            sceVu0CopyVector(&lt.v[4], &D_003139A0);
            sceVu0CopyVector(&lt.v[5], &D_003139A0);
            sceVu0CopyVector(&lt.v[6], &D_003139A0);
            sceVu0CopyVector(&lt.v[7], &D_003139A0);
            sceVu0CopyVector(&lt.v[8], &D_003139A0);
            lt.v[9].x = 1.0f;
            lt.v[9].y = 1.0f;
            lt.v[9].z = 1.0f;
            lt.v[9].w = 1.0f;
            o->v = lt;
            pk = GsPkt_Alloc_3_00154A80(2);
            tag.q = 0;
            tag.w[0] = 0x10000001;
            tag.w[1] = 0;
            tag.w[3] = 0x6C010056;
            pk[0].q = tag.q;
            tag.w[0] = 4096.0f * u2f(ns->x28);
            tag.w[1] = 4096.0f * u2f(ns->x29);
            tag.w[2] = 4096.0f * u2f(ns->x2A);
            tag.w[3] = 4096.0f * u2f(ns->x2B);
            pk[1].q = tag.q;
            GsPkt_Commit_1_00154A70();
            if (n->xC && (***n->xC)->x16) {
                Mdl_AnimateWrap_0_00171B70(*n->xC, 0.033333335f * b->x84, 0);
            }
            sceVu0UnitMatrix(&m1);
            m1.m[0].x = b->x70 * e->x180;
            m1.m[1].y = b->x74 * e->x180;
            m1.m[2].z = b->x78 * e->x180;
            Fx_GetWorldMatrix_1_00163C80(b, &m2);
            sceVu0MulMatrix(&m2, &m2, &m1);
            Mdl_UpdateBoneMatricesCur_0_00171540(*n->xC, &m2);
            Mdl_DrawLitWrap_0_0016B960(o, 0, ***n->xC, o->xC0, 0, 0);
            Mdl_DrawMeshesB_1_0016CD80(***n->xC, *n->xC, o, *(u32 *)&s->x4);
            GsPkt_CloseChain_1_001549D0();
        }
        idx = D_00201FD4[k].x4;
    }
cond:
    if (idx != 0xFFFF) goto body;
    Gfx_ResetBlendState_0_00145790();
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/screen_fx_flash_data.c): D_001F2130 */
Vec D_001F2130 = { 1.0f, 0.0f, 0.0f, 0.0f };
#endif
