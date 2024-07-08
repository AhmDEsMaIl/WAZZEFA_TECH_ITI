/*
 * STEPPER_Program.c
 *
 *  Created on: Mar 21, 2024
 *      Author: ahmed
 */

/****************************LIB***************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/****************************MCAL**************************/
#include "../../MCAL/DIO/DIO_Interface.h"

/****************************HAL***************************/
#include "STEPPER_Config.h"
#include "STEPPER_Interface.h"
#include "STEPPER_Private.h"

/*Inclusions*/
#include "avr/delay.h"

/*******************************Functions Defination*************************/\
void STEPPER_voidInit(void)
{
	DIO_u8SetPinDirection(STEPPER_PORT ,STEPPER_BLUE_PIN,   DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT ,STEPPER_PINK_PIN,   DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT ,STEPPER_YELLOW_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT ,STEPPER_ORANGE_PIN, DIO_PIN_OUTPUT);

}

void STEPPER_voidRotate(u8 copy_u8Direction)
{
	switch(copy_u8Direction)
	{
	case NORTH:
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_BLUE_PIN,   DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_PINK_PIN,   DIO_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_YELLOW_PIN, DIO_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_ORANGE_PIN, DIO_PIN_LOW);

		break;

	case EASTERN_NORTH:
		break;

	case EAST:
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_BLUE_PIN,   DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_PINK_PIN,   DIO_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_YELLOW_PIN, DIO_PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT ,STEPPER_ORANGE_PIN, DIO_PIN_LOW);

		break;

	case EASTREN_SOUTH:
		break;

	case SOUTH:
		break;

	case WESTERN_SOUTH:
		break;

	case WEST:
		break;

	case WESTERN_NORTH:
		break;

	default:
		break;
	}

}








