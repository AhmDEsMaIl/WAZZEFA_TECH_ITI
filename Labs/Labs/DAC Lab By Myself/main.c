/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/


/***********************LIB*************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/************************MCAL***********************/
#include "../include/MCAL/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Private.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MEXTI/MEXTI_Interface.h"
#include "../include/MCAL/MSTK/MSTK_Interface.h"

//#include "../include/MCAL/MGPIO/file.h"


/************************HAL***********************/
#include "../include/HAL/HLCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/HDAC/HDAC_Interface.h"

/************************SRVICES***********************/

#include "../include/SERVICES/SRTOS/SRTOS_Interface.h"
//************************PROTOTYPES***********************/

/*void DAC(void);


static u32 counter;
void DAC(void)
{

    GPIOA->ODR=Song2_raw[counter];
    counter++;
    if(counter==77512)
    {
    	counter=0;
    }


}*/
void main (void)
{

	// enable RCC
	MRCC_voidInit();

	// Clocks to usage Peripherals Enable (use RCC)
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);

	// pin configurations PA0 : OUTPUT :PUSH_PULL :LOW_SPEED
	HDAC_voidInit();
	HDAC_voidEnable();
	HDAC_voidSet_Song(SONG_ONE);
	for(volatile u64 c=0;c<(u64)10000000;c++)
	{

	}
	HDAC_voidSet_Song(SONG_TWO);
	while (1)
	{

	}

}
