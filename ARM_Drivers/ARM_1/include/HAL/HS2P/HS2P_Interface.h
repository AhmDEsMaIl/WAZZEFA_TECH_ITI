
#ifndef HS2P_INTERCFACE_H_
#define HS2P_INTERCFACE_H_

typedef enum{
	DISABLED=0,
	ENABLED
}ChipState_t;

/************************************************************************************************/
/*									FUNCTIONS API's												*/
/************************************************************************************************/

void HS2P_voidInit(void);
void HS2P_voidSendByte(u8 Copy_u8Data);
void HS2P_voidSendData(u16 Copy_u8Data);

void HS2P_voidChipEnableDisable(ChipState_t copy_ChState);
void HS2P_voidChipReset(void);



#endif /* HS2P_INTERCFACE_H_ */
