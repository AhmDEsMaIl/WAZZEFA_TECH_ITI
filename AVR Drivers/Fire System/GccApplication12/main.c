/*
 * GccApplication12.c
 *
 * Created: 11/2/2022 2:43:34 PM
 * Author : ahmed
 */ 

#include "MemMap.h"
#include "Utiles.h"
#include "StdTypes.h"
#include "DIO_interface.h"
#include "Motor_interface.h"
#include "Motor_cfg.h"
#include "LCD.h"
#include "ADC.h"
#include "LED.h"
#include "Sensors.h"
#include "Temp_Filter.h"
#include "Buzzer.h"
#include "Interrupt.h"
#include "NVM.h"
#include "Timer.h"
#include "RGB.h"
#include "Timer_Services.h"
#include "ULTRASONIC.h"
#include "Fire System.h"
#include "SERVO_MOTOR.h"
#include "Stepper_Motor.h"
#define F_CPU     16000000
#include <util/delay.h>
#define Global_Enable   sei
#define Global_Disable   cli
#include "Keypad.h"
// static volatile u16 dis=0;
// u16 T,P;
// u16 pass=1958;  

// volatile u16 x=0 ,num;
// u8 interput_timer=0,i;

// static volatile u16 NVM_interput_flag1,NVM_interput_flag2,n;
// static const u16 pass=1953;

u16 T=0;
MQ_2 S=0;
u16 ss=0;
u8 f;
u16 x;
int main(void)
{
	
	/*Replace with your application code */
		INIT();
		while(1)
 		{ 	 
	    f=1;
		LCD_INIT();
		change_pass();
		f=0;
	    T=Temp_Read();
 		S=MQ_2_Read();
		LDR_ON();
		if(T<High_Temp_thersold && S==Smoke)     // to not burn out LED and Motor when user enter Password but Temp in above 500\50C and Press is
		{                      //   is above 575\57.5Pa i make condition if not Temp less than 500 and Press not less than 575
		   TEMP_PRESS_CRITICAL();
		} 
 	   if(T>High_Temp_thersold)   // condition to check Temp
 	   {
 		   if(S==Smoke) // condition to check Press
 		   {
 			   High_TEMP_HIGH_PRESS(); 			   
 		   }
 		   if(S==NO_somke)         //   if Press is under 500  and Temp is more than 500 so turn yellow LED on 2 and put word HOT on LCD
 		   {                 // and turn off Motor and two another LED which is red and Green and Buzzer because Press less than 450
 			   High_TEMP_LOW_PRESS();
 		   }
 	   }
 	   else if(T<Low_Temp_thersold)        //   if Press is under 500  and Temp under 500 so turn green LED on 1 and put word FNE on LCD
 	   {                     // and turn off Motor and two another LED which is red and yellow and Buzzer because Temp less than 450
 		   LOW_TEMP();
 
 	   }
}
	
		
}

	


