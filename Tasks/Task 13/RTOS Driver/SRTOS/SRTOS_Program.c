/*
 * SRTOS_Program.c
 *
 *  Created on: Apr 30, 2024
 *      Author: sakr3
 */
/************************************************************************************************/
/***********************LIB*************************/
#include "../include/LIB/BIT_Math.h"
#include "../include/LIB/STD_Types.h"

/***********************MCAL*************************/
#include "../include/SERVICES/SRTOS/SRTOS_Config.h"
#include "../include/SERVICES/SRTOS/SRTOS_Interface.h"
#include "../include/SERVICES/SRTOS/SRTOS_Private.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"



volatile  TCB_t TasksArray[MAX_TASK_NUM] = {NULL} ;


static void RTOS_voidScheduler (void)
{
	static u32 Local_u32Counter = 0 ;
	Local_u32Counter++ ;
	for (u8 i = 0 ; i < MAX_TASK_NUM ; i++)
	{
		if (((TasksArray[i].T_FD) == 0))
		{
			if((TasksArray[i].T_ptr!=NULL)&&((TasksArray[i].State) == Ready))
			{
				TasksArray[i].T_ptr() ;
			}
			else
			{

			}
			TasksArray[i].T_FD = TasksArray[i].T_priodicity-1;

		}
		else
		{
			TasksArray[i].T_FD -- ;
		}
	}
}
void RTOS_u8CreateTask( u8 copy_u8Priority , u32 copy_u16Periodicity , u32 copy_u32FirstDelay ,void (*copy_pvTaskFunc)(void))
{

	TasksArray[copy_u8Priority].T_FD = copy_u32FirstDelay ;
	TasksArray[copy_u8Priority].T_priodicity = copy_u16Periodicity ;
	TasksArray[copy_u8Priority].T_ptr = copy_pvTaskFunc ;
	TasksArray[copy_u8Priority].State = Ready ;
}
void RTOS_voidInit (void)
{
	MSYSTICK_voidInit() ;
	MSYSTICK_voidSetPeriodicInterval(RTOS_TICK ,&RTOS_voidScheduler) ;
}

void RTOS_voidSusbendTask(u8 copy_u8Priority)
{
	TasksArray[copy_u8Priority].State = Susbend ;
}
void RTOS_voidResumeTask(u8 copy_u8Priority)
{
	TasksArray[copy_u8Priority].State = Ready ;
}
void RTOS_voidDeleteTask(u8 copy_u8Priority)
{
	TasksArray[copy_u8Priority].State = Deleted ;
	TasksArray[copy_u8Priority].T_ptr =NULL ;


}


