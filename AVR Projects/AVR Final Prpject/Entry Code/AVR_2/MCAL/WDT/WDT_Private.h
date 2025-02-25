/*
 * WDT_private.h
 *
 *  Created on: Mar 31, 2024
 *      Author: eng_youssef_goher
 */

#ifndef DRIVERS_01_MCAL_WDT_WDT_PRIVATE_H_
#define DRIVERS_01_MCAL_WDT_WDT_PRIVATE_H_

#define WDTCR_REG	*((volatile u8*)0x41)

#define WDTOE		4
#define WDE			3
#define WDP2		2
#define WDP1		1
#define WDP0		0

#endif /* DRIVERS_01_MCAL_WDT_WDT_PRIVATE_H_ */
