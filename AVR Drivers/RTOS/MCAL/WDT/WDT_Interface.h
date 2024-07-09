/*
 * WDT_interface.h
 *
 *  Created on: Mar 31, 2024
 *      Author: eng_youssef_goher
 */

#ifndef DRIVERS_01_MCAL_WDT_WDT_INTERFACE_H_
#define DRIVERS_01_MCAL_WDT_WDT_INTERFACE_H_

/***************************WDT MOODES**************************************/
#define WDT_MODE16K			0
#define WDT_MODE32K			1
#define WDT_MODE64K			2
#define WDT_MODE128K		3
#define WDT_MODE256K		4
#define WDT_MODE512K		5
#define WDT_MODE1024K		6
#define WDT_MODE2048K		7

void MWDT_SartWDT(u8 copy_u8Mode);
void MWDT_StopWDT(void);

#endif /* DRIVERS_01_MCAL_WDT_WDT_INTERFACE_H_ */
