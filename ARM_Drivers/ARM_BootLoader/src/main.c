
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

volatile u8 TimeOutFlag = 0 ;
volatile u8 ReceiveBuffer[100] ;
volatile u8 u8RecCounter = 0 ;
volatile u8 u8WriteReq = 1  ;

typedef void (*APP_Call)(void) ;
APP_Call Add_to_Called=0;


void App_voidToBurn(void)
{
	TimeOutFlag=1;
	//move vector table
#define SCB_VTOR    *((volatile u32*)0xE000ED08)
	SCB_VTOR=0X08004000;  //Starting from sector1 in flash
	Add_to_Called=*(APP_Call*)0X08004004;//Adress of Reset Handler
	Add_to_Called();
}


void main(void)
{

	u8 LOC_u8RecStatus = 0 ;
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(AHB1_LP, RCC_AHB1_FDI);//FDI
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);//UART
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);//GPIOA
	//Configure Pins A9,A10 -> ALT -> UART  ,A0 -> Indicate BootLoader
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);
	//Indicate i am in BootLoader Section in Flash
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_HIGH);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);
	//Enable Alternative Line
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN9,7);
	MGPIO_voidSetAF(GPIO_PORTA,GPIO_PIN10,7);
	//Enable Peripherals
	UART_voidInit();
	UART_voidEnable();
	//Enable Stk
	MSYSTICK_voidInit();
	//Wait 15 sec to boot the program then jump to execute it
	MSYSTICK_voidSetSingleInterval(30000000,&App_voidToBurn);
	while(TimeOutFlag==0)
	{
		LOC_u8RecStatus=UART_u8ReadDataSynch(&ReceiveBuffer[u8RecCounter]);

		if(LOC_u8RecStatus==1)
		{
			//Stop timer because The Application Code is in progress
			MSYSTICK_voidInit();
			if(ReceiveBuffer[u8RecCounter]=='\n')//indicate ->end of record
			{

				if(u8WriteReq==1)
				{
					//Erase Application area
					MFDI_voidEraseAppSector();
					u8WriteReq=0;
				}

				PARSE_voidRecord(&ReceiveBuffer);
				//Send Ok to the tool to send the next record
				UART_voidSendString("ok");
				//reset buffer counter
				u8RecCounter=0;
			}
			else{u8RecCounter++;}


		}
		//end of file


	}


}