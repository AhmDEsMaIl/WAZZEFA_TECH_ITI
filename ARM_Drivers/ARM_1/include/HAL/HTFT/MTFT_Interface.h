/*
 * MTFT_Interface.h
 *
 *  Created on: May 14, 2024
 *      Author: ahmed
 */

#ifndef MTFT_INTERFACE_H_
#define MTFT_INTERFACE_H_


void TFT_voidSendCommand(u8 Copy_u8Cmd);
void TFT_voidSendData(u8 Copy_u8data);
void TFT_voidInit();
void TFT_voidSendResetSequence(void);
void TFT_voidDisplayImg(u16 *Ptr);


#endif /* MTFT_INTERFACE_H_ */
