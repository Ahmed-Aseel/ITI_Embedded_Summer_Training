#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "avr/delay.h"

void LCD_voidInit()
{
	/* set pins 0,1,2 dir at portB output */
	DIO_voidSetPortDirection(PORTB_ID, 0b00000111);
	/* set portA dir as output port */	
	DIO_voidSetPortDirection(PORTA_ID, 0xFF);
	/* delay 30ms */
	_delay_ms(30);
	/* send command function set */
	LCD_voidWriteCommand(0b00111000);
	/* delay 2ms */
	_delay_ms(2);
	/* send command display on/off */
	LCD_voidWriteCommand(0b00001100);
	/* delay 2ms */
	_delay_ms(2);
	/* send command clear display */
	LCD_voidWriteCommand(0b00000001);
}

void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/* RS = 0 -----> portB pin0 */
	DIO_voidSetPinValue(PORTB_ID, PIN0_ID, PIN_LOW);
	/* RW = 0 -----> portB pin1 */
	DIO_voidSetPinValue(PORTB_ID, PIN1_ID, PIN_LOW);

	// send command
	DIO_voidSetPortValue(PORTA_ID, Copy_u8Command);

	/* EN = 1 -----> portB pin2 */
	DIO_voidSetPinValue(PORTB_ID, PIN2_ID, PIN_HIGH);
	_delay_ms(2);
	/* EN = 0 -----> portB pin2 */
	DIO_voidSetPinValue(PORTB_ID, PIN2_ID, PIN_LOW);
}

void LCD_voidWriteData(u8 Copy_u8Data)
{
	/* RS = 1 -----> portB pin0 */	
	DIO_voidSetPinValue(PORTB_ID, PIN0_ID, PIN_HIGH);
	/* RW = 0 -----> portB pin1 */
	DIO_voidSetPinValue(PORTB_ID, PIN1_ID, PIN_LOW);

	// send data
	DIO_voidSetPortValue(PORTA_ID, Copy_u8Data);

	/* EN = 1 -----> portB pin2 */
	DIO_voidSetPinValue(PORTB_ID, PIN2_ID, PIN_HIGH);
	_delay_ms(2);
	/* EN = 0 -----> portB pin2 */
	DIO_voidSetPinValue(PORTB_ID, PIN2_ID, PIN_LOW);	
}

void LCD_voidWriteString(u8* Copy_u8Str)
{
	volatile u8 i = 0;
	while(Copy_u8Str[i])
	{
		LCD_voidWriteData(Copy_u8Str[i]);
		i++;
	}
}

void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	volatile u8 i = 0;
	volatile u8 Numbers[10];

	do
	{
		Numbers[i] = Copy_u32Number % 10;
		Copy_u32Number /= 10;
		i++;

	}while(Copy_u32Number);

	while(i--)
	{
		LCD_voidWriteData(Numbers[i] + 48);
	}
}

void LCD_GoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	if(Copy_u8X == 0) // line 1
	{
		LCD_voidWriteCommand(0x80 + Copy_u8Y);
	}
	else // line 1
	{
		LCD_voidWriteCommand(0x80 + 0x40 + Copy_u8Y);
	}
}
