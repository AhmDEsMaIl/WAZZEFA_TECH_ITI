/*
 * RTOS_program.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ibrahim
 */


/******************************************************************/
/*						   FILES INCLUSIONS			    		  */
/******************************************************************/
/*******************************LIB********************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../../RTOS_STACK/GIE/GIE_Interface.h"
#include "../../RTOS_STACK/RTOS/RTOS_Config.h"
#include "../../RTOS_STACK/RTOS/RTOS_Interface.h"
#include "../../RTOS_STACK/RTOS/RTOS_Private.h"
#include "../../RTOS_STACK/TIMER0/TIMERS_Interface.h"

/******************************MCAL********************************/


/******************************************************************/
/*Global Variables*/
/*Global Array of struct for tasks(uses in functions)*/
Task_t SystemTasks[TASK_NUM] = {{}};


/******************************************************************/
/*						FUNCTIONS DEFINITIONS					  */
/******************************************************************/
void RTOS_voidStart(void)
{
	TIMER_u8SetCallBack(&voidScheduler, TIMER_VECTOR_ID);
	GIE_voidEnable();
	TIMER0_voidInit();
}

u8 RTOS_u8CreateTask(u8 copy_u8Priority , u16 copy_u16Periodicity ,void (*copy_pvTaskFunc)(void))
{
	u8 Local_u8ErrorState = E_OK;

	/*Check if the required priority is empty or used before for another task*/
	if(SystemTasks[copy_u8Priority].TaskFunc == NULL)
	{
		SystemTasks[copy_u8Priority].Periodicity = copy_u16Periodicity;
		SystemTasks[copy_u8Priority].TaskFunc = copy_pvTaskFunc;
		//SystemTasks[copy_u8Priority].State = TASK_RESUMED;
	}
	else
	{
		/*Priority is reserved before, Don't create the task*/
		Local_u8ErrorState = E_NOK;
	}

	return Local_u8ErrorState;
}

/******************************************************************************/
/*API Name          :														  */
/*Description       : 														  */
/*Parameters in     : 														  */
/*Parameters out	:													      */
/*Parameters in/out : 														  */
/*Reentrancy        : 														  */
/*Synchronization   :														  */
/*Return            : 														  */
/******************************************************************************/
void RTOS_voidSuspendTask(u8 copy_u8Priority)
{
	//SystemTasks[copy_u8Priority].State = TASK_SUSPENDED;
}


void RTOS_voidResumeTask(u8 copy_u8Priority)
{
	//SystemTasks[copy_u8Priority].State = TASK_RESUMED;
}


void RTOS_voidDeleteTask(u8 copy_u8Priority)
{
	SystemTasks[copy_u8Priority].TaskFunc = NULL;
}


/*This function run in Timer ISR*/
static void voidScheduler(void)
{
	static u16 Local_u16TickCounter = 0;
	u8 Local_u8TaskCounter;

	Local_u16TickCounter++;

	for(Local_u8TaskCounter=0 ;Local_u8TaskCounter< TASK_NUM;Local_u8TaskCounter++)
	{
//		/*Check if the task is suspended or not*/
//		if(SystemTasks[Local_u8TaskCounter].State == TASK_RESUMED)
//		{

			/*periodicity*/
			if(Local_u16TickCounter % SystemTasks[Local_u8TaskCounter].Periodicity == 0)
			{

				/*Check the task function*/
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();

				}
				else
				{

				}
			}
			else
			{

			}

//		}
//		else
//		{
//			/*Task state*/
//		}


	}
}



