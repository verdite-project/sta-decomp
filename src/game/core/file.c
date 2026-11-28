#include "m2c.h"
#include "common.h"
#include "game/core.h"
typedef struct { s32 x0; u32 x4; u32 x8; u32 xC; } Inf;
typedef struct { s32 x0; s32 x4; s32 x8; Inf *pC; volatile u16 flags; u16 mode; s32 fd; u32 size; } F;
typedef struct { s32 x0; volatile u32 x4; s32 x8; s32 xC; u16 flags; s32 fd; s32 size; } F_File_Read_2_0015A470;
typedef struct { s32 x0; char p4[0x10]; s32 fd; s32 x18; } F_File_Close_2_0015AB80;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u16 flags; s16 x12; s32 fd; s32 size; } F_Arc_FindByHash_2_0015ABD0;
typedef struct { u8 c[4]; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; } E;
typedef struct { s32 a, b, n, c; E e[1]; } T;
typedef struct { s32 x0; volatile s32 x4; s32 x8; s32 xC; u16 flags; s32 fd; s32 size; } F_Arc_Mount_2_0015AD00;
#ifndef NONMATCHING
extern s32 D_00201F88;
#else
/* data twins (src/game/data/sbss.c): D_00201F88 */
static s32 D_00201F88;
#endif
extern s8 *D_00201F80;
#ifndef NONMATCHING
extern s32 D_00201F8C;
#else
/* data twins (src/game/data/sbss.c): D_00201F8C */
static s32 D_00201F8C;
#endif
extern F_File_Read_2_0015A470 *D_00201F80__as_File_Read_2_0015A470;
#ifndef NONMATCHING
extern s32 D_00201C7C;
#else
/* data twins (src/game/data/sdata.c): D_00201C7C */
static s32 D_00201C7C = 3;
#endif
extern T D_002F20C0;
extern s32 D_002F20C8[];
extern F_Arc_FindByHash_2_0015ABD0 D_0030A0D0[];
#ifndef NONMATCHING
extern s8 D_001FB740[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): D_001FB740 */
static s8 D_001FB740[0x7] = "%s%s%s\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FB748[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): D_001FB748 */
static s8 D_001FB748[0x7] = "host0:\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FB750[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): D_001FB750 */
static s8 D_001FB750[0x8] = "S:/STA/\000";
#endif
#ifndef NONMATCHING
extern s8 D_001FB758[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): D_001FB758 */
static s8 D_001FB758[0x8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#ifndef NONMATCHING
extern s8 D_001FB760[];
#else
/* data twins (src/game/data/fx_proc_rodata.c): D_001FB760 */
static s8 D_001FB760[0x10] = ";1\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
#endif
/* .bss, from the top down (CodeWarrior writes it in reverse) */
s32 D_002F20C4[0x6003] __attribute__((aligned(4)));
extern F_Arc_Mount_2_0015AD00 *D_00201F80__as_Arc_Mount_2_0015AD00;
extern s8 D_002F20C0__as_Arc_Mount_2_0015AD00[];
extern F_Arc_Mount_2_0015AD00 D_0030A0D0__as_Arc_Mount_2_0015AD00[];
void Arc_LoadFileTo_1_0015A080(s32 arg0, u8 *arg1);
void File_GetSize_1_0015A2F0(void *arg0, s32 *arg1);
s32 File_GetSectorOrSize_0_0015A300(void *arg0);
s32 File_GetOffset_0_0015A350(void *arg0);
s32 File_WaitRead_1_0015A3A0(s8 *a0, s32 a1);
s32 File_Read_2_0015A470(F_File_Read_2_0015A470 *f, u8 *buf, s32 n, s32 mode);
void File_Close_2_0015AB80(F_File_Close_2_0015AB80 *f);
F_Arc_FindByHash_2_0015ABD0* Arc_FindByHash_2_0015ABD0(s32 key);
void Arc_Mount_2_0015AD00(s8 *arg0, s32 arg1, s32 arg2);
s32 sceClose(s32);
void Lz_Decompress_2_00179040(u8 *, u8 *, u32, u32);
void Lz_DecompressB_1_001797E0(u8 *, u8 *, u32, u32);
s32 sceIoctl(s32, s32, s32 *);
s32 sceGsSyncV(s32);
s32 sceCdSync(s32);
void sceLseek(s32, s32, s32);
void sceRead(s32, u8 *, s32);
void memset(void *, s32, s32);
void memcpy(void *, void *, s32);
s32 sceCdRead(u32, s32, void *, u8 *);
s32 sceCdGetError(void);
s32 File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(F_File_Read_2_0015A470 *, s32);
s32 sceOpen(s8 *, s32, s32);
void sceCdSearchFile(s32 *, s8 *);
void sprintf(s8 *, s8 *, s8 *, s8 *, s8 *);
void strcat(s8 *, s8 *);
void strcpy(s8 *, s8 *);

/* Arc_LoadFileTo_1_0015A080 */
#define Arc_FindByHash_2_0015ABD0 Arc_FindByHash_2_0015ABD0__as_Arc_LoadFileTo_1_0015A080
F *Arc_FindByHash_2_0015ABD0__as_Arc_LoadFileTo_1_0015A080(s32);
#define sceClose sceClose__as_Arc_LoadFileTo_1_0015A080
void sceClose__as_Arc_LoadFileTo_1_0015A080(s32);
#define File_Read_2_0015A470 File_Read_2_0015A470__as_Arc_LoadFileTo_1_0015A080
void File_Read_2_0015A470__as_Arc_LoadFileTo_1_0015A080(F *, u8 *, u32, s32);

void Arc_LoadFileTo_1_0015A080(s32 arg0, u8 *arg1) {
    F *f;
    u32 a;
    u32 b;
    u32 total;
    u32 done;
    u8 *src;
    u32 n;
    u32 step;

    f = Arc_FindByHash_2_0015ABD0(arg0);
    switch (f->flags & 1) {
    case 0: a = f->pC->xC; break;
    case 1: a = f->size; break;
    default: a = 0; break;
    }
    switch (f->flags & 1) {
    case 0: b = f->pC->x8; break;
    case 1: b = f->size; break;
    default: b = 0; break;
    }
    switch (f->flags & 1) {
    case 0: total = f->pC->x4; break;
    case 1: total = f->size; break;
    default: total = 0; break;
    }
    done = 0;
    src = arg1;
    if (f->mode != 0) {
        src = arg1 + ((a - (b + 1)) & ~0xF);
    }
    File_Read_2_0015A470(f, src, b, 1);
    Timer_GetTicks_3_001787A0();
    for (; done < total; ) {
        switch (f->mode) {
        case 0:
            n = 0x4000;
            step = n;
            break;
        case 1:
            n = *(u16 *)src;
            step = *(u16 *)(src + 2);
            if (total - done < n) n = total - done;
            Lz_DecompressB_1_001797E0(arg1, src, step, n);
            break;
        case 2:
            n = *(u16 *)src;
            step = *(u16 *)(src + 2);
            if (total - done < n) n = total - done;
            Lz_Decompress_2_00179040(arg1, src, step, n);
            break;
        default:
            n = 0;
            step = 0;
            break;
        }
        done += n;
        src += step;
        arg1 += n;
    }
    if (f->fd >= 0) {
        sceClose(f->fd);
        f->fd = -1;
    }
    f->size = 0;
    f->x0 = 0;
}
#undef Arc_FindByHash_2_0015ABD0
#undef sceClose
#undef File_Read_2_0015A470

/* File_GetSize_1_0015A2F0 */
/* File_GetSize_1_0015A2F0 */
void File_GetSize_1_0015A2F0(void *arg0, s32 *arg1) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0xC);
}

