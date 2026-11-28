/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Glow_Add_0_0015DBF0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR Glow_Add_0_0015DBF0: 19 of 104 words differ (was 28). Same length.
 * Fixed: list push written as a struct { u16 n; u16 l[0x40]; } array at D_0030D588 (l = D_0030D58A),
 * which fixes which base address is built first.
 * Still differs: the list base ends in v1 (retail v0), so the bitfield temp is v0 instead of v1,
 * and sll a0,a0,1 / ddiu -0xFD are scheduled differently around div.s. Tried: perm of the 6
 * statements (v70/v80[3], x54, x58, bitfield group, push), inline push/setf helpers, b38. */
#include "m2c.h"
typedef struct {
    f32 p[2][2][4];
    f32 c[4];
    union { s32 w; struct { u8 b0:1; u8 b1:1; u8 k:6; } f; } x50;
    f32 x54;
    f32 x58;
    s32 x5C;
} Obj;
void sceVu0CopyVector(f32 *, f32 *);
void memset(void *, s32, s32);
extern s32 D_0030D184[];
extern s32 D_0030D188[];
typedef struct { u16 n; u16 l[0x40]; } LL;
extern LL D_0030D588[];
#define L_ D_0030D588
extern u16 D_0030D58A[];
extern Obj D_0030D9A0[];

s32 Glow_Add_0_0015DBF0(s32 kind, f32 *a, f32 *b, f32 r, f32 h) {
    f32 v80[4];
    f32 v70[4];
    Obj *o;
    s32 i;
    s32 idx;
    u16 *cnt;
    u16 *lst;
    s32 off;
    s32 n;

    idx = D_0030D188[--D_0030D184[0]];
    o = &D_0030D9A0[idx];
    memset(o, 0, 0x60);
    sceVu0CopyVector(v80, a);
    sceVu0CopyVector(v70, b);
    v70[3] = h;
    v80[3] = -1.0f / (r * r);
    o->x54 = r;
    o->x58 = h;
    o->x50.w = 0;
    o->x50.f.b0 = 1;
    o->x50.f.k = kind;
    n = L_[kind].n++;
    L_[kind].l[n] = idx;
    for (i = 0; i < 2; i++) {
        sceVu0CopyVector(o->p[i][0], v80);
        sceVu0CopyVector(o->p[i][1], v70);
    }
    sceVu0CopyVector(o->c, v80);
    return idx;
}
#else
INCLUDE_ASM(Glow_Add_0_0015DBF0);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/point_light_bss.c): D_0030D588 */
LL D_0030D588[0x4] __attribute__((aligned(8)));
#endif
