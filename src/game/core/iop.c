#include "m2c.h"
#include "common.h"
#include "game/core.h"
#include "game/data.h"
typedef struct { s32 next; s32 len; s32 f8; s32 dsz; } Ent;
typedef struct { s8 *src; s8 *dst; s32 len; s32 z; } Req;
#ifndef NONMATCHING
extern u8 gIopRodata_001FB770[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): gIopRodata_001FB770 */
static u8 gIopRodata_001FB770[0x1d] = "cdrom0:\\IOPRP250.IMG;1\000\000\000\000\000\000\000";
#endif
extern u8 _end[];
void Iop_LoadModulesFromArc_2_0015C9F0(s32 a0);
void Iop_Reboot_3_0015CB50(void);
s8* Arc_FindByHash_2_0015ABD0(s32);
s32 File_GetSectorOrSize_0_0015A300(s8 *);
s32* memalign(s32, s32);
void File_Close_2_0015AB80(s8 *);
void Arc_LoadFileTo_1_0015A080(s32, s32 *, s32);
s8* sceSifAllocIopHeap(s32);
void sceSifSetDma(Req *, s32);
void sceSifLoadModuleBuffer(s8 *, s32, s32);
void sceSifFreeSysMemory(s8 *);
void free(s32 *);
void sceSifInitRpc(s32);
s32 sceSifRebootIop(void *);
s32 sceSifSyncIop(void);
void sceSifInitIopHeap(void);
void sceSifLoadFileReset(void);
void sceFsReset(void);
s32* malloc(s32);

/* Iop_LoadModulesFromArc_2_0015C9F0 */
void Iop_LoadModulesFromArc_2_0015C9F0(s32 a0) {
    s32 *buf;
    s32 n;
    Ent *e;
    s32 i;
    s8 *src;
    s32 len;
    s8 *mem;
    s8 *h;
    s32 sz;
    Req r;

    h = Arc_FindByHash_2_0015ABD0(a0);
    sz = File_GetSectorOrSize_0_0015A300(h);
    buf = memalign(0x40, sz);
    File_Close_2_0015AB80(h);
    Arc_LoadFileTo_1_0015A080(a0, buf, sz);
    switch (buf[0]) {
    case 0x53585249:
        n = *(u16 *)((s8 *)buf + 0xC);
        e = (Ent *)((s8 *)buf + 0x10);
        for (i = 0; i < n; i++) {
            src = (s8 *)((s32)(e + 1) + ((e->dsz + 15) & ~15));
            len = e->len;
            mem = sceSifAllocIopHeap((len + 63) & ~63);
            r.src = src;
            r.dst = mem;
            r.len = len;
            r.z = 0;
            sceSifSetDma(&r, 1);
            sceSifLoadModuleBuffer(mem, 0, 0);
            sceSifFreeSysMemory(mem);
            e = (Ent *)((s8 *)e + e->next);
        }
        break;
    }
    free(buf);
}

/* Iop_Reboot_3_0015CB50 */
static inline s32 sub(s32 a, s32 b) { return a - b; }
static inline s32 top(void) { return (s32)func_00100000 + 0x1000; }
static inline s32 add(s32 a, s32 b) { return a + b; }

void Iop_Reboot_3_0015CB50(void) {
    s32 n;
    s32 *p;
    sceSifInitRpc(0);
    Cd_Init_2_0015B040(0x200, 1);
    while (!(sceSifRebootIop(gIopRodata_001FB770) != 0) != 0) {}
    while (!(sceSifSyncIop() != 0) != 0) {}
    sceSifInitRpc(0);
    sceSifInitIopHeap();
    sceSifLoadFileReset();
    sceFsReset();
    Cd_Init_2_0015B040(0x200, 1);
    n = sub(0x2000000, (s32)_end + top() + 0x1000) - 0x10;
    p = malloc(n);
    if (p != 0) {
        free(p);
    }
    gGameMainSbss_00201F90 = n;
}
