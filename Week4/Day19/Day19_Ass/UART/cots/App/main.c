/*
 * main.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"

int main()
{
	u8 str[] = "Hi", i = 0, data;

	LCD_voidInit();

	UART_voidInit();
	while(str[i])
	{
		UART_voidSendData(str[i]);
		i++;
	}

	i = 0;
	while(1)
	{
		data = UART_u8RecieveData();
		if(data == 8) // backspace
		{
			i--;
			if(i < 16)
			{
				LCD_voidGoToXY(LINE_1, i);
				LCD_voidWriteData(data);
				LCD_voidGoToXY(LINE_1, i);
			}
			else
			{
				LCD_voidGoToXY(LINE_2, i - 16);
				LCD_voidWriteData(data);
				LCD_voidGoToXY(LINE_2, i - 16);
			}
		}
		else
		{
			LCD_voidWriteData(data);
			i++;
		}

		if(i == 16)
		{
			LCD_voidGoToXY(LINE_2, 0);
		}
	}

	return 0;
}
