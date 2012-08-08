#include "unity.h"
#include "mock_TS_Timing.h"
#include "mock_TS_Priorities.h"
#include "TaskScheduler.h"
#include "TS_Types.h"


uint16_t t1_calls;

uint16_t t2_calls;

uint16_t t3_calls;



uint16_t t1_init_calls;

uint16_t t2_init_calls;

uint16_t t3_init_calls;



TS_Task_Results t1_rv = FINISHED;

TS_Task_Results t2_rv = FINISHED;

TS_Task_Results t3_rv = FINISHED;



void setUp()

{



    TS_Initialize();



    t1_calls = 0;

    t2_calls = 0;

    t3_calls = 0;

    t1_init_calls = 0;

    t2_init_calls = 0;

    t3_init_calls = 0;

}



void tearDown()

{

}



TS_Task_Results callback_t1(void){t1_calls++; return t1_rv;}

TS_Task_Results callback_t2(void){t2_calls++; return t2_rv;}

TS_Task_Results callback_t3(void){t3_calls++; return t3_rv;}



void init_func_t1(void){t1_init_calls++;}

void init_func_t2(void){t2_init_calls++;}

void init_func_t3(void){t3_init_calls++;}



void test_TS_AddTask_should_not_return_a_null_pointer()

{

    TS_Task_T * rv = TS_AddTask(100, 0, &callback_t1);



    if (((((void *)0)) != (rv))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)48);;};

}



void test_TS_AddTask_should_set_task_priority_correctly()

{

    TS_Task_T * rv = TS_AddTask(100, 3, &callback_t1);

    UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((rv->priority)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

}
