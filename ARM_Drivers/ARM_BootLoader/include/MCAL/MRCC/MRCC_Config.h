/*
 * MRCC_Config.h
 *
 *  Created on: Apr 21, 2024
 *      Author: ahmed
 */

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_


/*SYS_CLK
 * OPTIONS
 * 1.RCC_HSI
 * 2.RCC_HSE
 * 3.RCC_PLL
 *
 */
#define SYS_CLK     RCC_HSI

/*RCC_CLK_SECURITY_SYSTEM
 * OPTIONS
 * 1. RCC_CSS_ON
 * R2. RCC_CSS_OFF
 *
 */
#define RCC_CLK_SECURITY_SYSTEM    RCC_CSS_ON
#endif /* MRCC_CONFIG_H_ */
