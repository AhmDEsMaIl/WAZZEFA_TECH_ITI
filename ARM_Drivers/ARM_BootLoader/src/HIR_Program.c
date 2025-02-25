/*
 * HIR_Program.c
 *
 *  Created on: 8 May 2024
 *      Author: User
 */

/***********************LIB*************************/
#include "../include/LIB/BIT_Math.h"
#include "../include/LIB/STD_Types.h"
/****************************MCAL***************************/

#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MEXTI/MEXTI_Interface.h"

/****************************HAL***************************/
#include "../include/HAL/HIR/HIR_Config.h"
#include "../include/HAL/HIR/HIR_Interface.h"
#include "../include/HAL/HIR/HIR_Private.h"



volatile u8 Global_u8StartFlag=0, Global_u8ReturnData=0, Global_u8Counter=0;
volatile u32 Global_IRData[50]={0};



static void HIR_voidSetValue(void)
{
	u8 Local_u8Counter=0;

	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		if((Global_IRData[Local_u8Counter+DATA_INDEX] >= 2000) && (Global_IRData[Local_u8Counter+DATA_INDEX])<=2500)
		{
			CLR_BIT(Global_u8ReturnData,Local_u8Counter);
		}
		else if((Global_IRData[Local_u8Counter+DATA_INDEX] >= 4000) && (Global_IRData[Local_u8Counter+DATA_INDEX])<=500000)
		{
			SET_BIT(Global_u8ReturnData,Local_u8Counter);
		}
		else
		{
			asm("NOP");
		}
	}
	Global_u8StartFlag=0;
}

static void HIR_voidOperate(void)
{
	if(Global_u8StartFlag==0)
	{
		MSYSTICK_voidCounterReset();
		MSYSTICK_voidSetSingleInterval_ms(1000,HIR_voidSetValue);
		Global_u8StartFlag=1;
		Global_u8Counter=0;
	}
	else
	{
		Global_IRData[Global_u8Counter]= MSYSTICK_u32GetElapsedTime();
		MSYSTICK_voidCounterReset();
		MSYSTICK_voidSetSingleInterval_ms(1000,HIR_voidSetValue);
		Global_u8Counter++;
	}

}


void HIR_voidInit(void)
{
	MSYSTICK_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(INTERRUPT_PERIPHERAL);
	MEXTI_voidSetCallBack(INTERRUPT_LINE,HIR_voidOperate);
	MEXTI_voidEnableEXTILine(INTERRUPT_LINE);
	MEXTI_voidInit();

}




void HIR_u8GetValue(u8* copy_u8ReturnData)
{
	*copy_u8ReturnData=Global_u8ReturnData;
	Global_u8ReturnData=0;
}



