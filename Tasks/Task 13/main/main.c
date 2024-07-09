
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

/************************SRVICES***********************/

#include "../include/SERVICES/SRTOS/SRTOS_Interface.h"
//************************PROTOTYPES***********************/

void LED1(void);
void LED2(void);
void LED3(void);
void InitSelf_Subend(void);


void LED1(void)
{
	static u8 flag=0 ;
	TOG_BIT(flag,0);
	MGPIO_voidSetResetPin(GPIO_PORTA,GPIO_PIN0,flag);
	RTOS_voidSusbendTask(2);
}
void LED2(void)
{
	static u8 flag=0 ;
	TOG_BIT(flag,0);
	MGPIO_voidSetResetPin(GPIO_PORTA,GPIO_PIN1,flag);

}
void LED3(void)
{
	static u8 flag=0 ;
	TOG_BIT(flag,0);
	MGPIO_voidSetResetPin(GPIO_PORTA,GPIO_PIN2,flag);
	RTOS_voidDeleteTask(1);
	RTOS_voidResumeTask(2);
}
void InitSelf_Subend(void)
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

	RTOS_u8CreateTask(1,1000,0,LED1);
	RTOS_u8CreateTask(2,1000,0,LED2);
	RTOS_u8CreateTask(3,1000,0,LED3);

	MGPIO_voidSetResetPin(GPIO_PORTA,GPIO_PIN3,GPIO_SET);


	RTOS_voidSusbendTask(0);
}
void main (void)
{

	RTOS_u8CreateTask(0,1,0,InitSelf_Subend);
	RTOS_voidInit();
	//MSYSTICK_voidSetPeriodicInterval(4000000,LED1);
	while (1)
	{

	}

}

