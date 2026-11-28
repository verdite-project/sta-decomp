/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Mdl_EmitStripD_0_0016DC70.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: 27 of 151 words differ (was 36). Remaining diff is pure saved-reg allocation: target s4=p, s3=&q.w[1] (CSE temp), s2=idx then &q.w[3], s1=a0 then e, s0=b. Here o/bb/idx are void*-param copies; the CSE'd &q.w[1]/&q.w[3] temps still get lower s-regs than o/bb. Explicit u32 *w1/*w3 pointer locals add 3 instructions. */
// ---
#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef union { u32 w; f32 f; struct { u16 a:7; u16 m:4; u16 b11:1; u16 b12:1; } s; } C;
typedef struct { u8 pad[0x100]; f32 v[4]; u8 pad2[0x30]; } E;
typedef struct { u8 pad[0xB0]; s32 off; u8 pad2[0xC]; E arr[1]; } Base;
typedef struct { u8 pad[5]; u8 i5; u8 pad2[8]; u8 e; } Obj;
extern B8 D_00222A50[];
extern B8 D_00222A51[];
extern u32 D_00201F54;
extern f32 D_001F2110[];
Q *GsPkt_Alloc_3_00154A80(s32);
void GsPkt_Commit_1_00154A70(void);
void sceVu0CopyVector(f32 *, f32 *);
void Mdl_EmitStripD_0_0016DC70(void *a0, s32 a1, void *b, s32 idx0, C c0) {
    s32 idx = idx0;
    s8 *e;
    Q *p;
    Obj *o = a0;
    Base *bb = b;
    C c;
    Q q;
    Q q2;
    u8 n;
    u32 x;
    s32 m;
    p = GsPkt_Alloc_3_00154A80(((o->e & 7) != 0) + 5);
    q.q = 0;
    q.w[0] = 0x30000004;
    q.w[1] = (s32)&bb->arr[idx] + bb->off;
    q.w[3] = 0x6C040018;
    p[0].q = q.q;
    p++;
    if (o->e & 7) {
        n = o->e & 7;
        q.w[0] = ((n >> 2) + 1) | 0x30000000;
        q.w[1] = (s32)((s8 *)&bb->arr[o->i5] + 0x250) + bb->off;
        q.w[3] = (((n >> 2) + 1) << 16) | 0x6C000038;
        p[0].q = q.q;
        p++;
    }
    q.q = 0;
    q.w[0] = 0x10000001;
    q.w[3] = 0x6C010028;
    c = c0;
    m = c.s.m;
    x = m & 3;
    if (x == 0) {
        x = c.s.b11 ? 0x100 : (c.s.b12 ? 0x200 : 0);
    }
    x |= ((m >> 2) & 3) << 4;
    q2.w[0] = x;
    q2.w[1] = 0;
    q2.w[2] = 0;
    q2.w[3] = (D_00222A51[0].b3 ? 0 : 4) | (D_00222A50[0].b1 ? 8 : 0);
    p[0].q = q.q;
    p[1].q = q2.q;
    e = (s8 *)bb->arr[idx].v;
    sceVu0CopyVector((f32 *)e, D_001F2110);
    q.q = 0;
    q.w[0] = 0x30000001;
    q.w[1] = (s32)e + bb->off;
    q.w[3] = 0x6C010029;
    p[2].q = q.q;
    q.q = 0;
    q.w[0] = 0x10000000;
    q.w[3] = D_00201F54 | 0x15000000;
    p[3].q = q.q;
    GsPkt_Commit_1_00154A70();
}
#else
INCLUDE_ASM(Mdl_EmitStripD_0_0016DC70);
#endif

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00201F54 */
u32 D_00201F54;
#endif
