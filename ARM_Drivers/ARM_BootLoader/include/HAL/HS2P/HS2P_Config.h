/*
 * HS2P_Config.h
 *
 *  Created on: 12 May 2024
 *      Author: User
 */

#ifndef HS2P_CONFIG_H_
#define HS2P_CONFIG_H_


#define S2P_PORT			GPIO_PORTA


#define S2P_DS_PIN			GPIO_PIN0
#define S2P_SH_CLK_PIN		GPIO_PIN1
#define S2P_STRG_CLK_PIN	GPIO_PIN2
#define S2P_RST_PIN			GPIO_PIN3
#define S2P_ENABLE_PIN		GPIO_PIN4


/* Select the number of output bit
 * 1. S2P_16_BIT
 * 2. S2P_8_BIT
 */
#define S2P_SELECT S2P_16_BIT



#endif /* HS2P_CONFIG_H_ */
