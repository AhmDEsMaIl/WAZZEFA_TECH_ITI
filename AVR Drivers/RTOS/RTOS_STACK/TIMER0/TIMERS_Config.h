/*
 * TIMERS_Config.h
 *
 *  Created on: Mar 27, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMERS_TIMERS_CONFIG_H_
#define MCAL_TIMERS_TIMERS_CONFIG_H_


/************************************************************************************************/
/*								FREQUENCY OF SYSTEM 											*/
/************************************************************************************************/
#define FCLK											8000000


/************************************************************************************************/
/*								CONFIGURATIONS MACROS											*/
/************************************************************************************************/
#define TIMER_NORMAL_MODE						        1
#define TIMER_PWM_MODE							        2
#define TIMER_CTC_MODE							        3
#define TIMER_FAST_PWM_MODE						        4
/************************************************************************************************/
/*								TIMER 0 CONFIGURATIONS											*/
/************************************************************************************************/
/*Set Timer0 Waveform Generation Mode
 * Choose between
 * 1. TIMER_NORMAL_MODE
 * 2. TIMER_PWM_MODE
 * 3. TIMER_CTC_MODE
 * 4. TIMER_FAST_PWM_MODE
 */
#define TIMER0_WAVEFORM_GENERATION_MODE		TIMER_CTC_MODE

/*Set the Required Prescaler
 * Choose between
 * - TIMER_NO_CLOCK_SOURCE
 * - TIMER_NO_PRESCALER_FACTOR
 * - TIMER_DIVISION_FACTOR_8
 * - TIMER_DIVISION_FACTOR_64
 * - TIMER_DIVISION_FACTOR_256
 * - TIMER_DIVISION_FACTOR_1024
 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 */
#define TIMER0_PRESCALER		TIMER_DIVISION_FACTOR_64

#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

/*Set the Required Preload on TIMER0 Normal Mode*/
#define TIMER0_PRELOAD_VAL					0

/*Set Timer0 Overflow Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER0_OVERFLOW_INTERRUPT			ENABLE

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE

/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
#define TIMER0_CTC_VAL						128

/*Set PWM Mode
 * Choose between
 * 1. TIMER_OC_DISCONNECTED
 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
 */
#define TIMER0_CTC_PWM_MODE						TIMER_SET_ON_CTC_CLR_ON_TOP

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
#define TIMER0_CTC_VAL						125

/*Set Compare Match Output Mode
 * Choose between
 * 1. TIMER_OC_DISCONNECTED
 * 2. TIMER_OC_TOGGEL
 * 3. TIMER_OC_LOW
 * 4. TIMER_OC_HIGH
 */
#define TIMER0_OC0_MODE						TIMER_OC_DISCONNECTED

/*Set Timer0 CTC Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER0_CTC_INTERRUPT			ENABLE

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
#define TIMER0_CTC_VAL						255

/*Set PWM Mode
 * Choose between
 * 1. TIMER_OC_DISCONNECTED
 * 2. TIMER_CLR_ON_CTC_SET_ON_TOP
 * 3. TIMER_SET_ON_CTC_CLR_ON_TOP
 */
#define TIMER0_CTC_PWM_MODE						TIMER_CLR_ON_CTC_SET_ON_TOP

#else
#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"

#endif




#endif /* MCAL_TIMERS_TIMERS_CONFIG_H_ */