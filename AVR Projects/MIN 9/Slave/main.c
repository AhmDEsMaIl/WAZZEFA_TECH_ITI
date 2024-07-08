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
#include "MCAL/SPI_NEW/SPI.h"

/****************************HAL**************************/
#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"


/*Inclusions*/
#include "avr/delay.h"

int main(void)
{
	u8 Data_TX=0;
	u8 Data_RX=0;
	/*************************************************************/
	/*				 1- MODULES INITIALIZATION				     */
	/*************************************************************/

	/*************************************************************/
	/*				         2- PIN SETUB				         */
	/*************************************************************/
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);


	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);
	SPI_VoidInit();




	/*************************************************************/
	/*				    3- SET CALLBACK FUNCTION				 */
	/*************************************************************/

	/***************************************************************/
	while(1)
	{
		SPI_u8Tranceive(Data_TX,&Data_RX);
		if(Data_RX==0xC0)
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		}
	}

	return 0;
}

