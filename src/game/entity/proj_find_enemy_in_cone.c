/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Proj_FindEnemyInCone_0_00146EF0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: 2 of 128 words differ (was 22). Only diff: the two hoisted mul.s come out as
   mul.s f23,f23,f0 / mul.s f22,f22,f0, retail has mul.s f23,f0,f23 / mul.s f22,f0,f22.
   Keys found: if/else for ok (else ok = 1), copy float params into locals (maxd/hw/hh) to
   get the f21/f23/f22 colouring. In-place `hw = 0.5f * hw` flips the mul operands; a fresh
   result var or `0.5f * w` inside the loop condition (LICM) gives the right order but
   mis-colours (f24/f23 instead of f23/f22). */
#include "common.h"
u16 *ActorList_Next_2_001A5460(s32 *);
void sceVu0Normalize(Vec *, Vec *);
void sceVu0SubVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
f32 fabsf(f32);
s32 Enemy_IsBusy_0_0013EE40(u16 *);
Vec *Enemy_Ptr6F0_1_0013FFA0(u16 *);
f32 Vec_Distance_3_00146940(Vec *, Vec *);
void Vec_GetYawPitchBetween_1_00146310(Vec *, Vec *, Vec *, f32 *, f32 *);
s32 Map_LineTest_1_001470F0(Vec *, Vec *, s32, s32, s32, Vec *);

u16 *Proj_FindEnemyInCone_0_00146EF0(Vec *pos, Vec *dir, s32 check, f32 maxd_, f32 w, f32 h) {
    f32 cc;
    f32 c8;
    s32 it;
    Vec b0;
    Vec a0;
    Vec p;
    Vec out;
    u16 *res;
    u16 *e;
    f32 hw;
    f32 hh;
    f32 maxd;
    f32 best;
    f32 d;
    s32 ok;

    maxd = maxd_;
    hw = w;
    hh = h;
    res = NULL;
    best = 65535.0f;
    it = 0;
    e = ActorList_Next_2_001A5460(&it);
    sceVu0Normalize(&a0, dir);
    if (e != NULL) {
        hw = 0.5f * hw;
        hh = 0.5f * hh;
        do {
            if (*e != 0 && Enemy_IsBusy_0_0013EE40(e) == 0) {
                sceVu0CopyVector(&p, Enemy_Ptr6F0_1_0013FFA0(e));
                d = Vec_Distance_3_00146940(&p, pos);
                if (!(maxd < d)) {
                    sceVu0SubVector(&b0, &p, pos);
                    sceVu0Normalize(&b0, &b0);
                    Vec_GetYawPitchBetween_1_00146310(pos, dir, &p, &cc, &c8);
                    cc = fabsf(cc);
                    c8 = fabsf(c8);
                    if (!(hw < c8) && !(hh < cc)) {
                        d = (1.0f + c8) * (d * (1.0f + cc));
                        if (d < 0.0f) {
                            d = -d;
                        }
                        if (d < best) {
                            if (check != 0) {
                                ok = !Map_LineTest_1_001470F0(pos, &p, 3, 0x26, 0, &out);
                            } else {
                                ok = 1;
                            }
                            if (ok != 0) {
                                best = d;
                                res = e;
                            }
                        }
                    }
                }
            }
            e = ActorList_Next_2_001A5460(&it);
        } while (e != NULL);
    }
    return res;
}
#else
INCLUDE_ASM(Proj_FindEnemyInCone_0_00146EF0);
#endif
