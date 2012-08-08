#include "TaskScheduler.h"
#include "TS_Priorities.h"
#include "TS_Timing.h"

// Counter to keep track of the number of tasks created
static uint16_t allocated_tasks = 0;

// This is the pool of tasks that can be assigned 
static TS_Task_T task_pool[MAX_NUM_TASKS];

static bool all_tasks_initialized = false;

// The idle function pointer. By default it is null
static TS_Callback_T idle_function;

// local function for executing a task
static void executeTaskAndHandleResults(TS_Task_T * t, TS_Time_T current_time);

// This function initialize internal crap of the scheduler. It must be called at the very beginning of the program
void TS_Initialize(void)
{
    int i;
    for(i=0; i<MAX_NUM_TASKS; i++)
    {
        task_pool[i].enabled = false;
        task_pool[i].needs_more_time = false;
        task_pool[i].init_complete = false;
    }
}

// Add a new task to the list of tasks to execute.
// p is the callback function to execute when the task is due
TS_Task_T * TS_AddTask(uint16_t period, uint8_t priority, TS_Callback_T f)
{
    // Initialize the task
    TS_Task_T * t = &task_pool[allocated_tasks];
    t->period_ms = period;
    t->callback = f;
    t->init_complete = true;        // At this point we don't have an init func.
    t->needs_more_time = false;
    t->enabled = true;
    all_tasks_initialized = false;
    // Increment the count and return a pointer to the task
    allocated_tasks++;
    return t;
}

// Every task can have an Init function that is called once after a specific amount of time
// after startup. Use this function to setup the init function for a task.
// Calling this is optional. By defalt there is no init funcion for tasks.
void TS_SetupTaskInitFunc(TS_Task_T * p_task, TS_Callback_T f, TS_TimeSpan_T delay)
{
    p_task->init_delay_ms = delay;
    p_task->init_func = f;
    p_task->init_complete = false;
}

void TS_SetIdleFunc(TS_Callback_T f)
{
    idle_function = f;
}

// This is the function that should be called from the main program loop
void TS_Process_Tasks(TS_Time_T current_time)
{
    // declare an array of pointers to tasks.
    TS_Task_T * pending_tasks[MAX_NUM_TASKS];

    // Check for tasks ready to be initialized
    ahhhah

    {
        // Check for expired tasks
        uint8_t task_cnt = TS_GetExpiredTaskList(task_pool, pending_tasks);
        
        if(task_cnt)
        {
            // Get the highest priority one if there are multiple
            TS_Task_T * t = TS_GetHighestPriorityTask(pending_tasks, task_cnt);
            executeTaskAndHandleResults(t, current_time);
        }
        else
        {
            // Check for tasks that need more work
            task_cnt = TS_GetTasksNeedingMoreWork(pending_tasks);
            // Get the highest priority one if there are multiple;
            if(task_cnt)
            {
                // Get the highest priority one if there are multiple
                TS_Task_T * t = TS_GetHighestPriorityTask(pending_tasks, task_cnt);
                executeTaskAndHandleResults(t, current_time);
            }
            else
            {
                // Call the idle function (if it has been defined!)
                if(idle_function) idle_function();
            }
        }
    }
}

static void executeTaskAndHandleResults(TS_Task_T * t, TS_Time_T current_time)
{
    // Call the task callback
    TS_Task_Results r = t->callback();
    // Set the next call time
    t->next_do_time = TS_GetNextCallTime(t->period, current_time);
    // Handle the results
    t->needs_more_time = false;
    if(r == INCOMPLETE) 
        t->needs_more_time = true;
    else if (r == KILL_TASK) 
        t->enabled = false;
}
