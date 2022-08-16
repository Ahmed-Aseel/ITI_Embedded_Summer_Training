// header protection
#ifndef Keypad_INTERFACE_H_
#define Keypad_INTERFACE_H_

#define NO_OF_ROWS     0x04
#define NO_OF_COLS     0x04
#define NO_KEY_PRESSED 0xFF

void KeyPad_voidInit();
u8 KeyPad_u8GetPressedKey();
u8 KeyPad_u8Calc();

#endif
