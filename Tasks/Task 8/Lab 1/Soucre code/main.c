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
u8 Global_u8BtnState;
u8 Global_u8Flag = 0;
u8 Global_u8CurrentState = 0;

/*TASKS PROTOTYPES*/
void LED(void);
void BUTTON(void);


/****************************************************************************/
/*ENTRY POINT <main>*/
int main(void)
{
	PORT_voidInit();

	RTOS_u8CreateTask(0,80,&LED);
	RTOS_u8CreateTask(1,80,&BUTTON);


	RTOS_voidStart();

	while(1)
	{

	}


	return 0;
}



/****************************************************************************/
/*TASKS DEFINITIONS*/
void LED(void)
{
	u8 static Flag=0;
	if(Global_u8BtnState == 0)
	{
		if(Flag==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			Flag=~Flag;

		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			Flag=~Flag;
		}

	}

}

void BUTTON(void)
{

	DIO_u8GetPinValue(DIO_PORTA,DIO_PIN1,&Global_u8Flag);
	if(Global_u8Flag == DIO_PIN_LOW)
	{
		Global_u8BtnState = 1;
	}
	else if(Global_u8Flag == DIO_PIN_HIGH)
	{
		Global_u8BtnState = 0;
	}
	while(Global_u8Flag == DIO_PIN_HIGH)
	{
		DIO_u8GetPinValue(DIO_PORTA,DIO_PIN1,&Global_u8Flag);
	}
}


/****************************************************************************/
