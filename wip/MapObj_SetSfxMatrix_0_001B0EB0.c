/* NEAR 16 of 103 (was 60): only t1/t2 swapped for the two gp loads gMapSbss_00201E88/gMapSbss_00201E8C (TB[2]/TB[3]); tried separate externs, struct extern, isActive helper, decl perms (120), b38, local copies, arg order. */
#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 x1A; u8 pad2[0x2C - 0x1C]; } Ent;
typedef struct { s32 id; u8 pad[0x74]; u16 x78; u8 pad2[0x150 - 0x7A]; Ent *x150; u8 pad3[0x190 - 0x154]; s32 *x190; u8 pad4[0x1D8 - 0x194]; u8 x1D8; } O;
extern s32 gMapSbss_00201E80;
void Sfx_SetMatrixOrAim_0_00167740(s32, s32);
#define TB ((O ***)&gMapSbss_00201E80)
static inline O *get(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    O *t;
    O *t2;
    O *r;
    r = NULL;
    if (TB[2] != NULL) {
        var_v1 = ((*TB[2])->x1D8 & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        t = *TB[2];
        if (t->id == arg0) {
            r = t;
        }
    }
    var_v1_2 = TB[3] != NULL ? ((*TB[3])->x1D8 & 1) != 0 : 0;
    if (var_v1_2 != 0) {
        t2 = *TB[3];
        if (t2->id == arg0) {
            r = t2;
        }
    }
    return r;
}

static inline s32 findIdx(O *p, s32 k) {
    s32 i;
    if (p == NULL) {
        return -1;
    }
    for (i = 0; i < p->x78; i++) {
        if (k == p->x150[i].x1A % 100) {
            return i;
        }
    }
    return -1;
}

void MapObj_SetSfxMatrix_0_001B0EB0(s32 a0, s32 a1, s32 a2) {
    O *o;
    s32 i;

    o = get(a0);
    i = findIdx(get(a0), a1);
    if (o != NULL && i != -1) {
        Sfx_SetMatrixOrAim_0_00167740(*(s32 *)((u8 *)o->x190 + i * 8), a2);
    }
}

