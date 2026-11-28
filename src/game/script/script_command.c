#include "common.h"
#include "m2c.h"
#include "game/script.h"
typedef ScrVal Val;
typedef struct { s32 type; Val v; } Var;
typedef struct { s32 type; union { s32 i; f32 f; } v; } V;
typedef struct { char pad[0xD8]; V e[1]; } B;
typedef struct { char p0[8]; u8 idx; char p9[7]; s32 type; char p14[4]; union { s8 c; u8 uc; s16 h; u16 uh; s32 i; u32 u; f32 f; } v; } A;
typedef struct { s32 v; char rest[0x254]; } E;
typedef struct { char p0[4]; s32 n; char p8[0x28C]; E e[1]; } S;
extern s8 *gEnemyScriptSbss_00201FA8;
extern S *gScriptEventSbss_00201FA4;
void ScrCmd_GetArg0_2_00164CC0(s32 arg0);
void ScrCmd_GetVar_1_00164CE0(s8 *a0);
void ScrCmd_SetVar_1_00164DC0(A *a);
void ScrCmd_SendEvent_1_00164EE0(void *arg0);
Val* Script_GetArgPtr_2_00165130(s8 *, u8);

/* ScrCmd_GetArg0_2_00164CC0 */
#define Script_GetArgPtr_2_00165130 Script_GetArgPtr_2_00165130__as_ScrCmd_GetArg0_2_00164CC0
int Script_GetArgPtr_2_00165130__as_ScrCmd_GetArg0_2_00164CC0();
void ScrCmd_GetArg0_2_00164CC0(s32 arg0) {
    Script_GetArgPtr_2_00165130(arg0, 0);
}
#undef Script_GetArgPtr_2_00165130

/* ScrCmd_Nop_2_00164CD0 */
void ScrCmd_Nop_2_00164CD0(void) {

}

/* ScrCmd_GetVar_1_00164CE0 */
void ScrCmd_GetVar_1_00164CE0(s8 *a0) {
    Var *e = (Var *)(gEnemyScriptSbss_00201FA8 + *(s32 *)(a0 + 8) * 8 + 0xD8);
    s32 t = e->type;
    Val *d = Script_GetArgPtr_2_00165130(a0, 2);
    switch (t) {
    case 0: d->c = e->v.c; break;
    case 1: d->uc = e->v.uc; break;
    case 2: d->s = e->v.s; break;
    case 3: d->us = e->v.us; break;
    case 4: d->i = e->v.i; break;
    case 5: d->u = e->v.u; break;
    case 6: d->f = e->v.f; break;
    }
}

/* ScrCmd_SetVar_1_00164DC0 */
#define gEnemyScriptSbss_00201FA8 gEnemyScriptSbss_00201FA8__as_ScrCmd_SetVar_1_00164DC0
extern B *gEnemyScriptSbss_00201FA8__as_ScrCmd_SetVar_1_00164DC0;
void ScrCmd_SetVar_1_00164DC0(A *a) {
    V *e = &gEnemyScriptSbss_00201FA8->e[a->idx];
    e->type = a->type;
    switch (e->type) {
    case 0: e->v.i = a->v.c; break;
    case 1: e->v.i = a->v.uc; break;
    case 2: e->v.i = a->v.h; break;
    case 3: e->v.i = a->v.uh; break;
    case 4: e->v.i = a->v.i; break;
    case 5: e->v.i = a->v.u; break;
    case 6: e->v.f = a->v.f; break;
    }
}
#undef gEnemyScriptSbss_00201FA8

/* ScrCmd_ResetAllSlots_0_00164E80 */
void ScrCmd_ResetAllSlots_0_00164E80(void)
{
    s32 i;
    for (i = 0; i < gScriptEventSbss_00201FA4->n; i++)
        gScriptEventSbss_00201FA4->e[i].v = 0;
}

/* ScrCmd_NopB_2_00164EC0 */
void ScrCmd_NopB_2_00164EC0(void) {

}

/* ScrCmd_NopC_2_00164ED0 */
void ScrCmd_NopC_2_00164ED0(void) {

}

/* ScrCmd_SendEvent_1_00164EE0 */
#define gScriptEventSbss_00201FA4 gScriptEventSbss_00201FA4__as_ScrCmd_SendEvent_1_00164EE0
extern void *gScriptEventSbss_00201FA4__as_ScrCmd_SendEvent_1_00164EE0;

void ScrCmd_SendEvent_1_00164EE0(void *arg0) {
    Script_SendEventImpl_1_00166DA0(gScriptEventSbss_00201FA4, M2C_FIELD(arg0, s32 *, 8), 0);
}
#undef gScriptEventSbss_00201FA4

/* ScrCmd_NopD_2_00164EF0 */
void ScrCmd_NopD_2_00164EF0(void) {

}

/* ScrCmd_NopE_2_00164F00 */
void ScrCmd_NopE_2_00164F00(void) {

}
