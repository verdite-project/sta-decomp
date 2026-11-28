#include "common.h"
#include "game/core.h"
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } Clk;
typedef struct { s32 a, b; } Pair;
typedef struct { s8 a, b; } P;
typedef struct { P p[4]; } Q;
typedef struct { u8 stat, second, minute, hour, pad, day, month, year; } CdClock;
extern Clk D_00202388;
extern Clk D_00202398;
extern Pair D_00202380;
extern Pair D_002023A0;
#ifndef NONMATCHING
extern int D_00202390;
#else
/* data twins (src/game/data/sbss.c): D_00202390 */
static int D_00202390;
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
    t = D_00202388;
    r += t.second + (t.minute + (t.hour + t.day * 99) * 60) * 60;
    D_00202398.second = r % 60;
    D_00202398.minute = (r / 60) % 60;
    D_00202398.hour = (r / 3600) % 99;
    D_00202398.day = r / 356400;
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
    PlayTime_Diff_2_001DF790(D_00202380, D_002023A0);
}
#undef PlayTime_Diff_2_001DF790

/* PlayTime_CopyClock_1_001DF930 */
#define D_00202398 D_00202398__as_PlayTime_CopyClock_1_001DF930
extern Q D_00202398__as_PlayTime_CopyClock_1_001DF930;
void PlayTime_CopyClock_1_001DF930(Q *p) { *p = D_00202398; }
#undef D_00202398

/* PlayTime_Resume_1_001DF960 */
/* Commit a pending pair of 64-bit values. */

#define D_00202398 D_00202398__as_PlayTime_Resume_1_001DF960
extern long long D_00202398__as_PlayTime_Resume_1_001DF960;
#define D_002023A0 D_002023A0__as_PlayTime_Resume_1_001DF960
extern long long D_002023A0__as_PlayTime_Resume_1_001DF960;
#define D_00202388 D_00202388__as_PlayTime_Resume_1_001DF960
extern long long D_00202388__as_PlayTime_Resume_1_001DF960;
#define D_00202380 D_00202380__as_PlayTime_Resume_1_001DF960
extern long long D_00202380__as_PlayTime_Resume_1_001DF960;

void PlayTime_Resume_1_001DF960(void)
{
    if (D_00202390) {
        D_00202388 = D_00202398;
        D_00202380 = D_002023A0;
        D_00202390 = 0;
    }
}
#undef D_00202398
#undef D_002023A0
#undef D_00202388
#undef D_00202380

/* PlayTime_Pause_1_001DF990 */
void PlayTime_Pause_1_001DF990(void) {
    D_00202390 = 1;
}

/* PlayTime_Tick_1_001DF9A0 */
#define sceCdReadClock sceCdReadClock__as_PlayTime_Tick_1_001DF9A0
void sceCdReadClock__as_PlayTime_Tick_1_001DF9A0(CdClock *);
#define PlayTime_Update_1_001DF670 PlayTime_Update_1_001DF670__as_PlayTime_Tick_1_001DF9A0
void PlayTime_Update_1_001DF670__as_PlayTime_Tick_1_001DF9A0(void);
#define D_002023A0 D_002023A0__as_PlayTime_Tick_1_001DF9A0
extern CdClock D_002023A0__as_PlayTime_Tick_1_001DF9A0;
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
s32 PlayTime_Tick_1_001DF9A0(void) {
    if (D_00202390 != 0) return 0;
    sceCdReadClock(&D_002023A0);
    D_002023A0.second = BCD(D_002023A0.second);
    D_002023A0.minute = BCD(D_002023A0.minute);
    D_002023A0.hour = BCD(D_002023A0.hour);
    D_002023A0.day = BCD(D_002023A0.day);
    D_002023A0.month = BCD(D_002023A0.month);
    D_002023A0.year = BCD(D_002023A0.year);
    PlayTime_Update_1_001DF670();
    return 1;
}
#undef sceCdReadClock
#undef PlayTime_Update_1_001DF670
#undef D_002023A0

/* PlayTime_Load_1_001DFAA0 */
#define D_00202380 D_00202380__as_PlayTime_Load_1_001DFAA0
extern Clk D_00202380__as_PlayTime_Load_1_001DFAA0;
#define sceCdReadClock sceCdReadClock__as_PlayTime_Load_1_001DFAA0
void sceCdReadClock__as_PlayTime_Load_1_001DFAA0(Clk *);
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
void PlayTime_Load_1_001DFAA0(Clk *a) {
    D_00202390 = 0;
    D_00202388.second = a->second;
    D_00202388.minute = a->minute;
    D_00202388.hour = a->hour;
    D_00202388.day = a->day;
    D_00202388.month = a->month;
    D_00202388.year = a->year;
    sceCdReadClock(&D_00202380);
    D_00202380.second = BCD(D_00202380.second);
    D_00202380.minute = BCD(D_00202380.minute);
    D_00202380.hour = BCD(D_00202380.hour);
    D_00202380.day = BCD(D_00202380.day);
    D_00202380.month = BCD(D_00202380.month);
    D_00202380.year = BCD(D_00202380.year);
}
#undef sceCdReadClock
#undef D_00202380

/* PlayTime_Reset_1_001DFBB0 */
#define D_00202380 D_00202380__as_PlayTime_Reset_1_001DFBB0
extern Clk D_00202380__as_PlayTime_Reset_1_001DFBB0;
#define sceCdReadClock sceCdReadClock__as_PlayTime_Reset_1_001DFBB0
void sceCdReadClock__as_PlayTime_Reset_1_001DFBB0(Clk *);
#define BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)
void PlayTime_Reset_1_001DFBB0(void) {
    D_00202390 = 0;
    D_00202388.second = 0;
    D_00202388.minute = 0;
    D_00202388.hour = 0;
    D_00202388.day = 0;
    D_00202388.month = 0;
    D_00202388.year = 0;
    sceCdReadClock(&D_00202380);
    D_00202380.second = BCD(D_00202380.second);
    D_00202380.minute = BCD(D_00202380.minute);
    D_00202380.hour = BCD(D_00202380.hour);
    D_00202380.day = BCD(D_00202380.day);
    D_00202380.month = BCD(D_00202380.month);
    D_00202380.year = BCD(D_00202380.year);
}
#undef sceCdReadClock
#undef D_00202380

#ifdef NONMATCHING
#pragma explicit_zero_data on
/* data twins (src/game/data/sbss.c): D_00202380, D_00202388, D_00202398, D_002023A0 */
Pair D_00202380;
Clk D_00202388;
Clk D_00202398;
Pair D_002023A0;
#endif
