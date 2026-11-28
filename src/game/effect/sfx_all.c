#include "m2c.h"
#include "actor.h"
#include "common.h"
#include "game/data.h"
#include "game/effect.h"
#include "game/gfx.h"
#include "game/sound.h"
#include "game/core.h"
typedef struct { u8 t:3; u8 r:5; u8 pad[3]; u8 c0:4; u8 c4:1; u8 c5:3; } S_Sfx_DrawAll_1_00168A40;
typedef struct { u8 pad[0x10]; S_Sfx_DrawAll_1_00168A40 s; u8 pad2[0x94 - 0x15]; u8 f0:3; u8 f3:1; u8 f4:4; } M_Sfx_DrawAll_1_00168A40;
typedef struct { u8 d[0x80]; } Sub_Sfx_DrawAll_1_00168A40;
typedef struct {
    u8 pad[0x188];
    u16 b0:1; u16 b1:1; u16 b2:2; u16 b4:1; u16 b5:2; u16 cnt:8; u16 b15:1;
    u8 g0:1; u8 g1:7;
    u8 pad2[0x210 - 0x18B];
    M_Sfx_DrawAll_1_00168A40 *m[(0x270 - 0x210) / 4];
    Sub_Sfx_DrawAll_1_00168A40 sub[24];
    u8 pad3[0xED0 - 0x270 - 24 * 0x80];
} E_Sfx_DrawAll_1_00168A40;
typedef struct { u8 pad[0x90]; E_Sfx_DrawAll_1_00168A40 *e; u16 k; u8 pad2[0x120 - 0x96]; } B_Sfx_DrawAll_1_00168A40;
typedef struct { u16 prev; u16 next; u16 x4; } L;
typedef struct { u8 a:2; u8 b:1; u8 c:5; } BF;
typedef struct {
    u8 pad0[8];
    u16 f8;
    u8 padA[6];
    u8 f10;
    u8 pad11[3];
    Flags8 f14;
} Dat;
typedef struct {
    u8 pad0[8];
    u16 f8;
    u16 fA;
    u8 padC[0x74];
} Ch;
typedef struct {
    u8 pad0[0x210];
    Dat *dat[24];
    Ch ch[1];
} Mgr_Sfx_UpdateInstance_0_00168D70;
typedef struct {
    u8 pad0[0x88];
    f32 f88;
    u8 pad8C[4];
    Mgr_Sfx_UpdateInstance_0_00168D70 *f90;
    u16 f94;
    u8 pad96[0x7A];
    s32 f110;
    Flags8 f114;
} Obj_Sfx_UpdateInstance_0_00168D70;
typedef struct {
    u8 pad0[0x2D];
    Flags8 f2D;
} X;
typedef struct {
    u8 pad0[0xC];
    s8 *fC;
    u8 pad10[0x1D];
    Flags8 f2D;
    u8 pad2E[0x32];
} E_Sfx_UpdateInstance_0_00168D70;
typedef struct {
    u16 prev;
    u16 next;
    u16 f4;
} Node_Sfx_UpdateInstance_0_00168D70;
typedef struct { u8 pad[0x4C]; f32 x, y, z; } M_Sfx_UpdateTransforms_1_00169030;
typedef struct { s32 off; u8 pad4[6]; u16 xA; u8 pad[0x80 - 0xC]; } Sub_Sfx_UpdateTransforms_1_00169030;
typedef struct {
    u8 pad0[0x30];
    Vec pos;
    u8 pad40[0x188 - 0x40];
    u16 b0:1; u16 b1:1; u16 b2:1; u16 b3:1; u16 b4:1; u16 b5:1; u16 b6:1; u16 cnt:8; u16 b15:1;
    u8 g0:1; u8 g1:7;
    u8 pad2[0x210 - 0x18B];
    M_Sfx_UpdateTransforms_1_00169030 *m[(0x270 - 0x210) / 4];
    Sub_Sfx_UpdateTransforms_1_00169030 sub[24];
    s8 **xE70;
    u8 padE74[8];
    s32 xE7C;
    u8 padE80[0x40];
    Vec xEC0;
} E_Sfx_UpdateTransforms_1_00169030;
typedef struct { u8 pad[0xBA]; u16 xBA; } T;
typedef struct { u8 pad[0x158]; T *p158; } S_Sfx_UpdateTransforms_1_00169030;
typedef struct { u8 pad[0x2D]; Flags8 f2D; Flags8 f2E; u8 pad2[0x30 - 0x2F]; } M3_Sfx_UpdateAll_1_00169400;
typedef struct { M3_Sfx_UpdateAll_1_00169400 m[2]; } E_Sfx_UpdateAll_1_00169400;
typedef struct { u8 pad[0x188]; Flags8 f188; } Mgr_Sfx_UpdateAll_1_00169400;
typedef struct { u8 pad[0x90]; Mgr_Sfx_UpdateAll_1_00169400 *f90; u8 pad2[0x114 - 0x94]; Flags8 f114; u8 pad3[0x120 - 0x115]; } B_Sfx_UpdateAll_1_00169400;
typedef struct { f32 v[12]; } M3_Sfx_CullFinished_0_00169630;
typedef struct { M3_Sfx_CullFinished_0_00169630 m[2]; } E_Sfx_CullFinished_0_00169630;
typedef struct { u8 pad[0x114]; Flags8 f114; u8 pad2[0x120 - 0x115]; } B_Sfx_CullFinished_0_00169630;
typedef struct { u16 x0; u8 pad[0x92]; u8 x94; } P;
typedef struct {
    u8 pad[0x174]; f32 x174; u8 p178[0x10]; Flags8 f188; u8 p189; Flags8 f18A; u8 p18B[0x85];
    P *x210; u8 p214[0x5C]; u8 x270[0xC]; s8 x27C;
} O;
typedef struct {
    s32 x0;
    f32 f4;
    s32 x8;
    s8 l;
    s8 r;
    u8 pad[0x72];
} Node_Sfx_ResetTree_0_001698E0;
typedef struct {
    u8 pad[0x270];
    Node_Sfx_ResetTree_0_001698E0 n[1];
} Tree;
typedef struct Node_Sfx_SpawnFromStam_2_00169BD0 { s32 id; s32 size; u32 lo:8; u32 off:24; u16 pad; u16 count; s32 x10, x14, x18; } Node_Sfx_SpawnFromStam_2_00169BD0;
typedef ResNode Node_Sfx_LoadStam_1_00169D70;
typedef struct { u8 pad[0x22]; s16 x22; } Obj_Sfx_LoadStam_1_00169D70;
typedef struct { Obj_Sfx_LoadStam_1_00169D70 *obj; } Blk;
#ifndef NONMATCHING
extern u8 gSfxAllSbss_00201FE0;
#else
/* data twins (src/game/data/sbss.c): gSfxAllSbss_00201FE0 */
static u8 gSfxAllSbss_00201FE0;
#endif
#ifndef NONMATCHING
extern s32 gSfxAllSbss_00201FE4;
#else
/* data twins (src/game/data/sbss.c): gSfxAllSbss_00201FE4 */
static s32 gSfxAllSbss_00201FE4;
#endif
extern B_Sfx_DrawAll_1_00168A40 *gSfxSystemSbss_00201FC0;
extern L *gSfxSystemSbss_00201FD4;
extern BF D_00222A50[];
extern E_Sfx_DrawAll_1_00168A40 gSfxSystemBss_003407E0[];
extern E_Sfx_UpdateInstance_0_00168D70 *gSfxAllSbss_00201FD0;
extern u8 gSfxAllBss_0042D7E0[];
extern s8 gMatrixFromData_001F2160[];
extern s8 gMatrixFromData_001F2170[];
#ifndef NONMATCHING
extern s32 gSfxAllSdata_00201C98;
#else
/* data twins (src/game/data/sdata.c): gSfxAllSdata_00201C98 */
static s32 gSfxAllSdata_00201C98 = 1;
#endif
extern S_Sfx_UpdateTransforms_1_00169030 **gPlayerSbss_002022BC;
#ifndef NONMATCHING
extern s32 gSfxAllSbss_00201FB0;
#else
/* data twins (src/game/data/sbss.c): gSfxAllSbss_00201FB0 */
static s32 gSfxAllSbss_00201FB0;
#endif
extern s32 gSfxSystemBss_0042D850[];
extern s32 *gSfxSystemSbss_00201FE8;
extern s32 gSfxSystemBss_003406E0[];
#ifndef NONMATCHING
extern s8 gSfxAllRodata_001FB8D0[];
#else
/* data twins (src/game/data/sfx_all_rodata.c): gSfxAllRodata_001FB8D0 */
static s8 gSfxAllRodata_001FB8D0[0x20] __attribute__((aligned(8))) = "SFX(%d) not found from STAM\000\000\000\000\000";
#endif
extern const s8 gSfxAllRodata_001FB8F0[];
extern s8 gSfxAllRodata_001FB8F1[];
extern s8 gSfxAllRodata_001FB8F2[];
extern s8 gSfxAllRodata_001FB8F3[];
extern s32 gSfxAllSdata_00201CB8;
s32 Sfx_UpdateInstance_0_00168D70(u16 id, Obj_Sfx_UpdateInstance_0_00168D70 *o, X *x);
s32 Sfx_UpdateTransforms_1_00169030(f32 f);
s32 Sfx_UpdateNode_1_001697A0(O *o, f32 dt);
void Sfx_ResetTree_0_001698E0(Tree *t, Node_Sfx_ResetTree_0_001698E0 *n);
s32 Sfx_Spawn_2_00169B50(s32 id, s32 a1, s32 a2, s32 a3);
s32 Sfx_SpawnFromStam_2_00169BD0(s32 id, s32 *a1, s32 a2, s32 a3, s32 a4, s32 a5);
void Sfx_RegisterList_0_00169D00(s32 *p, u32 n);
s32 Sfx_LoadStam_1_00169D70(s32 *a0, Blk **a1, u32 n);
void Sfx_DrawBillboard_0_00168480(E_Sfx_DrawAll_1_00168A40 *, Sub_Sfx_DrawAll_1_00168A40 *, M_Sfx_DrawAll_1_00168A40 *, S_Sfx_DrawAll_1_00168A40 *);
void Sfx_DrawMesh_0_00167C90(E_Sfx_DrawAll_1_00168A40 *, Sub_Sfx_DrawAll_1_00168A40 *, M_Sfx_DrawAll_1_00168A40 *, S_Sfx_DrawAll_1_00168A40 *);
void Sfx_SortByDepth_0_001679E0(u16);
void FxTable_CallA_0_0014D8E0(u16, Obj_Sfx_UpdateInstance_0_00168D70 *);
void Fx_GetWorldMatrix_1_00163C80(Obj_Sfx_UpdateInstance_0_00168D70 *, f32 *);
void sceVu0CopyVector(void *, void*);
void SndCh_SetPositionStatic_1_00131330(s32, f32 *);
void Mdl_DestroyInstance_0_001745D0(void *, s8 *);
void sceVu0CopyMatrix(Mtx *, void *);
void Camera_Update_1_001C8F90(Mtx *);
void sceVu0InversMatrix(Mtx *, Mtx *);
void sceVu0MulMatrix(void *, Mtx *, Mtx *);
void Sfx_Free_1_001670E0(E_Sfx_UpdateTransforms_1_00169030 *);
void Fx_UpdateChildren_1_00162700(O *, f32, s8);
s32 Sfx_Create_2_00169F40(s32 *, s32, s32, s32, s32, s32, u16);
Node_Sfx_SpawnFromStam_2_00169BD0* Node_FindById_2_0014DCD0(Node_Sfx_SpawnFromStam_2_00169BD0 *, s32);
void sprintf(s8 *, s8 *, s32);
void Mdl_Free_0_00170250(void *a, s32 b);
Blk* Mdl_LoadChunk_0_00170000(u8 *, s32 *, Node_Sfx_LoadStam_1_00169D70 *);

