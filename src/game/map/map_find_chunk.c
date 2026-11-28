/* Best-effort C for the NONMATCHING build; the matching attempt is
 * wip/Map_FindChunk_0_001B6190.c. */
#include "include_asm.h"

#ifdef NONMATCHING
/* NEAR: literal "STMI"/"STEM"/"STOI" (gMapAreaLoadRodata_001FDA60/68/70) - batch.py cannot link literals; checked with a private batch2.py placing .data at 0x1FDA60: same size/shape, ~300 words differ in temp/s-reg allocation. extern s8 D_[] instead hoists the byte loads out of the loops. */
#include "common.h"
typedef struct { u32 id; s32 size; u32 kind:8; u32 off:24; u16 xC; u16 n; } Ch;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } Dt;
typedef struct {
    u8 pad[0x28];
    s32 x28, x2C, x30, x34, x38, x3C, x40, x44, x48, x4C, x50, x54, x58, x5C, x60, x64, x68;
    s16 x6C, x6E, x70, x72, x74, x76, x78, x7A, x7C, x7E, x80;
} Out;
extern s8 gMapAreaLoadRodata_001FDA60[];
extern s8 gMapAreaLoadRodata_001FDA68[];
extern s8 gMapAreaLoadRodata_001FDA70[];
#define S1 "STMI\0\0\0\0"
#define S2 "STEM\0\0\0\0"
#define S3 "STOI\0\0\0\0"
#define FCC(d) ((d)[0] | ((d)[1] << 8) | ((d)[2] << 16) | ((d)[3] << 24))
#define OFS(d) ((s32)((u8 *)(d) + 0x10 + (((d)->xC + 15) & ~15)) - base)

Ch *Map_FindChunk_0_001B6190(Out *o, Ch *h, s32 base) {
    Ch *r = NULL;
    Ch *c;
    Ch *s;
    Dt *d;
    u32 i;
    u32 j;

    if (h->id != 0x4D415453) return NULL;
    for (i = 0, c = (Ch *)((u8 *)h + h->off); i < h->n; i++, c = (Ch *)((u8 *)c + c->size)) {
        if (c->id == FCC(S1)) {
            for (j = 0, s = (Ch *)((u8 *)c + c->off); j < c->n; j++, s = (Ch *)((u8 *)s + s->size)) {
                d = (Dt *)(s + 1);
                switch (s->id) {
                case 0x61524150: o->x28 = OFS(d); o->x6C = d->x8; break;
                case 0x614A424F: o->x2C = OFS(d); o->x6E = d->x8; break;
                case 0x61524843: o->x30 = OFS(d); o->x70 = d->x8; break;
                case 0x61455449: o->x34 = OFS(d); o->x72 = d->x8; break;
                case 0x6144544C: o->x38 = OFS(d); o->x74 = d->x8; break;
                case 0x61474F46: o->x54 = OFS(d); o->x7C = d->x8; break;
                case 0x61464645: o->x58 = OFS(d); o->x7E = d->x8; break;
                case 0x6150544C: o->x3C = OFS(d); o->x76 = d->x8; break;
                case 0x615F4553: o->x40 = OFS(d); o->x7A = d->x8; break;
                case 0x62584653: o->x48 = OFS(d); o->x78 = d->x8; break;
                case 0x61505247: o->x4C = OFS(d); break;
                case 0x61524353:
                    o->x64 = OFS(d);
                    if (d->x4 == 0) o->x64 = 0;
                    break;
                case 0x61535953:
                    o->x50 = OFS(d);
                    if (*(u16 *)(base + o->x50 + 0xBA) == 0) *(u16 *)(base + o->x50 + 0xBA) = 3000;
                    break;
                case 0x54554F52:
                    o->x60 = OFS(d);
                    if (d->x4 == 0) o->x60 = 0;
                    break;
                }
            }
        }
        if (c->id == FCC(S2)) {
            for (j = 0, s = (Ch *)((u8 *)c + c->off); j < c->n; j++, s = (Ch *)((u8 *)s + s->size)) {
                d = (Dt *)(s + 1);
                switch (s->id) {
                case 0x6147534D: o->x68 = OFS(d); break;
                }
            }
        }
        if (c->id == FCC(S3)) {
            r = c;
            for (j = 0, s = (Ch *)((u8 *)c + c->off); j < c->n; j++, s = (Ch *)((u8 *)s + s->size)) {
                d = (Dt *)(s + 1);
                switch (s->id) {
                case 0x61444D4F: o->x5C = OFS(d); o->x80 = d->x8; break;
                case 0x4D415453: break;
                }
            }
        }
    }
    return r;
}
#else
INCLUDE_ASM(Map_FindChunk_0_001B6190);
#endif
