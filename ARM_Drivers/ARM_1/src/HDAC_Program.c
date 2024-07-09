/*
 * HDAC_Program.c
 *
 *  Created on: May 3, 2024
 *      Author: ahmed
 */
#include "../include/LIB/BIT_Math.h"
#include "../include/LIB/STD_Types.h"


/*******************************MCAL*************************************/
#include "../include/HAL/HDAC/HDAC_Interface.h"
#include "../include/HAL/HDAC/HDAC_private.h"
#include "../include/HAL/HDAC/HDAC_Config.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"


/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/

u8 Global;
void HDAC_voidInit(void)
{
	u8 Counter;
	for(Counter=0;Counter<Pins_Numb;Counter++)
	{
		MGPIO_voidSetPinMode(HDAC_PORT,Counter,GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(HDAC_PORT,Counter,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	}
}

void HDAC_voidEnable()
{
	MSYSTICK_voidInit();
	MSYSTICK_voidSetPeriodicInterval(HDAC_SAMPLING_8000,HDAC_SongSet);

}
void HDAC_voidSet_Song(Song_e SONG)
{
	Global=SONG;

}
void HDAC_voidDisable(void)
{
	MSYSTICK_voidDisableTimer();
}
static void HDAC_SongSet(void)
{
	static u64 Counter_1=0;
	static u64 Counter_2=0;
	if(Global==SONG_ONE)
	{
		MGPIO_voidSetPortValue(HDAC_PORT,(Song1_raw[Counter_1]));
		Counter_1++;
		if(Counter_1==SONG1_LENGTH)
		{
			Counter_1=0;
		}

	}
	else if(Global==SONG_TWO)
	{
		MGPIO_voidSetPortValue(HDAC_PORT,(Song2_raw[Counter_2]));
		Counter_2++;
		if(Counter_2==40512)
		{
			Counter_2=0;
		}

	}

}



