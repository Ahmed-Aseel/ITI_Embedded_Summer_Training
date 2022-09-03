/*
 * LCD_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Size of the array used in LCD_voidWriteNumber function */
#define SIZE       10
/* ASCII Value Of Zero */
#define ZERO_ASCII 48

/******** LCD Commands ********/
#define LCD_CLEAR           0x01 /* replace all characters with ASCII 'space'             */
#define LCD_RETURN_HOME     0x02 /* return the cursor to the first position on first line */
#define LCD_ENTRY_MODE      0x06 /* shift cursor from left to right on read/write mode    */
#define LCD_DISPLAY_OFF     0x08 /* turn display off                                      */
#define LCD_DISPLAY_ON      0x0C /* turn display on, cursor off and don't blink character */
#define LCD_RESET           0x30 /* reset the LCD                                         */
#define LCD_4BITS_2LINES    0x28 /* 4-bit data, 2-lines display, 5 x 7 font               */
#define LCD_8BITS_2LINES    0x38 /* 8-bit data, 2-lines display, 5 x 7 font               */
#define LCD_CURSOR_OFFSET   0x80 /* set cursor position                                   */
#define LCD_LINE1_LENGTH    0x40
#define LCD_DDRAM_BASE      0x40

/** LCD Lines **/
#define LINE_1 0
#define LINE_2 1

/***************************** Functions Prototype *****************************/
void LCD_voidInit();
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidWriteString(u8* Copy_u8Str);
void LCD_voidWriteNumber(u32 Copy_u32Number);
void LCD_voidWriteSpecialChar(u8 u8P_Patterns[][8], u8 Copy_u8Rows, u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidClear();
void LCD_voidShiftString(u8* Copy_u8Str, u8 Copy_u8Length);

#endif /******** LCD_INTERFACE_H_ ********/
