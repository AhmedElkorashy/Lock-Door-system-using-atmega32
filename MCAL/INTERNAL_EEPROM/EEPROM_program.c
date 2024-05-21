/*
 * EEPROM_program.c
 *
 *  Created on: Jun 21, 2023
 *      Author: User
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EEPRIM_interface.h"
void EEPROM_WRITE(u8 address,u8 data){
	/* Wait for completion of previous write */
	//while(GET_BIT(EECR_REG,EEWE)==1);
	while(EECR_REG & (1<<EEWE));
	/* Set up address and data registers */
	EEAR_REG = address;
	EEDR_REG = data;
	/* Write logical one to EEMWE */
	EECR_REG |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR_REG |= (1<<EEWE);
}
u8 EEPROM_READ(u8 address){
	while(EECR_REG & (1<<EEWE));
	/* Wait for completion of previous write */
	//while(GET_BIT(EECR_REG,EEWE)==1);
	EEAR_REG=address;
	/* Start eeprom read by writing EERE */
	EECR_REG |= (1<<EERE);
	/* Return data from data register */
	return EEDR_REG;
}

void EEPROM_vReadBlockFromAddress(const u16 uiAddress, u8* dist,const u16 size)
{
	/* Wait for completion of previous write */
	while (((EECR_REG & (1 << EEWE))>>EEWE)==1);

	u16 counter = 0;//the counter of bytes that are read

	while (counter < size) //loop until move all bytes to the given array
	{
		/* Set up address register */
		EEAR_REG = uiAddress + counter;
		/* Start EEPROM read by writing EERE */
		EECR_REG |= (1 << EERE);
		/* move data from data register to the array */
		*(dist + counter) = EEDR_REG;

		counter++;//increase the bytes counter
	}
}

void EEPROM_vWriteBlockToAddress(const u16 uiAddress, const u8* uiData,const u16 size)
{
	u16 counter = 0;//Bytes write counter
	while (counter < size)
	{
		/* Wait for completion of previous write process*/
		while (( (EECR_REG & (1 << EEWE) ) >>EEWE ) == 1)
		;
		/* Set up address register */
		EEAR_REG = uiAddress + counter;

		/* Read the byte in the address of EEAR */
		EECR_REG |= (1 << EERE);
		if (EEDR_REG != (*(uiData + counter)))//compare the value read to the value to be written
		{//if they are not equal then write the data
			EEDR_REG = *(uiData + counter);//move the data to EEDR

			/* Write logical one to EEMWE */
			EECR_REG |= (1 << EEMWE);
			/* Start EEPROM write by setting EEWE */
			EECR_REG |= (1 << EEWE);
		}
		else
		{

		}
		counter++;//increase bytes counter
	}
}
