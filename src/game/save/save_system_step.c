#include "common.h"
#include "game/data.h"
#include "game/ee.h"
#include "game/save.h"
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0xC]; u8 name[0x20]; } E;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; s32 x20; u8 pad24[0x1C]; s8 x40[0x380]; s32 x3C0; s32 x3C4; u8 q[0x38]; } S_SaveSys_StepScan_1_001E7880;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; s32 x20; u8 pad[0x39C]; s32 x3C0; s32 x3C4; u8 q[0x38]; } S_SaveSys_StepCheckSpace_0_001E7C10;
typedef struct { s32 x0[8]; s32 n; u8 p24[0x1C]; E e[14]; u8 pad[0x40]; } S_SaveSys_ClassifyEntry_2_001E8310;
extern char gSaveSystemStepRodata_00201760[];
extern char gSaveSystemStepRodata_00201770[];
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_00201778[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_00201778 */
static char gSaveSystemStepRodata_00201778[0x8] __attribute__((aligned(4))) = "%s\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_00201780[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_00201780 */
static char gSaveSystemStepRodata_00201780[0x8] __attribute__((aligned(4))) = { 0x2f, 0x25, 0x73, 0x2f, 0x25, 0x73, 0, 0 };
#endif
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_00201788[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_00201788 */
static char gSaveSystemStepRodata_00201788[0x10] __attribute__((aligned(4))) = { 0x73, 0x74, 0x61, 0x5f, 0x61, 0x62, 0x79, 0x73, 0x73, 0x2e, 0x69, 0x63, 0x6f, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_00201798[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_00201798 */
static char gSaveSystemStepRodata_00201798[0x10] __attribute__((aligned(4))) = { 0x53, 0x59, 0x53, 0x54, 0x45, 0x4d, 0x44, 0x41, 0x54, 0x41, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_002017A8[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_002017A8 */
static char gSaveSystemStepRodata_002017A8[0x10] __attribute__((aligned(4))) = { 0x2f, 0x25, 0x73, 0x2f, 0x25, 0x73, 0x25, 0x64, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_002017B8[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_002017B8 */
static char gSaveSystemStepRodata_002017B8[0x10] __attribute__((aligned(4))) = { 0x47, 0x41, 0x4d, 0x45, 0x44, 0x41, 0x54, 0x41, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern char gSaveSystemStepRodata_002017C8[];
#else
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_002017C8 */
static char gSaveSystemStepRodata_002017C8[0x15] __attribute__((aligned(4))) = "/%s/icon.sys\000\000\000\000\000\000\000\000\000";
#endif
#ifndef NONMATCHING
extern s32 gSaveSystemStepSbss_002023B4;
#else
/* data twins (src/game/data/sbss.c): gSaveSystemStepSbss_002023B4 */
static s32 gSaveSystemStepSbss_002023B4;
#endif
#ifndef NONMATCHING
extern s32 gSaveSystemStepSbss_002023C0;
#else
/* data twins (src/game/data/sbss.c): gSaveSystemStepSbss_002023C0 */
static s32 gSaveSystemStepSbss_002023C0;
#endif
extern s32 gSaveSystemStepBss_004BC380[];
extern s32 gSaveSystemStepBss_004BC384[];
extern s32 gSaveSystemStepBss_004BC388[];
extern s32 gSaveSystemStepBss_004BC38C[];
extern s32 gSaveSystemStepBss_004BC394[];
extern s32 gSaveSystemStepBss_004BC39C[];
/* .bss, from the top down (CodeWarrior writes it in reverse) */
char D_004BCB80[0x40];
s32 D_004BC740[0x110];
s32 D_004BC3A0[0xe8];
extern u8 gSaveSystemStepBss_004BCBC0[];
extern u8 gSaveSystemStepBss_004BCF40[];
#ifndef NONMATCHING
extern s32 gSaveSystemStepSbss_002023BC;
#else
/* data twins (src/game/data/sbss.c): gSaveSystemStepSbss_002023BC */
static s32 gSaveSystemStepSbss_002023BC;
#endif
extern s32 gSaveSystemStepBss_004BC390[];
extern s32 D_004BC744[];
void SaveSys_StepScan_1_001E7880(void);
void SaveSys_StepCheckSpace_0_001E7C10(void);
void SaveSys_StepUnformat_1_001E7DF0(void);
void SaveSys_StepCheckCard_0_001E7FA0(void);
void SaveSys_ClassifyEntry_2_001E8310(s32 idx, s32 *pa, s32 *pb);
void Mc_StartFormat_2_001D6910(s32, s32);
s32 Mc_StartRead_2_001D6958(s32, s32, void *, s32, s32, void *);
s32 Mc_StartWriteChecked_1_001D69B0(s32, s32, char *, s32, u32);
void Mc_StartWrite_1_001D6A80(s32, s32, char *, void *, u32);
void Mc_StartChdir_1_001D6C60(s32, s32, char *);
s32 Mc_GetCardStatus_4_001D6E48(s32, s32);
s32 Mc_GetFreeClusters_3_001D7008(s32, s32);
s32 Mc_GetResult_1_001D7098(void);
s32 Mc_GetState_1_001D70A8(void);
s32 sprintf(char *, const char *, ...);
s32 strlen(const char *);
s32 strncmp(void *, const char*, s32);
s32 Mc_StartReadChecked_1_001D6A18(u32 a, u32 b, s32 c, s32 d, s32 e);
void sceMcSync(s32, s32, s32 *);
void sceMcUnformat(s32, s32);
void Mc_StartCheck_1_001D6BB8(s32, s32);
s32 strcmp(const char *, const char *);

/* SaveSys_StepSave_2_001E64E0 */
/* SaveSys_StepSave_2_001E64E0 */
#define SaveSys_ClassifyEntry_2_001E8310 SaveSys_ClassifyEntry_2_001E8310__as_SaveSys_StepSave_2_001E64E0
void SaveSys_ClassifyEntry_2_001E8310__as_SaveSys_StepSave_2_001E64E0(s32, void *, void *);


#define FAIL() { gSaveSystemStepSbss_002023D8 = -1; gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 1; }

static inline s32 chk(s32 r) {
    s32 s = gSaveSystemStepSbss_002023D8;
    if (r != 0) {
        if (!(++gSaveSystemStepSbss_002023B4 < 5)) return 2;
        return 1;
    }
    gSaveSystemStepSbss_002023D8 = s + 1;
    gSaveSystemStepSbss_002023B4 = 0;
    return 0;
}

static inline void clean(void) {
    s32 len;
    s32 d;
    s32 i;
    s32 n;
    E *e;
    d = gSaveSystemStepSbss_002023D4;
    e = (E *)((u8 *)&gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4 << 8] + 0x40);
    n = D_004BC3A0[gSaveSystemStepSbss_002023E4 << 8];
    for (i = 2; i < n; i++) {
        s32 c;
        len = strlen(gSaveSystemStepRodata_002017B8);
        if (strncmp(e[i].name, gSaveSystemStepRodata_002017B8, len) == 0) {
            c = e[i].name[len] - '0';
            if (c == d) e[i].x10 = 0;
        }
    }
    SaveSys_ClassifyEntry_2_001E8310(gSaveSystemStepSbss_002023E4, (u8 *)&gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4 << 8] + 0x3C0, (u8 *)&gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4 << 8] + 0x3C4);
}

void SaveSys_StepSave_2_001E64E0(s32 arg0) {
    s32 r;
    s32 e;
    s32 r2;
    s32 f, f4;

    switch (gSaveSystemStepSbss_002023D8) {
    case 0:
        Mc_StartFormat_2_001D6910(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 1:
        r = Mc_GetCardStatus_4_001D6E48(gSaveSystemStepSbss_002023E4, 0);
        if (r < 0) {
            gSaveSystemStepBss_004BC384[gSaveSystemStepSbss_002023E4 << 8] = 0;
            gSaveSystemStepBss_004BC388[gSaveSystemStepSbss_002023E4 << 8] = 0;
        } else if (r == 2) {
            gSaveSystemStepBss_004BC384[gSaveSystemStepSbss_002023E4 << 8] = 1;
            gSaveSystemStepBss_004BC388[gSaveSystemStepSbss_002023E4 << 8] = 0;
        }
        if (r == 0) {
            gSaveSystemStepBss_004BC384[gSaveSystemStepSbss_002023E4 << 8] = 1;
            r2 = Mc_GetState_1_001D70A8();
            gSaveSystemStepBss_004BC388[gSaveSystemStepSbss_002023E4 << 8] = 1;
            switch (r2) {
            case 3:
                gSaveSystemStepBss_004BC388[gSaveSystemStepSbss_002023E4 << 8] = 0;
                break;
            }
        } else {
            gSaveSystemStepBss_004BC384[gSaveSystemStepSbss_002023E4 << 8] = 0;
            gSaveSystemStepBss_004BC388[gSaveSystemStepSbss_002023E4 << 8] = 0;
        }
        e = *(volatile s32 *)&gSaveSystemStepSbss_002023E4 << 8;
        gSaveSystemStepBss_004BC394[e] = Mc_GetFreeClusters_3_001D7008(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepBss_004BC380[e] = 1;
        if (gSaveSystemStepBss_004BC388[e] == 0) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[e] = 1;
            return;
        }
        gSaveSystemStepSbss_002023D8++;
        break;
    case 2:
        if (chk(Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, gSaveSystemStepRodata_00201760, 0, 0xE, gSaveSystemStepBss_004BCBC0)) == 2) {
            FAIL();
            return;
        }
        break;
    case 3:
        r = Mc_GetResult_1_001D7098() > 0;
        gSaveSystemStepBss_004BC38C[gSaveSystemStepSbss_002023E4 << 8] = r;
        if (r) {
            sprintf(D_004BCB80, gSaveSystemStepRodata_00201770, gSaveSystemStepRodata_00201760);
            gSaveSystemStepSbss_002023D8 = 8;
        } else {
            sprintf(D_004BCB80, gSaveSystemStepRodata_00201778, gSaveSystemStepRodata_00201760);
            Mc_StartChdir_1_001D6C60(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80);
            gSaveSystemStepSbss_002023D8++;
        }
        break;
    case 4:
        if (Mc_GetState_1_001D70A8() == 0x64) {
            FAIL();
            return;
        }
        if (arg0 != 0) {
            FAIL();
            return;
        }
        gSaveSystemStepBss_004BC38C[gSaveSystemStepSbss_002023E4 << 8] = 1;
        sprintf(D_004BCB80, gSaveSystemStepRodata_00201770, gSaveSystemStepRodata_00201760);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 5:
        if (chk(Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, 0, 0xE, (u8 *)&gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4 << 8] + 0x40)) == 2) {
            FAIL();
            return;
        }
        break;
    case 6:
        if (Mc_GetState_1_001D70A8() == 0x64) {
            FAIL();
            return;
        }
        if (arg0 != 0) {
            FAIL();
            return;
        }
        e = gSaveSystemStepSbss_002023E4;
        D_004BC3A0[e << 8] = Mc_GetResult_1_001D7098();
        SaveSys_ClassifyEntry_2_001E8310(e, &gSaveSystemStepSbss_002023C0, (u8 *)&gSaveSystemStepBss_004BC380[e << 8] + 0x3C4);
        D_004BC740[gSaveSystemStepSbss_002023E4 << 8] = gSaveSystemStepSbss_002023C0;
        gSaveSystemStepSbss_002023D8++;
    case 7:
        f4 = gSaveSystemStepSbss_002023C0 & 4;
        if (!(gSaveSystemStepSbss_002023C0 & 1)) {
            sprintf(D_004BCB80, gSaveSystemStepRodata_00201780, gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_00201760);
            Mc_StartWriteChecked_1_001D69B0(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, 0, 0);
            while (0 < (r = Mc_Update_4_001D6D00())) {}
            if (r < 0) {
                FAIL();
                return;
            }
            gSaveSystemStepSbss_002023C0 |= 1;
            return;
        }
        if (!f4) {
            sprintf(D_004BCB80, gSaveSystemStepRodata_00201780, gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_00201788);
            Mc_StartWrite_1_001D6A80(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, (void *)gSaveSystemStepSbss_002023C8, gSaveSystemStepSbss_002023C4);
            while (0 < (r = Mc_Update_4_001D6D00())) {}
            if (r < 0) {
                FAIL();
                return;
            }
            gSaveSystemStepSbss_002023C0 |= 4;
            return;
        }
        gSaveSystemStepSbss_002023D8++;
        break;
    case 8:
        if (gSaveSystemStepSbss_002023D4 < 0) {
            sprintf(D_004BCB80, gSaveSystemStepRodata_00201780, gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_00201798, gSaveSystemStepSbss_002023D4);
        } else {
            sprintf(D_004BCB80, gSaveSystemStepRodata_002017A8, gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_002017B8, gSaveSystemStepSbss_002023D4);
        }
        gSaveSystemStepSbss_002023D8++;
    case 9:
        if (chk(Mc_StartWriteChecked_1_001D69B0(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, gSaveSystemStartSbss_002023D0, gSaveSystemStartSbss_002023CC)) == 2) {
            FAIL();
            return;
        }
        break;
    case 10:
        r = Mc_GetState_1_001D70A8();
        if (r != 0x3E) {
            FAIL();
        }
        if (r == 0x64) {
            clean();
            FAIL();
            return;
        }
        if (arg0 != 0) {
            clean();
            FAIL();
            return;
        }
        sprintf(D_004BCB80, gSaveSystemStepRodata_00201770, gSaveSystemStepRodata_00201760);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 11:
        if (chk(Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, 0, 0xE, (u8 *)&gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4 << 8] + 0x40)) == 2) {
            FAIL();
            return;
        }
        break;
    case 12:
        if (!(gSaveSystemStepSbss_002023C0 & 2)) {
            sprintf(D_004BCB80, gSaveSystemStepRodata_002017C8, gSaveSystemStepRodata_00201760);
            Mc_StartWrite_1_001D6A80(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, gSaveSystemStepBss_004BCF40, 0x3C4);
            while (0 < (r = Mc_Update_4_001D6D00())) {}
            if (r < 0) {
                FAIL();
                return;
            }
            gSaveSystemStepSbss_002023C0 |= 2;
            return;
        }
        gSaveSystemStepSbss_002023D8++;
        break;
    case 13:
        f = Mc_GetState_1_001D70A8();
        e = gSaveSystemStepSbss_002023E4;
        gSaveSystemStepBss_004BC394[e << 8] = Mc_GetFreeClusters_3_001D7008(e, gSaveSystemStepSbss_002023E0);
        D_004BC3A0[e << 8] = Mc_GetResult_1_001D7098();
        SaveSys_ClassifyEntry_2_001E8310(e, (u8 *)&gSaveSystemStepBss_004BC380[e << 8] + 0x3C0, (u8 *)&gSaveSystemStepBss_004BC380[e << 8] + 0x3C4);
        if (f == 0x64) {
            clean();
            FAIL();
            return;
        }
        if (arg0 != 0) {
            clean();
            FAIL();
            return;
        }
        gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 0;
        gSaveSystemStepSbss_002023D8 = -1;
        break;
    }
}

/* SaveSys_StepLoad_2_001E72A0 */
void SaveSys_ClassifyEntry_2_001E8310__as_SaveSys_StepSave_2_001E64E0(s32, void *, void *);

static inline s32 retry(s32 r) {
    s32 s = gSaveSystemStepSbss_002023D8;
    if (r != 0) {
        if (++gSaveSystemStepSbss_002023B4 >= 5) {
            return 2;
        }
        return 1;
    }
    gSaveSystemStepSbss_002023D8 = s + 1;
    gSaveSystemStepSbss_002023B4 = 0;
    return 0;
}

void SaveSys_StepLoad_2_001E72A0(s32 arg0) {
    s32 r;
    s32 t;
    s32 i;

    switch (gSaveSystemStepSbss_002023D8) {
    case 0:
        Mc_StartFormat_2_001D6910(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 1:
        r = Mc_GetCardStatus_4_001D6E48(gSaveSystemStepSbss_002023E4, 0);
        if (r < 0) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 0;
            gSaveSystemStepBss_004BC388[t] = 0;
        } else if (r == 2) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 1;
            gSaveSystemStepBss_004BC388[t] = 0;
        }
        if (r == 0) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 1;
            gSaveSystemStepBss_004BC388[t] = 1;
        } else {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 0;
            gSaveSystemStepBss_004BC388[t] = 0;
        }
        gSaveSystemStepBss_004BC394[t] = Mc_GetFreeClusters_3_001D7008(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepBss_004BC380[t] = 1;
        if (*(s32 *)((s32)gSaveSystemStepBss_004BC388 + t * 4) == 0) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[t] = 1;
        } else {
            gSaveSystemStepSbss_002023D8++;
        }
        break;
    case 2:
        if (retry(Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, gSaveSystemStepRodata_00201760, 0, 0xE, gSaveSystemStepBss_004BCBC0)) == 2) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 1;
        }
        break;
    case 3:
        r = Mc_GetResult_1_001D7098() > 0;
        gSaveSystemStepBss_004BC38C[gSaveSystemStepSbss_002023E4 << 8] = r;
        sprintf(D_004BCB80, gSaveSystemStepRodata_00201770, gSaveSystemStepRodata_00201760, r);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 4:
        if (retry(Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, 0, 0xE, (s32 *)((s32)&gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4 << 8] + 0x40))) == 2) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 1;
        }
        break;
    case 5:
        Mc_GetState_1_001D70A8();
        i = gSaveSystemStepSbss_002023E4;
        t = i << 8;
        D_004BC3A0[t] = Mc_GetResult_1_001D7098();
        SaveSys_ClassifyEntry_2_001E8310(i, &gSaveSystemStepSbss_002023BC, (s32 *)((s32)&gSaveSystemStepBss_004BC380[t] + 0x3C4));
        t = gSaveSystemStepSbss_002023E4 << 8;
        D_004BC740[t] = gSaveSystemStepSbss_002023BC;
        if ((gSaveSystemStepSbss_002023D4 < 0 ? (gSaveSystemStepSbss_002023BC & 8) != 0 : (gSaveSystemStepSbss_002023BC & (1 << (gSaveSystemStepSbss_002023D4 + 4))) != 0) == 0) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[t] = 1;
            break;
        }
        if (gSaveSystemStepSbss_002023D4 < 0) {
            sprintf(D_004BCB80, gSaveSystemStepRodata_00201780, gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_00201798, gSaveSystemStepSbss_002023D4);
        } else {
            sprintf(D_004BCB80, gSaveSystemStepRodata_002017A8, gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_002017B8, gSaveSystemStepSbss_002023D4);
        }
        gSaveSystemStepSbss_002023D8++;
        break;
    case 6:
        r = *(volatile s32 *)&gSaveSystemStartSbss_002023CC;
        if (retry(Mc_StartReadChecked_1_001D6A18(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, (s32)D_004BCB80, gSaveSystemStartSbss_002023D0, r)) == 2) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 1;
        }
        break;
    case 7:
        r = Mc_GetState_1_001D70A8();
        if (r == 0x64) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 1;
        } else if (r == 1) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 0;
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[t] = 1;
        } else if (arg0 != 0) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 1;
        } else {
            gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 << 8] = 0;
            gSaveSystemStepSbss_002023D8 = -1;
        }
        break;
    }
}
#undef SaveSys_ClassifyEntry_2_001E8310

