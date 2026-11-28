#include "common.h"
#include "game/core.h"
#include "game/data.h"
typedef struct { u8 *base; s32 stride; u32 n; s32 st; void (**fn)(s32); u32 cnt; u32 cur; u8 fl; Flags8 f; } L;
typedef struct { f32 x, y, z, w; } V4;
typedef struct { u16 a:1; u16 b:8; u16 c:1; u16 r:6; } BF;
typedef struct { u8 a; u8 b; u8 pad2[6]; s32 x8; u16 xC; u8 padE[10]; s32 x18; } Ent;
typedef s32 (*Fn)(Ent *);
typedef struct { u8 x0; u8 x1; u8 p2[6]; s32 x8; u8 pC[2]; u16 xE; s32 x10; s32 x14; } T;
extern L gTaskCallbackBss_004BAC30;
extern s32 gTaskCallbackBss_004BAC40[];
extern s32 gTaskCallbackBss_004BAC44[];
extern V4 gTaskCallbackBss_004BAC20[];
extern s32 gTaskCallbackBss_004BAC34[];
extern s32 gTaskCallbackBss_004BAC38[];
extern BF gTaskCallbackBss_004BAC4C[];
extern Fn gTaskCallbackBss_004BAC28[];
extern Fn gTaskCallbackBss_004BAC2C[];
extern s32 (*gTaskCallbackBss_004BAC24[])(T *, s32);
extern u8 *gTaskCallbackBss_004BAC30__as_Task_Schedule_1_001E0680[];
extern u32 gTaskCallbackBss_004BAC38__as_Task_Schedule_1_001E0680[];
extern s32 (*gTaskCallbackBss_004BAC28__as_Task_Dispatch_0_001E0AB0[])(T *);
void Task_SetCallback_1_001E0560(s32 arg0, s32 arg1);
void Task_Start_1_001E0590(s32 a0, s32 a1, s32 a2, V4 *v);
void Task_Schedule_1_001E0680(void);
s32 Task_Dispatch_0_001E0AB0(T *p);
void Task_RunAll_1_001DFCB0(s32);
void Task_Dispatch_0_001E0AB0__as_Task_Schedule_1_001E0680(Ent *);

/* Task_Init_1_001E03C0 */
/* round 2 near-miss: 8 words: li constants scheduled between the two lw of the loop-2 preheader */
static inline u8 *get_Task_Init_1_001E03C0(u32 i) { L *l = &gTaskCallbackBss_004BAC30; return l->base + l->stride * i; }

void Task_Init_1_001E03C0(void) {
    u32 i;
    s32 j;
    u32 n;
    if (!gTaskCallbackBss_004BAC30.f.f.b1) {
        for (i = 0; i < gTaskCallbackBss_004BAC30.cnt; i++) {
            gTaskCallbackBss_004BAC30.cur = i;
            gTaskCallbackBss_004BAC30.fn[i](0);
        }
        gTaskCallbackBss_004BAC30.cur = -1;
    } else if (gTaskCallbackBss_004BAC30.cur != -1) {
        gTaskCallbackBss_004BAC30.fn[gTaskCallbackBss_004BAC30.cur](0);
    }
    gTaskCallbackBss_004BAC30.st = 0; n = gTaskCallbackBss_004BAC30.n;
    for (j = 0; j < n; j++) {
        u8 c = *get_Task_Init_1_001E03C0(j);
        if (c == 1) { gTaskCallbackBss_004BAC30.st = 1; break; }
        if (c == 3) gTaskCallbackBss_004BAC30.st = 3;
        if (c == 6) gTaskCallbackBss_004BAC30.st = 6;
        if (c == 2 && gTaskCallbackBss_004BAC30.st != 3 && gTaskCallbackBss_004BAC30.st != 6) gTaskCallbackBss_004BAC30.st = 2;
    }
    if (!(gTaskCallbackBss_004BAC30.fl & 1)) Task_Schedule_1_001E0680();
}

