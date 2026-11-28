/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/EnemyMgr_Update_0_001A4990.c. */
#include "include_asm.h"

#ifdef NONMATCHING
#include "m2c.h"
typedef struct { u8 pad[0x14]; s32 x14; u8 b0:1; u8 b1:1; u8 r:6; } A;
typedef struct { volatile s32 id; volatile s32 x4; volatile s32 h8; volatile s32 cnt; volatile s32 x10; volatile s32 x14; s32 * volatile x18; volatile s32 x1C; volatile s32 x20; s32 pad; } S;
typedef struct { u8 pad[0xC]; s32 xC; u8 pad10[0x590]; u16 b0:1; u16 b1:1; u16 b2:1; u16 b:8; } B;
typedef struct { u8 a:3; u8 f:3; u8 c:2; } F3b;
extern A *D_00202278;
extern s32 D_00201DA8;
extern S D_004A43B0[];
typedef struct { volatile s32 v; s8 pad[0x24]; } E;
extern E D_004A43B8[];
extern F3b D_00222A54[];
extern u8 D_00270F40[];
B **ActorList_FindFree_0_001A55E0(void);
B **ActorList_AllocSlot_0_001A5530(void);
void EnemyData_ParseWrap_0_001A7C60(B **, s32);
void Enemy_Spawn_0_001A7420(B **);
void EnemyData_GetFile_2_001A7D00(s32, u8 *, s32 *);
s32 *Pool_Alloc_3_001288C0(A *, s32);
s32 Task_SetPriorityWrap_0_0014DB00(u8 *, s32, u8 *);
s32 Obj_FreeTimer_0_0014DA70(s32);
void Task_FlushWrap_0_0014DAC0(s32, s32);
u8 Task_KillWrap_0_0014DAF0(s32);
void FlushCache(s32);
void Dma_SprCopy_1_001789E0(s32, u8 *, s32);
void memcpy(s32, u8 *, s32);
void Task_RemoveWrap_0_0014DAE0(s32);
s32 Obj_SetTimerEx_0_0014DA90(s32, s32, s32, s32);
s32 Obj_SetTimer_0_0014DA80(s32, s32);
s32 EnemyData_LoadTextures_0_001A7C70(s32 *);
void Task_RunWrap_0_0014DAB0(s32);

static inline void link(s32 j) {
    B **n;
    B *b;
    u32 k;
    n = ActorList_FindFree_0_001A55E0();
    while (n != NULL) {
        b = *n;
        k = b->b;
        if (!b->b1) {
            n = ActorList_AllocSlot_0_001A5530();
            continue;
        }
        if (k - 1 == j) {
            b->xC = (s32)D_004A43B0[j].x18;
            D_004A43B0[j].cnt++;
            EnemyData_ParseWrap_0_001A7C60(n, D_004A43B0[j].x1C);
            Enemy_Spawn_0_001A7420(n);
        }
        n = ActorList_AllocSlot_0_001A5530();
    }
}