/* Sfx_DrawAll_1_00168A40 */
void Sfx_DrawAll_1_00168A40(void) {
    s32 i;
    s32 j;
    s32 saved;
    E_Sfx_DrawAll_1_00168A40 *e;
    u16 idx;

    if (gSfxAllSbss_00201FE0 == 1) {
        saved = gSfxAllSbss_00201F2C;
        gSfxAllSbss_00201F2C = gSfxAllSbss_00201FE4;
    } else if (gSfxAllSbss_00201FE0 == 2) {
        if (gSfxAllSbss_00201F2C == !(gSfxAllSbss_00201FE4 != 0)) return;
    }
    D_00222A50[0].b = 1;
    Sfx_SortByDepth_0_001679E0(gSfxAllSdata_00201CA4);
    for (idx = gSfxAllSdata_00201CA4; idx != 0xFFFF; idx = gSfxSystemSbss_00201FD4[idx].next) {
        volatile B_Sfx_DrawAll_1_00168A40 *b = &gSfxSystemSbss_00201FC0[idx];
        M_Sfx_DrawAll_1_00168A40 *m = b->e->m[b->k];
        S_Sfx_DrawAll_1_00168A40 *s = &m->s;
        E_Sfx_DrawAll_1_00168A40 *be = b->e;
        if (be->b1 && be->g0) {
            switch (s->t) {
            case 0:
            case 1:
                Sfx_DrawBillboard_0_00168480(be, &be->sub[b->k], m, s);
                break;
            case 2:
                Sfx_DrawMesh_0_00167C90(be, &be->sub[b->k], m, s);
                break;
            }
        }
    }
    for (i = 0, e = gSfxSystemBss_003407E0; i < 0x100; i++, e++) {
        if (e->b0 && !e->b4) {
            GsPkt_CloseChain_1_001549D0();
            if (e->m[0]->f3) {
                GsPkt_SetLayer_1_00154700(5, 0);
            } else {
                GsPkt_SetLayerB_0_00154610(5, 0);
            }
            for (j = 1; j < e->cnt; j++) {
                Sub_Sfx_DrawAll_1_00168A40 *sub = &e->sub[j];
                M_Sfx_DrawAll_1_00168A40 *m = e->m[j];
                S_Sfx_DrawAll_1_00168A40 *s = &m->s;
                if (e->b1 && e->g0 && !s->c4) {
                    switch (s->t) {
                    case 0:
                    case 1:
                        Sfx_DrawBillboard_0_00168480(e, sub, m, s);
                        break;
                    case 2:
                        Sfx_DrawMesh_0_00167C90(e, sub, m, s);
                        break;
                    }
                }
            }
            GsPkt_EndLayer_1_00155900();
        }
    }
    D_00222A50[0].b = 0;
    if (gSfxAllSbss_00201FE0 == 1) gSfxAllSbss_00201F2C = saved;
}

