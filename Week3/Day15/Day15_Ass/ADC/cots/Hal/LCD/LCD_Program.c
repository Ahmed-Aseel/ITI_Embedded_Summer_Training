#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "avr/delay.h"

void LCD_voidInit()
{
	/* set pins RS,RW,EN dir at LCD_CONTROL_PORT as output */
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, PIN_OUTPUT_ID);

	/* set LCD_PORT dir as output port */
	DIO_voidSetPortDirection(LCD_PORT, ALLPORTOUTPUT);
	/* delay 30ms */
	_delay_ms(30);
	/* send command function set */
	LCD_voidWriteCommand(LCD_8BITS_2LINES);
	/* delay 2ms */
	_delay_ms(2);
	/* send command display on */
	LCD_voidWriteCommand(LCD_DISPLAY_ON);
	/* delay 2ms */
	_delay_ms(2);
	/* send command clear display */
	LCD_voidClear();
}

void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/* RS = 0 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, PIN_LOW);
	/* RW = 0 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, PIN_LOW);

	// send command
	DIO_voidSetPortValue(LCD_PORT, Copy_u8Command);

	/* EN = 1 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, PIN_HIGH);
	_delay_ms(2);
	/* EN = 0 -----> LCD_CONTROL_PORT */
	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, PIN_LOW);
}

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

void LCD_voidWriteString(u8* Copy_u8Str)
{
	volatile u8 i = 0;
	while(Copy_u8Str[i])
	{
		LCD_voidWriteData(Copy_u8Str[i]);
		i++;
		if(i == 16)
		{
			LCD_voidGoToXY(LINE_2,0);
		}
	}
}

void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	volatile u8 i = 0;
	volatile u8 Numbers[SIZE];

	do
	{
		Numbers[i] = Copy_u32Number % 10;
		Copy_u32Number /= 10;
		i++;

	}while(Copy_u32Number);

	while(i--)
	{
		LCD_voidWriteData(Numbers[i] + ZERO_ASCII);
	}
}

void LCD_voidWriteSpecialChar(u8 u8P_Patterns[][8], u8 Copy_u8Rows, u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 i, j;

	for(i = 0; i < Copy_u8Rows; i++)
	{
		LCD_voidWriteCommand(LCD_DDRAM_BASE + (i * 8));
		for(j = 0; j < 8; j++)
		{
			LCD_voidWriteData(u8P_Patterns[i][j]);
		}
		LCD_voidGoToXY(Copy_u8X, Copy_u8Y - i);
		LCD_voidWriteData(i);
	}
}

void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	if(Copy_u8X == LINE_1) // line 1
	{
		LCD_voidWriteCommand(LCD_CURSOR_OFFSET + Copy_u8Y);
	}
	else // line 2
	{
		LCD_voidWriteCommand(LCD_CURSOR_OFFSET + LCD_LINE1_LENGTH + Copy_u8Y);
	}
}

void LCD_voidClear()
{
	LCD_voidWriteCommand(LCD_CLEAR);
}

void LCD_voidShiftString(u8* Copy_u8Str, u8 Copy_u8Length)
{
	s8 i;
	for(i = Copy_u8Length - 1; i >= 0; i--)
	{
		LCD_voidClear();
		LCD_voidWriteCommand(LCD_RETURN_HOME);
		LCD_voidWriteString(Copy_u8Str + i);
		_delay_ms(200);
	}

	for(i = 1; i <= 16; i++)
	{
		LCD_voidClear();
		LCD_voidGoToXY(LINE_1, i);
		LCD_voidWriteString(Copy_u8Str);
		_delay_ms(200);
	}
}