/* File_GetSectorOrSize_0_0015A300 */
s32 File_GetSectorOrSize_0_0015A300(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_3) {                               /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0xC);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}

/* File_GetOffset_0_0015A350 */
s32 File_GetOffset_0_0015A350(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_3) {                               /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 4);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}

/* File_WaitRead_1_0015A3A0 */
s32 File_WaitRead_1_0015A3A0(s8 *a0, s32 a1) {
    s32 r = 1;
    if (D_00201F88) {
        if (!(*(u16 *)(a0 + 0x10) & 1)) a0 = D_00201F80;
        if (a1 == 0) {
            sceIoctl(*(s32 *)(a0 + 0x14), 1, &r);
            if (a0 == D_00201F80 && r == 0) D_00201F8C = 0;
        } else {
            do {
                sceIoctl(*(s32 *)(a0 + 0x14), 1, &r);
                sceGsSyncV(0);
            } while (r);
            if (a0 == D_00201F80) D_00201F8C = 0;
        }
    } else {
        r = sceCdSync(a1 != 1);
    }
    return r;
}

/* File_Read_2_0015A470 */
static inline void seek(F_File_Read_2_0015A470 *f) {
    switch ((s32)f->flags) {
    case 0x100:
    case 0x200:
    case 0x101:
    case 0x201:
        break;
    case 0:
        sceLseek(D_00201F80__as_File_Read_2_0015A470->fd, f->x4, 0);
        break;
    case 1:
        sceLseek(f->fd, f->x4, 0);
        break;
    }
}
static inline void seek2(F_File_Read_2_0015A470 *f) {
    switch ((s32)*(volatile u16 *)&f->flags) {
    case 0x100:
    case 0x200:
    case 0x101:
    case 0x201:
        break;
    case 0:
        sceLseek(D_00201F80__as_File_Read_2_0015A470->fd, f->x4, 0);
        break;
    case 1:
        sceLseek(f->fd, f->x4, 0);
        break;
    }
}

