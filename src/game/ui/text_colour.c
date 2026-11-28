/* One 0x60-byte text colour entry.
 * cf. KFIV's Message_GetColor (kfiv-decomp src/game/ui/message.c). */

typedef struct { char data[0x60]; } TextColour;
extern TextColour gTextColourBss_0030D9A0[];

TextColour *TextColour_Get_1_0015D580(int colour)
{
    return &gTextColourBss_0030D9A0[colour];
}

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data group (src/game/data/player_bss.c): gTextColourBss_0030D9A0__grp: gTextColourBss_0030D9A0@0x0, gZeroVec_003139A0@0x6000, gTextColourBss_003139A4@0x6004, gTextColourBss_003139A8@0x6008 */
unsigned char gTextColourBss_0030D9A0__grp[0x6010] __attribute__((aligned(16)));
#endif
