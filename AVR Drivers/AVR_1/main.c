/*
 * main.c
 *
 *  Created on: Apr 3, 2024
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
#include "MCAL/SPI/SPI_Interface.h"

/****************************HAL**************************/
#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/FAN/FAN_Interface.h"


/*Inclusions*/
#include "avr/delay.h"
u16 Temp_1=0;
u16 Temp_2=0;
/************************* PRTOTYPES****************************************/
void Timer1_Func(void);
void IN0_Func(void);
void IN1_Func(void);
/**************************************************************************/


void Timer1_Func(void)
{
	static u8 c1=0;
	static u8 c2=0;
	TIMER1_voidSetPreload(65285);
	if(c1==2)
	{
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN0);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN1);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN2);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN3);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN4);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN5);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN6);
		DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN7);
		c2++;

	}
	if(c2==40)
	{
		Timer1_Interrupt_voidDisable();
		c2=0;
	}
	c1++;
}
void IN0_Func(void)
{
	u8 Dummy_1=5;
	SPI_u8Tranceive(1,&Dummy_1);
	_delay_ms(100);
	SPI_u8Tranceive(0xFF,&Temp_1);

}
void IN1_Func(void)
{
	u8 Dummy_2=10;
	SPI_u8Tranceive(2,&Dummy_2);
	_delay_ms(100);
	SPI_u8Tranceive(0xFF,&Temp_2);
}
int main(void)
{
	/*************************************************************/
	/*				         2- PIN SETUB				         */
	/*************************************************************/
	/*********************SPI PINS*******************************/
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);


	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);




	/*********************LED PINS*******************************/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);


	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);

	/*********************EXI PINS*******************************/
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);

	/*************************************************************/
	/*				 1- MODULES INITIALIZATION				     */
	/*************************************************************/
	GIE_voidEnable();
	LCD_voidInit();
	EXTI_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();
	TIMER2_voidInit();
	Timer1_Interrupt_voidDisable();
	USART_voidInit();
	SPI_VoidInit();
	FAN_INIT();
	/*************************************************************/
	/*				    3- SET CALLBACK FUNCTION				 */
	/*************************************************************/
	TIMER_u8SetCallBack(Timer1_Func,TIMER1_OVF_VECTOR_ID);
	EXTI_u8Int0SetCallBack(IN0_Func);
	EXTI_u8Int1SetCallBack(IN1_Func);
	/***************************************************************/
	TIMER1_voidSetPreload(65285);
	u8 Receive_ERROR=0;
	//USART_u8SendStringSynch("Hi");
	u8 x=255;
	while(1)
	{
		USART_u8RecevieData(&Receive_ERROR);
		//USART_u8SendData(1);
		if(Receive_ERROR==1)
		{
			/**********************FAN 1********************************/
			if(Temp_1>=14  && Temp_1<20)
			{
				//low
				FAN_Speed_1(64);

			}
			else if(Temp_1>=20 && Temp_1<30)
			{
				// medium
				FAN_Speed_1(128);
			}
			else if(Temp_1>=30)
			{
				// high
				FAN_Speed_1(255);

			}

			/**********************FAN 2********************************/
			if(Temp_2>=14  && Temp_2<20)
			{
				//low
				FAN_Speed_2(64);
			}
			else if(Temp_2>=20 && Temp_2<30)
			{
				// medium
				FAN_Speed_2(128);
			}
			else if(Temp_2>=30)
			{
				// high
				FAN_Speed_2(255);

			}
		}
		else if(Receive_ERROR==5)
		{
			Timer1_Interrupt_voidEnable();
			Receive_ERROR=-1;
		}

	}
	return 0;
}
