#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include "TS_Types.h"

#define MAX_NUM_TASKS   10

TS_Task_T * TS_AddTask(uint16_t period, TS_Callback_T p);

void TS_Process_Tasks(TS_Time_T current_time);

#endif 
