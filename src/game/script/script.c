#include "common.h"
#include "m2c.h"
#include "game/script.h"
typedef struct { s32 x0; u8 p[0x10]; u32 x14; } S_Script_ResetSlot_1_00164F10;
typedef struct { f32 v; char pad[8 - sizeof(f32)]; } E_Script_GetResultF32_1_00164F60;
typedef struct { char pad[0x370]; E_Script_GetResultF32_1_00164F60 e[1][75]; } Obj_Script_GetResultF32_1_00164F60;
typedef struct { s8 v; char pad[8 - sizeof(s8)]; } E_Script_GetResultS8_1_00164F90;
typedef struct { char pad[0x370]; E_Script_GetResultS8_1_00164F90 e[1][75]; } Obj_Script_GetResultS8_1_00164F90;
typedef struct { u8 v; char pad[8 - sizeof(u8)]; } E_Script_GetResultU8_1_00164FC0;
typedef struct { char pad[0x370]; E_Script_GetResultU8_1_00164FC0 e[1][75]; } Obj_Script_GetResultU8_1_00164FC0;
typedef struct { s32 a; f32 b; } E_Script_SetArgF32_1_00164FF0;
typedef struct { char pad[0x36C]; E_Script_SetArgF32_1_00164FF0 e[1][75]; } Obj_Script_SetArgF32_1_00164FF0;
typedef struct { s32 a; s32 b; } E8;
typedef struct { E8 e[75]; } Row;
typedef struct { s32 a, b; } E_Script_SetArgU8_1_00165070;
typedef struct { u8 pad[0x258]; } S_Script_SetArgU8_1_00165070;
typedef struct { u8 type; u8 pad[3]; s32 val; } Ent;
typedef struct { u8 pad[0xC]; u16 c; u16 e; } Hdr_Script_ResolveOperand_1_00165150;
typedef ScrVal Val;
typedef struct { s32 type; Val v; } Var;
typedef struct { u8 pad[0xC]; u16 c; u16 e; } Hdr_Script_StoreLocal_0_00165260;
typedef struct { s32 type; union { s32 i; u32 u; f32 f; } v; } Out;
typedef struct { u8 pad[0xC]; u16 xC; u16 xE; } Hdr_Script_LoadStack_0_001655C0;
extern s32 gScriptEventSbss_00201FA4;
extern void *gEnemyScriptSbss_00201FA8;
extern s8 * gScriptData_001F1C50[];
void ScrCmd_NopE_2_00164F00(void);
#pragma explicit_zero_data on
s8 *D_001F2300[0x10] = { (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00, (s8 *)ScrCmd_NopE_2_00164F00 };
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s8 *D_0033F500[0x10];
void Script_ResetSlot_1_00164F10(S_Script_ResetSlot_1_00164F10 *a);
f32 Script_GetResultF32_1_00164F60(Obj_Script_GetResultF32_1_00164F60 *o, u8 i, u8 j);
s8 Script_GetResultS8_1_00164F90(Obj_Script_GetResultS8_1_00164F90 *o, u8 i, u8 j);
u8 Script_GetResultU8_1_00164FC0(Obj_Script_GetResultU8_1_00164FC0 *o, u8 i, u8 j);
void Script_SetArgF32_1_00164FF0(Obj_Script_SetArgF32_1_00164FF0 *o, u8 i, u8 j, f32 f);
void Script_SetArgS8_1_00165030(u8 *a0, u8 a1, u8 a2, s8 a3);
void Script_SetArgU8_1_00165070(u8 *p, u8 i, u8 j, u8 v);
void Script_SetArgS16_1_001650B0(u8 *a0, u8 a1, u8 a2, s16 a3);
void Script_SetArgU16_1_001650F0(u8 *o, u8 i, u8 j, u16 v);
void Script_GetArgPtr_2_00165130(s32 arg0, s32 arg1);
s8* Script_ResolveOperand_1_00165150(s32 arg0, Hdr_Script_ResolveOperand_1_00165150 *arg1, Ent *arg2);
void Script_StoreLocal_0_00165260(s32 a0, Var *src, Hdr_Script_StoreLocal_0_00165260 *h, s32 a3, s32 v);
void Script_StoreGlobal_0_00165340(s32 a0, u8 *a1, s32 a2, s32 a3);
void Script_LoadLocal_1_00165400(u8 *a0, s32 a1, s32 a2);
void Script_LoadStack_0_001655C0(void *a0, Out *out, Hdr_Script_LoadStack_0_001655C0 *h, s32 key, s32 off);
void Script_LoadGlobal_0_001656B0(u8 *a0, Out *out, s32 key, s32 off);
void Script_LoadLocalB_1_00165770(u8 *a0, s32 a1, s32 a2);
void Script_FetchOperand_2_00165940(void *a0, void *a1, u32 *a2, u32 *a3);

/* Script_ResetSlot_1_00164F10 */
void Script_ResetSlot_1_00164F10(S_Script_ResetSlot_1_00164F10 *a) {
    u8 i;
    u32 n;
    if (a != 0 && a->x0 != 0) {
        n = a->x14;
        for (i = 0; i < n; i++) {}
    }
}

/* Script_GetResultF32_1_00164F60 */
f32 Script_GetResultF32_1_00164F60(Obj_Script_GetResultF32_1_00164F60 *o, u8 i, u8 j)
{
    E_Script_GetResultF32_1_00164F60 *row = o->e[i];
    return row[j].v;
}

/* Script_GetResultS8_1_00164F90 */
s8 Script_GetResultS8_1_00164F90(Obj_Script_GetResultS8_1_00164F90 *o, u8 i, u8 j)
{
    E_Script_GetResultS8_1_00164F90 *row = o->e[i];
    return row[j].v;
}

/* Script_GetResultU8_1_00164FC0 */
u8 Script_GetResultU8_1_00164FC0(Obj_Script_GetResultU8_1_00164FC0 *o, u8 i, u8 j)
{
    E_Script_GetResultU8_1_00164FC0 *row = o->e[i];
    return row[j].v;
}

/* Script_SetArgF32_1_00164FF0 */
void Script_SetArgF32_1_00164FF0(Obj_Script_SetArgF32_1_00164FF0 *o, u8 i, u8 j, f32 f) {
    E_Script_SetArgF32_1_00164FF0 *row = o->e[i];
    E_Script_SetArgF32_1_00164FF0 *p = &row[j];
    p->a = 6;
    p->b = f;
}

/* Script_SetArgS8_1_00165030 */
void Script_SetArgS8_1_00165030(u8 *a0, u8 a1, u8 a2, s8 a3) {
    E8 *p = (E8 *)(a0 + 0x36C + a1 * 0x258) + a2;
    p->a = 0;
    p->b = a3;
}

/* Script_SetArgU8_1_00165070 */
void Script_SetArgU8_1_00165070(u8 *p, u8 i, u8 j, u8 v) {
    E_Script_SetArgU8_1_00165070 *e = &((E_Script_SetArgU8_1_00165070 *)((u8 *)&((S_Script_SetArgU8_1_00165070 *)p)[i] + 0x36C))[j];
    e->a = 1;
    e->b = v;
}

/* Script_SetArgS16_1_001650B0 */
void Script_SetArgS16_1_001650B0(u8 *a0, u8 a1, u8 a2, s16 a3) {
    u8 *e = (u8 *)(a2 * 8 + (s32)(a0 + a1 * 0x258));
    *(s32 *)(e + 0x36C) = 2;
    *(s32 *)(e + 0x370) = a3;
}

/* Script_SetArgU16_1_001650F0 */
void Script_SetArgU16_1_001650F0(u8 *o, u8 i, u8 j, u16 v)
{
    u8 *p = (u8 *)(j * 8 + (s32)(o + i * 0x258));
    *(s32 *)(p + 0x36C) = 3;
    *(s32 *)(p + 0x370) = v;
}

/* Script_GetArgPtr_2_00165130 */
#define Script_ResolveOperand_1_00165150 Script_ResolveOperand_1_00165150__as_Script_GetArgPtr_2_00165130
int Script_ResolveOperand_1_00165150__as_Script_GetArgPtr_2_00165130();

void Script_GetArgPtr_2_00165130(s32 arg0, s32 arg1) {
    Script_ResolveOperand_1_00165150(gScriptEventSbss_00201FA4, gEnemyScriptSbss_00201FA8, arg0 + ((arg1 & 0xFF) * 8) + 4);
}
#undef Script_ResolveOperand_1_00165150

/* Script_ResolveOperand_1_00165150 */
static inline s8 *get(u8 i, s32 v) {
    s8 *r = NULL;
    if (i < 0x40) {
        if (i >= 0x20) r = (s8 *)(D_001F2300[i] + v); else if (i >= 0x10) r = (s8 *)(gScriptData_001F1C50[i] + v); else r = (s8 *)(D_0033F500[i] + v);
    }
    return r;
}

s8 *Script_ResolveOperand_1_00165150(s32 arg0, Hdr_Script_ResolveOperand_1_00165150 *arg1, Ent *arg2) {
    s32 t = arg2->type;
    s8 *ret = NULL;
    switch ((s64)t) {
    case 0x11:
        ret = get(t, arg2->val);
        break;
    case 0x12: {
        s32 v = arg2->val;
        u32 sz = ((s32)v + 7) & ~3;
        if ((u32)arg1->e < sz) arg1->e = sz;
        ret = (s8 *)(v + (arg1->c + (s32)arg1) + 0x158);
        break;
    }
    case 0x13:
        ret = (s8 *)(arg2->val + arg0 + 0x14);
        break;
    }
    return ret;
}

/* Script_StoreLocal_0_00165260 */
void Script_StoreLocal_0_00165260(s32 a0, Var *src, Hdr_Script_StoreLocal_0_00165260 *h, s32 a3, s32 v) {
    u16 t = (a3 & 0xFFFF00) >> 8;
    u32 sz = (v + 7) & ~3;
    Val *d;
    if ((u32)h->e < sz) h->e = sz;
    d = (Val *)(v + (h->c + (s32)h) + 0x158);
    switch (t) {
    case 0: d->c = src->v.c; break;
    case 1: d->uc = src->v.uc; break;
    case 2: d->s = src->v.s; break;
    case 3: d->us = src->v.us; break;
    case 4: d->i = src->v.i; break;
    case 5: d->u = src->v.u; break;
    case 6: d->f = src->v.f; break;
    }
}

/* Script_StoreGlobal_0_00165340 */
void Script_StoreGlobal_0_00165340(s32 a0, u8 *a1, s32 a2, s32 a3) {
    u8 *d = (u8 *)(a3 + a0) + 0x14;
    switch ((u16)((a2 & 0xFFFF00) >> 8)) {
    case 0: *(s8 *)d = *(s8 *)(a1 + 4); break;
    case 1: *(u8 *)d = *(u8 *)(a1 + 4); break;
    case 2: *(s16 *)d = *(s16 *)(a1 + 4); break;
    case 3: *(u16 *)d = *(u16 *)(a1 + 4); break;
    case 4: *(s32 *)d = *(s32 *)(a1 + 4); break;
    case 5: *(u32 *)d = *(u32 *)(a1 + 4); break;
    case 6: *(f32 *)d = *(f32 *)(a1 + 4); break;
    }
}

/* Script_LoadLocal_1_00165400 */
#define D_001F2300 D_001F2300__as_Script_LoadLocal_1_00165400
extern u8 *D_001F2300__as_Script_LoadLocal_1_00165400[];
#define gScriptData_001F1C50 gScriptData_001F1C50__as_Script_LoadLocal_1_00165400
extern u8 *gScriptData_001F1C50__as_Script_LoadLocal_1_00165400[];
#define D_0033F500 D_0033F500__as_Script_LoadLocal_1_00165400
extern u8 *D_0033F500__as_Script_LoadLocal_1_00165400[];
#define gScriptEventSbss_00201FA4 gScriptEventSbss_00201FA4__as_Script_LoadLocal_1_00165400
extern u8 *gScriptEventSbss_00201FA4__as_Script_LoadLocal_1_00165400;
#define Script_ResetSlot_1_00164F10 Script_ResetSlot_1_00164F10__as_Script_LoadLocal_1_00165400
void Script_ResetSlot_1_00164F10__as_Script_LoadLocal_1_00165400(void *);

void Script_LoadLocal_1_00165400(u8 *a0, s32 a1, s32 a2) {
    u16 k;
    u8 *p;
    u32 i;
    u8 *dst;
    u8 *q;
    s32 t;
    dst = 0;
    k = (a1 & 0xFFFF00) >> 8;
    t = a1 & 0xFF;
    if (t >= 0x40) {
        p = gScriptEventSbss_00201FA4;
        if (p != 0) {
            i = 0;
            if (i < *(u32 *)(p + 4)) {
                q = p;
                do {
                    if (*(u32 *)(q + 0x294) != 0) {
                        Script_ResetSlot_1_00164F10(q + 0x294);
                    }
                    q += 0x258;
                    i++;
                } while (i < *(u32 *)(p + 4));
            }
        }
    } else if (t >= 0x20) {
        dst = D_001F2300[t] + a2;
    } else if (t >= 0x10) {
        dst = gScriptData_001F1C50[t] + a2;
    } else {
        dst = D_0033F500[t] + a2;
    }
    switch (k) {
    case 0: *(s8 *)dst = *(s8 *)(a0 + 4); break;
    case 1: *(u8 *)dst = *(u8 *)(a0 + 4); break;
    case 2: *(s16 *)dst = *(s16 *)(a0 + 4); break;
    case 3: *(u16 *)dst = *(u16 *)(a0 + 4); break;
    case 4: *(s32 *)dst = *(s32 *)(a0 + 4); break;
    case 5: *(u32 *)dst = *(u32 *)(a0 + 4); break;
    case 6: *(f32 *)dst = *(f32 *)(a0 + 4); break;
    }
}
#undef Script_ResetSlot_1_00164F10
#undef D_001F2300
#undef gScriptData_001F1C50
#undef D_0033F500
#undef gScriptEventSbss_00201FA4

/* Script_LoadStack_0_001655C0 */
void Script_LoadStack_0_001655C0(void *a0, Out *out, Hdr_Script_LoadStack_0_001655C0 *h, s32 key, s32 off) {
    u16 type;
    u8 *p;
    u32 end;

    type = (key & 0xFFFF00) >> 8;
    end = (off + 7) & ~3;
    if (h->xE < end) {
        h->xE = end;
    }
    p = (u8 *)(off + (h->xC + (s32)h) + 0x158);
    switch (type) {
    case 0: out->v.i = *(s8 *)p; break;
    case 1: out->v.i = *(u8 *)p; break;
    case 2: out->v.i = *(s16 *)p; break;
    case 3: out->v.i = *(u16 *)p; break;
    case 4: out->v.i = *(s32 *)p; break;
    case 5: out->v.u = *(u32 *)p; break;
    case 6: out->v.f = *(f32 *)p; break;
    }
    out->type = type;
}

/* Script_LoadGlobal_0_001656B0 */
void Script_LoadGlobal_0_001656B0(u8 *a0, Out *out, s32 key, s32 off) {
    u16 type;
    u8 *p;
    p = (u8 *)(off + (s32)a0 + 0x14);
    type = (key & 0xFFFF00) >> 8;
    switch (type) {
    case 0: out->v.i = *(s8 *)p; break;
    case 1: out->v.i = *(u8 *)p; break;
    case 2: out->v.i = *(s16 *)p; break;
    case 3: out->v.i = *(u16 *)p; break;
    case 4: out->v.i = *(s32 *)p; break;
    case 5: out->v.u = *(u32 *)p; break;
    case 6: out->v.f = *(f32 *)p; break;
    }
    out->type = type;
}

/* Script_LoadLocalB_1_00165770 */
#define D_001F2300 D_001F2300__as_Script_LoadLocalB_1_00165770
extern u8 *D_001F2300__as_Script_LoadLocalB_1_00165770[];
#define gScriptData_001F1C50 gScriptData_001F1C50__as_Script_LoadLocalB_1_00165770
extern u8 *gScriptData_001F1C50__as_Script_LoadLocalB_1_00165770[];
#define D_0033F500 D_0033F500__as_Script_LoadLocalB_1_00165770
extern u8 *D_0033F500__as_Script_LoadLocalB_1_00165770[];
#define gScriptEventSbss_00201FA4 gScriptEventSbss_00201FA4__as_Script_LoadLocalB_1_00165770
extern u8 *gScriptEventSbss_00201FA4__as_Script_LoadLocalB_1_00165770;
#define Script_ResetSlot_1_00164F10 Script_ResetSlot_1_00164F10__as_Script_LoadLocalB_1_00165770
void Script_ResetSlot_1_00164F10__as_Script_LoadLocalB_1_00165770(void *);

void Script_LoadLocalB_1_00165770(u8 *a0, s32 a1, s32 a2) {
    u16 k;
    u8 *p;
    u32 i;
    u8 *src;
    u8 *q;
    s32 t;
    src = 0;
    k = (a1 & 0xFFFF00) >> 8;
    t = a1 & 0xFF;
    if (t >= 0x40) {
        p = gScriptEventSbss_00201FA4;
        if (p != 0) {
            i = 0;
            if (i < *(u32 *)(p + 4)) {
                q = p;
                do {
                    if (*(u32 *)(q + 0x294) != 0) {
                        Script_ResetSlot_1_00164F10(q + 0x294);
                    }
                    q += 0x258;
                    i++;
                } while (i < *(u32 *)(p + 4));
            }
        }
    } else if (t >= 0x20) {
        src = D_001F2300[t] + a2;
    } else if (t >= 0x10) {
        src = gScriptData_001F1C50[t] + a2;
    } else {
        src = D_0033F500[t] + a2;
    }
    switch (k) {
    case 0: *(s32 *)(a0 + 4) = *(s8 *)src; break;
    case 1: *(s32 *)(a0 + 4) = *(u8 *)src; break;
    case 2: *(s32 *)(a0 + 4) = *(s16 *)src; break;
    case 3: *(s32 *)(a0 + 4) = *(u16 *)src; break;
    case 4: *(s32 *)(a0 + 4) = *(s32 *)src; break;
    case 5: *(u32 *)(a0 + 4) = *(u32 *)src; break;
    case 6: *(f32 *)(a0 + 4) = *(f32 *)src; break;
    }
    *(u32 *)a0 = k;
}
#undef Script_ResetSlot_1_00164F10
#undef D_001F2300
#undef gScriptData_001F1C50
#undef D_0033F500
#undef gScriptEventSbss_00201FA4

/* Script_FetchOperand_2_00165940 */
#define Script_LoadLocalB_1_00165770 Script_LoadLocalB_1_00165770__as_Script_FetchOperand_2_00165940
void Script_LoadLocalB_1_00165770__as_Script_FetchOperand_2_00165940(u32 *, s32, s32);
#define Script_LoadStack_0_001655C0 Script_LoadStack_0_001655C0__as_Script_FetchOperand_2_00165940
void Script_LoadStack_0_001655C0__as_Script_FetchOperand_2_00165940(void *, u32 *, void *, s32, s32);
#define Script_LoadGlobal_0_001656B0 Script_LoadGlobal_0_001656B0__as_Script_FetchOperand_2_00165940
void Script_LoadGlobal_0_001656B0__as_Script_FetchOperand_2_00165940(void *, u32 *, s32, s32);

void Script_FetchOperand_2_00165940(void *a0, void *a1, u32 *a2, u32 *a3) {
    u32 w;
    u32 hi;
    u32 w1;
    u32 mid;
    w = a2[0];
    w1 = a2[1];
    hi = (w & 0xFFFF0000) >> 16;
    mid = (w & 0xFFFFFF00) >> 8;
    switch (w & 0xFF) {
    case 1:
        Script_LoadLocalB_1_00165770(a3, mid, w1);
        break;
    case 2:
        Script_LoadStack_0_001655C0(a0, a3, a1, mid, w1);
        break;
    case 3:
        Script_LoadGlobal_0_001656B0(a0, a3, mid, w1);
        break;
    case 0:
        a3[0] = hi;
        a3[1] = w1;
        break;
    case 0x11:
    case 0x12:
    case 0x13:
        a3[0] = w;
        a3[1] = w1;
        break;
    }
}
#undef Script_LoadLocalB_1_00165770
#undef Script_LoadStack_0_001655C0
#undef Script_LoadGlobal_0_001656B0

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/game_main_data.c): D_001F1C50__grp: gScriptData_001F1C50@0x0 */
u16 D_001F1C50__grp[0x8] __attribute__((aligned(16))) = { 0x1f4, 0x1f5, 0x1f6, 0x1f4, 0x1f5, 0x1f6, 0, 0 };
#endif
