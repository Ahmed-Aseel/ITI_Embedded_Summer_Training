/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: metro
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "SevSeg_Interface.h"
#include "avr/delay.h"

int main()
{
	volatile u8 SevSeg_PORT_ID, No_Port, i;
	volatile u8 Numbers[] = {ZERO, ONE, TWO, THREE, FOUR,
							 FIVE, SIX, SEVEN, EIGHT, NINE};

	SevSeg_voidInit();
	while(1)
	{
		No_Port = 0;
		switch(SevSeg_u8CheckSwitches())
		{
		case 0b0001: // port A is enabled
			SevSeg_PORT_ID = PORTA_ID;
			break;

		case 0b0010: // port B is enabled
			SevSeg_PORT_ID = PORTB_ID;
			break;

		case 0b0100: // port C is enabled
			SevSeg_PORT_ID = PORTC_ID;
			break;

		case 0b1000: // port D is enabled
			SevSeg_PORT_ID = PORTD_ID;
			break;

		default:
			No_Port = 1;
			break;
		}

		if(No_Port)
		{
			continue;
		}

		for(i = 0; i < 10; i++)
		{
			SevSeg_voidDisplayNumber(SevSeg_PORT_ID, Numbers[i]);
			_delay_ms(500);
		}

	}

	return 0;
}
