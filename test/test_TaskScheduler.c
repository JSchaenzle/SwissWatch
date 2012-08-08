#include "unity.h"
#include "TaskScheduler.h"
#include "TS_Types.h"

void setUp()
{
}

void tearDown()
{
}

void ExCallbackFunc1(TS_Task_Params_T * args)
{

}

void ExCallbackFunc2(TS_Task_Params_T * args)
{

}

// void test_TS_AddTask_should_return_the_total_number_of_allocated_tasks(void)
// {
//     // Call function under test
//     TS_AddTask(10000U, &ExCallbackFunc1);
//     TS_AddTask(10000U, &ExCallbackFunc2);

    
// }

void test_TS_AddTask_should()
{
    TS_Task_T * task = TS_AddTask(10010U, &ExCallbackFunc1);

    TEST_ASSERT_EQUAL(10010U, task->period_ms);
}