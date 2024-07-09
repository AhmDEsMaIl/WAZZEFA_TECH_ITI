/*
 * SRTOS_Private.h
 *
 *  Created on: 30 Apr 2024
 *      Author: User
 */

#ifndef SRTOS_PRIVATE_H_
#define SRTOS_PRIVATE_H_


/****************************************************************************/
/*						TASK STRUCTURE									*/
/****************************************************************************/

static void RTOS_voidScheduler (void);

#define ONE_MS           2000
#define TWO_MS           4000

//free rtos implementaion ->build software ->using struct
//free rtos ->user view -> parameters ->separate
typedef struct
{
	u8 State;
	u32 T_priodicity;
	u32 T_FD;
	void (*T_ptr)(void);
}TCB_t;



#define Ready          1
#define Deleted        2
#define Resume         3
#define Susbend        4


#endif /* SRTOS_PRIVATE_H_ */
