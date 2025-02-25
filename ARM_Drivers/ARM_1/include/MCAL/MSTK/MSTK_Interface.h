/*
 * STK_Interface.h
 *
 *  Created on: Apr 29, 2024
 *      Author: ahmed
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_
/************************************************************************************************/
/*									FUNCTIONS API's												*/
/************************************************************************************************/
typedef void(* PtrToFunc_void)(void);

void MSYSTICK_voidInit(void);

void MSYSTICK_voidSetBusyWait(u32 copy_u32Ticks);
void MSYSTICK_voidSetBusyWait_ms(u16 copy_u16TimePeriod);
void MSYSTICK_voidSetBusyWait_us(u32 copy_u32TimePeriod);

void MSYSTICK_voidSetSingleInterval(u32 copy_u32Ticks,PtrToFunc_void copy_callBackFunc);
void MSYSTICK_voidSetSingleInterval_ms(u16 copy_u16TimePeriod,PtrToFunc_void copy_callBackFunc);
void MSYSTICK_voidSetSingleInterval_us(u32 copy_u32TimePeriod,PtrToFunc_void copy_callBackFunc);
void MSYSTICK_voidSetSingleInterval_IR(u32 copy_u32Ticks,PtrToFunc_void copy_callBackFunc);

void MSYSTICK_voidSetPeriodicInterval(u32 copy_u32Ticks,PtrToFunc_void copy_callBackFunc);
void MSYSTICK_voidSetPeriodicInterval_ms(u16 copy_u16TimePeriod,PtrToFunc_void copy_callBackFunc);
void MSYSTICK_voidSetPeriodicInterval_us(u32 copy_u32TimePeriod,PtrToFunc_void copy_callBackFunc);

u32 MSYSTICK_u32GetElapsedTime(void);
u16 MSYSTICK_u16GetElapsedTime_ms(void);

u32 MSYSTICK_u32GetRemainingTime(void);
u16 MSYSTICK_u16GetRemainingTime_ms(void);

void MSYSTICK_voidCounterReset(void);

void MSYSTICK_voidDisableTimer();

#endif /* MSTK_INTERFACE_H_ */
