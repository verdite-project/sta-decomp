/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Input_Init_2_0015FC60.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR Input_Init_2_0015FC60: 10 of 74 words differ (was 72, len-9). Length now right.
 * Fixed: inline get(i) keeps the i*0x58 mult in both loops (no strength reduction).
 * Still differs in loop 1: retail builds 0xC0 once with daddiu a2 and uses it both for the
 * bitfield or and as the call's 3rd arg. The u.b form gives ori 0xC0 + separate addiu a2;
 * the plain bitfield hi = 3 gives daddiu a3 (bitfield) + addiu a2 (arg) = +1 instr +1 nop.
 * Tried: u16/u8/u64 callee params, u16/u8 locals, (u8)/(u64) casts, inline param, signed
 * bitfields, u16/u32 containers, b38. None shares the constant. */
#include "m2c.h"
typedef struct {
    u8 pad[0x50];
    s16 x50;
    u8 x52;
    union { u8 b; struct { u8 lo:6; u8 hi:2; } f; } u;
    u8 x54;
    u8 pad55[3];
} S;
void memset(void *, s32, s32);
void Pad_Init_3_001D7290(s32);
void Pad_UpdateAll_3_001D7350(void);
void Pad_PortOpen_3_001D72F8(u32, s32, s32);
void Pad_ClearRepeat_3_001D7C80(u32, s32, s32);
void Pad_SetRepeat_3_001D7C08(s32, s32, u16, u16, u16);
extern S gMenuBss_00317230[];

static inline S *get(s32 i) { return &gMenuBss_00317230[i]; }
void Input_Init_2_0015FC60(void) {
    u32 i;
    memset(gMenuBss_00317230, 0, 0xB0);
    Pad_Init_3_001D7290(0);
    Pad_UpdateAll_3_001D7350();
    for (i = 0; i < 2; i++) {
        get(i)->u.b = (get(i)->u.b & ~0xC0) | 0xC0;
        get(i)->x54 = 10;
        Pad_PortOpen_3_001D72F8(i, 0, 0xC0);
    }
    for (i = 0; i < 2; i++) {
        get(i)->x50 = 0xF0;
        get(i)->x52 = 0xF;
        get(i)->u.f.lo = 4;
        Pad_ClearRepeat_3_001D7C80(i, 0, 0xFFFF);
        Pad_SetRepeat_3_001D7C08(i, 0, 0xF0, 0xF, 4);
    }
}
#else
INCLUDE_ASM(Input_Init_2_0015FC60);
#endif
