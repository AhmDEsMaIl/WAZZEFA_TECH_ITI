/***********************LIB*************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
/***********************MCAL*************************/

#include "../include/MCAL/FDI/MFDI_Interface.h"


/************************APP***********************/

#include "../include/APP/HEXPARSING/HEXPARSING_Interface.h"

u32 Glopal_u32SectorAddress=0x08000000;
u16 Glopal_u16HalfWordValue[100];

static u8 ASCI_voidToHex(u8 Copy_u8Asci)
{
	u8 Local_u8Result=0;
	//for the numbers from 0 -> 9
	if((Copy_u8Asci>=48)&&(Copy_u8Asci<=57))
	{
		Local_u8Result = Copy_u8Asci-48;
	}
	//for charecters and special charecters
	else
	{
		Local_u8Result = Copy_u8Asci-55;
	}

	return Local_u8Result;

}

void PARSE_voidData(u8 *Copy_u8Buffer)
{
	// for the CC
	u8 Copy_u8CcHighNipple;
	u8 Copy_u8CcLowNipple;
	u8 Copy_u8CcTotal;

	//for the address Digits and DataDigits -> both are 2 bytes  -> ..
	//required one var for the digit
	u8 Local_u8Digit0;
	u8 Local_u8Digit1;
	u8 Local_u8Digit2;
	u8 Local_u8Digit3;
	u16 Local_u16LowPartAddress=0;
	//implementatoin CC part
	Copy_u8CcHighNipple=ASCI_voidToHex(Copy_u8Buffer[1]);
	Copy_u8CcLowNipple=ASCI_voidToHex(Copy_u8Buffer[2]);
	Copy_u8CcTotal = ((Copy_u8CcHighNipple<<4)|(Copy_u8CcLowNipple));

	//implementaion adress part
	Local_u8Digit0=ASCI_voidToHex(Copy_u8Buffer[3]);
	Local_u8Digit1=ASCI_voidToHex(Copy_u8Buffer[4]);
	Local_u8Digit2=ASCI_voidToHex(Copy_u8Buffer[5]);
	Local_u8Digit3=ASCI_voidToHex(Copy_u8Buffer[6]);
	/*
	Local_u16LowPartAddress=
			(Local_u8Digit3<<12)                |
			(Local_u8Digit2<<8)                 |
			(Local_u8Digit1<<4)                 |
			(Local_u8Digit0<<0)                 ;
	 */
	Local_u16LowPartAddress=((Local_u8Digit0<<12) |(Local_u8Digit1<<8)|
			(Local_u8Digit2<<4)|(Local_u8Digit3<<0));
	Glopal_u32SectorAddress &= 0xFFFF0000;
	Glopal_u32SectorAddress|=Local_u16LowPartAddress;

	//for the Data Bytes -> each transfer is 2 bytes (half word_ -> i.e) 4 digits
	for(u8 Local_u8Iterator=0;Local_u8Iterator<(Copy_u8CcTotal/2); Local_u8Iterator++)
	{
		Local_u8Digit0=ASCI_voidToHex(Copy_u8Buffer[(Local_u8Iterator*4) + 9]);
		Local_u8Digit1=ASCI_voidToHex(Copy_u8Buffer[(Local_u8Iterator*4) + 10]);
		Local_u8Digit2=ASCI_voidToHex(Copy_u8Buffer[(Local_u8Iterator*4) + 11]);
		Local_u8Digit3=ASCI_voidToHex(Copy_u8Buffer[(Local_u8Iterator*4) + 12]);

		Glopal_u16HalfWordValue[Local_u8Iterator] =   ( (Local_u8Digit2<<12)|
				(Local_u8Digit3<<8) |
				(Local_u8Digit0<<4) |
				(Local_u8Digit1<<0) ) ;
	}
	MFDI_voidWrite(Glopal_u32SectorAddress,Glopal_u16HalfWordValue,(Copy_u8CcTotal/2));

}

void PARSE_voidRecord(u8 *Copy_u8Record)
{
	switch(Copy_u8Record[8])
	{
	case '0':PARSE_voidData(Copy_u8Record);
	break;
	case '1'://end of file
		break;
	case '5':// complete address
		break;

	default :
		break;
	}

}
