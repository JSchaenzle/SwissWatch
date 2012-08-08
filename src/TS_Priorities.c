#include "TS_Priorities.h"

// This function takes a pointer to an array of pointers to Tasks.
TS_Task_T * TS_GetHighestPriorityTask(TS_Task_T * p_list[], uint8_t num_tasks)
{
    TS_Task_T * t = p_list[0]
    uint8_t max_priority = *p_list
    int i;
    for(i=0; i <num_tasks; i++)
    {
        if(*p_list[i]->priority > max_priority)
        {
            t = p_list[i];
            max_priority = p_list[i]->priority
        }
    }
    return t;
}

TS_Task_T * TS_GetTasksNeedingMoreWork(TS_Task_T * p_list[], uint8_t num_tasks)
{

}
