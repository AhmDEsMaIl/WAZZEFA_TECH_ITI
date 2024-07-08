/*
 * FAN_Program.c
 *
 *  Created on: Apr 8, 2024
 *      Author: ahmed
 */


/****************************LIB***************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/****************************MCAL**************************/
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Interface.h"


void FAN_INIT(void)
{
	/************************** TIMERS INIT*************************/
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
}

void FAN_Speed_1(u8 Speed)
{
	TIMER0_voidSetCTC(Speed);
}

void FAN_Speed_2(u8 Speed)
{
	TIMER2_voidSetCTC(Speed);
}
