
/****************************LIB***************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"

/****************************MCAL**************************/
#include "../include/MCAL/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"


/****************************HAL**************************/



/*Inclusions*/
//#include "/delay.h"


int main (void)
{
	/************** CLK INIT*********/
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	/************** GPIO INIT*********/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	/******************** APP ************/
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_PIN_LOW);
	while(1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_HIGH);


		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_PIN_HIGH);
		for(u64 c=0;c<1000000;c++)
		{

		}

		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_PIN_LOW);
		for(u64 c=0;c<1000000;c++)
		{

		}

	}
	return 0;
}
