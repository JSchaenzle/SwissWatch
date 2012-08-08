#ifndef TS_TIMING_H
#define TS_TIMING_H
#include "TS_Types.h"

uint8_t TS_GetExpiredTaskList(pending_tasks);

TS_Time_T TS_GetNextCallTime(TS_TimeSpan_T period, TS_Time_T current_time);

#endif
