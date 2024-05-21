/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Ibrahim
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_


void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);

//void EEPROM_vReadBlockFromAddress(u16 Copy_u16LocationAddress,u8* dist,const u16 size);
//void EEPROM_vWriteBlockToAddress(const u16 uiAddress, const u8* uiData,const u16 size);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