s32 File_Read_2_0015A470(F_File_Read_2_0015A470 *f, u8 *buf, s32 n, s32 mode) {
    u8 sec[0x800];
    u8 sec2[0x800];
    u8 st[4];
    s32 rem;
    s32 cnt;
    s32 res;
    s32 ns;
    s32 off;

    rem = f->size - (f->x4 - f->x0);
    cnt = n;
    if (rem <= 0) {
        return 0;
    }
    if (rem < n) {
        cnt = rem;
    }
    if ((f->flags & 1) && f->fd >= 0) {
        if (mode) {
            seek(f);
            sceRead(f->fd, buf, n);
            File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(f, mode);
            f->x4 += n;
        } else {
            seek(f);
            sceRead(f->fd, buf, (cnt + 0x7FF) & ~0x7FF);
            f->x4 += cnt;
        }
        return rem;
    }
    if (D_00201F88) {
        if (D_00201F8C) {
            return rem;
        }
        if (D_00201F80__as_File_Read_2_0015A470->fd >= 0) {
            if (mode) {
                seek2(f);
                sceRead(D_00201F80__as_File_Read_2_0015A470->fd, buf, n);
                File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(f, mode);
                f->x4 += n;
            } else {
                seek2(f);
                D_00201F8C = 1;
                sceRead(D_00201F80__as_File_Read_2_0015A470->fd, buf, (cnt + 0x7FF) & ~0x7FF);
                f->x4 += cnt;
            }
        }
    } else {
    memset(st, 0, 4);
    st[0] = 0;
    st[1] = 1;
    st[2] = 0;
    st[3] = 0;
    if (!mode) goto nm;
    {
        res = 0;
        off = f->x4 & 0x7FF;
        if (off) {
            cnt = 0x800 - off;
            if (rem < cnt) {
                cnt = rem;
            }
            if (n < cnt) {
                cnt = n;
            }
            memset(st, 0, 4);
            st[0] = 0;
            st[1] = 1;
            st[2] = 0;
            st[3] = 0;
            do {
                while (sceCdRead(f->x4 >> 11, 1, sec, st) == 0) {
                }
                if (!File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(f, mode)) {
                    res = sceCdGetError();
                }
            } while (res != 0 && res != 1);
            memcpy(buf, sec + (f->x4 & 0x7FF), cnt);
            f->x4 += cnt;
            rem -= cnt;
            buf += cnt;
            n -= cnt;
            if (rem == 0) {
                return 0;
            }
            if (n == 0) {
                return rem;
            }
        }
        cnt = (n / 0x800) << 11;
        if (rem < cnt) {
            cnt = rem;
        }
        if (n < cnt) {
            cnt = n;
        }
        if (cnt) {
            ns = cnt / 0x800;
            do {
                while (sceCdRead(f->x4 >> 11, ns, buf, st) == 0) {
                }
                if (!File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(f, mode)) {
                    res = sceCdGetError();
                }
            } while (res != 0 && res != 1);
        }
        f->x4 += cnt;
        rem -= cnt;
        buf += cnt;
        n -= cnt;
        if (rem == 0) {
            return 0;
        }
        if (n == 0) {
            return rem;
        }
        if (n) {
            memset(st, 0, 4);
            st[0] = 0;
            st[1] = 1;
            st[2] = 0;
            st[3] = 0;
            do {
                while (sceCdRead(f->x4 >> 11, 1, sec2, st) == 0) {
                }
                if (!File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(f, mode)) {
                    res = sceCdGetError();
                }
            } while (res != 0 && res != 1);
            memcpy(buf, sec2, n);
            f->x4 += n;
            rem -= n;
            if (rem == 0) {
                return 0;
            }
            return rem;
        }
        rem = 0;
        goto out;
    }
rd:
    if (sceCdRead(f->x4 >> 11, n, buf, st) == 0) goto rd;
    f->x4 += cnt;
    }
out:
    return rem;
nm:
    n = ((cnt + 0x7FF) & ~0x7FF) / 0x800;
    goto rd;
}

