#include "common.h"
typedef struct {
    char p0[0x102];
    u16 btn;
    char p104[0x1C];
    u16 x120;
    char p122[0x46];
    s32 state;
    s32 req;
    s32 actNum;
    u8 act[6];
    u8 phase;
    u8 x17B;
    u8 x17C;
    u8 flags;
    s8 x17E;
    u8 x17F;
    u8 lock;
    u8 x181;
    char p182[0x3E];
} E;
typedef struct { E e[8]; u8 mask[2]; } PadData;
extern PadData gPadState_004B6900;
s32 scePadEnterPressMode(s32, s32);
s32 scePadExitPressMode(s32, s32);
s32 scePadGetReqState(s32, s32);
s32 scePadGetState(s32, s32);
s32 scePadInfoAct(s32, s32, s32, s32);
s32 scePadInfoMode(s32, s32, s32, s32);
s32 scePadInfoPressMode(s32, s32);
s32 scePadSetActAlign(s32, s32, u8 *);
s32 scePadSetMainMode(s32, s32, s32, s32);
s32 Pad_Read_4_001D7110(E *, s32, s32);
void Pad_StepRepeat_3_001D71E0(E *);
void scePadSetActDirect(s32, s32, u8 *);

void Pad_UpdateAll_3_001D7350(void) {
    u8 act[6];
    s32 port;
    s32 slot;
    E *e;
    s32 id;
    s32 ext;
    s32 r;
    s32 i;
    u16 old;

    for (port = 0; port < 2; port++) {
        for (slot = 0; slot < 4; slot++) {
            if (!((gPadState_004B6900.mask[port] >> slot) & 1)) continue;
            e = &gPadState_004B6900.e[port * 4 + slot];
            if ((e->state = scePadGetState(port, slot)) == 0) e->phase = 0;
            e->req = scePadGetReqState(port, slot);
            switch (e->phase) {
            case 0:
                e->x17E = -1;
                if (e->state == 0) break;
                id = scePadInfoMode(port, slot, 1, 0);
                if (id == 0) break;
                ext = scePadInfoMode(port, slot, 2, 0);
                e->flags = 0;
                if (ext > 0) id = ext;
                e->x181 = 0;
                /* IDs 2, 3 and 0x100 leave the phase unchanged. */
                if (id < 7) {
                    if (id >= 5) continue;
                    if (id < 2) continue;
                    if (id >= 4) e->phase = 0x28;
                } else {
                    if (id == 0x100) continue;
                    if (id > 0x100) continue;
                    if (id != 7) continue;
                    e->phase = 0x46;
                }
                break;
            case 0x28:
            case 0x46:
                if (e->phase != 0x28 || scePadInfoMode(port, slot, 4, -1) != 0) e->flags |= 1;
                if ((e->actNum = scePadInfoAct(port, slot, -1, 0)) != 0) e->flags |= 2;
                if (scePadInfoPressMode(port, slot) == 1) e->flags |= 4;
                if ((e->flags & 1) && (e->x17F == 1 || e->x17F == 2)) {
                    e->phase = 0x6E;
                } else if (e->x17F == 0) {
                    e->phase = 0x64;
                } else if (e->phase == 0x28) {
                    e->phase = 0xFD;
                } else {
                    e->phase = 0xFE;
                }
                break;
            case 0x64:
                if (scePadSetMainMode(port, slot, 0, e->lock) == 1) e->phase = 0x65;
                break;
            case 0x65:
                if (e->req == 1) e->phase = 0x64;
                if (e->req == 0 && (e->state == 6 || e->state == 2)) {
                    e->x181 = 0;
                    e->phase = 0xFD;
                }
                break;
            case 0x6E:
                if (scePadSetMainMode(port, slot, 1, e->lock) == 1) e->phase = 0x6F;
                break;
            case 0x6F:
                if (e->req == 1) e->phase = 0x6E;
                if (e->req == 0 && (e->state == 6 || e->state == 2)) {
                    e->x181 = 0;
                    if (scePadInfoPressMode(port, slot) == 1) e->flags |= 4;
                    e->phase = 0xFE;
                }
                break;
            case 0x78:
                if (scePadEnterPressMode(port, slot) == 1) e->phase = 0x79;
                break;
            case 0x79:
                if (e->req == 1) e->phase = 0x78;
                if (e->req == 0 && (e->state == 6 || e->state == 2)) e->phase = 0xFF;
                break;
            case 0x82:
                if (scePadExitPressMode(port, slot) == 1) e->phase = 0x83;
                break;
            case 0x83:
                if (e->req == 1) e->phase = 0x82;
                if (e->req == 0 && (e->state == 6 || e->state == 2)) e->phase = 0xFE;
                break;
            case 0xC8:
                for (i = 0; i < 6; i++) {
                    act[i] = 0xFF;
                    e->act[i] = 0;
                }
                for (i = 0; i < e->actNum; i++) act[i] = i;
                if (scePadSetActAlign(port, slot, act) == 1) e->phase++;
                break;
            case 0xC9:
                if (e->req == 1) e->phase--;
                if (e->req == 0) {
                    e->x181 = 1;
                    e->phase = e->x17B;
                }
                break;
            case 0xFF:
                if (e->x17F == 2) e->x17F = 0xFF;
                if (e->x17F < 2) {
                    e->phase = 0x82;
                    e->x17E = -1;
                    break;
                }
                e->x17E = 2;
                if (e->x181 || !(e->flags & 2)) goto read_pad;
                e->x17B = e->phase;
                e->phase = 0xC8;
                break;
            case 0xFE:
                if (e->x17F == 1) e->x17F = 0xFF;
                if (e->x17F == 0) {
                    e->x17E = -1;
                    e->phase = 0;
                    break;
                }
                if (e->x17F == 2) {
                    if (e->flags & 4) {
                        e->phase = 0x78;
                        e->x17E = -1;
                        break;
                    }
                }
                e->x17E = 1;
                if (e->x181 == 0 && (e->flags & 2)) {
                    e->x17B = e->phase;
                    e->phase = 0xC8;
                } else {
                    goto read_pad;
                }
                break;
            case 0xFD: {
                /* The signed byte/word copy keeps the request in v1 while
                 * ee-gcc schedules the subtraction in the branch delay slot. */
                s8 requestedMode = e->x17F;
                s32 mode = requestedMode;

                if (e->x17F == 0) {
                    e->x17F = 0xFF;
                } else {
                    requestedMode = mode;
                }
                if ((u8)(e->x17F - 1) < 2) {
                    e->x17E = -1;
                    e->phase = 0;
                    break;
                }
                e->x17E = 0;
                if (e->x181 == 0 && (e->flags & 2)) {
                    e->x17B = e->phase;
                    e->phase = 0xC8;
                    break;
                }
                goto read_pad;
            }
            read_pad:
                old = e->btn;
                r = Pad_Read_4_001D7110(e, port, slot);
                if (r != 0) {
                    if (r == -1) e->phase = 0;
                    e->x120 = e->btn & ~old;
                    Pad_StepRepeat_3_001D71E0(e);
                    if ((e->flags & 2) && e->state == 6) scePadSetActDirect(port, slot, e->act);
                }
                break;
            }
        }
    }
}
