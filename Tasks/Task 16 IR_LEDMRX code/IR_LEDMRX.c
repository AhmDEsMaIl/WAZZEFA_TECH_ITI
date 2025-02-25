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



/************************HAL***********************/
#include "../include/HAL/HLCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/HLEDMRX/HLEDMRX_Interface.h"
#include "../include/HAL/HIR/HIR_Interface.h"


/************************SRVICES***********************/

#include "../include/SERVICES/SRTOS/SRTOS_Interface.h"
//************************PROTOTYPES***********************/

u8 array1[8]={0, 0, 254, 17, 17, 254, 0, 0};
u8 array2[8]={0, 255, 8, 8, 8, 8, 255, 0};
u8 array3[8]={255, 1, 2, 4, 4, 2, 1, 255};
u8 array4[8]={255, 137, 137, 137, 137, 137, 137, 137};
u8 array5[8]={255, 129, 129, 129, 66, 36, 24, 0};


void main (void)
{
   u8 u8Data=0;

	// enable RCC
	MRCC_voidInit();

	// Clocks to usage Peripherals Enable (use RCC)

	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN0 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN0 , GPIO_PULLUP);
	HLEDMRX_voidInit();
	HIR_voidInit();


	while (1)
	{
		HIR_u8GetValue(&u8Data);
		// LEDMRX SEt array
		switch (u8Data)
		{
		case 0:
			break;
		case 1:
			for(u16 c=0 ;c<100;c++)
			{
				HLEDMRX_voidSendPattern(array1);
			}

			break;
		case 2:
			for(u16 c=0 ;c<100;c++)
			{
				HLEDMRX_voidSendPattern(array2);
			}

			break;
		case 4:
			for(u16 c=0 ;c<100;c++)
			{
				HLEDMRX_voidSendPattern(array3);
			}

			break;
		case 5:
			for(u16 c=0 ;c<100;c++)
			{
				HLEDMRX_voidSendPattern(array4);
			}

			break;
		case 6:
			for(u16 c=0 ;c<100;c++)
			{
				HLEDMRX_voidSendPattern(array5);
			}

			break;
		default :
			break;

		}


	}

}


