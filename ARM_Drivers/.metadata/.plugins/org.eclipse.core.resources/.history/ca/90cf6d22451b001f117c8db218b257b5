/*
 * MUSART_Program.c
 *
 *  Created on: 8 May 2024
 *      Author: User
 */


/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_Math.h"
#include "../include/MCAL/MUART/MUART_Interface.h"
#include "../include/MCAL/MUART/MUART_Private.h"
#include "../include/MCAL/MUART/MUART_Config.h"
#include "../include/MCAL/MRCC/MRCC_Interface.h"



/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/

/*
 * BAUD RATE = CLK/16(VALUE)
 */
void UART_voidInit(void)
{
	//full dublex
	UART->CR1 |=(1<<2);
	UART->CR1 |=(1<<3);
	//sampling 16
	CLR_BIT(UART->CR1,15);
	//baudrate 9600
	//mantissa 104 , exponent 3
	UART->BRR = (104<<4) | (3);
	//one stop bit
	CLR_BIT(UART->CR2,12);
	CLR_BIT(UART->CR2,13);
	//no parity
	CLR_BIT(UART->CR1,10);

	//word size 8 bits
	CLR_BIT(UART->CR1,12);
}

void UART_voidSendByteSynchronous(u8 Copy_u8Data)
{
	while(!GET_BIT(UART->SR,7));
	UART->DR=Copy_u8Data;
}

u8 UART_u8ReciveDataByte(void)
{
	while(!GET_BIT(UART->SR,5));
	return UART->DR;

}
void UART_voidSendString(u8 *ptr)
{
	u16 Counter=0;
	while(ptr[Counter]!='\0')//while true
	{
		UART_voidSendByteSynchronous(ptr[Counter]);
		Counter++;
	}
	UART_voidSendByteSynchronous('\0');
}
void UART_voidEnable(void)
{
	SET_BIT(UART->CR1,13);
}

void UART_voidDisable(void)
{
	CLR_BIT(UART->CR1,13);
}

