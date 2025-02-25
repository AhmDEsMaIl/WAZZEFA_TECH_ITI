
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
/************************HAL***********************/
#include "../include/HAL/HLCD/LCD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"



/************************************************************************/
void Handler1 (void);
void Handler2 (void);
void Handler3 (void);
void Handler4 (void);
void Handler5 (void);

#define Numb_OF_Loop     1000000


/************************************************************************/
/*							ENTRY POINT <main>							*/
/************************************************************************/
void main (void)
{
	MRCC_voidInit();

	MNVIC_voidSetInterruptGroupMode(Groups2_Sub8);

	MNVIC_voidSetInterruptPriority(EXTI0_IRQ,0,0);
	MNVIC_voidSetInterruptPriority(EXTI1_IRQ,0,1);

	MNVIC_voidSetInterruptPriority(EXTI2_IRQ,1,0);
	MNVIC_voidSetInterruptPriority(EXTI3_IRQ,1,1);
	MNVIC_voidSetInterruptPriority(EXTI4_IRQ,1,2);

	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN0 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN0 , GPIO_PULLUP);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN1 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN1 , GPIO_PULLUP);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN2 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN2 , GPIO_PULLUP);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN3 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN3 , GPIO_PULLUP);

	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN4 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN4 , GPIO_PULLUP);





	MEXTI_voidInit();

	MEXTI_voidSetCallBack(MEXTI_LINE0 , Handler1);
	MEXTI_voidSetCallBack(MEXTI_LINE1 , Handler2);
	MEXTI_voidSetCallBack(MEXTI_LINE2 , Handler3);
	MEXTI_voidSetCallBack(MEXTI_LINE3 , Handler4);
	MEXTI_voidSetCallBack(MEXTI_LINE4 , Handler5);


	MNVIC_voidEnablePeripheralInterrupt(EXTI0_IRQ);
	MNVIC_voidEnablePeripheralInterrupt(EXTI1_IRQ);
	MNVIC_voidEnablePeripheralInterrupt(EXTI2_IRQ);
	MNVIC_voidEnablePeripheralInterrupt(EXTI3_IRQ);
	MNVIC_voidEnablePeripheralInterrupt(EXTI4_IRQ);

	u8 local_u8Iterator = 0;

	for ( local_u8Iterator = 0 ; local_u8Iterator < 16 ; local_u8Iterator++)
	{
		MGPIO_voidSetPinMode(GPIO_PORTB , local_u8Iterator , GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(GPIO_PORTB , local_u8Iterator , GPIO_PUSH_PULL , GPIO_LOW_SPEED);
		MGPIO_voidSetResetPin(GPIO_PORTB , local_u8Iterator , GPIO_RESET);
	}

	MEXTI_voidEnableEXTILine(MEXTI_LINE0);
	MEXTI_voidEnableEXTILine(MEXTI_LINE1);
	MEXTI_voidEnableEXTILine(MEXTI_LINE2);
	MEXTI_voidEnableEXTILine(MEXTI_LINE3);
	MEXTI_voidEnableEXTILine(MEXTI_LINE4);

	while (1)
	{

	}
}


void Handler1 (void)
{
	while (1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN12,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN13,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN8,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN9,GPIO_PIN_LOW);
	}
}
void Handler2 (void)
{
	while (1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN12,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN13,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN8,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN9,GPIO_PIN_HIGH);
	}
}
void Handler3 (void)
{
	while (1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN12,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN13,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN8,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN9,GPIO_PIN_LOW);
	}
}
void Handler4 (void)
{
	while (1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN12,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN13,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN8,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN9,GPIO_PIN_HIGH);
	}
}

void Handler5 (void)
{
	while (1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN12,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN12,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN13,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN13,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN8,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN8,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN9,GPIO_PIN_HIGH);
		for(u32 c=0;c<Numb_OF_Loop;c++)
		{

		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN9,GPIO_PIN_LOW);

	}
}
