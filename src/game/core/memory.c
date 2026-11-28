#include "common.h"
typedef struct { s32 off[8]; s32 sz[8]; } T;
extern T gSoundBankLoadBss_00222B50;
extern s32 gMapSbss_00201E80;
void Mem_LayoutRegions_1_00128E80(void) {
    s32 v = gMapSbss_00201E80;
    gSoundBankLoadBss_00222B50.off[0] = v; v += gSoundBankLoadBss_00222B50.sz[0];
    gSoundBankLoadBss_00222B50.off[1] = v; v += gSoundBankLoadBss_00222B50.sz[1];
    gSoundBankLoadBss_00222B50.off[2] = v; v += gSoundBankLoadBss_00222B50.sz[2];
    gSoundBankLoadBss_00222B50.off[3] = v; v += gSoundBankLoadBss_00222B50.sz[3];
    gSoundBankLoadBss_00222B50.off[4] = v; v += gSoundBankLoadBss_00222B50.sz[4];
    gSoundBankLoadBss_00222B50.off[5] = v; v += gSoundBankLoadBss_00222B50.sz[5];
    gSoundBankLoadBss_00222B50.off[6] = v;
}
