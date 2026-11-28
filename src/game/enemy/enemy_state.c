#include "m2c.h"
#include "common.h"
#include "actor.h"
#include "game/enemy.h"
#include "game/data.h"
typedef struct { s32 *p; } P;
typedef struct { char pad[0x4A8]; P *p; char p1[0xF5]; unsigned char : 3; unsigned char f : 1; char p2[0x170]; u16 h; } Obj;
typedef struct { char pad[0x120]; unsigned int f : 1; } C_Enemy_IsBusy_0_0013EE40;
typedef struct { char pad[0x190]; C_Enemy_IsBusy_0_0013EE40 *c; } B_Enemy_IsBusy_0_0013EE40;
typedef struct { char pad[0x518]; B_Enemy_IsBusy_0_0013EE40 *b; } Q;
typedef struct {
    char pad[0x5A1]; unsigned int : 5; unsigned int a : 1;
    char p2[0x14]; unsigned int : 3; unsigned int s : 1;
} Obj_Enemy_IsBusy_0_0013EE40;
typedef struct {
    char pad[0x5A1];
    unsigned char : 5;
    unsigned char f : 1;
} Obj_Enemy_Set5A1b5_1_0013EE90;
typedef struct { char pad[0x120]; unsigned char : 1; unsigned char f : 1; } C_Enemy_SetDeadFlag_0_0013EEB0;
typedef struct { char pad[0x190]; C_Enemy_SetDeadFlag_0_0013EEB0 *c; } B_Enemy_SetDeadFlag_0_0013EEB0;
typedef struct { char pad[0x518]; B_Enemy_SetDeadFlag_0_0013EEB0 *b; } Obj_Enemy_SetDeadFlag_0_0013EEB0;
typedef struct { char pad[0x6B9]; u8 c; } Obj_Enemy_IncCounter6B9_1_0013EF10;
typedef struct { char pad[0x6B8]; u8 c; } Obj_Enemy_IncCounter6B8_1_0013EF50;
typedef struct { u8 pad[0x120]; Flags8 f; } S2;
typedef struct { s8 pad[6]; u16 n; s8 pad2[0x38]; s8 data[1]; } O;
typedef struct { u8 pad[0xB0]; O **pp; } S;
typedef struct { u8 pad[0x2A]; u8 k; } K;
typedef struct { u8 pad[0x4B4]; K *x4B4[25]; S *x518; } A_Enemy_GetBoneMatrix_0_0013F030;
typedef struct { u8 pad[0x20]; u16 x20; } Part_Enemy_UpdatePartStat_0_0013F0C0;
typedef struct { u8 pad[0x15C]; u16 x15C; u8 pad15E[2]; Flags8 x160; u8 pad161[0xF]; } Ent_Enemy_UpdatePartStat_0_0013F0C0;
typedef struct { u8 pad[0x4B4]; Part_Enemy_UpdatePartStat_0_0013F0C0 *tbl[0x19]; void *x518; Ent_Enemy_UpdatePartStat_0_0013F0C0 *x51C; } A_Enemy_UpdatePartStat_0_0013F0C0;
typedef struct { char pad[0x2A]; u8 idx; } Ent_Enemy_InitPart_1_0013F1B0;
typedef struct { char pad[0x39A]; u8 b[0x11A]; Ent_Enemy_InitPart_1_0013F1B0 *ents[1]; } Obj_Enemy_InitPart_1_0013F1B0;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[8]; u8 x2A; u8 pad2B[2]; Flags8 x2D; } Part_Enemy_BreakPart_0_0013F210;
typedef struct { u8 pad[0x15C]; u16 x15C; u8 pad15E[2]; Flags8 x160; u8 pad161[0xF]; } Ent_Enemy_BreakPart_0_0013F210;
typedef struct { u8 pad[0xB0]; s32 **xB0; u8 padB4[0xB8]; u32 x16C; u8 pad170[0x3C]; u8 *x1AC; } Sub;
typedef struct { u8 pad[6]; u16 h6; } Hdr;
typedef struct {
    u8 pad[0x78];
    u32 x78;
    u8 pad7C[0x1E];
    u8 x9A[0x416];
    u16 *x4B0;
    Part_Enemy_BreakPart_0_0013F210 *tbl[0x19];
    Sub *x518;
    Ent_Enemy_BreakPart_0_0013F210 *x51C;
    u8 pad520[0x90];
    Flags8 f5B0;
    u8 pad5B1[3];
    Flags8 f5B4;
    u8 pad5B5[0x54];
    s8 x609;
    u8 pad60A[0xB0];
    s16 x6BA;
} A_Enemy_BreakPart_0_0013F210;
s32 Enemy_GetMotionId_0_0013ED20(s8 *arg0);
s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *o);
s32 Ent_IsNull0_1_0013EE30(u16 *arg0);
u8 Enemy_IsBusy_0_0013EE40(Obj_Enemy_IsBusy_0_0013EE40 *o);
void Enemy_Set5A1b5_1_0013EE90(Obj_Enemy_Set5A1b5_1_0013EE90 *o, int v);
void Enemy_SetDeadFlag_0_0013EEB0(Obj_Enemy_SetDeadFlag_0_0013EEB0 *o, int v);
s32 Enemy_IsDead_1_0013EEE0(void *arg0);
u8 Enemy_Get6B9_1_0013EF00(void *arg0);
void Enemy_IncCounter6B9_1_0013EF10(Obj_Enemy_IncCounter6B9_1_0013EF10 *o);
u8 Enemy_Get6B8_1_0013EF40(void *arg0);
void Enemy_IncCounter6B8_1_0013EF50(Obj_Enemy_IncCounter6B8_1_0013EF50 *o);
void Enemy_Kill_1_0013EF80(Actor *a, s32 d);
s8* Enemy_GetBoneMatrix_0_0013F030(A_Enemy_GetBoneMatrix_0_0013F030 *a, u8 i);
void Enemy_LoadPartWrap_0_0013F0B0(s32 arg0, s32 arg1);
void Enemy_UpdatePartStat_0_0013F0C0(A_Enemy_UpdatePartStat_0_0013F0C0 *a, u8 k);
void Enemy_InitPart_1_0013F1B0(Obj_Enemy_InitPart_1_0013F1B0 *o, u8 i);
void Enemy_BreakPart_0_0013F210(A_Enemy_BreakPart_0_0013F210 *a, u8 idx, s32 flag);
void EnemyScr_Event2017OnDeath_1_00141260(Actor *, s32);
void Enemy_DropItems_0_001A5990(Actor *);
void Player_OnEnemyKilled_1_001CB980(void *);
void Enemy_ResetPartAnim_1_001A8670(Obj_Enemy_InitPart_1_0013F1B0 *o, u8 i);
void Enemy_HidePart_1_001A8B10(A_Enemy_BreakPart_0_0013F210 *, u8);
void Enemy_ScatterPart_0_001A8700(A_Enemy_BreakPart_0_0013F210 *, u8);
void EnemyScr_Event2010_1_00141DA0(A_Enemy_BreakPart_0_0013F210 *);
void EnemyScr_Event200E_1_00142010(A_Enemy_BreakPart_0_0013F210 *, u8);
void Hud_AddMarker_0_001BC320(u8 *, s32);
s32 Enemy_HidePart_1_001A8B10__as_Enemy_LoadPartWrap_0_0013F0B0();
void Enemy_UpdatePartStat_0_0013F0C0__as_Enemy_InitPart_1_0013F1B0(Obj_Enemy_InitPart_1_0013F1B0 *o, u8 v);

