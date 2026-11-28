#include "common.h"

/* bss_004B5DD0: the game's .bss from 0x004B5DD0, defined from the top down
   (CodeWarrior writes uninitialised objects in reverse order). */
/* used by: mc_check_room, mc_get_card_status, mc_get_card_type_raw,
   mc_get_format_raw, mc_get_free_clusters, mc_get_info_status,
   mc_get_result, mc_get_state, mc_init, mc_set_error_status, mc_start_chdir,
   mc_start_check, mc_start_copy_file, mc_start_format, mc_start_get_dir,
   mc_start_mkdir, mc_start_read, mc_start_read_b, mc_start_read_checked,
   mc_start_write, mc_start_write_checked, mc_step_chdir, mc_step_check,
   mc_step_copy_file, mc_step_find_file, mc_step_format, mc_step_get_dir,
   mc_step_get_info, mc_step_mkdir, mc_step_read, mc_step_read_checked,
   mc_step_write, mc_update, pad_clear_repeat, pad_get_buttons,
   pad_get_connected, pad_get_mode, pad_get_record, pad_get_stick_lx,
   pad_get_stick_ly, pad_get_stick_r, pad_get_trigger, pad_init,
   pad_is_analog, pad_port_open, pad_request_analog, pad_request_digital,
   pad_set_act_buffer, pad_set_enabled, pad_set_repeat, pad_set_rumble,
   pad_set_rumble_large, sound_driver_call, stats, text_001D4170.s,
   text_001D7350.s, text_001D8AB0.s */

