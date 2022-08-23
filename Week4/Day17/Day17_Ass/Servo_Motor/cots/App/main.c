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
#include "GIE_Interface.h"
#include "Timer1_Interface.h"
#include "avr/delay.h"

int main()
{
	u16 digital_res, analog_res;

	// enable global interrupt
	Global_INTR_Enable();
	// initialize Timer1 Fast PWM mode , non inverting , prescaler 1/8
	TIMER1_voidInit();
	// set OC1A pin direction as output
	DIO_voidSetPinDirection(PORTD_ID, PIN5_ID, PIN_OUTPUT_ID);

	// initialize ADC channel0 , right adjust, prescaler 1/8
	ADC_voidSelectRef(AVCC_CAP);
	ADC_voidSelectChannel(CHANNEL0);
	ADC_voidLeftorRight(RIGHT);
	ADC_voidSelectPrescaler(FACTOR_64);
	ADC_voidInit();
	/* set ADC0 pin direction as input */
	DIO_voidSetPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT_ID);

	// initialize LCD
	LCD_voidInit();
	LCD_voidWriteString("WELCOME");
	_delay_ms(1000);

	while(1)
	{
		LCD_voidClear();
		LCD_voidGoToXY(0,0);
		LCD_voidWriteString("CH0");

		// start single conversion
		ADC_voidSingleConv();
		digital_res = ADC_u16GetResult();

		analog_res = ( (u32)digital_res * 5000) / 1024;
		// ADC ---> 0:5000 , Servo ---> 999:2000
		// 2000 - 999 = 1001 , 1001 / 4995 = 0.2004
		TIMER1_voidSetOCR1AValue(999 + (analog_res * 0.2004));

		LCD_voidGoToXY(0,5);
		LCD_voidWriteNumber(digital_res);
		LCD_voidGoToXY(0,10);
		LCD_voidWriteNumber(999 + (analog_res * 0.2004));
		LCD_voidWriteString("mV");
		_delay_ms(1000);
	}
	return 0;
}
