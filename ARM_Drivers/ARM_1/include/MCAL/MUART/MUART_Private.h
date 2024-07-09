/*
 * MUSART_Private.h
 *
 *  Created on: 8 May 2024
 *      Author: User
 */

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_

#define UART1_BASE_ADDRESS        0X40011000

typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;

}UART_t;

#define UART       ((volatile UART_t*)UART1_BASE_ADDRESS)


#endif /* MUSART_PRIVATE_H_ */
