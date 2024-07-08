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


/*Inclusions*/
#include "avr/delay.h"
/**********************************/
#define GIFR			(*((volatile u8*)0x5A))
#define GIFR_INTF1		        7

/**********************************/
void func_1(void);
void func_2(void);


void func_1(void)
{
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,3);
	LCD_voidSendString("Welcome !");
	LCD_voidSetPosition(1,5);
	LCD_voidSendString("EIN_0");
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(5000);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);

}
void func_2(void)
{
	SET_BIT(GIFR,GIFR_INTF1);
	GIE_voidEnable();
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,3);
	LCD_voidSendString("Welcome !");
	LCD_voidSetPosition(1,5);
	LCD_voidSendString("EIN_1");
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

int main(void)
{
	/*Modules Initializations*/
	GIE_voidEnable();
	EXTI_voidInit();
	LCD_voidInit();
	/*DIO Pins setup*/
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	/*Enable External Interrupt 0*/
	EXTI_u8Int0SetCallBack(func_1);
	EXTI_u8Int1SetCallBack(func_2);

	while(1)
	{
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,5);
		LCD_voidSendString("Welcome");
		LCD_voidSetPosition(1,3);
		LCD_voidSendString("Wazeefa_Tech");
		_delay_ms(5000);
	}

	return 0;
}
