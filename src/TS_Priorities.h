#ifndef TS_PRIORITIES_H
#define TS_PRIORITIES_H

#include "TS_Types.h"

TS_Task_T * TS_GetHighestPriorityTask(TS_Task_T * p_list[], uint8_t num_tasks);

#endif
