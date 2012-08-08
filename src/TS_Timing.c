#include "TS_Timing.h"

static bool isTaskDue(TS_Time_T current_time, TS_TimeSpan_T period, TS_Time_T next_due_time);

uint8_t TS_GetExpiredTaskList(TS_Task_T task_pool[], TS_Task_T * pending_tasks[])
{
    uint8_t cnt = 0;
    uint8_t i;

    for(i=0; i< MAX_NUM_TASKS; i++)
    {
        // First check if the task is enabled
        TS_Task_T * t = &task_pool[i];
        if(t->enabled && t->init_complete)
        {
            bool is_due = isTaskDue(t->current_time, t->period, t->next_due_time);
            if(is_due)
            {
                pending_tasks
            }
        }
    }
}

TS_Time_T TS_GetNextCallTime(TS_TimeSpan_T period, TS_Time_T current_time)
{
    return current_time + period;
}

static bool isTaskDue(TS_Time_T current_time, TS_TimeSpan_T period, TS_Time_T next_due_time)
{
    if(current_time < next_due_time) 
        return false;
    else if(current_time == next_due_time)
        return true;
    else
    {
        // Handle the wrap around situation
        if((current_time + period) < current_time)) 
            return false;
        else 
            return true;
    }
}

