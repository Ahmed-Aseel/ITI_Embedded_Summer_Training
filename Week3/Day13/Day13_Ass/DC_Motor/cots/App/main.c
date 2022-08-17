/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "Motor_Interface.h"
#include "Motor_Config.h"
#include "avr/delay.h"

int main()
{
	LCD_voidInit();
	Motor_voidInit();

	u8 str1[] = "Motor Stopped";
	u8 str2[] = "Motor Rotates To Right";
	u8 str3[] = "Motor Rotates To Left";

	while(1)
	{
		if(DIO_u8GetPinValue(SWITCHES_PORT, SW1) == 0)
		{
			LCD_voidClear();
			LCD_voidWriteString(str1);
			Motor(STOP);
			while(DIO_u8GetPinValue(SWITCHES_PORT, SW1) == 0);
		}
		else if(DIO_u8GetPinValue(SWITCHES_PORT, SW2) == 0)
		{
			LCD_voidClear();
			LCD_voidWriteString(str2);
			Motor(RIGHT);
			while(DIO_u8GetPinValue(SWITCHES_PORT, SW2) == 0);
		}
		else if(DIO_u8GetPinValue(SWITCHES_PORT, SW3) == 0)
		{
			LCD_voidClear();
			LCD_voidWriteString(str3);
			Motor(LEFT);
			while(DIO_u8GetPinValue(SWITCHES_PORT, SW3) == 0);
		}
		else if(DIO_u8GetPinValue(SWITCHES_PORT, SW4) == 0)
		{
			DIO_voidSetPinValue(MOTOR_PORT, LED, PIN_LOW);
			while(DIO_u8GetPinValue(SWITCHES_PORT, SW4) == 0);
		}

		DIO_voidSetPinValue(MOTOR_PORT, LED, PIN_HIGH);
		Motor(STOP);
		LCD_voidClear();
	}

	return 0;
}
