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
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/WDT/WDT_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/SPI_NEW/SPI.h"
#include "MCAL/EEPROM/EEPROM_Interface.h"
#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"


/*Inclusions*/
#include "avr/delay.h"

#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"


/************************************MCAL************************************/
#include "MCAL/PORT/PORT_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "RTOS_STACK/GIE/GIE_Interface.h"
#include "RTOS_STACK/RTOS/RTOS_Interface.h"
#include "RTOS_STACK/RTOS/RTOS_Interface.h"

/*************************************HAL************************************/


/*********************************RTOS_STACK*********************************/




/****************************************************************************/
/*GLOBAL VARIABLES*/
u8 Global_u8BtnState=0;

/*TASKS PROTOTYPES*/
void LCD1(void);
void LCD2(void);


/****************************************************************************/
/*ENTRY POINT <main>*/
int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	RTOS_u8CreateTask(0,80,&LCD1);
	RTOS_u8CreateTask(1,80,&LCD2);


	RTOS_voidStart();

	while(1)
	{

	}


	return 0;
}



/****************************************************************************/
/*TASKS DEFINITIONS*/
void LCD1(void)
{
	u8 static Flag='A';
	if(Global_u8BtnState == 0)
	{
		LCD_voidSetPosition(0,0);
		LCD_voidSendString((u8)"I AM TASK 1 ");
		LCD_voidSendData(Flag);
		if(Flag=='Z')
		{
			Flag='A';
		}
		Flag++;
		Global_u8BtnState=1;
	}

}

void LCD2(void)
{
	u8 static Flag='a';
	if(Global_u8BtnState == 1)
	{
		LCD_voidSetPosition(1,0);
		LCD_voidSendString((u8)"I AM TASK 2 ");
		LCD_voidSendData(Flag);
		if(Flag=='z')
		{
			Flag='a';
		}
		Flag++;
		Global_u8BtnState = 0;
	}

}


/****************************************************************************/