/* Sfx_UpdateInstance_0_00168D70 */
#define sceVu0CopyVector sceVu0CopyVector__as_Sfx_UpdateInstance_0_00168D70
void sceVu0CopyVector__as_Sfx_UpdateInstance_0_00168D70(f32 *, void *);
#define gSfxSystemSbss_00201FD4 gSfxSystemSbss_00201FD4__as_Sfx_UpdateInstance_0_00168D70
extern Node_Sfx_UpdateInstance_0_00168D70 *gSfxSystemSbss_00201FD4__as_Sfx_UpdateInstance_0_00168D70;

s32 Sfx_UpdateInstance_0_00168D70(u16 id, Obj_Sfx_UpdateInstance_0_00168D70 *o, X *x) {
    f32 v[4];
    f32 m[16];
    Dat *d;
    Ch *ch;
    E_Sfx_UpdateInstance_0_00168D70 *e;

    d = o->f90->dat[o->f94];
    x->f2D.f.b3 = 0;
    if ((d->f10 & 7) == 2) {
        gSfxAllSbss_00201FD0[id].f2D.f.b2 = 0;
        gFxSpawnSbss_00201FDC--;
    }
    if (o->f114.f.b2) {
        o->f114.f.b0 = 0;
        o->f114.f.b1 = 0;
        o->f114.f.b2 = 0;
        ch = &o->f90->ch[o->f94];
        ch->fA--;
        if (id == ch->f8) {
            ch->f8 = gSfxSystemSbss_00201FD4[ch->f8].f4;
        }
        Sfx_ListInsert_0_0016AF40(ch->f8, id, d->f14.f.b4);
        return 0;
    }
    FxTable_CallA_0_0014D8E0(d->f8, o);
    if (o->f110 != -1) {
        if (o->f114.f.b5) {
            Fx_GetWorldMatrix_1_00163C80(o, m);
            sceVu0CopyVector(v, &m[12]);
        } else {
            sceVu0CopyVector(v, o);
        }
        SndCh_SetPositionStatic_1_00131330(o->f110, v);
        SndCh_Stop_2_00131440(o->f110);
    }
    Attack_TriggerSfxEvent_0_001D21E0(o, 1);
    o->f114.f.b2 = 1;
    o->f88 = (u32)(o->f114.f.b1 = 0);
    if ((d->f10 & 7) == 2) {
        e = &gSfxAllSbss_00201FD0[id];
        if (e->fC) {
            Mdl_DestroyInstance_0_001745D0(gSfxAllBss_0042D7E0, e->fC);
            e->fC = 0;
        }
    }
    return 1;
}
#undef sceVu0CopyVector
#undef gSfxSystemSbss_00201FD4

