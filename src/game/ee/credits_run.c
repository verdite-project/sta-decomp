#include "common.h"
typedef struct Node { struct Node *next; } Node;
typedef struct { u8 pad[4]; u8 type; u8 pad2[0x3B]; } E;
typedef struct { u8 pad[8]; u16 n; } H;
typedef struct { s32 x0; s32 x4; H *x8; E *xC; s32 x10; s32 x14; Node *x18; } G;
extern G gCreditsLoadBss_004BC2F0[];
Node *Credits_AllocNode_1_001E3FD8(E *);
void Credits_ParseHeader_0_001E40D0(Node *);
void Credits_BindCallbacks_1_001E4080(Node *);

s32 Credits_Run_1_001E3EC0(void)
{
    s32 n;
    s32 i;
    E *e;
    Node *r;
    Node *p;

    e = (E *)((u8 *)gCreditsLoadBss_004BC2F0->x8 + 0x20); n = gCreditsLoadBss_004BC2F0->x8->n; gCreditsLoadBss_004BC2F0->xC = e;
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