/* SaveSys_StepScan_1_001E7880 */
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_StepScan_1_001E7880
extern S_SaveSys_StepScan_1_001E7880 gSaveSystemStepBss_004BC380__as_SaveSys_StepScan_1_001E7880[];
#define gSaveSystemStepRodata_00201760 gSaveSystemStepRodata_00201760__as_SaveSys_StepScan_1_001E7880
extern s8 gSaveSystemStepRodata_00201760__as_SaveSys_StepScan_1_001E7880[];
#define gSaveSystemStepRodata_00201770 gSaveSystemStepRodata_00201770__as_SaveSys_StepScan_1_001E7880
extern s8 gSaveSystemStepRodata_00201770__as_SaveSys_StepScan_1_001E7880[];
#define D_004BCB80 D_004BCB80__as_SaveSys_StepScan_1_001E7880
extern s8 D_004BCB80__as_SaveSys_StepScan_1_001E7880[];
#define sprintf sprintf__as_SaveSys_StepScan_1_001E7880
void sprintf__as_SaveSys_StepScan_1_001E7880(s8 *, s8 *, s8 *);

void SaveSys_StepScan_1_001E7880(void) {
    s32 r; s32 c;

    switch (gSaveSystemStepSbss_002023D8) {
    case 0:
        Mc_StartFormat_2_001D6910(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 1:
        r = Mc_GetState_1_001D70A8();
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 = 1;
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 = 1;
        switch (r) {
        case 3:
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 = 0;
        }
        r = Mc_GetCardStatus_4_001D6E48(gSaveSystemStepSbss_002023E4, 0);
        if (r < 0) {
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 = 0;
        } else if (r == 2) {
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x4 = 1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 = 0;
        }
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x14 = Mc_GetFreeClusters_3_001D7008(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x0 = 1;
        if (gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x8 == 0) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 1;
            break;
        }
        Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, gSaveSystemStepRodata_00201760, 0, 0xE, gSaveSystemStepBss_004BCBC0);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 2:
        if (Mc_GetState_1_001D70A8() == 0x64) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 1;
            break;
        }
        c = Mc_GetResult_1_001D7098() > 0; gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].xC = c;
        if (c == 0) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x10 = 1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 0;
            break;
        }
        sprintf(D_004BCB80, gSaveSystemStepRodata_00201770, gSaveSystemStepRodata_00201760);
        Mc_StartRead_2_001D6958(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0, D_004BCB80, 0, 0xE, gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x40);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 3:
        if (Mc_GetState_1_001D70A8() == 0x64) {
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 1;
            break;
        }
        r = Mc_GetResult_1_001D7098();
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x20 = r;
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x10 = 1;
        SaveSys_ClassifyEntry_2_001E8310(gSaveSystemStepSbss_002023E4, &gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x3C0, &gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x3C4);
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E4].x1C = 0;
        gSaveSystemStepSbss_002023D8 = -1;
        break;
    }
}
#undef sprintf
#undef gSaveSystemStepBss_004BC380
#undef gSaveSystemStepRodata_00201760
#undef gSaveSystemStepRodata_00201770
#undef D_004BCB80

