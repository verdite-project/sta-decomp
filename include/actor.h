/* The big game object behind the getter/setter block at 0x13D1C0-0x13FFFF.
 * gPlayerSbss_002022E4 points to one. The name is a guess; fields are named by offset until known.
 * Layout comes from the matched accessors in src/game_0013*.c. */
#ifndef ACTOR_H
#define ACTOR_H

#include "common.h"

typedef struct Actor {
    u8 pad000[0x81];
    u8 unk81;           /* count; 0 means none (Enemy_GetCollider_0_0013FB90) */
    u8 unk82[0x426];    /* indexed by u8 into the unk51C table; real length unknown */
    s32 unk4A8;
    u16 unk4AC;
    u8 pad4AE[0x2];
    s8 *unk4B0;
    s8 *unk4B4;
    u8 pad4B8[0x60];
    s8 *unk518;         /* sub-object; +0x190 is another pointer */
    s32 unk51C;
    u8 pad520[0x81];
    Flags8 flags5A1;
    u8 pad5A2[0xE];
    Flags8 flags5B0;
    Flags8 flags5B1;
    Flags8_6x2 flags5B2;
    Flags8 flags5B3;
    Flags8 flags5B4;
    Flags8_4x2 flags5B5;
    Flags8 flags5B6;
    Flags8 flags5B7;
    f32 unk5B8;
    f32 unk5BC;
    f32 unk5C0;
    f32 unk5C4;
    f32 unk5C8;
    f32 unk5CC;
    f32 unk5D0;
    f32 unk5D4;
    f32 unk5D8;
    f32 unk5DC;
    u8 pad5E0[0x28];
    s8 unk608;
    s8 unk609;
    s8 unk60A;
    s8 unk60B;
    u8 pad60C[0xA8];
    s16 unk6B4[2];      /* indexed by flags5B0.f.b0 */
    u8 unk6B8;
    u8 unk6B9;
    s16 unk6BA;
    f32 unk6BC;
    u8 pad6C0[0x50];
    u16 unk710;
    u16 unk712;
} Actor;

extern Actor *gPlayerSbss_002022E4;

#endif
