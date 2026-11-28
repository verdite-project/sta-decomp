/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Actor_CollideCapsulesB_0_00137E60.c. The matching build takes it from the assembly that
 * actor.c includes (INCLUDE_ASM(Actor_CollideCapsules_0_00137870)). */
#ifdef NONMATCHING
/* NEAR 16 of 384 words (unchanged). `out` home 0xC4 vs retail 0xC0 (retail leaves 0xC4 unused between b and out), and t/dd f22/f23 swapped. Tried all 120 float decl orders, extra unused params (int/float, every position), local copies of params (36 decl/assign orders), body/fin inlines, dummy locals, b38, dd/t reusing len. */
#include "common.h"
s32 Enemy_Get81_1_0013FC00(s8 *);
s32 Enemy_GetCollider_0_0013FB90(s8 *, u8, Vec **, Vec **);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0ScaleVector(Vec *, Vec *, f32);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0Normalize(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
void Player_GetHeadPos_0_001C93A0(Vec *);
void Player_SetPosition_0_001C9320(Vec *);
void Player_GetPosB_0_001C9490(Vec *);
void Player_GetPos_1_001C9410(Vec *);
f32 sqrtf(f32);
static inline f32 u2f(u32 x) { return x; }

s32 Actor_CollideCapsulesB_0_00137E60(s8 *a, s8 *b, Vec *out) {
    Vec *pa[4];
    Vec *pb[4];
    Vec *qa[4];
    Vec *qb[4];
    Vec d;
    Vec e;
    Vec f;
    Vec c1;
    Vec c2;
    Vec g;
    Vec h;
    Vec e2;
    Vec c3;
    Vec c4;
    Vec g2;
    u8 i;
    u8 j;
    u32 steps;
    u32 k;
    u8 nb;
    u8 na;
    f32 rr;
    f32 dd;
    f32 t;
    f32 r;
    f32 len;

    na = Enemy_Get81_1_0013FC00(a);
    nb = Enemy_Get81_1_0013FC00(b);
    for (i = 0; i < na; i++) {
        Enemy_GetCollider_0_0013FB90(a, i, pa, qa);
        sceVu0SubVector(&d, pa[0], qa[0]);
        len = sqrtf(sceVu0InnerProduct(&d, &d));
        if (!(len <= 0.9f * pa[0]->w)) {
            steps = (u32)(len / (0.9f * pa[0]->w)) + 1;
            if (steps > 6) steps = 6;
            for (j = 0; j < nb; j++) {
                Enemy_GetCollider_0_0013FB90(b, j, pb, qb);
                r = pa[0]->w + pb[0]->w;
                for (k = 0; k < steps; k = (u8)(k + 1)) {
                    rr = r * r;
                    Player_GetHeadPos_0_001C93A0(&c1);
                    Player_SetPosition_0_001C9320(&c2);
                    t = u2f(k) / u2f(steps);
                    sceVu0ScaleVector(&f, &d, t);
                    sceVu0AddVector(&c1, &f, &c1);
                    sceVu0AddVector(&c2, &f, &c2);
                    sceVu0AddVector(&f, &f, qa[0]);
                    sceVu0SubVector(&e, pb[0], &f);
                    e.y = 0.0f;
                    if (sceVu0InnerProduct(&e, &e) - rr <= 0.0f) {
                        if (pb[0]->y < c1.y) {
                            if (pb[0]->y < c1.y - r) continue;
                            sceVu0CopyVector(&g, &c1);
                        } else if (!(pb[0]->y <= c2.y)) {
                            if (!(pb[0]->y <= c2.y + r)) continue;
                            sceVu0CopyVector(&g, &c2);
                        } else {
                            sceVu0CopyVector(&g, &c1);
                            g.y = pb[0]->y;
                        }
                        sceVu0SubVector(&e, pb[0], &g);
                        dd = r - sqrtf(sceVu0InnerProduct(&e, &e));
                        if (!(dd <= 0.0f)) {
                            sceVu0ScaleVector(&h, &d, t);
                            sceVu0SubVector(out, &g, pb[0]);
                            sceVu0Normalize(out, out);
                            sceVu0ScaleVector(out, out, 1.0f + dd);
                            sceVu0AddVector(out, out, &h);
                            out->w = 0.0f;
                            return 1;
                        }
                    }
                }
            }
        } else {
            for (j = 0; j < nb; j++) {
                Enemy_GetCollider_0_0013FB90(b, j, pb, qb);
                r = pa[0]->w + pb[0]->w;
                Player_GetPosB_0_001C9490(&c3);
                Player_GetPos_1_001C9410(&c4);
                sceVu0SubVector(&e2, pb[0], pa[0]);
                e2.y = 0.0f;
                if (sceVu0InnerProduct(&e2, &e2) - r * r <= 0.0f) {
                    if (pb[0]->y < c3.y) {
                        if (pb[0]->y < c3.y - r) continue;
                        sceVu0CopyVector(&g2, &c3);
                    } else if (!(pb[0]->y <= c4.y)) {
                        if (!(pb[0]->y <= c4.y + r)) continue;
                        sceVu0CopyVector(&g2, &c4);
                    } else {
                        sceVu0CopyVector(&g2, &c3);
                        g2.y = pb[0]->y;
                    }
                    sceVu0SubVector(&e2, pb[0], &g2);
                    r = r - sqrtf(sceVu0InnerProduct(&e2, &e2));
                    if (!(r <= 0.0f)) {
                        sceVu0SubVector(out, &g2, pb[0]);
                        sceVu0Normalize(out, out);
                        sceVu0ScaleVector(out, out, 1.0f + r);
                        out->w = 0.0f;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
#endif
