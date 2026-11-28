#include "common.h"
#include "game/core.h"
#include "game/data.h"
#include "game/sound.h"
typedef struct { u8 pad[0x14]; s32 x14; u64 b0:1; u64 b1:1; u64 rest:62; } S22C4;
extern s32 gMapSeStreamRodata_001FE8A0[];
extern S22C4 *D_002022C4;
extern s32 gLoadBuf_00270F40[];
#ifndef NONMATCHING
extern s32 gMapSeLoadBss_004BC2D0[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2D0 */
static s32 gMapSeLoadBss_004BC2D0[0x1];
#endif
#ifndef NONMATCHING
extern s32 gMapSeLoadBss_004BC2D4[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2D4 */
static s32 gMapSeLoadBss_004BC2D4[0x1];
#endif
#ifndef NONMATCHING
extern s32 gMapSeLoadBss_004BC2D8[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2D8 */
static s32 gMapSeLoadBss_004BC2D8[0x1];
#endif
#ifndef NONMATCHING
extern s32 gMapSeLoadBss_004BC2DC[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2DC */
static s32 gMapSeLoadBss_004BC2DC[0x1];
#endif
#ifndef NONMATCHING
extern s32 gMapSeLoadBss_004BC2E0[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2E0 */
static s32 gMapSeLoadBss_004BC2E0[0x1];
#endif
#ifndef NONMATCHING
extern u32 gMapSeLoadBss_004BC2E4[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2E4 */
static u32 gMapSeLoadBss_004BC2E4[0x1];
#endif
#ifndef NONMATCHING
extern u32 gMapSeLoadBss_004BC2E8[];
#else
/* data twins (src/game/data/save_system_start_bss.c): gMapSeLoadBss_004BC2E8 */
static u32 gMapSeLoadBss_004BC2E8[0x2];
#endif
void MapSe_LoadTask_1_001E19A0(void);
void FlushCache(s32);
void memcpy(s32, s32 *, s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
s32 Task_KillWrap_0_0014DAF0(s32);
s32 Task_SetPriorityWrap_0_0014DB00(s8 *, s32, s32 *);
s32 File_HashName_3_00159D10(s8 *);
s32 File_GetSectorOrSize_0_0015A300(s32);
void File_Close_2_0015AB80(s32);
s32 Arc_FindByHash_2_0015ABD0(s32);
void Dma_SprCopy_1_001789E0(s32, s32 *, s32);
void MapSe_BindBank_0_001E1810(s32, s32);
void sprintf(s8 *, s32 *, s32);
void Task_Register_0_0014DB10(void (*)());
void memset(s32 *, s32, s32);

/* MapSe_LoadTask_1_001E19A0 */
static inline u32 umin(u32 a, u32 b) { return a > b ? b : a; }
void MapSe_LoadTask_1_001E19A0(void) {
    s8 buf[256];
    s32 rem;
    s32 q;
    s32 sz;
    s32 n;
    s32 h;
    s32 off;

    if (D_002022C4 == 0) return;
    if (D_002022C4->b1 && D_002022C4->x14 != 0) return;
    if (*gMapSeLoadBss_004BC2D0 != -1) {
        if (*gMapSeLoadBss_004BC2E0 != 0) {
            if ((u8)Task_KillWrap_0_0014DAF0(*gMapSeLoadBss_004BC2E0)) {
                Task_AddWrap_0_0014DAD0(*gMapSeLoadBss_004BC2E0);
            } else {
                Task_RunWrap_0_0014DAB0(*gMapSeLoadBss_004BC2E0);
                *gMapSeLoadBss_004BC2E0 = 0;
            }
        }
        if (*gMapSeLoadBss_004BC2E0 == 0) {
            *gMapSeLoadBss_004BC2DC = 0;
            *gMapSeLoadBss_004BC2D4 = *gMapSeLoadBss_004BC2D0;
            *gMapSeLoadBss_004BC2D0 = -1;
            sprintf(buf, gMapSeStreamRodata_001FE8A0, *gMapSeLoadBss_004BC2D4 / 10);
            h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
            sz = File_GetSectorOrSize_0_0015A300(h);
            File_Close_2_0015AB80(h);
            *gMapSeLoadBss_004BC2E4 = sz;
            *gMapSeLoadBss_004BC2E8 = 0;
            *gMapSeLoadBss_004BC2E0 = Task_SetPriorityWrap_0_0014DB00(buf, 0x101, gLoadBuf_00270F40);
            if (*gMapSeLoadBss_004BC2E0 == 0) {
                if (*gMapSeLoadBss_004BC2E0 != 0) {
                    Task_AddWrap_0_0014DAD0(*gMapSeLoadBss_004BC2E0);
                    *gMapSeLoadBss_004BC2E0 = 0;
                }
                *gMapSeLoadBss_004BC2D8 = 0;
                *gMapSeLoadBss_004BC2E0 = 0;
                *gMapSeLoadBss_004BC2D4 = -1;
                *gMapSeLoadBss_004BC2D0 = -1;
                *gMapSeLoadBss_004BC2DC = 0;
                return;
            }
            Task_FlushWrap_0_0014DAC0(*gMapSeLoadBss_004BC2E0, 0);
        }
    } else if (*gMapSeLoadBss_004BC2D4 != -1) {
        switch ((u8)Task_KillWrap_0_0014DAF0(*gMapSeLoadBss_004BC2E0)) {
        case 0:
            break;
        case 5:
            n = *gMapSeLoadBss_004BC2E4 - *gMapSeLoadBss_004BC2E8;
            n = umin(n, 0x80000);
            q = n >> 4;
            off = q << 4;
            rem = n - off;
            FlushCache(0);
            Dma_SprCopy_1_001789E0(*gSoundBankLoadBss_00222B54 + *gMapSeLoadBss_004BC2E8, gLoadBuf_00270F40, q);
            if (rem > 0) {
                memcpy(*gSoundBankLoadBss_00222B54 + off, (s32 *)((u8 *)gLoadBuf_00270F40 + off), rem);
            }
            *gMapSeLoadBss_004BC2E8 += n;
            Task_RemoveWrap_0_0014DAE0(*gMapSeLoadBss_004BC2E0);
            break;
        case 1:
        case 2:
        case 4:
            break;
        case 3:
        case 6:
            if (*gMapSeLoadBss_004BC2DC == 0) {
                MapSe_BindBank_0_001E1810(*gSoundBankLoadBss_00222B54, *gSoundBankLoadBss_00222B54);
                Snd_SetStreamId_0_0012C790(*gMapSeLoadBss_004BC2D4);
                Snd_StartStream1_0_0012DD10(*gMapSeLoadBss_004BC2D4);
                *gMapSeLoadBss_004BC2DC = 1;
            }
            break;
        }
    }
}

/* MapSe_Flush_0_001E1CC0 */
void MapSe_Flush_0_001E1CC0(void) {
    if ((*gMapSeLoadBss_004BC2E0) != 0) {
        Task_AddWrap_0_0014DAD0((*gMapSeLoadBss_004BC2E0));
        (*gMapSeLoadBss_004BC2E0) = 0;
    }
    (*gMapSeLoadBss_004BC2D8) = 0;
    (*gMapSeLoadBss_004BC2E0) = 0;
    (*gMapSeLoadBss_004BC2D4) = -1;
    (*gMapSeLoadBss_004BC2D0) = -1;
    (*gMapSeLoadBss_004BC2DC) = 0;
}

/* MapSe_GetState_0_001E1D20 */
s32 MapSe_GetState_0_001E1D20(void) {
    return gMapSeLoadBss_004BC2DC[0];
}

/* MapSe_Request_0_001E1D30 */
void MapSe_Request_0_001E1D30(s32 arg0, s32 arg1) {
    if ((*gMapSeLoadBss_004BC2D4) != arg0) {
        if ((*gMapSeLoadBss_004BC2D8) != 0) {
            if (arg1 != 0) {
                goto block_4;
            }
        } else {
block_4:
            (*gMapSeLoadBss_004BC2D0) = arg0;
            (*gMapSeLoadBss_004BC2D8) = arg1;
        }
    }
}

/* MapSe_Init_0_001E1D70 */
void MapSe_Init_0_001E1D70(void) {
    if ((*gMapSeLoadBss_004BC2E0) != 0) {
        Task_AddWrap_0_0014DAD0((*gMapSeLoadBss_004BC2E0));
        (*gMapSeLoadBss_004BC2E0) = 0;
    }
    (*gMapSeLoadBss_004BC2D8) = 0;
    (*gMapSeLoadBss_004BC2E0) = 0;
    (*gMapSeLoadBss_004BC2D4) = -1;
    (*gMapSeLoadBss_004BC2D0) = -1;
    (*gMapSeLoadBss_004BC2DC) = 0;
    Task_Register_0_0014DB10(MapSe_LoadTask_1_001E19A0);
    memset(gMapSeLoadBss_004BC2D0, 0, 0x20);
    (*gMapSeLoadBss_004BC2D4) = -1;
    (*gMapSeLoadBss_004BC2D0) = -1;
}
