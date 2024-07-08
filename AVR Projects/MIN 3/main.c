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


int main (void)
{
	/***********************MODULES INIT*************************/
	MOTOR_voidINIT();
	LCD_voidInit();
	KEYPAD_Init();
	u8 Local=0;
	u16 Numb=0;
	LCD_voidSetPosition(0,0);
	LCD_voidSendString("Enter Your Pass");
	LCD_voidSetPosition(1,4);
	while(1)
	{
		Local=KEYPAD_u8GetPressed();
		if(Local!=NOTPRESSED)
		{
			if(Local>='0' && Local<='9')
			{
				Numb=Numb*10+(Local-'0');
				LCD_voidSendData('*');
			}
			if(Local=='?')
			{
				LCD_voidClearScreen();
				LCD_voidSetPosition(0,0);
				LCD_voidSendString("Your Pass Done");
				LCD_voidSetPosition(1,4);
				LCD_voidSendNumber(Numb);
				Numb=0;
			}
			Local=NOTPRESSED;
		}


	}
	return 0;
}



