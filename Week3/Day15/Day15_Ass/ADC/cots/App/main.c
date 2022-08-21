/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "avr/delay.h"

int main()
{
	u16 digital_res, analog_res;
	u16 digital_res2, analog_res2;

	ADC_voidSelectRef(AVCC_CAP);
	ADC_voidLeftorRight(RIGHT);
	ADC_voidSelectPrescaler(FACTOR_64);
	ADC_voidInit();
	/* set ADC0, ADC1 pins direction as input */
	DIO_voidSetPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT_ID);
	DIO_voidSetPinDirection(PORTA_ID, PIN1_ID, PIN_INPUT_ID);

	LCD_voidInit();
	LCD_voidWriteString("WELCOME");
	_delay_ms(1000);

	while(1)
	{
		LCD_voidClear();
		/* channel 1 connected to touch ldr */
/*		LCD_voidGoToXY(0,0);
		LCD_voidWriteString("CH 0");

		ADC_voidSelectChannel(CHANNEL0);
		ADC_voidSimpleConv();
		digital_res = ADC_u16GetResult();
		analog_res = ( (u32)digital_res * 5000) / 1024;
		LCD_voidGoToXY(0,5);
		LCD_voidWriteNumber(digital_res);
		LCD_voidGoToXY(0,10);
		LCD_voidWriteNumber(analog_res);
		LCD_voidWriteString("mV");*/

		/* channel 1 connected to touch ldr */
		LCD_voidGoToXY(1,0);
		LCD_voidWriteString("CH 1");
		ADC_voidSelectChannel(CHANNEL1);
		ADC_voidSimpleConv();

		digital_res2 = ADC_u16GetResult();
		analog_res2 = ( (u32)digital_res2 * 5000) / 684;
		LCD_voidGoToXY(1,5);
		LCD_voidWriteNumber(digital_res2);
		LCD_voidGoToXY(1,10);
		LCD_voidWriteNumber(analog_res2);
		LCD_voidWriteString("mV");
		_delay_ms(2000);
	}
	return 0;
}
