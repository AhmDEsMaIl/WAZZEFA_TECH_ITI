/*
 * TIMERS_Program.c
 *
 *  Created on: Mar 27, 2024
 *      Author: Ibrahim
 */


/******************LIB**********************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../../RTOS_STACK/TIMER0/TIMERS_Config.h"
#include "../../RTOS_STACK/TIMER0/TIMERS_Interface.h"
#include "../../RTOS_STACK/TIMER0/TIMERS_Private.h"

/******************MCAL*********************/


/**********Global pointer to array of functions***/
static void(*TIMERS_ptfCallBackFuncArr[2])(void)={NULL};

/*****************************************************/
/******************FUNCTIONS DEFINITIONS***************/
/*****************************************************/
/**************************************************************************************/
/*											TIM0									  */
/**************************************************************************************/

void TIMER0_voidInit(void)
{
	/*Set Configurable Modes*/
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

	/*Initialize Waveform Generation Mode as Normal Mode*/
	CLR_BIT(TCCR0 , TCCR0_WGM00) ;
	CLR_BIT(TCCR0 , TCCR0_WGM01) ;

	/*Set the Required Preload Value*/
	TCNT0 = TIMER0_PRELOAD_VAL ;

	/*Timer0 Overflow Interrupt Enable*/
#if TIMER0_OVERFLOW_INTERRUPT == DISABLE
	CLR_BIT(TIMSK , TIMSK_TOIE0) ;
#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
	SET_BIT(TIMSK , TIMSK_TOIE0) ;
#else
#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
#endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
	/*Initialize Waveform Generation Mode as PWM Mode*/
	SET_BIT(TCCR0 , TCCR0_WGM00) ;
	CLR_BIT(TCCR0 , TCCR0_WGM01) ;

	/*Set CTC PWM MODE*/
#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR0 , TCCR0_COM00) ;
	CLR_BIT(TCCR0 , TCCR0_COM01) ;
#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR0 , TCCR0_COM00) ;
	SET_BIT(TCCR0 , TCCR0_COM01) ;
#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR0 , TCCR0_COM00) ;
	SET_BIT(TCCR0 , TCCR0_COM01) ;
#else
#error "Wrong TIMER0_CTC_PWM_MODE Config"
#endif

	/*Set the Required CTC Value*/
	OCR0 = TIMER0_CTC_VAL ;

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

	/*Initialize Waveform Generation Mode as CTC Mode*/
	CLR_BIT(TCCR0 , TCCR0_WGM00) ;
	SET_BIT(TCCR0 , TCCR0_WGM01) ;

	/*Set the Required CTC Value*/
	OCR0 = TIMER0_CTC_VAL ;

	/*Timer0 Compare Match Interrupt Enable*/
#if TIMER0_CTC_INTERRUPT == DISABLE
	CLR_BIT(TIMSK , TIMSK_OCIE0) ;
#elif TIMER0_CTC_INTERRUPT == ENABLE
	SET_BIT(TIMSK , TIMSK_OCIE0) ;
#else
#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
#endif


	/*Set CTC PWM MODE*/
#if TIMER0_OC0_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR0 , TCCR0_COM00) ;
	CLR_BIT(TCCR0 , TCCR0_COM01) ;
#elif TIMER0_OC0_MODE == TIMER_OC_TOGGEL
	CLR_BIT(TCCR0 , TCCR0_COM01) ;
	SET_BIT(TCCR0 , TCCR0_COM00) ;
#elif TIMER0_OC0_MODE == TIMER_OC_LOW
	CLR_BIT(TCCR0 , TCCR0_COM00) ;
	SET_BIT(TCCR0 , TCCR0_COM01) ;
#elif TIMER0_OC0_MODE == TIMER_OC_HIGH
	SET_BIT(TCCR0 , TCCR0_COM00) ;
	SET_BIT(TCCR0 , TCCR0_COM01) ;
#else
#error "Wrong TIMER0_OC0_MODE Configuration parameter!"
#endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

	/*Initialize Waveform Generation Mode as Fast PWM Mode*/
	SET_BIT(TCCR0 , TCCR0_WGM00) ;
	SET_BIT(TCCR0 , TCCR0_WGM01) ;

	/*Set CTC Fast PWM MODE*/
#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR0 , TCCR0_COM00) ;
	CLR_BIT(TCCR0 , TCCR0_COM01) ;
#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR0 , TCCR0_COM00) ;
	SET_BIT(TCCR0 , TCCR0_COM01) ;
#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR0 , TCCR0_COM00) ;
	SET_BIT(TCCR0 , TCCR0_COM01) ;
#else
#error "Wrong TIMER0_CTC_PWM_MODE Config"
#endif

	/*Set the Required CTC Value*/
	OCR0 = TIMER0_CTC_VAL ;

#else
#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"

#endif

	/*Set the Required Prescaler*/
	TCCR0 &= TIMER_PRESCALER_MASK ;
	TCCR0 |= TIMER0_PRESCALER ;
}

void TIMER0_voidSetPreload(u8 copy_u8Preload)
{
	TCNT0 = copy_u8Preload ;
}

void TIMER0_voidSetCTC(u8 copy_u8CTC)
{
	OCR0 = copy_u8CTC ;
}


void TIMER0_voidSetFastPWM(u8 copy_u8PWM)
{
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
	/*Set the Required CTC Value*/
	OCR0 = copy_u8PWM ;
#endif
}


void TIMER0_voidSetPhaseCorrectPWM(u8 copy_u8PWM)
{
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
	/*Set the Required CTC Value*/
	OCR0 = copy_u8PWM ;
#endif
}

u8 TIMER0_u8GetTimerCounterValue(void)
{

	return TCNT0 ;
}





/*****************************************************************************************************/
u8 TIMER_u8SetCallBack(void(*copy_ptfCallBackFunc)(void),u8 copy_u8VectorID)
{
	u8 Local_u8ErrorState = E_OK;
	if((copy_u8VectorID<=TIMER0_OVF_VECTOR_ID) && (copy_u8VectorID>=TIMER0_CTC_VECTOR_ID))
	{
		u8 Local_u8ArrayIndex = copy_u8VectorID - CBF_OFFSET ;
		if(copy_ptfCallBackFunc!= NULL)
		{
			TIMERS_ptfCallBackFuncArr[Local_u8ArrayIndex]= copy_ptfCallBackFunc;
		}
		else
		{
			Local_u8ErrorState = E_NOK_NULL_PTR;
		}
	}
	else
	{
		Local_u8ErrorState = E_NOK_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}


/***************TIMER0 OVF************************/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMERS_ptfCallBackFuncArr[TIMER0_OVF_VECTOR_ID - CBF_OFFSET] != NULL)
	{
		TIMERS_ptfCallBackFuncArr[TIMER0_OVF_VECTOR_ID - CBF_OFFSET]();
	}
}


/***************TIMER0 CTC************************/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMERS_ptfCallBackFuncArr[TIMER0_CTC_VECTOR_ID - CBF_OFFSET] != NULL)
	{
		TIMERS_ptfCallBackFuncArr[TIMER0_CTC_VECTOR_ID - CBF_OFFSET]();
	}
}











