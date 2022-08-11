/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: metro
 */

#include "BitMath.h"
#include "avr/io.h"
#include "avr/delay.h"

int main()
{
	DDRA = 0x0; // port A pin 0 input
	PORTA = 0x1; // enable poll up at pin 0 in port A
	DDRB = 0x1; // port B pin 0 output

	while(1)
	{
		if(read_bit(PINA, 0) == 0)
		{
			PORTB = 0x1;
		}
		else
		{
			PORTB = 0x0;
		}
	}

	return 0;
}
