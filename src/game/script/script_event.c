#include "common.h"
#include "m2c.h"
#include "game/script.h"
typedef struct { s32 f0; u8 pad4[0xC]; s32 f10; u8 pad14[0x258 - 0x14]; } Slot_Script_RunEvent_2_00166C10;
typedef struct { s32 h0; u32 count; u8 pad8[0x294 - 8]; Slot_Script_RunEvent_2_00166C10 s[1]; } Mgr_Script_RunEvent_2_00166C10;
typedef struct { s32 f0; u8 pad4[0xC]; s32 f10; u8 pad14[0x258 - 0x14]; } Slot_Script_RunAll_1_00166CC0;
typedef struct { s32 h0; u32 count; u8 pad8[0x294 - 8]; Slot_Script_RunAll_1_00166CC0 s[1]; } Mgr_Script_RunAll_1_00166CC0;
typedef struct {
    s32 a;
    s32 b;
    u16 c;
    u16 d;
} Ent;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u16 fC;
    u16 fE;
    s32 f10;
    s32 f14;
    Ent ent[16];
    s8 pad[0x154 - 0x18 - 16 * 0xC];
    s32 f154;
    s8 pad2[0x258 - 0x158];
} Slot_Script_SendEventImpl_1_00166DA0;
typedef struct {
    s32 h0;
    u32 count;
    s32 *base;
    s8 pad[0x294 - 0xC];
    Slot_Script_SendEventImpl_1_00166DA0 slots[1];
} Mgr_Script_SendEventImpl_1_00166DA0;
typedef struct { u8 b[0x258]; } R;
typedef struct { s32 id; u32 n; s32 a; s32 b; s32 x10; u8 m[0x200]; u8 k[0x80]; R r[1]; } H;
extern Mgr_Script_RunEvent_2_00166C10 *gScriptEventSbss_00201FA4;
extern Slot_Script_RunEvent_2_00166C10 *gEnemyScriptSbss_00201FA8;
s32 Script_RunEvent_2_00166C10(Mgr_Script_RunEvent_2_00166C10 *o, s32 i);
s32 Script_RunAll_1_00166CC0(Mgr_Script_RunAll_1_00166CC0 *o);
u32 Script_SendEventImpl_1_00166DA0(Mgr_Script_SendEventImpl_1_00166DA0 *arg0, s32 arg1, s32 arg2);
void Script_SendEvent_2_00166F80(s32 arg0, s32 arg1, s32 arg2);
void Script_InitContext_1_00166F90(H **arg0, s32 arg1, s32 arg2, u32 arg3);
s8 Script_Exec_2_00166170(void *, void *);
void Script_ResetSlot_1_00164F10(Slot_Script_SendEventImpl_1_00166DA0 *);
void memset(void *, s32, s32);

/* Script_RunEvent_2_00166C10 */
#define Script_Exec_2_00166170 Script_Exec_2_00166170__as_Script_RunEvent_2_00166C10
s8 Script_Exec_2_00166170__as_Script_RunEvent_2_00166C10(Mgr_Script_RunEvent_2_00166C10 *, Slot_Script_RunEvent_2_00166C10 *);
s32 Script_RunEvent_2_00166C10(Mgr_Script_RunEvent_2_00166C10 *o, s32 i) {
    Mgr_Script_RunEvent_2_00166C10 *save;
    Slot_Script_RunEvent_2_00166C10 *save2;
    Slot_Script_RunEvent_2_00166C10 *s;
    s32 r;
    save = gScriptEventSbss_00201FA4;
    save2 = gEnemyScriptSbss_00201FA8;
    gScriptEventSbss_00201FA4 = o;
    r = 0;
    if (o->s[i].f0) {
        s = &o->s[i];
        gEnemyScriptSbss_00201FA8 = s;
        if (s->f10 == 0) {
            r = Script_Exec_2_00166170(o, s);
            if (r == 0) s->f0 = 0;
        } else {
            s->f10--;
        }
        gEnemyScriptSbss_00201FA8 = save2;
    }
    gScriptEventSbss_00201FA4 = save;
    return r;
}
#undef Script_Exec_2_00166170