/* Sfx_UpdateTransforms_1_00169030 */
#define Sfx_UpdateNode_1_001697A0 Sfx_UpdateNode_1_001697A0__as_Sfx_UpdateTransforms_1_00169030
s32 Sfx_UpdateNode_1_001697A0__as_Sfx_UpdateTransforms_1_00169030(E_Sfx_UpdateTransforms_1_00169030 *, f32);
#define gSfxSystemBss_003407E0 gSfxSystemBss_003407E0__as_Sfx_UpdateTransforms_1_00169030
extern E_Sfx_UpdateTransforms_1_00169030 gSfxSystemBss_003407E0__as_Sfx_UpdateTransforms_1_00169030[];
static inline f32 u2f_Sfx_UpdateTransforms_1_00169030(u32 x) { return x; }
static inline s32 busy(E_Sfx_UpdateTransforms_1_00169030 *e) {
    u32 n; u32 j; s32 found = 0;
    n = e->cnt; for (j = 1; j < n; j++) { if (0 < e->sub[j].xA) { found = 1; break; } }
    return found;
}
static inline void reloc(E_Sfx_UpdateTransforms_1_00169030 *e) {
    if (e != NULL) {
        s32 n; s8 *base; s32 j;
        n = e->cnt; base = *e->xE70 + e->xE7C;
        for (j = 0; j < n; j++) {
            e->m[j] = (M_Sfx_UpdateTransforms_1_00169030 *)(base + e->sub[j].off);
        }
    }
}

