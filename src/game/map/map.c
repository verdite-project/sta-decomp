#include "m2c.h"
#include "common.h"
#include "actor.h"
#include "game/core.h"
#include "game/map.h"
typedef struct { u8 pad[0x14]; s32 x14; u8 b0:1; u8 b1:1; } G2C4;
typedef struct { u8 lo:3; u8 f3:3; } BF;
typedef struct { f32 v[4]; s32 x10; u8 b14; char p15[3]; s32 x18; } Out;
typedef struct { u8 pad[0x1C]; u16 x1C; u8 p[0xA]; } T_Map_StreamUpdate_0_001B0020;
typedef struct { s32 x0; s32 x4; } U_Map_StreamUpdate_0_001B0020;
typedef struct { s32 id; u8 pad[0x6E]; u16 x72; u8 p74[0xCC]; T_Map_StreamUpdate_0_001B0020 *x140; u8 p144[0x40]; U_Map_StreamUpdate_0_001B0020 *x184; } O_MapObj_DropItem_0_001B0880;
typedef struct { s32 *p; } O_MapObj_SpawnItem_0_001B0990;
typedef struct { char p[0x1D8]; u8 b0:1; } T_Map_FindLoaded_0_001B0AE0;
typedef struct { s32 x0; char p[0x8A]; s16 x8E; } U_Map_FindLoaded_0_001B0AE0;
typedef struct { s32 id; } O_Map_GetLightIndex_0_001B0BC0;
typedef struct { char pad[0x1D8]; u8 b0:1; } O2;
typedef struct { u8 pad[0x20]; u16 x20; u8 pad2[0x30 - 0x22]; } Ent;
typedef struct { s32 id; u8 pad[0x72]; u16 x76; u8 pad2[0x148 - 0x78]; Ent *x148; u8 pad3[0x18C - 0x14C]; u32 *x18C; u8 pad4[0x1D8 - 0x190]; u8 x1D8; } O_Map_GetGlowIndex_0_001B0C70;
extern G2C4 *D_002022C4;
extern BF D_00222A54[];
extern u8 gLoadBuf_00270F40[];
extern f32 D_004B4B90[];
#ifndef NONMATCHING
extern s32 D_004B4BB0[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BB0 */
static s32 D_004B4BB0[0x1] __attribute__((aligned(16)));
#endif
#ifndef NONMATCHING
extern s32 D_004B4BB4[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BB4 */
static s32 D_004B4BB4[0x1];
#endif
extern s16 D_004B4BBC[];
extern s16 D_004B4BBE[];
#ifndef NONMATCHING
extern s32 D_004B4BC0[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BC0 */
static s32 D_004B4BC0[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004B4BC4[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BC4 */
static s32 D_004B4BC4[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004B4BC8[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BC8 */
static s32 D_004B4BC8[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004B4BCC[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BCC */
static s32 D_004B4BCC[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004B4BB8[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BB8 */
static s32 D_004B4BB8[0x1];
#endif
extern f32 D_004B4B94[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
f32 D_004B4B98[0x6] __attribute__((aligned(8)));
extern s32 D_004B4B9C[];
extern s32 D_004B4B90__as_Map_StreamStart_0_001B0450[];
extern struct { f32 v[4]; char p10[0x14]; s32 x24; char p28[8]; s32 h; s32 x34; } D_004B4B90__as_Map_StreamGetResult_1_001B0660;
extern s32 D_004B4B90__as_Map_StreamInit_0_001B07B0[];
extern s32 D_004B4B94__as_Map_StreamInit_0_001B07B0[];
extern s32 D_004B4B98__as_Map_StreamInit_0_001B07B0[];
extern O_MapObj_DropItem_0_001B0880 **D_00201E80[2];
extern O_MapObj_SpawnItem_0_001B0990 *D_00201E80__as_MapObj_SpawnItem_0_001B0990[2];
extern T_Map_FindLoaded_0_001B0AE0 **D_00201E88;
extern T_Map_FindLoaded_0_001B0AE0 **D_00201E8C;
extern O_Map_GetLightIndex_0_001B0BC0 **D_00201E88__as_Map_GetLightIndex_0_001B0BC0;
extern O_Map_GetLightIndex_0_001B0BC0 **D_00201E8C__as_Map_GetLightIndex_0_001B0BC0;
extern s32 D_00201E80__as_Map_FindLoaded_0_001B0AE0;
void Map_StreamUpdate_0_001B0020(void);
s32 Map_StreamGetResult_1_001B0660(Out *o);
void Map_RequestArea_1_001B06E0(s32 arg0, f32 *arg1, s32 arg2);
void MapObj_DropItem_0_001B0880(u16 a0, u16 a1);
void MapObj_SpawnItem_0_001B0990(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, u16 id, s32 t2);
void MapObj_SendEvent_1_001B0A80(void *arg0, s32 arg1);
s32* Map_FindLoaded_0_001B0AE0(s32 arg0);
void Map_SetVar_0_001B0B30(s32 arg0, s16 arg1);
u16 Map_GetGlowIndex_0_001B0C70(s32 arg0, s32 arg1);
void MapObj_SpawnSfx_0_001B0D60(s16 arg0, s16 arg1, s32 arg2, s32 arg3);
s32 Task_KillWrap_0_0014DAF0(s32);
void Map_GetFile_2_001B7050(s32, u8 *, s32 *);
s32 Map_AllocAreaBuf_1_001B70E0(s32);
s32 Task_SetPriorityWrap_0_0014DB00(u8 *, s32, u8 *);
s32 Obj_FreeTimer_0_0014DA70(s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(u8 *, u8 *, s32);
void memcpy(u8 *, u8 *, s32);
s32 Obj_SetTimerEx_0_0014DA90(s32, s32, s32, s32);
s32 Obj_SetTimer_0_0014DA80(s32, s32);
void Map_LoadTextures_0_001B6FC0(s32);
void Map_SetOrigin_1_001B4BD0(s32, void *);
void Map_OnAreaLoadedWrap_1_001B6FB0(s32);
void sceVu0CopyVector(f32 *v0, f32 *v1);
void Map_FreeArea_1_001B5640(s32);
void Task_Register_0_0014DB10(void (*)());
void memset(s32 *, s32, s32);
void Map_SetOrigin_1_001B4BD0__as_Map_StreamUpdate_0_001B0020(s32, f32 *);
s32 Task_AddWrap_0_0014DAD0__as_Map_StreamFlush_1_001B03E0();
void Map_SetOrigin_1_001B4BD0__as_Map_StreamStart_0_001B0450(s32, s32 *);
void ItemObj_DropToGround_0_001AE0E0(O_MapObj_DropItem_0_001B0880 **, s32, O_MapObj_DropItem_0_001B0880 *);
s32 Inventory_CountItem_0_001CC0C0(s32, s32);
void ItemObj_Drop_0_001AE900(O_MapObj_SpawnItem_0_001B0990 *, s16, s32, s32, s32, s32);
void Script_SendEvent_2_00166F80(s32, s32, s32);
s32 Sfx_Spawn_2_00169B50(s32, s32, s32, s32);
void sceVu0AddVector(s32, s32, s8 *);
void Mtx_Compose_2_00173FD0(f32 *, s32, s32, f32 *);
void Sfx_SetTransform_1_001677C0(s32, f32 *);

/* Map_StreamUpdate_0_001B0020_ */
/* Map_StreamUpdate_0_001B0020_ */
/* Map_StreamUpdate_0_001B0020_ */
/* Map_StreamUpdate_0_001B0020 */
static inline u32 umin(u32 a, u32 b) { return a > b ? b : a; }

void Map_StreamUpdate_0_001B0020(void) {
    u8 buf[0x100];
    s32 n;
    s32 q;
    s32 off;
    s32 r;
    s32 x;
    if (D_002022C4 == 0) return;
    if (D_002022C4->b1 && D_002022C4->x14 != 0) return;
    if (D_004B4BB0[0] != -1) {
        if (D_004B4BC0[0] != 0) {
            if ((u8)Task_KillWrap_0_0014DAF0(D_004B4BC0[0])) {
                Task_AddWrap_0_0014DAD0(D_004B4BC0[0]);
            } else {
                Task_RunWrap_0_0014DAB0(D_004B4BC0[0]);
                D_004B4BC0[0] = 0;
            }
        }
        if (D_004B4BC0[0] != 0) return;
        D_004B4BBC[0] = 0;
        D_004B4BB4[0] = D_004B4BB0[0];
        D_004B4B90[0] = D_004B4B90[0];
        D_004B4B90[1] = D_004B4B90[1];
        D_004B4B90[2] = D_004B4B90[2];
        D_004B4B90[3] = D_004B4B90[3];
        D_004B4BB0[0] = -1;
        Map_GetFile_2_001B7050(D_004B4BB4[0], buf, D_004B4BC8);
        D_004B4BC4[0] = Map_AllocAreaBuf_1_001B70E0(D_004B4BB4[0]);
        D_004B4BCC[0] = 0;
        D_004B4BC0[0] = Task_SetPriorityWrap_0_0014DB00(buf, 0x100, gLoadBuf_00270F40);
        D_004B4BCC[0] = Obj_FreeTimer_0_0014DA70(D_004B4BC0[0]);
        D_004B4BBE[0] = 0;
        Task_FlushWrap_0_0014DAC0(D_004B4BC0[0], 0);
    } else if (D_004B4BB4[0] != -1) {
        switch ((u8)Task_KillWrap_0_0014DAF0(D_004B4BC0[0])) {
        case 0:
            break;
        case 5:
            n = D_004B4BC8[0] - D_004B4BCC[0];
            n = umin(n, 0x80000);
            q = n >> 4;
            off = q << 4;
            r = n - off;
            FlushCache(0);
            Dma_SprCopy_1_001789E0((u8 *)(**(s32 **)(*(s32 *)D_004B4BC4[0] + 0x24) + D_004B4BCC[0]), gLoadBuf_00270F40, q);
            if (r > 0) {
                memcpy((u8 *)(**(s32 **)(*(s32 *)D_004B4BC4[0] + 0x24) + D_004B4BCC[0]) + off, gLoadBuf_00270F40 + off, r);
            }
            D_004B4BCC[0] += n;
            Task_RemoveWrap_0_0014DAE0(D_004B4BC0[0]);
            break;
        case 3:
        case 6:
            if (D_004B4BBC[0] == 0) {
                x = **(s32 **)(*(s32 *)D_004B4BC4[0] + 0x24);
                if (D_004B4BBE[0] == 0) {
                    if (Obj_SetTimerEx_0_0014DA90(D_004B4BC0[0], x, x, D_004B4BC8[0])) {
                        D_004B4BBE[0] = 1;
                    }
                }
                if (D_004B4BBE[0]) {
                    if (Obj_SetTimer_0_0014DA80(D_004B4BC0[0], 2)) break;
                }
                D_004B4BBE[0] = 0;
                Map_LoadTextures_0_001B6FC0(D_004B4BC4[0]);
                Map_SetOrigin_1_001B4BD0__as_Map_StreamUpdate_0_001B0020(*(s32 *)D_004B4BC4[0], D_004B4B90);
                D_004B4BBC[0] = 1;
            }
            break;
        case 1:
        case 2:
        case 4:
            D_00222A54[0].f3 = 1;
            break;
        }
    }
}

/* Map_StreamFlush_1_001B03E0 */

void Map_StreamFlush_1_001B03E0(void) {
    if ((*D_004B4BC0) != 0) {
        Task_AddWrap_0_0014DAD0__as_Map_StreamFlush_1_001B03E0((*D_004B4BC0));
        (*D_004B4BC0) = 0;
    }
    (*D_004B4BB8) = 0;
    (*D_004B4BC0) = 0;
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
    (*D_004B4BBC) = 0;
    (*D_004B4BC4) = 0;
    (*D_004B4BBE) = 0;
}

/* Map_StreamStart_0_001B0450 */
static inline void reset(void) {
    if (D_004B4BC0[0] != 0) {
        Task_AddWrap_0_0014DAD0(D_004B4BC0[0]);
        D_004B4BC0[0] = 0;
    }
    D_004B4BB8[0] = 0;
    D_004B4BC0[0] = 0;
    D_004B4BB4[0] = -1;
    D_004B4BB0[0] = -1;
    D_004B4BBC[0] = 0;
    D_004B4BC4[0] = 0;
    D_004B4BBE[0] = 0;
}
static inline s32 status(void) {
    s32 r = 0;
    if (D_004B4BC0[0] != 0) r = Task_KillWrap_0_0014DAF0(D_004B4BC0[0]);
    return r;
}

void Map_StreamStart_0_001B0450(void) {
    s8 *p;
    s32 x;
    if (D_004B4BB4[0] != -1) {
        if ((u8)status() != 3 && (u8)status() != 6) {
            while (!D_004B4BBC[0]) {
                Task_InitWrap_0_0014DAA0();
            }
        } else if (D_004B4BBC[0] == 0) {
            x = **(s32 **)(*(s8 **)D_004B4BC4[0] + 0x24);
            if (D_004B4BBE[0] == 0) {
                if (Obj_SetTimerEx_0_0014DA90(D_004B4BC0[0], x, x, D_004B4BC8[0])) {
                    D_004B4BBE[0] = 1;
                }
            }
            if (D_004B4BBE[0]) {
                while (Obj_SetTimer_0_0014DA80(D_004B4BC0[0], 2)) {
                }
            }
            Map_LoadTextures_0_001B6FC0(D_004B4BC4[0]);
            Map_SetOrigin_1_001B4BD0__as_Map_StreamStart_0_001B0450(*(s32 *)D_004B4BC4[0], D_004B4B90__as_Map_StreamStart_0_001B0450);
        }
        p = *(s8 **)D_004B4BC4[0];
        Map_OnAreaLoadedWrap_1_001B6FB0(D_004B4BC4[0]);
        ((Flags8_6x2 *)(**(s8 ***)*(s8 **)(p + 0x178) + 0x24))->f.b6 = 1;
        reset();
    }
}

/* Map_StreamGetResult_1_001B0660 */


s32 Map_StreamGetResult_1_001B0660(Out *o)
{
    s32 r = 0;
    if (D_004B4B90__as_Map_StreamGetResult_1_001B0660.h)
        r = Task_KillWrap_0_0014DAF0(D_004B4B90__as_Map_StreamGetResult_1_001B0660.h);
    if (o) {
        sceVu0CopyVector(o->v, D_004B4B90__as_Map_StreamGetResult_1_001B0660.v);
        o->x10 = D_004B4B90__as_Map_StreamGetResult_1_001B0660.x24;
        o->b14 = r;
        o->x18 = D_004B4B90__as_Map_StreamGetResult_1_001B0660.x34;
    }
    return r;
}

/* Map_RequestArea_1_001B06E0 */
void Map_RequestArea_1_001B06E0(s32 arg0, f32 *arg1, s32 arg2) {
    if (D_004B4BB4[0] != arg0 && (D_004B4BB8[0] == 0 || arg2 != 0)) {
        if (D_004B4BBC[0] == 0 && D_004B4BB4[0] != -1) {
            Map_FreeArea_1_001B5640(D_004B4BC4[0]);
        }
        D_004B4BB0[0] = arg0;
        D_004B4B90[0] = -arg1[0];
        D_004B4B94[0] = -arg1[1];
        D_004B4B98[0] = -arg1[2];
        D_004B4BB8[0] = arg2;
        D_004B4B9C[0] = 0;
    }
}

/* Map_StreamInit_0_001B07B0 */

void Map_StreamInit_0_001B07B0(void) {
    if ((*D_004B4BC0) != 0) {
        Task_AddWrap_0_0014DAD0((*D_004B4BC0));
        (*D_004B4BC0) = 0;
    }
    (*D_004B4BB8) = 0;
    (*D_004B4BC0) = 0;
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
    (*D_004B4BBC) = 0;
    (*D_004B4BC4) = 0;
    (*D_004B4BBE) = 0;
    (*D_004B4B90__as_Map_StreamInit_0_001B07B0) = 0;
    (*D_004B4B94__as_Map_StreamInit_0_001B07B0) = 0;
    (*D_004B4B98__as_Map_StreamInit_0_001B07B0) = 0;
    (*D_004B4B9C) = 0;
    Task_Register_0_0014DB10(Map_StreamUpdate_0_001B0020);
    memset(D_004B4B90__as_Map_StreamInit_0_001B07B0, 0, 0x40);
    (*D_004B4BB4) = -1;
    (*D_004B4BB0) = -1;
}

/* MapObj_DropItem_0_001B0880 */
/* MapObj_DropItem_0_001B0880 */
#define C (D_00201E80[2])
#define D (D_00201E80[3])

void MapObj_DropItem_0_001B0880(u16 a0, u16 a1) {
    O_MapObj_DropItem_0_001B0880 **h;
    s32 i;
    O_MapObj_DropItem_0_001B0880 *o;
    h = 0;
    if (C) { O_MapObj_DropItem_0_001B0880 *t = *C; if (t && t->id == a0) h = C; }
    if (D) { O_MapObj_DropItem_0_001B0880 *t = *D; if (t && t->id == a0) h = D; }
    if (h == 0) return;
    i = 0;
    if (0 < (*h)->x72) {
        do {
            U_Map_StreamUpdate_0_001B0020 *u;
            T_Map_StreamUpdate_0_001B0020 *t;
            t = &(*h)->x140[i];
            u = &(*h)->x184[i];
            if (t->x1C == a1) ItemObj_DropToGround_0_001AE0E0(h, u->x0, *h);
            i++;
        } while (i < (*h)->x72);
    }
}
#undef C
#undef D

/* MapObj_SpawnItem_0_001B0990 */

void MapObj_SpawnItem_0_001B0990(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, u16 id, s32 t2) {
    O_MapObj_SpawnItem_0_001B0990 *o;
    O_MapObj_SpawnItem_0_001B0990 *p;
    o = 0;
    p = D_00201E80__as_MapObj_SpawnItem_0_001B0990[2];
    if (p && p->p && *p->p == id) o = p;
    p = D_00201E80__as_MapObj_SpawnItem_0_001B0990[3];
    if (p && p->p && *p->p == id) o = p;
    if (o && (u32)a0 < 0x400 && id < 200 && Inventory_CountItem_0_001CC0C0(a0, 1)) {
        ItemObj_Drop_0_001AE900(o, a0, a1, a2, t2, 0);
    }
}

/* MapObj_SendEvent_1_001B0A80 */
void MapObj_SendEvent_1_001B0A80(void *arg0, s32 arg1) {
    s32 *temp_6;

    if (arg0 != NULL) {
        temp_6 = M2C_FIELD(arg0, s32 **, 0xC);
        if ((temp_6 != NULL) && (M2C_FIELD(arg0, u8 *, 0x1D8) & 1)) {
            Script_SendEvent_2_00166F80(*temp_6, (arg1 != 0) ? 0x7FFE : 0x7FFD, 0);
        }
    }
}
#undef C
#undef D
#undef C
#undef D

/* Map_FindLoaded_0_001B0AE0 */

/* Map_FindLoaded_0_001B0AE0 */
s32 *Map_FindLoaded_0_001B0AE0(s32 arg0) {
    if ((M2C_FIELD(&D_00201E80__as_Map_FindLoaded_0_001B0AE0, s32 **, 8) != NULL) && (*M2C_FIELD(&D_00201E80__as_Map_FindLoaded_0_001B0AE0, s32 **, 8) == arg0)) {
        return M2C_FIELD(&D_00201E80__as_Map_FindLoaded_0_001B0AE0, s32 **, 8);
    }
    if ((M2C_FIELD(&D_00201E80__as_Map_FindLoaded_0_001B0AE0, s32 **, 0xC) != NULL) && (*M2C_FIELD(&D_00201E80__as_Map_FindLoaded_0_001B0AE0, s32 **, 0xC) == arg0)) {
        return M2C_FIELD(&D_00201E80__as_Map_FindLoaded_0_001B0AE0, s32 **, 0xC);
    }
    return NULL;
}

/* Map_SetVar_0_001B0B30 */
void Map_SetVar_0_001B0B30(s32 arg0, s16 arg1) {
    U_Map_FindLoaded_0_001B0AE0 *r = 0;
    if ((D_00201E88 ? (*D_00201E88)->b0 != 0 : 0) && ((U_Map_FindLoaded_0_001B0AE0 *)*D_00201E88)->x0 == arg0) r = (U_Map_FindLoaded_0_001B0AE0 *)*D_00201E88;
    if ((D_00201E8C ? (*D_00201E8C)->b0 != 0 : 0) && ((U_Map_FindLoaded_0_001B0AE0 *)*D_00201E8C)->x0 == arg0) r = (U_Map_FindLoaded_0_001B0AE0 *)*D_00201E8C;
    if (r) r->x8E = arg1;
}

/* Map_GetLightIndex_0_001B0BC0 */
static inline s32 act(O_Map_GetLightIndex_0_001B0BC0 **p) { return p ? (((O2 *)*p)->b0 != 0) : 0; }
s16 Map_GetLightIndex_0_001B0BC0(s32 id, s32 base) {
    s32 r = -1;
    if (act(D_00201E88__as_Map_GetLightIndex_0_001B0BC0) && (*D_00201E88__as_Map_GetLightIndex_0_001B0BC0)->id == id) r = 0;
    if (act(D_00201E8C__as_Map_GetLightIndex_0_001B0BC0) && (*D_00201E8C__as_Map_GetLightIndex_0_001B0BC0)->id == id) r = 1;
    if (r == -1) return r;
    return base + r * 64;
}

/* Map_GetGlowIndex_0_001B0C70 */
#define TB ((O_Map_GetGlowIndex_0_001B0C70 ***)&D_00201E80__as_Map_FindLoaded_0_001B0AE0)
static inline O_Map_GetGlowIndex_0_001B0C70 *get(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    O_Map_GetGlowIndex_0_001B0C70 *t;
    O_Map_GetGlowIndex_0_001B0C70 *t2;
    O_Map_GetGlowIndex_0_001B0C70 *r;
    r = NULL;
    if (TB[2] != NULL) {
        var_v1 = ((*TB[2])->x1D8 & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        t = *TB[2];
        if (t->id == arg0) {
            r = t;
        }
    }
    var_v1_2 = TB[3] != NULL ? ((*TB[3])->x1D8 & 1) != 0 : 0;
    if (var_v1_2 != 0) {
        t2 = *TB[3];
        if (t2->id == arg0) {
            r = t2;
        }
    }
    return r;
}

u16 Map_GetGlowIndex_0_001B0C70(s32 arg0, s32 arg1) {
    O_Map_GetGlowIndex_0_001B0C70 *p;
    Ent *e;
    s32 i;

    p = get(arg0);
    if (p != NULL) {
        for (i = 0; i < p->x76; i++) {
            if (arg1 == p->x148[i].x20 % 100) {
                return p->x18C[i];
            }
        }
    }
    return 0;
}
#undef TB
#undef TB
#undef C
#undef D
#undef TB

/* MapObj_SpawnSfx_0_001B0D60 */
#define D_00201E80 D_00201E80__as_MapObj_SpawnSfx_0_001B0D60
extern M2C_UNK D_00201E80__as_MapObj_SpawnSfx_0_001B0D60;

void MapObj_SpawnSfx_0_001B0D60(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    f32 mtx[16];
    f32 scale[4] __attribute__((aligned(16)));
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *o;
    s32 h;

    o = NULL;
    if (M2C_FIELD(&D_00201E80, s8 ***, 8) != NULL) {
        var_v1 = (M2C_FIELD(*M2C_FIELD(&D_00201E80, s8 ***, 8), u8 *, 0x1D8) & 1) != 0;
    } else {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        temp_a1 = *M2C_FIELD(&D_00201E80, s8 ***, 8);
        if (M2C_FIELD(temp_a1, s32 *, 0) == arg0) {
            o = temp_a1;
        }
    }
    if (M2C_FIELD(&D_00201E80, s8 ***, 0xC) != NULL) {
        var_v1_2 = (M2C_FIELD(*M2C_FIELD(&D_00201E80, s8 ***, 0xC), u8 *, 0x1D8) & 1) != 0;
    } else {
        var_v1_2 = 0;
    }
    if (var_v1_2 != 0) {
        temp_a1_2 = *M2C_FIELD(&D_00201E80, s8 ***, 0xC);
        if (M2C_FIELD(temp_a1_2, s32 *, 0) == arg0) {
            o = temp_a1_2;
        }
    }
    if (arg1 <= 0 || arg1 > 0x3FF) {
        return;
    }
    h = Sfx_Spawn_2_00169B50(arg1, 0, 0, 0);
    if (h != 0) {
        if (o != NULL) {
            sceVu0AddVector(arg2, arg2, o + 0x10);
        }
        scale[2] = 1.0f;
        scale[1] = 1.0f;
        scale[0] = 1.0f;
        Mtx_Compose_2_00173FD0(mtx, arg2, arg3, scale);
        Sfx_SetTransform_1_001677C0(h, mtx);
    }
}
#undef D_00201E80

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/pad_get_connected_bss_004AC630.c): D_004B4B94 */
f32 D_004B4B94[0x1];
/* data twins (src/game/data/pad_get_connected_bss_004B4BB0.c): D_004B4BBC */
s16 D_004B4BBC[0x2];
#endif