int D_004B7EB0[0x10];
u8 D_004B7CB0[0x200]; /* also D_004B7EAF */
u8 D_004B7C90[0x20];
u8 D_004B7C40[0x50];
u8 D_004B7A40[0x200]; /* also D_004B7C3F */
char D_004B7840[0x200];
u8 D_004B7740[0x100];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/pad_set_enabled.c */
u8 D_004B6A68[0xcd8] __attribute__((aligned(8))); /* also D_004B6A6C, D_004B6A74, D_004B6A7E, D_004B6A82 */
u8 D_004B6A20[0x48]; /* also D_004B6A22 */
u8 D_004B6A00[0x20]; /* also D_004B6A02 */
#endif
u8 gPadState_004B6900[0x100];
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_write_checked.c */
s32 D_004B68D0[0xc];
u8 gMcDirBuf_004B68C0[0x10];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_read_checked.c */
u8 D_004B6474[0x44c] __attribute__((aligned(4))); /* also D_004B6478 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_set_error_status.c */
s32 D_004B6450[0x9];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_get_result.c */
s32 D_004B644C[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_read.c */
u8 D_004B63B4[0x98] __attribute__((aligned(4))); /* also gMcState_004B63B8, D_004B6418 */
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_copy_file.c */
s32 D_004B63B0[0x1];
s32 D_004B63AC[0x1];
s32 D_004B63A8[0x1];
s32 D_004B63A4[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_write.c */
s32 D_004B63A0[0x1];
u32 D_004B639C[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_read_checked.c */
s32 D_004B6398[0x1];
s32 D_004B6394[0x1];
s32 D_004B6390[0x1];
s32 D_004B638C[0x1];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/ee/mc_step_write_checked.c */
u8 D_004B6388[0x4];
u8 D_004B6384[0x4];
u8 D_004B6380[0x4];
#endif
#ifndef NONMATCHING /* the NONMATCHING build defines these in src/game/player/stats.c */
u8 D_004B6288[0xf8] __attribute__((aligned(8))); /* also D_004B628A */
u8 D_004B6284[0x4]; /* also D_004B6286 */
u8 D_004B6280[0x4]; /* also D_004B6282 */
u8 D_004B627C[0x4]; /* also D_004B627E */
u8 D_004B6278[0x4]; /* also D_004B6279, D_004B627A, D_004B627B */
u8 D_004B61F8[0x80] __attribute__((aligned(8))); /* also D_004B61FA, D_004B6276, D_004B6277 */
u8 D_004B61F4[0x4]; /* also D_004B61F6 */
u8 D_004B61F0[0x4]; /* also D_004B61F2 */
u8 D_004B61EC[0x4]; /* also D_004B61EE */
u8 D_004B61E8[0x4]; /* also D_004B61E9, D_004B61EA, D_004B61EB */
u8 D_004B6180[0x68]; /* also D_004B6182, D_004B6184, D_004B61E6, D_004B61E7 */
u8 D_004B617C[0x4]; /* also D_004B617E */
u8 D_004B6168[0x14] __attribute__((aligned(8))); /* also D_004B616A, D_004B617A */
u8 D_004B6164[0x4]; /* also D_004B6166 */
u8 D_004B6160[0x4]; /* also D_004B6162 */
u8 D_004B615C[0x4]; /* also D_004B615E */
u8 D_004B6158[0x4]; /* also D_004B6159, D_004B615A, D_004B615B */
u8 D_004B6130[0x28]; /* also D_004B6156, D_004B6157 */
u8 D_004B60D8[0x58] __attribute__((aligned(8))); /* also D_004B60DA */
u8 D_004B60D4[0x4]; /* also D_004B60D6 */
u8 D_004B60D0[0x4]; /* also D_004B60D2 */
u8 D_004B60CC[0x4]; /* also D_004B60CE */
u8 D_004B60C8[0x4]; /* also D_004B60C9, D_004B60CA, D_004B60CB */
u8 D_004B6048[0x80] __attribute__((aligned(8))); /* also D_004B604A, D_004B60C6, D_004B60C7 */
u8 D_004B6044[0x4]; /* also D_004B6046 */
u8 D_004B6040[0x4]; /* also D_004B6042 */
u8 D_004B603C[0x4]; /* also D_004B603E */
u8 D_004B6038[0x4]; /* also D_004B6039, D_004B603A, D_004B603B */
u8 D_004B5FB8[0x80] __attribute__((aligned(8))); /* also D_004B5FBA, D_004B6036, D_004B6037 */
u8 D_004B5FB4[0x4]; /* also D_004B5FB6 */
u8 D_004B5FB0[0x4]; /* also D_004B5FB2 */
u8 D_004B5FAC[0x4]; /* also D_004B5FAE */
u8 D_004B5FA8[0x4]; /* also D_004B5FA9, D_004B5FAA, D_004B5FAB */
u8 D_004B5F28[0x80] __attribute__((aligned(8))); /* also D_004B5F2A, D_004B5FA6, D_004B5FA7 */
u8 D_004B5F24[0x4]; /* also D_004B5F26 */
u8 D_004B5F20[0x4]; /* also D_004B5F22 */
u8 D_004B5F1C[0x4]; /* also D_004B5F1E */
u8 D_004B5F18[0x4]; /* also D_004B5F19, D_004B5F1A, D_004B5F1B */
u8 D_004B5EF0[0x28]; /* also D_004B5F16, D_004B5F17 */
u8 D_004B5E98[0x58] __attribute__((aligned(8))); /* also D_004B5E9A */
u8 D_004B5E94[0x4]; /* also D_004B5E96 */
u8 D_004B5E90[0x4]; /* also D_004B5E92 */
u8 D_004B5E8C[0x4]; /* also D_004B5E8D, D_004B5E8E, D_004B5E8F */
u8 D_004B5E60[0x2c]; /* also D_004B5E8A, D_004B5E8B */
#endif
u8 D_004B5E08[0x58] __attribute__((aligned(8))); /* also D_004B5E0A, D_004B5E0C */
u8 D_004B5E04[0x4]; /* also D_004B5E06 */
u8 D_004B5E00[0x4]; /* also D_004B5E02 */
u8 D_004B5DFC[0x4]; /* also D_004B5DFD, D_004B5DFE, D_004B5DFF */
u8 D_004B5DF0[0xc]; /* also D_004B5DFA, D_004B5DFB */
u8 D_004B5DD0[0x20];
