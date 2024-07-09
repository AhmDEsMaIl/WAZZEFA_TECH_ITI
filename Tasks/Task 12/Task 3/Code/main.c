
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

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA,GPIO_PIN4,GPIO_PULLUP);
	/******************** APP ************/
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);


	u8 value,Flag=0;
	while(1)
	{
		MGPIO_voidGetPinValue(GPIO_PORTA,GPIO_PIN4,&value);
		if(value==GPIO_PIN_LOW)
		{
			if(Flag==0)
			{
				MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_HIGH);
				Flag=~Flag;
				for(u64 c=0;c<100000;c++)
				{

				}
			}
			else
			{
				MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
				Flag=~Flag;
				for(u64 c=0;c<100000;c++)
				{

				}

			}
			value=-1;
		}
		else
		{

		}


	}
	return 0;
}
