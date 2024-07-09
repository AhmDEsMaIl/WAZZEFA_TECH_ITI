/*
 * DCMOTOR_Program.c
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
#include "DCMOTOR_Config.h"
#include "DCMOTOR_Interface.h"
#include "DCMOTOR_Private.h"




/********************Functions Defintions****************/
void MOTOR_voidINIT(void)
{
	DIO_u8SetPinDirection(MOTOR_PORT,MOTOR_CCW_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(MOTOR_PORT,MOTOR_CW_PIN,DIO_PIN_OUTPUT);

}
void MOTOR_voidCounterClockwise(void)
{
	DIO_u8SetPinValue(MOTOR_PORT,MOTOR_CCW_PIN,DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,DIO_PIN_HIGH);

}
void MOTOR_voidClockwise(void)
{
	DIO_u8SetPinValue(MOTOR_PORT,MOTOR_CCW_PIN,DIO_PIN_HIGH);
	DIO_u8SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,DIO_PIN_LOW);

}
void MOTOR_voidStop(void)
{
	DIO_u8SetPinValue(MOTOR_PORT,MOTOR_CCW_PIN,DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,DIO_PIN_LOW);

}
