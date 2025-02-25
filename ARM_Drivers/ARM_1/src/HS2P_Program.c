/*
 * HS2P_Program.c
 *
 *  Created on: 12 May 2024
 *      Author: User
 */
/***********************LIB*************************/
#include "../include/LIB/Std_Types.h"
#include "../include/LIB/BIT_Math.h"
/****************************MCAL***************************/

#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"

/****************************HAL***************************/
#include "../include/HAL/HS2P/HS2P_Config.h"
#include "../include/HAL/HS2P/HS2P_Interface.h"
#include "../include/HAL/HS2P/HS2P_Private.h"


void HS2P_voidInit(void)
{
	//Make the Direction of S2P pins Output
	MGPIO_voidSetPinMode(S2P_PORT,S2P_DS_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_PORT,S2P_DS_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_PORT,S2P_SH_CLK_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_PORT,S2P_SH_CLK_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_PORT,S2P_STRG_CLK_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_PORT,S2P_STRG_CLK_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

#if S2P_SELECT == S2P_16_BIT

	MGPIO_voidSetPinMode(S2P_PORT,S2P_RST_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_PORT,S2P_RST_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_PORT,S2P_ENABLE_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_PORT,S2P_ENABLE_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

#endif


}

void HS2P_voidSendByte(u8 Copy_u8Data)
{
	s8 Local_u8Counter;
	u8 Local_u8BitValue;
	for(Local_u8Counter=7;Local_u8Counter>=0;Local_u8Counter--)
	{
		// Set the value of every single bit each time
		Local_u8BitValue = GET_BIT(Copy_u8Data,Local_u8Counter);
		MGPIO_voidSetPinValue(S2P_PORT,S2P_DS_PIN,Local_u8BitValue);
		//Send Pulse to shift register to synchronise
		MGPIO_voidSetPinValue(S2P_PORT,S2P_SH_CLK_PIN,GPIO_PIN_HIGH);
		MSYSTICK_voidSetBusyWait_us(2);
		MGPIO_voidSetPinValue(S2P_PORT,S2P_SH_CLK_PIN,GPIO_PIN_LOW);
		MSYSTICK_voidSetBusyWait_us(2);
	}
	//Send Pulse to storage register to synchronise
	MGPIO_voidSetPinValue(S2P_PORT,S2P_STRG_CLK_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait_us(2);
	MGPIO_voidSetPinValue(S2P_PORT,S2P_STRG_CLK_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait_us(2);
}

void HS2P_voidSendData(u16 Copy_u8Data)
{
	s8 Local_u8Counter;
	u8 Local_u8BitValue;
	for(Local_u8Counter=15;Local_u8Counter>=0;Local_u8Counter--)
	{
		// Set the value of every single bit each time
		Local_u8BitValue = GET_BIT(Copy_u8Data,Local_u8Counter);
		MGPIO_voidSetPinValue(S2P_PORT,S2P_DS_PIN,Local_u8BitValue);
		//Send Pulse to shift register to synchronise
		MGPIO_voidSetPinValue(S2P_PORT,S2P_SH_CLK_PIN,GPIO_PIN_HIGH);
		MSYSTICK_voidSetBusyWait_us(2);
		MGPIO_voidSetPinValue(S2P_PORT,S2P_SH_CLK_PIN,GPIO_PIN_LOW);
		MSYSTICK_voidSetBusyWait_us(2);
	}
	//Send Pulse to storage register to synchronise
	MGPIO_voidSetPinValue(S2P_PORT,S2P_STRG_CLK_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait_us(2);
	MGPIO_voidSetPinValue(S2P_PORT,S2P_STRG_CLK_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait_us(2);
}

void HS2P_voidChipEnableDisable(ChipState_t copy_ChState)
{
	switch(copy_ChState)
	{
	case DISABLED:
		MGPIO_voidSetPinValue(S2P_PORT,S2P_ENABLE_PIN,GPIO_PIN_HIGH);
		break;
	case ENABLED:
		MGPIO_voidSetPinValue(S2P_PORT,S2P_ENABLE_PIN,GPIO_PIN_LOW);
		break;

	}

}

void HS2P_voidChipReset(void)
{
	MGPIO_voidSetPinValue(S2P_PORT,S2P_RST_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait_ms(100);
	MGPIO_voidSetPinValue(S2P_PORT,S2P_RST_PIN,GPIO_PIN_HIGH);
}

