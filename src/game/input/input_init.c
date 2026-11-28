#include "common.h"

typedef struct {
    u8 pad00[0x50];
    u16 repeatMask;
    u8 repeatDelay;
    u8 repeatInterval : 6;
    u8 mode : 2;
    u8 settleFrames;
    u8 pad55[3];
} InputPort;

extern InputPort gMenuBss_00317230[2];
void *memset(void *, s32, u32);
s32 Pad_Init_3_001D7290(s32 mode);
void Pad_UpdateAll_3_001D7350(void);
s32 Pad_PortOpen_3_001D72F8(s32 port, s32 slot);
void Pad_ClearRepeat_3_001D7C80(s32 port, s32 slot, u16 mask);
void Pad_SetRepeat_3_001D7C08(s32 port, s32 slot, u16 mask, u16 delay, u16 interval);

static inline InputPort *getPort(s32 port) {
    return &gMenuBss_00317230[port];
}

void Input_Init_2_0015FC60(void) {
    u32 port;

    memset(gMenuBss_00317230, 0, sizeof(gMenuBss_00317230));
    Pad_Init_3_001D7290(0);
    Pad_UpdateAll_3_001D7350();
    for (port = 0; port < 2; port++) {
        getPort(port)->mode = 3;
        getPort(port)->settleFrames = 10;
        Pad_PortOpen_3_001D72F8(port, 0);
    }
    for (port = 0; port < 2; port++) {
        getPort(port)->repeatMask = 0xF0;
        getPort(port)->repeatDelay = 0xF;
        getPort(port)->repeatInterval = 4;
        Pad_ClearRepeat_3_001D7C80(port, 0, 0xFFFF);
        Pad_SetRepeat_3_001D7C08(port, 0, 0xF0, 0xF, 4);
    }
}
