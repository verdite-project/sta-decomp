#include "common.h"
#include "game/ee.h"

extern s32 D_004B638C[];
extern s32 D_004B6390[];
extern s32 D_004B6394[];
extern s32 D_004B6398[];
s32 Mc_StepGetInfo_3_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
void *memcpy(void *, void *, s32);
void memset(void *, s32, s32);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcClose(s32);
s32 sceMcRead(s32, void *, s32);
s32 sceMcSeek(s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 Mc_StepReadChecked_3_001D4A78(void)
{
#define t (&gMcState_004B63B8)
    s32 r;
    s32 v;
    s32 port = t->port;
    s32 slot = t->slot;
    s32 max;
    s32 len;
    s32 i;
    u8 sum;
    s32 d;
    s32 a;
    s32 x;

    switch (t->step) {
    case 0:
        D_004B6474[0] = -1;
        t->step++;
        t->retry = 0;
        D_004B638C[0] = 0;
    case 1:
        v = Mc_StepGetInfo_3_001D3BF0(port, slot, &t->type[(port) * 4 + (slot)], &t->free[(port) * 4 + (slot)], &t->format[(port) * 4 + (slot)], t->x90);
        t->x90 = v;
        if (v > 0) break;
        v = Mc_GetInfoStatus_2_001D3CE0(v);
        t->err = v;
        if (v != 0) {
            t->cmd = 0;
            return -10;
        }
        if (t->type[(port) * 4 + (slot)] != 2) {
            if (t->type[(port) * 4 + (slot)] == 3) t->err = 1;
            else t->err = 1;
            t->cmd = 0;
            return -10;
        }
        t->retry = 0;
        t->step++;
        break;
    case 2:
        if (sceMcOpen(port, slot, t->name, 1) != 0) {
            if (t->retry == 2) {
                t->cmd = 0;
                t->err = 0x47;
                return -10;
            }
            t->retry++;
        } else {
            t->step++;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    Mc_SetErrorStatus_4_001D3DA8(r);
                    if (t->err == 100) {
                        t->err = 0x47;
                    }
                    t->cmd = 0;
                    return r;
                } else {
                    t->retry++;
                    t->step--;
                }
            } else {
                D_004B6474[0] = r;
                t->retry = 0;
                t->step++;
            }
        }
        break;
    case 4:
        v = sceMcRead(D_004B6474[0], D_004B6390, 4);
        if (v != 0) {
            if (t->retry == 2) {
                t->err = 0x47;
                t->step = 100;
            } else {
                t->retry++;
            }
        } else {
            t->step++;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    t->err = 0x47;
                    t->step = 100;
                } else {
                    t->retry++;
                    t->step--;
                }
            } else {
                t->step++;
            }
        }
        break;
    case 6:
        x = D_004B6390[0];
        D_004B6398[0] = x + 6;
        x -= 0x3FB;
        if (x > 0) {
            D_004B6398[0] += (x + 0x3FE) / 0x3FF;
        }
        a = (D_004B6398[0] + 0x1F) & ~0x1F;
        d = D_004B6398[0] - 1;
        t->step++;
        D_004B6398[0] = a;
        D_004B6394[0] = d - a + 0x20;
        t->retry = 0;
        break;
    case 7:
        v = sceMcSeek(D_004B6474[0], D_004B6398[0] - 0x20, 0);
        if (v != 0) {
            if (t->retry == 2) {
                t->err = 0x47;
                t->step = 100;
            } else {
                t->retry++;
            }
        } else {
            t->step++;
        }
        break;
    case 8:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    t->err = 0x47;
                    t->step = 100;
                } else {
                    t->retry++;
                    t->step--;
                }
            } else {
                t->retry = 0;
                t->step++;
            }
        }
        break;
    case 9:
        v = sceMcRead(D_004B6474[0], D_004B6478, 0x20);
        if (v != 0) {
            if (t->retry == 2) {
                t->err = 0x47;
                t->step = 100;
            } else {
                t->retry++;
            }
        } else {
            t->step++;
        }
        break;
    case 10:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    t->err = 0x47;
                    t->step = 100;
                } else {
                    t->retry++;
                    t->step--;
                }
            } else {
                if (D_004B6478[D_004B6394[0]] != 1) {
                    t->err = 0x47;
                    t->step = 100;
                } else {
                    t->retry = 0;
                    t->step++;
                }
            }
        }
        break;
    case 11:
        v = sceMcSeek(D_004B6474[0], 4, 0);
        if (v != 0) {
            if (t->retry == 2) {
                t->err = 0x47;
                t->step = 100;
            } else {
                t->retry++;
            }
        } else {
            t->step++;
        }
        break;
    case 12:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    t->err = 0x47;
                    t->step = 100;
                } else {
                    t->retry++;
                    t->step--;
                }
            } else {
                t->step++;
                memset(D_004B6478, 0, 0x400);
                t->retry = 0;
            }
        }
        break;
    case 13:
        len = D_004B638C[0] == 0 ? 0x3FC : 0x400;
        v = sceMcRead(D_004B6474[0], D_004B6478, len);
        if (v != 0) {
            if (t->retry == 2) {
                t->err = 0x47;
                t->step = 100;
            } else {
                t->retry++;
            }
        } else {
            t->step++;
        }
        break;
    case 14:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    if (r == -2) t->err = 3;
                    else if (r < -10) t->err = 1;
                    else t->err = 0x47;
                    t->x90 = r;
                    t->step = 100;
                } else {
                    t->retry++;
                    t->step--;
                }
            } else {
                max = D_004B638C[0] ? 0x3FF : 0x3FB;
                len = D_004B6390[0] - D_004B638C[0];
                if (max < len) len = max;
                if (len != 0) {
                    sum = 0;
                    for (i = 0; i < len; i++) {
                        sum += ~D_004B6478[i];
                    }
                    if (sum == D_004B6478[len]) {
                        if (t->size < (u32)D_004B6390[0]) {
                            len = t->size - D_004B638C[0];
                        } else {
                            len = D_004B6390[0] - D_004B638C[0];
                        }
                        if (max < len) len = max;
                        memcpy((void *)(t->buf + D_004B638C[0]), D_004B6478, len);
                        if (len < max) {
                            t->step++;
                            break;
                        }
                    } else {
                        t->x90 = -399;
                        t->err = 0x47;
                        t->step = 100;
                        break;
                    }
                }
                D_004B638C[0] += len;
                t->retry = 0;
                t->step--;
            }
        }
        break;
    case 15:
        t->retry = 0;
        t->step++;
        break;
    case 16:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (t->retry == 2) {
                t->cmd = 0;
                t->err = 0x47;
                return -100;
            }
            t->retry++;
        } else {
            t->step++;
        }
        break;
    case 17:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->retry == 2) {
                    t->cmd = 0;
                    t->err = 0x47;
                    return r;
                }
                t->retry++;
                t->step--;
            } else {
                t->err = 0x48;
                t->cmd = 0;
                return 1;
            }
        }
        break;
    case 100:
        if (D_004B6474[0] < 0) {
            t->cmd = 0;
            return -100;
        }
        t->retry = 0;
        t->step++;
        break;
    case 101:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (t->retry == 2) {
                t->err = 0x47;
                return -1;
            }
            t->retry++;
        } else {
            t->step++;
        }
        break;
    case 102:
        if (sceMcSync(1, 0, &r) != 0) {
            t->cmd = 0;
            return -200;
        }
        break;
    }
    return 0;
}
