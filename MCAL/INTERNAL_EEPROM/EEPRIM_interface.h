/*
 * EEPRIM_interface.h
 *
 *  Created on: Jun 21, 2023
 *      Author: User
 */

#ifndef EEPRIM_INTERFACE_H__
#define EEPRIM_INTERFACE_H__
#include "STD_TYPES.h"
#include "EEPROM_PRIVATE.h"
void EEPROM_WRITE(u8 address,u8 data);
u8 EEPROM_READ(u8 address);
void EEPROM_vWriteBlockToAddress(const u16 uiAddress, const u8* uiData,const u16 size);
void EEPROM_vReadBlockFromAddress(const u16 uiAddress, u8* dist,const u16 size);
#endif /* EEPRIM_INTERFACE_H__ */
