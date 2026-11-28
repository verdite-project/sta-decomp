#include "common.h"
#include "game/core.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } Clk;
typedef struct { s32 a, b; } Pair;
typedef struct { s8 a, b; } P;
typedef struct { P p[4]; } Q;
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } CdClock;
extern Clk gPlayTimeSbss_00202388;
extern Clk gPlayTimeSbss_00202398;
extern Pair gPlayTimeSbss_00202380;
extern Pair gPlayTimeSbss_002023A0;
#ifndef NONMATCHING
extern int gPlayTimeSbss_00202390;
#else
/* data twins (src/game/data/sbss.c): gPlayTimeSbss_00202390 */
static int gPlayTimeSbss_00202390;
#endif
s32 PlayTime_Update_1_001DF670(void);
s32 PlayTime_Diff_2_001DF790(Clk a, Clk b);
void PlayTime_DiffNow_2_001DF910(void);
void PlayTime_CopyClock_1_001DF930(Q *p);
void PlayTime_Load_1_001DFAA0(Clk *a);
void PlayTime_Reset_1_001DFBB0(void);
s32 mktime(struct tm *);
void sceCdReadClock(void *);

/* PlayTime_Update_1_001DF670 */
#define PlayTime_DiffNow_2_001DF910 PlayTime_DiffNow_2_001DF910__as_PlayTime_Update_1_001DF670
s32 PlayTime_DiffNow_2_001DF910__as_PlayTime_Update_1_001DF670(void);

s32 PlayTime_Update_1_001DF670(void) {
    s32 r;
    Clk t;
    r = PlayTime_DiffNow_2_001DF910();
    t = gPlayTimeSbss_00202388;
    r += t.second + (t.minute + (t.hour + t.day * 99) * 60) * 60;
    gPlayTimeSbss_00202398.second = r % 60;
    gPlayTimeSbss_00202398.minute = (r / 60) % 60;
    gPlayTimeSbss_00202398.hour = (r / 3600) % 99;
    gPlayTimeSbss_00202398.day = r / 356400;
    return 1;
}
#undef PlayTime_DiffNow_2_001DF910

/* PlayTime_Diff_2_001DF790 */
struct tm { s32 tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst; };
static inline s32 yday(Clk c) {
    struct tm t;
    t.tm_sec = c.second;
    t.tm_min = c.minute;
    t.tm_hour = c.hour;
    t.tm_mday = c.day - 1;
    t.tm_mon = c.month - 1;
    t.tm_year = c.year + 100;
    mktime(&t);
    return t.tm_yday;
}
s32 PlayTime_Diff_2_001DF790(Clk a, Clk b) {
    s32 d1 = yday(a);
    s32 d2 = yday(b);
    if (a.year != b.year) {
        s32 k; if (a.year % 4) k = (b.year - a.year) * 365; else k = (b.year - a.year) * 366; d2 += k;
    }
    return (b.second - a.second) + ((b.minute - a.minute) + ((b.hour - a.hour) + (d2 - d1) * 24) * 60) * 60;
}

/* PlayTime_DiffNow_2_001DF910 */
#define PlayTime_Diff_2_001DF790 PlayTime_Diff_2_001DF790__as_PlayTime_DiffNow_2_001DF910
void PlayTime_Diff_2_001DF790__as_PlayTime_DiffNow_2_001DF910(Pair a, Pair b);

void PlayTime_DiffNow_2_001DF910(void)
{
    PlayTime_Diff_2_001DF790(gPlayTimeSbss_00202380, gPlayTimeSbss_002023A0);
}
#undef PlayTime_Diff_2_001DF790

/* PlayTime_CopyClock_1_001DF930 */
#define gPlayTimeSbss_00202398 gPlayTimeSbss_00202398__as_PlayTime_CopyClock_1_001DF930
extern Q gPlayTimeSbss_00202398__as_PlayTime_CopyClock_1_001DF930;
void PlayTime_CopyClock_1_001DF930(Q *p) { *p = gPlayTimeSbss_00202398; }
#undef gPlayTimeSbss_00202398

/* PlayTime_Resume_1_001DF960 */
/* Commit a pending pair of 64-bit values. */

#define gPlayTimeSbss_00202398 gPlayTimeSbss_00202398__as_PlayTime_Resume_1_001DF960
extern long long gPlayTimeSbss_00202398__as_PlayTime_Resume_1_001DF960;
#define gPlayTimeSbss_002023A0 gPlayTimeSbss_002023A0__as_PlayTime_Resume_1_001DF960
extern long long gPlayTimeSbss_002023A0__as_PlayTime_Resume_1_001DF960;
#define gPlayTimeSbss_00202388 gPlayTimeSbss_00202388__as_PlayTime_Resume_1_001DF960
extern long long gPlayTimeSbss_00202388__as_PlayTime_Resume_1_001DF960;
#define gPlayTimeSbss_00202380 gPlayTimeSbss_00202380__as_PlayTime_Resume_1_001DF960
extern long long gPlayTimeSbss_00202380__as_PlayTime_Resume_1_001DF960;

void PlayTime_Resume_1_001DF960(void)
{
    if (gPlayTimeSbss_00202390) {
        gPlayTimeSbss_00202388 = gPlayTimeSbss_00202398;
        gPlayTimeSbss_00202380 = gPlayTimeSbss_002023A0;
        gPlayTimeSbss_00202390 = 0;
    }
}
#undef gPlayTimeSbss_00202398
#undef gPlayTimeSbss_002023A0
#undef gPlayTimeSbss_00202388
#undef gPlayTimeSbss_00202380