/* Task_SetCallback_1_001E0560 */
#define gTaskCallbackBss_004BAC30 gTaskCallbackBss_004BAC30__as_Task_SetCallback_1_001E0560
extern s32 gTaskCallbackBss_004BAC30__as_Task_SetCallback_1_001E0560[];

/* Task_SetCallback_1_001E0560 */
void Task_SetCallback_1_001E0560(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*gTaskCallbackBss_004BAC40) = arg0;
        (*gTaskCallbackBss_004BAC44) = arg1;
        (*gTaskCallbackBss_004BAC48) = -1;
    }
}

/* Task_Start_1_001E0590 */
void Task_Start_1_001E0590(s32 a0, s32 a1, s32 a2, V4 *v) {
    if (gTaskCallbackSbss_002023A8 == 0 && a0 != 0 && v != NULL) {
        gTaskCallbackBss_004BAC20[0] = *v;
        gTaskCallbackBss_004BAC38[0] = a2;
        gTaskCallbackBss_004BAC34[0] = a1;
        gTaskCallbackBss_004BAC30[0] = a0;
        gTaskCallbackBss_004BAC4C[0].a = 0;
        gTaskCallbackBss_004BAC4C[0].b = 0;
        gTaskCallbackBss_004BAC4C[0].c = 0;
        Task_RunAll_1_001DFCB0(0);
        gTaskCallbackSbss_002023A8 = 1;
    }
}

/* Task_Schedule_1_001E0680 */

static inline s32 cb(Ent *e) {
    Fn f = gTaskCallbackBss_004BAC2C[0];
    return f ? f(e) : 0;
}

static inline void get3(Ent **pe, u32 i) {
    *pe = (Ent *)(gTaskCallbackBss_004BAC30__as_Task_Schedule_1_001E0680[0] + gTaskCallbackBss_004BAC34[0] * i);
}

static inline Ent *get_Task_SetCallback_1_001E0560(u32 i) {
    return (Ent *)(gTaskCallbackBss_004BAC30__as_Task_Schedule_1_001E0680[0] + gTaskCallbackBss_004BAC34[0] * i);
}

void Task_Schedule_1_001E0680(void) {
    u32 i;
    Ent *p;
    u32 k;
    Ent *q;
    Ent *e;
    s32 j;
    s32 foundv;
    s32 minv;
    u32 found;
    u32 mi;

    minv = foundv = 0x10000;
    mi = found = -1;
    {
        for (j = 0; j < gTaskCallbackBss_004BAC38__as_Task_Schedule_1_001E0680[0]; j++) {
            get3(&e, j);
            if (e->a == 1 || e->a == 4) {
                if (found != -1) return;
                foundv = e->xC;
                found = j;
            } else if (e->b == 2 && e->xC < minv) {
                minv = e->xC;
                mi = j;
            }
        }
    }
    if (mi != -1 && minv < foundv) {
        if (found == -1) {
            e = get_Task_SetCallback_1_001E0560(mi);
            e->a = 1;
            Task_Dispatch_0_001E0AB0__as_Task_Schedule_1_001E0680(e);
        } else {
            e = get_Task_SetCallback_1_001E0560(found);
            if (e->b == 2) e->b = 3;
        }
    } else if (found != -1) {
        e = get_Task_SetCallback_1_001E0560(found);
        if (cb(e) == 0 && e->b == 2) Task_Dispatch_0_001E0AB0__as_Task_Schedule_1_001E0680(e);
    }
    for (i = 0; i < gTaskCallbackBss_004BAC38__as_Task_Schedule_1_001E0680[0]; i++) {
        q = get_Task_SetCallback_1_001E0560(i);
        if (q->b == 1) {
            if (q->a == 1 || q->a == 4) {
                if (cb(q) == 0) {
                    q->a = 0;
                    q->b = 0;
                    q->x18 = -1;
                    if (gTaskCallbackBss_004BAC28[0]) gTaskCallbackBss_004BAC28[0](q);
                }
            } else {
                q->a = 0;
                q->b = 0;
                q->x18 = -1;
                if (gTaskCallbackBss_004BAC28[0]) gTaskCallbackBss_004BAC28[0](q);
            }
        }
    }
    for (k = 0; k < gTaskCallbackBss_004BAC38__as_Task_Schedule_1_001E0680[0]; k++) {
        p = get_Task_SetCallback_1_001E0560(k);
        if (p->b == 3) {
            if (p->a == 1) {
                if (cb(p) == 0) {
                    p->a = 2;
                    p->b = 0;
                }
            } else if (p->a == 4) {
                if (cb(p) == 0) p->a = 5;
            } else {
                p->b = 0;
            }
        }
    }
    for (k = 0; k < gTaskCallbackBss_004BAC38__as_Task_Schedule_1_001E0680[0]; k++) {
        p = get_Task_SetCallback_1_001E0560(k);
        if (p->b == 4) {
            if (p->a == 6) {
                if (gTaskCallbackBss_004BAC28[0]) gTaskCallbackBss_004BAC28[0](p);
                p->a = 3;
                p->b = 0;
                p->x8 = 0;
            } else {
                p->b = 0;
            }
        }
    }
}

