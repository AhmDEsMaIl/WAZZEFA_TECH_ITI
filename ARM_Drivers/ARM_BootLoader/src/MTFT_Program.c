/*
 * MTFT_Program.c
 *
 *  Created on: May 14, 2024
 *      Author: ahmed
 */

/****************************LIB***************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"

/****************************MCAL**************************/
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"
#include "../include/MCAL/MSPI/MSPI_Interface.h"



#include "../include/HAL/HTFT/MTFT_Interface.h"
#include "../include/HAL/HTFT/MTFT_Private.h"
#include "../include/HAL/HTFT/MTFT_Config.h"



/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/


void TFT_voidSendCommand(u8 Copy_u8Cmd)
{

	u8 Local_u8var=0;
	MGPIO_voidSetPinValue(TFT_PORT,TFT_A0_PIN,GPIO_PIN_LOW);
	MSPI_voidTranceive(Copy_u8Cmd,&Local_u8var);


}
void TFT_voidSendData(u8 Copy_u8data)
{
	u8 Local_u8var=0;
	MGPIO_voidSetPinValue(TFT_PORT,TFT_A0_PIN,GPIO_PIN_HIGH);
	MSPI_voidTranceive(Copy_u8data,&Local_u8var);
}
void TFT_voidSendResetSequence(void)
{
	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait(200);

	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(2);

	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait(200);

	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(200);

	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait(240000);


}
void TFT_voidInit()
{
	// reset seq
	TFT_voidSendResetSequence();
	//sleep out mode
	TFT_voidSendCommand(0x11);
	// delay 10ms
	MSYSTICK_voidSetBusyWait(20000);
	//Color mode
	TFT_voidSendCommand(0x3A);
	TFT_voidSendData(0x05);
	// display on mode
	TFT_voidSendCommand(0x29);

}
void TFT_voidDisplayImg(u16 *Ptr)
{
    // set command of x axis
	TFT_voidSendCommand(0x2A);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(127);

    // set command of y axis
	TFT_voidSendCommand(0x2B);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(159);

	// commad ram address
	TFT_voidSendCommand(0X2C);

	for(u16 i=0;i<20480;i++)
	{
		u8 LowByte;
		u8 HighByte;
		LowByte=(u8)Ptr[i];
		HighByte=(u8)(Ptr[i]>>8);
		TFT_voidSendData(LowByte);
		TFT_voidSendData(HighByte);
	}
}
