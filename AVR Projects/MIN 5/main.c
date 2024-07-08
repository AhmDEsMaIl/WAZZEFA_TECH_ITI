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
/****************************HAL**************************/

#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"

/*Inclusions*/
#include "avr/delay.h"

/**********************************/
#define GIFR			(*((volatile u8*)0x5A))
#define GIFR_INTF1		        7

/**********************************/
void func_1(void);
void func_2(void);

u16 TempValue_1;
u16 TempValue_2;

void func_1(void)
{
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidSendString((u8*)"Welcome to Room 1");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*)"Temp=");
	TempValue_1 =LM35_u16GetTempReading(1);
	LCD_voidSendNumber(TempValue_1);
	_delay_ms(2000);


}
void func_2(void)
{
	SET_BIT(GIFR,GIFR_INTF1);
	GIE_voidEnable();
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidSendString((u8*)"Welcome to Room 2");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*)"Temp=");
	TempValue_2 =LM35_u16GetTempReading(2);
	LCD_voidSendNumber(TempValue_2);
	_delay_ms(2000);


}
int main(void)
{
	/*Modules Initializations*/
	GIE_voidEnable();
	LCD_voidInit();
	LM35_voidInit();
	EXTI_voidInit();
	MOTOR_voidINIT();

	/*DIO Pins setup*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT);

	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);

	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);



	DIO_u8GetConnectPullUp(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);


	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);

	/*Enable External Interrupt 0*/
	EXTI_u8Int1SetCallBack(func_1);
	EXTI_u8Int2SetCallBack(func_2);

	/***************************************************************/

	while(1)
	{
		LCD_voidSetPosition(0,0);
		LCD_voidSendString((u8*)"MOTOR CCW");
		MOTOR_voidCounterClockwise();
		_delay_ms(3000);
		LCD_voidClearScreen();

		LCD_voidSendString((u8*)"MOTOR CW");
		MOTOR_voidClockwise();
		_delay_ms(3000);
		LCD_voidClearScreen();

	}
	return 0;
}

