/*
 * LCD_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "avr/delay.h"

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void LCD_voidInit()
{
	/* Set Pins RS,RW,EN direction at LCD_CONTROL_PORT as Output */
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, PIN_OUTPUT_ID);

	/***** Set LCD_PORT direction as Output Port ****/
	DIO_voidSetPortDirection(LCD_PORT, ALLPORTOUTPUT);
	_delay_ms(30);
	/***** Send Command Function Set *****/
	LCD_voidWriteCommand(LCD_8BITS_2LINES);
	_delay_ms(2);
	/***** Send Command display on *****/
	LCD_voidWriteCommand(LCD_DISPLAY_ON);
	_delay_ms(2);
	/* Send Command clear display */
	LCD_voidClear();
}

/*******************************************************************************************/
void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/******** RS = 0 -----> LCD_CONTROL_PORT *********/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, PIN_LOW);
	/******** RW = 0 -----> LCD_CONTROL_PORT *********/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, PIN_LOW);

	/**********  Send User Command  **************/
	DIO_voidSetPortValue(LCD_PORT, Copy_u8Command);

	/******** EN = 1 -----> LCD_CONTROL_PORT **********/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, PIN_HIGH);
	_delay_ms(2);
	/******** EN = 0 -----> LCD_CONTROL_PORT *********/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, PIN_LOW);
}

/*******************************************************************************************/
void LCD_voidWriteData(u8 Copy_u8Data)
{
	/* RS = 1 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, PIN_HIGH);
	/* RW = 0 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, PIN_LOW);

	// send data
	DIO_voidSetPortValue(LCD_PORT, Copy_u8Data);

	/* EN = 1 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, PIN_HIGH);
	_delay_ms(2);
	/* EN = 0 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, PIN_LOW);
}

/*******************************************************************************************/
void LCD_voidWriteString(u8* Copy_u8Str)
{
	u8 i = 0;
	/* Loop till reach NULL char */
	while(Copy_u8Str[i])
	{
		/***** Display char by char ****/
		LCD_voidWriteData(Copy_u8Str[i]);
		i++;
		if(i == 16) /* if reach end of line 1 */
		{
			/*** Go To Next Line ***/
			LCD_voidGoToXY(LINE_2,0);
		}
	}
}

/*******************************************************************************************/
void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	u8 i = 0;
	u8 Digits[SIZE];

	do
	{
		/* Store each digit in the number in array */
		Digits[i] = Copy_u32Number % 10;
		Copy_u32Number /= 10;
		i++;

	}while(Copy_u32Number); /* Loop till number = 0 */

	/* Display digits in reverse */
	while(i--)
	{
		/* Send ASCII Value of each digit */
		LCD_voidWriteData(Digits[i] + ZERO_ASCII);
	}
}

/*******************************************************************************************/
void LCD_voidWriteSpecialChar(u8 u8P_Patterns[][8], u8 Copy_u8Rows, u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 i, j;

	/* loop over all patterns */
	for(i = 0; i < Copy_u8Rows; i++)
	{
		/* store pattern in DDRAM each pattern
		 *  in a separate block of 8 bytes
		 */
		LCD_voidWriteCommand(LCD_DDRAM_BASE + (i * 8));
		/* loop over 8 bytes of each pattern */
		for(j = 0; j < 8; j++)
		{
			/* write byte in DDRAM */
			LCD_voidWriteData(u8P_Patterns[i][j]);
		}
		/* display pattern from right to left */
		LCD_voidGoToXY(Copy_u8X, Copy_u8Y - i);
		LCD_voidWriteData(i);
	}
}

/*******************************************************************************************/
void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	if(Copy_u8X == LINE_1) // line 1
	{
		LCD_voidWriteCommand(LCD_CURSOR_OFFSET + Copy_u8Y);
	}
	else // line 2
	{
		/* To go to line 2 we add length of the line 1 */
		LCD_voidWriteCommand(LCD_CURSOR_OFFSET + LCD_LINE1_LENGTH + Copy_u8Y);
	}
}

/*******************************************************************************************/
void LCD_voidClear()
{
	LCD_voidWriteCommand(LCD_CLEAR);
}

/*******************************************************************************************/
void LCD_voidShiftString(u8* Copy_u8Str, u8 Copy_u8Length)
{
	s8 i;
	/* This loop to display last i chars
	 * till display whole string
	 * first display last char then last 2 chars
	 * and so on
	 */
	for(i = Copy_u8Length - 1; i >= 0; i--)
	{
		LCD_voidClear();
		/** send cursor to start of line 1 **/
		LCD_voidWriteCommand(LCD_RETURN_HOME);
		/******* display last i chars *******/
		LCD_voidWriteString(Copy_u8Str + i);
		_delay_ms(200);
	}

	/* This loop to display and
	 * shift whole string
	 */
	for(i = 1; i <= 16; i++)
	{
		LCD_voidClear();
		/* send cursor to line 2 position i */
		LCD_voidGoToXY(LINE_1, i);
		/**** display whole string ****/
		LCD_voidWriteString(Copy_u8Str);
		_delay_ms(200);
	}
}
/*******************************************************************************************/