s32 Sfx_UpdateTransforms_1_00169030(f32 f) {
    s32 i;
    s32 n;
    E_Sfx_UpdateTransforms_1_00169030 *e;
    s32 v;
    f32 d;
    f32 r;
    Mtx m1;
    Mtx m2;

    n = 0;
    for (i = 0, e = gSfxSystemBss_003407E0; i < 0x100; i++, e++) {
        if (!e->b0) continue;
        n++;
        if (e->b5) {
            e->g0 = 1;
        } else {
            if (gSfxAllSdata_00201C98 == 0) {
                v = 1;
            } else {
                d = Vec_Distance_3_00146940(&e->pos, (gPlayerSbss_002022E4 != NULL && gPlayerSbss_002022E4->unk518 != NULL) ? gPlayerSbss_002022E4->unk518 + 0x1C0 : gMatrixFromData_001F2160);
                if (gPlayerSbss_002022BC != NULL && (*gPlayerSbss_002022BC)->p158 != NULL) {
                    r = u2f_Sfx_UpdateTransforms_1_00169030((*gPlayerSbss_002022BC)->p158->xBA);
                } else {
                    r = 0.0f;
                }
                v = d < r;
            }
            e->g0 = v;
        }
        if (e->b5) {
            sceVu0CopyMatrix(&m1, gMatrixFromData_001F2170);
            m1.m[3].x = e->m[0]->x;
            m1.m[3].y = e->m[0]->y;
            m1.m[3].z = e->m[0]->z;
            *(s32 *)&m1.m[3].w = 0;
            m1.m[3].w = 1.0f;
            Camera_Update_1_001C8F90(&m2);
            sceVu0InversMatrix(&m2, &m2);
            sceVu0MulMatrix(e, &m2, &m1);
        }
        if (e->b3) {
            if (!busy(e)) {
                Sfx_Free_1_001670E0(e);
            }
        } else {
            reloc(e);
            if (Sfx_UpdateNode_1_001697A0(e, f)) {
                e->b3 = 1;
            }
            sceVu0CopyVector(&e->xEC0, &e->pos);
        }
    }
    return n;
}
#undef Sfx_UpdateNode_1_001697A0
#undef gSfxSystemBss_003407E0

