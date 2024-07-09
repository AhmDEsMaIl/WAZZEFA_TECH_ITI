/*
 * TIMERS_Private.h
 *
 *  Created on: Mar 27, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_

/****************************************************************************/
/*								REGISTERS									*/
/****************************************************************************/
/****************INT REGISTERS*****************/
#define TIMSK		(*((volatile u8*)0x59))
#define TIFR		(*((volatile u8*)0x58))


/******************TIM0************************/
#define TCCR0		(*((volatile u8*)0x53))
#define TCNT0		(*((volatile u8*)0x52))
#define OCR0		(*((volatile u8*)0x5C))


/****************************************************************************/
/*						        REGISTERS BITS								*/
/****************************************************************************/
/*TIMSK REGISTER*/
#define TIMSK_TOIE0					0
#define TIMSK_OCIE0					1
#define TIMSK_TOIE1					2
#define TIMSK_OCIE1B				3
#define TIMSK_OCIE1A				4
#define TIMSK_TICIE1				5
#define TIMSK_TOIE2					6
#define TIMSK_OCIE2					7


/*TIFR REGISTER*/
#define TIFR_TOV0					0
#define TIFR_OCF0					1
#define TIFR_TOV1					2
#define TIFR_OCF1B					3
#define TIFR_OCF1A					4
#define TIFR_ICF1					5
#define TIFR_TOV2					6
#define TIFR_OCF2					7


/******************TIM0************************/
/*TCCR0 REGISTER*/
#define TCCR0_CS00					0
#define TCCR0_CS01					1
#define TCCR0_CS02					2
#define TCCR0_WGM01					3
#define TCCR0_COM00					4
#define TCCR0_COM01					5
#define TCCR0_WGM00					6
#define TCCR0_FOC0					7


/********************************************************************/
/*******************PRIVATE MACROS***********************************/
#define CBF_OFFSET					4


#define DISABLE						                    0
#define ENABLE						                    1

#define FALLING_EDGE				                    0
#define RISING_EDGE					                    1

#define TIMER_NO_CLOCK_SOURCE	 	                    0
#define TIMER_NO_PRESCALER_FACTOR 	                    1
#define TIMER_DIVISION_FACTOR_8	 	                    2
#define TIMER_DIVISION_FACTOR_64	                    3
#define TIMER_DIVISION_FACTOR_256	                    4
#define TIMER_DIVISION_FACTOR_1024	                    5
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7

#define TIMER_PRESCALER_MASK					        0b11111000
#define TIMER_NORMAL_MODE						        1
#define TIMER_PWM_MODE							        2
#define TIMER_CTC_MODE							        3
#define TIMER_FAST_PWM_MODE						        4

#define TIMER_OC_DISCONNECTED					        0
#define TIMER_OC_TOGGEL							        1
#define TIMER_OC_LOW							        2
#define TIMER_OC_HIGH							        3

#define TIMER_OC_DISCONNECTED					        0
#define TIMER_CLR_ON_CTC_SET_ON_TOP				        2
#define TIMER_SET_ON_CTC_CLR_ON_TOP				        3


#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
