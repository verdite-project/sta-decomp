#include "game/ee.h"
typedef struct { u8 pad[8]; u16 n; } H;
typedef struct { s32 x0; s32 x4; H *x8; CreditsEntry *xC; s32 x10; s32 x14; CreditsNode *x18; } G;
extern G gCreditsLoadBss_004BC2F0[];
CreditsNode *Credits_AllocNode_1_001E3FD8(CreditsEntry *);
void Credits_ParseHeader_0_001E40D0(CreditsNode *);

s32 Credits_Run_1_001E3EC0(void)
{
    s32 n;
    s32 i;
    CreditsEntry *e;
    CreditsNode *r;
    CreditsNode *p;

    e = (CreditsEntry *)((u8 *)gCreditsLoadBss_004BC2F0->x8 + 0x20); n = gCreditsLoadBss_004BC2F0->x8->n; gCreditsLoadBss_004BC2F0->xC = e;
    for (i = 0; --n != -1; i++) {
        r = Credits_AllocNode_1_001E3FD8(&e[i]);
        if (r == NULL) break;
        switch (e[i].type) {
        case 2: Credits_ParseHeader_0_001E40D0(r); break;
        case 0: case 1: Credits_BindCallbacks_1_001E4080(r); break;
        }
        if (gCreditsLoadBss_004BC2F0->x18 == NULL) {
            gCreditsLoadBss_004BC2F0->x18 = r;
        } else {
            p = gCreditsLoadBss_004BC2F0->x18;
            while (p->next != NULL) p = p->next;
            p->next = r;
        }
    }
    if (gCreditsLoadBss_004BC2F0->x18 == NULL) return -1; return 0;
}
