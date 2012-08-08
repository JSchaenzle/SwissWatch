#ifndef TS_TYPES_H
#define TS_TYPES_H

#include <stdint.h>
#include <stdbool.h>

struct s_TS_Task;
struct s_TS_Task_Params;

typedef uint64_t TS_Time_T;
typedef uint32_t TS_TimeSpan_T;
typedef struct s_TS_Task_Params TS_Task_Params_T;
typedef void(*TS_Callback_T)(TS_Task_Params_T * args);
typedef struct s_TS_Task TS_Task_T;

struct s_TS_Task_Params
{
    /*
    Fill in if needed:

    Config_T * config;
    State_T * state;
    */
};

struct s_TS_Task
{
    bool enabled;
    TS_Task_T * next_task;
    TS_Task_T * prev_task;
    TS_Time_T next_do_time;
    TS_TimeSpan_T period_ms;
    TS_Callback_T callback;
};


#endif
