/*
 * main.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Aseel
 */

#include "avr/io.h"
#include "avr/delay.h"

int main()
{
	while(1)
	{
		// turn on led on PORTC pin0
		DDRC = 0b00000001;
		PORTC = 0b00000001;

		// seven segment display common anode
		// ON PORTA
		DDRA = 0b01111111;
		PORTA = 0b01000000; // Number 0
		_delay_ms(500);
		PORTA = 0b01111001; // Number 1
		_delay_ms(500);
		PORTA = 0b00100100; // Number 2
		_delay_ms(500);
		PORTA = 0b00110000; // Number 3
		_delay_ms(500);
		PORTA = 0b00011001; // Number 4
		_delay_ms(500);
		PORTA = 0b00010010; // Number 5
		_delay_ms(500);
		PORTA = 0b00000010; // Number 6
		_delay_ms(500);
		PORTA = 0b01111000; // Number 7
		_delay_ms(500);
		PORTA = 0b00000000; // Number 8
		_delay_ms(500);
		PORTA = 0b00010000; // Number 9
		_delay_ms(500);
	}
	return 0;
}
