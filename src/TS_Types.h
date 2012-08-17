#ifndef TS_TYPES_H
#define TS_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_NUM_TASKS   10

struct s_TS_Task;

typedef uint64_t TS_Time_T;
typedef uint32_t TS_TimeSpan_T;
typedef struct s_TS_Task TS_Task_T;
typedef enum e_TS_Task_Results TS_Task_Results;

typedef TS_Task_Results(*TS_Callback_T)(void);

enum e_TS_Task_Results
{
    INCOMPLETE = -1,
    FINISHED = 0,
    CRASH_N_BURN = 1
};

struct s_TS_Task
{
    bool enabled;
    bool init_complete;
    bool needs_more_time;
    uint8_t priority;
    TS_Time_T next_do_time;
    TS_TimeSpan_T period_ms;
    TS_Callback_T callback;
    TS_TimeSpan_T init_delay_ms;
    TS_Callback_T init_func;
};


#endif
