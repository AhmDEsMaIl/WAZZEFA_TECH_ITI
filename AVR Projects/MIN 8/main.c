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
	u8 local=0;
	u8 f_Red=0;
	u8 f_Yellow=0;
	u8 f_Green=0;

	/*Initialize USART*/
	USART_voidInit();
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);

	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);

	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
	USART_u8SendStringSynch("PLZ Choose Color (r,y,g)\n");
	while(1)
	{
		USART_u8RecevieData(&local);
		if(local=='r')
		{
			if(f_Red==0)
			{
				USART_u8SendStringSynch("\n RED ON");
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			}
			else
			{
				USART_u8SendStringSynch("\n RED OFF");
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			}
			f_Red=~f_Red;
			local=0;
		}

		if(local=='y')
		{
			if(f_Yellow==0)
			{
				USART_u8SendStringSynch("\n YELLOW ON");
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			}
			else
			{
				USART_u8SendStringSynch("\n YELLOW OFF");
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			}
			f_Yellow=~f_Yellow;
			local=0;
		}


		if(local=='g')
		{
			if(f_Green==0)
			{
				USART_u8SendStringSynch("\n GREEN ON");
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			}
			else
			{
				USART_u8SendStringSynch("\n GREEN OFF");
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			}
			f_Green=~f_Green;
			local=0;
		}

	}
	return 0;
}

