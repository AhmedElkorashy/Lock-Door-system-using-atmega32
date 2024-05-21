/*
 * EEPROM_PRIVATE.h
 *
 *  Created on: Jun 21, 2023
 *      Author: User
 */

#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_
#define EECR_REG  		*((volatile u8*)0X3C)
#define EEDR_REG  		*((volatile u8*)0X3D)
#define EEAR_REG  		*((volatile u16*)0X3E)

#define EEWE			1
#define EEMWE			2
#define EERE			0



#endif /* EEPROM_PRIVATE_H_ */
