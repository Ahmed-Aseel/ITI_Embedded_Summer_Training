/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: metro
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "avr/delay.h"

int main()
{
	volatile u8 switches;

	// make pin 7 at each port as input pin
	// each pin enables 7Seg which connected in the same port
	DIO_voidSetPinDirection(PORTA_ID, PIN7_ID, PIN_INPUT_ID);
	DIO_voidSetPinDirection(PORTB_ID, PIN7_ID, PIN_INPUT_ID);
	DIO_voidSetPinDirection(PORTC_ID, PIN7_ID, PIN_INPUT_ID);
	DIO_voidSetPinDirection(PORTD_ID, PIN7_ID, PIN_INPUT_ID);

	while(1)
	{
		switches = 0;
		// switches var store pin 7 from each port
		// == pinD7 pinC7 pinB7 pinA7
		switches =  switches + read_bit(PIND_REG, 7);
		switches = (switches << 1) + read_bit(PINC_REG, 7);
		switches = (switches << 1) + read_bit(PINB_REG, 7);
		switches = (switches << 1) + read_bit(PINA_REG, 7);

		switch(switches)
		{
		case 0b0001: // port A is enabled
			SevSeg_voidDisplayNumber(PORTA_ID, ZERO);
			_delay_ms(500);
			SevSeg_voidDisplayNumber(PORTA_ID, ONE);
			_delay_ms(500);
			break;

		case 0b0010: // port B is enabled
			SevSeg_voidDisplayNumber(PORTB_ID, ZERO);
			_delay_ms(500);
			SevSeg_voidDisplayNumber(PORTB_ID, ONE);
			_delay_ms(500);
			break;

		case 0b0100: // port C is enabled
			SevSeg_voidDisplayNumber(PORTC_ID, ZERO);
			_delay_ms(500);
			SevSeg_voidDisplayNumber(PORTC_ID, ONE);
			_delay_ms(500);
			break;

		case 0b1000: // port D is enabled
			SevSeg_voidDisplayNumber(PORTD_ID, ZERO);
			_delay_ms(500);
			SevSeg_voidDisplayNumber(PORTD_ID, ONE);
			_delay_ms(500);
			break;

		default:
			break;
		}
	}

	return 0;
}