/* Enemy_GetMotionId_0_0013ED20 */
/* Enemy_GetMotionId_0_0013ED20 */
s32 Enemy_GetMotionId_0_0013ED20(s8 *arg0)
{
  s8 **temp_v1;
  u16 new_var;
  s8 *var_v0;
  if (((u64) (((s64) (*((u8 *) (((s8 *) arg0) + 0x5A1)))) << 0x3C)) >> 0x3F)
  {
    return (((s32) (*((u16 *) (((s8 *) arg0) + 0x710)))) % 100) & 0xFF;
  }
  temp_v1 = *((s8 ***) (((s8 *) arg0) + 0x4A8));
  new_var = *((u16 *) (((s8 *) arg0) + 0x4AC));
  if (temp_v1 != 0)
  {
    if (1)
    {
    }
    var_v0 = (signed char *) ((*((s32 *) (((s8 *) (*temp_v1)) + 0x13C))) + ((new_var & 0xFFFF) * 0x54));
  }
  else
  {
    var_v0 = 0;
  }
  if (var_v0 != 0)
  {
    return (((s32) (*((u16 *) (((s8 *) var_v0) + 0x1A)))) % 100) & 0xFF;
  }
  return (((s32) (*((u16 *) (((s8 *) arg0) + 0x710)))) % 100) & 0xFF;
}

/* Enemy_GetTargetHandle_0_0013EDE0 */
s32 Enemy_GetTargetHandle_0_0013EDE0(Obj *o)
{
    s32 r;
    if (o->f)
        r = o->h;
    else if (o->p)
        r = *o->p->p;
    else
        r = 0;
    return r;
}

/* Ent_IsNull0_1_0013EE30 */
s32 Ent_IsNull0_1_0013EE30(u16 *arg0) {
    return *arg0 == 0;
}

/* Enemy_IsBusy_0_0013EE40 */
/* Enemy_IsBusy_0_0013EE40 */
u8 Enemy_IsBusy_0_0013EE40(Obj_Enemy_IsBusy_0_0013EE40 *o)
{
    u8 r = 0;
    r |= ((Q *)o)->b->c->f;
    r |= o->a;
    r |= o->s;
    return r;
}

