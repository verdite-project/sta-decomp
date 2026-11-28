#include "m2c.h"
#include "game/script.h"
typedef struct { s32 type; union { s32 i; f32 f; } v; } Val;
typedef struct { u8 pad[8]; u32 *pc; } Ctx;
typedef struct { s32 op; Val args[16]; u8 m[16]; u8 pad[0x1C]; } Cmd;
typedef struct { s32 a; s32 b; u16 c; u16 d; } Ent;
typedef struct {
    s32 f0; s32 f4; s32 f8; u16 fC; u16 fE; s32 f10; s32 f14;
    Ent ent[16];
} Slot;
typedef struct { s32 h0; u32 count; s32 *base; } Mgr;
typedef void (*Fn)(Cmd *);
extern Fn D_001F2400[];
extern Fn D_001F1CD0[];
#ifndef NONMATCHING
extern Fn D_0033F540[];
#else
/* data twins (src/game/data/vibration_bss_0033F540.c): D_0033F540 */
static Fn D_0033F540[0x190 / sizeof(Fn)];
#endif
extern Fn D_001F21B0[];
void Script_OpCompare_1_00165DF0(void *o, Ctx *s);
s8 Script_Exec_2_00166170(Mgr *o, Slot *s);
void Script_FetchOperand_2_00165940(void *, Ctx *, u32 *, Val *);
void Script_OpArith_1_00165A30(Mgr *, Slot *);
void memset(void *, s32, s32);

/* Script_OpCompare_1_00165DF0 */
void Script_OpCompare_1_00165DF0(void *o, Ctx *s) {
    u8 res[32];
    Val a;
    Val b;
    u16 i;
    u32 w;
    s32 skip;
    s32 n;
    u8 mode;
    u8 op;
    u8 r;
    f32 fa;
    f32 fb;

    w = *s->pc;
    s->pc++;
    mode = w & 0xFF;
    skip = *s->pc;
    s->pc++;
    n = (u8)((w & 0xFF00) >> 8);
    for (i = 0; i < n; i++) {
        Script_FetchOperand_2_00165940(o, s, s->pc, &a);
        s->pc += 2;
        op = *(u8 *)s->pc;
        s->pc++;
        Script_FetchOperand_2_00165940(o, s, s->pc, &b);
        s->pc += 2;
        if (a.type == 6 || b.type == 6) {
            fa = a.v.f;
            fb = b.v.f;
            switch (op) {
            case 0: res[i] = fa == fb; break;
            case 1: res[i] = fa != fb; break;
            case 2: res[i] = fa > fb; break;
            case 3: res[i] = fa < fb; break;
            case 4: res[i] = fa >= fb; break;
            case 5: res[i] = fa <= fb; break;
            }
        } else {
            switch (op) {
            case 0: res[i] = a.v.i == b.v.i; break;
            case 1: res[i] = a.v.i != b.v.i; break;
            case 2: res[i] = a.v.i > b.v.i; break;
            case 3: res[i] = a.v.i < b.v.i; break;
            case 4: res[i] = a.v.i >= b.v.i; break;
            case 5: res[i] = a.v.i <= b.v.i; break;
            }
        }
    }
    if (n == 1) {
        r = res[0];
    } else {
        r = res[0];
        if (mode == 0) {
        for (i = 1; i < n; i++) {
            r = r || res[i];
        }
    } else {
        for (i = 1; i < n; i++) {
            r = r && res[i];
        }
    }
    }
    if (!r) {
        s->pc += skip;
    }
}

