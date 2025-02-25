/***********************LIB*************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/************************MCAL***********************/
#include "../include/MCAL/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"




/************************HAL***********************/


/************************SRVICES***********************/

//************************PROTOTYPES***********************/

void EXTI0_IRQHandler(void);


void main (void)
{

	// enable RCC
	MRCC_voidInit();

	// Clocks to usage Peripherals Enable (use RCC)
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);

	// pin configurations PA0 : OUTPUT :PUSH_PULL :LOW_SPEED
	for(u8 i=0 ; i<4 ;i++)
	{
		MGPIO_voidSetPinMode(GPIO_PORTA,i,GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(GPIO_PORTA,i,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	}
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_PIN_LOW);
	//Enable EX1
	MNVIC_voidEnablePeripheralInterrupt(6);
	MNVIC_voidEnablePeripheralInterrupt(7);
	// assgin SW priority 2 groups
	MNVIC_voidSetInterruptGroupMode(Groups2_Sub8);
	// INT 1 higher INT 0
	MNVIC_voidSetInterruptPriority(6,1,0);   // group 1
	MNVIC_voidSetInterruptPriority(7,0,0);   // group 0
	MNVIC_voidEnablePeripheralInterruptPending(6);

	while (1)
	{

	}

}

void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_HIGH);
	MNVIC_voidEnablePeripheralInterruptPending(7);
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_HIGH);

}

void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_HIGH);

}