/* Script_RunAll_1_00166CC0 */
#define Script_Exec_2_00166170 Script_Exec_2_00166170__as_Script_RunAll_1_00166CC0
s8 Script_Exec_2_00166170__as_Script_RunAll_1_00166CC0(Mgr_Script_RunAll_1_00166CC0 *, Slot_Script_RunAll_1_00166CC0 *);
#define gScriptEventSbss_00201FA4 gScriptEventSbss_00201FA4__as_Script_RunAll_1_00166CC0
extern Mgr_Script_RunAll_1_00166CC0 *gScriptEventSbss_00201FA4__as_Script_RunAll_1_00166CC0;
#define gEnemyScriptSbss_00201FA8 gEnemyScriptSbss_00201FA8__as_Script_RunAll_1_00166CC0
extern Slot_Script_RunAll_1_00166CC0 *gEnemyScriptSbss_00201FA8__as_Script_RunAll_1_00166CC0;

s32 Script_RunAll_1_00166CC0(Mgr_Script_RunAll_1_00166CC0 *o) {
    u32 i;
    Mgr_Script_RunAll_1_00166CC0 *save;
    Slot_Script_RunAll_1_00166CC0 *save2;
    Slot_Script_RunAll_1_00166CC0 *s;
    save = gScriptEventSbss_00201FA4;
    gScriptEventSbss_00201FA4 = o;
    for (i = 0; i < o->count; i++) {
        if (o->s[i].f0) {
            save2 = gEnemyScriptSbss_00201FA8;
            s = &o->s[i];
            gEnemyScriptSbss_00201FA8 = s;
            if (s->f10 == 0) {
                if (Script_Exec_2_00166170(o, s) == 0) s->f0 = 0;
            } else {
                s->f10--;
            }
            gEnemyScriptSbss_00201FA8 = save2;
        }
    }
    gScriptEventSbss_00201FA4 = save;
    return 0;
}
#undef Script_Exec_2_00166170
#undef gScriptEventSbss_00201FA4
#undef gEnemyScriptSbss_00201FA8

/* Script_SendEventImpl_1_00166DA0 */
u32 Script_SendEventImpl_1_00166DA0(Mgr_Script_SendEventImpl_1_00166DA0 *arg0, s32 arg1, s32 arg2) {
    u32 i;
    u32 n;
    Slot_Script_SendEventImpl_1_00166DA0 *s;
    u32 j;

    i = 0;
    n = arg0->count;
    s = NULL;
    for (i = 0; i < n; i++) {
        if (arg0->slots[i].f0 == 0) {
            s = &arg0->slots[i];
            break;
        }
    }
    if (s == NULL && arg0 != NULL) {
        for (j = 0; j < arg0->count; j++) {
            if (arg0->slots[j].f0 != 0) {
                Script_ResetSlot_1_00164F10(&arg0->slots[j]);
            }
        }
    }
    s->f0 = arg1;
    s->f154 = arg2;
    s->f4 = Script_FindLabel_1_00166970(arg0, arg1 & 0xFFFF);
    s->f8 = *arg0->base + s->f4;
    s->fC = 0;
    s->fE = 0;
    s->f10 = 0;
    s->f14 = 0;
    if (s->f14 != 16) {
        s->ent[s->f14].b = s->f8 - *arg0->base;
        s->ent[s->f14].a = s->f4;
        s->ent[s->f14].c = s->fC;
        s->ent[s->f14].d = s->fE;
        s->f14++;
        s->f8 = 0;
    }
    return i;
}

/* Script_SendEvent_2_00166F80 */
#define Script_SendEventImpl_1_00166DA0 Script_SendEventImpl_1_00166DA0__as_Script_SendEvent_2_00166F80
int Script_SendEventImpl_1_00166DA0__as_Script_SendEvent_2_00166F80();
void Script_SendEvent_2_00166F80(s32 arg0, s32 arg1, s32 arg2) {
    Script_SendEventImpl_1_00166DA0((void *) arg0, arg1, arg2);
}
#undef Script_SendEventImpl_1_00166DA0

/* Script_InitContext_1_00166F90 */
void Script_InitContext_1_00166F90(H **arg0, s32 arg1, s32 arg2, u32 arg3) {
    u32 i;
    H *p = *arg0;
    p->id = -1;
    p->n = arg3;
    p->a = arg1;
    p->b = arg2;
    memset(p->m, 0, 0x200);
    memset(p->k, 0, 0x80);
    for (i = 0; i < arg3; i++) {
        memset(&p->r[i], 0, 0x258);
    }
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gScriptEventSbss_00201FA4 */
Mgr_Script_RunEvent_2_00166C10 *gScriptEventSbss_00201FA4;
#endif
