#include "common.h"

/* bss_0042D7E0: the game's .bss from 0x0042D7E0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: dma, fx_spawn, model_emit, model_load, sfx_all, sfx_system,
   text_00176FB0.s, text_001777C0.s, text_001789E0.s, texture, texture_anim,
   texture_hash, vram_init */

#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/core/dma.c */
u8 gDmaBss_00483100[0x3000]; /* also D_004860FE */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 gTextureBss_004830F0[0x10]; /* also D_004830F4 */
s32 gTextureBss_004830EC[0x1];
s32 gTextureBss_004830E8[0x1];
s32 gTextureBss_004830E4[0x1];
s32 gTextureBss_004830E0[0x1];
u8 gTextureBss_004830DC[0x4]; /* also D_004830DE */
u8 gTextureBss_004830D8[0x4]; /* also D_004830DA */
u8 gTextureBss_004830D4[0x4]; /* also D_004830D6 */
u8 gTextureBss_004830D0[0x4]; /* also D_004830D2 */
u8 gTextureBss_004830CC[0x4]; /* also D_004830CE */
u8 gTextureBss_004830C8[0x4]; /* also D_004830CA */
u8 gTextureBss_004830C4[0x4];
u8 gTextureBss_004830C0[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture_hash.c */
u8 gTextureHashBss_00483090[0x30]; /* also D_004830AC */
u8 gTextureHashBss_004800DC[0x2fb4] __attribute__((aligned(4))); /* also D_004800DE, D_004800E2, D_004800EA, D_004800EE */
u8 gTextureHashBss_004800D0[0xc]; /* also D_004800D4 */
u8 gTextureHashBss_004800C8[0x8];
u8 gTextureHashBss_004800C0[0x8];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/vram_init.c */
u8 gVramInitBss_004800B0[0x10];
u8 gVramInitBss_0047F0C8[0xfe8] __attribute__((aligned(8))); /* also D_0047F0CA, D_0047F0CC */
u8 gVramInitBss_0047F0C4[0x4]; /* also D_0047F0C6 */
u8 gVramBlocks_0047F0C0[0x4]; /* also D_0047F0C2 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture_hash.c */
u8 gTextureHashBss_0047F080[0x40]; /* also D_0047F084 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 gTextureBss_0043F080[0x40000];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 gTextureBss_00438A70[0x6610];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 gTextureBss_00438A30[0x40];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 gTextureBss_00438A20[0x10]; /* also D_00438A22, D_00438A24 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture.c */
u8 gTextureBss_00438A1C[0x4]; /* also D_00438A1E */
s32 gTextureBss_00438A18[0x1];
s32 gTextureBss_00438A14[0x1];
u8 gTextureBss_00438A10[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/gfx/texture_anim.c */
u8 gTextureAnimBss_00437DC0[0xc50]; /* also D_00437DC8, D_004380D8, D_004383E8, D_004386F8 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_emit.c */
u8 gModelEmitBss_0042DDC0[0xa000];
u8 gModelEmitBss_0042D8C0[0x500];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_load.c */
s32 gModelLoadBss_0042D8B8[0x2];
s32 gModelLoadBss_0042D8B4[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_load.c */
u8 gModelLoadBss_0042D8B0[0x4];
u8 gModelLoadBss_0042D8AC[0x4];
u8 gModelLoadBss_0042D8A8[0x4];
u8 gModelLoadBss_0042D8A4[0x4];
u8 gModelLoadBss_0042D8A0[0x4];
u8 gModelLoadBss_0042D89C[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/model/model_load.c */
s32 gModelLoadBss_0042D898[0x1];
s32 gModelLoadBss_0042D894[0x1];
s32 gModelLoadBss_0042D890[0x1];
s32 gModelLoadBss_0042D88C[0x1];
s32 gModelLoadBss_0042D888[0x1];
s32 gModelLoadBss_0042D884[0x1];
s32 gModelLoadBss_0042D880[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_system.c */
u8 gSfxSystemBss_0042D850[0x30];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/effect/sfx_all.c */
u8 gSfxAllBss_0042D7E0[0x70];
#endif
