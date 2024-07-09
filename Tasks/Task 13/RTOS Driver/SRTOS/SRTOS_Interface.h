/*
 * SRTOS_Interface.h
 *
 *  Created on: 30 Apr 2024
 *      Author: User
 */

#ifndef SRTOS_INTERFACE_H_
#define SRTOS_INTERFACE_H_



/************************************************************************************************/
/*									FUNCTIONS API's												*/
/************************************************************************************************/


void RTOS_voidInit();
void RTOS_u8CreateTask( u8 copy_u8Priority , u32 copy_u16Periodicity , u32 copy_u32FirstDelay ,void (*copy_pvTaskFunc)(void));
void RTOS_voidSusbendTask(u8 copy_u8Priority);
void RTOS_voidDeleteTask(u8 copy_u8Priority);
void RTOS_voidResumeTask(u8 copy_u8Priority);

#endif /* SRTOS_INTERFACE_H_ */