/* Sfx_UpdateAll_1_00169400 */
#define Sfx_UpdateTransforms_1_00169030 Sfx_UpdateTransforms_1_00169030__as_Sfx_UpdateAll_1_00169400
s32 Sfx_UpdateTransforms_1_00169030__as_Sfx_UpdateAll_1_00169400(void);
#define Sfx_UpdateInstance_0_00168D70 Sfx_UpdateInstance_0_00168D70__as_Sfx_UpdateAll_1_00169400
s32 Sfx_UpdateInstance_0_00168D70__as_Sfx_UpdateAll_1_00169400(u16, B_Sfx_UpdateAll_1_00169400 *, M3_Sfx_UpdateAll_1_00169400 *);
#define gSfxSystemSbss_00201FC0 gSfxSystemSbss_00201FC0__as_Sfx_UpdateAll_1_00169400
extern B_Sfx_UpdateAll_1_00169400 *gSfxSystemSbss_00201FC0__as_Sfx_UpdateAll_1_00169400;
#define gSfxAllSbss_00201FD0 gSfxAllSbss_00201FD0__as_Sfx_UpdateAll_1_00169400
extern E_Sfx_UpdateAll_1_00169400 *gSfxAllSbss_00201FD0__as_Sfx_UpdateAll_1_00169400;

void Sfx_UpdateAll_1_00169400(f32 dt) {

    u16 i;
    u16 idx;
    u16 next;
    B_Sfx_UpdateAll_1_00169400 *o;
    M3_Sfx_UpdateAll_1_00169400 *e;
    s32 r;

    if (gSfxAllSbss_00201FE0 == 1) return;
    gSfxAllSbss_00201FB0 = Sfx_UpdateTransforms_1_00169030();
    {
    u16 h[2] = {0};
    h[0] = gSfxAllSdata_00201C9C;
    h[1] = gSfxAllSdata_00201CA4;
    for (i = 0; i < 2; i++) {
        idx = h[i];
        while (idx != 0xFFFF) {
            o = &gSfxSystemSbss_00201FC0[idx];
            next = gSfxSystemSbss_00201FD4[idx].next;
            if (o->f114.f.b0) {
                e = &gSfxAllSbss_00201FD0[idx].m[gSfxAllSbss_00201F2C];
                if (o->f90->f188.f.b4 || o->f114.f.b2) {
                    r = 1;
                    e->f2D.f.b3 = 0;
                } else {
                    if (e->f2E.f.b1) {
                        e->f2D.f.b3 = 1;
                        e->f2E.f.b1 = 0;
                    }
                    r = Fx_UpdateEmitter_0_00160370(o, e, dt);
                }
                if (r) Sfx_UpdateInstance_0_00168D70(idx, o, e);
            }
            idx = next;
        }
    }
    }
    GlowFx_Update_0_001E0C10(dt);
    if (gSfxAllSbss_00201FE0 == 2 && gSfxAllSbss_00201FE4 == gSfxAllSbss_00201F2C) gSfxAllSbss_00201FE0 = 1;
}
#undef Sfx_UpdateTransforms_1_00169030
#undef Sfx_UpdateInstance_0_00168D70
#undef gSfxSystemSbss_00201FC0
#undef gSfxAllSbss_00201FD0

/* Sfx_CullFinished_0_00169630 */
#define gSfxSystemSbss_00201FC0 gSfxSystemSbss_00201FC0__as_Sfx_CullFinished_0_00169630
extern B_Sfx_CullFinished_0_00169630 *gSfxSystemSbss_00201FC0__as_Sfx_CullFinished_0_00169630;
#define gSfxAllSbss_00201FD0 gSfxAllSbss_00201FD0__as_Sfx_CullFinished_0_00169630
extern E_Sfx_CullFinished_0_00169630 *gSfxAllSbss_00201FD0__as_Sfx_CullFinished_0_00169630;

void Sfx_CullFinished_0_00169630(void) {
    u16 h[2] = {0};
    s32 i; s32 idx; s32 next;

    h[0] = gSfxAllSdata_00201C9C;
    h[1] = gSfxAllSdata_00201CA4;
    for (i = 0; i < 2; i++) {
        idx = h[i];
        while (idx != 0xFFFF) {
            next = gSfxSystemSbss_00201FD4[idx].next;
            if (gSfxSystemSbss_00201FC0[idx].f114.f.b0) { *(M3_Sfx_CullFinished_0_00169630 *)((s32)&gSfxAllSbss_00201FD0[idx] + gSfxAllSbss_00201F2C * 0x30) = *(M3_Sfx_CullFinished_0_00169630 *)((s32)&gSfxAllSbss_00201FD0[idx] + !(gSfxAllSbss_00201F2C != 0) * 0x30); }
            idx = next;
        }
    }
}
#undef gSfxSystemSbss_00201FC0
#undef gSfxAllSbss_00201FD0

