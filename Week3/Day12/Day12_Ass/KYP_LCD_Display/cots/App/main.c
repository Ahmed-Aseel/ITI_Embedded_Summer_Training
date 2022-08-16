/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "avr/delay.h"
#include "string.h"

int main()
{
	u8 str[] = "Ahmed";
	LCD_voidInit();
	KeyPad_voidInit();
	LCD_voidShiftString(str, strlen(str));

	while(1)
	{
		LCD_voidWriteCommand(LCD_RETURN_HOME);
		LCD_voidWriteString("SIMPLE CALC");
		LCD_voidGoToXY(LINE_2,0);
		KeyPad_u8Calc();
		LCD_voidClear();
	}

	return 0;
}
