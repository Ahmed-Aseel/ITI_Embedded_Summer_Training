/*
 * main.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "UART_Interface.h"
#include "avr/delay.h"

int main()
{
	u16 digital_res, analog_res;

	ADC_voidSelectRef(AVCC_CAP);
	ADC_voidLeftorRight(RIGHT);
	ADC_voidSelectPrescaler(FACTOR_64);
	ADC_voidInit();
	/* set ADC0 pin direction as input */
	DIO_voidSetPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT_ID);

	UART_voidInit();

	while(1)
	{
		ADC_voidSingleConv();
		digital_res = ADC_u16GetResult();
		analog_res = ( (u32)digital_res * 5000) / 1024;

		UART_voidSendNumber(analog_res);
		UART_voidSendData('/');
		_delay_ms(2000);
	}

	return 0;
}
