/*
 * RTOS_Interface.h
 *
 *  Created on: Apr 8, 2024
 *      Author: Ibrahim
 */

#ifndef SERVICES_RTOS_INTERFACE_H_
#define SERVICES_RTOS_INTERFACE_H_


/******************************************************************/
/*						FUNCTIONS PROTOTYPES					  */
/******************************************************************/
void RTOS_voidStart(void);
u8 RTOS_u8CreateTask(u8 copy_u8Priority , u16 copy_u16Periodicity ,void (*copy_pvTaskFunc)(void));
void RTOS_voidSuspendTask(u8 copy_u8Priority);
void RTOS_voidResumeTask(u8 copy_u8Priority);
void RTOS_voidDeleteTask(u8 copy_u8Priority);

#endif /* SERVICES_RTOS_INTERFACE_H_ */

