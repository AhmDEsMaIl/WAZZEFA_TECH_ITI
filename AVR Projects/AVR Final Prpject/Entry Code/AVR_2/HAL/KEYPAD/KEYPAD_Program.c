/*
 * KEYPAD_Program.c
 *
 *  Created on: Mar 20, 2024
 *      Author: ahmed
 */


/****************************************************************/
/*                    FILES INCLUSIONS							*/
/****************************************************************/
/************************LIB*************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


/*************************MCAL************************************/
#include "../../MCAL/DIO/DIO_Interface.h"

/*************************HAL************************************/
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"
/****************************DELAY************************/
#include "avr/delay.h"

/********************functions**************************/



void KEYPAD_Init(void)
{
	/***Connect PUll Up For Rowws Pins*/
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R0,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R1,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R2,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R3,DIO_PIN_HIGH);

	/*Connect the colums pins as output high*/
	DIO_u8SetPinDirection(KPD_PORT,KPD_C0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_C1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_C2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_C3,DIO_PIN_OUTPUT);


	DIO_u8SetPinValue(KPD_PORT,KPD_C0,DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_C1,DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_C2,DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_C3,DIO_PIN_HIGH);



}
u8 KEYPAD_u8GetPressed(void)
{
	u8 Local_u8ReturnData=NOTPRESSED;
	u8 Local_u8GetPressed;
	u8 Local_u8Col;
	u8 Local_u8Row;
	for(Local_u8Col=KPD_COL_INT ; Local_u8Col< KPD_COL_END+1 ; Local_u8Col++)
	{
		DIO_u8SetPinValue(KPD_PORT, Local_u8Col,DIO_PIN_LOW);
		for(Local_u8Row=KPD_ROW_INT ; Local_u8Row<KPD_ROW_END+1 ; Local_u8Row++)
		{
			DIO_u8GetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);
			if(Local_u8GetPressed==0)
			{
				_delay_ms(50);
				DIO_u8GetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);
				if(Local_u8GetPressed==0)
				{
					Local_u8ReturnData= KPD_u8Buttoms[Local_u8Row-KPD_ROW_INT][Local_u8Col-KPD_COL_INT];
				}
				DIO_u8GetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);
				while(DIO_PIN_LOW == Local_u8GetPressed)
				{
					DIO_u8GetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);

				}
				break;
			}


	}
	DIO_u8SetPinValue(KPD_PORT, Local_u8Col,DIO_PIN_HIGH);

}
return Local_u8ReturnData;
}
