/*
 * main.c
 *
 *  Created on: Aug 14, 2022
 *      Author: Aseel
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "avr/delay.h"

int main()
{
	/* Display my name and a number on LCD */

	u8 str1[] = "Ahmed Aseel";
	u8 str2[] = "Number = ";
	u32 number = 5324;
	LCD_voidInit();
	LCD_GoToXY(0,2);
	LCD_voidWriteString(str1);
	LCD_GoToXY(1,0);
	LCD_voidWriteString(str2);
	LCD_voidWriteNumber(number);
	while(1);
	return 0;
}
