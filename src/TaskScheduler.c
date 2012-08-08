#include "TaskScheduler.h"
#include "TS_Priorities.h"
#include "TS_Timing.h"

// Counter to keep track of the number of tasks created
uint16_t allocated_tasks = 0;

// This is the pool of tasks that can be assigned 
TS_Task_T task_pool[MAX_NUM_TASKS];

// This is an array of pointers to tasks. It will be populated with tasks that are ready to be executed.
TS_Task_T * pending_tasks[MAX_NUM_TASKS];

// Add a new task to the list of tasks to execute.
// p is the callback function to execute when the task is due
TS_Task_T * TS_AddTask(uint16_t period, TS_Callback_T p)
{
    // Allocate the task
    task_pool[allocated_tasks].period_ms = period;
    task_pool[allocated_tasks].callback = p;
    // Increment the count and return a pointer to the task
    return &task_pool[allocated_tasks++];
    
}

// This is the function that should be called from the main program loop
void TS_Process_Tasks(TS_Time_T current_time)
{
    // uint8_t num_tasks = TS_GetExpiredTaskList(task_pool, pending_tasks);
    // if(num_tasks)
    // {
    //     // Get the highest proiorty task in the list
    //     TS_Task_T * t = TS_GetHighestPriorityTask(pending_tasks, num_tasks);
    //     // Execute the task worker
    //     t->callback();
    //     // Update the tasks 

    // }
}