/* Sfx_CompactPool_3_00169780 */
void Sfx_CompactPool_3_00169780(void) {
    Pool_Compact_2_00128210(gSfxSystemBss_0042D850);
}

/* Sfx_PlanCompactPool_3_00169790 */
void Sfx_PlanCompactPool_3_00169790(void) {
    Pool_PlanCompact_1_00128460(gSfxSystemBss_0042D850, -1U);
}

/* Sfx_UpdateNode_1_001697A0 */
static inline f32 u2f_Sfx_UpdateNode_1_001697A0(u32 x) { return x; }
#define Sfx_ResetTree_0_001698E0 Sfx_ResetTree_0_001698E0__as_Sfx_UpdateNode_1_001697A0
void Sfx_ResetTree_0_001698E0__as_Sfx_UpdateNode_1_001697A0(O *, u8 *);

s32 Sfx_UpdateNode_1_001697A0(O *o, f32 dt) {
    P *p;
    f32 lim;

    p = o->x210;
    lim = 0.033333335f * u2f_Sfx_UpdateNode_1_001697A0(p->x0);
    if (p == NULL) return 0;
    if (o->f188.f.b3) return 0;
    if (lim < o->x174 + dt) {
        if (!(p->x94 & 1)) {
            o->x174 = lim;
            return 1;
        }
        o->x174 = 0.0f;
        Sfx_ResetTree_0_001698E0(o, o->x270);
    }
    if (o->f188.f.b2 && o->f18A.f.b0 && o->x27C != 0) {
        Fx_UpdateChildren_1_00162700(o, dt, o->x27C);
    }
    if (o->f188.f.b2) {
        o->x174 += dt;
    }
    return 0;
}
#undef Sfx_ResetTree_0_001698E0

/* Sfx_ResetTree_0_001698E0 */
static inline void g2(Tree *t, Node_Sfx_ResetTree_0_001698E0 *n) {
    n->f4 = 0.0f;
    if (n->l) {
        Sfx_ResetTree_0_001698E0(t, &t->n[n->l]);
    }
    if (n->r) {
        Sfx_ResetTree_0_001698E0(t, &t->n[n->r]);
    }
}
static inline void g1(Tree *t, Node_Sfx_ResetTree_0_001698E0 *n) {
    n->f4 = 0.0f;
    if (n->l) {
        g2(t, &t->n[n->l]);
    }
    if (n->r) {
        g2(t, &t->n[n->r]);
    }
}

void Sfx_ResetTree_0_001698E0(Tree *t, Node_Sfx_ResetTree_0_001698E0 *n) {
    n->f4 = 0.0f;
    if (n->l) {
        g1(t, &t->n[n->l]);
    }
    if (n->r) {
        g1(t, &t->n[n->r]);
    }
}

/* Sfx_Spawn_2_00169B50 */
s32 Sfx_Spawn_2_00169B50(s32 id, s32 a1, s32 a2, s32 a3) {
    if (id == 0) return 0;
    return Sfx_Create_2_00169F40(gSfxSystemSbss_00201FE8, gSfxAllBss_0033F6D0[id], (s32)gSfxSystemBss_003406E0, a1, a2, a3, id);
}

/* Sfx_IsLoaded_2_00169BB0 */
s32 Sfx_IsLoaded_2_00169BB0(s32 i)
{
    return gSfxAllBss_0033F6D0[i] != 0;
}

/* Sfx_SpawnFromStam_2_00169BD0 */
s32 Sfx_SpawnFromStam_2_00169BD0(s32 id, s32 *a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    Node_Sfx_SpawnFromStam_2_00169BD0 *h;
    Node_Sfx_SpawnFromStam_2_00169BD0 *p;
    u32 i;
    s8 buf[256];
    h = Node_FindById_2_0014DCD0((Node_Sfx_SpawnFromStam_2_00169BD0 *)*a1, gSfxAllSdata_00201CA8);
    if (id == 0) return 0;
    if (h == NULL) return 0;
    p = (Node_Sfx_SpawnFromStam_2_00169BD0 *)((s8 *)h + h->off);
    for (i = 0; i < h->count; i++) {
        if (p->id == gSfxCreateSdata_00201CAC && p->x18 == id) {
            return Sfx_Create_2_00169F40(a1, (s32)p - *a1, a2, a3, a4, a5, id);
        }
        p = (Node_Sfx_SpawnFromStam_2_00169BD0 *)((s8 *)p + p->size);
    }
    sprintf(buf, gSfxAllRodata_001FB8D0, id);
    return 0;
}