/* SaveSys_StepCheckSpace_0_001E7C10 */
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_StepCheckSpace_0_001E7C10
extern S_SaveSys_StepCheckSpace_0_001E7C10 gSaveSystemStepBss_004BC380__as_SaveSys_StepCheckSpace_0_001E7C10[];
void SaveSys_StepCheckSpace_0_001E7C10(void) {
    s32 r;

    switch (gSaveSystemStepSbss_002023D8) {
    case 0:
        Mc_StartFormat_2_001D6910(gSaveSystemStepSbss_002023E8, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8++;
        break;
    case 1:
        r = Mc_GetState_1_001D70A8();
        if (r == 1) {
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x4 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x8 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x10 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x20 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x3C0 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x3C4 = 0;
        } else if (r == 3 || r == 4 || r == 0x15) {
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x4 = 1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x8 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x10 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x20 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x3C0 = 0;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x3C4 = 0;
        } else {
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x4 = 1;
            gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x8 = 1;
        }
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x14 = Mc_GetFreeClusters_3_001D7008(gSaveSystemStepSbss_002023E8, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepBss_004BC380[gSaveSystemStepSbss_002023E8].x0 = 1;
        gSaveSystemStepSbss_002023D8 = -1;
        gSaveSystemStepSbss_002023E8 = !(gSaveSystemStepSbss_002023E8 != 0);
        break;
    }
}
#undef gSaveSystemStepBss_004BC380

/* SaveSys_StepUnformat_1_001E7DF0 */
void SaveSys_StepUnformat_1_001E7DF0(void) {
    s32 sp1C;
    s32 temp_11;
    s32 temp_12;

    switch (gSaveSystemStepSbss_002023D8) {                           /* irregular */
    case 0:
        Mc_StartFormat_2_001D6910(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8 += 1;
        break;
    case 1:
        sp1C = Mc_GetCardStatus_4_001D6E48(gSaveSystemStepSbss_002023E4, 0);
        if (sp1C < 0) {
            temp_11 = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[temp_11] = 0;
            gSaveSystemStepBss_004BC388[temp_11] = 0;
            gSaveSystemStepBss_004BC380[temp_11] = 0;
            gSaveSystemStepBss_004BC390[temp_11] = 0;
            gSaveSystemStepBss_004BC394[temp_11] = -1;
            gSaveSystemStepBss_004BC39C[temp_11] = 1;
            gSaveSystemStepSbss_002023D8 = -1;
            break;
        }
        sceMcUnformat(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        sceMcSync(0, 0, &sp1C);
        gSaveSystemStepSbss_002023D8 += 1;
        break;
    case 2:
        temp_12 = gSaveSystemStepSbss_002023E4 << 8;
        gSaveSystemStepBss_004BC384[temp_12] = 1;
        gSaveSystemStepBss_004BC388[temp_12] = 0;
        gSaveSystemStepBss_004BC390[temp_12] = 0;
        D_004BC3A0[temp_12] = 0;
        D_004BC740[temp_12] = 0;
        D_004BC744[temp_12] = 0;
        gSaveSystemStepBss_004BC39C[temp_12] = 0;
        gSaveSystemStepSbss_002023D8 = -1;
        break;
    }
}

/* SaveSys_StepCheckCard_0_001E7FA0 */
void SaveSys_StepCheckCard_0_001E7FA0(void) {
    s32 r;
    s32 t;

    switch (gSaveSystemStepSbss_002023D8) {
    case 0:
        Mc_StartFormat_2_001D6910(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8 += 1;
        break;
    case 1:
        switch (Mc_GetState_1_001D70A8()) {
        case 3:
            if (++gSaveSystemStepSbss_002023B4 >= 5) { gSaveSystemStepSbss_002023B4 = 0; gSaveSystemStepSbss_002023D8 += 1; }
            break;
        default:
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 0;
            gSaveSystemStepBss_004BC388[t] = 0;
            gSaveSystemStepBss_004BC380[t] = 0;
            gSaveSystemStepBss_004BC390[t] = 0;
            gSaveSystemStepBss_004BC394[t] = -1;
            gSaveSystemStepBss_004BC39C[t] = 1;
            gSaveSystemStepSbss_002023D8 = -1;
            break;
        }
        break;
    case 2:
        if (Mc_GetCardStatus_4_001D6E48(gSaveSystemStepSbss_002023E4, 0) < 0) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC384[t] = 0;
            gSaveSystemStepBss_004BC388[t] = 0;
            gSaveSystemStepBss_004BC380[t] = 0;
            gSaveSystemStepBss_004BC390[t] = 0;
            gSaveSystemStepBss_004BC394[t] = -1;
            gSaveSystemStepBss_004BC39C[t] = 1;
            gSaveSystemStepSbss_002023D8 = -1;
            break;
        }
        Mc_StartCheck_1_001D6BB8(gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E0);
        gSaveSystemStepSbss_002023D8 += 1;
        break;
    case 3:
        r = Mc_GetState_1_001D70A8();
        if (r == 0x32) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC388[t] = 0;
            gSaveSystemStepSbss_002023D8 = -1;
            gSaveSystemStepBss_004BC39C[t] = 1;
        } else if (r != 0x33) {
            t = gSaveSystemStepSbss_002023E4 << 8;
            gSaveSystemStepBss_004BC380[t] = 1;
            gSaveSystemStepBss_004BC384[t] = 1;
            gSaveSystemStepBss_004BC388[t] = 1;
            gSaveSystemStepBss_004BC38C[t] = 0;
            gSaveSystemStepBss_004BC390[t] = 1;
            gSaveSystemStepBss_004BC39C[t] = 0;
            D_004BC3A0[t] = 0;
            D_004BC740[t] = 0;
            D_004BC744[t] = 0;
            gSaveSystemStepSbss_002023D8 = -1;
        }
        break;
    }
}

/* SaveSys_GetPort_1_001E8290 */
s32 SaveSys_GetPort_1_001E8290(void) {
    return gSaveSystemStepSbss_002023E4;
}

/* SaveSys_SetPort_1_001E82A0 */
s32 SaveSys_SetPort_1_001E82A0(s32 a) {
    volatile s32 t;
    if (a < 0 || a > 1) return 0;
    t = gSaveSystemStepBss_004BC39C[gSaveSystemStepSbss_002023E4 * 256];
    if (t == 2) return 0;
    gSaveSystemStepSbss_002023E4 = a;
    return 1;
}

/* SaveSys_ClassifyEntry_2_001E8310 */
#pragma explicit_zero_data on
const char D_00201840[0x9] = "icon.sys\000";
#define gSaveSystemStepBss_004BC380 gSaveSystemStepBss_004BC380__as_SaveSys_ClassifyEntry_2_001E8310
extern S_SaveSys_ClassifyEntry_2_001E8310 gSaveSystemStepBss_004BC380__as_SaveSys_ClassifyEntry_2_001E8310[];

void SaveSys_ClassifyEntry_2_001E8310(s32 idx, s32 *pa, s32 *pb) {
    s32 n;
    s32 i;
    s32 a;
    s32 b;
    s32 len;
    s32 z;
    s32 c;
    i = 2;
    a = 0;
    n = gSaveSystemStepBss_004BC380[idx].n;
    b = 0;
    for (; i < n; i++) {
        z = gSaveSystemStepBss_004BC380[idx].e[i].x10 == 0;
        if (strcmp((char *)gSaveSystemStepBss_004BC380[idx].e[i].name, gSaveSystemStepRodata_00201760) == 0) a |= 1;
        if (strcmp((char *)gSaveSystemStepBss_004BC380[idx].e[i].name, D_00201840) == 0) { if (z) b |= 2; else a |= 2; }
        if (strcmp((char *)gSaveSystemStepBss_004BC380[idx].e[i].name, gSaveSystemStepRodata_00201788) == 0) { if (z) b |= 4; else a |= 4; }
        if (strcmp((char *)gSaveSystemStepBss_004BC380[idx].e[i].name, gSaveSystemStepRodata_00201798) == 0) { if (z) b |= 8; else a |= 8; }
        len = strlen(gSaveSystemStepRodata_002017B8);
        if (strncmp((char *)gSaveSystemStepBss_004BC380[idx].e[i].name, gSaveSystemStepRodata_002017B8, len) == 0) {
            c = gSaveSystemStepBss_004BC380[idx].e[i].name[len] - '0';
            if (z) b |= 1 << (c + 4); else a |= 1 << (c + 4);
        }
    }
    if (pa != NULL) *pa = a;
    if (pb != NULL) *pb = b;
}
#undef gSaveSystemStepBss_004BC380

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gSaveSystemStepSbss_002023C4, gSaveSystemStepSbss_002023C8, gSaveSystemStepSbss_002023D4, gSaveSystemStepSbss_002023D8, gSaveSystemStepSbss_002023E0, gSaveSystemStepSbss_002023E4, gSaveSystemStepSbss_002023E8 */
s32 gSaveSystemStepSbss_002023C4;
s32 gSaveSystemStepSbss_002023C8;
s32 gSaveSystemStepSbss_002023D4;
s32 gSaveSystemStepSbss_002023D8;
s32 gSaveSystemStepSbss_002023E0;
s32 gSaveSystemStepSbss_002023E4;
s32 gSaveSystemStepSbss_002023E8;
/* data twins (src/game/data/save_system_start_bss_004BCBC0.c): gSaveSystemStepBss_004BCBC0, gSaveSystemStepBss_004BCF40 */
u8 gSaveSystemStepBss_004BCBC0[0x380];
u8 gSaveSystemStepBss_004BCF40[0x3d0];
#endif


#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/save_system_step_rodata.c): gSaveSystemStepRodata_00201760, gSaveSystemStepRodata_00201770 */
char gSaveSystemStepRodata_00201760[0x10] __attribute__((aligned(4))) = { 0x42, 0x49, 0x53, 0x4c, 0x50, 0x53, 0x2d, 0x32, 0x35, 0x32, 0x31, 0x37, 0, 0, 0, 0 };
char gSaveSystemStepRodata_00201770[0x8] __attribute__((aligned(4))) = { 0x2f, 0x25, 0x73, 0x2f, 0x2a, 0, 0, 0 };
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/save_system_start_bss.c): D_004BC360__grp: gSaveSystemStepBss_004BC360@0x0, gSaveSystemStepBss_004BC380@0x20, gSaveSystemStepBss_004BC384@0x24, gSaveSystemStepBss_004BC388@0x28, gSaveSystemStepBss_004BC38C@0x2c, gSaveSystemStepBss_004BC390@0x30, gSaveSystemStepBss_004BC394@0x34, gSaveSystemStepBss_004BC398@0x38, gSaveSystemStepBss_004BC39C@0x3c */
u8 D_004BC360__grp[0x40] __attribute__((aligned(16)));
#endif
