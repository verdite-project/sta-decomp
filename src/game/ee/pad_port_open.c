#include "common.h"
#include "game/ee.h"
typedef struct { u8 b[0x1C0]; } PadBuf;
typedef struct { PadBuf buf[8]; u8 open[8]; } PadState;
extern PadState gPadState_004B6900;
s32 scePadPortOpen(s32 port, s32 slot, void *addr);

s32 Pad_PortOpen_3_001D72F8(s32 port, s32 slot) {
    gPadState_004B6900.open[port] |= 1 << slot;
    return scePadPortOpen(port, slot, &gPadState_004B6900.buf[port * 4 + slot]);
}
