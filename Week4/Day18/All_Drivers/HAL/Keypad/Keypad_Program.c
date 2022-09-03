/*
 * KeyPad_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"
#include "KeyPad_Config.h"
#include "Keypad_Interface.h"
#include "avr/delay.h"


/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void KeyPad_voidInit()
{
	/* set KeyPad_PORT pins 0:3 as input (rows)
	 * set KeyPad_PORT pins  4:7 as output (cols)
	 */
	DIO_voidSetPortDirection(KeyPad_PORT, 0xF0);
	/* activate pull up for pins 0:3
	 * make pins 4:7 high
	 */
	DIO_voidSetPortValue(KeyPad_PORT, ALLPORTOUTPUT);
}

/*******************************************************************************************/
u8 KeyPad_u8GetPresultsedKey()
{
	u8 KYP_SwitchVal[ROWS][COLS] = {{'7','8','9','/'},
							        {'4','5','6','*'},
			                        {'1','2','3','-'},
							        {'C','0','=','+'}
	                               };
	u8 rows, cols;
	u8 keyval = NO_KEY_PRESSED;
	for(cols = 0; cols < COLS; cols++)
	{
		/* activate this column */
		DIO_voidSetPinValue(KeyPad_PORT, (cols + COLS), PIN_LOW);
		for(rows = 0; rows < ROWS; rows++)
		{
			/* check if switch at pin (rows) is pressed */
			if(DIO_u8GetPinValue(KeyPad_PORT, rows) == 0)
			{
				/* store value corresponding to rows,cols
				 * in keyval variable
				 */
				keyval = KYP_SwitchVal[rows][cols];
				/* deal with bouncing effect */
				while(DIO_u8GetPinValue(KeyPad_PORT, rows) == 0);
				_delay_ms(50);
				return keyval; /* return value found */
			}
		}
		/* deactivate this column */
		DIO_voidSetPinValue(KeyPad_PORT, (cols + COLS), PIN_HIGH);
	}

	/* return default value if no switch pressed */
	return keyval;
}

/*******************************************************************************************/
u8 KeyPad_u8Calc()
{
	/* array of 4 elements to store operand1,
	 *  operand2, operation and '='
	 */
	u8 keyval, i, operation[4];
	u32 result;

	/* Take 4 inputs from the user */
	for(i = 0; i < 4; i++)
	{
		/* loop until any key is pressed */
		while(1)
		{
			/* Get value corresponding to pressed key */
			keyval = KeyPad_u8GetPresultsedKey();
			if(keyval != NO_KEY_PRESSED)
			{
				/* (on/c) key is used to exit function */
				if(keyval == 'C')
				{
					return 0;
				}
				/* store user input then display it */
				operation[i] = keyval;
				LCD_voidWriteData(keyval);
				/* break while and take the next input */
				break;
			}
		}
	}

	/* The value stored in the array is the ASCII
	 * so subtract ASCII of zero from the 2 operands
	 */
	operation[0] -= ZERO_ASCII;
	operation[2] -= ZERO_ASCII;

	/* switch operation that user has entered */
	switch(operation[1])
	{
	case '+':
		result = operation[0] + operation[2];
		break;

	case '-':
		result = operation[0] - operation[2];
		break;

	case '*':
		result = operation[0] * operation[2];
		break;

	case '/':
		result = operation[0] / operation[2];
		break;
	}

	/* Display result */
	LCD_voidWriteNumber(result);

	/* loop until the user press (on/c) to exit function */
	while(1)
	{
		keyval = KeyPad_u8GetPresultsedKey();
		if(keyval != NO_KEY_PRESSED)
		{
			if(keyval == 'C')
			{
				return 0;
			}
		}
	}
}
/*******************************************************************************************/
