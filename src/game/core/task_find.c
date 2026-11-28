/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Task_Find_0_001E02C0.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* FAR: retail keeps the mult each iteration (no strength reduction) and tests 0 < count
 * with sltu $at first; the plain for-loop strength-reduces. */
#include "common.h"
typedef struct { u8 state; u8 x1; u8 pad2[0xA]; s16 xC; s16 xE; s32 x10; s32 x14; s32 x18; } Rec;
extern s32 (*D_004BAC20[])(Rec *, s32);
extern u8 *D_004BAC30[];
extern s32 D_004BAC34[];
extern u32 D_004BAC38[];
extern s32 D_004BAC48[];

Rec *Task_Find_0_001E02C0(s32 arg, s16 id, s32 v) {
    u32 i;
    Rec *r;
    s32 ok;
    r = 0;
    for (i = 0; i < D_004BAC38[0]; i++) {
        r = (Rec *)(D_004BAC30[0] + D_004BAC34[0] * i);
        if (r->state == 0) {
            r->x14 = v;
            if (D_004BAC20[0] != 0) {
                ok = D_004BAC20[0](r, arg);
            } else {
                ok = 0;
            }
            if (ok == 0) return 0;
            r->state = 2;
            r->x1 = 2;
            r->xC = id;
            r->xE = 0;
            r->x14 = v;
            r->x10 = v;
            r->x18 = D_004BAC48[0];
            return r;
        }
        r = 0;
    }
    return r;
}
#else
INCLUDE_ASM(Task_Find_0_001E02C0);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/save_system_start_bss.c): D_004BAC48 */
s32 D_004BAC48[0x1];
#endif
