/*
 * STEPPER_Interface.h
 *
 *  Created on: Mar 21, 2024
 *      Author: ahmed
 */

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_
/*********************Function Prototypes*********************/
void STEPPER_voidInit(void);
void STEPPER_voidRotate(u8 copy_u8Direction);

/****************************User MARCOS***********************/
#define NORTH                   1
#define EASTERN_NORTH           2
#define EAST                    3
#define EASTREN_SOUTH           4
#define SOUTH                   5
#define WESTERN_SOUTH           6
#define WEST                    7
#define WESTERN_NORTH           8




#endif /* HAL_STEPPER_STEPPER_INTERFACE_H_ */
