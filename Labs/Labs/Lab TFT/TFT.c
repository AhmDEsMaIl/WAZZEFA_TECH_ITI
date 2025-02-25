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
//************************PROTOTYPES***********************/


void main(void)
{
	u8 data;
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_SPI1);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);

	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);;
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);;


	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_ALT_FUNC);



	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN4,5);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN5,5);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN6,5);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN7,5);


	MSYSTICK_voidInit();
	MSPI_VoidInit();
	TFT_voidInit();
	TFT_voidDisplayImg(imge_arr);
	while(1)
	{


	}







}