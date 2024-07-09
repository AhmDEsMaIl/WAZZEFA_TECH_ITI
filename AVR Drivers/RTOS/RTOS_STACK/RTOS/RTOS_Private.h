/*
 * RTOS_Private.h
 *
 *  Created on: Apr 8, 2024
 *      Author: Ibrahim
 */

#ifndef SERVICES_RTOS_PRIVATE_H_
#define SERVICES_RTOS_PRIVATE_H_


typedef struct
{
	u16 Periodicity			;
	void(*TaskFunc)(void)	;
	//u8 State				;
}Task_t;

/*******************PRIVATE FUNCTIONS***********************/
static void voidScheduler(void);


/********************PRIVATE MACROS************************/
#define TASK_RESUMED			1
#define TASK_SUSPENDED			2


#endif /* SERVICES_RTOS_PRIVATE_H_ */
