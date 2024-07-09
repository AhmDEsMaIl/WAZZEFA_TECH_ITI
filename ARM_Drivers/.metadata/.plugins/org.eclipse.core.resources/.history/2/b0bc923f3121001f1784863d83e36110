
/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/

/***********************LIB*************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/************************MCAL***********************/
#include "../include/MCAL/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MEXTI/MEXTI_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"
#include "../include/MCAL/MUART/MUART_Interface.h"
#include "../include/MCAL/MSPI/MSPI_Interface.h"
#include "../include/MCAL/MDMA/MDMA_Interface.h"
#include "../include/MCAL/FDI/MFDI_Interface.h"



/************************HAL***********************/
#include "../include/HAL/HLCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/HLEDMRX/HLEDMRX_Interface.h"
#include "../include/HAL/HIR/HIR_Interface.h"
#include "../include/HAL/HS2P/HS2P_Interface.h"
#include "../include/HAL/HTFT/MTFT_Interface.h"
#include "../include/HAL/HTFT/Image.h"


/************************SRVICES***********************/

#include "../include/SERVICES/SRTOS/SRTOS_Interface.h"
/************************APP***********************/

#include "../include/APP/HEXPARSING/HEXPARSING_Interface.h"
//************************PROTOTYPES***********************/

void main(void)
{

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);

	//initialize pina0 output high

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);


	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);
	//Enable Alternative Line
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN9,7);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN10,7);

	while(1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_HIGH);
		for(u32 i=0;i<100000;i++)
		{
			asm("NOP");
		}
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
		for(u32 i=0;i<1000000;i++)
		{
			asm("NOP");
		}



	}





}



