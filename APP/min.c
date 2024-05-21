
/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <string.h>
/*****************MCAL*******************/
#include "DIO_Interface.h"
#include "TWI_Interface.h"
/*****************HAL*******************/
#include "EEPROM_Interface.h"
#include "LCD_Interface.h"
#include "KPD_Interface.h"

/********************************************************************************/
/***********Global Variables************/


#define MAX_SIZE	5
u8 password[MAX_SIZE];
u8 temp_pass[MAX_SIZE];
u8 counter=0;


/********************************************************************************/
/*								ENTRY POINT <main>								*/
/********************************************************************************/

u8 arr[5]={1,2,3,4,5};

int main(void)
{
	LCD_voidInit();
	KPD_Init();
	u8 Key;
	//0b00010011
	TWI_voidInitMaster(0X0C);
	LCD_voidSendString((u8*)"Welcome ");
	_delay_ms(1000);
	u16 read_eeprom=EEPROM_u8ReadDataByte(0);
	_delay_ms(200);
	u16 first=0;
	u8 second=0;
	u8 cursor=7;
	u8 flag=0;
	u16 var=0;
	while(1)
	{
		if(counter<3)
		{
			if(read_eeprom == 0xFF)
			{
				LCD_voidSetPosition(0,0);
				LCD_voidSendString((u8 *)"CREATE PASSWORD");
				LCD_voidSetPosition(1,0);
				LCD_voidSendString((u8*)"PASS :");
				Key=KPD_u8GetPressed();
				if(Key!=NOTPRESSED)
				{
					LCD_voidSetPosition(1,cursor);
					LCD_voidSendData('*');
					cursor++;
					if(Key!='?')
					{

						EEPROM_voidSendDataByte(first,Key);
						_delay_ms(200);
						first++;
					}
					if(Key=='?')
					{
						LCD_voidClearScreen();
						LCD_voidSendString((u8*)"welcome to smart.");
						LCD_voidSetPosition(1,0);
						LCD_voidSendString((u8*)"Pass Saved");
						counter=3;
					}
				}
			}
			else
			{
				LCD_voidSetPosition(0,0);
				LCD_voidSendString((u8 *)"Enter the pass");
				LCD_voidSetPosition(1,0);
				LCD_voidSendString((u8*)"PASS :");
				Key=KPD_u8GetPressed();
				if(Key!=NOTPRESSED)
				{
					if(Key!='?')
					{
						//var=EEPROM_u8ReadDataByte(first);
						_delay_ms(50);
						temp_pass[first]=var;
						first++;
					}
					if(Key=='?')
					{
						if(strcmp(password,temp_pass)==0)
						{
							LCD_voidClearScreen();
							LCD_voidSendString((u8*)"welcome to smart");
							counter=4;
						}
						if(strcmp(password,temp_pass))
						{
							counter++;
							LCD_voidClearScreen();
							LCD_voidSendString((u8*)"wrong pass");
							cursor=5;
							_delay_ms(2000);
							if(counter==3)
							{
								flag=1;
							}
						}
					}
					//password[second]=Key;
					LCD_voidSetPosition(1,cursor);
					LCD_voidSendData('*');
					cursor++;
					//second++;
					if(flag)
					{
						LCD_voidClearScreen();
						LCD_voidSendString((u8*)"wrong pass");
						LCD_voidSetPosition(1,0);
						LCD_voidSendString((u8 *)"Game over");
					}
				}
			}
		}
	}
}

