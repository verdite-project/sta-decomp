/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Mc_StepWriteChecked_3_001D4170.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR (ee-gcc): 519 of 577 positional, built 571 vs 577; difflib full-instruction mismatch 187 (prev 194, incl. reloc noise).
   Changed: case 1 stores call results straight into t->x90 / t->err (no copy reg); case 2 without the e local.
   Still differs: case 2 success path is cross-jumped (retail keeps retry=0;state++ inline and rebuilds &t for the x88 store),
   cases 5 and 19 register/scheduling, retail movz vs our movn near the end. */
#include "common.h"
typedef struct {
    s32 type[8]; s32 free[8]; s32 format[8]; s32 res[8];
    s32 port; s32 slot; s32 x88; s32 state;
    s32 x90; s32 x94; s32 err; s32 retry;
    s32 name; s32 xa4; s32 size; s32 xac; s32 xb0; s32 xb4; s32 data;
} T;
extern T gMcState_004B63B8;
#ifndef NONMATCHING
extern u32 D_004B6380[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B6380 */
static u32 D_004B6380[0x1];
#endif
#ifndef NONMATCHING
extern u32 D_004B6384[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B6384 */
static u32 D_004B6384[0x1];
#endif
#ifndef NONMATCHING
extern s32 D_004B6388[];
#else
/* data twins (src/game/data/pad_get_connected_bss_004B5DD0.c): D_004B6388 */
static s32 D_004B6388[0x1];
#endif
extern s32 D_004B6474[];
extern u8 D_004B6478[];
extern volatile s32 gMcDirBuf_004B68C0[];
extern s32 D_004B68D0[];
s32 Mc_StepGetInfo_3_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
s32 Mc_GetInfoStatus_2_001D3CE0(s32);
void Mc_SetErrorStatus_4_001D3DA8(s32);
void memcpy(void *, s32, s32);
void *memset(void *, s32, u32);
s32 sceMcGetDir(s32, s32, s32, u32, s32, s32 *);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcSeek(s32, s32, s32);
s32 sceMcWrite(s32, void *, s32);
s32 sceMcClose(s32);
s32 sceMcSync(s32, s32 *, s32 *);

#define t (&gMcState_004B63B8)
s32 Mc_StepWriteChecked_3_001D4170(void)
{

    s32 r;
    s32 e;
    s32 fr;
    s32 d;
    s32 rem;
    s32 n;
    s32 off;
    s32 pos;
    u8 sum;
    u8 *p;
    u8 *q;
    s32 k;
    s32 sz;
    s32 i;
    s32 port = t->port;
    s32 slot = t->slot;

    switch (t->state) {
    case 0:
        D_004B6474[0] = 0;
        D_004B6384[0] = 0;
        t->state++;
        t->retry = 0;
        D_004B6388[0] = 0;
        break;
    case 1:
        t->x90 = Mc_StepGetInfo_3_001D3BF0(port, slot, &t->type[port * 4 + slot], &t->free[port * 4 + slot], &t->format[port * 4 + slot], t->x90);
        if (t->x90 > 0) break;
        t->err = Mc_GetInfoStatus_2_001D3CE0(t->x90);
        if (t->err != 0) {
            t->x88 = 0;
            return -1;
        }
        t->state++;
        break;
    case 2:
        if (t->type[port * 4 + slot] != 2) {
            t->err = 1;
            t->x88 = 0;
            return -4;
        }
        t->retry = 0;
        t->state++;
        break;
    case 3:
        if (sceMcGetDir(port, slot, t->name, 0, 1, gMcDirBuf_004B68C0) != 0) {
            if (t->retry == 2) {
                t->x88 = 0;
                t->err = 100;
                return -1;
            }
            t->retry++;
        } else {
            t->state++;
        }
        break;
    case 4:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (t->retry == 2) {
                if (r == -2) t->err = 3;
                else if (r == -4) {
                    D_004B68D0[0] = 0;
                    t->state++;
                    break;
                } else t->err = 100;
                return r;
            }
            t->retry++;
            t->state--;
            break;
        }
        if (r == 0) D_004B68D0[0] = 0;
        t->state++;
        break;
    case 5:
        d = t->size;
        sz = gMcDirBuf_004B68C0[4];
        fr = ((u32)(sz + 0x3FF) >> 10) + t->free[port * 4 + slot];
        if (sz == 0 && fr < 3) goto fail5;
        d -= 0x3FB;
        D_004B6380[0] = ((volatile T *)t)->size + 6;
        if (d > 0) D_004B6380[0] += (d + 0x3FE) / 0x3FF;
        D_004B6380[0] = (D_004B6380[0] + 0x1F) & ~0x1F;
        k = 2;
        if (gMcDirBuf_004B68C0[4] != 0) k = 0;
        if (fr - k < (s32)((D_004B6380[0] + 0x3FF) >> 10)) {
        fail5:
            t->x88 = 0;
            t->err = 0x1F;
            return -6;
        }
        t->state = 9;
        break;
    case 9:
        t->retry = 0;
        t->state++;
    case 10:
        if (sceMcOpen(port, slot, t->name, D_004B68D0[0] == 0 ? 0x203 : 3) != 0) {
            if (t->retry == 2) {
                t->x88 = 0;
                t->err = 0x3D;
                return -10;
            }
            t->retry++;
        } else {
            t->state++;
        }
        break;
    case 11:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (t->retry == 2) {
                Mc_SetErrorStatus_4_001D3DA8(r);
                if (t->err == 100) t->err = 0x3D;
                t->x88 = 0;
                return -5;
            }
            t->retry++;
            t->state--;
            break;
        }
        D_004B6474[0] = r;
        t->retry = 0;
        t->state++;
        break;
    case 12:
        e = sceMcSeek(D_004B6474[0], D_004B6380[0] - 0x20, 0);
        if (e != 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
            } else {
                t->retry++;
            }
        } else {
            t->state++;
        }
        break;
    case 13:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
                break;
            }
            t->retry++;
            t->state--;
            break;
        }
        t->state++;
        break;
    case 14:
        t->retry = 0;
        memset(D_004B6478, 0, 0x20);
        t->state++;
    case 15:
        e = sceMcWrite(D_004B6474[0], D_004B6478, 0x20);
        if (e != 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
            } else {
                t->retry++;
            }
        } else {
            t->state++;
        }
        break;
    case 16:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (t->retry != 2 && r != -8) {
                t->retry++;
                t->state--;
            } else {
                t->err = 0x3D;
                t->state = 100;
            }
            break;
        }
        t->retry = 0;
        t->state++;
        break;
    case 17:
        e = sceMcSeek(D_004B6474[0], 0, 0);
        if (e != 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
            } else {
                t->retry++;
            }
        } else {
            t->state++;
        }
        break;
    case 18:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
                break;
            }
            t->retry++;
            t->state--;
            break;
        }
        t->state++;
        break;
    case 19:
        if ((u32)t->size >= D_004B6384[0]) {
            memset(D_004B6478, 0, 0x420);
            n = t->size - D_004B6384[0];
            if (D_004B6384[0] == 0) {
                *(u32 *)D_004B6478 = t->size;
                if (n > 0x3FA) n = 0x3FB;
                off = 4;
            } else {
                if (n > 0x3FE) n = 0x3FF;
                off = 0;
            }
            pos = n + off;
            sum = 0;
            if (n != 0) {
                p = &D_004B6478[off];
                memcpy(p, gMcState_004B63B8.data + D_004B6384[0], n);
                if (n > 0) { q = p; i = n; do { sum += ~*q; q++; i--; } while (i != 0); }
                D_004B6478[pos++] = sum;
            }
            if (D_004B6384[0] == 0) {
                if (n < 0x3FB) {
                    D_004B6478[pos++] = 1;
                    D_004B6384[0] = 1;
                }
            } else if (n < 0x3FF) {
                D_004B6478[pos++] = 1;
                D_004B6384[0]++;
            }
            D_004B6384[0] += n;
            if (pos & 0x1F) pos = (pos & ~0x1F) + 0x20;
            D_004B6388[0] = pos;
            t->retry = 0;
            t->state++;
        } else {
            t->state = 0x16;
        }
        break;
    case 20:
        e = sceMcWrite(D_004B6474[0], D_004B6478, D_004B6388[0]);
        if (e != 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
            } else {
                t->retry++;
            }
        } else {
            t->state++;
        }
        break;
    case 21:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r < 0) {
            if (t->retry != 2 && r != -8) {
                t->retry++;
                t->state--;
            } else {
                t->err = 0x3D;
                t->state = 100;
            }
            break;
        }
        t->state = 0x13;
        t->retry = 0;
        break;
    case 22:
        e = sceMcClose(D_004B6474[0]);
        if (e != 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                t->state = 100;
            } else {
                t->retry++;
            }
        } else {
            t->state++;
        }
        break;
    case 23:
        if (sceMcSync(1, 0, &r) == 0) break;
        t->x88 = 0;
        if (r < 0) {
            if (t->retry == 2) {
                t->err = 0x3D;
                return -8;
            }
            t->retry++;
            t->state--;
            break;
        }
        t->err = 0x3E;
        return 1;
    case 100:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (D_004B6474[0] < 0) goto fail;
        t->retry = 0;
        t->state++;
        break;
    case 101:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (t->retry == 2) {
                t->x88 = 0;
                t->err = 0x3D;
                return -999;
            }
            t->retry++;
        } else {
            t->state++;
        }
        break;
    case 102:
        if (sceMcSync(1, 0, &r) == 0) break;
    fail:
        e = t->x90;
        t->err = 0x3D;
        t->x88 = 0;
        if (e >= 0) e = -999;
        return e;
    }
    return 0;
}
#else
INCLUDE_ASM(Mc_StepWriteChecked_3_001D4170);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/pad_get_connected_bss_004B5DD0.c): gMcDirBuf_004B68C0__grp: gMcDirBuf_004B68C0@0x0, D_004B68D0@0x10 */
u8 gMcDirBuf_004B68C0__grp[0x40] __attribute__((aligned(16)));
#endif
