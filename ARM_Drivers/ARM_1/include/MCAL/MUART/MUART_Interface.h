/*
 * MUSART_Interface.h
 *
 *  Created on: 8 May 2024
 *      Author: User
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_
/************************************************************************************************/
/*									FUNCTIONS API's												*/
/************************************************************************************************/

void UART_voidInit(void);

void UART_voidSendByteSynchronous(u8 Copy_u8Data);

u8 UART_u8ReciveDataByte(void);

void UART_voidEnable(void);
void UART_voidDisable(void);
void UART_voidSendString(u8 *ptr);

#endif /* MUSART_INTERFACE_H_ */
