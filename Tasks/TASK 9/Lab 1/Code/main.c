/*
 * main.c
 *
 *  Created on: Apr 3, 2024
 *      Author: ahmed
 */

/****************************LIB***************************/
/*
#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"
*/
/****************************MCAL**************************/
/*
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/WDT/WDT_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/SPI_NEW/SPI.h"
#include "MCAL/EEPROM/EEPROM_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
*/
/****************************HAL**************************/
/*
#include"HAL/KEYPAD/KEYPAD_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"

*/
/*Inclusions*/
#include "avr/delay.h"


/****************************************************************************/
/*							    FREE_RTOS LAB 01		   		  			*/
/****************************************************************************/
/****************************************************************************/
/*								FILES INCLUSIONS							*/
/****************************************************************************/
/*************************************LIB************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"


/************************************MCAL************************************/
#include "MCAL/PORT/PORT_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"

/*************************************HAL************************************/


/***********************************FREERTOS*********************************/
#include "FREE_RTOS/FreeRTOS.h"
#include "FREE_RTOS/task.h"


/****************************************************************************/
/*GLOBAL VARIABLES*/
volatile u8 Global_u8BtnState=0;
volatile u8 Global_u8Flag = 0;
volatile u8 Global_u8CurrentState = 0;

/*TASKS PROTOTYPES*/
void LED(void *pv);
void BUTTON(void *pv);

/****************************************************************************/
/*ENTRY POINT <main>*/
int main(void)
{
	/*MODULES INITIALIZATIONS*/
	PORT_voidInit();
	/*TASKS CREATION*/
	xTaskCreate(&LED,NULL,200,NULL,1,NULL);
	xTaskCreate(&BUTTON,NULL,200,NULL,0,NULL);

	/*START SCHEDULING*/
	vTaskStartScheduler();
	while(1)
	{

	}


	return 0;
}



/****************************************************************************/
/*TASKS DEFINITIONS*/
void LED(void *pv)
{
	while(1)
	{
		if(Global_u8BtnState == 0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		}
		vTaskDelay(1);
	}
}

void BUTTON(void *pv)
{

	while(1)
	{
		DIO_u8GetPinValue(DIO_PORTA,DIO_PIN1,&Global_u8Flag);
		if(Global_u8Flag == DIO_PIN_HIGH)
		{
			Global_u8BtnState = 1;
		}
		else
		{
			Global_u8BtnState = 0;
		}
		vTaskDelay(2);
	}
}

