#include "common.h"
#include "game/data.h"

/* rodata_001FD698: the game's data at 0x001FD698..., one object per label. */
/* used by: notify */
#pragma explicit_zero_data on


#ifndef NONMATCHING /* the NONMATCHING build defines these in their owners */
const s8 gNotifyRodata_001FD698[0x8] = "%d\000\000\000\000\000\000";
const s8 gNotifyRodata_001FD6A0[0x8] = { -0x7f, 0x7e, 0x20, 0x25, 0x64, 0, 0, 0 };
const s8 gNotifyRodata_001FD6A8[0x8] = { -0x7e, 0x62, 0x20, 0x25, 0x64, 0, 0, 0 };
const s32 jtbl_001FD6B0[0x8] __attribute__((aligned(8))) = { (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x698), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x48), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x1A0), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x2C0), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x370), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x428), (s32)((u8 *)Inventory_Sort_0_0019FD00 + 0x500), 0 };
#endif