/* File_Close_2_0015AB80 */
void File_Close_2_0015AB80(F_File_Close_2_0015AB80 *f)
{
    if (f->fd >= 0) {
        sceClose(f->fd);
        f->fd = -1;
    }
    f->x18 = 0;
    f->x0 = 0;
}

/* Arc_FindByHash_2_0015ABD0 */
#define D_00201F80 D_00201F80__as_Arc_FindByHash_2_0015ABD0
extern F_Arc_FindByHash_2_0015ABD0 *D_00201F80__as_Arc_FindByHash_2_0015ABD0;
#define File_Read_2_0015A470 File_Read_2_0015A470__as_Arc_FindByHash_2_0015ABD0
void File_Read_2_0015A470__as_Arc_FindByHash_2_0015ABD0(F_Arc_Mount_2_0015AD00 *, s8 *, s32, s32);

/* Arc_FindByHash_2_0015ABD0 */
static inline F_Arc_FindByHash_2_0015ABD0 *findFree_Arc_FindByHash_2_0015ABD0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0030A0D0[i].size == 0) {
            return &D_0030A0D0[i];
        }
    }
    return NULL;
}

F_Arc_FindByHash_2_0015ABD0 *Arc_FindByHash_2_0015ABD0(s32 key) {
    s32 n;
    E *e;
    s32 i;
    F_Arc_FindByHash_2_0015ABD0 *f;

    n = D_002F20C8[0];
    e = NULL;
    if (D_00201C7C == 3 && D_00201F88 == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        e = &D_002F20C0.e[i];
        if (key == e->x14) break;
    }
    if (i == n) {
        return NULL;
    }
    f = findFree_Arc_FindByHash_2_0015ABD0();
    f->x0 = D_00201F80->x0 + (e->x18 << 11);
    f->x4 = f->x0;
    f->x8 = e->x14;
    f->xC = (s32)e;
    f->flags = D_00201F80->flags;
    f->flags &= 0x300;
    f->x12 = e->c[3] - 0x30;
    f->fd = -1;
    f->size = e->x8;
    return f;
}

/* Arc_Mount_2_0015AD00 */
static inline F_Arc_Mount_2_0015AD00 *findFree_Arc_Mount_2_0015AD00(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0030A0D0__as_Arc_Mount_2_0015AD00[i].size == 0) {
            return &D_0030A0D0__as_Arc_Mount_2_0015AD00[i];
        }
    }
    return NULL;
}

