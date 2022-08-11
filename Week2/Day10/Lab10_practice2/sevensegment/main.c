/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: metro
 */

#include "avr/io.h"
#include "avr/delay.h"

int main()
{
	// seven segment display common anode
	// ON port A
	DDRA = 0b01111111; // bins 0:6 are output
	unsigned char arr1[] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 16};

	// seven segment display common cathode
	// ON port C
	DDRC = 0b01111111; // bins 0:6 are output
	unsigned char arr2[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

	// toggle 2 leds on port B
	DDRB = 0b00000011; // bins 0,1 are out

	while(1)
	{
		PORTB = 0b00000001;
		_delay_ms(500);
		PORTB = 0b00000010;

		int i;
		for(i = 0; i < 10; i++)
		{
			PORTA = arr1[i];
			PORTC = arr2[i];
			_delay_ms(500);
		}
	}
	return 0;
}
