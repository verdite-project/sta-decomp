#include "common.h"

/* bss_0022F040: the game's .bss from 0x0022F040, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: sound, sound_bank_load, sound_bank_step, sound_emitter,
   sound_start, text_0012F0F0.s */

u8 D_0022F090[0x40000];
u8 D_0022F08C[0x4];
u8 D_0022F088[0x4];
s32 D_0022F084[0x1];
s32 D_0022F080[0x1];
u8 D_0022F070[0x10]; /* also D_0022F074 */
u8 D_0022F060[0x10]; /* also D_0022F064 */
u8 D_0022F050[0x10]; /* also D_0022F054 */
u8 D_0022F04C[0x4];
s32 D_0022F048[0x1];
s32 D_0022F044[0x1];
u8 D_0022F040[0x4] __attribute__((aligned(16)));