/* Enemy_Set5A1b5_1_0013EE90 */
/* Bitfield setter on an object's flag byte at 0x5A1. */


void Enemy_Set5A1b5_1_0013EE90(Obj_Enemy_Set5A1b5_1_0013EE90 *o, int v)
{
    o->f = v;
}

/* Enemy_SetDeadFlag_0_0013EEB0 */
void Enemy_SetDeadFlag_0_0013EEB0(Obj_Enemy_SetDeadFlag_0_0013EEB0 *o, int v)
{
    o->b->c->f = v;
}

/* Enemy_IsDead_1_0013EEE0 */
s32 Enemy_IsDead_1_0013EEE0(void *arg0) {
    return M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x518), void **, 0x190), u8 *, 0x120) & 1;
}

/* Enemy_Get6B9_1_0013EF00 */
u8 Enemy_Get6B9_1_0013EF00(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x6B9);
}

/* Enemy_IncCounter6B9_1_0013EF10 */
void Enemy_IncCounter6B9_1_0013EF10(Obj_Enemy_IncCounter6B9_1_0013EF10 *o)
{
    o->c++;
    if (o->c > 0x80)
        o->c = 0x80;
}

/* Enemy_Get6B8_1_0013EF40 */
u8 Enemy_Get6B8_1_0013EF40(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x6B8);
}

/* Enemy_IncCounter6B8_1_0013EF50 */
void Enemy_IncCounter6B8_1_0013EF50(Obj_Enemy_IncCounter6B8_1_0013EF50 *o)
{
    o->c++;
    if (o->c > 0x80)
        o->c = 0x80;
}

/* Enemy_Kill_1_0013EF80 */
void Enemy_Kill_1_0013EF80(Actor *a, s32 d) {
    Flags8 *f = &(*(S2 **)(a->unk518 + 0x190))->f; if (!f->f.b0) { f->f.b0 = 1; EnemyScr_Event2017OnDeath_1_00141260(a, d); if ((*(S2 **)(a->unk518 + 0x190))->f.f.b0) { if (!a->flags5B3.f.b6) Enemy_DropItems_0_001A5990(a); if (!a->flags5B6.f.b1) Player_OnEnemyKilled_1_001CB980(a->unk4B0 + 0x250); } }
}

/* Enemy_GetBoneMatrix_0_0013F030 */
s8 *Enemy_GetBoneMatrix_0_0013F030(A_Enemy_GetBoneMatrix_0_0013F030 *a, u8 i) {
    O *o = *a->x518->pp;
    u8 *cur = (u8 *)((s32)o->data + gSfxAllSbss_00201F2C * (o->n * 0x140 + 0x200));
    u8 *oth = (u8 *)((s32)o->data + !gSfxAllSbss_00201F2C * (o->n * 0x140 + 0x200));
    return (s8 *)(oth + (a->x4B4[i]->k * 0x140 + cur)[0x331] * 0x140 + 0xF0);
}

/* Enemy_LoadPartWrap_0_0013F0B0 */
void Enemy_LoadPartWrap_0_0013F0B0(s32 arg0, s32 arg1) {
    Enemy_HidePart_1_001A8B10__as_Enemy_LoadPartWrap_0_0013F0B0((void *) arg0, arg1);
}

/* Enemy_UpdatePartStat_0_0013F0C0 */
static inline s32 clamp_Enemy_UpdatePartStat_0_0013F0C0(s32 v, s32 hi) {
    if (v < 0) v = 0;
    if (hi < v) v = hi;
    return v;
}
static inline void upd5_Enemy_UpdatePartStat_0_0013F0C0(Ent_Enemy_UpdatePartStat_0_0013F0C0 *e, s32 l1, s32 l2) { e->x15C = clamp_Enemy_UpdatePartStat_0_0013F0C0(e->x15C - l1, l2); }

void Enemy_UpdatePartStat_0_0013F0C0(A_Enemy_UpdatePartStat_0_0013F0C0 *a, u8 k) {
    Ent_Enemy_UpdatePartStat_0_0013F0C0 *e;
    s32 m;
    s32 v;
    s32 mx;
    s32 j;
    j = k;
    e = &a->x51C[k];
    e->x160.f.b0 = 0;
    e->x160.f.b2 = 0;
    m = a->tbl[k]->x20;
    upd5_Enemy_UpdatePartStat_0_0013F0C0(&a->x51C[k], m, m);
    e = (Ent_Enemy_UpdatePartStat_0_0013F0C0 *)((u8 *)a->x51C + j * 0x170);
    mx = a->tbl[k]->x20;
    v = e->x15C + ((u32)(u16)m >> 1);
    if (v < 0) v = 0;
    if (mx < v) v = mx;
    e->x15C = v;
}