/* Script_Exec_2_00166170 */
#define Script_FetchOperand_2_00165940 Script_FetchOperand_2_00165940__as_Script_Exec_2_00166170
void Script_FetchOperand_2_00165940__as_Script_Exec_2_00166170(void *, Slot *, s32, Val *);
#define Script_OpCompare_1_00165DF0 Script_OpCompare_1_00165DF0__as_Script_Exec_2_00166170
void Script_OpCompare_1_00165DF0__as_Script_Exec_2_00166170(Mgr *, Slot *);
static inline s8 pop(Mgr *o, Slot *s) {
    if (s->f14 == 0) return -1;
    s->f14--;
    s->f8 = *o->base + s->ent[s->f14].b;
    s->f4 = s->ent[s->f14].a;
    s->fC = s->ent[s->f14].c;
    s->fE = s->ent[s->f14].d;
    return s->f14;
}
static inline void push(Mgr *o, Slot *s) {
    if (s->f14 != 16) {
        s->ent[s->f14].b = s->f8 - *o->base;
        s->ent[s->f14].a = s->f4;
        s->ent[s->f14].c = s->fC;
        s->ent[s->f14].d = s->fE;
        s->f14++;
        s->f8 = 0;
    }
}
static inline void jmp(Slot *s, u16 n) {
    s->f8 += 4;
    s->f8 += (s16)n * 4;
}
static inline void getArgs(Mgr *o, Slot *s, Cmd *c, u16 op, u16 n) {
    u16 i;
    c->op = op;
    s->f8 += 4;
    for (i = 0; i < n; i++) {
        Script_FetchOperand_2_00165940(o, s, s->f8, &c->args[i]);
        s->f8 += 8;
    }
    memset(c->m, 0, 0x10);
}

s8 Script_Exec_2_00166170(Mgr *o, Slot *s) {
    s8 ret;
    u16 run;
    u32 w;
    u32 op;
    u32 arg;
    s32 p;
    s32 i;

    run = 1;
    ret = 0;
    if (pop(o, s) == -1) {
        ret = 0;
        run = 0;
    }
    while (run) {
        p = s->f8;
        w = *(u32 *)p;
        op = (w & 0xFFFF0000) >> 16;
        arg = w & 0xFFFF;
        switch (op) {
        case 0x190:
            s->f8 += 4;
            break;
        case 0x191:
            if (pop(o, s) == -1) {
                ret = 0;
                run = 0;
            }
            break;
        case 0x194:
            s->f8 += 4;
            break;
        case 0x195:
            s->f8 += 4;
            ret = 1;
            s->f10 = 0;
            run = 0;
            push(o, s);
            break;
        case 0x192:
            Script_OpCompare_1_00165DF0(o, s);
            break;
        case 0x197:
            jmp(s, arg);
            break;
        case 0x196:
            Script_OpArith_1_00165A30(o, s);
            break;
        case 0x19D:
            p += 8;
            for (i = 0; i < (s32)arg; i++) {
                p += 4;
            }
            s->f8 = p;
            break;
        case 1: {
            Cmd c;
            getArgs(o, s, &c, op, arg);
            s->f10 = c.args[0].v.i;
            ret = 1;
            run = 0;
            push(o, s);
            break;
        }
        case 2: {
            Cmd c;
            getArgs(o, s, &c, op, arg);
            push(o, s);
            s->f4 = Script_FindLabel_1_00166970(o, *(u16 *)&c.args[0].v);
            if (s->f4 == -1) return 0;
            s->f8 = *o->base + s->f4;
            s->fC += s->fE;
            s->fE = 0;
            break;
        }
        case 7:
            ret = 0;
            run = 0;
            break;
        default: {
            Cmd c;
            getArgs(o, s, &c, op, arg);
            if (c.op != 0 && !(c.op & 0x8000)) {
                if (c.op >= 300) {
                    D_001F2400[c.op - 300](&c);
                } else if (c.op >= 200) {
                    D_001F1CD0[c.op - 200](&c);
                } else if (c.op >= 100) {
                    D_0033F540[c.op - 100](&c);
                } else {
                    D_001F21B0[c.op](&c);
                }
            }
            break;
        }
        }
    }
    return ret;
}
#undef Script_FetchOperand_2_00165940
#undef Script_OpCompare_1_00165DF0