/* PlayTime_Pause_1_001DF990 */
void PlayTime_Pause_1_001DF990(void) {
    gPlayTimeSbss_00202390 = 1;
}

/* PlayTime_Tick_1_001DF9A0 */
#define sceCdReadClock sceCdReadClock__as_PlayTime_Tick_1_001DF9A0
void sceCdReadClock__as_PlayTime_Tick_1_001DF9A0(CdClock *);
#define PlayTime_Update_1_001DF670 PlayTime_Update_1_001DF670__as_PlayTime_Tick_1_001DF9A0
void PlayTime_Update_1_001DF670__as_PlayTime_Tick_1_001DF9A0(void);
#define gPlayTimeSbss_002023A0 gPlayTimeSbss_002023A0__as_PlayTime_Tick_1_001DF9A0
extern CdClock gPlayTimeSbss_002023A0__as_PlayTime_Tick_1_001DF9A0;
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
s32 PlayTime_Tick_1_001DF9A0(void) {
    if (gPlayTimeSbss_00202390 != 0) return 0;
    sceCdReadClock(&gPlayTimeSbss_002023A0);
    gPlayTimeSbss_002023A0.second = BCD(gPlayTimeSbss_002023A0.second);
    gPlayTimeSbss_002023A0.minute = BCD(gPlayTimeSbss_002023A0.minute);
    gPlayTimeSbss_002023A0.hour = BCD(gPlayTimeSbss_002023A0.hour);
    gPlayTimeSbss_002023A0.day = BCD(gPlayTimeSbss_002023A0.day);
    gPlayTimeSbss_002023A0.month = BCD(gPlayTimeSbss_002023A0.month);
    gPlayTimeSbss_002023A0.year = BCD(gPlayTimeSbss_002023A0.year);
    PlayTime_Update_1_001DF670();
    return 1;
}
#undef sceCdReadClock
#undef PlayTime_Update_1_001DF670
#undef gPlayTimeSbss_002023A0

/* PlayTime_Load_1_001DFAA0 */
#define gPlayTimeSbss_00202380 gPlayTimeSbss_00202380__as_PlayTime_Load_1_001DFAA0
extern Clk gPlayTimeSbss_00202380__as_PlayTime_Load_1_001DFAA0;
#define sceCdReadClock sceCdReadClock__as_PlayTime_Load_1_001DFAA0
void sceCdReadClock__as_PlayTime_Load_1_001DFAA0(Clk *);
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
void PlayTime_Load_1_001DFAA0(Clk *a) {
    gPlayTimeSbss_00202390 = 0;
    gPlayTimeSbss_00202388.second = a->second;
    gPlayTimeSbss_00202388.minute = a->minute;
    gPlayTimeSbss_00202388.hour = a->hour;
    gPlayTimeSbss_00202388.day = a->day;
    gPlayTimeSbss_00202388.month = a->month;
    gPlayTimeSbss_00202388.year = a->year;
    sceCdReadClock(&gPlayTimeSbss_00202380);
    gPlayTimeSbss_00202380.second = BCD(gPlayTimeSbss_00202380.second);
    gPlayTimeSbss_00202380.minute = BCD(gPlayTimeSbss_00202380.minute);
    gPlayTimeSbss_00202380.hour = BCD(gPlayTimeSbss_00202380.hour);
    gPlayTimeSbss_00202380.day = BCD(gPlayTimeSbss_00202380.day);
    gPlayTimeSbss_00202380.month = BCD(gPlayTimeSbss_00202380.month);
    gPlayTimeSbss_00202380.year = BCD(gPlayTimeSbss_00202380.year);
}
#undef sceCdReadClock
#undef gPlayTimeSbss_00202380

/* PlayTime_Reset_1_001DFBB0 */
#define gPlayTimeSbss_00202380 gPlayTimeSbss_00202380__as_PlayTime_Reset_1_001DFBB0
extern Clk gPlayTimeSbss_00202380__as_PlayTime_Reset_1_001DFBB0;
#define sceCdReadClock sceCdReadClock__as_PlayTime_Reset_1_001DFBB0
void sceCdReadClock__as_PlayTime_Reset_1_001DFBB0(Clk *);
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
void PlayTime_Reset_1_001DFBB0(void) {
    gPlayTimeSbss_00202390 = 0;
    gPlayTimeSbss_00202388.second = 0;
    gPlayTimeSbss_00202388.minute = 0;
    gPlayTimeSbss_00202388.hour = 0;
    gPlayTimeSbss_00202388.day = 0;
    gPlayTimeSbss_00202388.month = 0;
    gPlayTimeSbss_00202388.year = 0;
    sceCdReadClock(&gPlayTimeSbss_00202380);
    gPlayTimeSbss_00202380.second = BCD(gPlayTimeSbss_00202380.second);
    gPlayTimeSbss_00202380.minute = BCD(gPlayTimeSbss_00202380.minute);
    gPlayTimeSbss_00202380.hour = BCD(gPlayTimeSbss_00202380.hour);
    gPlayTimeSbss_00202380.day = BCD(gPlayTimeSbss_00202380.day);
    gPlayTimeSbss_00202380.month = BCD(gPlayTimeSbss_00202380.month);
    gPlayTimeSbss_00202380.year = BCD(gPlayTimeSbss_00202380.year);
}
#undef sceCdReadClock
#undef gPlayTimeSbss_00202380

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): gPlayTimeSbss_00202380, gPlayTimeSbss_00202388, gPlayTimeSbss_00202398, gPlayTimeSbss_002023A0 */
Pair gPlayTimeSbss_00202380;
Clk gPlayTimeSbss_00202388;
Clk gPlayTimeSbss_00202398;
Pair gPlayTimeSbss_002023A0;
#endif
