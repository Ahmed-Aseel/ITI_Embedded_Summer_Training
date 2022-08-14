// header protection
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit();
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidWriteString(u8* Copy_u8Str);
void LCD_voidWriteNumber(u32 Copy_u32Number);
void LCD_GoToXY(u8 x, u8 y);

#endif
