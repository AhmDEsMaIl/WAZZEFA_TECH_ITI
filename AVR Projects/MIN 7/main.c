/*
 * main.c


 *
 *  Created on: Mar 20, 2024
 *      Author: ahmed
 */
/****************************LIB***************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"

/****************************MCAL**************************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/WDT/WDT_Interface.h"

/****************************HAL**************************/
#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"


/*Inclusions*/
#include "avr/delay.h"
#include "MCAL/WDT/WDT_Interface.h"



/***********************************************/
#define TIMSK		(*((volatile u8*)0x59))
#define TIMSK_TOIE0					0
/**********************************************/

u8 Global_Sec;
u8 Global_Min;
u8 Global_Hou;

void func_EX1(void);
void func_EX2(void);
void func_OVF(void);
void func_EX0(void);

void func_EX0(void)
{
	MWDT_SartWDT(WDT_MODE2048K);
}

void func_EX1(void)
{
	CLR_BIT(TIMSK , TIMSK_TOIE0);

}

void func_EX2(void)
{
	SET_BIT(TIMSK , TIMSK_TOIE0) ;

}
void func_OVF(void)
{
	static u8 Global_u8TickCounts;
	Global_u8TickCounts++;

	if(Global_u8TickCounts == 30)
	{
		Global_Sec++;
		if(Global_Sec==60)
		{
			Global_Sec=0;
			Global_Min++;
			if(Global_Min==60)
			{
				Global_Min=0;
				Global_Hou++;
				if(Global_Hou==24)
				{
					Global_Hou=0;
					Global_Min=0;
					Global_Sec=0;
				}
			}
		}
		Global_u8TickCounts = 0;
	}
}

int main(void)
{
	/*************************************************************/
	/*				 1- MODULES INITIALIZATION				     */
	/*************************************************************/
	GIE_voidEnable();
	EXTI_voidInit();
	TIMER0_voidInit();

	/*************************************************************/
	/*				         2- PIN SETUB				         */
	/*************************************************************/
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);

	DIO_u8GetConnectPullUp(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);




	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);


	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);


	DIO_u8SetPortDirection(DIO_PORTC,DIO_PORT_OUTPUT);

	/*************************************************************/
	/*				    3- SET CALLBACK FUNCTION				 */
	/*************************************************************/
	EXTI_u8Int0SetCallBack(func_EX0);
	EXTI_u8Int1SetCallBack(func_EX1);
	EXTI_u8Int2SetCallBack(func_EX2);
	TIMER_u8SetCallBack(func_OVF,TIMER0_OVF_VECTOR_ID);
	/***************************************************************/

	while(1)
	{
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,(Global_Sec%10));
		_delay_ms(10);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,(Global_Sec/10));
		_delay_ms(10);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);




		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,(Global_Min%10));
		_delay_ms(10);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,(Global_Min/10));
		_delay_ms(10);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);





		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,(Global_Hou%10));
		_delay_ms(10);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,(Global_Hou/10));
		_delay_ms(10);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}

	return 0;
}
