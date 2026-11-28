#include "common.h"
#include "game/core.h"
#include "game/data.h"
typedef struct { u8 *base; s32 stride; u32 n; } L;
extern void (*volatile gTaskCallbackBss_004BAC28[])(u8 *);
extern u8 *volatile gTaskCallbackBss_004BAC30[];
extern volatile s32 gTaskCallbackBss_004BAC34[];
extern volatile u32 gTaskCallbackBss_004BAC38[];
extern u8 gTaskCallbackBss_004BAC4C[];
extern Flags8 D_004BAC4D[];
s32 Task_RunAll_1_001DFCB0(u8 *a);
s32 Task_Run_1_001DFEE0(u8 *a);
s32 Task_Step_1_001E0020(u8 *p);
void Task_SetPriority_0_001E0160(void *arg0, s16 arg1);
void Task_Add_0_001E0180(u8 *a);
void Task_Remove_0_001E01F0(u8 *a);
s32 Task_GetState_0_001E02A0(s8 *p);

/* Task_RunAll_1_001DFCB0 */
static inline void clr_Task_RunAll_1_001DFCB0(u8 *p) {
    void (*f)(u8 *);
    p[0] = 0;
    p[1] = 0;
    *(s32 *)(p + 0x18) = -1;
    f = gTaskCallbackBss_004BAC28[0];
    if (f != NULL) f(p);
}
static inline void mk(u8 *a) {
    u32 i;
    u8 *p;
    if (a == NULL) {
        for (i = 0; i < gTaskCallbackBss_004BAC38[0]; i++) {
            p = gTaskCallbackBss_004BAC30[0] + gTaskCallbackBss_004BAC34[0] * i;
            if (p[1] == 2) p[1] = 3;
        }
    } else if (a[1] == 2) {
        a[1] = 3;
    }
}
s32 Task_RunAll_1_001DFCB0(u8 *a) {
    u32 i;
    s32 st;
    if (a == NULL) {
        if (gTaskCallbackSbss_002023A8 != 0) {
            st = gTaskCallbackBss_004BAC3C[0];
            if (st == 1 || st == 4) {
                mk(NULL);
                if (Task_Step_1_001E0020(NULL) != 0) return 1;
            }
        }
        gTaskCallbackBss_004BAC3C[0] = 0;
        for (i = 0; i < gTaskCallbackBss_004BAC38[0]; i++) clr_Task_RunAll_1_001DFCB0(gTaskCallbackBss_004BAC30[0] + gTaskCallbackBss_004BAC34[0] * i);
    } else {
        if (a[0] == 1 || a[0] == 4) {
            mk(a);
            if (Task_Step_1_001E0020(a) != 0) return 1;
        }
        clr_Task_RunAll_1_001DFCB0(a);
    }
    return 0;
}

/* Task_Run_1_001DFEE0 */
static inline void clr_Task_Run_1_001DFEE0(u8 *p) {
    void (*f)(u8 *);
    p[0] = 0;
    p[1] = 0;
    *(s32 *)(p + 0x18) = -1;
    f = gTaskCallbackBss_004BAC28[0];
    if (f != NULL) f(p);
}
s32 Task_Run_1_001DFEE0(u8 *a) {
    u32 i;
    s32 st;
    if (a == NULL) {
        st = gTaskCallbackBss_004BAC3C[0];
        if ((st == 1 || st == 4) && Task_Step_1_001E0020(NULL) != 0) return 1;
        gTaskCallbackBss_004BAC3C[0] = 0;
        for (i = 0; i < gTaskCallbackBss_004BAC38[0]; i++) clr_Task_Run_1_001DFEE0(gTaskCallbackBss_004BAC30[0] + gTaskCallbackBss_004BAC34[0] * i);
    } else {
        if ((a[0] == 1 || a[0] == 4) && Task_Step_1_001E0020(a) != 0) return 1;
        clr_Task_Run_1_001DFEE0(a);
    }
    return 0;
}

/* Task_Step_1_001E0020 */
#define gTaskCallbackBss_004BAC3C gTaskCallbackBss_004BAC3C__as_Task_Step_1_001E0020
extern s32 gTaskCallbackBss_004BAC3C__as_Task_Step_1_001E0020[];

s32 Task_Step_1_001E0020(u8 *p) {
    s32 s;
    if (!(gTaskCallbackBss_004BAC4C[0] & 1)) {
        if (p == NULL) {
            while ((s = gTaskCallbackBss_004BAC3C[0]) == 1 || s == 4) {
                if (gTaskCallbackBss_004BAC48[0] != -1) D_004BAC4D[0].f.b1 = 1;
                Task_Init_1_001E03C0();
            }
            D_004BAC4D[0].f.b1 = 0;
        } else {
            while ((s = *p) == 1 || s == 4) {
                if (gTaskCallbackBss_004BAC48[0] != -1) D_004BAC4D[0].f.b1 = 1;
                Task_Init_1_001E03C0();
            }
            D_004BAC4D[0].f.b1 = 0;
        }
        return 0;
    }
    return 0;
}
#undef gTaskCallbackBss_004BAC3C

/* Task_SetPriority_0_001E0160 */
void Task_SetPriority_0_001E0160(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0xE) = arg1;
    }
}

/* Task_Add_0_001E0180 */
void Task_Add_0_001E0180(u8 *a) {
    u32 i;
    if (a == 0) {
        for (i = 0; i < gTaskCallbackBss_004BAC38[0]; i++) (gTaskCallbackBss_004BAC30[0] + gTaskCallbackBss_004BAC34[0] * i)[1] = 1;
    } else {
        a[1] = 1;
    }
}

/* Task_Remove_0_001E01F0 */
#define gTaskCallbackBss_004BAC30 gTaskCallbackBss_004BAC30__as_Task_Remove_0_001E01F0
extern L gTaskCallbackBss_004BAC30__as_Task_Remove_0_001E01F0;
static inline void f(u8 *p) { if (p[0] == 2 || p[0] == 5) { p[1] = 2; p[0] = 2; } }
void Task_Remove_0_001E01F0(u8 *a) {
    u32 i;
    if (a == NULL) {
        for (i = 0; i < gTaskCallbackBss_004BAC30.n; i++) f(gTaskCallbackBss_004BAC30.base + gTaskCallbackBss_004BAC30.stride * i);
    } else {
        f(a);
    }
}
#undef gTaskCallbackBss_004BAC30

/* Task_GetState_0_001E02A0 */
#define gTaskCallbackBss_004BAC3C gTaskCallbackBss_004BAC3C__as_Task_GetState_0_001E02A0
extern u8 gTaskCallbackBss_004BAC3C__as_Task_GetState_0_001E02A0[];
s32 Task_GetState_0_001E02A0(s8 *p) { if (p == NULL) return gTaskCallbackBss_004BAC3C[0]; return *p; }
#undef gTaskCallbackBss_004BAC3C

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif
