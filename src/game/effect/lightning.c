#include "common.h"
#include "game/effect.h"
#include "game/data.h"
typedef struct { char pad[0x10]; char sub[0x4D0]; } E;
typedef struct { E e[64]; } B;
typedef struct { u8 pad0[8]; f32 x8; f32 xC; f32 x10; f32 x14; } LP;
extern B gVibrationBss_003174F0[2];
extern Mtx gSoundEmitterBss_002F16C0;
/* .bss, from the top down (CodeWarrior writes it in reverse) */
Vec D_0033E500[0x100];
void Lightning_BuildStrip_0_00164440(LP *P, u32 *out, Vec *L, Vec *dir, Vec *c);
void Lightning_ResetPoints_0_00164940(void);
void Lightning_Init_0_00164BB0(void *p);
void sceVu0CopyVector(Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);

/* Lightning_InitAll_1_001643B0 */
void Lightning_InitAll_1_001643B0(void)
{
    s32 j, i;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 64; i++)
            Lightning_Init_0_00164BB0(gVibrationBss_003174F0[j].e[i].sub);
    }
    Lightning_ResetPoints_0_00164940();
}

/* Lightning_BuildStrip_0_00164440 */
static inline void body(LP *P, u32 **po, Vec *L, Vec *dir, Vec *c) {
    Vec col;
    Vec tr[4];
    Vec nd[4];
    Vec n;
    Vec *tbl;
    Vec *L2;
    u16 i;
    u8 k;
    f32 sum;
    f32 d;
    f32 h;
    f32 s;

    tbl = D_0033E500;
    for (k = 0; k < 4; k++) {
        tr[k].x = gSoundEmitterBss_002F16C0.m[0].x * L[k].x + gSoundEmitterBss_002F16C0.m[1].x * L[k].y + gSoundEmitterBss_002F16C0.m[2].x * L[k].z;
        tr[k].y = gSoundEmitterBss_002F16C0.m[0].y * L[k].x + gSoundEmitterBss_002F16C0.m[1].y * L[k].y + gSoundEmitterBss_002F16C0.m[2].y * L[k].z;
        tr[k].z = gSoundEmitterBss_002F16C0.m[0].z * L[k].x + gSoundEmitterBss_002F16C0.m[1].z * L[k].y + gSoundEmitterBss_002F16C0.m[2].z * L[k].z;
        tr[k].w = L[k].w;
        sceVu0CopyVector(&nd[k], &dir[k]);
        nd[k].w = nd[k].z + (nd[k].x + nd[k].y);
        if (nd[k].w != 0.0f) nd[k].w = 1.0f;
    }
    L2 = L;
    for (i = 0; i < 256; i++) {
        sceVu0CopyVector(&n, tbl++);
        sceVu0CopyVector(&col, &gZeroVec_003139A0);
        for (k = 0; k < 2; k++) {
            sum = 0.0f;
            d = sceVu0InnerProduct(&tr[k], &n);
            h = 0.5f * (1.0f + d);
            col.w = 0.0f;
            if (!(d <= 0.0f)) {
                s = 0.5f * (d * (P->x10 * d) - P->x8);
                if (s < 0.0f) s = 0.0f;
                sum += s;
                col.w = s * (4.0f * (P->x14 * nd[k].w));
            }
            if (!(h <= 0.0f)) sum += 0.125f * (P->xC * h);
            if (!(sum <= 0.0f)) {
                sum = sum * (1.0f + L2[k].w);
                col.x += sum * (c->x * nd[k].x);
                col.y += sum * (c->y * nd[k].y);
                col.z += sum * (c->z * nd[k].z);
            }
            col.x += col.w * nd[k].x;
            col.y += col.w * nd[k].y;
            col.z += col.w * nd[k].z;
        }
        if (!(col.x <= 255.0f)) col.x = 255.0f;
        if (!(col.y <= 255.0f)) col.y = 255.0f;
        if (!(col.z <= 255.0f)) col.z = 255.0f;
        *(*po)++ = (u32)col.z << 16 | ((u32)col.x | (u32)col.y << 8) | 0x80000000;
    }
}

void Lightning_BuildStrip_0_00164440(LP *P, u32 *out, Vec *L, Vec *dir, Vec *c) {
    body(P, &out, L, dir, c);
}

/* Lightning_ResetPoints_0_00164940 */
void Lightning_ResetPoints_0_00164940(void) {
    s16 i;
    Vec *p;
    s16 j;
    f32 x;
    f32 z;
    f32 y;
    f32 zz;
    f32 d;
    f32 xx;
    f32 nx;
    f32 l;
    f32 s;

    p = D_0033E500;
    for (i = 0; i < 16; i++) {
        x = 2.0f * ((f32)i / 16.0f) - 1.0f;
        xx = x * x;
        for (j = 0; j < 16; j++) {
            z = 2.0f * ((f32)j / 16.0f) - 1.0f;
            zz = z * z;
            d = 1.0f - zz - xx;
            if (!(d <= 0.0f)) {
                y = sqrtf(d);
                nx = x;
            } else {
                l = sqrtf(zz + xx);
                z = z / l;
                nx = x / l;
                y = 0.0f;
            }
            s = 2.0f * y;
            p->x = -(s * z);
            p->y = -(s * nx);
            p->z = -(s * y - 1.0f);
            *(s32 *)&p->w = 0;
            p++;
        }
    }
}
