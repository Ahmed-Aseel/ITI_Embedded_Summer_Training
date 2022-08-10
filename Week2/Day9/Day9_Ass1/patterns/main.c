/*
 * main.c
 *
 *  Created on: Aug 10, 2022
 *      Author: metro
 */

#include "avr/io.h"
#include "avr/delay.h"

int main()
{
	DDRA = 0xFF; // all portA pins are output pins
	while(1)
	{
		// pattern1 on PORTA
		PORTA = 0b10000001; // led 1 & 8 are on
		_delay_ms(500);     // delay 500 ms
		PORTA = 0b01000010; // led 2 & 7 are on
		_delay_ms(500);
		PORTA = 0b00100100; // led 3 & 6 are on
		_delay_ms(500);
		PORTA = 0b00011000; // led 4 & 5 are on
		_delay_ms(500);

		// reverse pattern1
		PORTA = 0b00011000; // led 4 & 5 are on
		_delay_ms(500);
		PORTA = 0b00100100; // led 3 & 6 are on
		_delay_ms(500);
		PORTA = 0b01000010; // led 2 & 7 are on
		_delay_ms(500);
		PORTA = 0b10000001; // led 1 & 8 are on
		_delay_ms(500);

		// pattern2 on PORTA
		PORTA = 0b00000001; // led 1 is on
		_delay_ms(500);
		PORTA = 0b00000011; // led 1,2 are on
		_delay_ms(500);
		PORTA = 0b00000111; // led 1,2,3 are on
		_delay_ms(500);
		PORTA = 0b00001111; // led 1,2,3,4 are on
		_delay_ms(500);
		PORTA = 0b00011111; // led 1,2,3,4,5 are on
		_delay_ms(500);
		PORTA = 0b00111111; // led 1,2,3,4,5,6 are on
		_delay_ms(500);
		PORTA = 0b01111111; // led 1,2,3,4,5,6,7 are on
		_delay_ms(500);
		PORTA = 0b11111111; // all leds are on
		_delay_ms(500);

		// reverse pattern2
		PORTA = 0b10000000; // led 8 is on
		_delay_ms(500);
		PORTA = 0b11000000; // led 8,7 is on
		_delay_ms(500);
		PORTA = 0b11100000; // led 8,7,6 is on
		_delay_ms(500);
		PORTA = 0b11110000; // led 8,7,6,5 is on
		_delay_ms(500);
		PORTA = 0b11111000; // led 8,7,6,5,4 is on
		_delay_ms(500);
		PORTA = 0b11111100; // led 8,7,6,5,4,3 is on
		_delay_ms(500);
		PORTA = 0b11111110; // led 8,7,6,5,4,3,2 is on
		_delay_ms(500);
		PORTA = 0b11111111; // all leds are on
		_delay_ms(500);
	}

	return 0;
}