/* Sfx_RegisterList_0_00169D00 */
#define gSfxAllBss_0042D7E0 gSfxAllBss_0042D7E0__as_Sfx_RegisterList_0_00169D00
extern char gSfxAllBss_0042D7E0__as_Sfx_RegisterList_0_00169D00[];

void Sfx_RegisterList_0_00169D00(s32 *p, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (p[i]) {
            Mdl_Free_0_00170250(gSfxAllBss_0042D7E0, p[i]);
            p[i] = 0;
        }
    }
}
#undef gSfxAllBss_0042D7E0

/* Sfx_LoadStam_1_00169D70 */
#define Node_FindById_2_0014DCD0 Node_FindById_2_0014DCD0__as_Sfx_LoadStam_1_00169D70
extern Node_Sfx_LoadStam_1_00169D70 *Node_FindById_2_0014DCD0__as_Sfx_LoadStam_1_00169D70(Node_Sfx_LoadStam_1_00169D70 *, s32);

s32 Sfx_LoadStam_1_00169D70(s32 *a0, Blk **a1, u32 n) {
    Node_Sfx_LoadStam_1_00169D70 *h;
    s32 cnt;
    Node_Sfx_LoadStam_1_00169D70 *p;
    u32 i;
    Blk *b;
    h = Node_FindById_2_0014DCD0((Node_Sfx_LoadStam_1_00169D70 *)*a0, gSfxAllSdata_00201CB8);
    for (i = 0; i < n; i++) {
        a1[i] = 0;
    }
    if (h == NULL) return 0;
    cnt = 0;
    p = (Node_Sfx_LoadStam_1_00169D70 *)((s8 *)h + h->off);
    for (i = 0; i < h->count; i++) {
        if (p->id == (gSfxAllRodata_001FB8F0[0] | (((const s8 *)gSfxAllRodata_001FB8F0)[1] << 8) | (((const s8 *)gSfxAllRodata_001FB8F0)[2] << 16) | (((const s8 *)gSfxAllRodata_001FB8F0)[3] << 24))) {
            b = Mdl_LoadChunk_0_00170000(gSfxAllBss_0042D7E0, a0, p);
            b->obj->x22++;
            *a1++ = b;
            cnt++;
        }
        p = (Node_Sfx_LoadStam_1_00169D70 *)((s8 *)p + p->size);
    }
    return cnt;
}
#undef Node_FindById_2_0014DCD0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sdata.c): gSfxAllSdata_00201C9C, gSfxAllSdata_00201CA4, gSfxAllSdata_00201CA8, gSfxAllSdata_00201CB8 */
u16 gSfxAllSdata_00201C9C = 0xffff;
u16 gSfxAllSdata_00201CA4 = 0xffff;
s32 gSfxAllSdata_00201CA8 = 0x49535453;
s32 gSfxAllSdata_00201CB8 = 0x4d584653;
/* data twins (src/game/data/sbss.c): gSfxAllSbss_00201F2C, gSfxAllSbss_00201FD0 */
s32 gSfxAllSbss_00201F2C;
E_Sfx_UpdateInstance_0_00168D70 *gSfxAllSbss_00201FD0;
/* data twins (src/game/data/vibration_bss_0033F540.c): gSfxAllBss_0033F6D0 */
s32 gSfxAllBss_0033F6D0[0x400];
/* data twins (src/game/data/texture_bss.c): gSfxAllBss_0042D7E0 */
u8 gSfxAllBss_0042D7E0[0x70];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/sfx_all_rodata.c): D_001FB8F0__grp: gSfxAllRodata_001FB8F0@0x0, gSfxAllRodata_001FB8F1@0x1, gSfxAllRodata_001FB8F2@0x2, gSfxAllRodata_001FB8F3@0x3 */
s32 D_001FB8F0__grp[0x2] __attribute__((aligned(16))) = { 0x4d415453, 0 };
#endif
