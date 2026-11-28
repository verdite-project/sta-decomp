/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Attack_SpawnHitEffect_1_001D2CB0.c.
 * The retail assembly of Attack_SpawnHitEffect_1_001D2CB0 also holds Attack_Ricochet_0_001D31E0. */
#include "include_asm.h"

#ifdef NONMATCHING
// NEAR: 18 of 330 words differ (was 45). Remaining: 2nd-loop rec index addu operand order (addu v0,a2,v0),
// final rand-compare bc1t threads straight to loop exit (retail lands on a b), last-block q address computation scheduling (retail loads x7,x5,x4,x6).
#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u8 pad0[4]; u8 x4; u8 x5; u8 x6; B8 x7; } Rec;
typedef struct { u8 pad0[0x90]; s8 *x90; u16 x94; } O;
typedef struct { f32 f0; u8 pad4[8]; union { s32 w; struct { B8 c; B8 d; } b; } u; } Ent;
typedef struct { u16 x0; u16 x2; u8 pad4[0x24]; } E2;
typedef struct { u8 pad0[0x2AD]; B8 x2AD; } P4B0;
typedef struct { u16 x0; u8 pad2[0x4AE]; P4B0 *x4B0; } A1;
void Fx_GetWorldMatrix_1_00163C80(O *, Mtx *);
void sceVu0CopyVector(Vec *, Vec *);
void Attack_HandleSfxEvent_1_001D3810(O *, u8, E2 *, Mtx *, A1 *, s32, s32);
u32 Rand_Next_3_0015ED20(void);
static inline f32 u2f(u32 x) { return x; }

static inline u8 flags(Ent *e) {
    u8 r = 0;
    if (e->u.w == 0) return 0;
    if (e->u.b.c.b0) r |= 1;
    if (e->u.b.c.b1) r |= 2;
    if (e->u.b.c.b2) r |= 4;
    if (e->u.b.c.b3) r |= 8;
    return r;
}

s32 Attack_SpawnHitEffect_1_001D2CB0(O *o, A1 *a, s32 a2, Vec *pos, s32 mode) {
    Ent *found[4];
    Mtx M;
    Mtx M2;
    Ent **pp;
    s32 res;
    E2 *q;
    Ent *e;
    Rec *rec;
    s32 k;
    s32 j;
    s32 i;
    s32 any;
    u8 m;
    s32 mask;

    res = 0;
    rec = ((Rec **)(*(s8 **)((s32)o + 0x90) + 0x210))[*(u16 *)((s32)o + 0x94)];
    e = (Ent *)(rec->x6 * 12 + (rec->x5 * 4 + ((s32)((u8 *)(rec->x4 * 20) + (s32)rec))) + 0x108);
    any = 0;
    mask = 0;
    if (a->x0 == 0) {
        mask |= 1;
    } else {
        mask |= 6;
    }
    if (a->x4B0->x2AD.b2) mask |= 8;
    pp = found;
    for (i = 0; i < 4; i++, e++) {
        m = flags(e);
        pp[i] = 0;
        if (m & mask) {
            res = 1;
            if (e->u.b.d.b3 == 0) {
                if (mode == 2) {
                    pp[i] = e;
                    any = res;
                }
            } else {
                pp[i] = e;
                any = res;
            }
        }
    }
    if (!any) return res;
    {
        s32 k2;
        E2 *q2;
        Ent **p2;
        s32 j2;
        Rec *r2;
        p2 = pp;
        for (j2 = 0; j2 < 4; j2++, p2++) {
            if (*p2) {
                r2 = ((Rec **)(*(s8 **)((s32)o + 0x90) + 0x210))[*(u16 *)((s32)o + 0x94)];
                q2 = (E2 *)((r2->x7.b1 ? 4 : 0) * 16 + (r2->x6 * 12 + (r2->x5 * 4 + ((s32)((u8 *)(r2->x4 * 20) + (s32)r2)))) + 0x108);
                Fx_GetWorldMatrix_1_00163C80(o, &M);
                sceVu0CopyVector(&M.m[3], pos);
                M.m[3].w = 1.0f;
                for (k2 = 0; k2 < 4; k2++, q2++) {
                    if (q2->x2 == j2) Attack_HandleSfxEvent_1_001D3810(o, 4, q2, &M, a, 0, a2);
                }
            }
        }
    }
    if (mode == 2) {
        res = 0;
        for (j = 0; j < 4; j++, pp++) {
            Ent *f = *pp;
            if (!(f != 0) == 0) {
                if (f->f0 == 0.0f) break;
                res = 100.0f <= f->f0;
                if (res) break;
                res = 100.0f * (1.5259022e-05f * (f32)(Rand_Next_3_0015ED20() & 0xFFFF)) < f->f0;
                break;
            }
        }
        rec = ((Rec **)(*(s8 **)((s32)o + 0x90) + 0x210))[*(u16 *)((s32)o + 0x94)];
        q = (E2 *)((s32)rec + rec->x6 * 12 + rec->x4 * 20 + rec->x5 * 4 + (rec->x7.b1 ? 4 : 0) * 16 + 0x108);
        Fx_GetWorldMatrix_1_00163C80(o, &M2);
        sceVu0CopyVector(&M2.m[3], pos);
        M2.m[3].w = 1.0f;
        for (k = 0; k < 4; k++, q++) {
            if (q->x2 == j) Attack_HandleSfxEvent_1_001D3810(o, res ? 5 : 6, q, &M2, a, 0, a2);
        }
    }
    return res;
}
#else
INCLUDE_ASM(Attack_SpawnHitEffect_1_001D2CB0);
#endif