void Arc_Mount_2_0015AD00(s8 *arg0, s32 arg1, s32 arg2) {
    s8 path[0x100];
    s8 name[0x100];
    s32 st[12];
    s32 mode;
    s8 *p;
    s8 c;
    F_Arc_Mount_2_0015AD00 *f;

    mode = arg1 & 0x300;
    D_00201F88 = mode == 0;
    D_00201C7C = arg1 & 3;
    Cd_Init_2_0015B040(mode, 0);
    D_00201F80__as_Arc_Mount_2_0015AD00 = findFree_Arc_Mount_2_0015AD00();
    if (D_00201F88 != 0) {
        strcpy(name, arg0);
        c = name[0];
        p = name;
        if (c != 0) {
            do {
                if (c == 0x5C) {
                    *p = 0x2F;
                }
                p++;
                c = *p;
            } while (c != 0);
        }
        sprintf(path, D_001FB740, D_001FB748, D_001FB750, name + 1);
        D_00201F80__as_Arc_Mount_2_0015AD00->x0 = 0;
        D_00201F80__as_Arc_Mount_2_0015AD00->x4 = 0;
        D_00201F80__as_Arc_Mount_2_0015AD00->x8 = 0;
        D_00201F80__as_Arc_Mount_2_0015AD00->xC = 0;
        D_00201F80__as_Arc_Mount_2_0015AD00->flags = 1;
        D_00201F80__as_Arc_Mount_2_0015AD00->fd = sceOpen(path, 0x8001, 0x124);
        if (D_00201C7C != 0) {
            D_00201F80__as_Arc_Mount_2_0015AD00->size = 0x800;
        }
    } else {
        strcpy(path, D_001FB758);
        strcat(path, arg0);
        strcat(path, D_001FB760);
        memset(st, 0, 0x24);
        sceCdSearchFile(st, path);
        D_00201F80__as_Arc_Mount_2_0015AD00->x0 = st[0] << 11;
        D_00201F80__as_Arc_Mount_2_0015AD00->x4 = D_00201F80__as_Arc_Mount_2_0015AD00->x0;
        D_00201F80__as_Arc_Mount_2_0015AD00->x8 = 0;
        D_00201F80__as_Arc_Mount_2_0015AD00->xC = 0;
        D_00201F80__as_Arc_Mount_2_0015AD00->flags = mode | 1;
        D_00201F80__as_Arc_Mount_2_0015AD00->fd = -1;
        D_00201F80__as_Arc_Mount_2_0015AD00->size = 0x800;
    }
    if (arg2 == 0) {
        File_Read_2_0015A470(D_00201F80__as_Arc_Mount_2_0015AD00, D_002F20C0__as_Arc_Mount_2_0015AD00, 0x800, 1);
        f = D_00201F80__as_Arc_Mount_2_0015AD00;
        switch (f->flags) {
        case 0x100:
        case 0x200:
            f->x4 = f->x0;
            break;
        case 0x101:
        case 0x201:
            f->x4 = f->x0;
            break;
        case 0:
            f->x4 = f->x0;
            sceLseek(D_00201F80__as_Arc_Mount_2_0015AD00->fd, f->x4, 0);
            break;
        case 1:
            f->x4 = 0;
            sceLseek(f->fd, f->x4, 0);
            break;
        }
        arg2 = D_002F20C8[0];
        D_00201F80__as_Arc_Mount_2_0015AD00->size = (arg2 << 5) + 0x10;
    }
    File_Read_2_0015A470(D_00201F80__as_Arc_Mount_2_0015AD00, D_002F20C0__as_Arc_Mount_2_0015AD00, (arg2 << 5) + 0x10, 1);
    D_00201F80__as_Arc_Mount_2_0015AD00->size = D_002F20C4[0];
}
#undef File_Read_2_0015A470
#undef D_00201F80

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F80 */
s8 *D_00201F80;
/* data twins (src/game/data/screen_fx_bss_0030A0D0.c): D_0030A0D0 */
F_Arc_FindByHash_2_0015ABD0 D_0030A0D0[0x10];
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/screen_fx_bss.c): D_002F20C0__grp: D_002F20C0@0x0 */
u8 D_002F20C0__grp[0x4] __attribute__((aligned(16)));
#endif
