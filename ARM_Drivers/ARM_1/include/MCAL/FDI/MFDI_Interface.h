/*
 * FDI_Interface.h
 *
 *  Created on: 23 May 2024
 *      Author: User
 */

#ifndef FDI_INTERFACE_H_
#define FDI_INTERFACE_H_


void MFDI_voidEraseSector(u8 copy_u8SectorNum);
void MFDI_voidEraseAppSector(void);
void MFDI_voidWrite(u32 copy_u32Address, u16 *copy_u16ptData,u8 copy_u8Length);




#endif /* FDI_INTERFACE_H_ */
