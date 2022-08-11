/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: metro
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "avr/delay.h"

int main()
{
	// set pin0 portC as output pin
	DIO_voidSetPinDirection(PORTC_ID, PIN0_ID, PIN_OUTPUT_ID);

	while(1)
	{
		// toggle led on pin0 portC
		DIO_voidSetPinValue(PORTC_ID, PIN0_ID, PIN_HIGH);
		_delay_ms(500);
		DIO_voidSetPinValue(PORTC_ID, PIN0_ID, PIN_LOW);
		_delay_ms(500);
	}

	return 0;
}