/* Task_Dispatch_0_001E0AB0 */

s32 Task_Dispatch_0_001E0AB0(T *p) {
    if (p == NULL) return -1;
    if (p->x14 == 0) return -1;
    if (p->x0 != 1) return -1;
    if (p->x1 != 2) return -1;
    if (gTaskCallbackBss_004BAC24[0] != NULL) {
        if (gTaskCallbackBss_004BAC24[0](p, 0x20000) != 0) {
            if (p->xE != 0) {
                p->x14 += 0x20000;
                p->x8 -= 0x20000;
            } else {
                p->x14 = p->x10;
                p->x8 -= 0x20000;
                p->x0 = 4;
                p->x1 = 3;
            }
            return 0;
        }
        if (gTaskCallbackBss_004BAC28__as_Task_Dispatch_0_001E0AB0[0] != NULL) {
            if (gTaskCallbackBss_004BAC28__as_Task_Dispatch_0_001E0AB0[0](p) != 0) {
                p->x0 = 3;
            } else {
                p->x0 = 6;
            }
        } else {
            p->x0 = 6;
        }
        p->x1 = 0;
        p->x8 = 0;
        return 1;
    }
    return -1;
}
#undef gTaskCallbackBss_004BAC30

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gTaskCallbackSbss_002023A8 */
s32 gTaskCallbackSbss_002023A8;
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_system_start_bss.c): D_004BAC20__grp: gTaskCallbackBss_004BAC20@0x0, gTaskCallbackBss_004BAC24@0x4, gTaskCallbackBss_004BAC28@0x8, gTaskCallbackBss_004BAC2C@0xc */
u8 D_004BAC20__grp[0x10] __attribute__((aligned(16)));
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_system_start_bss.c): D_004BAC30__grp: gTaskCallbackBss_004BAC30@0x0, gTaskCallbackBss_004BAC34@0x4, gTaskCallbackBss_004BAC38@0x8, gTaskCallbackBss_004BAC3C@0xc, gTaskCallbackBss_004BAC40@0x10, gTaskCallbackBss_004BAC44@0x14, gTaskCallbackBss_004BAC48@0x18, gTaskCallbackBss_004BAC4C@0x1c, gGlowFxSlots_004BAC50@0x20, gTaskCallbackBss_004BAC54@0x24, gTaskCallbackBss_004BAC80@0x50, gTaskCallbackBss_004BB010@0x3e0 */
unsigned char D_004BAC30__grp[0x420] __attribute__((aligned(16)));
#endif
