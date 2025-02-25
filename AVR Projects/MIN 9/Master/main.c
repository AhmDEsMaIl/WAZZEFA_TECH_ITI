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


/*Inclusions*/
#include "avr/delay.h"

int main(void)
{
	u8 value=0;
	u8 Data_TX=0xFF;
	u8 Data_RX=0;
	/*************************************************************/
	/*				 1- MODULES INITIALIZATION				     */
	/*************************************************************/
	/*************************************************************/
	/*				         2- PIN SETUB				         */
	/*************************************************************/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);




	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	//DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);

	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);

	SPI_VoidInit();


	/*************************************************************/
	/*				    3- SET CALLBACK FUNCTION				 */
	/*************************************************************/

	/***************************************************************/
	while(1)
	{
		DIO_u8GetPinValue(DIO_PORTA,DIO_PIN0,&value);
        if(value==DIO_PIN_HIGH)
        {
        	SPI_u8Tranceive(0xC0,&Data_RX);
        }
        else if (value==DIO_PIN_LOW)
        {
        	SPI_u8Tranceive(0,&Data_RX);

        }
	}

	return 0;
}

