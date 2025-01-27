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

u8 customChar[] = {
		0x04,
		0x0A,
		0x04,
		0x1F,
		0x04,
		0x04,
		0x0A,
		0x11
};

int main (void)
{
	/***********************MODULES INIT*************************/
	MOTOR_voidINIT();
	LCD_voidInit();
	KEYPAD_Init();
	u8 Local=0;
	u8 x=0,y=0;
	LCD_voidSendCustomCharacter(customChar,1,0,0);
	while(1)
	{
		Local=KEYPAD_u8GetPressed();
		if(Local!=NOTPRESSED)
		{
			switch(Local)
			{
			case '8':
				LCD_voidClearScreen();
				LCD_voidSendCustomCharacter(customChar,1,0,y);
				x=0;
				break;
			case '2':
				LCD_voidClearScreen();
				LCD_voidSendCustomCharacter(customChar,1,1,y);
				x=1;
				break;
			case '6':
				if(y<=14)
				{
					y++;
				}
				LCD_voidClearScreen();
				LCD_voidSendCustomCharacter(customChar,1,x,y);
				break;
			case '4':
				if(y>=1)
				{
					y--;
				}
				LCD_voidClearScreen();
				LCD_voidSendCustomCharacter(customChar,1,x,y);
				break;
			}

			Local=NOTPRESSED;
		}


	}
	return 0;
}


