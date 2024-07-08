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

/****************************HAL**************************/

#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"


/*Inclusions*/
#include "avr/delay.h"

u8 customChar_1[] = {
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F
};
u8 customChar_2[] = {
		0x03,
		0x03,
		0x03,
		0x03,
		0x03,
		0x07,
		0x0F,
		0x1F
};
u8 customChar_3[] = {
		0x18,
		0x18,
		0x18,
		0x18,
		0x18,
		0x1C,
		0x1E,
		0x1F
};
int main(void)
{
	u8 f=0;
	/*************************************************************/
	/*				 1- MODULES INITIALIZATION				     */
	/*************************************************************/
	TIMER0_voidInit();
	LCD_voidInit();
	/*************************************************************/
	/*				         2- PIN SETUB				         */
	/*************************************************************/
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	/*************************************************************/
	/*				    3- SET CALLBACK FUNCTION				 */
	/*************************************************************/

	/***************************************************************/
	LCD_voidSetPosition(0,0);
	LCD_voidSendString("Hello ! Fast & Furious 10 :");
	LCD_voidSendCustomCharacter(customChar_1,1,1,0);
	LCD_voidSendCustomCharacter(customChar_1,1,1,39);
	LCD_voidSendCustomCharacter(customChar_2,2,1,1);
	LCD_voidSendCustomCharacter(customChar_3,3,1,2);
	_delay_ms(500);
	while(1)
	{
		LCD_voidClearScreen();
		LCD_voidSendCustomCharacter(customChar_1,1,1,0);
		LCD_voidSendCustomCharacter(customChar_1,1,1,39);
		LCD_voidSetPosition(0,0);
		LCD_voidSendString("Car Speed :Low                         ");
		TIMER0_voidSetCTC(32);
		f=0;
		for(u8 i=1; i<6;i++)
		{
			LCD_voidSendCustomCharacter(customChar_2,4,1,i);
			LCD_voidSendCustomCharacter(customChar_3,5,1,i+1);
			LCD_voidSetPosition(1,i-1);
			if(f==1)
			{
				LCD_voidSendString(" ");
			}
			f=1;
			_delay_ms(400);
		}
		LCD_voidSetPosition(0,0);
		LCD_voidSendString("Car Speed :Medium                         ");
		TIMER0_voidSetCTC(128);
		for(u8 i=6; i<14;i++)
		{
			LCD_voidSendCustomCharacter(customChar_2,4,1,i);
			LCD_voidSendCustomCharacter(customChar_3,5,1,i+1);
			LCD_voidSetPosition(1,i-1);
			LCD_voidSendString(" ");
			_delay_ms(100);
		}

		LCD_voidSetPosition(0,0);
		LCD_voidSendString("Car Speed :High                         ");
		TIMER0_voidSetCTC(255);
		for(u8 i=14; i<25; i++)
		{
			LCD_voidSendCustomCharacter(customChar_2,4,1,i);
			LCD_voidSendCustomCharacter(customChar_3,5,1,i+1);
			LCD_voidSetPosition(1,i-1);
			LCD_voidSendString(" ");
			_delay_ms(50);
		}
		LCD_voidSetPosition(0,0);
		LCD_voidSendString("Car Speed :Medium                         ");
		TIMER0_voidSetCTC(128);
		for(u8 i=25; i<32;i++)
		{
			LCD_voidSendCustomCharacter(customChar_2,4,1,i);
			LCD_voidSendCustomCharacter(customChar_3,5,1,i+1);
			LCD_voidSetPosition(1,i-1);
			LCD_voidSendString(" ");
			_delay_ms(100);
		}
		LCD_voidSetPosition(0,0);
		LCD_voidSendString("Car Speed :Low                         ");
		TIMER0_voidSetCTC(32);
		for(u8 i=32; i<38;i++)
		{
			LCD_voidSendCustomCharacter(customChar_2,4,1,i);
			LCD_voidSendCustomCharacter(customChar_3,5,1,i+1);
			LCD_voidSetPosition(1,i-1);
			LCD_voidSendString(" ");
			_delay_ms(400);
		}


	}

	return 0;
}
