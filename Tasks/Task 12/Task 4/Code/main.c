
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
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN5,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN6,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN7,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN8,GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA,GPIO_PIN8,GPIO_PULLUP);
	/******************** APP ************/
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN7,GPIO_PIN_LOW);



	u8 value,c=0;
	while(1)
	{
		MGPIO_voidGetPinValue(GPIO_PORTA,GPIO_PIN8,&value);
		if(value==GPIO_PIN_LOW)
		{
			c++;
			while(value==GPIO_PIN_LOW)
			{
				MGPIO_voidGetPinValue(GPIO_PORTA,GPIO_PIN8,&value);

			}
		}
		if(c==1)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_HIGH);

		}

		else if(c==2)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_HIGH);

		}
		else if(c==3)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_HIGH);

		}
		else if(c==4)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_PIN_HIGH);

		}
		else if(c==5)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_PIN_HIGH);

		}
		else if(c==6)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_PIN_HIGH);

		}
		else if(c==7)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_PIN_HIGH);

		}
		else if(c==8)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN7,GPIO_PIN_HIGH);

		}
		else
		{
			c=0;
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_PIN_LOW);
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN7,GPIO_PIN_LOW);

		}




	}
	return 0;
}
