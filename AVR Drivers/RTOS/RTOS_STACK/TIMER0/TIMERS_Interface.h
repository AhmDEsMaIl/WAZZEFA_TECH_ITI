/*
 * TIMERS_Interface.h
 *
 *  Created on: Mar 27, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_


/*********************GENERAL MACROS*******************/
/*Define Indexes for global pointer to function for ISR*/
#define	TIMER0_OVF_VECTOR_ID 		11
#define	TIMER0_CTC_VECTOR_ID 		10


/******************FUNCTIONS PROTOTYPES***************/
/******************TIM0************************/
void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(u8 copy_u8Preload);
void TIMER0_voidSetCTC(u8 copy_u8CTC);
void TIMER0_voidSetFastPWM(u8 copy_u8PWM);
void TIMER0_voidSetPhaseCorrectPWM(u8 copy_u8PWM);
u8 TIMER0_u8GetTimerCounterValue(void);




/**********************************************/
u8 TIMER_u8SetCallBack(void(*copy_ptfCallBackFunc)(void),u8 copy_u8VectorID);


#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
