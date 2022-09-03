/*
 * KeyPad_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#ifndef Keypad_INTERFACE_H_
#define Keypad_INTERFACE_H_

/* Dimensions of switches values array
 * on KeyPad_u8GetPressedKey function
 */
#define ROWS           0x04
#define COLS           0x04
/* No switch is pressed */
#define NO_KEY_PRESSED 0xFF

/***************************** Functions Prototype *****************************/
void KeyPad_voidInit();
u8 KeyPad_u8GetPressedKey();
u8 KeyPad_u8Calc();

#endif /******** Keypad_INTERFACE_H_ ********/
