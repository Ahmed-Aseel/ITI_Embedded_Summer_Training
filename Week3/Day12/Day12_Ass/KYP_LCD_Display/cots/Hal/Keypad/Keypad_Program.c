#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"
#include "KeyPad_Config.h"
#include "Keypad_Interface.h"
#include "avr/delay.h"

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

u8 KeyPad_u8GetPressedKey()
{
	u8 KYP_SwitchVal[NO_OF_ROWS][NO_OF_COLS] = {{'7','8','9','/'},
							                    {'4','5','6','*'},
			                                    {'1','2','3','-'},
							                    {'C','0','=','+'}
	                                           };
	u8 rows, cols;
	u8 keyval = NO_KEY_PRESSED;
	for(cols = 0; cols < NO_OF_COLS; cols++)
	{
		/* activate this column */
		DIO_voidSetPinValue(KeyPad_PORT, (cols + NO_OF_COLS), PIN_LOW);
		for(rows = 0; rows < NO_OF_ROWS; rows++)
		{
			/* check if switch at pin (rows + 4) is pressed */
			if(DIO_u8GetPinValue(KeyPad_PORT, rows) == 0)
			{
				keyval = KYP_SwitchVal[rows][cols];
				/* deal with bouncing effect */
				while(DIO_u8GetPinValue(KeyPad_PORT, rows) == 0);
				_delay_ms(50);
				return keyval;
			}
		}
		/* deactivate this column */
		DIO_voidSetPinValue(KeyPad_PORT, (cols + NO_OF_COLS), PIN_HIGH);
	}

	return keyval;
}

u8 KeyPad_u8Calc()
{
	u8 keyval, i, operation[4];
	u32 res;
	for(i = 0; i < 4; i++)
	{
		while(1)
		{
			keyval = KeyPad_u8GetPressedKey();
			if(keyval != NO_KEY_PRESSED)
			{
				if(keyval == 'C')
				{
					return 0;
				}
				operation[i] = keyval;
				LCD_voidWriteData(keyval);
				break;
			}
		}
	}

	switch(operation[1])
	{
	case '+':
		res = (operation[0] - ZERO_ASCII) + (operation[2] - ZERO_ASCII);
		break;

	case '-':
		res = (operation[0] - ZERO_ASCII) - (operation[2] - ZERO_ASCII);
		break;

	case '*':
		res = (operation[0] - ZERO_ASCII) * (operation[2] - ZERO_ASCII);
		break;

	case '/':
		res = (operation[0] - ZERO_ASCII) / (operation[2] - ZERO_ASCII);
		break;
	}

	LCD_voidWriteNumber(res);

	while(1)
	{
		keyval = KeyPad_u8GetPressedKey();
		if(keyval != NO_KEY_PRESSED)
		{
			if(keyval == 'C')
			{
				return 0;
			}
		}
	}
}
