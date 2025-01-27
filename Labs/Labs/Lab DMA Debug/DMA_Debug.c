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
void func(void);
u16 arr1[1000]={0};
u16 arr2[1000]={0};
u16 arr3[1000]={0};
u16 arr4[1000]={0};

void main(void)
{
	for(u16 c=0;c<1000;c++)
	{
		arr1[c]=1;
		arr3[c]=4;

	}

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_DMA2);
	DMA2_voidSetStreamConfiguration(DMA_STREAM0,0,arr1,arr2,DMA_HWORD_SIZE,DMA_HWORD_SIZE,1000);
	DMA2_voidStreamInterruptConfiguration(DMA_STREAM0,ENABLED_DMA,DISABLED_DMA,DISABLED_DMA,DISABLED_DMA);
	DMA2_voidSetStreamFIFOConfiguration(DMA_STREAM0,DMA_FIFO_FULL,DMA_INC_BY_4,DMA_INC_BY_4,ENABLED_DMA);
	DMA2_voidStreamSetCallBack(func,DMA_STREAM0);
	MNVIC_voidEnablePeripheralInterrupt(DMA2_Stream0_IRQ);
	DMA2_voidStreamEnable(DMA_STREAM0,DMA_M2M_MODE,DMA_LOW_PRIORITY);

	for(u16 c=0;c<1000;c++)
	{
		arr4[c]=arr3[c];
	}
	while(1)
	{


	}







}


void func(void)
{
	asm("NOP");
}

