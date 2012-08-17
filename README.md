**Swiss Watch:**

 - A priority based task scheduler for C.

**Setting Up Tasks**

At the start of the program each task must be initialized with a period, a priority and a callback function pointer.

    - Task Periods
        - The period of a task is the ideal number of milliseconds between calls to the tasks callback function

    - Task Priorities
        - Each task must be assigned a priority when it is initialized
        - The tasks priority is only taken into consideration in the case where multiple tasks are due at the same time
        - Tasks with higher priority (lower numeric value) will be executed first
        - Priority values can range from 0 (highest priority) to 255 (lowest priority)

    - Task Callback Functions
        - When a task is due the callback function is called.
        - The callback function must return the results of the task

    - Task Results
        - When a task is called it should not block execution any longer than necessary
        - Tasks should return FINISHED if they do not require further work until their next normal call
        - If a task occasionally needs more time to finish it's work it can return a result of INCOMPLETE
        - If a task returns INCOMPLETE it will be marked as "needs more time"
        - If the task scheduler determines that no tasks are due at a given time, it will call the highest priority task that "needs more time"
        - If a task determines that it needs to be disabled it can do so by returning KILL_TASK. This task will not be called again unless it is re-enabled.
        

**Monitoring Idle Time**

    By default, nothing happens when all tasks are idle. The task scheduler supports an Idle Callback which will be called during this time. This can be used to monitor the amount of time that the processor is idle. To do so use the TS_SetIdleFunc method. This function takes a function pointer to the function that you want to be called during idle time. The idle function cannot take any arguments.

    IMPORTANT: If this is running on a system with an OS where there are other processes running you need to implement a sleep function in idle function. Otherwise you will peg the processor at 100% for your process.  <-- Baaaaad


