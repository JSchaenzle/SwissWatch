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

void test_TS_AddTask_should()

{

    TS_Task_T * task = TS_AddTask(10010U, &ExCallbackFunc1);



    UnityAssertEqualNumber((_U_SINT)((10010U)), (_U_SINT)((task->period_ms)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

}
