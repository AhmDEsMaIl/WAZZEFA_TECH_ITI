/*
 * HDAC_Interface.h
 *
 *  Created on: May 3, 2024
 *      Author: ahmed
 */

#ifndef HDAC_INTERFACE_H_
#define HDAC_INTERFACE_H_

typedef enum
{
	SONG_ONE=0,
	SONG_TWO
}Song_e;



void HDAC_voidInit(void);

void HDAC_voidEnable(void);

void HDAC_voidDisable(void);

void HDAC_voidSet_Song(Song_e SONG);

#endif /* HDAC_INTERFACE_H_ */
