/*
 * SPI.c
 *
 * Created: 3/7/2023 10:03:56 PM
 *  Author: ahmed
 */ 
/******************LIB**********************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/******************MCAL*********************/
#include "../SPI/SPI_Private.h"
#include "SPI.h"
void SPI_Init(SPIMode_type mode)
{
	if(mode==Master)
	{
		//clock 2Mhz
		SET_BIT(SPCR , SPCR_MSTR) ;
	}
	else
	{
		CLR_BIT(SPCR , SPCR_MSTR) ;
	}
	// SPI Enable
	SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_SendReceieve(u8 data)
{
	SPDR=data;
	while(!(GET_BIT(SPSR , SPSR_SPIF)));
	return  SPDR;
}
u8 SPI_Receieveperodic(u8 *pdata)
{
	if(GET_BIT(SPSR , SPSR_SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}
u8 SPI_Receieve()
{
	return SPDR;
}
void SPI_Send(u8 data)
{
	SPDR=data;
}
