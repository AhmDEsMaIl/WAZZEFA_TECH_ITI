/*
 * LEDMRX_Program.c
 *
 *  Created on: May 7, 2024
 *      Author: mahmo
 */

/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/*******************************MCAL*************************************/
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"


/****************************HAL***************************/
#include "../include/HAL/HLEDMRX/HLEDMRX_Config.h"
#include "../include/HAL/HLEDMRX/HLEDMRX_Interface.h"
#include "../include/HAL/HLEDMRX/HLEDMRX_Private.h"


/********************Functions Definitions*****************/


static void HLEDMRX_voidDisableColumns(void)
{
	MGPIO_voidSetPinValue(COLS_PORT,C0,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C1,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C2,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C3,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C4,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C5,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C6,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(COLS_PORT,C7,GPIO_PIN_HIGH);


}

void HLEDMRX_voidInit(void)
{
	MSYSTICK_voidInit();

	MGPIO_voidSetPinMode(COLS_PORT,C0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C2,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C3,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C4,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C5,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C6,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(COLS_PORT,C7,GPIO_OUTPUT);

	MGPIO_voidSetPinOutputMode(COLS_PORT,C0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C5,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C6,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(COLS_PORT,C7,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	//ROWS
	MGPIO_voidSetPinMode(RWS_PORT,R0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R2,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R3,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R4,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R5,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R6,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(RWS_PORT,R7,GPIO_OUTPUT);

	MGPIO_voidSetPinOutputMode(RWS_PORT,R0,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R1,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R2,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R3,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R4,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R5,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R6,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;
	MGPIO_voidSetPinOutputMode(RWS_PORT,R7,GPIO_PUSH_PULL,GPIO_LOW_SPEED) ;

}

void HLEDMRX_voidSendPattern(u8 *Copy_u8ptr)
{
	//Disable Columns
	HLEDMRX_voidDisableColumns();

	//Activate Column -> Rowvalue -> delay
	HLEDMRX_u8GetRowValue(Copy_u8ptr[0]);
	MGPIO_voidSetPinValue(COLS_PORT,C0,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();

	HLEDMRX_u8GetRowValue(Copy_u8ptr[1]);
	MGPIO_voidSetPinValue(COLS_PORT,C1,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();

	HLEDMRX_u8GetRowValue(Copy_u8ptr[2]);
	MGPIO_voidSetPinValue(COLS_PORT,C2,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();

	HLEDMRX_u8GetRowValue(Copy_u8ptr[3]);
	MGPIO_voidSetPinValue(COLS_PORT,C3,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();

	HLEDMRX_u8GetRowValue(Copy_u8ptr[4]);
	MGPIO_voidSetPinValue(COLS_PORT,C4,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();


	HLEDMRX_u8GetRowValue(Copy_u8ptr[5]);
	MGPIO_voidSetPinValue(COLS_PORT,C5,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();


	HLEDMRX_u8GetRowValue(Copy_u8ptr[6]);
	MGPIO_voidSetPinValue(COLS_PORT,C6,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();

	HLEDMRX_u8GetRowValue(Copy_u8ptr[7]);
	MGPIO_voidSetPinValue(COLS_PORT,C7,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(5000);
	HLEDMRX_voidDisableColumns();


}

void HLEDMRX_u8GetRowValue(u8 Copy_u8RowValue)
{
	//row value -> 8bit , each bit -> to each pin
	u8 Reading;
	Reading= GET_BIT(Copy_u8RowValue,0);
	MGPIO_voidSetPinValue(RWS_PORT,R0,Reading);

	Reading= GET_BIT(Copy_u8RowValue,1);
	MGPIO_voidSetPinValue(RWS_PORT,R1,Reading);

	Reading= GET_BIT(Copy_u8RowValue,2);
	MGPIO_voidSetPinValue(RWS_PORT,R2,Reading);

	Reading= GET_BIT(Copy_u8RowValue,3);
	MGPIO_voidSetPinValue(RWS_PORT,R3,Reading);

	Reading= GET_BIT(Copy_u8RowValue,4);
	MGPIO_voidSetPinValue(RWS_PORT,R4,Reading);

	Reading= GET_BIT(Copy_u8RowValue,5);
	MGPIO_voidSetPinValue(RWS_PORT,R5,Reading);

	Reading= GET_BIT(Copy_u8RowValue,6);
	MGPIO_voidSetPinValue(RWS_PORT,R6,Reading);

	Reading= GET_BIT(Copy_u8RowValue,7);
	MGPIO_voidSetPinValue(RWS_PORT,R7,Reading);
}