/* Enemy_InitPart_1_0013F1B0 */

void Enemy_InitPart_1_0013F1B0(Obj_Enemy_InitPart_1_0013F1B0 *o, u8 i)
{
    Enemy_InitPartState_1_001A8510(o, i);
    Enemy_ResetPartAnim_1_001A8670(o, i);
    Enemy_UpdatePartStat_0_0013F0C0__as_Enemy_InitPart_1_0013F1B0(o, o->b[o->ents[i]->idx]);
}

/* Enemy_BreakPart_0_0013F210 */
/* Enemy_BreakPart_0_0013F210: matched. upd3 passes the limit twice through a 3-param inline (upd5_Enemy_BreakPart_0_0013F210), which avoids CSE of tbl[k] with pp. */

static inline s32 clamp_Enemy_BreakPart_0_0013F210(s32 v, s32 hi) {
    if (v < 0) v = 0;
    if (hi < v) v = hi;
    return v;
}

static inline void upd(Ent_Enemy_BreakPart_0_0013F210 *e, s32 lim) {
    e->x15C = clamp_Enemy_BreakPart_0_0013F210(e->x15C - lim, lim);
}

static inline void upd4(Ent_Enemy_BreakPart_0_0013F210 *e, A_Enemy_BreakPart_0_0013F210 *a, u8 k) { e->x15C = clamp_Enemy_BreakPart_0_0013F210(e->x15C - a->tbl[k]->x20, a->tbl[k]->x20); }
static inline void upd5_Enemy_BreakPart_0_0013F210(Ent_Enemy_BreakPart_0_0013F210 *e, s32 l1, s32 l2) { e->x15C = clamp_Enemy_BreakPart_0_0013F210(e->x15C - l1, l2); }
static inline void upd3(A_Enemy_BreakPart_0_0013F210 *a, u8 k) { upd5_Enemy_BreakPart_0_0013F210(&a->x51C[k], a->tbl[k]->x20, a->tbl[k]->x20); }

void Enemy_BreakPart_0_0013F210(A_Enemy_BreakPart_0_0013F210 *a, u8 idx, s32 flag) {
    u8 k;
    Part_Enemy_BreakPart_0_0013F210 *p;
    Part_Enemy_BreakPart_0_0013F210 **pp;
    Ent_Enemy_BreakPart_0_0013F210 *e;
    u8 i;
    u8 *base;
    u8 *t;
    u8 m, n;
    s32 lim;
    s32 neg;
    u32 *f;
    Hdr *h;
    u8 *b0;
    u8 *b1;

    k = a->x9A[0x300 + a->tbl[idx]->x2A];
    p = a->tbl[k];
    pp = &a->tbl[k];
    e = &a->x51C[k];
    a->f5B4.f.b7 = 1;
    e->x160.f.b0 = 1;
    e->x160.f.b2 = 1;
    base = a->x518->x1AC + 0xC0;
    for (i = 1; i < a->x78 + 1; i++) {
        t = base + i * 0x140;
        m = a->x9A[t[0x130]];
        n = a->x9A[(base + t[0x131] * 0x140)[0x130]];
        if (n != 0xFF && m != 0xFF && a->x51C[n].x160.f.b0) {
            e = &a->x51C[m];
            e->x160.f.b0 = 1;
            e->x160.f.b2 = 1;
            upd(&a->x51C[m], a->tbl[m]->x20);
        }
    }
    if (flag) {
        upd3(a, k);
        neg = -(*pp)->x20;
        f = &a->x518->x16C;
        { s32 v = *(u16 *)f + neg; s32 hi = *a->x4B0; if (v < 0) v = 0; if (hi < v) v = hi; *f = (u16)v; }
        a->x6BA = neg;
        Enemy_HidePart_1_001A8B10(a, k);
        if ((*pp)->x2D.f.b1) {
            a->f5B0.f.b0 = 1;
            EnemyScr_Event2010_1_00141DA0(a);
        }
    } else {
        h = (Hdr *)*a->x518->xB0;
        b0 = (u8 *)((s32)h + 0x40) + gSfxAllSbss_00201F2C * (h->h6 * 0x140 + 0x200);
        b1 = (u8 *)((s32)h + 0x40) + !gSfxAllSbss_00201F2C * (h->h6 * 0x140 + 0x200);
        Hud_AddMarker_0_001BC320(b1 + (b0 + (*pp)->x2A * 0x140)[0x331] * 0x140 + 0xF0, a->x609);
        if (p->x2D.f.b2) {
            Enemy_ScatterPart_0_001A8700(a, k);
        } else {
            Enemy_HidePart_1_001A8B10(a, k);
        }
    }
    EnemyScr_Event200E_1_00142010(a, k);
}
