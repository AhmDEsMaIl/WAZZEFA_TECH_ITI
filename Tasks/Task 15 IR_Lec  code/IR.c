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
#include "../include/HAL/HLEDMRX/HLEDMRX_Interface.h"



/************************HAL***********************/
#include "../include/HAL/HLCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"

/************************SRVICES***********************/

#include "../include/SERVICES/SRTOS/SRTOS_Interface.h"
//************************PROTOTYPES***********************/
void Handler1 (void);
void func1(void);
void func2(void);
void func3(void);

volatile u8 flag=0;
volatile u32 arr[50]={0};
volatile u8 counter=0;
u8 u8Data=0;
void func1(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTB , GPIO_PIN0,GPIO_PIN_HIGH);
}
void func2(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTB , GPIO_PIN1,GPIO_PIN_HIGH);
}
void func3(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTB , GPIO_PIN2,GPIO_PIN_HIGH);
}
void func (void)
{
	for(u8 i=0;i<8;i++)
	{
		if((arr[17+i]>=2000) &&(arr[17+i]<=2500))
		{
			CLR_BIT(u8Data,i);
		}
		else if((arr[17+i]>=4000) &&(arr[17+i]<=500000))
		{
			SET_BIT(u8Data,i);

		}
		else
		{
		}
	}
	flag=0;
	asm("NOP");


}

void main (void)
{


	// enable RCC
	MRCC_voidInit();
	MSYSTICK_voidInit();


	// Clocks to usage Peripherals Enable (use RCC)

	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN0 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN0 , GPIO_PULLUP);

	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN0 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN1 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN2 , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB , GPIO_PIN0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB , GPIO_PIN1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB , GPIO_PIN2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MEXTI_voidSetCallBack(MEXTI_LINE0 , Handler1);


	MNVIC_voidEnablePeripheralInterrupt(EXTI0_IRQ);



	MEXTI_voidEnableEXTILine(MEXTI_LINE0);
	MEXTI_voidInit();



	while (1)
	{
		// LEDMRX SEt array
		switch (u8Data)
		{
		case 0:
			break;
		case 1:
			func1();

			break;
		case 2:
			func2();

			break;
		case 4:
			func3();

			break;
		default :
			break;

		}


	}

}

void Handler1 (void)
{
	if(flag==0)
	{
		flag=1;
		counter=0;
		MSYSTICK_voidSetSingleInterval_IR(2000000,func);
	}
	else
	{
		arr[counter]=MSYSTICK_u32GetElapsedTime();
		MSYSTICK_voidSetSingleInterval_IR(2000000,func);
		counter++;

	}
}