void EnemyMgr_Update_0_001A4990(void) {
    u8 buf[0x100];
    s32 i;
    B **n;
    S *e;
    B *b;
    u32 k;
    s32 *h;
    s32 p;

    if (D_00202278 == NULL) return;
    if (D_00202278->b1 && D_00202278->x14 != 0) return;
    if (D_00201DA8 == -1) {
        for (i = 0; i < 11; i++) {
            e = &D_004A43B0[i];
            if (e->id != -1 && e->x4 != 0) {
                n = ActorList_FindFree_0_001A55E0();
                while (n != NULL) {
                    b = *n;
                    k = b->b;
                    if (!b->b1) {
                        n = ActorList_AllocSlot_0_001A5530();
                        continue;
                    }
                    if (k - 1 == i) {
                        b->xC = (s32)e->x18;
                        e->cnt++;
                        EnemyData_ParseWrap_0_001A7C60(n, e->x1C);
                        Enemy_Spawn_0_001A7420(n);
                    }
                    n = ActorList_AllocSlot_0_001A5530();
                }
            }
        }
    }
    if (D_00201DA8 == -1) {
        for (i = 0; i < 11; i++) {
            e = &D_004A43B0[i];
            if (e->id != -1 && e->x4 == 0) {
                D_00201DA8 = i;
                break;
            }
        }
        if (D_00201DA8 == -1) return;
        EnemyData_GetFile_2_001A7D00(D_004A43B0[D_00201DA8].id, buf, (s32 *)&D_004A43B0[D_00201DA8].x10);
        D_004A43B0[D_00201DA8].x18 = Pool_Alloc_3_001288C0(D_00202278, D_004A43B0[D_00201DA8].x10);
        D_004A43B0[D_00201DA8].x1C = 0;
        D_004A43B0[D_00201DA8].x14 = 0;
        h = (s32 *)&D_004A43B8[*(volatile s32 *)&D_00201DA8].v;
        *h = Task_SetPriorityWrap_0_0014DB00(buf, 0x101, D_00270F40);
        D_004A43B0[D_00201DA8].x14 = Obj_FreeTimer_0_0014DA70(*h);
        Task_FlushWrap_0_0014DAC0(D_004A43B0[D_00201DA8].h8, 0);
        return;
    }
    switch (Task_KillWrap_0_0014DAF0(D_004A43B0[D_00201DA8].h8)) {
    case 0:
        break;
    case 5: {
        s32 q;
        s32 sz;
        s32 o;
        s32 r;
        sz = (u32)(D_004A43B0[D_00201DA8].x10 - D_004A43B0[D_00201DA8].x14) > 0x80000 ? 0x80000 : D_004A43B0[D_00201DA8].x10 - D_004A43B0[D_00201DA8].x14;
        q = sz >> 4;
        o = q << 4;
        r = sz - o;
        FlushCache(0);
        Dma_SprCopy_1_001789E0(*D_004A43B0[D_00201DA8].x18 + D_004A43B0[D_00201DA8].x14, D_00270F40, q);
        if (r > 0) {
            memcpy(*D_004A43B0[D_00201DA8].x18 + D_004A43B0[D_00201DA8].x14 + o, D_00270F40 + o, r);
        }
        D_004A43B0[D_00201DA8].x14 += sz;
        Task_RemoveWrap_0_0014DAE0(D_004A43B0[D_00201DA8].h8);
        break;
    }
    case 3:
    case 6:
        if (D_004A43B0[D_00201DA8].x4 != 0) break;
        p = *D_004A43B0[D_00201DA8].x18;
        if (D_004A43B0[D_00201DA8].x20 == 0 && Obj_SetTimerEx_0_0014DA90(D_004A43B0[D_00201DA8].h8, p, p, D_004A43B0[D_00201DA8].x10)) {
            D_004A43B0[D_00201DA8].x20 = 1;
        }
        if (D_004A43B0[D_00201DA8].x20 != 0 && Obj_SetTimer_0_0014DA80(D_004A43B0[D_00201DA8].h8, 4)) break;
        i = D_00201DA8;
        D_004A43B0[i].x20 = 0;
        D_004A43B0[i].x1C = EnemyData_LoadTextures_0_001A7C70(D_004A43B0[i].x18);
        link(i);
        D_004A43B0[D_00201DA8].x4 = 1;
        if (D_004A43B0[D_00201DA8].cnt <= 0) D_004A43B0[D_00201DA8].id = -1;
        if (D_00201DA8 != -1 && D_004A43B0[D_00201DA8].h8 != 0) {
            Task_RunWrap_0_0014DAB0(D_004A43B0[D_00201DA8].h8);
            D_004A43B0[D_00201DA8].h8 = 0;
        }
        D_00201DA8 = -1;
        break;
    case 1:
    case 2:
    case 4:
        D_00222A54[0].f = 2;
        break;
    }
}
#else
INCLUDE_ASM(EnemyMgr_Update_0_001A4990);
#endif
