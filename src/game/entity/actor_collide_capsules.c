/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Actor_CollideCapsules_0_00137870.c. The matching build takes it from the assembly that
 * actor.c includes (INCLUDE_ASM(Actor_CollideCapsules_0_00137870)). */
#ifdef NONMATCHING
/* NEAR: still 380 vs 378 words (positional 284); difflib-aligned diff 58 (prev 63, float decl order f,r,rr,dd fixed most f-regs).
 * Remaining: retail spills the OUTER counter i to 0xC0 (sb/lbu) and keeps inner k in s3; we spill k and keep i in fp.
 * Retail also homes out (a2) at 0xD0 leaving 0xD4 empty (we use 0xD4) - something else owns a slot there. f/dd f22/f23 still swapped.
 * u8 decl order (all 120) has no effect; volatile i, separate counter for the else loop, block-scoped k, u8/s32 steps don't help. */
#include "common.h"
u8 Enemy_Get81_1_0013FC00(s8 *);
s32 Enemy_GetCollider_0_0013FB90(s8 *, u8, Vec **, Vec **);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Player_GetPosB_0_001C9490(Vec *);
void Player_GetPos_1_001C9410(Vec *);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }

s32 Actor_CollideCapsules_0_00137870(s8 *a, s8 *b, Vec *out) {
    Vec *pa[4];
    Vec *pb[4];
    Vec *qa[4];
    Vec *qb[4];
    Vec d;
    Vec e;
    Vec c;
    Vec g;
    Vec h;
    Vec lo;
    Vec hi;
    u8 na;
    u8 i;
    u8 nb;
    u8 j;
    u8 k;
    u32 steps;
    f32 len;
    f32 t;
    f32 f;
    f32 r;
    f32 rr;
    f32 dd;

    na = Enemy_Get81_1_0013FC00(a);
    nb = Enemy_Get81_1_0013FC00(b);
    for (i = 0; i < na; i++) {
        Enemy_GetCollider_0_0013FB90(a, i, pa, qa);
        sceVu0SubVector(&d, pa[0], qa[0]);
        len = sqrtf(sceVu0InnerProduct(&d, &d));
        t = 0.9f * pa[0]->w;
        if (!(len <= t)) {
            steps = (u32)(len / t) + 1;
            if (steps > 6) steps = 6;
            for (j = 0; j < nb; j++) {
                Enemy_GetCollider_0_0013FB90(b, j, pb, qb);
                r = pa[0]->w + pb[0]->w;
                k = 0;
                if (k < steps) {
                    rr = r * r;
                    do {
                        f = u2f(k) / u2f(steps);
                        sceVu0ScaleVector(&c, &d, f);
                        sceVu0AddVector(&c, &c, qa[0]);
                        sceVu0SubVector(&e, pb[0], &c);
                        e.y = 0.0f;
                        if (sceVu0InnerProduct(&e, &e) - rr <= 0.0f) {
                            Player_GetPosB_0_001C9490(&lo);
                            Player_GetPos_1_001C9410(&hi);
                            if (c.y < lo.y) {
                                if (c.y < lo.y - r) continue;
                                sceVu0CopyVector(&g, &lo);
                            } else if (!(c.y <= hi.y)) {
                                if (!(c.y <= hi.y + r)) continue;
                                sceVu0CopyVector(&g, &hi);
                            } else {
                                sceVu0CopyVector(&g, &lo);
                                g.y = c.y;
                            }
                            sceVu0SubVector(&e, &g, &c);
                            dd = r - sqrtf(sceVu0InnerProduct(&e, &e));
                            if (!(dd <= 0.0f)) {
                                sceVu0ScaleVector(&h, &d, f);
                                sceVu0SubVector(out, pa[0], &g);
                                sceVu0Normalize(out, out);
                                sceVu0ScaleVector(out, out, 1.0f + dd);
                                sceVu0AddVector(out, out, &h);
                                *(s32 *)&out->w = 0;
                                return 1;
                            }
                        }
                    } while (++k < steps);
                }
            }
        } else {
            Vec e2;
            Vec g2;
            Vec lo2;
            Vec hi2;
            for (k = 0; k < nb; k++) {
                Enemy_GetCollider_0_0013FB90(b, k, pb, qb);
                r = pa[0]->w + pb[0]->w;
                sceVu0SubVector(&e2, pb[0], pa[0]);
                e2.y = 0.0f;
                if (sceVu0InnerProduct(&e2, &e2) - r * r <= 0.0f) {
                    Player_GetPosB_0_001C9490(&lo2);
                    Player_GetPos_1_001C9410(&hi2);
                    if (pa[0]->y < lo2.y) {
                        if (pa[0]->y < lo2.y - r) continue;
                        sceVu0CopyVector(&g2, &lo2);
                    } else if (!(pa[0]->y <= hi2.y)) {
                        if (!(pa[0]->y <= hi2.y + r)) continue;
                        sceVu0CopyVector(&g2, &hi2);
                    } else {
                        sceVu0CopyVector(&g2, &lo2);
                        g2.y = pa[0]->y;
                    }
                    sceVu0SubVector(&e2, &g2, pa[0]);
                    r = r - sqrtf(sceVu0InnerProduct(&e2, &e2));
                    if (!(r <= 0.0f)) {
                        sceVu0SubVector(out, pa[0], &g2);
                        sceVu0Normalize(out, out);
                        sceVu0ScaleVector(out, out, 1.0f + r);
                        *(s32 *)&out->w = 0;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
#endif
